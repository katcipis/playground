'''
Created on 29/03/2009
@author: Tiago Katcipis
'''
import serial
import sys
import struct

class DispositivoSerial():
  
  def __init__(self, numeroDispositivo, tamanhoBufferEscrita):
    self.__serial = serial.Serial(port = numeroDispositivo, baudrate = 9600, 
                                  bytesize = serial.EIGHTBITS)    
    self.__serial.open()
    self.__byteStart = struct.pack('B', 1)
    self.__byteEnd = struct.pack('B', 2)
    self.__tamanhoBufferEscrita = tamanhoBufferEscrita
    self.__erro = ''
    
  def existemDadosParaLer(self):
    return self.__serial.inWaiting() != 0
  
  def obterDados(self):
    if(self.__serial.read() != self.__byteStart):
      self.__erro = 'Erro na comunicacao, mensagem nao possui byteStart'
      return None
    
    byte_lido = ''
    dados = ''
    while(byte_lido != self.__byteEnd):
      byte_lido = self.__serial.read()
      if(byte_lido != self.__byteEnd):
        dados += byte_lido
      
    return dados
      
  def gravarDados(self, dados):
    tamanho_msg = len(dados)
    while(tamanho_msg > 0):
      if(tamanho_msg < self.__tamanhoBufferEscrita):
        tamanho_msg = 0
        msg = dados
      else:
        tamanho_msg -= self.__tamanhoBufferEscrita
        msg = dados[0:self.__tamanhoBufferEscrita]
        dados = dados[self.__tamanhoBufferEscrita:]
        
      try:
        self.__serial.write(self.__byteStart)
        self.__serial.write(msg)
        self.__serial.write(self.__byteEnd)
      except:
        self.__erro = str(sys.exc_info()[1])
        return False      
    return True
  
  def obterMsgDeErro(self):
    return self.__erro
    