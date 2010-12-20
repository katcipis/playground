'''
Created on 17/06/2009
@author: Katcipis
Modulo contendo a definicao da classe PacoteDeDados
'''
import copy

class PacoteDeDados():
  '''
  Classe responsavel por encapsular todas as informacoes fornecidas
  pelos pacotes de dados vindos da camada de rede.
  Apos instanciado um pacote eh imutavel
  '''

  def __init__(self, tipoPacote, conId, dados):
    self.__tipoPacote = tipoPacote
    self.__conId = int(conId)
    self.__dados = dados
      
  def obterDados(self):
    return copy.copy(self.__dados)          
        
  def obterIdConexao(self):
    return copy.copy(self.__conId)
  
  def obterTipoDoPacote(self):
    return copy.copy(self.__tipoPacote)  
  