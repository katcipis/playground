'''
Created on 22/06/2009
@author: Katcipis
'''
from threading import Thread
from time import sleep

def adciona_funcao_callback_clock(funcao):
  '''
  Adciona uma funcao para ser invocada sempre que o clock do sistema pulsar.
  '''
  ClockSistema.funcoes.add(funcao)
  if(not ClockSistema.jaIniciou):
    clock = ClockSistema()
    clock.start()

class ClockSistema(Thread):
  '''
  Simula o clock do sistema
  '''
  funcoes = set()
  jaIniciou = False
  
  def __init__(self):
    Thread.__init__(self)
    self.__rodar = True
    
  def run(self):
    if(not ClockSistema.jaIniciou):
      ClockSistema.jaIniciou = True
      
      while(self.__rodar):
        sleep(1)
        [funcao() for funcao in ClockSistema.funcoes]
            
      ClockSistema.jaIniciou = False
      
  def parar(self):
    self.__rodar = False