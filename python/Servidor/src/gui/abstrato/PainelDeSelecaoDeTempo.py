from gui.abstrato.PainelMultiplaEscolha import PainelMultiplaEscolha
from gui.componentes.EscolhasComRotulo import EscolhasComRotulo
from gui.componentes.PainelCamposMesmoTempo import PainelCamposMesmoTempo
from gui.componentes.PainelCamposTempoDiferenteDet import PainelCamposTempoDiferenteDet
from gui.componentes.PainelDuasFreqDiferenteEmpirica import PainelDuasFreqDiferenteEmpirica
from gui import gui_constantes
from gui import gui_rotulos

class PainelDeSelecaoDeTempo(PainelMultiplaEscolha):
  
  def __init__(self, parent, frame, *args, **kwargs):
    self._freqIgual = gui_rotulos.IGUAL
    self._freqDiferenteDet = gui_rotulos.DIFERENTE_DETERMINISTICA
    self._freqDiferenteEmp = gui_rotulos.DIFERENTE_ALEATORIA
    PainelMultiplaEscolha.__init__(self, parent , frame)
    
  
  def _obterPaineisInternos(self):
    self._painelMesmaFreq  = PainelCamposMesmoTempo(self)
    self._painelFreqDiferenteDet = PainelCamposTempoDiferenteDet(self)
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
    
  def obterValoresNosCamposAtuais(self):
    if(self._painelInternoAtual == None):
      return None
    
    if(self._painelInternoAtual == self._painelFreqDiferenteEmp):
      valoresUm = self._painelFreqDiferenteEmp.obterPainelUm().obterValoresNosCamposAtuais()
      valoresDois = self._painelFreqDiferenteEmp.obterPainelDois().obterValoresNosCamposAtuais()
      
      if(valoresUm != None and valoresDois != None):
        return valoresUm, valoresDois
      
      return None
      
    return self._painelInternoAtual.obterValoresNosCampos()
                              
  def _obterOpcoes(self):
    return [self._freqIgual, self._freqDiferenteDet, self._freqDiferenteEmp]
  
  def _obterRotulo(self):
    """ ABSTRATO : DEFINIR O NOME DO PAINEL DE SELECAO (string)"""
    
  def _obterRotuloDoGeradorUm(self):
    """ ABSTRATO : DEFINIR O NOME DO PRIMEIRO GERADOR DE TEMPO (string)"""
    
  def _obterRotuloDoGeradorDois(self):
    """ ABSTRATO : DEFINIR O NOME DO SEGUNDO GERADOR DE TEMPO (string)"""
