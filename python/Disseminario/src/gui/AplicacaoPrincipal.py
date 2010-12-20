# -*- coding: latin-1 -*-
import wx
from gui.PainelDeEscolhaDeSeminarios import PainelDeEscolhaDeSeminarios
from gui.FramePrincipal import FramePrincipal

#CONSTANTES
PIXELS_POR_SCROLL_HORIZONTAL = 20
PIXELS_POR_SCROLL_VERTICAL =   20

NUMERO_UNIDADES_DE_SCROLL_HORIZONTAL = 50
NUMERO_UNIDADES_DE_SCROLL_VERTICAL   = 50


class ConstrutorAplicacaoPrincipal:
  """ Classe responsável pela criação e inicialização da aplicação principal, garantindo que exista apenas uma instância. """
  aplicacaoPrincipal = None
  
  def obterAplicacaoPrincipal(self):
    if(ConstrutorAplicacaoPrincipal.aplicacaoPrincipal == None):
      ConstrutorAplicacaoPrincipal.aplicacaoPrincipal = ConstrutorAplicacaoPrincipal.__AplicacaoPrincipal(0)
      
    return ConstrutorAplicacaoPrincipal.aplicacaoPrincipal
  
  class __AplicacaoPrincipal(wx.App):
    """ Esta classe nunca deve ser utilizada diretamente, para instância-la utilize o ConstrutorAplicacaoPrincipal. """
    def OnInit(self):
      self.__frame = FramePrincipal()
    
      self.__painelPrincipal = wx.ScrolledWindow(self.__frame, style = wx.TAB_TRAVERSAL|wx.NO_BORDER|wx.VSCROLL|wx.HSCROLL|wx.CLIP_CHILDREN)
      self.__painelPrincipal.SetScrollbars(PIXELS_POR_SCROLL_HORIZONTAL, PIXELS_POR_SCROLL_VERTICAL, 
                                           NUMERO_UNIDADES_DE_SCROLL_HORIZONTAL, NUMERO_UNIDADES_DE_SCROLL_VERTICAL);
    
      self.__sizerPainelPrincipal = wx.BoxSizer(wx.VERTICAL)
      self.__painelPrincipal.SetSizer(self.__sizerPainelPrincipal)
    
      self.SetTopWindow(self.__frame)
      self.__frame.Show(True)
      return True
  
    def obterFramePrincipal(self):
      return self.__frame
  
    def obterPainelPrincipal(self):
      return self.__painelPrincipal
  
  