'''
Created on 23/09/2009
@author: katcipis
'''
from copy import copy

class Estado(object):
  '''
  Define o estado utilizado nos automatos
  '''

  def __init__(self, nome, transicoes, eh_inicial, eh_final):
    '''
    Construtor do automato.
    @param nome: nome deste estado.
    @param transicoes: conjunto de transicoes possiveis a partir deste estado.
    @param eh_inicial: Determina se eh um estado inicial
    @param eh_final: Determina se eh um estado final   
    '''
    self.__eh_final = eh_final
    self.__eh_inicial = eh_inicial
    self.__nome = nome
    self.__transicoes = copy(transicoes)
    
  def ehFinal(self):
    return self.__eh_final   
  
  def ehInicial(self):
    return self.__eh_inicial 
  
  def obterNome(self):
    return self.__nome
  
  def obterTransicoes(self):
    return copy(self.__transicoes)
  
  def obterTransicoesPorSimbolo(self, simbolo):
    return set([transicao  for transicao in self.__transicoes 
                           if transicao.obterSimbolo() == simbolo])
  
  def __hash__(self):
    return hash(self.__nome)
  
  def __ne__(self, outro):
    return not self == outro  
  
  def __eq__(self, outro):
    if isinstance(outro, Estado):
      return hash(self) == hash(outro)
    return False
  
  def __str__(self):
    str_repr = '<<<< Estado [' + self.__nome + '] >>>>' + '\n'
    
    if(self.__eh_final):
      str_repr += '<<<< final >>>> \n'
    if(self.__eh_inicial):
      str_repr += '<<<< inicial >>>> \n'
      
    str_transicoes = []
    for transicao in self.__transicoes:
      str_transicoes.append(str(transicao) + '\n')
    
    str_transicoes.sort()
    for str_transicao in str_transicoes:
      str_repr += str_transicao
      
    return str_repr + '\n'
    