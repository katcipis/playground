# -*- coding: latin-1 -*-
import wx
from gui.PainelTempoEntreChegadas import PainelTempoEntreChegadas
from gui.PainelTempoEntreFalhas import PainelTempoEntreFalhas
from gui.PainelTempoEmFalha import PainelTempoEmFalha
from gui.PainelTempoDeServicoServidores import PainelTempoDeServicoServidores
from gui.PainelDosBotoes import PainelDosBotoes
from gui.PainelLocalizacaoRelatorio import PainelLocalizacaoRelatorio
from gui.PainelLimiteDasFilas import PainelLimiteDasFilas
from gui.PainelTempoDeDuracao import PainelTempoDeDuracao
from gui.FrameDeLogDeEventos import FrameDeLogDeEventos
from gui import gui_constantes

from mediador.MediadorTempoEntreChegadas import MediadorTempoEntreChegadas
from mediador.MediadorTemposEmGeral import MediadorTemposEmGeral
from mediador.MediadorLimitesDasFilas import MediadorLimitesDasFilas
from mediador.MediadorTempoDeDuracao import MediadorTempoDeDuracao
from mediador.MediadorLocalizacaoRelatorio import MediadorLocalizacaoRelatorio
from mediador.MediadorSimulador import MediadorSimulador

class FramePrincipal(wx.Frame):
  def __init__(self, *args, **kwargs):
    wx.Frame.__init__(self, *args, **kwargs)
    
       
class MyApp(wx.App):
  
  def OnInit(self):
    self.frame = FramePrincipal(None, -1, "Simulador de servidores v 0.1", size = gui_constantes.TAMANHO_DO_FRAME_PRINCIPAL, 
                           style = wx.CAPTION|wx.SYSTEM_MENU|wx.MINIMIZE_BOX|wx.MAXIMIZE_BOX|wx.CLOSE_BOX|wx.RESIZE_BORDER|wx.CLIP_CHILDREN|wx.VSCROLL|wx.HSCROLL|wx.TAB_TRAVERSAL)
    self.painelPrincipal = wx.ScrolledWindow(self.frame, style = wx.NO_BORDER|wx.VSCROLL|wx.HSCROLL|wx.CLIP_CHILDREN)
    self.painelPrincipal.SetScrollbars(20, 20, 50, 50);
    
    self.sizerPainelPrincipal = wx.FlexGridSizer(8,1,0,0)
    self.painelPrincipal.SetSizer(self.sizerPainelPrincipal)
    
    self.painelTempoEntreChegadas = PainelTempoEntreChegadas(parent = self.painelPrincipal,frame = self.frame)
    self.painelTempoDeServicoServidores = PainelTempoDeServicoServidores(parent = self.painelPrincipal,frame = self.frame)
    self.painelTempoEntreFalhas = PainelTempoEntreFalhas(parent = self.painelPrincipal,frame = self.frame)
    self.painelTempoEmFalha = PainelTempoEmFalha(parent = self.painelPrincipal,frame = self.frame)
    
    self.painelLimiteDasFilas = PainelLimiteDasFilas(parent = self.painelPrincipal) 
    self.painelLocalizacaoRelatorio = PainelLocalizacaoRelatorio(parent = self.painelPrincipal)
    self.painelTempoDeDuracao =  PainelTempoDeDuracao(parent = self.painelPrincipal)
    self.painelDosBotoes = PainelDosBotoes(parent = self.painelPrincipal,
                                           funcaoQueLidaComCliqueSimul = self.apertouBotaoSimul,
                                           funcaoQueLidaComCliqueCancel = self.apertouBotaoCancel)
    
    self.sizerPainelPrincipal.Add(self.painelTempoEntreChegadas)
    self.sizerPainelPrincipal.Add(self.painelTempoDeServicoServidores)
    self.sizerPainelPrincipal.Add(self.painelTempoEntreFalhas)
    self.sizerPainelPrincipal.Add(self.painelTempoEmFalha)
    self.sizerPainelPrincipal.Add(self.painelLimiteDasFilas)
    self.sizerPainelPrincipal.Add(self.painelTempoDeDuracao)
    self.sizerPainelPrincipal.Add(self.painelLocalizacaoRelatorio)
    self.sizerPainelPrincipal.Add(self.painelDosBotoes)
    
    self.SetTopWindow(self.frame)
    self.frame.Show(True)
    self.iniciarMediadores()
    self.countSimul = 0
    return True
  
  def apertouBotaoSimul(self, event):
    self.countSimul += 1
    self.mediadorSimulador = MediadorSimulador(self.mediadorTempoEntreChegadas, self.mediadorTempoDeServico,
                                               self.mediadorTempoEmFalha, self.mediadorTempoEntreFalhas,
                                               self.mediadorLimiteDasFilas, self.mediadorLocalizacaoRelatorio,
                                               self.mediadorTempoDeDuracao)
    self.frameLog = FrameDeLogDeEventos(mediadorSimulador = self.mediadorSimulador,
                                   parent = None, id = -1, title = "Log da simulacao " + str(self.countSimul), size = gui_constantes.TAMANHO_DA_JANELA_DE_LOG, 
                                   style = wx.CAPTION|wx.SYSTEM_MENU|wx.MINIMIZE_BOX|wx.MAXIMIZE_BOX|wx.CLOSE_BOX|wx.RESIZE_BORDER|wx.CLIP_CHILDREN|wx.VSCROLL|wx.HSCROLL|wx.TAB_TRAVERSAL)
    self.frameLog.Show(True)
    self.mediadorSimulador.start()
    self.frameLog.start()
    
  def apertouBotaoCancel(self, event):
    if(not (self.mediadorSimulador == None)):
      self.mediadorSimulador.cancelarSimulacao()

  def iniciarMediadores(self):
    self.mediadorTempoEntreChegadas = MediadorTempoEntreChegadas(self.painelTempoEntreChegadas)
    self.mediadorTempoDeServico = MediadorTemposEmGeral(self.painelTempoDeServicoServidores)
    self.mediadorTempoEmFalha = MediadorTemposEmGeral(self.painelTempoEmFalha)
    self.mediadorTempoEntreFalhas  = MediadorTemposEmGeral(self.painelTempoEntreFalhas)
    self.mediadorLimiteDasFilas = MediadorLimitesDasFilas(self.painelLimiteDasFilas)
    self.mediadorLocalizacaoRelatorio = MediadorLocalizacaoRelatorio(self.painelLocalizacaoRelatorio)
    self.mediadorTempoDeDuracao = MediadorTempoDeDuracao(self.painelTempoDeDuracao)
    
    

def main():
  app = MyApp(0)
  app.MainLoop()

if __name__ == "__main__":
    main()