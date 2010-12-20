'''
Created on 11/08/2009
Abstracao geral do nome dos campos que compoem a tabela paciente, 
independente do banco de dados utilizado na implementacao.
@author: katcipis
'''

class TabelaPaciente:  
  
  def obterNomeTabela(self):
    return 'Paciente'
  
  def obterCampoNome(self):
    return 'Nome'
    
  def obterCampoDataNascimento(self):
    return 'DataDeNascimento'
  
  def obterCampoNumeroFamilia(self):
    return 'NumeroDaFamilia'

  def obterCampoNumeroArea(self):
    return 'NumeroArea'

  def obterCampoNumeroMicroArea(self):
    return 'NumeroMicroArea'
  
  def obterCampoRua(self):
    return 'Rua'

  def obterCampoNumeroCasa(self):
    return 'NumeroCasa'
  
  def obterCampoComplemento(self):
    return 'Complemento'
  
  def obterCampoIdade(self):
    return 'Idade'