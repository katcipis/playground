import copy
from enum import EstadoDoServidor
from FilaDoServidor import FilaDoServidor

ID_NULO = 'ID_NULO'

class Servidor():
  
  def __init__(self, id = ID_NULO):
    self.__id = id
    self.__estadoAtual = EstadoDoServidor.LIVRE
    self.__entidadeSendoServida = None
    
  def estaOcupado(self):
    return self.__estadoAtual == EstadoDoServidor.OCUPADO
  
  def estaLivre(self):
    return self.__estadoAtual == EstadoDoServidor.LIVRE
  
  def estaEmFalha(self):
    return self.__estadoAtual == EstadoDoServidor.EM_FALHA
  
  def servirEntidade(self, entidade):
    if(self.estaLivre()):
      self.__estadoAtual = EstadoDoServidor.OCUPADO
      self.__entidadeSendoServida = entidade
      self.__entidadeSendoServida.marcarComoServida()
    
  def obterId(self):
    return copy.copy(self.__id)
  
  def falhar(self):
    if(self.estaOcupado()):
      self.__entidadeSendoServida.marcarComoFalha()
      
    self.__estadoAtual = EstadoDoServidor.EM_FALHA
    
  def funcionar(self):
    if(self.estaEmFalha()):
      self.__estadoAtual = EstadoDoServidor.LIVRE
  
  def terminarServico(self):
    self.__entidadeSendoServida = None
    self.__estadoAtual = EstadoDoServidor.LIVRE
  
  def obterEntidadeSendoServida(self):
    return copy.copy(self.__entidadeSendoServida)