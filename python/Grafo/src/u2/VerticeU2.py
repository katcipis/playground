# -*- coding: latin-1 -*-
import copy

class VerticeU2():
  
  def __init__(self, integrantes, possui_lanterna = False):
    self.__integrantes = copy.copy(integrantes)
    self.__possui_lanterna = possui_lanterna
    
  def ObterIntegrantes(self):
    return copy.copy(self.__integrantes)

  def PossuiLanterna(self):
    return self.__possui_lanterna

  def EstaVazio(self):
    return len(self.__integrantes) is 0
    
  def __eq__(self, outro):
    if isinstance(outro, VerticeU2):
      cond1 = self.ObterIntegrantes() == outro.ObterIntegrantes()
      cond2 = self.PossuiLanterna() == outro.PossuiLanterna()
      return cond1 and cond2

    return False
    
  def __ne__(self, other):
    result = self.__eq__(other)
    return not result

  def __hash__(self):
    hash = self.__possui_lanterna.__hash__()
    
    for integrante in self.__integrantes:
      hash = hash + integrante.__hash__()
    
    return hash

  def __str__(self):
    str = ''
    
    if(len(self.__integrantes) is 0):
      return 'Ninguem esperando para atravessar'
      

    for i in self.__integrantes:
      str = str + ' ' + i.ObterNome()
         
    if(self.__possui_lanterna):  
      str = str + ' : ' + 'possuem lanterna'
    else:
      str = str + ' : ' + 'nao possuem lanterna'
      
    return str