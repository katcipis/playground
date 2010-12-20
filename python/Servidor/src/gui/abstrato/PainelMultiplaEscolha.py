import wx
from gui.componentes.EscolhasComRotulo import EscolhasComRotulo
from gui.paineisGeradores.PainelCamposGeradorExponencial import PainelCamposGeradorExponencial
from gui.paineisGeradores.PainelCamposGeradorNormal import PainelCamposGeradorNormal
from gui.paineisGeradores.PainelCamposGeradorTriangular import PainelCamposGeradorTriangular
from gui import gui_constantes
import os

def atualizarRecursivamente(parent):
  if(parent != None):
    parent.FitInside()
    parent.Layout()
    parent.Refresh()
    parent.Update()
    
    try:
      atualizarRecursivamente(parent._parent)
    except AttributeError:
      pass

   

class PainelMultiplaEscolha(wx.Panel):
  
  def __init__(self, parent, frame, *args, **kwargs):
    wx.Panel.__init__(self, parent, *args, **kwargs)
    
    self._parent = parent
    self._frame = frame
    
    self._sizerDoPainelInterno = wx.FlexGridSizer(1, 0, 1, 1) 
    self._sizerDoPainelInterno.AddGrowableRow(0)
    
    self._paineisInternos = self._obterPaineisInternos()
    self._painelInternoAtual = None
    self._inicializar()
    
  def _inicializar(self):
    self.sizer = wx.FlexGridSizer(1, 0, 1, 1) 
    self.sizer.AddGrowableRow(0)
    self.SetSizer(self.sizer)
    
    self._opcoes = self._obterOpcoes()
    self._escolhas = EscolhasComRotulo(parent = self, 
                                      rotulo = self._obterRotulo(), 
                                      opcoes = self._opcoes, 
                                      funcaoChamadaEmEvento = self.clicouEmTipoDoGerador)
    
    self.sizer.Add(self._escolhas)
    self.sizer.AddSpacer(gui_constantes.ESPACAMENTO)
    self.sizer.Add(self._sizerDoPainelInterno)
    
  def _obterPaineisInternos(self):
    """ ABSTRATO: RETORNAR O MAPA DE PAINEIS INTERNOS <Opcao, Instancia de painel>"""
    
  def _obterOpcoes(self):
    """ ABSTRATO: DEFINIR A LISTA DE OPCOES (Strings)"""
  
  def _obterRotulo(self):
    """ ABSTRATO: DEFINIR O ROTULO (String)"""
    
  def obterValoresNosCamposAtuais(self):
    if(self._painelInternoAtual == None):
      return None
      
    return self._painelInternoAtual.obterValoresNosCampos()
      
  def clicouEmTipoDoGerador(self, evento):
    self._sizerDoPainelInterno.Clear()
    
    for opcao in self._paineisInternos.keys():
      self._paineisInternos[opcao].Show(False)
    
    self._painelInternoAtual = self._paineisInternos[self._escolhas.obterOpcaoSelecionada()]
    self._sizerDoPainelInterno.Add(self._painelInternoAtual)
    self._sizerDoPainelInterno.ShowItems(True)
    self._sizerDoPainelInterno.Layout()
    if(os.name == 'nt'):
      atualizarRecursivamente(self)
    self._frame.SendSizeEvent() 
       
    
  def obterEscolhaSelecionada(self):
    return self._escolhas.obterOpcaoSelecionada()
  
  def obterPainelDeEscolhaDeTempoAleatorio(self):
    return self._painelFreqDiferenteEmp
    
    
