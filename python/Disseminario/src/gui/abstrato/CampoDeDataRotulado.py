# -*- coding: latin-1 -*-
import wx
from gui.abstrato.ComponenteRotulado import ComponenteRotulado

class CampoDeDataRotulado(ComponenteRotulado):
  
  def __init__(self,pai):
    ComponenteRotulado.__init__(self, pai)

    self.__dataPicker = wx.DatePickerCtrl(parent = self, style = wx.DP_DROPDOWN|wx.DP_SHOWCENTURY)
    self._sizer.Add(self.__dataPicker, proportion = 1, flag = wx.EXPAND)
    
  def obterDataSelecionada(self):
    return self.__dataPicker.GetValue()
    

    