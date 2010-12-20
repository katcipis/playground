import unittest
from grafo.Rede import ArcoComCapacidadeMaxima

class TesteArcoComCapacidadeMaxima(unittest.TestCase):
  
  def setUp(self):
    self.vertice_um = 'A'
    self.vertice_dois = 'B'
    self.vertice_tres = 'C'
    self.vertice_quatro = 'D'

  def testUmArcoEhIgualAOutroArcoSeOsVerticesDosArcosSaoIdenticosEADirecaoEhAMesma(self):
    arco1 = ArcoComCapacidadeMaxima(self.vertice_um, self.vertice_dois)
    arco2 = ArcoComCapacidadeMaxima(self.vertice_um, self.vertice_dois)
    self.assertEquals(arco1, arco2)
    
    
  def testUmArcoEhDiferenteDoOutroSeUmOuMaisVerticesSaoDiferentes(self):
    arco1 = ArcoComCapacidadeMaxima(self.vertice_um, self.vertice_um)
    arco2 = ArcoComCapacidadeMaxima(self.vertice_um, self.vertice_dois)
    self.assertNotEquals(arco1, arco2)
    
    arco1 = ArcoComCapacidadeMaxima(self.vertice_um, self.vertice_dois)
    arco2 = ArcoComCapacidadeMaxima(self.vertice_dois, self.vertice_tres)
    self.assertNotEquals(arco1, arco2)
    
    arco1 = ArcoComCapacidadeMaxima(self.vertice_um, self.vertice_dois)
    arco2 = ArcoComCapacidadeMaxima(self.vertice_tres, self.vertice_quatro)
    self.assertNotEquals(arco1, arco2)
    
  def testUmArcoEhDiferenteDoOutroSeOsVerticesSaoIdenticosMasADirecaoEhDiferente(self):
    arco1 = ArcoComCapacidadeMaxima(self.vertice_um, self.vertice_dois)
    arco2 = ArcoComCapacidadeMaxima(self.vertice_dois, self.vertice_um)
    self.assertNotEquals(arco1, arco2)
    
  def testUmArcoTemHashDiferenteDoOutroSeOsVerticesSaoIdenticosMasADirecaoEhDiferente(self):
    arco1 = ArcoComCapacidadeMaxima(self.vertice_um, self.vertice_dois)
    arco2 = ArcoComCapacidadeMaxima(self.vertice_dois, self.vertice_um)
    self.assertNotEquals(hash(arco1), hash(arco2))
    
  def testOValorDoArcoNaoEhLevadoEmContaNaComparacaoDeDoisArcos(self):
    arco1 = ArcoComCapacidadeMaxima(self.vertice_um, self.vertice_dois, 3)
    arco2 = ArcoComCapacidadeMaxima(self.vertice_um, self.vertice_dois, "bla bla")
    self.assertEquals(arco1, arco2)
    
    arco1 = ArcoComCapacidadeMaxima(self.vertice_um, self.vertice_dois, 5.5)
    arco2 = ArcoComCapacidadeMaxima(self.vertice_um, self.vertice_dois, 5.7)
    self.assertEquals(arco1, arco2)
    
  def testPodeInformarQualSuaCapacidadeMaxima(self):
    arco1 = ArcoComCapacidadeMaxima(self.vertice_um, self.vertice_dois, 3, 8)
    self.assertEquals(8, arco1.ObterCapacidade())
    
  def testPodeInformarSeuValor(self):
    arco1 = ArcoComCapacidadeMaxima(self.vertice_um, self.vertice_dois, 3, 8)
    self.assertEquals(3, arco1.ObterValor())
    
  def testSeForPassadoUmaCapacidadeNegativaAoArcoACapacidadeSeraZero(self):
    arco1 = ArcoComCapacidadeMaxima(self.vertice_um, self.vertice_dois, 3, -5)
    self.assertEquals(0, arco1.ObterCapacidade())
    
  def testSeNaoForInformadaUmaCapacidadeParaOArcoACapacidadeSeraZero(self):
    arco1 = ArcoComCapacidadeMaxima(self.vertice_um, self.vertice_dois, 3)
    self.assertEquals(0, arco1.ObterCapacidade())
    
  def testSeForPassadoUmValorSuperiorACapacidadeOValorSeraIgualACapacidade(self):
    arco1 = ArcoComCapacidadeMaxima(self.vertice_um, self.vertice_dois, 15, 10)
    arco2 = ArcoComCapacidadeMaxima(self.vertice_um, self.vertice_dois, 11, 10)
    self.assertEquals(10, arco1.ObterValor())
    self.assertEquals(10, arco2.ObterValor())
    
  def testSeForPassadoUmValorNegativoAoArcoOValorSeraZero(self):
    arco1 = ArcoComCapacidadeMaxima(self.vertice_um, self.vertice_dois, -3, -5)
    self.assertEquals(0, arco1.ObterValor())
    
    
#<<<<<EXECUTANDO TESTES>>>>>#  
suite = unittest.TestSuite()
suite.addTest(unittest.makeSuite(TesteArcoComCapacidadeMaxima))
unittest.TextTestRunner(verbosity=2).run(suite)