'''
Created on 23/07/2009
@author: katcipis <tiagokatcipis@gmail.com>
'''
from PyQt4 import QtCore, QtGui, uic
from eventos.TratadorDeEventos import TratadorDeEventos
from eventos import eventos_sistema
from gui.TabelaPacientesGUI import TabelaPacientesGUI
from gui.PacienteGUI import PacienteGUI
from gui.EnderecoGUI import EnderecoGUI
from abstrato.DataNascimento import DataNascimento
from abstrato.TabelaPaciente import TabelaPaciente
from abstrato.ParametroDePesquisa import ParametroDePesquisa
import os

class JanelaPrincipal(QtGui.QDialog):
  def __init__(self, ui_dir):
    QtGui.QDialog.__init__(self)

    # Setar a interface criada no QTCreator.
    self.ui_dir = ui_dir
    self.ui = uic.loadUi(os.path.join(self.ui_dir, "janelaprincipal.ui"))
    self.ui.show()
    self.tratadorEventos = TratadorDeEventos()
        
    # Conectar eventos dos botoes
    self.connect(self.ui.botaoAdcionar, QtCore.SIGNAL("clicked()"), self.clicouAdcionar)
    self.connect(self.ui.botaoBuscar, QtCore.SIGNAL("clicked()"), self.clicouBuscar)
    self.connect(self.ui.botaoListar, QtCore.SIGNAL("clicked()"), self.clicouListar)
    self.connect(self.ui.botaoRemover, QtCore.SIGNAL("clicked()"), self.clicouRemover)
      
    # TODO Preencher os campo dos tipos de busca possiveis
    tabelaPaciente = TabelaPaciente()
    opcoesPesquisa = [tabelaPaciente.obterCampoIdade(), tabelaPaciente.obterCampoNome(),
                      tabelaPaciente.obterCampoNumeroFamilia(), tabelaPaciente.obterCampoNumeroArea(),
                      tabelaPaciente.obterCampoNumeroMicroArea()]
    
    self.ui.modosPesquisa.insertItems(0, opcoesPesquisa)
    
    # Delegar tabela de pacientes para uma classe
    self.__tabelaPacientes = TabelaPacientesGUI(self.ui.tabelaPacientes)
 
    # Disparar evento para listar os pacientes existentes
    self.tratadorEventos.dispararEvento(eventos_sistema.LISTAR_PACIENTES)

  def clicouAdcionar(self):
    enderecoGUI = EnderecoGUI(rua = str(self.ui.entradaRua.text()), 
                           numero = str(self.ui.entradaNumero.text()), 
                           complemento = str(self.ui.entradaComplemento.text()))
    pacienteGUI = PacienteGUI(nome = str(self.ui.entradaNome.text()), 
                           numArea = str(self.ui.entradaArea.text()), 
                           numMicroArea = str(self.ui.entradaMicroArea.text()), 
                           numFamilia = str(self.ui.entradaFamilia.text()), 
                           dataNascimento = DataNascimento(self.ui.entradaDataNasc.text()),
                           endereco = enderecoGUI)

    self.tratadorEventos.dispararEvento(evento = eventos_sistema.ADCIONAR_PACIENTE, paciente = pacienteGUI)

  def clicouBuscar(self):
    #TODO ao disparar o evento deve construir um ParametroPesquisa utilizando a 
    #TabelaPaciente para definir o nome do campo da busca
    self.tratadorEventos.dispararEvento(evento = eventos_sistema.BUSCA_PACIENTE,
                                        parametro_pesquisa = ParametroDePesquisa(str(self.ui.modosPesquisa.currentText()),
                                                                                 str(self.ui.entradaBusca.text())))

  def clicouListar(self):
    self.tratadorEventos.dispararEvento(eventos_sistema.LISTAR_PACIENTES)

  def clicouRemover(self):
    self.tratadorEventos.dispararEvento(evento = eventos_sistema.REMOVER_PACIENTE,
                                        paciente = self.__tabelaPacientes.obterPacienteSelecionado())

