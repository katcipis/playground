import wx
from gui import gui_rotulos
from gui import gui_constantes
from mediador.MediadorSimulador import MediadorSimulador
import time
import threading

class FrameDeLogDeEventos(wx.Frame, threading.Thread):
  def __init__(self, mediadorSimulador, *args, **kwargs):
    wx.Frame.__init__(self, *args, **kwargs)
    threading.Thread.__init__(self)
    self.__logList = mediadorSimulador.obterAListaDeLog()
    self.__mediadorSimulador = mediadorSimulador
    self.__campoDeLog = wx.TextCtrl(self, size = gui_constantes.TAMANHO_DA_JANELA_DE_LOG, style = wx.TE_MULTILINE|wx.TE_READONLY);
    
    
  def run(self):
    
    while(self.__mediadorSimulador.simulacaoTerminou()):
      time.sleep(1)
    
    while((not self.__mediadorSimulador.simulacaoTerminou()) and 
          (len(self.__logList) != 0)):
      
      while(len(self.__logList) != 0):
        self.__campoDeLog.AppendText(self.__logList.pop(0) + '\n')
        time.sleep(0.1)
              
    self.__campoDeLog.AppendText('------ Simulacao terminou ------')
        
    
        