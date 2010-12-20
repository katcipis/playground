from gui.componentes.EscolhasComRotulo import EscolhasComRotulo
from gui.paineisGeradores.PainelCamposGeradorExponencial import PainelCamposGeradorExponencial
from gui.paineisGeradores.PainelCamposGeradorNormal import PainelCamposGeradorNormal
from gui.paineisGeradores.PainelCamposGeradorTriangular import PainelCamposGeradorTriangular
from gui.paineisGeradores.PainelCamposGeradorAleatorio import PainelCamposGeradorAleatorio
from gui.abstrato.PainelMultiplaEscolha import PainelMultiplaEscolha
from gui import gui_constantes
from gui import gui_rotulos

class PainelFrequenciaEmpirica(PainelMultiplaEscolha):
  
  def __init__(self, rotulo, parent, frame, *args, **kwargs):
    self.__distribuicaoNormal = gui_rotulos.NORMAL
    self.__distribuicaoExponencial = gui_rotulos.EXPONENCIAL
    self.__distribuicaoTriangular = gui_rotulos.TRIANGULAR
    self.__distribuicaoAleatoria = gui_rotulos.ALEATORIA
    self._rotulo = rotulo
    PainelMultiplaEscolha.__init__(self, parent = parent, frame = frame)
    
    
  def _obterPaineisInternos(self):
    self.__painelDistribuicaoNormal      = PainelCamposGeradorNormal(self)
    self.__painelDistribuicaoTriangular  = PainelCamposGeradorTriangular(self)
    self.__painelDistribuicaoExponencial = PainelCamposGeradorExponencial(self)
    self.__painelDistribuicaoAleatoria = PainelCamposGeradorAleatorio(self)
    
    self.__painelDistribuicaoNormal.Show(False)
    self.__painelDistribuicaoTriangular.Show(False)
    self.__painelDistribuicaoExponencial.Show(False)
    self.__painelDistribuicaoAleatoria.Show(False)
    
    return { self.__distribuicaoNormal : self.__painelDistribuicaoNormal,
             self.__distribuicaoExponencial : self.__painelDistribuicaoExponencial,
             self.__distribuicaoTriangular : self.__painelDistribuicaoTriangular,
             self.__distribuicaoAleatoria : self.__painelDistribuicaoAleatoria
            } 
    
  def _obterOpcoes(self):
    return [self.__distribuicaoNormal, self.__distribuicaoExponencial, self.__distribuicaoTriangular, self.__distribuicaoAleatoria]
  
  def _obterRotulo(self):
    return self._rotulo
