from sistema.GeradorDeChegadasDeEntidades import GeradorDeChegadasDeEntidades
from testes.sistema import TesteBase
from geradoresDeNumeros.GeradorDeNumerosTriangular import GeradorDeNumerosTriangular 

def testeGeradorComFrequenciaDiferenteEmp():
  geradorDeChegadas = GeradorDeChegadasDeEntidades()  
  
  geradorFrequenciaTipoUm = GeradorDeNumerosTriangular(2,5,7)
  geradorFrequenciaTipoDois = GeradorDeNumerosTriangular(5, 10, 15)
  
  geradorDeChegadas.setFrequenciaDiferenteEmpirica(geradorFrequenciaTipoUm, geradorFrequenciaTipoDois)
  TesteBase.testeBaseGeradorDeChegadasEntidades(geradorDeChegadas)
  
testeGeradorComFrequenciaDiferenteEmp()