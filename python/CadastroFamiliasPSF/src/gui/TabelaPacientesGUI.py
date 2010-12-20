'''
Created on 25/07/2009
@author: katcipis <tiagokatcipis@gmail.com>
'''
from eventos.TratadorDeEventos import TratadorDeEventos
from eventos import eventos_sistema
from gui.EnderecoGUI import EnderecoGUI
from gui.PacienteGUI import PacienteGUI
from abstrato.DataNascimento import DataNascimento
from PyQt4 import QtGui

class TabelaPacientesGUI():
  ''' Controla a tabela de pacientes da interface '''

  def __init__(self, tabelaPacientes):
    self.__tabelaPacientes = tabelaPacientes
    self.__colunaNome = 0
    self.__colunaArea = 1
    self.__colunaMicroArea = 2
    self.__colunaFamilia = 3
    self.__colunaDataNasc = 4
    self.__colunaRua = 5
    self.__colunaNumero = 6
    self.__colunaComplemento = 7
    self.limpar()
  
  def limpar(self):
    ''' Deixa a tabela vazia '''
    [self.__tabelaPacientes.removeRow(i) for i in range(self.__tabelaPacientes.rowCount())]

  def adcionarPaciente(self, paciente):
    ''' Adciona um paciente a tabela '''
    linha_livre = self.__tabelaPacientes.rowCount()
    self.__tabelaPacientes.insertRow(linha_livre)
    self.__tabelaPacientes.setItem(linha_livre, self.__colunaNome, QtGui.QTableWidgetItem(str(paciente.obterNome())))
    self.__tabelaPacientes.setItem(linha_livre, self.__colunaArea, QtGui.QTableWidgetItem(str(paciente.obterArea())))
    self.__tabelaPacientes.setItem(linha_livre, self.__colunaMicroArea, QtGui.QTableWidgetItem(str(paciente.obterMicroArea())))
    self.__tabelaPacientes.setItem(linha_livre, self.__colunaFamilia, QtGui.QTableWidgetItem(str(paciente.obterNumeroFamilia())))
    self.__tabelaPacientes.setItem(linha_livre, self.__colunaDataNasc, QtGui.QTableWidgetItem(str(paciente.obterDataNascimento())))

    endereco = paciente.obterEndereco()
    self.__tabelaPacientes.setItem(linha_livre, self.__colunaRua, QtGui.QTableWidgetItem(str(endereco.obterRua())))
    self.__tabelaPacientes.setItem(linha_livre, self.__colunaNumero, QtGui.QTableWidgetItem(str(paciente.obterNumero())))
    self.__tabelaPacientes.setItem(linha_livre, self.__colunaComplemento, QtGui.QTableWidgetItem(str(paciente.obterComplemento())))

  def obterPacienteSelecionado(self):
    ''' Retorna o paciente que foi selecionado pelo usuario na tabela '''
    linha_selecionada = self.__tabelaPacientes.currentRow()
    nome = self.__tabelaPacientes.item(linha_selecionada, self.__colunaNome)
    area = self.__tabelaPacientes.item(linha_selecionada, self.__colunaArea)
    microarea = self.__tabelaPacientes.item(linha_selecionada, self.__colunaMicroArea)
    familia   = self.__tabelaPacientes.item(linha_selecionada, self.__colunaFamilia)
    data_nasc = self.__tabelaPacientes.item(linha_selecionada, self.__colunaDataNasc)
    rua       = self.__tabelaPacientes.item(linha_selecionada, self.__colunaRua)
    numero      = self.__tabelaPacientes.item(linha_selecionada, self.__colunaNumero)
    complemento = self.__tabelaPacientes.item(linha_selecionada, self.__colunaComplemento)

    endereco = EnderecoGUI(rua, numero, complemento)
    return PacienteGUI(nome, DataNascimento(data_nasc), familia, area, microarea, endereco) 

