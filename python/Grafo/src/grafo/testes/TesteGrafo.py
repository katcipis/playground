import unittest
from grafo.Grafo import Grafo

class TesteGrafo(unittest.TestCase):
  """Teste da classe Grafo"""
  
  def setUp(self):
    self.vertice_um = 'A'
    self.vertice_dois = 'B'
    self.vertice_tres = 'C'
    self.grafo = Grafo()
    
  def testSeUmVerticeNaoFoiAdcionadoEleNaoExisteNoGrafo(self):
    self.assertFalse(self.grafo.PossuiVertice(self.vertice_um))
    self.assertFalse(self.grafo.PossuiVertice(self.vertice_dois))
    self.assertFalse(self.grafo.PossuiVertices([self.vertice_um, self.vertice_dois]))
    
  def testSeUmVerticeFoiAdcionadoEleExisteNoGrafo(self):
    self.grafo.AdcionaVertice(self.vertice_um)
    
    self.assertTrue(self.grafo.PossuiVertice(self.vertice_um))
    self.assertFalse(self.grafo.PossuiVertice(self.vertice_dois))
    
    self.grafo.AdcionaVertice(self.vertice_dois)
    
    self.assertTrue(self.grafo.PossuiVertice(self.vertice_dois))
    self.assertTrue(self.grafo.PossuiVertices([self.vertice_um, self.vertice_dois]))
    
  def testSeUmVerticeFoiAdcionadoEOutroNaoOOutroNaoEstaNoGrafo(self):
    self.grafo.AdcionaVertice(self.vertice_um)
    
    self.assertTrue(self.grafo.PossuiVertice(self.vertice_um))
    self.assertFalse(self.grafo.PossuiVertice(self.vertice_dois))
    self.assertFalse(self.grafo.PossuiVertices([self.vertice_um, self.vertice_dois]))
    
  def testSeUmVerticeForInseridoDuasVezesExistiraApenasUmaOcorrenciaDeleNoGrafo(self):
    self.grafo.AdcionaVertice(self.vertice_um)
    self.grafo.AdcionaVertice(self.vertice_um)

    self.assertTrue(self.grafo.PossuiVertice(self.vertice_um))
    self.assertEquals(self.grafo.Ordem(), 1)
    
    self.grafo.AdcionaVertice(self.vertice_dois)
    self.grafo.AdcionaVertice(self.vertice_dois)
    
    self.assertTrue(self.grafo.PossuiVertice(self.vertice_dois))
    self.assertEquals(self.grafo.Ordem(), 2)
   
  def testSeUmVerticeQueNaoExisteNoGrafoForRemovidoNadaAcontece(self):
    self.grafo.RemoveVertice(self.vertice_um)
    
  def testSeUmVerticeForRemovidoEleNaoSeEncontraMaisNoGrafo(self):
    self.grafo.AdcionaVertice(self.vertice_um)
    self.assertTrue(self.grafo.PossuiVertice(self.vertice_um))
    
    self.grafo.RemoveVertice(self.vertice_um)
    self.assertFalse(self.grafo.PossuiVertice(self.vertice_um))
    
  def testSabeSeDoisVerticesEstaoConectados(self):
    self.grafo.AdcionaVertice(self.vertice_um)
    self.grafo.AdcionaVertice(self.vertice_dois)
    
    self.assertFalse(self.grafo.EstaoConectados(self.vertice_um, self.vertice_dois))
    self.grafo.Conecta(self.vertice_um, self.vertice_dois)
    self.assertTrue(self.grafo.EstaoConectados(self.vertice_um, self.vertice_dois))
    
  def testSabeSeDoisVerticesNaoEstaoConectados(self):
    self.grafo.AdcionaVertice(self.vertice_um)
    self.grafo.AdcionaVertice(self.vertice_dois)
    
    self.assertFalse(self.grafo.EstaoConectados(self.vertice_um, self.vertice_dois))
    
  def testSeOsVerticesNaoEstaoNoGrafoNaoEhPossivelConectalos(self):
    self.grafo.Conecta(self.vertice_um, self.vertice_dois)
    self.assertFalse(self.grafo.EstaoConectados(self.vertice_um, self.vertice_dois))
    
  def testSeUmDosVerticesNaoEstaoNoGrafoNaoEhPossivelConectalos(self):
    self.grafo.AdcionaVertice(self.vertice_um)
    self.grafo.Conecta(self.vertice_um, self.vertice_dois)
    self.assertFalse(self.grafo.EstaoConectados(self.vertice_um, self.vertice_dois))
    
  def testSeDoisVerticesSaoDesconectadosElesNaoEstaoMaisConectados(self):
    self.grafo.AdcionaVertice(self.vertice_um)
    self.grafo.AdcionaVertice(self.vertice_dois)
    
    self.grafo.Conecta(self.vertice_um, self.vertice_dois)
    self.assertTrue(self.grafo.EstaoConectados(self.vertice_um, self.vertice_dois))
    
    self.grafo.Desconecta(self.vertice_um, self.vertice_dois)
    self.assertFalse(self.grafo.EstaoConectados(self.vertice_um, self.vertice_dois))
    
  def testSeDoisVerticesDesconectadosForemDesconectadosNadaOcorre(self):
    self.grafo.AdcionaVertice(self.vertice_um)
    self.grafo.AdcionaVertice(self.vertice_dois)
    
    self.grafo.Desconecta(self.vertice_um, self.vertice_dois)
    self.assertFalse(self.grafo.EstaoConectados(self.vertice_um, self.vertice_dois))
    
  def testSeDoisVerticesNaoExistemNoGrafoESaoDesconectadosNadaOcorre(self):
    self.grafo.Desconecta(self.vertice_um, self.vertice_dois)
    self.assertFalse(self.grafo.EstaoConectados(self.vertice_um, self.vertice_dois))
    
  def testSabeSePossuiUmVertice(self):
    self.grafo.AdcionaVertice(self.vertice_um)
    self.assertTrue(self.grafo.PossuiVertice(self.vertice_um))
    
  def testSabeSeNaoPossuiUmVertice(self):
    self.grafo.AdcionaVertice(self.vertice_um)
    self.assertFalse(self.grafo.PossuiVertice(self.vertice_dois))
    
  def testSabeSePossuiUmConjuntoDeVertices(self):
    self.grafo.AdcionaVertice(self.vertice_um)
    self.grafo.AdcionaVertice(self.vertice_dois)
    self.assertTrue(self.grafo.PossuiVertices([self.vertice_um,self.vertice_dois] ))
    
  def testSabeSeNaoPossuiUmConjuntoDeVertices(self):
    self.grafo.AdcionaVertice(self.vertice_um)
    self.assertFalse(self.grafo.PossuiVertices([self.vertice_um,self.vertice_dois] ))
    
  def testSabeSeEstaVazio(self):
    self.assertTrue(self.grafo.EstaVazio())
    
  def testSabeSeNaoEstaVazio(self):
    self.grafo.AdcionaVertice(self.vertice_um)
    self.assertFalse(self.grafo.EstaVazio())
    
  def testSabeSuaOrdem(self):
    self.assertEquals(self.grafo.Ordem(), 0)
    self.grafo.AdcionaVertice(self.vertice_um)
    self.assertEquals(self.grafo.Ordem(), 1)
    self.grafo.AdcionaVertice(self.vertice_dois)
    self.assertEquals(self.grafo.Ordem(), 2)
    
  def testPodeRetornarTodosOsSeusVertices(self):
    self.grafo.AdcionaVertice(self.vertice_um)
    vertices = self.grafo.RetornaVertices()
    
    self.assertTrue(self.vertice_um in vertices)
    self.assertEquals(len(vertices), 1)
    
    self.grafo.AdcionaVertice(self.vertice_dois)
    vertices = self.grafo.RetornaVertices()
    
    self.assertTrue(self.vertice_um in vertices)
    self.assertTrue(self.vertice_dois in vertices)
    self.assertEquals(len(vertices), 2)
    
  def testRetornaUmConjuntoVazioSeNaoPossuiVertices(self):
    vertices = self.grafo.RetornaVertices()
    self.assertEquals(len(vertices), 0)
    
  def testPodeRetornarUmVerticeAleatorio(self):
    self.grafo.AdcionaVertice(self.vertice_um)
    self.grafo.AdcionaVertice(self.vertice_dois)
    vertice = self.grafo.RetornaVertice()
    self.assertNotEquals(vertice, None)
    
  def testRetornaNoneSeOGrafoEstaVazioETentaObterUmVertice(self):
    vertice = self.grafo.RetornaVertice()
    self.assertEquals(vertice, None)
    
  def testPodeRetornarTodosOsVerticesAdjacentesAUmDadoVertice(self):
    self.grafo.AdcionaVertice(self.vertice_um)
    self.grafo.AdcionaVertice(self.vertice_dois)
    self.grafo.AdcionaVertice(self.vertice_tres)
    self.grafo.Conecta(self.vertice_um, self.vertice_dois)
    
    adjacentes = self.grafo.Adjacentes(self.vertice_um)
    
    self.assertEquals(len(adjacentes), 1)
    self.assertTrue(self.vertice_dois in adjacentes)
    
    self.grafo.Conecta(self.vertice_um, self.vertice_tres)
    
    adjacentes = self.grafo.Adjacentes(self.vertice_um)
    self.assertEquals(len(adjacentes), 2)
    self.assertTrue(self.vertice_dois in adjacentes)
    self.assertTrue(self.vertice_tres in adjacentes)
    
  def testAdjacenciaEhSimetrica(self):
    self.grafo.AdcionaVertice(self.vertice_um)
    self.grafo.AdcionaVertice(self.vertice_dois)
    self.grafo.Conecta(self.vertice_um, self.vertice_dois)
    
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
    
    self.grafo.Conecta(self.vertice_um, self.vertice_um)
    
    self.assertTrue(self.grafo.EstaoConectados(self.vertice_um, self.vertice_um))
    adjacentes = self.grafo.Adjacentes(self.vertice_um)
    
    self.assertEquals(len(adjacentes), 1)
    self.assertTrue(self.vertice_um in adjacentes)
    
  def testPodeInformarOGrauDeUmVertice(self):
    self.grafo.AdcionaVertice(self.vertice_um)
    self.assertEquals(self.grafo.Grau(self.vertice_um), 0)
    
    self.grafo.AdcionaVertice(self.vertice_dois)
    self.assertEquals(self.grafo.Grau(self.vertice_um), 0)
    self.assertEquals(self.grafo.Grau(self.vertice_dois), 0)
    
    self.grafo.Conecta(self.vertice_dois, self.vertice_um)
    
    self.assertEquals(self.grafo.Grau(self.vertice_um), 1)
    self.assertEquals(self.grafo.Grau(self.vertice_dois), 1)
    
  def testSeOVerticeEhConectadoAEleMentoSeuGrauEhUm(self):
    self.grafo.AdcionaVertice(self.vertice_um)
    self.assertEquals(self.grafo.Grau(self.vertice_um), 0)
    
    self.grafo.Conecta(self.vertice_um, self.vertice_um)
    
    self.assertEquals(self.grafo.Grau(self.vertice_um), 1)
    
  def testSeOVerticeNaoExisteNoGrafoSeraRetornadoZeroComoGrau(self):
    self.assertEquals(self.grafo.Grau(self.vertice_um), 0)
    self.assertEquals(self.grafo.Grau(self.vertice_dois), 0)
  
  
#<<<<<EXECUTANDO TESTES>>>>>#  
suite = unittest.TestSuite()
suite.addTest(unittest.makeSuite(TesteGrafo))
unittest.TextTestRunner(verbosity=2).run(suite)
