'''
Created on 17/06/2009
@author: Katcipis
Modulo onde eh definida a classe PoolConexoes
'''
from threading import BoundedSemaphore
from transporte.Conexao import Conexao

class PoolConexoes():
  '''
  Pool de conexoes thread-safe, garante que uma conexao soh possa ser 
  vista ou modificada por uma thread por vez. Eh importante que sempre
  que uma thread nao precise mais de uma conexao ela libere essa conexao.
  Se uma conexao for obtida e nunca for liberada podera ocorrer um deadlock.
  '''
  def __init__(self, numConexoes):
    '''
    Construtor
    Parametros:
    numConexoes = numero de conexoes que existirao no pool
    '''
    self.__conexoes = [(Conexao(i), BoundedSemaphore()) for i in range(numConexoes)]
    
  def obterConexao(self, indice):
    self.__conexoes[indice][1].acquire()
    return self.__conexoes[indice][0]
  
  def liberarConexao(self, conexao):
    for tupla in self.__conexoes:
      if(tupla[0] == conexao):
        tupla[1].release()
        