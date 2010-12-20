from componentes.Entidade import Entidade
from componentes.Evento import Evento
from componentes.ListaDeEventosFuturos import ListaDeEventosFuturos
from enum import TipoDoEvento
from enum import TipoDaEntidade
from sistema import EstadoGeradorDeEntidades
from geradoresDeNumeros.GeradorDeNumerosAleatorios import GeradorDeNumerosAleatorios

class GeradorDeChegadasDeEntidades():
  
  def __init__(self):
    self.__probabilidadeEntidade1 = 0.5
    self.__geradorAleatorio = GeradorDeNumerosAleatorios()
    self.__frequencia = 0
    
    self.__frequenciaTipoUm = 0
    self.__frequenciaTipoDois = 0
    
    self.__geradorFrequenciaTipoUm = None
    self.__geradorFrequenciaTipoDois = None
    self.__estado = None
    self.__contadorDeEntidades = 0
    
    self.__funcoesGeradoras = {
                               EstadoGeradorDeEntidades.MESMA_FREQUENCIA : self.__gerarComMesmaFrequencia,
                               EstadoGeradorDeEntidades.FREQUENCIA_DIFERENTE_DET : self.__gerarComFrequenciaDiferenteDeterministica,
                               EstadoGeradorDeEntidades.FREQUENCIA_DIFERENTE_EMP : self.__gerarComFrequenciaDiferenteEmpirica
                               }
    
  def setMesmaFrequencia(self, probTipoUm, frequencia):
    self.__probabilidadeEntidade1 = probTipoUm
    self.__frequencia = frequencia
    self.__estado = EstadoGeradorDeEntidades.MESMA_FREQUENCIA
    
  def setFrequenciaDiferenteDeterministica(self, frequenciaTipoUm, frequenciaTipoDois):
    self.__frequenciaTipoUm = frequenciaTipoUm
    self.__frequenciaTipoDois = frequenciaTipoDois
    self.__estado = EstadoGeradorDeEntidades.FREQUENCIA_DIFERENTE_DET
    
  def setFrequenciaDiferenteEmpirica(self, geradorFrequenciaTipoUm, geradorFrequenciaTipoDois):
    self.__geradorFrequenciaTipoUm = geradorFrequenciaTipoUm
    self.__geradorFrequenciaTipoDois = geradorFrequenciaTipoDois
    self.__estado = EstadoGeradorDeEntidades.FREQUENCIA_DIFERENTE_EMP
    
  def obterListaDeChegadasDasEntidades(self, limiteTempo = 100, offsetRelogio = 0):
    if(self.__estado == None):
      return ListaDeEventosFuturos()
    
    return self.__funcoesGeradoras[self.__estado](limiteTempo, offsetRelogio)
    
  def __gerarComMesmaFrequencia(self, limiteTempo, offsetRelogio):
    tempoTotal = 0
    listaDeEventos = ListaDeEventosFuturos()
    
    while((tempoTotal + self.__frequencia) <= limiteTempo):
      tempoTotal += self.__frequencia
      self.__contadorDeEntidades += 1
      
      aleatorio = self.__geradorAleatorio.gerarValorFloat()
      tipoEntidade = TipoDaEntidade.TIPO_DOIS
      
      if(aleatorio <= self.__probabilidadeEntidade1):
        tipoEntidade = TipoDaEntidade.TIPO_UM
        
      listaDeEventos.adcionarEvento(Evento(TipoDoEvento.ENTRADA, 
                                           tempoTotal + offsetRelogio, 
                                           Entidade(tipoEntidade, 'Entidade ' + str(self.__contadorDeEntidades))))
        
      
    return listaDeEventos
    
  def __gerarComFrequenciaDiferenteDeterministica(self, limiteTempo, offsetRelogio):
    tempoTotal = 0
    listaDeEventos = ListaDeEventosFuturos()
    incrementoDeTempo = self.__frequenciaTipoUm
    
    if(self.__frequenciaTipoUm < self.__frequenciaTipoDois):
      incrementoDeTempo = self.__frequenciaTipoDois
    
    while((tempoTotal + incrementoDeTempo) <= limiteTempo):
      
      self.__adcionarDoisEventosALista(listaDeEventos, tempoTotal, offsetRelogio, 
                                       self.__frequenciaTipoUm, self.__frequenciaTipoDois)
      tempoTotal += incrementoDeTempo
      
    return listaDeEventos
    
  def __gerarComFrequenciaDiferenteEmpirica(self, limiteTempo, offsetRelogio):
    tempoTotal = 0
    listaDeEventos = ListaDeEventosFuturos()

    incrementoDeTempo = 0 
    frequenciaTipoUm = 0 
    frequenciaTipoDois = 0

    incrementoDeTempo, frequenciaTipoUm, frequenciaTipoDois = self.__determinarFrequencias(incrementoDeTempo, frequenciaTipoUm, frequenciaTipoDois)
    
    while((tempoTotal + incrementoDeTempo) <= limiteTempo):
      
      self.__adcionarDoisEventosALista(listaDeEventos, tempoTotal, offsetRelogio, frequenciaTipoUm, frequenciaTipoDois)
      
      tempoTotal += incrementoDeTempo
      incrementoDeTempo, frequenciaTipoUm, frequenciaTipoDois = self.__determinarFrequencias(incrementoDeTempo, frequenciaTipoUm, frequenciaTipoDois)
    
    return listaDeEventos
  
  def __determinarFrequencias(self, incrementoDeTempo, frequenciaTipoUm, frequenciaTipoDois):
    
    frequenciaTipoUm   = self.__geradorFrequenciaTipoUm.gerarValorInteiro()
    frequenciaTipoDois = self.__geradorFrequenciaTipoDois.gerarValorInteiro()
    incrementoDeTempo = frequenciaTipoUm
      
    if(frequenciaTipoUm < frequenciaTipoDois):
      incrementoDeTempo = frequenciaTipoDois
      
    return incrementoDeTempo, frequenciaTipoUm, frequenciaTipoDois
      
  def __adcionarDoisEventosALista(self, listaDeEventos, tempoTotal , offsetRelogio , frequenciaTipoUm, frequenciaTipoDois):
    
    self.__contadorDeEntidades += 1  
    listaDeEventos.adcionarEvento(Evento(TipoDoEvento.ENTRADA, 
                                         tempoTotal + offsetRelogio + frequenciaTipoUm, 
                                         Entidade(TipoDaEntidade.TIPO_UM, 'Entidade ' + str(self.__contadorDeEntidades))))
      
    self.__contadorDeEntidades += 1
    listaDeEventos.adcionarEvento(Evento(TipoDoEvento.ENTRADA, 
                                         tempoTotal + offsetRelogio + frequenciaTipoDois, 
                                         Entidade(TipoDaEntidade.TIPO_DOIS, 'Entidade ' + str(self.__contadorDeEntidades))))