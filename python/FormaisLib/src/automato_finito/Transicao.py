'''
Created on 23/09/2009
@author: katz
'''

class Transicao(object):
  '''
  Define uma transicao, dado uma entrada sabe qual o nome do estado destino
  '''

  def __init__(self, simbolo_entrada, nome_estado_destino):
    '''
    Construtor
    @param simbolo_entrada: Simbolo de entrada da transicao (deve ser representavel como string)
    @param nome_estado_destino: Nome do estado de destino da transicao
    '''
    self.__simbolo = simbolo_entrada
    self.__nome_destino = nome_estado_destino
    self.__representacao_string = str(simbolo_entrada) + ' -> ' + str(nome_estado_destino)
        
  def obterNomeEstadoDestino(self):
    return self.__nome_destino
  
  def obterSimbolo(self):
    return self.__simbolo
  
  def __str__(self):
    return self.__representacao_string
  
  def __hash__(self):
    return hash(self.__representacao_string)
  
  def __eq__(self, outro):
    if isinstance(outro, Transicao):
      return hash(self) == hash(outro)
    return False
  
  def __ne__(self, outro):
    return not self == outro
  