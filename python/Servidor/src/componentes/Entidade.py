import copy
from enum import EstadoDaEntidade

SEM_ID = 'SEM_ID'

class Entidade():
  
  def __init__(self, tipoEntidade, id = SEM_ID):
    self.__tipo = tipoEntidade
    self.__id = id
    self.__estado = EstadoDaEntidade.NAO_SERVIDA
    
  def obterTipo(self):
    return copy.copy(self.__tipo)
  
  def obterID(self):
    return copy.copy(self.__id)
  
  def marcarComoServida(self):
    self.__estado = EstadoDaEntidade.SERVIDA
    
  def marcarComoNaoServida(self):
    self.__estado = EstadoDaEntidade.NAO_SERVIDA

  def marcarComoFalha(self):
    self.__estado = EstadoDaEntidade.FALHOU
        
  def falhou(self):
    return self.__estado == EstadoDaEntidade.FALHOU
    
  def estaServida(self):
    return self.__estado == EstadoDaEntidade.SERVIDA
  
  def naoEstaServida(self):
    return self.__estado == EstadoDaEntidade.NAO_SERVIDA

  def __eq__(self, outraEntidade):
    
    if(not isinstance(outraEntidade,Entidade)):
      return False
    
    cmp1 = self.obterID() == outraEntidade.obterID()
    cmp2 = self.obterTipo() == outraEntidade.obterTipo()
    
    return cmp1 and cmp2
  
  def __neq__(self, outraEntidade):
    return not self.__eq__(outraEntidade)
  
