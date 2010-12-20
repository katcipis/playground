import copy

class Evento:
  
  def __init__(self, tipoEvento, tempoQueOcorre, entidade = None):
    self.__tempoQueOcorre = tempoQueOcorre
    self.__tipoEvento = tipoEvento
    self.__entidade = entidade
    
  def obterTempoQueOcorre(self):
    return copy.copy(self.__tempoQueOcorre)
  
  def obterTipo(self):
    return copy.copy(self.__tipoEvento)
  
  def possuiEntidade(self):
    return self.__entidade != None
    
  def obterEntidade(self):
    return copy.copy(self.__entidade)
  
  def designarEntidade(self, entidade):
    self.__entidade = entidade

      