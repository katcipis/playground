'''
Created on 31/03/2009
@author: Tiago Katcipis
'''
import threading
import time
import os
from modelo.DispositivoSerial import DispositivoSerial

class GerenciadorConexaoSerial(threading.Thread):
  
  def __init__(self, janela):
    threading.Thread.__init__(self)
    self.__janela = janela
    self.__rodar = True
    self.__sleepTime = 0.3
    self.__dispositivoSerial = None
    self.__tamanhoMaximoMsg = 32    
    
  def setDispositivoSerial(self, porta):
    self.__dispositivoSerial = DispositivoSerial(porta, self.__tamanhoMaximoMsg)
    
  def terminar(self):
    self.__rodar = False
    
  def run(self):
    
    while(self.__rodar):
      time.sleep(self.__sleepTime)

      if(self.__dispositivoSerial != None):
        dados = ''
        while(self.__dispositivoSerial.existemDadosParaLer()):
          dados += self.__dispositivoSerial.obterDados()
      
        self.__janela.gravarTextoRemoto(dados)
          
        if(not self.__dispositivoSerial.gravarDados(self.__janela.obterTextoCliente())):
          print 'Erro ' + self.__dispositivoSerial.obterMsgDeErro()   
         
    return None