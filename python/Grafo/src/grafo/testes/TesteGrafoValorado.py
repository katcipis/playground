import unittest
from grafo.testes.TesteGrafo import TesteGrafo
from grafo.GrafoValorado import GrafoValorado

class TesteGrafoValorado(TesteGrafo):
  """Teste da classe GrafoValorado"""
  
  def setUp(self):
    self.vertice_um = 'A'
    self.vertice_dois = 'B'
    self.vertice_tres = 'C'
    self.grafo = GrafoValorado()
    
  def testPodeInformarOGrauDeUmVertice(self):
    self.grafo.AdcionaVertice(self.vertice_um)
    self.assertEquals(self.grafo.Grau(self.vertice_um), 0)
    
    self.grafo.AdcionaVertice(self.vertice_dois)
    self.assertEquals(self.grafo.Grau(self.vertice_um), 0)
    self.assertEquals(self.grafo.Grau(self.vertice_dois), 0)
    
    self.grafo.Conecta(self.vertice_dois, self.vertice_um, 1)
    
    self.assertEquals(self.grafo.Grau(self.vertice_um), 1)
    self.assertEquals(self.grafo.Grau(self.vertice_dois), 1)
    
  def testSeOVerticeEhConectadoAEleMentoSeuGrauEhUm(self):
    self.grafo.AdcionaVertice(self.vertice_um)
    self.assertEquals(self.grafo.Grau(self.vertice_um), 0)
    
    self.grafo.Conecta(self.vertice_um, self.vertice_um, 1)
    
    self.assertEquals(self.grafo.Grau(self.vertice_um), 1) 
    
    
  def testSeTentarObterOValorDeUmaConexaoQueNaoExisteRetornaNone(self):
    self.assertEquals(self.grafo.ValorDaConexao(self.vertice_um, self.vertice_dois), None)
    
    self.grafo.AdcionaVertice(self.vertice_um)
    self.grafo.AdcionaVertice(self.vertice_dois)
    
    self.assertEquals(self.grafo.ValorDaConexao(self.vertice_um, self.vertice_dois), None)
    
  def testPodeRetornarOValorDeUmaConexao(self):
    self.grafo.AdcionaVertice(self.vertice_um)
    self.grafo.AdcionaVertice(self.vertice_dois)
    self.grafo.AdcionaVertice(self.vertice_tres)
    
    self.grafo.Conecta(self.vertice_um, self.vertice_dois, 3)
    self.grafo.Conecta(self.vertice_um, self.vertice_tres, 5)
    self.grafo.Conecta(self.vertice_dois, self.vertice_tres, 6.7)
    
    self.assertEquals(self.grafo.ValorDaConexao(self.vertice_um, self.vertice_dois), 3)
    self.assertEquals(self.grafo.ValorDaConexao(self.vertice_um, self.vertice_tres), 5)
    self.assertEquals(self.grafo.ValorDaConexao(self.vertice_dois, self.vertice_tres), 6.7)
    
  def testAdjacenciaEhSimetrica(self):
    self.grafo.AdcionaVertice(self.vertice_um)
    self.grafo.AdcionaVertice(self.vertice_dois)
    self.grafo.Conecta(self.vertice_um, self.vertice_dois, 2)
    
    adjacentes = self.grafo.Adjacentes(self.vertice_um)
    
    self.assertEquals(len(adjacentes), 1)
    self.assertTrue(self.vertice_dois in adjacentes)
    
    adjacentes = self.grafo.Adjacentes(self.vertice_dois)
    self.assertEquals(len(adjacentes), 1)
    self.assertTrue(self.vertice_um in adjacentes)
    
  def testEhPossivelConectarUmVerticeAEleMesmo(self):
    self.grafo.AdcionaVertice(self.vertice_um)
    
    adjacentes = self.grafo.Adjacentes(self.vertice_um)
    self.assertEquals(len(adjacentes), 0)
    self.assertFalse(self.grafo.EstaoConectados(self.vertice_um, self.vertice_um))
    
    self.grafo.Conecta(self.vertice_um, self.vertice_um, 2)
    
    self.assertTrue(self.grafo.EstaoConectados(self.vertice_um, self.vertice_um))
    adjacentes = self.grafo.Adjacentes(self.vertice_um)
    
    self.assertEquals(len(adjacentes), 1)
    self.assertTrue(self.vertice_um in adjacentes)
    
  def testPodeRetornarTodosOsVerticesAdjacentesAUmDadoVertice(self):
    self.grafo.AdcionaVertice(self.vertice_um)
    self.grafo.AdcionaVertice(self.vertice_dois)
    self.grafo.AdcionaVertice(self.vertice_tres)
    self.grafo.Conecta(self.vertice_um, self.vertice_dois,2)
    
    adjacentes = self.grafo.Adjacentes(self.vertice_um)
    
    self.assertEquals(len(adjacentes), 1)
    self.assertTrue(self.vertice_dois in adjacentes)
    
    self.grafo.Conecta(self.vertice_um, self.vertice_tres,2)
    
    adjacentes = self.grafo.Adjacentes(self.vertice_um)
    self.assertEquals(len(adjacentes), 2)
    self.assertTrue(self.vertice_dois in adjacentes)
    self.assertTrue(self.vertice_tres in adjacentes)
    
  def testSabeSeDoisVerticesEstaoConectados(self):
    self.grafo.AdcionaVertice(self.vertice_um)
    self.grafo.AdcionaVertice(self.vertice_dois)
    
    self.assertFalse(self.grafo.EstaoConectados(self.vertice_um, self.vertice_dois))
    self.grafo.Conecta(self.vertice_um, self.vertice_dois, 2)
    self.assertTrue(self.grafo.EstaoConectados(self.vertice_um, self.vertice_dois))
    
  def testSeOsVerticesNaoEstaoNoGrafoNaoEhPossivelConectalos(self):
    self.grafo.Conecta(self.vertice_um, self.vertice_dois, 2)
    self.assertFalse(self.grafo.EstaoConectados(self.vertice_um, self.vertice_dois))
    
  def testSeUmDosVerticesNaoEstaoNoGrafoNaoEhPossivelConectalos(self):
    self.grafo.AdcionaVertice(self.vertice_um)
    self.grafo.Conecta(self.vertice_um, self.vertice_dois, 2)
    self.assertFalse(self.grafo.EstaoConectados(self.vertice_um, self.vertice_dois))
    
  def testSeDoisVerticesSaoDesconectadosElesNaoEstaoMaisConectados(self):
    self.grafo.AdcionaVertice(self.vertice_um)
    self.grafo.AdcionaVertice(self.vertice_dois)
    
    self.grafo.Conecta(self.vertice_um, self.vertice_dois, 2)
    self.assertTrue(self.grafo.EstaoConectados(self.vertice_um, self.vertice_dois))
    
    self.grafo.Desconecta(self.vertice_um, self.vertice_dois)
    self.assertFalse(self.grafo.EstaoConectados(self.vertice_um, self.vertice_dois))
    
    
    
#<<<<<EXECUTANDO TESTES>>>>>#    
suite = unittest.TestSuite()
suite.addTest(unittest.makeSuite(TesteGrafoValorado))
unittest.TextTestRunner(verbosity=2).run(suite)

    