from geradoresDeNumeros.GeradorDeNumeros import GeradorDeNumeros
import random

class GeradorDeNumerosAleatorios(GeradorDeNumeros):
  
  def __init__(self, maximo = 1, semente = None):
    
    self._geradorAleatorio = random.Random()
    if(semente != None):
      self._geradorAleatorio = random.Random(semente)
    
    self.__maximo = maximo
    
  def gerarValorInteiro(self):
    return int(self._geradorAleatorio.random() * self.__maximo)
  
  def gerarValorFloat(self):
    return self._geradorAleatorio.random() * self.__maximo
  
