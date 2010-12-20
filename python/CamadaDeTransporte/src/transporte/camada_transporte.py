'''
Created on 16/06/2009
@author: Katcipis

Modulo contendo as funcoes disponiveis nesta camada de transporte

As funcoes que pertencem a API sao:
listen
connect
send
receive

Todas as demais funcoes e variaveis existentes no modulo sao de uso interno 
da camada de transporte e nunca devem ser invocadas.

Enderecos sempre devem ser fornecidos como IP:PORTA.
Exemplo: 192.168.170.30:5000

'''
from util.Log import Log
from threading import Event
from transporte.PoolConexoes import PoolConexoes
from transporte import ErrosTransporte
from transporte import EstadosConexao
from rede import TiposDePacote
from rede import camada_rede
from util import sistema

# ================= #
# VARIAVEIS GLOBAIS #
# ================= #

_NUMERO_MAX_CONEXOES = 32
_pool_conexoes = PoolConexoes(_NUMERO_MAX_CONEXOES)
_log = Log('Camada de transporte: ')
_TIMEOUT = 30

##Todos as estruturas mapeiam suas chaves para um evento, as chaves podem variar
# documentacao do evento: http://docs.python.org/library/threading.html#event-objects

_listensEmEspera = {}   ##Chave eh apenas o endereco local de quem espera
_conectsEmEspera = {}   ##Chave eh a concatenacao do endereco local com o remoto
_esperandoCreditos = {} ##Chave eh o ID da Conexao 
_esperandoDados = {}    ##Chave eh o ID da Conexao

# ================ #
# FUNCOES INTERNAS #
# ================ #

def _acordar_processos(chave, eventos_dict):
  '''
  Libera todos os processos que estavam aguardando por um determinado evento
  '''
  _log.logar('Acordando ' + str(len(eventos_dict[chave])) + ' processos')
  [evento.set() for evento in eventos_dict[chave]]
  eventos_dict[chave] = []

def _aguardar_por_evento(chave, eventos_dict, msg_log = 'Aguardando evento', funcao = None, args = None):
  '''
  Bloqueia quem chama a funcao ate que ocorra um evento em outro processo que ira acessar
  o eventos_dict e liberar todos os que estavam esperando por este evento.
  Para evitar problemas de corrida, ja que as vezes era possivel que a resposta do end_remoto
  podia vir mais rapido que a velocidade de inserir o evento no dicionario foi adcionado o parametro
  funcao e args, funcao sera chamada com os argumentos args somente apos o evento ter sido colocado no dicionario.
  '''
  evento = Event()
  if(not chave in eventos_dict):
    eventos_dict[chave] = []    
          
  eventos_dict[chave].append(evento)
  _log.logar(msg_log)
  
  if(funcao != None):
    funcao(*args)
  
  evento.wait()
  
def _conexao_esta_ok(con):
  if(con.obterEstado() != EstadosConexao.ESTABELECIDA):
    _log.logar('Erro!!! Conexao nao esta estabelecida!!' )
    _log.logar('Detalhes da conexao: ' + str(con))
    _pool_conexoes.liberarConexao(con)
    return ErrosTransporte.CONEXAO_NAO_ESTABELECIDA
  
  if(con.obterReqLiberarRecebida()):
    _log.logar('Erro!!! Parceiro pediu para encerrar a conexao!!')
    _log.logar('Detalhes da conexao: ' + str(con))
    _pool_conexoes.liberarConexao(con)
    return ErrosTransporte.CONEXAO_FECHADA
  
  return ErrosTransporte.OK

def _dados_possui_endereco_local_e_remoto(dados):
  if(not camada_rede.ENDERECO_LOCAL in dados):
    _log.logar('ERRO: Endereco local nao foi encontrado no pacote de requisicao de chamada')
    return False
  
  if(not camada_rede.ENDERECO_REMOTO in dados):
    _log.logar('ERRO: Endereco remoto nao foi encontrado no pacote de requisicao de chamada')
    return False
  
  return True

# ============================ # 
# DEFINICAO FUNCAO DE CALLBACK #
# DO CLOCK DO SISTEMA          #
# ============================ #

def _clock():        
  '''
  O relogio pulsou, verifica os timeouts de solicitacoes de conexao enfileiradas
  '''
  for i in range(_NUMERO_MAX_CONEXOES):
    con = _pool_conexoes.obterConexao(i)
    
    if(con.timerEstaLigado()):
      con.setTimer(con.obterTimer() - 1)
      if(con.obterTimer() == 0):
        con.setEstado(EstadosConexao.PARADO)
        _log.logar('Solicitacao de conexao expirou: ' + str(con))
        camada_rede.enviar_requisicao_clear(con.obterId(), con.obterEnderecoLocal(), con.obterEnderecoRemoto())
          
    _pool_conexoes.liberarConexao(con)
  
  
# ============================= #
# DEFININDO FUNCOES DE CALLBACK # 
# ESTAS FUNCOES NUNCA DEVEM SER #
# CHAMADAS DIRETAMENTE PELO     #
# CLIENTE DA API                #
# ============================= #

def _tratar_req_liberar(pacote):
  '''
  Recebe e processa um pacote de requisicao de liberacao da conexao
  '''
  dados = pacote.obterDados()
  
  if(not _dados_possui_endereco_local_e_remoto(dados)):
    return
  
  con = _pool_conexoes.obterConexao(pacote.obterIdConexao())
  con.setReqLiberarRecebida(True)
  estado_con = con.obterEstado()
  _log.logar('Liberando conexao: ' + str(con))
  
  if(estado_con == EstadosConexao.DESCONECTANDO):
    con.setEstado(EstadosConexao.PARADO)
    _log.logar('Conexao interrompida: ' + str(con))
    
  if(estado_con == EstadosConexao.ENVIANDO or
     estado_con == EstadosConexao.RECEBENDO or
     estado_con == EstadosConexao.ESPERANDO):
    con_id = con.obterId()
    enderecos  = dados[camada_rede.ENDERECO_LOCAL] + dados[camada_rede.ENDERECO_REMOTO]
    _log.logar('Conexao ainda nao interrompida acordando demais processos que estao utilizando a conexao para entao interrompe-la: ' + str(con))
    
    if(enderecos in _conectsEmEspera):
      _acordar_processos(enderecos, _conectsEmEspera)
      
    if(con_id in _esperandoCreditos):
       _acordar_processos(con_id, _esperandoCreditos)
       
    if(con_id in _esperandoDados):
      _acordar_processos(con_id, _esperandoDados)
         
  _pool_conexoes.liberarConexao(con)
  
def _tratar_conf_liberar(pacote):
  '''
  Recebe e processa um pacote de confirmacao de liberacao da conexao
  '''
  con = _pool_conexoes.obterConexao(pacote.obterIdConexao())
  con.setEstado(EstadosConexao.PARADO)
  _log.logar('Conexao desconectada: ' + str(con))
  _pool_conexoes.liberarConexao(con)
  
def _tratar_creditos(pacote):
  '''
  Recebe e processa um pacote de creditos, indicando que o usuario remoto deseja receber dados
  e envio creditos para uma determinada conexao
  '''
  dados = pacote.obterDados()
  if(not camada_rede.CREDITOS in dados):
    _log.logar('Erro: Dados do pacote estao imcompletos, falta o campo ' + camada_rede.CREDITOS)
    return
  
  con_id = pacote.obterIdConexao()
  con = _pool_conexoes.obterConexao(con_id)
  con.setCreditos(con.obterCreditos() + dados[camada_rede.CREDITOS])  
  
  if(con_id in _esperandoCreditos):
    _acordar_processos(con_id, _esperandoCreditos)
  
  _pool_conexoes.liberarConexao(con)
  

def _tratar_chamada_aceita(pacote):
  '''
  Recebe e processa um pacote indicando que o usuario remoto aceitou uma chamada
  '''
  dados = pacote.obterDados()
  
  if(not _dados_possui_endereco_local_e_remoto(dados)):
    return
  
  chave = dados[camada_rede.ENDERECO_LOCAL] + dados[camada_rede.ENDERECO_REMOTO] 
  con_id = pacote.obterIdConexao()
  
  con = _pool_conexoes.obterConexao(con_id)
  con.setEstado(EstadosConexao.ESTABELECIDA)
  _log.logar('Conexao estabelecida: ' + str(con))
  _pool_conexoes.liberarConexao(con)
  
  if(chave in _conectsEmEspera):
    _acordar_processos(chave, _conectsEmEspera)
  else:
    _log.logar('Erro: Foi recebido uma confirmacao de chamada aceita porem ninguem esta esperando a confirmacao!!')
    _log.logar('DEBUG: chave: ' + chave)
    _log.logar('DEBUG: Conects esperando: ' + str(_conectsEmEspera))  
  
  
def _tratar_dados(pacote):
  '''
  Recebe e processa um pacote de dados enviado pelo usuario remoto
  '''
  dados = pacote.obterDados()
  con_id = pacote.obterIdConexao()
  con = _pool_conexoes.obterConexao(con_id)
  con.setDados(dados)
  _pool_conexoes.liberarConexao(con)
  
  if(con_id in _esperandoDados):
    _acordar_processos(con_id, _esperandoDados)

def _tratar_req_chamada(pacote):
  '''
  Recebe e processa um pacote de requisicao de chamada
  '''
  con = _pool_conexoes.obterConexao(pacote.obterIdConexao())
  dados = pacote.obterDados()

  if(not _dados_possui_endereco_local_e_remoto(dados)):
    return
  
  end_local = dados[camada_rede.ENDERECO_LOCAL]
  con.setEnderecoLocal(end_local)
  con.setEnderecoRemoto(dados[camada_rede.ENDERECO_REMOTO])
  con.setEstado(EstadosConexao.ENFILEIRADO)
  _log.logar('Conexao setada como enfileirada: '+ str(con))
  
  if(end_local in _listensEmEspera):
    _acordar_processos(end_local, _listensEmEspera)
  else:
    con.setTimer(_TIMEOUT)
    _log.logar('Ninguem estava escutando no endereco local, timer ativado: ' + str(con))
    
  con.setReqLiberarRecebida(False)
  con.setCreditos(0)
  
  _pool_conexoes.liberarConexao(con)
      
    
  
# =============================== #
# REGISTRANDO FUNCOES DE CALLBACK #
# =============================== #

camada_rede.registra_callback(_tratar_req_chamada, TiposDePacote.REQ_CHAMADA)
camada_rede.registra_callback(_tratar_req_liberar, TiposDePacote.REQ_LIBERAR)
camada_rede.registra_callback(_tratar_conf_liberar, TiposDePacote.CONFIRMA_LIBERAR)
camada_rede.registra_callback(_tratar_creditos, TiposDePacote.CREDITO)
camada_rede.registra_callback(_tratar_dados, TiposDePacote.DADOS)
camada_rede.registra_callback(_tratar_chamada_aceita, TiposDePacote.CHAMADA_ACEITA)
sistema.registra_callback_clock(_clock)

# ============== #
# FUNCOES DA API #
# ============== #
def listen(endereco):
  ''' 
  Fica escutando esperando um pedido de conexao no endereco local fornecido,
  esta chamada bloqueia quem esta ouvindo ate que um pedido chegue.
  Exemplo endereco: 127.1.1.1:8000
  Bloqueia ate estabelecer uma conexao e retornar o id da mesma
  '''
  encontrado = False
  con_encontrada = None
  
  for i in range(_NUMERO_MAX_CONEXOES):
    con = _pool_conexoes.obterConexao(i)
    if(con.obterEstado() == EstadosConexao.ENFILEIRADO and 
      con.obterEnderecoLocal() == endereco):
      _log.logar('Conexao estabelecida com o endereco ' + endereco)      
      encontrado = True
      con_encontrada = con
      break
    else:
      _pool_conexoes.liberarConexao(con)
       
  if(not encontrado):
    _aguardar_por_evento(endereco, _listensEmEspera, endereco + ' esta na lista de espera aguardando', 
                         camada_rede.esperar_dados_no_endereco, [endereco])
    return listen(endereco)
  
  con_encontrada.setEstado(EstadosConexao.ESTABELECIDA)
  con_encontrada.setTimer(0)
  camada_rede.aceitar_conexao(con_encontrada.obterId(), con_encontrada.obterEnderecoLocal(), 
                                                        con_encontrada.obterEnderecoRemoto())
  _log.logar('Detalhes da conexao: ' + str(con_encontrada))
  _pool_conexoes.liberarConexao(con_encontrada)
  
  return con_encontrada.obterId()

def connect(endereco_local, endereco_remoto):
  ''' 
  O usuario deseja se conectar ao endereco_remoto a partir do seu 
  endereco local fornecido em endereco_local. Sera enviado um 
  pacote de requisicao de conexao.
  Retorna o id da conexao estabelecida ou um erro
  '''
  _log.logar('Iniciando tentativa de conexao entre ' + endereco_local + ' com ' + endereco_remoto)
  
  for i in range(_NUMERO_MAX_CONEXOES):
    con = _pool_conexoes.obterConexao(i)
    if(con.obterEstado() == EstadosConexao.PARADO):
      con.setEstado(EstadosConexao.ESPERANDO)
      con.setEnderecoLocal(endereco_local)
      con.setEnderecoRemoto(endereco_remoto)
      con.setTimer(0)
      con.setCreditos(0)
      con.setReqLiberarRecebida(False)
      con_id = con.obterId()
      str_con = str(con)
      _pool_conexoes.liberarConexao(con)
      
      chave = endereco_local + endereco_remoto
  
      camada_rede.esperar_dados_no_endereco(endereco_local)
      _log.logar('Esperando pela aceitacao ou recusa do pedido de conexao: ' + str_con)
      _aguardar_por_evento(chave, _conectsEmEspera, ' adcionando evento para esperar aceitacao da conexao ',
                          camada_rede.enviar_requisicao_con, [con_id , endereco_local, endereco_remoto])
        
      con = _pool_conexoes.obterConexao(i)
      _log.logar('Aceitacao ou recusa do pedido de conexao chegou, estado da conexao: ' + str(con))
      
      if(con.obterEstado() == EstadosConexao.ESTABELECIDA):
        _pool_conexoes.liberarConexao(con)
        _log.logar('Conexao estabelecida: ' + str(con))
        return con.obterId()
      
      if(con.obterReqLiberarRecebida()):
        con.setEstado(EstadosConexao.PARADO)
        camada_rede.enviar_confirmacao_clear(con.obterId(), endereco_local, endereco_remoto)
        _pool_conexoes.liberarConexao(con)
        _log.logar('Conexao rejeitada')
        return ErrosTransporte.CONEXAO_REJEITADA
      
      _log.logar('Ops o codigo nao devia chegar aqui, soh Deus sabe o que aconteceu !!')
      _log.logar('Debug Info da Conexao: ' + str(con))
      _pool_conexoes.liberarConexao(con)
      
    else:
      _pool_conexoes.liberarConexao(con)
      
  _log.logar('Tabela de conexoes esta cheia, impossivel realizar connect')
  return ErrosTransporte.TABELA_CHEIA                                             
    
    
def send(con_id, dados):
  '''
  Envia os dados utilizando a conexao com o id fornecido, se a conexao estiver estabelecida
  '''
  con = _pool_conexoes.obterConexao(con_id)
  retorno = _conexao_esta_ok(con)
  if(retorno != ErrosTransporte.OK):
    _pool_conexoes.liberarConexao(con)
    return retorno
  
  if(not con.possuiCreditos()):
    con_detalhes = str(con)
    _pool_conexoes.liberarConexao(con)
    _aguardar_por_evento(con_id, _esperandoCreditos , 'Aguardando por creditos na conexao: ' + con_detalhes)
    return send(con_id, dados)
  
  con.setEstado(EstadosConexao.ENVIANDO)
  _log.logar('Enviando dados, conexao: ' + str(con))
  camada_rede.enviar_dados(con_id, con.obterEnderecoLocal(), con.obterEnderecoRemoto(), dados)
  con.setEstado(EstadosConexao.ESTABELECIDA)
  con.setCreditos(con.obterCreditos() - 1)
  _log.logar('Terminou o envio de dados com sucesso, conexao: ' + str(con))
  _pool_conexoes.liberarConexao(con)
  
  return ErrosTransporte.OK


def receive(con_id):
  '''
  Recebe dados a partir da conexao informada.
  Bloqueia ate receber os dados, e retorna os dados recebidos
  '''
  con = _pool_conexoes.obterConexao(con_id)
  retorno = _conexao_esta_ok(con)
  if(retorno != ErrosTransporte.OK):
    _pool_conexoes.liberarConexao(con)
    return retorno
  
  con.setEstado(EstadosConexao.RECEBENDO)
  camada_rede.enviar_creditos(con.obterId(),con.obterEnderecoLocal(), con.obterEnderecoRemoto(), 1)
  con_data = str(con)
  _pool_conexoes.liberarConexao(con)
  _aguardar_por_evento(con_id, _esperandoDados , msg_log = 'Aguardando dados na conexao: ' + con_data)
  
  con = _pool_conexoes.obterConexao(con_id)
  if(con.obterReqLiberarRecebida()):
    _log.logar('Erro!!! Parceiro pediu para encerrar a conexao!!')
    _log.logar('Detalhes da conexao: ' + str(con))
    _pool_conexoes.liberarConexao(con)
    return ErrosTransporte.CONEXAO_FECHADA
  
  dados = con.obterDados()
  con.setEstado(EstadosConexao.ESTABELECIDA)
  _pool_conexoes.liberarConexao(con)
  
  return dados
    

def disconnect(con_id):
  '''
  Encerra a conexao
  '''
  con = _pool_conexoes.obterConexao(con_id)
  
  if(con.obterReqLiberarRecebida()):
    _log.logar('Usuario remoto ja desconectou')
    con.setEstado(EstadosConexao.PARADO)
    _log.logar('Conexao desconectada: ' + str(con))
    camada_rede.enviar_confirmacao_clear(con_id, con.obterEnderecoLocal(), con.obterEnderecoRemoto())
    _pool_conexoes.liberarConexao(con)
    return ErrosTransporte.OK

  con.setEstado(EstadosConexao.DESCONECTANDO)
  _log.logar('Desconectando conexao: ' + str(con))
  camada_rede.enviar_requisicao_clear(con_id, con.obterEnderecoLocal(), con.obterEnderecoRemoto())
  _pool_conexoes.liberarConexao(con)
  return ErrosTransporte.OK
  