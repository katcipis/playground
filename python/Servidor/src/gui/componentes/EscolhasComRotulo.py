import wx
from gui import gui_constantes

class EscolhasComRotulo(wx.Panel):
  
  def __init__(self, parent, rotulo, opcoes, funcaoChamadaEmEvento):
    wx.Panel.__init__(self, parent)
    self.Inicializar(rotulo, opcoes, funcaoChamadaEmEvento)
    
  def Inicializar(self, rotulo, opcoes, funcaoChamadaEmEvento):
    self.sizer = wx.BoxSizer(wx.HORIZONTAL)
    self.SetSizer(self.sizer)

    self.escolhas = wx.ComboBox(parent = self, choices = opcoes, style = wx.ALIGN_LEFT|wx.ALIGN_CENTER_HORIZONTAL|wx.ALIGN_CENTER_VERTICAL)
    self.Bind(wx.EVT_COMBOBOX, funcaoChamadaEmEvento, self.escolhas)
    self.rotulo = wx.StaticText(self, label = rotulo, style = wx.ALIGN_LEFT|wx.ALIGN_CENTRE_HORIZONTAL|wx.ALIGN_CENTRE_VERTICAL)

    self.sizer.AddSpacer(gui_constantes.ESPACAMENTO * 2)
    self.sizer.Add(self.rotulo, flag = wx.ALIGN_CENTER_VERTICAL)
    self.sizer.AddSpacer(gui_constantes.ESPACAMENTO)
    self.sizer.Add(self.escolhas, flag = wx.ALIGN_CENTER_VERTICAL)
    self.sizer.AddSpacer(gui_constantes.ESPACAMENTO)
    
  def obterOpcaoSelecionada(self):
    return self.escolhas.GetValue()