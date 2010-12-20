# -*- coding: latin-1 -*-

import wx
import os
from conversor import ValidadorDeArquivos
from conversor import ConversorDeArquivos

global COMPRIMENTO_MAXIMO
global ALTURA_MAXIMA

COMPRIMENTO_MAXIMO = 400
ALTURA_MAXIMA = 300

class PainelPrincipal(wx.Panel):
  
  def __init__(self, *args, **kwargs):
    wx.Panel.__init__(self, *args, **kwargs)
    self.Inicializar()
    self.validador = ValidadorDeArquivos()
    self.conversor = ConversorDeArquivos()
    self.arquivosParaConverter = []
    
  def Inicializar(self):
    self.sizer = wx.BoxSizer(wx.VERTICAL)
    self.SetSizer(self.sizer)
    
    tmp = wx.BoxSizer(wx.HORIZONTAL)
    self.fileBrowser = PegadorDeArquivo(self)
    self.botaoConverter = wx.Button(self, label='Converter')
    self.Bind(wx.EVT_BUTTON, self.ClicouEmConverter, self.botaoConverter)
    self.arquivosEscolhidos = wx.TextCtrl(self, size = (COMPRIMENTO_MAXIMO - 50, ALTURA_MAXIMA - 55),style = wx.TE_MULTILINE);
    
    self.sizer.Add(tmp)
    self.sizer.AddSpacer(2)
    tmp.Add(self.fileBrowser)
    tmp.Add(self.botaoConverter, 0, wx.GROW|wx.EXPAND|wx.ALL, 5)
    self.sizer.Add(self.arquivosEscolhidos, 0, wx.GROW|wx.EXPAND|wx.ALL, 5)

   
  def ValidarArquivos(self, nomes, diretorio):
    if(len(self.arquivosParaConverter) == 0):
      self.arquivosEscolhidos.Clear()
      
    for nome in nomes:
      caminhoCompleto = os.path.join(diretorio, nome)
      if(self.validador.ArquivoEstaOk(diretorio, nome)):
        tmp = caminhoCompleto + " - " + "Ok" + "\n"
        self.arquivosParaConverter.append(caminhoCompleto)
      else:
        tmp = caminhoCompleto + " - " + "Arquivo inválido" + "\n"
        
      self.arquivosEscolhidos.AppendText(tmp)
      
  def ClicouEmConverter(self, event):
    self.arquivosEscolhidos.Clear()
    
    if(len(self.arquivosParaConverter) == 0):
      self.arquivosEscolhidos.AppendText('Nenhum arquivo foi escolhido')
    
    for arquivo in self.arquivosParaConverter:
      tmp = ''
      if(self.conversor.ConverterArquivo(arquivo)):
        tmp = arquivo + ' - ' + 'foi convertido' + '\n'
      else:
        tmp = arquivo + ' - ' + 'ocorreu um erro' + '\n'
        
      self.arquivosEscolhidos.AppendText(tmp)
      
    self.arquivosParaConverter = []
      
   
   
    
class PegadorDeArquivo(wx.Panel):
  
  def __init__(self, parent, **kwargs):
    wx.Panel.__init__(self, parent, **kwargs)
    self.Inicializar()
    self.pai = parent
    
  def Inicializar(self):

    self.sizer = wx.FlexGridSizer(1,2,0,0)
    self.SetSizer(self.sizer)
    
    self.fileBrowser = wx.FileDialog(self, message = "Escolha os arquivos a serem convertidos", style = wx.FD_MULTIPLE)
    self.botaoProcurarArquivo = wx.Button(self, label="Procurar")
    self.sizer.Add(self.botaoProcurarArquivo, 0, wx.GROW|wx.EXPAND|wx.ALL, 5);
    
    self.Bind(wx.EVT_BUTTON, self.ClicouProcurar, self.botaoProcurarArquivo)
    self.sizer.FitInside(self)
    
  def ClicouProcurar(self, event):
    estado = self.fileBrowser.ShowModal()
    if(estado == wx.ID_OK):
      self.nomeArquivos = self.fileBrowser.GetFilenames()
      self.diretorioDosArquivos = self.fileBrowser.GetDirectory()
      self.pai.ValidarArquivos(self.nomeArquivos, self.diretorioDosArquivos)
      
    