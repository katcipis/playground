import unittest
from grafo.DigrafoValorado import DigrafoValorado
from grafo.testes.TesteDigrafo import TesteDigrafo

class TesteDigrafoValorado(TesteDigrafo):
  """Teste da classe DigrafoValorado"""
  
  def setUp(self):
    self.vertice_um = 'A'
    self.vertice_dois = 'B'
    self.vertice_tres = 'C'
    self.digrafo = DigrafoValorado()
    self.digrafo_valorado = DigrafoValorado()

    
  def testSeDoisVerticesEstaoConectadosPodeInformarOValorDaConexao(self):
    self.digrafo_valorado.AdcionaVertice(self.vertice_um)
    self.digrafo_valorado.AdcionaVertice(self.vertice_dois)
    
    self.digrafo_valorado.Conecta(self.vertice_dois, self.vertice_um, 5)
    
    self.assertEquals(5, self.digrafo_valorado.ValorDaConexao(self.vertice_dois, self.vertice_um))
    
  def testConexoesEmDirecoesDiferentesPodemPossuirValoresDiferentes(self):
    self.digrafo_valorado.AdcionaVertice(self.vertice_um)
    self.digrafo_valorado.AdcionaVertice(self.vertice_dois)
    
    self.digrafo_valorado.Conecta(self.vertice_dois, self.vertice_um, 5)
    self.digrafo_valorado.Conecta(self.vertice_um, self.vertice_dois, 3)
    
    self.assertEquals(5, self.digrafo_valorado.ValorDaConexao(self.vertice_dois, self.vertice_um))
    self.assertEquals(3, self.digrafo_valorado.ValorDaConexao(self.vertice_um, self.vertice_dois))
    
  def testSeDoisVerticesNaoEstaoConectadosNaDirecaoInformadaRetornaNada(self):
    self.digrafo_valorado.AdcionaVertice(self.vertice_um)
    self.digrafo_valorado.AdcionaVertice(self.vertice_dois)
    
    self.digrafo_valorado.Conecta(self.vertice_dois, self.vertice_um, 5)
    self.assertEquals(None, self.digrafo_valorado.ValorDaConexao(self.vertice_um, self.vertice_dois))
    
  def testSeDoisVerticesNaoEstaoConectadosRetornaNada(self):
    self.digrafo_valorado.AdcionaVertice(self.vertice_um)
    self.digrafo_valorado.AdcionaVertice(self.vertice_dois)
    
    self.assertEquals(None, self.digrafo_valorado.ValorDaConexao(self.vertice_um, self.vertice_dois))
    self.assertEquals(None, self.digrafo_valorado.ValorDaConexao(self.vertice_dois, self.vertice_um))
    
    
  def testAoVerificarOValorDaConexaoOPrimeiroVerticeEhOAntecessorEOSegundoEhOSuscessor(self):
    self.digrafo_valorado.AdcionaVertice(self.vertice_um)
    self.digrafo_valorado.AdcionaVertice(self.vertice_dois)
    
    self.digrafo_valorado.Conecta(self.vertice_dois, self.vertice_um, 5)
    
    self.assertTrue(self.vertice_um in self.digrafo_valorado.Suscessores(self.vertice_dois))
    self.assertTrue(self.vertice_dois in self.digrafo_valorado.Antecessores(self.vertice_um))
    self.assertEquals(None, self.digrafo_valorado.ValorDaConexao(self.vertice_um, self.vertice_dois))
    self.assertNotEquals(None, self.digrafo_valorado.ValorDaConexao(self.vertice_dois, self.vertice_um))
  
#<<<<<EXECUTANDO TESTES>>>>>#  
suite = unittest.TestSuite()
suite.addTest(unittest.makeSuite(TesteDigrafoValorado))
unittest.TextTestRunner(verbosity=2).run(suite)