'''
Created on 03/11/2009
@author: katcipis
'''
import os, sys
from PyQt4 import QtGui
from JanelaPrincipal import JanelaPrincipal

app = QtGui.QApplication(sys.argv)
janela = JanelaPrincipal(os.path.join(os.getcwd(), "arquivos_ui"))
sys.exit(app.exec_())
