# -*- coding: latin-1 -*-
import copy

class IntegranteU2 ():

  def __init__(self, nome, velocidade):
    self.__nome = nome
    self.__velocidade = velocidade
    
  def ObterNome(self):
    return copy.copy(self.__nome)

  def ObterVelocidade(self):
    return copy.copy(self.__velocidade)


  def __eq__(self, outro):
    if isinstance(outro, IntegranteU2):
      return self.ObterNome() == outro.ObterNome()

    return False
    
  def __ne__(self, other):
    result = self.__eq__(other)
    return not result

  def __hash__(self):
    return hash(self.__nome)