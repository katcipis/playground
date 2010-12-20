# -*- coding: latin-1 -*-
import wx
from gui.abstrato.CaixaDeTextoRotulada import CaixaDeTextoRotulada

class PainelDaDisponibilidade(CaixaDeTextoRotulada):
  
  def __init__(self, pai):
    CaixaDeTextoRotulada.__init__(self, pai)
    self._adcionarEspacamento()
    
  def _obterRotuloInicial(self):
    return 'Disponibilidade: '
    
  def _obterTextoInicial(self):
    return 'Disponibilidade'
