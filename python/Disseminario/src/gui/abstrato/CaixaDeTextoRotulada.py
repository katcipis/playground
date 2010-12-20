# -*- coding: latin-1 -*-
import wx
from gui.abstrato.ComponenteRotulado import ComponenteRotulado

class CaixaDeTextoRotulada(ComponenteRotulado):
  
  def __init__(self,pai, estilo = wx.TE_PROCESS_ENTER|wx.TE_LEFT|wx.TE_BESTWRAP):
    ComponenteRotulado.__init__(self, pai)

    self.__caixaDeTexto = wx.TextCtrl(parent = self, value = self._obterTextoInicial(), style = estilo)
    self.Bind(wx.EVT_TEXT_ENTER, self._trataCliqueEnterDentroDaCaixa, self.__caixaDeTexto)
    
    self._sizer.Add(self.__caixaDeTexto, proportion = 1, flag = wx.EXPAND)
    
  def obterTexto(self):
    return self.__escolhas.GetValue()
  
  def substituirTexto(self, novoTexto):
    self.__caixaDeTexto.Clear()
    self.adcionarTexto(novoTexto)
    
  def adcionarTexto(self, texto):
    self.__caixaDeTexto.AppendText(texto)
    
  def bloquearCaixaDeTexto(self):
    self.__caixaDeTexto.SetEditable(False)
    
  def desbloquearCaixaDeTexto(self):
    self.__caixaDeTexto.SetEditable(True)
    
  def _obterTextoInicial(self):
    """ Funcao abstrata, deve retornar uma string que sera o conteudo da caixa de texto."""
    return ''
    
  def _trataCliqueEnterDentroDaCaixa(self, evento):
    """ Funcao abstrata, esta funcao sera chamada sempre que for clicado enter 
        com o foco dentro da caixa de texto """
    