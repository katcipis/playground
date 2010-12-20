import wx
from gui import gui_constantes

class CamposComRotulo(wx.Panel):
  
  def __init__(self, parent, rotulosDosCampos, tamanhoDosCampos = wx.DefaultSize):
    wx.Panel.__init__(self, parent)
    self.__campos = {}
    self.__tamanhoDosCampos = tamanhoDosCampos
    self.Inicializar(rotulosDosCampos)
    
  def Inicializar(self, rotulosDosCampos):
    self.sizer =  wx.FlexGridSizer(0, 1, 1, 1) 
    self.SetSizer(self.sizer)
    i = 0
    for rotulo in rotulosDosCampos:
      self.sizer.AddGrowableRow(i)
      i += 1
      campo = wx.TextCtrl(parent = self, size = self.__tamanhoDosCampos)
      rotuloDoCampo = wx.StaticText(self, label = rotulo,  
                                    style = wx.ALIGN_LEFT|wx.ALIGN_CENTRE_HORIZONTAL|wx.ALIGN_CENTRE_VERTICAL)
      
      self.sizer.Add(rotuloDoCampo, flag = wx.ALIGN_CENTER_VERTICAL)
      self.sizer.Add(campo, flag = wx.ALIGN_CENTER_VERTICAL|wx.GROW|wx.EXPAND|wx.ALL)
            
      self.__campos[rotulo] = campo
    
  def obterValorDoCampoComOSeguinteRotulo(self, rotulo):
    if(self.__campos.has_key(rotulo)):
      return self.__campos[rotulo].GetValue()
    
  def obterCampoComOSeguinteRotulo(self, rotulo):
    if(self.__campos.has_key(rotulo)):
      return self.__campos[rotulo]