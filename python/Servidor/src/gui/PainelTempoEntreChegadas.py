from gui.abstrato.PainelDeSelecaoDeTempo import PainelDeSelecaoDeTempo
from gui.componentes.PainelCamposMesmaFrequencia import PainelCamposMesmaFrequencia
from gui.componentes.PainelCamposFreqDiferenteDet import PainelCamposFreqDiferenteDet 
from gui.componentes.PainelDuasFreqDiferenteEmpirica import PainelDuasFreqDiferenteEmpirica 

class PainelTempoEntreChegadas(PainelDeSelecaoDeTempo):
  
  def __init__(self, parent, frame, *args, **kwargs):
    PainelDeSelecaoDeTempo.__init__(self, parent , frame)
    
  def _obterPaineisInternos(self):
    self._painelMesmaFreq  = PainelCamposMesmaFrequencia(self)
    self._painelFreqDiferenteDet = PainelCamposFreqDiferenteDet(self)
    self._painelFreqDiferenteEmp = PainelDuasFreqDiferenteEmpirica(parent = self, frame= self._frame, 
                                                                    rotuloUm = self._obterRotuloDoGeradorUm(), 
                                                                    rotuloDois = self._obterRotuloDoGeradorDois())
    
    self._painelMesmaFreq.Show(False)
    self._painelFreqDiferenteDet.Show(False)
    self._painelFreqDiferenteEmp.Show(False)
    
    return { self._freqIgual : self._painelMesmaFreq,
             self._freqDiferenteDet : self._painelFreqDiferenteDet,
             self._freqDiferenteEmp : self._painelFreqDiferenteEmp
           }
  
  def _obterRotulo(self):
    return 'Tempo entre chegadas: '
    
  def _obterRotuloDoGeradorUm(self):
    return 'Entidade 1: '
    
  def _obterRotuloDoGeradorDois(self):
    return 'Entidade 2: '
