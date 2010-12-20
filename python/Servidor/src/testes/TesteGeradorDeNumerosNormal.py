import unittest
from geradoresDeNumeros.GeradorDeNumerosNormal import GeradorDeNumerosNormal

class TesteGeradorDeNumerosNormal(unittest.TestCase):
  
  def setUp(self):
    self.gerador = GeradorDeNumerosNormal(5, 10)
    
  def testSempreGeraUmNumeroAleatorioBonitoESexy(self): 
    for i in range(1000):
      numero = self.gerador.gerarValorInteiro()
      
      
      
      
#<<<<<EXECUTANDO TESTES>>>>>#  
suite = unittest.TestSuite()
suite.addTest(unittest.makeSuite(TesteGeradorDeNumerosNormal))
unittest.TextTestRunner(verbosity=2).run(suite)