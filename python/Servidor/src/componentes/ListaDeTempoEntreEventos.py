import copy

class ListaDeTempoEntreEventos():
  
  def __init__(self):
    self.__tempoDeOcorrencias = []
    self.__temposEntreEventos = []
    
  def __calcularTemposEntreEventos(self):
    if(len(self.__tempoDeOcorrencias) >= 2):
      self.__temposEntreEventos.append(self.__tempoDeOcorrencias[1] - 
                                       self.__tempoDeOcorrencias[0])
      self.__tempoDeOcorrencias.pop(0)
      self.__calcularTemposEntreEventos()
      
  def adcionarTempoDeOcorrencia(self, tempo):
    self.__tempoDeOcorrencias.append(tempo)
    
  def obterTemposEntreEventos(self):
    self.__calcularTemposEntreEventos()
    return copy.copy(self.__temposEntreEventos)