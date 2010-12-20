import wx

ESPACAMENTO_ENTRE_FILHOS = wx.Size(20,20)

class DialogoDeMensagem(wx.Dialog):
  
  def __init__(self, pai, titulo, mensagemDeErro):
    wx.Dialog.__init__(self, pai, title = titulo, style = wx.DEFAULT_DIALOG_STYLE|wx.RESIZE_BORDER)
    
    self.__sizer = wx.BoxSizer(wx.VERTICAL)
    self.SetSizer(self.__sizer)
    
    self.__rotulo = wx.StaticText(self, label = mensagemDeErro, style = wx.ALIGN_CENTRE)
    self.__sizerBotaoOk = self.CreateButtonSizer(wx.OK)
    
    self.__sizer.Add(ESPACAMENTO_ENTRE_FILHOS)
    self.__sizer.Add(self.__rotulo, flag = wx.ALIGN_CENTER_VERTICAL|wx.ALIGN_CENTER_HORIZONTAL)
    self.__sizer.Add(ESPACAMENTO_ENTRE_FILHOS)
    self.__sizer.Add(self.__sizerBotaoOk, flag = wx.ALIGN_CENTER_VERTICAL|wx.ALIGN_CENTER_HORIZONTAL)
    self.SetSize(self.GetMinSize())
    
    