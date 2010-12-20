# -*- coding: latin-1 -*-
import wx

_NOME_APLICACAO             = 'Disseminário'
_TAMANHO_DO_FRAME_PRINCIPAL = (800, 600)

class FramePrincipal(wx.Frame):
   
   def __init__(self):
     wx.Frame.__init__(self, None, -1, _NOME_APLICACAO, size = _TAMANHO_DO_FRAME_PRINCIPAL, 
                                                                 style = wx.CAPTION|wx.SYSTEM_MENU|wx.MINIMIZE_BOX|wx.MAXIMIZE_BOX|wx.CLOSE_BOX|wx.RESIZE_BORDER|wx.CLIP_CHILDREN|wx.VSCROLL|wx.HSCROLL|wx.TAB_TRAVERSAL)
     
     self.__barraMenu = wx.MenuBar()
     self.__menuArquivo = wx.Menu()
     
     self.__menuArquivo.Append(wx.ID_OPEN, 'Log in', 'Logar no servidor', wx.ITEM_NORMAL)
     self.__menuArquivo.Append(wx.ID_SAVE, 'Salvar', 'Salvar alterações no servidor', wx.ITEM_NORMAL)
     self.__menuArquivo.AppendSeparator()
     self.__menuArquivo.Append(wx.ID_EXIT, 'Sair', 'Sair', wx.ITEM_NORMAL)
     
     self.__barraMenu.Append(self.__menuArquivo, 'Opções')
     self.SetMenuBar(self.__barraMenu)