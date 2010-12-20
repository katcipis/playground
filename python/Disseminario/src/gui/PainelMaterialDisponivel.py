# -*- coding: latin-1 -*-
import wx
from gui.abstrato.CaixaMultiplaEscolhaRotulada import CaixaMultiplaEscolhaRotulada

class PainelMaterialDisponivel(CaixaMultiplaEscolhaRotulada):
  
  def __init__(self, pai):
    CaixaMultiplaEscolhaRotulada.__init__(self, pai)
    self.__botaoDownload = wx.Button(self, label = 'Download')
    self.__botaoRemover = wx.Button(self, label = 'Remover')
    self._sizer.Add(self.__botaoDownload)
    self._sizer.Add(self.__botaoRemover)
    self.Bind(wx.EVT_BUTTON, self.__trataCliqueBotaoDownload, self.__botaoDownload)
    self.Bind(wx.EVT_BUTTON, self.__trataCliqueBotaoRemover, self.__botaoRemover)
    self._adcionarEspacamento()
    
  def _obterEscolhas(self):
    return ['Material 1', 'Material 2']
    
  def _obterRotuloInicial(self):
    return 'Material disponí­vel para download: '
  
  def __trataCliqueBotaoDownload(self, evento):
    """ TODO """
  
  def __trataCliqueBotaoRemover(self, evento):
    """ TODO """  
