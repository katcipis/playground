# -*- coding: utf-8 -*-
'''
Created on 22/04/2009
@author: katcipis
Parametro de pesquisa utilizado para realizar pesquisas no sistema,
esta classe deve ser utilizada diretamente ou como base se for desejado
utilizar o sistema de eventos para realizar uma busca no sistema.
'''

class ParametroDePesquisa():
  
  def __init__(self, nomeCampo, valorCampo):
    self.__nome = nomeCampo
    self.__valor = valorCampo
    
  def obterNomeDoCampo(self):
    return self.__nome
  
  def obterValorDoCampo(self):
    return self.__valor
    
