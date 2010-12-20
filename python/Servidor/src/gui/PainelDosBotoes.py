import wx
class PainelDosBotoes(wx.Panel):
  
  def __init__(self,parent, funcaoQueLidaComCliqueSimul,funcaoQueLidaComCliqueCancel , *args, **kwargs):
    wx.Panel.__init__(self, parent)
    self.Inicializar(funcaoQueLidaComCliqueSimul,funcaoQueLidaComCliqueCancel)
    
  def Inicializar(self,funcaoQueLidaComCliqueSimul,funcaoQueLidaComCliqueCancel):
    self._sizer = wx.FlexGridSizer(1, 2, 1, 1) 
    self._sizer.AddGrowableRow(0)
    self._sizer.AddGrowableCol(0)
    self._sizer.AddGrowableCol(1)
    self.SetSizer(self._sizer)
    
    self.botaoSimul = self.botaoConverter = wx.Button(self, label='Simular')
    self.Bind(wx.EVT_BUTTON, funcaoQueLidaComCliqueSimul, self.botaoSimul)

    self.botaoCancela = self.botaoConverter = wx.Button(self, label='Cancela')
    self.Bind(wx.EVT_BUTTON, funcaoQueLidaComCliqueCancel, self.botaoCancela)

    self._sizer.Add(self.botaoSimul)
    self._sizer.Add(self.botaoCancela)
    
  
    
