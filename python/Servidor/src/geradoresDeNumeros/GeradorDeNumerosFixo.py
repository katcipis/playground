from geradoresDeNumeros.GeradorDeNumeros import GeradorDeNumeros
import random

class GeradorDeNumerosFixo(GeradorDeNumeros):
  
  def __init__(self, valor = 1, semente = None):
    self.__valor = valor
    
  def gerarValorInteiro(self):
    return int(self.__valor)
  
  def gerarValorFloat(self):
    return float(self.__valor)
  
