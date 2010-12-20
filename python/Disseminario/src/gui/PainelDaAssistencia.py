# -*- coding: latin-1 -*-
import wx
from gui.abstrato.CaixaDeTextoRotulada import CaixaDeTextoRotulada

class PainelDaAssistencia(CaixaDeTextoRotulada):
  
  def __init__(self, pai):
    CaixaDeTextoRotulada.__init__(self, pai)
    self._adcionarEspacamento()
    
  def _obterRotuloInicial(self):
    return 'Assistência: '
    
  def _obterTextoInicial(self):
    return 'Assistência'
