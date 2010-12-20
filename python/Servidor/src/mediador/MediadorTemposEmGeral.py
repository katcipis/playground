from mediador.abstrato.CriadorDeGeradorDeTempo import CriadorDeGeradorDeTempo 
from gui import gui_rotulos
from sistema.GeradorDeChegadasDeEntidades import GeradorDeChegadasDeEntidades
from geradoresDeNumeros.GeradorDeNumerosFixo import GeradorDeNumerosFixo

class MediadorTemposEmGeral(CriadorDeGeradorDeTempo):
  
  def __init__(self, painelTempoEntreChegadas):
    CriadorDeGeradorDeTempo.__init__(self, painelTempoEntreChegadas)
    
  def _criarGeradorDeTempoIgual(self):
    valores = self._painelTempoEntreChegadas.obterValoresNosCamposAtuais()
    tempo = int(valores[gui_rotulos.TEMPO])
    
    geradorUm = GeradorDeNumerosFixo(tempo)
    geradorDois = GeradorDeNumerosFixo(tempo)
    return geradorUm, geradorDois
  
    
  def _criarGeradorDeTempoDiferenteDeterministico(self):
    valores = self._painelTempoEntreChegadas.obterValoresNosCamposAtuais()
    tempoUm = int(valores[gui_rotulos.TEMPO_UM])
    tempoDois = int(valores[gui_rotulos.TEMPO_DOIS])
    
    geradorUm = GeradorDeNumerosFixo(tempoUm)
    geradorDois = GeradorDeNumerosFixo(tempoDois)
    return geradorUm, geradorDois
  
  def _criarGeradorDeTempoDiferenteAleatorio(self):
    painelUm =   self._painelTempoEntreChegadas.obterPainelDeEscolhaDeTempoAleatorio().obterPainelUm()
    painelDois = self._painelTempoEntreChegadas.obterPainelDeEscolhaDeTempoAleatorio().obterPainelDois()
    
    escolhaUm =   painelUm.obterEscolhaSelecionada()
    escolhaDois = painelDois.obterEscolhaSelecionada()
    
    geradorUm = self._funcoesCriadorasDeGeradores[escolhaUm](painelUm)
    geradorDois = self._funcoesCriadorasDeGeradores[escolhaDois](painelDois)
    
    return geradorUm, geradorDois