'''
Created on 15/06/2009
@author: Katcipis
Modulo contendo a definicao da Classe Conexao
'''
from transporte.EstadosConexao import PARADO
from threading import BoundedSemaphore

class Conexao():
  '''
  Responsavel por guardar todos os dados referentes a uma conexao.
  '''
  def __init__(self, id):
    ''' 
        Construtor da Classe Conexao
        
        Variaveis de instancia privadas de uma Conexao:
        __enderecoLocal  = Endereco Local
        __enderecoRemovo = Endereco Remoto
        __estado         = Estado da conexao
        __reqLiberarRecebida = Ativado quando o pacote LIBERA_REQ eh recebido
        __timer    = Usado para interromper pacotes LIBERA_REQ 
        __creditos = Numero maximo de mensagens que podem ser enviadas
        __id       = Identificador da conexao
        
    '''
    self.__enderecoLocal = None
    self.__enderecoRemoto = None
    self.__estado = PARADO
    self.__reqLiberarRecebida = False
    self.__timer = 0
    self.__creditos = 0
    self.__id = id
    self.__dados = None
    
    
  def __str__(self):
    '''
    Define a representacao como string da classe
    '''
    str_repr = '\n\n -------------------------------\n'
    str_repr += 'Id = ' + str(self.__id) + '\n'
    str_repr += 'Endereco local  = ' + self.__enderecoLocal  + '\n'
    str_repr += 'Endereco remoto = ' + self.__enderecoRemoto + '\n'
    str_repr += 'Estado = ' + self.__estado + '\n'
    str_repr += 'Requisicao para liberar foi recebida = ' + str(self.__reqLiberarRecebida) + '\n'
    str_repr += 'Timer = ' + str(self.__timer) + '\n'
    str_repr += 'Creditos = ' + str(self.__creditos) + '\n'
    str_repr += ' -------------------------------\n\n'
    return str_repr
    
  def possuiCreditos(self):
    return self.__creditos > 0
  
  def timerEstaLigado(self):
    return self.__timer > 0
  
  def obterTimer(self):
    return self.__timer
    
  def obterId(self):
    return self.__id
  
  def obterDados(self):
    return self.__dados
    
  def obterEnderecoLocal(self):
    return self.__enderecoLocal
  
  def obterEnderecoRemoto(self):
    return self.__enderecoRemoto
  
  def obterEstado(self):
    return self.__estado
  
  def obterReqLiberarRecebida(self):
    return self.__reqLiberarRecebida    
  
  def obterCreditos(self):
    return self.__creditos
    
    
  def setEstado(self, novoEstado):
    self.__estado = novoEstado
    
  def setTimer(self, valorTimer):       
    self.__timer = valorTimer
    
  def setDados(self, dados):
    self.__dados = dados
    
  def setEnderecoLocal(self, enderecoLocal):
    self.__enderecoLocal = enderecoLocal
    
  def setEnderecoRemoto(self, enderecoRemoto):
    self.__enderecoRemoto = enderecoRemoto
  
  def setCreditos(self, creditos):
    self.__creditos = creditos
  
  def setReqLiberarRecebida(self, value):
    self.__reqLiberarRecebida = value    