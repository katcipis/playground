import unittest
from grafo.Grafo import Aresta

class TesteAresta(unittest.TestCase):
  
  def setUp(self):
    self.vertice_um = 'A'
    self.vertice_dois = 'B'
    self.vertice_tres = 'C'
    self.vertice_quatro = 'D'

  def testUmaArestaEhIgualAOutraArestaSeOsVerticesDasArestasSaoIdenticos(self):
    aresta1 = Aresta(self.vertice_um, self.vertice_dois)
    aresta2 = Aresta(self.vertice_um, self.vertice_dois)
    self.assertEquals(aresta1, aresta2)
    
    aresta1 = Aresta(self.vertice_um, self.vertice_dois)
    aresta2 = Aresta(self.vertice_dois, self.vertice_um)
    self.assertEquals(aresta1, aresta2)
    
  def testUmaArestaEhDiferenteDaOutraSeUmOuMaisVerticesSaoDiferentes(self):
    aresta1 = Aresta(self.vertice_um, self.vertice_um)
    aresta2 = Aresta(self.vertice_um, self.vertice_dois)
    self.assertNotEquals(aresta1, aresta2)
    
    aresta1 = Aresta(self.vertice_um, self.vertice_dois)
    aresta2 = Aresta(self.vertice_dois, self.vertice_tres)
    self.assertNotEquals(aresta1, aresta2)
    
    aresta1 = Aresta(self.vertice_um, self.vertice_dois)
    aresta2 = Aresta(self.vertice_tres, self.vertice_quatro)
    self.assertNotEquals(aresta1, aresta2)
    
  def testOValorDaArestaNaoEhLevadoEmContaNaComparacaoDeDuasArestas(self):
    aresta1 = Aresta(self.vertice_um, self.vertice_dois, 3)
    aresta2 = Aresta(self.vertice_um, self.vertice_dois, "bla bla")
    self.assertEquals(aresta1, aresta2)
    
    aresta1 = Aresta(self.vertice_um, self.vertice_dois, 5.5)
    aresta2 = Aresta(self.vertice_dois, self.vertice_um, 5.7)
    self.assertEquals(aresta1, aresta2)
    
    
    
    
#<<<<<EXECUTANDO TESTES>>>>>#  
suite = unittest.TestSuite()
suite.addTest(unittest.makeSuite(TesteAresta))
unittest.TextTestRunner(verbosity=2).run(suite)