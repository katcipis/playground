from sistema.Simulador import Simulador
from sistema.GeradorDeChegadasDeEntidades import GeradorDeChegadasDeEntidades
from geradoresDeNumeros.GeradorDeNumerosTriangular import GeradorDeNumerosTriangular
from geradoresDeNumeros.GeradorDeNumerosAleatorios import GeradorDeNumerosAleatorios
from componentes.FilaDoServidor import FilaDoServidor

def __main__():
  geradorDeChegadas = GeradorDeChegadasDeEntidades()
  geradorDeChegadas.setFrequenciaDiferenteDeterministica(12, 15)
  
  geradorDeTempoEntreFalhasServidorUm = GeradorDeNumerosTriangular(50,70, 100)
  geradorDeTempoEntreFalhasServidorDois = GeradorDeNumerosTriangular(60,75, 110)
  
  geradorDeTempoDeFalhaServidorUm = GeradorDeNumerosAleatorios(13)
  geradorDeTempoDeFalhaServidorDois = GeradorDeNumerosAleatorios(18)
  
  geradorDeTempoDeServicoServidorUm = GeradorDeNumerosTriangular(10,12, 15)
  geradorDeTempoDeServicoServidorDois = GeradorDeNumerosTriangular(8,10, 12)
                
  filaDoServidorUm = FilaDoServidor(50)
  filaDoServidorDois = FilaDoServidor()
  
  listaDeLog = []
  
  simulador = Simulador(geradorDeChegadas, 
                    geradorDeTempoEntreFalhasServidorUm,
                    geradorDeTempoEntreFalhasServidorDois,
                    geradorDeTempoDeFalhaServidorUm,
                    geradorDeTempoDeFalhaServidorDois,
                    geradorDeTempoDeServicoServidorUm, 
                    geradorDeTempoDeServicoServidorDois,
                    filaDoServidorUm,
                    filaDoServidorDois,
                    listaDeLog)
  
  simulador.iniciarSimulacao(1000)
  while(simulador.simulaUmPasso()):
    print 'Iniciando passo'
    print '----------------------------------------------'
    while(len(listaDeLog) > 0):
      print listaDeLog.pop(0)
      
    print '----------------------------------------------'
    print 'Terminando passo'
    
  simulador.gerarRelatorioDaSimulacao('TesteSimulacao.txt')
  
__main__()