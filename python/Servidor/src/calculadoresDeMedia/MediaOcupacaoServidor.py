
class MediaOcupacaoServidor():
  
  def __init__(self):
    self.__totalTempoOcupado = 0.0
    
  def adcionarAmostra(self, tempoQueFicouOcupado):
    self.__totalTempoOcupado += tempoQueFicouOcupado
    
  def obterMedia(self, tempoTotalDeSimulacao):
    if(tempoTotalDeSimulacao == 0):
      return 0
      
    return self.__totalTempoOcupado / tempoTotalDeSimulacao 