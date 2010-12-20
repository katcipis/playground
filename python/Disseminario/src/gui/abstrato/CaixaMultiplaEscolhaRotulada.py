# -*- coding: latin-1 -*-
import wx
from gui.abstrato.ComponenteRotulado import ComponenteRotulado

class CaixaMultiplaEscolhaRotulada(ComponenteRotulado):
  
  def __init__(self,pai):
    ComponenteRotulado.__init__(self, pai)

    self.__escolhas = wx.ComboBox(parent = self, choices = self._obterEscolhas())
    self.Bind(wx.EVT_COMBOBOX, self._trataCliqueNaCaixa, self.__escolhas)
    self._sizer.Add(self.__escolhas, proportion = 1, flag = wx.EXPAND)
    
  def obterOpcaoSelecionada(self):
    return self.__escolhas.GetValue()
  
  def _obterEscolhas(self):
    """ Função abstrata, deve retornar uma lista de strings que serão as escolhas."""
    return ''
    
  def _trataCliqueNaCaixa(self, evento):
    """ Função abstrata, esta função será chamada sempre que for clicado em uma das opções da 
        caixa de multipla escolha """
    return None    