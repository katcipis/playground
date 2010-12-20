import wx
from gui.abstrato.PainelDeCampos import PainelDeCampos
from gui import gui_rotulos

class PainelCamposMesmoTempo(PainelDeCampos):
  
  def __init__(self, *args, **kwargs):
    PainelDeCampos.__init__(self, *args, **kwargs)
    
  def obterRotuloDosCampos(self):
    return [gui_rotulos.TEMPO]
  