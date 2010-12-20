import unittest
from grafo.Digrafo import Digrafo

class TesteDigrafo(unittest.TestCase):
  """Teste da classe DigrafoValorado"""
  
  def setUp(self):
    self.vertice_um = 'A'
    self.vertice_dois = 'B'
    self.vertice_tres = 'C'
    self.digrafo = Digrafo()
    
  def testSeUmVerticeNaoFoiAdcionadoEleNaoExisteNoGrafo(self):
    self.assertFalse(self.digrafo.PossuiVertice(self.vertice_um))
    self.assertFalse(self.digrafo.PossuiVertice(self.vertice_dois))
    self.assertFalse(self.digrafo.PossuiVertices([self.vertice_um, self.vertice_dois]))
    
  def testSeUmVerticeFoiAdcionadoEleExisteNoGrafo(self):
    self.digrafo.AdcionaVertice(self.vertice_um)
    
    self.assertTrue(self.digrafo.PossuiVertice(self.vertice_um))
    self.assertFalse(self.digrafo.PossuiVertice(self.vertice_dois))
    
    self.digrafo.AdcionaVertice(self.vertice_dois)
    
    self.assertTrue(self.digrafo.PossuiVertice(self.vertice_dois))
    self.assertTrue(self.digrafo.PossuiVertices([self.vertice_um, self.vertice_dois]))
    
  def testSeUmVerticeFoiAdcionadoEOutroNaoOOutroNaoEstaNoGrafo(self):
    self.digrafo.AdcionaVertice(self.vertice_um)
    
    self.assertTrue(self.digrafo.PossuiVertice(self.vertice_um))
    self.assertFalse(self.digrafo.PossuiVertice(self.vertice_dois))
    self.assertFalse(self.digrafo.PossuiVertices([self.vertice_um, self.vertice_dois]))
    
  def testSeUmVerticeForInseridoDuasVezesExistiraApenasUmaOcorrenciaDeleNoGrafo(self):
    self.digrafo.AdcionaVertice(self.vertice_um)
    self.digrafo.AdcionaVertice(self.vertice_um)

    self.assertTrue(self.digrafo.PossuiVertice(self.vertice_um))
    self.assertEquals(self.digrafo.Ordem(), 1)
    
    self.digrafo.AdcionaVertice(self.vertice_dois)
    self.digrafo.AdcionaVertice(self.vertice_dois)
    
    self.assertTrue(self.digrafo.PossuiVertice(self.vertice_dois))
    self.assertEquals(self.digrafo.Ordem(), 2)
   
  def testSeUmVerticeQueNaoExisteNoGrafoForRemovidoNadaAcontece(self):
    self.digrafo.RemoveVertice(self.vertice_um)
    
  def testSeUmVerticeForRemovidoEleNaoSeEncontraMaisNoGrafo(self):
    self.digrafo.AdcionaVertice(self.vertice_um)
    self.assertTrue(self.digrafo.PossuiVertice(self.vertice_um))
    
    self.digrafo.RemoveVertice(self.vertice_um)
    self.assertFalse(self.digrafo.PossuiVertice(self.vertice_um))
    
  def testSabeSeDoisVerticesEstaoConectados(self):
    self.digrafo.AdcionaVertice(self.vertice_um)
    self.digrafo.AdcionaVertice(self.vertice_dois)
    
    self.assertFalse(self.digrafo.EstaoConectados(self.vertice_um, self.vertice_dois))
    self.digrafo.Conecta(self.vertice_um, self.vertice_dois)
    self.assertTrue(self.digrafo.EstaoConectados(self.vertice_um, self.vertice_dois))
    
  def testSabeSeDoisVerticesNaoEstaoConectados(self):
    self.digrafo.AdcionaVertice(self.vertice_um)
    self.digrafo.AdcionaVertice(self.vertice_dois)
    
    self.assertFalse(self.digrafo.EstaoConectados(self.vertice_um, self.vertice_dois))
    
  def testSeOsVerticesNaoEstaoNoGrafoNaoEhPossivelConectalos(self):
    self.digrafo.Conecta(self.vertice_um, self.vertice_dois)
    self.assertFalse(self.digrafo.EstaoConectados(self.vertice_um, self.vertice_dois))
    
  def testSeUmDosVerticesNaoEstaoNoGrafoNaoEhPossivelConectalos(self):
    self.digrafo.AdcionaVertice(self.vertice_um)
    self.digrafo.Conecta(self.vertice_um, self.vertice_dois)
    self.assertFalse(self.digrafo.EstaoConectados(self.vertice_um, self.vertice_dois))
    
  def testSeDoisVerticesSaoDesconectadosEmUmaDirecaoElesNaoEstaoMaisConectadosNaquelaDirecao(self):
    self.digrafo.AdcionaVertice(self.vertice_um)
    self.digrafo.AdcionaVertice(self.vertice_dois)
    
    self.digrafo.Conecta(self.vertice_um, self.vertice_dois)
    self.assertTrue(self.digrafo.EstaoConectados(self.vertice_um, self.vertice_dois))
    
    self.digrafo.Desconecta(self.vertice_um, self.vertice_dois)
    self.assertFalse(self.digrafo.EstaoConectados(self.vertice_um, self.vertice_dois))
    
  def testSeDoisVerticesDesconectadosForemDesconectadosNadaOcorre(self):
    self.digrafo.AdcionaVertice(self.vertice_um)
    self.digrafo.AdcionaVertice(self.vertice_dois)
    
    self.digrafo.Desconecta(self.vertice_um, self.vertice_dois)
    self.assertFalse(self.digrafo.EstaoConectados(self.vertice_um, self.vertice_dois))
    
  def testSeDoisVerticesNaoExistemNoGrafoESaoDesconectadosNadaOcorre(self):
    self.digrafo.Desconecta(self.vertice_um, self.vertice_dois)
    self.assertFalse(self.digrafo.EstaoConectados(self.vertice_um, self.vertice_dois))
    
  def testSabeSePossuiUmVertice(self):
    self.digrafo.AdcionaVertice(self.vertice_um)
    self.assertTrue(self.digrafo.PossuiVertice(self.vertice_um))
    
  def testSabeSeNaoPossuiUmVertice(self):
    self.digrafo.AdcionaVertice(self.vertice_um)
    self.assertFalse(self.digrafo.PossuiVertice(self.vertice_dois))
    
  def testSabeSePossuiUmConjuntoDeVertices(self):
    self.digrafo.AdcionaVertice(self.vertice_um)
    self.digrafo.AdcionaVertice(self.vertice_dois)
    self.assertTrue(self.digrafo.PossuiVertices([self.vertice_um,self.vertice_dois] ))
    
  def testSabeSeNaoPossuiUmConjuntoDeVertices(self):
    self.digrafo.AdcionaVertice(self.vertice_um)
    self.assertFalse(self.digrafo.PossuiVertices([self.vertice_um,self.vertice_dois] ))
    
  def testSabeSeEstaVazio(self):
    self.assertTrue(self.digrafo.EstaVazio())
    
  def testSabeSeNaoEstaVazio(self):
    self.digrafo.AdcionaVertice(self.vertice_um)
    self.assertFalse(self.digrafo.EstaVazio())
    
  def testSabeSuaOrdem(self):
    self.assertEquals(self.digrafo.Ordem(), 0)
    self.digrafo.AdcionaVertice(self.vertice_um)
    self.assertEquals(self.digrafo.Ordem(), 1)
    self.digrafo.AdcionaVertice(self.vertice_dois)
    self.assertEquals(self.digrafo.Ordem(), 2)
    
  def testPodeRetornarTodosOsSeusVertices(self):
    self.digrafo.AdcionaVertice(self.vertice_um)
    vertices = self.digrafo.RetornaVertices()
    
    self.assertTrue(self.vertice_um in vertices)
    self.assertEquals(len(vertices), 1)
    
    self.digrafo.AdcionaVertice(self.vertice_dois)
    vertices = self.digrafo.RetornaVertices()
    
    self.assertTrue(self.vertice_um in vertices)
    self.assertTrue(self.vertice_dois in vertices)
    self.assertEquals(len(vertices), 2)
    
  def testRetornaUmConjuntoVazioSeNaoPossuiVertices(self):
    vertices = self.digrafo.RetornaVertices()
    self.assertEquals(len(vertices), 0)
    
  def testPodeRetornarUmVerticeAleatorio(self):
    self.digrafo.AdcionaVertice(self.vertice_um)
    self.digrafo.AdcionaVertice(self.vertice_dois)
    vertice = self.digrafo.RetornaVertice()
    self.assertNotEquals(vertice, None)
    
  def testRetornaNoneSeOGrafoEstaVazioETentaObterUmVertice(self):
    vertice = self.digrafo.RetornaVertice()
    self.assertEquals(vertice, None)
    
  def testAdjacenciaEhSimetrica(self):
    self.digrafo.AdcionaVertice(self.vertice_um)
    self.digrafo.AdcionaVertice(self.vertice_dois)
    self.digrafo.Conecta(self.vertice_um, self.vertice_dois)
    
    adjacentes = self.digrafo.Adjacentes(self.vertice_um)
    
    self.assertEquals(len(adjacentes), 1)
    self.assertTrue(self.vertice_dois in adjacentes)
    
    adjacentes = self.digrafo.Adjacentes(self.vertice_dois)
    self.assertEquals(len(adjacentes), 1)
    self.assertTrue(self.vertice_um in adjacentes)
    
  def testEhPossivelConectarUmVerticeAEleMesmo(self):
    self.digrafo.AdcionaVertice(self.vertice_um)
    
    adjacentes = self.digrafo.Adjacentes(self.vertice_um)
    self.assertEquals(len(adjacentes), 0)
    self.assertFalse(self.digrafo.EstaoConectados(self.vertice_um, self.vertice_um))
    
    self.digrafo.Conecta(self.vertice_um, self.vertice_um)
    
    self.assertTrue(self.digrafo.EstaoConectados(self.vertice_um, self.vertice_um))
    adjacentes = self.digrafo.Adjacentes(self.vertice_um)
    
    self.assertEquals(len(adjacentes), 1)
    self.assertTrue(self.vertice_um in adjacentes)
    
  def testPodeInformarOGrauDeUmVertice(self):
    self.digrafo.AdcionaVertice(self.vertice_um)
    self.assertEquals(self.digrafo.Grau(self.vertice_um), 0)
    
    self.digrafo.AdcionaVertice(self.vertice_dois)
    self.assertEquals(self.digrafo.Grau(self.vertice_um), 0)
    self.assertEquals(self.digrafo.Grau(self.vertice_dois), 0)
    
    self.digrafo.Conecta(self.vertice_dois, self.vertice_um)
    
    self.assertEquals(self.digrafo.Grau(self.vertice_um), 1)
    self.assertEquals(self.digrafo.Grau(self.vertice_dois), 1)
    
  def testSeOVerticeNaoExisteNoGrafoSeraRetornadoZeroComoGrau(self):
    self.assertEquals(self.digrafo.Grau(self.vertice_um), 0)
    self.assertEquals(self.digrafo.Grau(self.vertice_dois), 0)
    
  def testSabeQuaisSaoOsSuscessoresDeUmVertice(self):
    self.digrafo.AdcionaVertice(self.vertice_um)
    self.digrafo.AdcionaVertice(self.vertice_dois)
    self.digrafo.AdcionaVertice(self.vertice_tres)
    
    self.digrafo.Conecta(self.vertice_um, self.vertice_dois)
    self.digrafo.Conecta(self.vertice_um, self.vertice_tres)
    
    sus = self.digrafo.Suscessores(self.vertice_um)
    self.assertTrue(self.vertice_dois in sus)
    self.assertTrue(self.vertice_tres in sus)
    self.assertEquals(2, len(sus))
    
    
  def testSabeQuaisSaoOsAntecessoresDeUmVertice(self):
    self.digrafo.AdcionaVertice(self.vertice_um)
    self.digrafo.AdcionaVertice(self.vertice_dois)
    self.digrafo.AdcionaVertice(self.vertice_tres)
    
    self.digrafo.Conecta(self.vertice_dois, self.vertice_um)
    self.digrafo.Conecta(self.vertice_tres, self.vertice_um)
    
    ant = self.digrafo.Antecessores(self.vertice_um)
    self.assertTrue(self.vertice_dois in ant)
    self.assertTrue(self.vertice_tres in ant)
    self.assertEquals(2, len(ant))
  
  def testPodeInformarOGrauDeEmissaoDeUmVertice(self):
    self.digrafo.AdcionaVertice(self.vertice_um)
    self.digrafo.AdcionaVertice(self.vertice_dois)
    self.digrafo.AdcionaVertice(self.vertice_tres)
    
    self.digrafo.Conecta(self.vertice_um, self.vertice_dois)
    self.digrafo.Conecta(self.vertice_um, self.vertice_tres)
    
    self.assertEquals(2, self.digrafo.GrauDeEmissao(self.vertice_um))
    
  def testPodeInformarOGrauDeRecepcaoDeUmVertice(self):
    self.digrafo.AdcionaVertice(self.vertice_um)
    self.digrafo.AdcionaVertice(self.vertice_dois)
    self.digrafo.AdcionaVertice(self.vertice_tres)
    
    self.digrafo.Conecta(self.vertice_dois, self.vertice_um)
    self.digrafo.Conecta(self.vertice_tres, self.vertice_um)
    
    self.assertEquals(2, self.digrafo.GrauDeRecepcao(self.vertice_um))
    
    
  def testPodeRetornarTodosOsVerticesAdjacentesAUmDadoVertice(self):
    self.digrafo.AdcionaVertice(self.vertice_um)
    self.digrafo.AdcionaVertice(self.vertice_dois)
    self.digrafo.AdcionaVertice(self.vertice_tres)
    
    self.digrafo.Conecta(self.vertice_dois, self.vertice_um)
    self.digrafo.Conecta(self.vertice_um, self.vertice_tres)
    
    adj = self.digrafo.Adjacentes(self.vertice_um)
    self.assertTrue(self.vertice_dois in adj)
    self.assertTrue(self.vertice_tres in adj)
    self.assertEquals(2, len(adj))
  
  def testSeDoisVerticesConectadosEmAmbasDirecoesSaoDesconectadosEmUmaDirecaoElesContinuamConectadosEmOutraDirecao(self):
    self.digrafo.AdcionaVertice(self.vertice_um)
    self.digrafo.AdcionaVertice(self.vertice_dois)
    self.digrafo.AdcionaVertice(self.vertice_tres)
    
    self.digrafo.Conecta(self.vertice_dois, self.vertice_um)
    self.digrafo.Conecta(self.vertice_um, self.vertice_dois)
    
    self.assertTrue(self.digrafo.EstaoConectados(self.vertice_um, self.vertice_dois))
    self.assertTrue(self.digrafo.EstaoConectados(self.vertice_dois, self.vertice_um))
    
    self.digrafo.Desconecta(self.vertice_um, self.vertice_dois)
    self.assertFalse(self.digrafo.EstaoConectados(self.vertice_um, self.vertice_dois))
    
    self.assertTrue(self.digrafo.EstaoConectados(self.vertice_dois, self.vertice_um))
    
    
  def testAoConectarOPrimeiroVerticeEhOAntecessorEOSegundoEhOSuscessor(self):
    self.digrafo.AdcionaVertice(self.vertice_um)
    self.digrafo.AdcionaVertice(self.vertice_dois)
    
    self.digrafo.Conecta(self.vertice_dois, self.vertice_um)
    
    self.assertTrue(self.vertice_um in self.digrafo.Suscessores(self.vertice_dois))
    self.assertTrue(self.vertice_dois in self.digrafo.Antecessores(self.vertice_um))
    
    
  def testAoDesconectarOPrimeiroVerticeEhOAntecessorEOSegundoEhOSuscessor(self):
    self.digrafo.AdcionaVertice(self.vertice_um)
    self.digrafo.AdcionaVertice(self.vertice_dois)
    
    self.digrafo.Conecta(self.vertice_dois, self.vertice_um)
    
    self.assertTrue(self.vertice_um in self.digrafo.Suscessores(self.vertice_dois))
    self.assertTrue(self.vertice_dois in self.digrafo.Antecessores(self.vertice_um))
    
    self.digrafo.Desconecta(self.vertice_dois, self.vertice_um)
    self.assertFalse(self.digrafo.EstaoConectados(self.vertice_dois, self.vertice_um))
    
  
#<<<<<EXECUTANDO TESTES>>>>>#  
suite = unittest.TestSuite()
suite.addTest(unittest.makeSuite(TesteDigrafo))
unittest.TextTestRunner(verbosity=2).run(suite)