from geradoresDeNumeros.GeradorDeNumerosAleatorios import GeradorDeNumerosAleatorios

class GeradorDeNumerosTriangular(GeradorDeNumerosAleatorios):
  
  def __init__(self, min, media, maximo, semente = None):
    self.__min = min
    self.__media = media
    self.__max = maximo
    GeradorDeNumerosAleatorios.__init__(self, semente)
    
  def gerarValorInteiro(self):
    return int(self._geradorAleatorio.uniform(self.__min, self.__max))
  
  def gerarValorFloat(self):
    return self._geradorAleatorio.uniform(self.__min, self.__max)
