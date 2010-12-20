import wx
from gui import gui_rotulos
from gui.componentes.CamposComRotulo import CamposComRotulo

class PainelLimiteDasFilas(wx.Panel):
  
  def __init__(self, parent , *args, **kwargs):
    wx.Panel.__init__(self, parent)
    self.Inicializar()
    
  def Inicializar(self):
    self._sizer = wx.FlexGridSizer(1, 1, 1, 1) 
    self._sizer.AddGrowableRow(0)
    self._sizer.AddGrowableCol(0)
    self.SetSizer(self._sizer)
    self._limiteDasFilas = CamposComRotulo(self, [gui_rotulos.LIMITE_FILA_UM, gui_rotulos.LIMITE_FILA_DOIS])
    
    self._sizer.Add(self._limiteDasFilas)
    
  def obterLimitesDasFilas(self):
    limiteUmStr = self._limiteDasFilas.obterValorDoCampoComOSeguinteRotulo(gui_rotulos.LIMITE_FILA_UM)
    limiteDoisStr = self._limiteDasFilas.obterValorDoCampoComOSeguinteRotulo(gui_rotulos.LIMITE_FILA_DOIS)
    limiteUm = 0
    limiteDois = 0
    
    if(limiteUmStr != ''):
      limiteUm = int(limiteUmStr)
      
    if(limiteDoisStr != ''):
      limiteDois = int(limiteDoisStr)
      
    return limiteUm, limiteDois