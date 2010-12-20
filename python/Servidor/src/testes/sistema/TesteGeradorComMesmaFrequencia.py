from sistema.GeradorDeChegadasDeEntidades import GeradorDeChegadasDeEntidades
from testes.sistema import TesteBase

def testeGeradorComMesmaFrequencia():
  geradorDeChegadas = GeradorDeChegadasDeEntidades()  
  geradorDeChegadas.setMesmaFrequencia(0.3, 3)
  TesteBase.testeBaseGeradorDeChegadasEntidades(geradorDeChegadas)
  
testeGeradorComMesmaFrequencia()