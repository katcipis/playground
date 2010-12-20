from gui.JanelaPrincipal import JanelaPrincipal
import sys
import wx

class MyApp(wx.App):
  
  def OnInit(self):
    self.frame = wx.Frame(None, -1, 'Chat Serial', size = (800,600), 
                           style = wx.CAPTION|wx.SYSTEM_MENU|wx.MINIMIZE_BOX|wx.MAXIMIZE_BOX|wx.CLOSE_BOX|wx.RESIZE_BORDER|wx.CLIP_CHILDREN|wx.VSCROLL|wx.HSCROLL|wx.TAB_TRAVERSAL)
    self.painelPrincipal = JanelaPrincipal(self.frame)
   
    
    self.SetTopWindow(self.frame)
    self.frame.Show(True)

    return True
  
  def obterConexaoSerial(self):
    return self.painelPrincipal.obterConexaoSerial()
  

def main():
  app = MyApp(0)
  conexao = app.obterConexaoSerial()
  app.MainLoop()
  conexao.terminar()

if __name__ == "__main__":
    main()
    