'''
Created on 16/06/2009
@author: Katcipis
Modulo contendo as funcoes disponiveis nesta camada de rede
'''

from rede import TiposDePacote
from rede.PacoteDeDados import PacoteDeDados
from util import sistema
from util.Log import Log

# ========================================= #
# Chaves para acessar os dados do pacote    #
# nem sempre estas chaves estarao presentes #
# nos dados do pacote, isto depende do      #
# tipo do pacote recebido                   #
# ========================================= #
ENDERECO_LOCAL  = 'endereco_local'
ENDERECO_REMOTO = 'endereco_remoto'
CREDITOS        = 'creditos'
 
# ================= #
# VARIAVEIS GLOBAIS #
# ================= #
_funcoes_callback = {}
_SEPARADOR_DADOS  = ':'
_log = Log('Camada de Rede: ')

# ================ #
# FUNCOES PRIVADAS #
# ================ #

def _trata_chegada_dados(end_local, end_remoto, dados):
  '''
  Funcao interna que faz o parse da chegada dos dados do sistema.
  O unico tipo de pacote que nao possui os enderecos eh o de dados.
  '''
  lista_dados = dados.split(_SEPARADOR_DADOS)
  if(len(lista_dados) < 2):
    _log.logar('Erro critico, dados vieram corrompidos')
    _log.logar('Dados: ' + dados)
    
  tipo_pacote = lista_dados[0]
  id_con = lista_dados[1]
  
  if(not tipo_pacote in _funcoes_callback):
    _log.logar('Nao existe funcao de callback para o seguinte tipo de pacote: ' + tipo_pacote)
    return
  
  if(tipo_pacote == TiposDePacote.DADOS):
    dados_pac = lista_dados[2]
  else:
    dados_pac = {
                 ENDERECO_LOCAL : end_local,
                 ENDERECO_REMOTO : end_remoto
                 }
    if(tipo_pacote == TiposDePacote.CREDITO):
      dados_pac[CREDITOS] = int(lista_dados[2])
      
  for callback in _funcoes_callback[tipo_pacote]:
    callback(PacoteDeDados(tipo_pacote, id_con, dados_pac))
    
  
sistema.registra_callback_server(_trata_chegada_dados)

# =========== #
# FUNCOES API #
# =========== #
def registra_callback(funcao, tipo_pacote):
  '''
  Registra a funcao como uma das funcoes que serao chamadas 
  sempre que um pacote do tipo informado chegar da rede.
  As funcoes devem receber um argumento que sera o pacote.
  '''
  if(not tipo_pacote in _funcoes_callback):
    _funcoes_callback[tipo_pacote] = set()
    
  _funcoes_callback[tipo_pacote].add(funcao)
  

def esperar_dados_no_endereco(end_local):
  '''
  Deve ser chamado sempre que se esperar a chegada de dados neste endereco local
  '''
  sistema.criar_servidor(end_local)
  _log.logar('Servidor criado para escutar no endereco local: ' + end_local)

def aceitar_conexao(con_id, end_local, end_remoto):
  ''' 
  Envia ao endereco_remoto uma confirmacao de que a conexao foi aceita, 
  enviando tb o identificador da conexao.
  '''
  dados = TiposDePacote.CHAMADA_ACEITA + _SEPARADOR_DADOS
  dados += str(con_id)
  sistema.enviar_dados(end_local, end_remoto, dados)
  
def enviar_requisicao_con(con_id, end_local, end_remoto):
  '''
  Envia ao endereco_remoto um pedido de estabelecimento de conexao.
  '''
  dados = TiposDePacote.REQ_CHAMADA + _SEPARADOR_DADOS
  dados += str(con_id)
  sistema.enviar_dados(end_local, end_remoto, dados)
  
def enviar_requisicao_clear(con_id, end_local, end_remoto):
  '''
  Envia ao endereco_remoto um pedido de encerramento de conexao.
  '''
  dados = TiposDePacote.REQ_LIBERAR + _SEPARADOR_DADOS
  dados += str(con_id)
  sistema.enviar_dados(end_local, end_remoto, dados)
  
def enviar_confirmacao_clear(con_id, end_local, end_remoto):
  '''
  Envia uma confirmacao de que recebeu um pedido de liberacao de conexao
  '''
  dados = TiposDePacote.CONFIRMA_LIBERAR + _SEPARADOR_DADOS
  dados += str(con_id)
  sistema.enviar_dados(end_local, end_remoto, dados)
  
def enviar_creditos(con_id, end_local, end_remoto, cred):
  '''
  Envia creditos para o end remoto de acordo com o id da conexao informado
  '''
  dados = TiposDePacote.CREDITO + _SEPARADOR_DADOS
  dados += str(con_id) + _SEPARADOR_DADOS
  dados += str(cred)
  sistema.enviar_dados(end_local, end_remoto, dados)
  
def enviar_dados(con_id, end_local, end_remoto, dados_env):
  '''
  Envia dados para o ip_remoto utilizando a conexao con_id
  '''
  dados = TiposDePacote.DADOS + _SEPARADOR_DADOS
  dados += str(con_id) + _SEPARADOR_DADOS
  dados += dados_env
  sistema.enviar_dados(end_local, end_remoto, dados)
  