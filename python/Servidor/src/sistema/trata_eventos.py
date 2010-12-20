from enum  import TipoDaEntidade
from enum import TipoDoEvento
from componentes.Evento import Evento
from componentes.Entidade import Entidade

# INICIO TRATADOR DE ENTRADAS

def tratarEventoDeEntrada(sistema, proximoEvento):
  entidade = proximoEvento.obterEntidade()
  
  if(sistema._servidorUm.estaEmFalha() and sistema._servidorDois.estaEmFalha()):  
    sistema._loglist.append(sistema._obterTempoFormatado() + 'Servidores estao em falha, descartando ' + str(entidade.obterID()))
    entidade.marcarComoFalha()
    sistema._listaDeEventosFuturos.adcionarEvento(Evento(TipoDoEvento.SAIDA, 
                                                  proximoEvento.obterTempoQueOcorre(), 
                                                  entidade))
    return None
  
  if(sistema._servidorUm.estaLivre()):
    sistema._tempoRestanteDeServicoServidorUm   = sistema._geradorDeTempoDeServicoServidorUm.gerarValorInteiro()
    sistema._mediaOcupacaoServidorUm.adcionarAmostra(sistema._tempoRestanteDeServicoServidorUm)
    sistema._servidorUm.servirEntidade(entidade)
    sistema._loglist.append(sistema._obterTempoFormatado() + 'Servidor 1 esta recebendo ' + str(entidade.obterID()))
    return None
      
  if(not sistema._filaDoServidorUm.estaCheia()):
    sistema._loglist.append(sistema._obterTempoFormatado() + str(entidade.obterID()) + ' esta entrando na fila do servidor 1')
    sistema._filaDoServidorUm.adcionarEntidade((entidade, proximoEvento.obterTempoQueOcorre()))
    return None
    
      
  if(sistema._servidorDois.estaLivre()):
    sistema._tempoRestanteDeServicoServidorDois   = sistema._geradorDeTempoDeServicoServidorDois.gerarValorInteiro()
    sistema._mediaOcupacaoServidorDois.adcionarAmostra(sistema._tempoRestanteDeServicoServidorDois)
    sistema._servidorDois.servirEntidade(entidade)
    sistema._loglist.append(sistema._obterTempoFormatado() + ' por troca o Servidor 2 esta recebendo ' + str(entidade.obterID()))
    sistema._contadorDeTrocasNosServidores += 1
    return None
  
  if(not sistema._filaDoServidorDois.estaCheia()):
    sistema._filaDoServidorDois.adcionarEntidade((entidade, proximoEvento.obterTempoQueOcorre()))
    sistema._loglist.append(sistema._obterTempoFormatado() + str(entidade.obterID()) + ' esta entrando na fila do servidor 2 por troca')
    sistema._contadorDeTrocasNosServidores += 1
    return None

# FIM TRATADOR DE ENTRADAS  

def aindaNaoEstaNoHistoricoDeSaida(sistema, proximoEvento):
  for evento in sistema._historicoDeSaidaDeEntidades:
    if(evento.obterEntidade() == proximoEvento.obterEntidade()):
      return False
    
  return True

# INICIO TRATADOR DE SAIDAS
def tratarEntidadeTipoUmMudandoDeServidor(sistema, entidade, proximoEvento):
  if(sistema._servidorDois.estaLivre()):
    sistema._tempoRestanteDeServicoServidorDois   = sistema._geradorDeTempoDeServicoServidorDois.gerarValorInteiro()
    sistema._mediaOcupacaoServidorDois.adcionarAmostra(sistema._tempoRestanteDeServicoServidorDois)
    sistema._servidorDois.servirEntidade(entidade)
    sistema._loglist.append(sistema._obterTempoFormatado() + ' Servidor 2 esta recebendo ' + str(entidade.obterID()))
    return None
  
  if(not sistema._filaDoServidorDois.estaCheia()):
    sistema._filaDoServidorDois.adcionarEntidade((entidade, proximoEvento.obterTempoQueOcorre()))
    sistema._loglist.append(sistema._obterTempoFormatado() + str(entidade.obterID()) + ' esta entrando na fila do servidor 2')
    return None
    
  sistema._loglist.append(sistema._obterTempoFormatado() + 'Servidores estao em falha, descartando ' + str(entidade.obterID()))
  
  if(aindaNaoEstaNoHistoricoDeSaida(sistema, proximoEvento)):
    self._historicoDeSaidaDeEntidades.append(proximoEvento)

def tratarEventoDeSaida(sistema, proximoEvento):
  entidade = proximoEvento.obterEntidade()
  
  if(entidade.naoEstaServida()):
    tratarEntidadeTipoUmMudandoDeServidor(sistema, entidade, proximoEvento)
    return None
    
  if(entidade.falhou()):
    sistema._loglist.append(sistema._obterTempoFormatado() + 'entidade com falha sendo descartada ' + str(entidade.obterID()))
  
    if(aindaNaoEstaNoHistoricoDeSaida(sistema, proximoEvento)):
      sistema._historicoDeSaidaDeEntidades.append(proximoEvento)
    
    return None
  
  sistema._loglist.append(sistema._obterTempoFormatado() + 'entidade servida com sucesso saindo do sistema ' + str(entidade.obterID()))
  
  if(aindaNaoEstaNoHistoricoDeSaida(sistema, proximoEvento)):
    sistema._historicoDeSaidaDeEntidades.append(proximoEvento)
    
# FIM TRATADOR DE SAIDAS