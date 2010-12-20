import unittest
from grafo.Digrafo import Arco

class TesteArco(unittest.TestCase):
  
  def setUp(self):
    self.vertice_um = 'A'
    self.vertice_dois = 'B'
    self.vertice_tres = 'C'
    self.vertice_quatro = 'D'

  def testUmArcoEhIgualAOutroArcoSeOsVerticesDosArcosSaoIdenticosEADirecaoEhAMesma(self):
    arco1 = Arco(self.vertice_um, self.vertice_dois)
    arco2 = Arco(self.vertice_um, self.vertice_dois)
    self.assertEquals(arco1, arco2)
    
    
  def testUmArcoEhDiferenteDoOutroSeUmOuMaisVerticesSaoDiferentes(self):
    arco1 = Arco(self.vertice_um, self.vertice_um)
    arco2 = Arco(self.vertice_um, self.vertice_dois)
    self.assertNotEquals(arco1, arco2)
    
    arco1 = Arco(self.vertice_um, self.vertice_dois)
    arco2 = Arco(self.vertice_dois, self.vertice_tres)
    self.assertNotEquals(arco1, arco2)
    
    arco1 = Arco(self.vertice_um, self.vertice_dois)
    arco2 = Arco(self.vertice_tres, self.vertice_quatro)
    self.assertNotEquals(arco1, arco2)
    
  def testUmArcoEhDiferenteDoOutroSeOsVerticesSaoIdenticosMasADirecaoEhDiferente(self):
    arco1 = Arco(self.vertice_um, self.vertice_dois)
    arco2 = Arco(self.vertice_dois, self.vertice_um)
    self.assertNotEquals(arco1, arco2)
    
  def testUmArcoTemHashDiferenteDoOutroSeOsVerticesSaoIdenticosMasADirecaoEhDiferente(self):
    arco1 = Arco(self.vertice_um, self.vertice_dois)
    arco2 = Arco(self.vertice_dois, self.vertice_um)
    self.assertNotEquals(hash(arco1), hash(arco2))
    
  def testOValorDoArcoNaoEhLevadoEmContaNaComparacaoDeDoisArcos(self):
    arco1 = Arco(self.vertice_um, self.vertice_dois, 3)
    arco2 = Arco(self.vertice_um, self.vertice_dois, "bla bla")
    self.assertEquals(arco1, arco2)
    
    arco1 = Arco(self.vertice_um, self.vertice_dois, 5.5)
    arco2 = Arco(self.vertice_um, self.vertice_dois, 5.7)
    self.assertEquals(arco1, arco2)
    
  def testSeNaoForInformadoOValorOValorSeraNulo(self):
    arco1 = Arco(self.vertice_um, self.vertice_dois)
    self.assertEquals(None, arco1.ObterValor())
    
    
    
#<<<<<EXECUTANDO TESTES>>>>>#  
suite = unittest.TestSuite()
suite.addTest(unittest.makeSuite(TesteArco))
unittest.TextTestRunner(verbosity=2).run(suite)