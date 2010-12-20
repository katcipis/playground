from sistema.GeradorDeChegadasDeEntidades import GeradorDeChegadasDeEntidades
from testes.sistema import TesteBase

def testeGeradorComFrequenciaDiferenteDet():
  geradorDeChegadas = GeradorDeChegadasDeEntidades()  
  geradorDeChegadas.setFrequenciaDiferenteDeterministica(3, 5)
  TesteBase.testeBaseGeradorDeChegadasEntidades(geradorDeChegadas)
  
testeGeradorComFrequenciaDiferenteDet()