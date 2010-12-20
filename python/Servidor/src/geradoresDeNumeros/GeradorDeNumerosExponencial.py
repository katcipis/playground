from geradoresDeNumeros.GeradorDeNumerosAleatorios import GeradorDeNumerosAleatorios

class GeradorDeNumerosExponencial(GeradorDeNumerosAleatorios):
  
  def __init__(self, media, semente = None):
    GeradorDeNumerosAleatorios.__init__(self, semente)
    self.__media = media
    
  def gerarValorInteiro(self):
    return int(self._geradorAleatorio.expovariate(1.0 / self.__media))

  def gerarValorFloat(self):
    return self._geradorAleatorio.expovariate(1.0 / self.__media)
