from gui.componentes.EscolhasComRotulo import EscolhasComRotulo
from gui.componentes.PainelFrequenciaEmpirica import PainelFrequenciaEmpirica 
from gui import gui_constantes
import wx

class PainelDuasFreqDiferenteEmpirica(wx.Panel):
  
  def __init__(self, parent, frame, rotuloUm, rotuloDois,  *args, **kwargs):
    wx.Panel.__init__(self, parent = parent)
    self._parent = parent
    self._painelFrequenciaUm = PainelFrequenciaEmpirica(rotulo = rotuloUm, parent = self, frame = frame)
    self._painelFrequenciaDois  = PainelFrequenciaEmpirica(rotulo = rotuloDois, parent = self, frame = frame)
    self._inicializar()
    
  def _inicializar(self):
    self._sizer = wx.FlexGridSizer(1, 2, 1, 1)
    self.SetSizer(self._sizer)
  
    self._sizer.Add(self._painelFrequenciaUm)
    self._sizer.Add(self._painelFrequenciaDois)
    
    self._sizer.AddGrowableRow(0)
    self._sizer.AddGrowableCol(0)
    self._sizer.AddGrowableCol(1)
    
    
  def obterPainelUm(self):
    return self._painelFrequenciaUm

  def obterPainelDois(self):
    return self._painelFrequenciaDois
  
