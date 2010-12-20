# -*- coding: latin-1 -*-
import wx
from gui.abstrato.ComponenteRotulado import ComponenteRotulado

class PainelDeAdicaoDeMaterial(ComponenteRotulado):
  
  def __init__(self, pai):
    ComponenteRotulado.__init__(self, pai)
    
    self.__pegadorDeArquivo = wx.FilePickerCtrl(self, style = wx.FLP_DEFAULT_STYLE|wx.FLP_OPEN)
    self.__botaoEnviar = wx.Button(self, label = 'Enviar')
    
    self._sizer.Add(self.__pegadorDeArquivo, proportion = 1, flag = wx.EXPAND)
    self._sizer.Add(self.__botaoEnviar)
    
    self.Bind(wx.EVT_BUTTON, self.__trataCliqueBotao, self.__botaoEnviar)
    self._adcionarEspacamento()
    
  def _obterRotuloInicial(self):
    return 'Adcionar Material: '
    
  def __trataCliqueBotao(self, evento):
    """ TODO """
