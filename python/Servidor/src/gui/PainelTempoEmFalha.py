from gui.abstrato.PainelDeSelecaoDeTempo import PainelDeSelecaoDeTempo

class PainelTempoEmFalha(PainelDeSelecaoDeTempo):
  
  def __init__(self, parent, frame, *args, **kwargs):
    PainelDeSelecaoDeTempo.__init__(self, parent , frame)
    
  def _obterRotulo(self):
    return 'Tempo em falha: '
    
  def _obterRotuloDoGeradorUm(self):
    return 'Servidor 1: '
    
  def _obterRotuloDoGeradorDois(self):
    return 'Servidor 2: '
