
class TempoMedioDeEntidadesEmAlgo():
  
  def __init__(self):
    self.__temposNaFila = []
    
  def adcionarAmostra(self, tempoNaFila):
    self.__temposNaFila.append(tempoNaFila)
    
  def obterMedia(self):
    amostras = len(self.__temposNaFila)
    if(amostras == 0):
      return 0
    
    total = 0
    for tempo in self.__temposNaFila:
       total += tempo
       
    return float(total) / float(amostras)