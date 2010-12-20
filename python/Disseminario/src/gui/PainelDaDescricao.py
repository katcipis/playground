# -*- coding: latin-1 -*-
import wx
from gui.abstrato.CaixaDeTextoRotulada import CaixaDeTextoRotulada

class PainelDaDescricao(CaixaDeTextoRotulada):
  
  def __init__(self, pai):
    CaixaDeTextoRotulada.__init__(self, pai, wx.TE_MULTILINE|wx.HSCROLL|
                                             wx.TE_LEFT|wx.TE_PROCESS_ENTER|
                                             wx.TE_RICH|wx.TE_AUTO_URL)
    self._adcionarEspacamento()
    
  def _obterRotuloInicial(self):
    return 'Descrição: '
    
  def _obterTextoInicial(self):
    return 'Descrição aqui'
