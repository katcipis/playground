import copy

class Relogio():
  
  def __init__(self, tempoInicial = 0.0):
    self.__tempoAtual = tempoInicial
    
  def adiantarSegundos(self, novoTempo):
      self.__tempoAtual += novoTempo / 60.0
    
  def adiantarMinutos(self, novoTempo):
      self.__tempoAtual += novoTempo
      
  def adiantarHoras(self, novoTempo):
    self.__tempoAtual += novoTempo * 60.0
      
  def adiantarDias(self, novoTempo):
    self.__tempoAtual = novoTempo * 24.0 * 60.0
    
  def obterEmSegundos(self):
    return self.__tempoAtual * 60.0
  
  def obterEmMinutos(self):
    return self.__tempoAtual
  
  def obterEmHoras(self):
    return self.__tempoAtual / 60.0
  
  def obterEmDias(self):
    return self.__tempoAtual / (60.0 * 24.0)