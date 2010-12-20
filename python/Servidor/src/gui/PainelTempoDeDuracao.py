import wx
from gui import gui_rotulos
from gui.componentes.CamposComRotulo import CamposComRotulo

class PainelTempoDeDuracao(wx.Panel):
  
  def __init__(self, parent , *args, **kwargs):
    wx.Panel.__init__(self, parent)
    self.Inicializar()
    
  def Inicializar(self):
    self._sizer = wx.FlexGridSizer(1, 1, 1, 1) 
    self.SetSizer(self._sizer)
    self._tempoDeDuracao = CamposComRotulo(self, [gui_rotulos.TEMPO_DE_DURACAO])
    
    self._sizer.Add(self._tempoDeDuracao)
 
    
  def obterTempoDeDuracao(self):
    return int(self._tempoDeDuracao.obterValorDoCampoComOSeguinteRotulo(gui_rotulos.TEMPO_DE_DURACAO))
      