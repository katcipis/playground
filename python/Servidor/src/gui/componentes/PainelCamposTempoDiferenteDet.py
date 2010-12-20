import wx
from gui.abstrato.PainelDeCampos import PainelDeCampos
from gui import gui_rotulos
class PainelCamposTempoDiferenteDet(PainelDeCampos):
  
  def __init__(self, *args, **kwargs):
    PainelDeCampos.__init__(self, *args, **kwargs)
    
  def obterRotuloDosCampos(self):
    return [gui_rotulos.TEMPO_UM, gui_rotulos.TEMPO_DOIS]
  