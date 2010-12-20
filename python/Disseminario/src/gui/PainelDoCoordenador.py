# -*- coding: latin-1 -*-
import wx
from gui.abstrato.CaixaDeTextoRotulada import CaixaDeTextoRotulada

class PainelDoCoordenador(CaixaDeTextoRotulada):
  
  def __init__(self, pai):
    CaixaDeTextoRotulada.__init__(self, pai)
    self._adcionarEspacamento()
    
  def _obterRotuloInicial(self):
    return 'Coordenador: '
    
  def _obterTextoInicial(self):
    return 'Coordenador'
