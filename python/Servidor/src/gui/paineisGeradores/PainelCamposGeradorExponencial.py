import wx
from gui.abstrato.PainelDeCampos import PainelDeCampos
from gui import gui_rotulos
class PainelCamposGeradorExponencial(PainelDeCampos):
  
  def __init__(self, *args, **kwargs):
    PainelDeCampos.__init__(self, *args, **kwargs)
    
  def obterRotuloDosCampos(self):
    return [gui_rotulos.SEMENTE, gui_rotulos.MEDIA]
  