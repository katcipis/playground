from mediador.abstrato.CriadorDeGeradorDeTempo import CriadorDeGeradorDeTempo 
from gui import gui_rotulos
from sistema.GeradorDeChegadasDeEntidades import GeradorDeChegadasDeEntidades

class MediadorTempoEntreChegadas(CriadorDeGeradorDeTempo):
  
  def __init__(self, painelTempoEntreChegadas):
    CriadorDeGeradorDeTempo.__init__(self, painelTempoEntreChegadas)
    
  def _criarGeradorDeTempoIgual(self):
    valores = self._painelTempoEntreChegadas.obterValoresNosCamposAtuais()
    frequencia = int(valores[gui_rotulos.FREQUENCIA])
    probabilidadeUm = float(valores[gui_rotulos.PROBABILIDADE_UM])
    
    gerador = GeradorDeChegadasDeEntidades()
    gerador.setMesmaFrequencia(probabilidadeUm,  frequencia)
    return gerador
  
    
  def _criarGeradorDeTempoDiferenteDeterministico(self):
    valores = self._painelTempoEntreChegadas.obterValoresNosCamposAtuais()
    frequenciaUm   = int(valores[gui_rotulos.FREQUENCIA_UM])
    frequenciaDois = int(valores[gui_rotulos.FREQUENCIA_DOIS])
    
    gerador = GeradorDeChegadasDeEntidades()
    gerador.setFrequenciaDiferenteDeterministica(frequenciaUm, frequenciaDois)
    return gerador
  
  def _criarGeradorDeTempoDiferenteAleatorio(self):
    
    painelUm =   self._painelTempoEntreChegadas.obterPainelDeEscolhaDeTempoAleatorio().obterPainelUm()
    painelDois = self._painelTempoEntreChegadas.obterPainelDeEscolhaDeTempoAleatorio().obterPainelDois()
    
    escolhaUm =   painelUm.obterEscolhaSelecionada()
    escolhaDois = painelDois.obterEscolhaSelecionada()
    
    geradorUm = self._funcoesCriadorasDeGeradores[escolhaUm](painelUm)
    geradorDois = self._funcoesCriadorasDeGeradores[escolhaDois](painelDois)
    gerador = GeradorDeChegadasDeEntidades()
    gerador.setFrequenciaDiferenteEmpirica(geradorUm, geradorDois)
    return gerador