
class MediaEntidadesNaFila():
  
  def __init__(self):
    self.__amostras = []
    
  def adcionarAmostra(self, tempoQueFicouConstante, qtdadeEntidadesNaFila):
    self.__amostras.append( (tempoQueFicouConstante, qtdadeEntidadesNaFila) )
    
  def __obterTempoTotalAmostrado(self):
    total = 0.0
    for amostra in self.__amostras:
      total += amostra[0]
      
    return total
    
  def obterMedia(self):
    total = self.__obterTempoTotalAmostrado()
    media = 0.0
    
    for amostra in self.__amostras:
      media += amostra[1] * (amostra[0] / total)
      
    return media