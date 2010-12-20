# -*- coding: latin-1 -*-

import wx
from gui import PainelPrincipal
import gui

class FramePrincipal(wx.Frame):
  def __init__(self, *args, **kwargs):
    wx.Frame.__init__(self, *args, **kwargs)
       

class MyApp(wx.App):
  def OnInit(self):
    frame = FramePrincipal(None, -1, "Conversor CSV", size = (gui.COMPRIMENTO_MAXIMO, gui.ALTURA_MAXIMA))
    self.SetTopWindow(frame)
    painel = PainelPrincipal(frame) 
    frame.Show(True)
    melhorTamanho = painel.GetSize()
    melhorTamanho.SetHeight(melhorTamanho.GetHeight() + 70)
    frame.SetSize(melhorTamanho)
    return True


def main():
  app = MyApp(0)
  app.MainLoop()

if __name__ == "__main__":
    main()

