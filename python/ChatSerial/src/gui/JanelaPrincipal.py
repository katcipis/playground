'''
Created on 29/03/2009
@author: Tiago Katcipis
'''
import wx
from modelo.portas_disponiveis import obter_portas_disponiveis
from modelo.GerenciadorConexaoSerial import GerenciadorConexaoSerial

_ESPACAMENTO = wx.Size(10,10)

class JanelaPrincipal(wx.Panel):

  def __init__(self, parent):
    wx.Panel.__init__(self, parent)
    self.__sizer = wx.BoxSizer(wx.VERTICAL)
    self.SetSizer(self.__sizer)
    
    sizerComboBox = wx.BoxSizer(wx.HORIZONTAL)
    rotulo =  wx.StaticText(self, label = 'Portas disponiveis:',  style = wx.ALIGN_LEFT)
    self.__comboBox = wx.ComboBox(parent = self, choices = obter_portas_disponiveis())
    sizerComboBox.Add(rotulo)
    sizerComboBox.Add(self.__comboBox)
    
    self.__sizer.Add(_ESPACAMENTO)
    self.__sizer.Add(sizerComboBox, border = 10)
    self.__sizer.Add(_ESPACAMENTO)
    
    self.__caixaDeTextoCliente = wx.TextCtrl(self, style = wx.TE_MULTILINE)
    self.__caixaDeTextoRemota = wx.TextCtrl(self, style = wx.TE_READONLY|wx.TE_MULTILINE)
    
    self.__sizer.Add(wx.StaticText(self, label = 'Remoto:',  style = wx.ALIGN_LEFT))
    self.__sizer.Add(self.__caixaDeTextoRemota, proportion = 1, flag = wx.EXPAND, border = 10)
    self.__sizer.Add(_ESPACAMENTO)
    
    self.__sizer.Add(wx.StaticText(self, label = 'Cliente:',  style = wx.ALIGN_LEFT))
    self.__sizer.Add(self.__caixaDeTextoCliente, proportion = 1, flag = wx.EXPAND, border = 10)
    self.__sizer.Add(_ESPACAMENTO)
    
    self.Bind(wx.EVT_COMBOBOX, self.__trataCliqueComboBox, self.__comboBox)
    self.__conexaoSerial = GerenciadorConexaoSerial(self)
    self.__conexaoSerial.start()
    
  def __trataCliqueComboBox(self, evento):
    porta = self.__comboBox.GetValue()
    if(porta == ''):
      return
    self.__conexaoSerial.setDispositivoSerial(str(porta))  
    
  def obterConexaoSerial(self):
    return self.__conexaoSerial
    

  def gravarTextoRemoto(self, texto):
    self.__caixaDeTextoRemota.ChangeValue(texto)
        
  def obterTextoCliente(self):
    return str(self.__caixaDeTextoCliente.GetValue())