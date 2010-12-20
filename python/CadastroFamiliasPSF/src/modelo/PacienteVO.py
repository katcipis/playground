# -*- coding: utf-8 -*-
'''
Created on 10/04/2009
@author: katcipis
'''
from datetime import date
from abstrato.Paciente import Paciente
from abstrato.DataNascimento import DataNascimento

class PacienteVO(Paciente):
  ''' Value Object do Paciente, representacao do paciente para ser usado no banco de dados'''  

  def obterIdade(self):
    dataHoje = DataNascimento(date.today())
    anos = dataHoje.obterAno() - self._dataNascimento.obterAno()
    
    if(dataHoje.obterMes() < self._dataNascimento.obterMes()):
      return anos - 1
    
    if(dataHoje.obterMes() == self._dataNascimento.obterMes()):
      if(dataHoje.obterDia() < self._dataNascimento.obterDia()):
        return anos - 1
    return anos
   

  def __eq__(self, outro):
    if(not isinstance(outro, PacienteVO)):
      return False
    
    caseUm = self.obterNome() == outro.obterNome()
    caseDois = self.obterDataNascimento() == outro.obterDataNascimento()
    caseTres = self.obterNumeroFamilia() == outro.obterNumeroFamilia()
    caseQuatro = self.obterNumeroArea() == outro.obterNumeroArea()
    caseCinco = self.obterNumeroMicroArea() == outro.obterNumeroMicroArea()
    caseSeis = self.obterEndereco() == outro.obterEndereco()
    
    return caseUm and caseDois and caseTres and caseQuatro and caseCinco and caseSeis
  
  def __str__(self):
    paciente = '\n' + 'Nome: ' + self.obterNome() + '\n'
    paciente += 'Data Nascimento: ' + str(self.obterDataNascimento()) + '\n'
    paciente += 'Idade: ' + str(self.obterIdade()) + '\n'
    paciente += 'Familia: ' + str(self.obterNumeroFamilia()) + '\n'
    paciente += 'Micro area: ' + str(self.obterNumeroMicroArea()) + '\n'
    paciente += 'Area: ' + str(self.obterNumeroArea()) + '\n'
    paciente += 'Endereco: ' + str(self.obterEndereco())
    return paciente
  
  def __neq__(self, outro):
    return not self.__eq__(outro)
