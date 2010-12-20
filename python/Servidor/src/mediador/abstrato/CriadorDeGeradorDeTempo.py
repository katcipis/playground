from gui.PainelTempoEntreChegadas import PainelTempoEntreChegadas
from sistema.GeradorDeChegadasDeEntidades import GeradorDeChegadasDeEntidades
from geradoresDeNumeros.GeradorDeNumerosAleatorios import GeradorDeNumerosAleatorios
from geradoresDeNumeros.GeradorDeNumerosExponencial import GeradorDeNumerosExponencial
from geradoresDeNumeros.GeradorDeNumerosNormal import GeradorDeNumerosNormal
from geradoresDeNumeros.GeradorDeNumerosTriangular import GeradorDeNumerosTriangular 
from gui import gui_rotulos

class CriadorDeGeradorDeTempo():
  
  def __init__(self, painelTempoEntreChegadas):
    self._painelTempoEntreChegadas = painelTempoEntreChegadas
    self._funcoesCriadorasDeGeradores = {
                                          gui_rotulos.IGUAL                    : self._criarGeradorDeTempoIgual,
                                          gui_rotulos.DIFERENTE_ALEATORIA      : self._criarGeradorDeTempoDiferenteAleatorio,
                                          gui_rotulos.DIFERENTE_DETERMINISTICA : self._criarGeradorDeTempoDiferenteDeterministico,
                                          
                                          gui_rotulos.NORMAL : self._criarGeradorDeTempoNormal,
                                          gui_rotulos.EXPONENCIAL : self._criarGeradorDeTempoExponencial,
                                          gui_rotulos.TRIANGULAR : self._criarGeradorDeTempoTriangular,
                                          gui_rotulos.ALEATORIA : self._criarGeradorDeTempoAleatorio
                                          }
    
  def obterGeradorDeTempo(self):
    escolhaAtual = self._painelTempoEntreChegadas.obterEscolhaSelecionada()
    
    if(self._funcoesCriadorasDeGeradores.has_key(escolhaAtual)):
      return self._funcoesCriadorasDeGeradores[escolhaAtual]()
    
  def _criarGeradorDeTempoIgual(self):
    """ ABSTRATO """
    
  def _criarGeradorDeTempoDiferenteDeterministico(self):
    """ ABSTRATO """
    
  def _criarGeradorDeTempoDiferenteAleatorio(self):
   """ ABSTRATO """
    
  def _criarGeradorDeTempoNormal(self, painel):
    valores = painel.obterValoresNosCamposAtuais()
    semente = int(valores[gui_rotulos.SEMENTE])
    media = int(valores[gui_rotulos.MEDIA])
    desvioPadrao = int(valores[gui_rotulos.DESVIO_PADRAO])
    
    return GeradorDeNumerosNormal(media = media, desvioPadrao = desvioPadrao, semente = semente)
    
  def _criarGeradorDeTempoExponencial(self, painel):
    valores = painel.obterValoresNosCamposAtuais()
    semente = int(valores[gui_rotulos.SEMENTE])
    media = int(valores[gui_rotulos.MEDIA])

    return GeradorDeNumerosExponencial(media = media, semente = semente)
  
  def _criarGeradorDeTempoTriangular(self, painel):
    valores = painel.obterValoresNosCamposAtuais()
    semente = int(valores[gui_rotulos.SEMENTE])
    media = int(valores[gui_rotulos.MEDIA])
    minimo = int(valores[gui_rotulos.MINIMO])
    maximo = int(valores[gui_rotulos.MAXIMO])
    
    return GeradorDeNumerosTriangular(min = minimo, 
                                      media = media, 
                                      maximo = maximo, 
                                      semente = semente)
    
  def _criarGeradorDeTempoAleatorio(self, painel):
    valores = painel.obterValoresNosCamposAtuais()
    semente = int(valores[gui_rotulos.SEMENTE])
    maximo = int(valores[gui_rotulos.MAXIMO])

    return GeradorDeNumerosAleatorios(maximo = maximo, semente = semente)