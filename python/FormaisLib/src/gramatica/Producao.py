'''
Created on 26/10/2009
@author: katcipis
'''
from enum.separadores import SEPARADOR_SIMBOLO_PRODUCAO

class Producao(object):
  '''
  Define a producao de uma gramatica.
  '''

  def __remover_espacos_extra(self, palavra):
    simbolos = [simbolo for simbolo in palavra.split(SEPARADOR_SIMBOLO_PRODUCAO) if simbolo != '']
    palavra = simbolos.pop(0)
    for simbolo in simbolos:
      palavra += SEPARADOR_SIMBOLO_PRODUCAO + simbolo
    return palavra

  def __init__(self, alpha, beta):
    '''
    Construtor
    @param alpha: alpha que deriva (produz) beta.
    @param beta:  beta que eh produzido (derivado) por alpha.
    '''
    self.__alpha = self.__remover_espacos_extra(alpha)
    self.__beta = self.__remover_espacos_extra(beta)
    
  def obterAlpha(self):
    return self.__alpha
  
  def obterBeta(self):
    return self.__beta
  
  def obterTamanhoBeta(self):
    return len(self.__beta.split(SEPARADOR_SIMBOLO_PRODUCAO))
  
  def obterSimboloBeta(self, indice):
    simbolos = self.__beta.split(SEPARADOR_SIMBOLO_PRODUCAO)
    if(indice < len(simbolos)):
      return simbolos[indice]
  
    return None
  
  def __str__(self):
    return self.__alpha + ' ::= ' + self.__beta
  
  def __hash__(self):
    return hash(str(self))
  
  def __eq__(self, outro):
    if(isinstance(outro, Producao)):
      return hash(self) == hash(outro)
    return False
        