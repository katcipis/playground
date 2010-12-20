import wx
from gui.componentes.CamposComRotulo import CamposComRotulo
from gui import gui_constantes

class PainelDeCampos(wx.Panel):
  
  def __init__(self, *args, **kwargs):
    wx.Panel.__init__(self, *args, **kwargs)
    self.Inicializar()
    
  def Inicializar(self):
    self._sizer = wx.FlexGridSizer(1, 1, 1, 1) 
    self._sizer.AddGrowableRow(0)
    self._sizer.AddGrowableCol(0)
    self.SetSizer(self._sizer)
    
    self._rotulosDosCampos = self.obterRotuloDosCampos()
    self._campos = CamposComRotulo(parent = self, rotulosDosCampos = self._rotulosDosCampos)
    
    self._sizer.Add(self._campos)
    
  def obterRotuloDosCampos(self):
    """ ABSTRATO DEFINIR NAS SUBCLASSES """
    
  def obterValoresNosCampos(self):
    valores = {}
    for rotulo in self._rotulosDosCampos:
     valores[rotulo] = self._campos.obterValorDoCampoComOSeguinteRotulo(rotulo)
    
    return valores
    
