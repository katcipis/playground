# INICIO DA CHECAGEM DE TERMINACAO DE SERVICO
from componentes.Evento import Evento
from enum import TipoDoEvento
from enum import TipoDaEntidade

def checarSeServidorUmTerminouOServico(self, avancoDeTempo):
  if(self._servidorUm.estaEmFalha()):
    return None
    
  if(self._tempoRestanteDeServicoServidorUm == 0):
    self._loglist.append(self._obterTempoFormatado() + 'Servidor 1 esta ocioso')
    return None
    
  if(self._tempoRestanteDeServicoServidorUm > avancoDeTempo):
    self._tempoRestanteDeServicoServidorUm -= avancoDeTempo
    return None
    
  if(self._filaDoServidorUm.estaVazia()):
    removerEntidadeDoServidorUm(self)
    self._tempoRestanteDeServicoServidorUm = 0
    self._loglist.append(self._obterTempoFormatado() + 'Servidor 1 esta ocioso')
    return None
      
  removerEntidadeDoServidorUm(self)
    
  entidade, tempoQueEntrouNaFila = self._filaDoServidorUm.obterEntidade()
  self._tempoMedioNaFilaDoServidorUm.adcionarAmostra((self._relogio.obterEmMinutos() + self._tempoRestanteDeServicoServidorUm) - tempoQueEntrouNaFila)
  
  self._tempoRestanteDeServicoServidorUm = self._geradorDeTempoDeServicoServidorUm.gerarValorInteiro()
  self._mediaOcupacaoServidorUm.adcionarAmostra(self._tempoRestanteDeServicoServidorUm)
  
  self._servidorUm.servirEntidade(entidade)
  self._loglist.append('Entidade ' + str(entidade.obterID()) + ' acabou de sair da fila do Servidor 1 para ser servida')
     
def removerEntidadeDoServidorUm(self):
  entidadeSaindo = self._servidorUm.obterEntidadeSendoServida()
  self._servidorUm.terminarServico()

  if(entidadeSaindo.obterTipo() == TipoDaEntidade.TIPO_UM):
    entidadeSaindo.marcarComoNaoServida()

  self._listaDeEventosFuturos.adcionarEvento(Evento(TipoDoEvento.SAIDA, 
                                                   (self._relogio.obterEmMinutos() + self._tempoRestanteDeServicoServidorUm), 
                                                    entidadeSaindo))   
     
   
def removerEntidadeDoServidorDois(self):
  entidadeSaindo = self._servidorDois.obterEntidadeSendoServida()
  self._servidorDois.terminarServico()
    
  self._listaDeEventosFuturos.adcionarEvento(Evento(TipoDoEvento.SAIDA, 
                                                   (self._relogio.obterEmMinutos() + self._tempoRestanteDeServicoServidorUm), 
                                                    entidadeSaindo))
   
def checarSeServidorDoisTerminouOServico(self, avancoDeTempo):
  if(self._servidorDois.estaEmFalha()):
    return None
    
  if(self._tempoRestanteDeServicoServidorDois == 0):
    self._loglist.append(self._obterTempoFormatado() + 'Servidor 2 esta ocioso')
    return None
    
  if(self._tempoRestanteDeServicoServidorDois > avancoDeTempo):
    self._tempoRestanteDeServicoServidorDois -= avancoDeTempo
    return None
    
  if(self._filaDoServidorDois.estaVazia()):
    removerEntidadeDoServidorDois(self)
    self._tempoRestanteDeServicoServidorDois = 0
    self._loglist.append(self._obterTempoFormatado() + 'Servidor 2 esta ocioso')
    return None
      
  removerEntidadeDoServidorDois(self)
    
  entidade, tempoQueEntrouNaFila = self._filaDoServidorDois.obterEntidade()
  self._tempoMedioNaFilaDoServidorDois.adcionarAmostra((self._relogio.obterEmMinutos() + self._tempoRestanteDeServicoServidorUm) - tempoQueEntrouNaFila)

  self._tempoRestanteDeServicoServidorDois = self._geradorDeTempoDeServicoServidorDois.gerarValorInteiro()
  self._mediaOcupacaoServidorDois.adcionarAmostra(self._tempoRestanteDeServicoServidorDois)
  
  self._servidorDois.servirEntidade(entidade)
  self._loglist.append('Entidade ' + str(entidade.obterID()) + ' acabou de sair da fila do Servidor 2 para ser servida')
     
     
     
# FIM DA CHECAGEM DE TERMINACAO DE SERVICO
     
     
# INICIO DA CHECAGEM SE O SERVIDOR ENTRA EM FALHA   
     
def checarSeServidorUmEntraEmFalha(self, avancoDeTempo):
  if(self._tempoQueFaltaParaFalharServidorUm == 0):
    self._tempoQueFaltaParaFalharServidorUm = self._geradorDeTempoEntreFalhasServidorUm.gerarValorInteiro()
    return None
    
  if(self._tempoQueFaltaParaFalharServidorUm > avancoDeTempo):
    self._tempoQueFaltaParaFalharServidorUm = self._tempoQueFaltaParaFalharServidorUm - avancoDeTempo
    return None
    
  self._tempoRestanteDeFalhaServidorUm = self._geradorDeTempoDeFalhaServidorUm.gerarValorInteiro()
  self._tempoQueFaltaParaFalharServidorUm = self._tempoRestanteDeFalhaServidorUm + self._geradorDeTempoEntreFalhasServidorUm.gerarValorInteiro()
     
  self._contadorDeFalhasNoServidorUm += 1
  self._tempoTotalDeFalhaDoServidorUm += self._tempoRestanteDeFalhaServidorUm
  self._loglist.append('Servidor 1 vai entrar em falha por ' + str(self._tempoRestanteDeFalhaServidorUm) + ' Minutos ' + 
                       'no tempo ' + str(self._tempoQueFaltaParaFalharServidorUm + self._relogio.obterEmMinutos()))
  self._servidorUm.falhar()
  
def checarSeServidorDoisEntraEmFalha(self, avancoDeTempo):
  if(self._tempoQueFaltaParaFalharServidorDois == 0):
    self._tempoQueFaltaParaFalharServidorDois = self._geradorDeTempoEntreFalhasServidorDois.gerarValorInteiro()
    return None
    
  if(self._tempoQueFaltaParaFalharServidorDois > avancoDeTempo):
    self._tempoQueFaltaParaFalharServidorDois = self._tempoQueFaltaParaFalharServidorDois - avancoDeTempo
    return None
   
  self._tempoRestanteDeFalhaServidorDois = self._geradorDeTempoDeFalhaServidorDois.gerarValorInteiro()
  self._tempoQueFaltaParaFalharServidorDois = self._tempoRestanteDeFalhaServidorDois + self._geradorDeTempoEntreFalhasServidorDois.gerarValorInteiro()
     
  self._contadorDeFalhasNoServidorDois += 1
  self._tempoTotalDeFalhaDoServidorDois += self._tempoRestanteDeFalhaServidorDois
  self._loglist.append('Servidor 2 vai entrar em falha por ' + str(self._tempoRestanteDeFalhaServidorDois) + ' Minutos ' + 
                       'no tempo ' + str(self._tempoQueFaltaParaFalharServidorUm + self._relogio.obterEmMinutos()))
  self._servidorDois.falhar()
    
  
# FIM DA CHECAGEM SE O SERVIDOR ENTRA EM FALHA
    
def checarSeAlgumServidorSaiDaFalha(self, avancoDeTempo):
  if(self._servidorUm.estaEmFalha()):
    self._tempoRestanteDeFalhaServidorUm, self._tempoRestanteDeServicoServidorUm =   tratarServidorEmFalha(self, self._servidorUm,
                                                                                     self._tempoRestanteDeFalhaServidorUm, 
                                                                                     self._filaDoServidorUm,
                                                                                     avancoDeTempo,
                                                                                     self._geradorDeTempoDeServicoServidorUm,
                                                                                     self._tempoMedioNaFilaDoServidorUm)
    if(self._tempoRestanteDeServicoServidorUm != 0):
      self._mediaOcupacaoServidorUm.adcionarAmostra(self._tempoRestanteDeServicoServidorUm)
      
  if(self._servidorDois.estaEmFalha()):
    self._tempoRestanteDeFalhaServidorDois, self._tempoRestanteDeServicoServidorDois =   tratarServidorEmFalha(self, self._servidorDois, 
                                                                                         self._tempoRestanteDeFalhaServidorDois, 
                                                                                         self._filaDoServidorDois,
                                                                                         avancoDeTempo,
                                                                                         self._geradorDeTempoDeServicoServidorDois,
                                                                                         self._tempoMedioNaFilaDoServidorDois)
    if(self._tempoRestanteDeServicoServidorDois != 0):
      self._mediaOcupacaoServidorDois.adcionarAmostra(self._tempoRestanteDeServicoServidorDois)
      
def tratarServidorEmFalha(self, servidor, tempoRestanteDeFalha, filaDoServidor, 
                              avancoDeTempo, geradorDeTempoDeServico, tempoMedioNaFilaDoServidor):
    
  if(tempoRestanteDeFalha > avancoDeTempo):
    return (tempoRestanteDeFalha - avancoDeTempo), 0
    
  servidor.funcionar()
  self._loglist.append(str(servidor.obterId()) + ' voltou a funcionar')
    
  if(filaDoServidor.estaVazia()):
    return 0, 0
    
  tempoDeServico = geradorDeTempoDeServico.gerarValorInteiro()
  entidade, tempoQueEntrouNaFila = filaDoServidor.obterEntidade()
  tempoMedioNaFilaDoServidor.adcionarAmostra((self._relogio.obterEmMinutos() + tempoRestanteDeFalha) - tempoQueEntrouNaFila)
    
  self._loglist.append(str(entidade.obterID()) + ' acabou de sair da fila do ' + str(servidor.obterId()) + ' para ser servida')
  servidor.servirEntidade(entidade)
  self._listaDeEventosFuturos.adcionarEvento(Evento(TipoDoEvento.SAIDA, 
                                                      self._relogio.obterEmMinutos() + tempoRestanteDeFalha + tempoDeServico, 
                                                      entidade)) 
    
  self._loglist.append(str(entidade.obterID()) + ' esta sendo servida pelo ' + str(servidor.obterId()))
  return 0, tempoDeServico
  

  