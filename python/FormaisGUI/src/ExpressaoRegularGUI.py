'''
Created on 04/11/2009
@author: katcipis
'''
from PyQt4 import QtCore, QtGui
from expressao_regular.ExpressaoRegular import ExpressaoRegular
from util import util

class ExpressaoRegularGUI(object):
  '''
  Defina classe que controla a GUI da expressao regular.
  '''

  def __init__(self, ui, janela_principal):
    '''
    Construtor
    @param ui: a gui carregada na memoria.
    '''
    self.__ui = ui
    self.__janela_principal = janela_principal
    
    self.__janela_principal.connect(self.__ui.exp_em_automato, QtCore.SIGNAL("clicked()"), self.clicouTransformarEmAFD)
    self.__janela_principal.connect(self.__ui.testar_equivalencia, QtCore.SIGNAL("clicked()"), self.clicouTestarEquivalencia)
    self.__janela_principal.connect(self.__ui.exp_em_gramatica, QtCore.SIGNAL("clicked()"), self.clicouTransformarEmGR)
    self._error = QtGui.QErrorMessage(janela_principal)
    self._error.setWindowTitle('Erro')
    
        
  def clicouTransformarEmGR(self):
    try:
      exp = ExpressaoRegular(str(self.__ui.exp_reg.text()))
      afd = exp.obterAFD()
      afd = util.remover_estados_mortos_afd(afd)
      self.__janela_principal.obterGRGUI().setarGR(util.obter_gramatica_regular(afd))
      
    except Exception as excecao:
      self._error.showMessage(str(excecao))
    
    
  def clicouTestarEquivalencia(self):
    try:
      exp1 = ExpressaoRegular(str(self.__ui.exp_reg1.text()))
      exp2 = ExpressaoRegular(str(self.__ui.exp_reg2.text()))
      if(util.sao_equivalentes_af(exp1.obterAFD(), exp2.obterAFD())):
        self.__ui.sao_equivalentes.setText('OK')
      else:
        self.__ui.sao_equivalentes.setText('NOK')
        
    except Exception as excecao:
      self._error.showMessage(str(excecao))
    
    
  def clicouTransformarEmAFD(self):
    try:
      exp = ExpressaoRegular(str(self.__ui.exp_reg.text()))
      afd = exp.obterAFD()
      afd = util.remover_estados_mortos_afd(afd)
      self.__janela_principal.obterAFGUI().setarAF(afd)
      
    except Exception as excecao:
      self._error.showMessage(str(excecao))