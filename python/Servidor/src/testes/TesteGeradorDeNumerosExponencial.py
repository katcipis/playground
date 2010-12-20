import unittest
from geradoresDeNumeros.GeradorDeNumerosExponencial import GeradorDeNumerosExponencial

class TesteGeradorDeNumerosExponencial(unittest.TestCase):
  
  def setUp(self):
    self.gerador = GeradorDeNumerosExponencial(10)
    
  def testSempreGeraUmNumeroAleatorioBonitoESexy(self): 
    for i in range(1000):
      self.gerador.gerarValorInteiro()

      
      
#<<<<<EXECUTANDO TESTES>>>>>#  
suite = unittest.TestSuite()
suite.addTest(unittest.makeSuite(TesteGeradorDeNumerosExponencial))
unittest.TextTestRunner(verbosity=2).run(suite)