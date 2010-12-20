from gui.abstrato.PainelDeSelecaoDeTempo import PainelDeSelecaoDeTempo

class PainelTempoDeServicoServidores(PainelDeSelecaoDeTempo):
  
  def __init__(self, parent, frame, *args, **kwargs):
    PainelDeSelecaoDeTempo.__init__(self, parent , frame)
    
  
  def _obterRotulo(self):
    return 'Tempo de servico dos servidores: '
    
  def _obterRotuloDoGeradorUm(self):
    return 'Servidor 1: '
    
  def _obterRotuloDoGeradorDois(self):
    return 'Servidor 2: '
