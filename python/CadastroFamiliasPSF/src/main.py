'''
Created on 23/07/2009
@author: katcipis <tiagokatcipis@gmail.com>
'''
from banco_dados import inicia_bd
from gui.JanelaPrincipal import JanelaPrincipal
from PyQt4 import QtGui
from eventos.TratadorDeEventos import TratadorDeEventos
from eventos import eventos_sistema
from modelo import tratador_eventos
import os
import sys 

if(not inicia_bd.iniciar_bd()):
  print('Erro ao iniciar banco de dados, abortando !!!')
  
app = QtGui.QApplication(sys.argv)
janela = JanelaPrincipal(os.path.join(os.getcwd(), "arquivos_qt"))
tratadorEventos = TratadorDeEventos()

#Eventos tratados pelo modelo logico
tratadorEventos.registraTratador(eventos_sistema.ADCIONAR_PACIENTE, tratador_eventos.adciona_paciente)
tratadorEventos.registraTratador(eventos_sistema.BUSCA_PACIENTE, tratador_eventos.busca_paciente)
tratadorEventos.registraTratador(eventos_sistema.REMOVER_PACIENTE, tratador_eventos.remove_paciente)
tratadorEventos.registraTratador(eventos_sistema.LISTAR_PACIENTES, tratador_eventos.listar_pacientes)

#TODO respostas de eventos que devem ser tratados pela GUI
#tratadorEventos.registraTratador()
#tratadorEventos.registraTratador()
#tratadorEventos.registraTratador()
                                 
sys.exit(app.exec_())
