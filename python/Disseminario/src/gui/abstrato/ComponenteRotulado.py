# -*- coding: latin-1 -*-
import wx
from gui.abstrato.ComponenteGenerico import ComponenteGenerico

class ComponenteRotulado(ComponenteGenerico):
  
  def __init__(self,pai):
    ComponenteGenerico.__init__(self, pai)
    self.__rotulo = wx.StaticText(self, label = self._obterRotuloInicial(),  
                                  style = wx.ALIGN_LEFT)
    self._sizer.Add(self.__rotulo, flag = wx.ALIGN_CENTER_VERTICAL)
    
  
  def _obterRotuloInicial(self):
    """ Funcao abstrata, deve retornar uma strings que sera o rotulo."""
    return 'Rotulo'
    
  def obterRotulo(self):
    self.__rotulo.GetLabel()
    
  def modificarRotulo(self, novoRotulo):
    self.__rotulo.SetLabel(novoRotulo)