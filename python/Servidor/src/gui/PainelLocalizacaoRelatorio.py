import wx
from gui import gui_rotulos
from gui.componentes.CamposComRotulo import CamposComRotulo

class PainelLocalizacaoRelatorio(wx.Panel):
  
  def __init__(self, parent , *args, **kwargs):
    wx.Panel.__init__(self, parent)
    self.Inicializar()
    
  def Inicializar(self):
    self._sizer = wx.FlexGridSizer(1, 1, 1, 1) 
    self._sizer.AddGrowableRow(0)
    self._sizer.AddGrowableCol(0)
    self.SetSizer(self._sizer)
    self._localizacaoRelatorio = CamposComRotulo(self, [gui_rotulos.LOCALIZACAO_RELATORIO])
    self._browserDeArquivo = wx.FileDialog(self, message = "Escolha onde salvar o relatorio", style = wx.FD_OVERWRITE_PROMPT|wx.FD_SAVE)
    
    self.botaoBuscar = self.botaoConverter = wx.Button(self, label='Buscar')
    self.Bind(wx.EVT_BUTTON, self._definirEnderecoDeSalvamento, self.botaoBuscar)
    self._sizer.Add(self._localizacaoRelatorio)
    self._sizer.Add(self._browserDeArquivo)
    self._sizer.Add(self.botaoBuscar)
    
    
  def obterEnderecoRelatorio(self):
    return self._localizacaoRelatorio.obterValorDoCampoComOSeguinteRotulo(gui_rotulos.LOCALIZACAO_RELATORIO)
  
  def _definirEnderecoDeSalvamento(self, event):
    estado = self._browserDeArquivo.ShowModal()
    if(estado == wx.ID_OK):
      nomeArquivo = self._browserDeArquivo.GetFilename()
      diretorioDosArquivo = self._browserDeArquivo.GetDirectory()
      self._localizacaoRelatorio.obterCampoComOSeguinteRotulo(gui_rotulos.LOCALIZACAO_RELATORIO).SetValue(diretorioDosArquivo + nomeArquivo)
    
    