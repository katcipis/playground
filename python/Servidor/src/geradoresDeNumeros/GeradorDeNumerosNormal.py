from geradoresDeNumeros.GeradorDeNumerosAleatorios import GeradorDeNumerosAleatorios

class GeradorDeNumerosNormal(GeradorDeNumerosAleatorios):
  
  def __init__(self, media, desvioPadrao, semente = None):
    
    GeradorDeNumerosAleatorios.__init__(self, semente)
    self.__media = media
    self.__desvioPadrao = desvioPadrao
    
  def gerarValorInteiro(self):
    return int(self._geradorAleatorio.normalvariate(self.__media, self.__desvioPadrao))

  def gerarValorFloat(self):
    return self._geradorAleatorio.normalvariate(self.__media, self.__desvioPadrao)
