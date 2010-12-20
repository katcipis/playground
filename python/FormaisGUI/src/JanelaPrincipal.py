'''
Created on 03/11/2009
@author: katcipis
'''
import os
from AutomatoFinitoGUI import AutomatoFinitoGUI
from ExpressaoRegularGUI import ExpressaoRegularGUI
from GramaticaRegularGUI import GramaticaRegularGUI
from GramaticaLivreContextoGUI import GramaticaLivreContextoGUI
from PyQt4 import QtGui, uic

class JanelaPrincipal(QtGui.QDialog):
  def __init__(self, ui_dir):
    QtGui.QDialog.__init__(self)

    # Setar a interface criada no QTCreator.
    self.ui_dir = ui_dir
    self.__ui = uic.loadUi(os.path.join(self.ui_dir, "janelaprincipal.ui"))
    self.__automato_gui = AutomatoFinitoGUI(self.__ui, self)
    self.__gramatica_gui = GramaticaRegularGUI(self.__ui, self)
    self.__exp_reg_gui = ExpressaoRegularGUI(self.__ui, self)
    self.__gramatica_lc_gui = GramaticaLivreContextoGUI(self.__ui, self)
    self.__ui.show()
    
    
  def obterGRGUI(self):
    return self.__gramatica_gui
          
  def obterAFGUI(self):
    return self.__automato_gui
  
    