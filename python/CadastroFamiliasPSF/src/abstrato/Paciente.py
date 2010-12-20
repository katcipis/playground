'''
Created on 10/04/2009
@author: katcipis
'''
import copy

class Paciente():
  ''' Representa a mais alta abstracao de um paciente no sistema '''
  
  def __init__(self, nome, dataNascimento, numFamilia, numArea,
               numMicroArea, endereco ):
    self._nome = nome
    self._dataNascimento = dataNascimento
    self._numFamilia = numFamilia
    self._numArea = numArea
    self._numMicroArea = numMicroArea
    self._endereco = endereco
    
  def obterNome(self):
    return self._nome
  
  def obterDataNascimento(self):
    return self._dataNascimento
  
  def obterNumeroFamilia(self):
    return self._numFamilia
  
  def obterNumeroArea(self):
    return self._numArea

  def obterNumeroMicroArea(self):
    return self._numMicroArea
  
  def obterEndereco(self):
    return copy.copy(self._endereco)    

