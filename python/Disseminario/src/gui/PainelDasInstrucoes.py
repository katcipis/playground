# -*- coding: latin-1 -*-
import wx
from gui.abstrato.CaixaDeTextoRotulada import CaixaDeTextoRotulada

class PainelDasInstrucoes(CaixaDeTextoRotulada):
  
  def __init__(self, pai):
    CaixaDeTextoRotulada.__init__(self, pai, wx.TE_MULTILINE|wx.HSCROLL|
                                             wx.TE_LEFT|wx.TE_PROCESS_ENTER|
                                             wx.TE_RICH|wx.TE_AUTO_URL)
    self._adcionarEspacamento()
    
  def _obterRotuloInicial(self):
    return 'Instruções: '
    
  def _obterTextoInicial(self):
    return 'Instruções aqui'
