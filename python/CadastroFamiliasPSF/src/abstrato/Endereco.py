'''
Created on 10/04/2009
@author: katcipis
'''

class Endereco():
  ''' Representa mais alta abstracao de um endereco no sistema '''

  def __init__(self, rua, numero, complemento):
    self._rua = rua
    self._numero = numero
    self._complemento = complemento
  
  def __str__(self):
    endereco = str(self.obterRua())
    endereco += '. Numero' + str(self.obterNumero())
    endereco += '. Complemento: ' + str(self.obterComplemento())
    return endereco
  
  def obterComplemento(self):
    return self._complemento
  
  def obterNumero(self):
    return self._numero
  
  def obterRua(self):
    return self._rua
