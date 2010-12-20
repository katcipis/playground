import init_sistema
import checa_servidores
import trata_eventos
import relatorio_sistema
from componentes.Relogio import Relogio
from componentes.Servidor import Servidor
from componentes.ListaDeEventosFuturos import ListaDeEventosFuturos
from componentes.Evento import Evento
from enum import TipoDoEvento
from enum import TipoDaEntidade

class Simulador():
  
  def __init__(self, geradorDeChegadasDeEntidades,
                     geradorDeTempoEntreFalhasServidorUm,
                     geradorDeTempoEntreFalhasServidorDois,
                     geradorDeTempoDeFalhaServidorUm,
                     geradorDeTempoDeFalhaServidorDois,
                     geradorDeTempoDeServicoServidorUm, 
                     geradorDeTempoDeServicoServidorDois,
                     filaDoServidorUm,
                     filaDoServidorDois, 
                     loglist):
    
    init_sistema.iniciarContadores(self)
    init_sistema.iniciarCalculadoresDeMedia(self)
    init_sistema.iniciarSomadoresDeTempoTotal(self)
    init_sistema.iniciarComponentesDosServidores(self, filaDoServidorUm, filaDoServidorDois)
    self._relogio = Relogio()   
    self._listaDeEventosFuturos = ListaDeEventosFuturos()
    self._historicoDeChegadaDeEntidades = []
    self._historicoDeSaidaDeEntidades = []
    self._tempoRestanteDeSimulacao = 0

    self._geradorDeChegadasDeEntidades = geradorDeChegadasDeEntidades
    self._geradorDeTempoEntreFalhasServidorUm = geradorDeTempoEntreFalhasServidorUm
    self._geradorDeTempoEntreFalhasServidorDois = geradorDeTempoEntreFalhasServidorDois
    
    self._geradorDeTempoDeServicoServidorUm = geradorDeTempoDeServicoServidorUm
    self._geradorDeTempoDeServicoServidorDois = geradorDeTempoDeServicoServidorDois
    
    self._geradorDeTempoDeFalhaServidorUm   = geradorDeTempoDeFalhaServidorUm
    self._geradorDeTempoDeFalhaServidorDois = geradorDeTempoDeFalhaServidorDois
    self._loglist = loglist
    self._simulacaoAcabou = True
    self._tempoTotalDeSimulacao = 0
    
  def iniciarSimulacao(self, tempoTotalDeSimulacao):
    listaDeChegadas = self._geradorDeChegadasDeEntidades.obterListaDeChegadasDasEntidades(tempoTotalDeSimulacao, 0)
    self._simulacaoAcabou = False
    
    while (listaDeChegadas.possuiEvento()):
      evento = listaDeChegadas.obterProximoEvento()
      self._listaDeEventosFuturos.adcionarEvento(evento)
    
    self._tempoRestanteDeSimulacao += tempoTotalDeSimulacao
    self._tempoTotalDeSimulacao += tempoTotalDeSimulacao
    self.simulaUmPasso()
      
  def simulaUmPasso(self):
    if(self._simulacaoAcabou):
      return False
    
    proximoEvento = self._listaDeEventosFuturos.obterProximoEvento()    
    avancoDeTempo = 0
    
    if(proximoEvento != None):
      if(proximoEvento.obterTempoQueOcorre() > self._relogio.obterEmMinutos()):
        avancoDeTempo = proximoEvento.obterTempoQueOcorre() - self._relogio.obterEmMinutos()
    
    
    checa_servidores.checarSeServidorUmEntraEmFalha(self, avancoDeTempo)
    checa_servidores.checarSeServidorDoisEntraEmFalha(self, avancoDeTempo)
    checa_servidores.checarSeAlgumServidorSaiDaFalha(self, avancoDeTempo)
 
    checa_servidores.checarSeServidorUmTerminouOServico(self, avancoDeTempo)
    checa_servidores.checarSeServidorDoisTerminouOServico(self, avancoDeTempo)
    
    if(proximoEvento != None):
      if(proximoEvento.obterTipo() == TipoDoEvento.ENTRADA):
        self._historicoDeChegadaDeEntidades.append(proximoEvento)
        trata_eventos.tratarEventoDeEntrada(self, proximoEvento)
    
      elif(proximoEvento.obterTipo() == TipoDoEvento.SAIDA):
        trata_eventos.tratarEventoDeSaida(self, proximoEvento)
      
      elif(proximoEvento.obterTipo() == TipoDoEvento.FIM_DA_SIMULACAO):
        self._relogio.adiantarMinutos(avancoDeTempo)
        self._loglist.append(self._obterTempoFormatado() + 'Simulacao terminou.')
        self._simulacaoAcabou = True
        
      
    self._relogio.adiantarMinutos(avancoDeTempo)
    if(proximoEvento == None):
      self._tempoRestanteDeSimulacao -= 1
    
    self._tempoRestanteDeSimulacao -= avancoDeTempo
    if(self._tempoRestanteDeSimulacao < 0):
      self._listaDeEventosFuturos.adcionarEvento(Evento(TipoDoEvento.FIM_DA_SIMULACAO, self._relogio.obterEmMinutos()))  
    
    self._amostrasEntidadesEsperandoNaFilaUm.append(self._filaDoServidorUm.obterQuantasEntidadesPossui())
    self._amostrasEntidadesEsperandoNaFilaDois.append(self._filaDoServidorDois.obterQuantasEntidadesPossui())
    
    return True
     
     
  def _obterTempoFormatado(self):
    return 'Tempo no relogio: '+ str(self._relogio.obterEmMinutos()) + ' min '
  
  def gerarRelatorioDaSimulacao(self, nomeDoArquivoDoRelatorio):
    relatorio_sistema.gerarRelatorio(self, nomeDoArquivoDoRelatorio)

  def gerarRelatorioParcialDaSimulacao(self, nomeDoArquivoDoRelatorio):
    relatorio_sistema.gerarRelatorioParcial(self, nomeDoArquivoDoRelatorio)
