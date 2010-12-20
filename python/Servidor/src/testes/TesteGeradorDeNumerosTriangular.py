import unittest
from geradoresDeNumeros.GeradorDeNumerosTriangular import GeradorDeNumerosTriangular

class TesteGeradorDeNumerosTriangular(unittest.TestCase):
  
  def setUp(self):
    self.min = 1.0
    self.max = 9.5
    self.media = 6.0
    self.gerador = GeradorDeNumerosTriangular(self.min, self.media, self.max)
    
  def testSempreGeraUmNumeroAleatorioEntreOMinimoEOMaximo(self): 
    for i in range(1000):
      numero = self.gerador.gerarValorInteiro()
      self.assertTrue(numero <= self.max)
      self.assertTrue(numero >= self.min)
      
  def testNaoRepeteOValorEmPeloMenosMilIteracoesSeForFloat(self):
    antigo = self.gerador.gerarValorFloat()
    for i in range(1000):
      numero = self.gerador.gerarValorFloat()
      self.assertNotEqual(numero, antigo)
      antigo = numero
      
      
#<<<<<EXECUTANDO TESTES>>>>>#  
suite = unittest.TestSuite()
suite.addTest(unittest.makeSuite(TesteGeradorDeNumerosTriangular))
unittest.TextTestRunner(verbosity=2).run(suite)