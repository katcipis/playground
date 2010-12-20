# -*- coding: latin-1 -*-
import wx

class ComponenteGenerico(wx.Panel):
  
  def __init__(self,pai):
    wx.Panel.__init__(self, pai)
    self._pai = pai

    self._sizer = wx.BoxSizer(wx.HORIZONTAL)
    self.SetSizer(self._sizer)
    self._adcionarEspacamento()
    
    
  def _adcionarEspacamento(self):
    self._sizer.Add(wx.Size(10,10))
    