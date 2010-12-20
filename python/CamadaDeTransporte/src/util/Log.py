'''
Created on 16/06/2009
@author: Katcipis

Modulo contendo a definicao da Classe Log
'''
from threading import BoundedSemaphore

class Log():
  '''
  Log thread-safe
  '''
  semaforo = BoundedSemaphore()
  
  def __init__(self, prefix, path = None):
    '''
    Construtor
        
    Se nenhum path for informado o log apenas ira exibir as informacoes
    no stdout padrao do processo, se um path for informado as informacoes
    serao gravadas no arquivo informado no path e tambem serao exibidas pelo
    stdout do processo.
    
    '''
    self.__path = path    
    self.__prefix = prefix
    
  def logar(self, texto):
    ''' Escreve no log o texto informado, adcionando uma nova linha ao texto'''
    Log.semaforo.acquire()
    texto = self.__prefix + texto
    
    if(self.__path != None):
      arquivo = open(self.__path, 'w')
      arquivo.write(texto + '\n')
      arquivo.close
      
    print(texto)
    Log.semaforo.release()