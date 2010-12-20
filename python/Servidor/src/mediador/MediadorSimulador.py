from componentes.FilaDoServidor import FilaDoServidor
from mediador.MediadorLimitesDasFilas import MediadorLimitesDasFilas
from mediador.MediadorTempoEntreChegadas import MediadorTempoEntreChegadas
from mediador.MediadorTemposEmGeral import MediadorTemposEmGeral
from sistema.Simulador import Simulador
import time
import threading

class MediadorSimulador(threading.Thread):
  
  def __init__(self, mediadorTempoEntreChegadas, mediadorTempoDeServico,
               mediadorTempoEmFalha, mediadorTempoEntreFalhas,
               mediadorLimiteDasFilas, mediadorLocalizacaoRelatorio,
               mediadorTempoDeDuracao):
    
    self.__mediadorTempoEntreChegadas = mediadorTempoEntreChegadas
    self.__mediadorTempoDeServico = mediadorTempoDeServico 
    self.__mediadorTempoEmFalha = mediadorTempoEmFalha
    self.__mediadorTempoEntreFalhas = mediadorTempoEntreFalhas 
    self.__mediadorLimiteDasFilas = mediadorLimiteDasFilas
    self.__mediadorLocalizacaoRelatorio = mediadorLocalizacaoRelatorio
    self.__mediadorTempoDeDuracao = mediadorTempoDeDuracao
    self.__listaDeLog = []
    self.__simular = False
    
    threading.Thread.__init__(self)
    
  def run(self):
    geradorDeChegadas = self.__mediadorTempoEntreChegadas.obterGeradorDeTempo()
    geradorDeTempoEntreFalhasServidorUm, geradorDeTempoEntreFalhasServidorDois = self.__mediadorTempoEntreFalhas.obterGeradorDeTempo()  
    geradorDeTempoDeFalhaServidorUm, geradorDeTempoDeFalhaServidorDois = self.__mediadorTempoEmFalha.obterGeradorDeTempo()
    geradorDeTempoDeServicoServidorUm, geradorDeTempoDeServicoServidorDois  = self.__mediadorTempoDeServico.obterGeradorDeTempo()
    
    limiteUm, limiteDois = self.__mediadorLimiteDasFilas.obterLimitesDasFilas()
    
    filaDoServidorUm = FilaDoServidor(limiteUm)
    filaDoServidorDois = FilaDoServidor(limiteDois)
    
    simulador = Simulador(geradorDeChegadas, 
                    geradorDeTempoEntreFalhasServidorUm,
                    geradorDeTempoEntreFalhasServidorDois,
                    geradorDeTempoDeFalhaServidorUm,
                    geradorDeTempoDeFalhaServidorDois,
                    geradorDeTempoDeServicoServidorUm, 
                    geradorDeTempoDeServicoServidorDois,
                    filaDoServidorUm,
                    filaDoServidorDois,
                    self.__listaDeLog)
    
    simulador.iniciarSimulacao(self.__mediadorTempoDeDuracao.obterTempoDeDuracao())
    i = 1
    self.__simular = True
    self.__listaDeLog.append(' ------- Simulando passo ' + str(i) + ' -------')
    
    while(simulador.simulaUmPasso() and self.__simular):
      self.__listaDeLog.append(' ------- Simulando passo ' + str(i) + ' -------')
      i+= 1
      time.sleep(0.1)
    
    if(not self.__simular):
      simulador.gerarRelatorioParcialDaSimulacao(self.__mediadorLocalizacaoRelatorio.obterLocalizacaoRelatorio())
    else:
      simulador.gerarRelatorioDaSimulacao(self.__mediadorLocalizacaoRelatorio.obterLocalizacaoRelatorio())    
    
  def obterAListaDeLog(self):
    return self.__listaDeLog
  
  def cancelarSimulacao(self):
    self.__simular = False
    
  def simulacaoTerminou(self):
    return not self.__simular