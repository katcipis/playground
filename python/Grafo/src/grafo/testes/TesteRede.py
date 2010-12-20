# -*- coding: latin-1 -*-

import unittest
from grafo.Rede import Rede
from grafo.testes.TesteDigrafoValorado import TesteDigrafoValorado

class TesteRede(TesteDigrafoValorado):
  """Teste da classe Rede"""
  
  def setUp(self):
    self.vertice_um = 'Abacate'
    self.vertice_dois = 'Bobo'
    self.vertice_tres = 'Caca'
    self.digrafo = Rede()
    self.digrafo_valorado = Rede()
    self.rede = Rede()
  
  def testEhPossivelConectarUmVerticeAEleMesmo(self):
    """ Não é possível, portanto o teste esta sendo sobrecarregado """
    
    
  def testSeOVerticeEhConectadoAEleMentoSeuGrauEhUm(self):
     """ Não é possível, portanto o teste esta sendo sobrecarregado """
     
  def testNaoEhPossivelConectarUmVerticeAEleMesmo(self):
    self.rede.Conecta(self.vertice_um, self.vertice_um)
    self.assertFalse(self.rede.EstaoConectados(self.vertice_um, self.vertice_um))
    self.assertEquals(0, self.rede.Grau(self.vertice_um))
    
  def testSeForPassadoUmValorNegativoAoConectarDoisVerticesOValorSeraZero(self):
    self.rede.AdcionaVertice(self.vertice_um)
    self.rede.AdcionaVertice(self.vertice_dois)
    
    self.rede.Conecta(self.vertice_um, self.vertice_dois, -10, 10)
    self.assertTrue(self.rede.EstaoConectados(self.vertice_um, self.vertice_dois))
    self.assertEquals(0, self.rede.ValorDaConexao(self.vertice_um, self.vertice_dois))
    
  def testSeNaoForPassadoUmValorAoConectarDoisVerticesOValorSeraZero(self):
    self.rede.AdcionaVertice(self.vertice_um)
    self.rede.AdcionaVertice(self.vertice_dois)
    
    self.rede.Conecta(self.vertice_um, self.vertice_dois)
    self.assertTrue(self.rede.EstaoConectados(self.vertice_um, self.vertice_dois))
    self.assertEquals(0, self.rede.ValorDaConexao(self.vertice_um, self.vertice_dois))
    
  def testSeNaoForPassadoUmaCapacidadeAoConectarDoisVerticesACapacidadeSeraZero(self):
    self.rede.AdcionaVertice(self.vertice_um)
    self.rede.AdcionaVertice(self.vertice_dois)
    
    self.rede.Conecta(self.vertice_um, self.vertice_dois)
    self.assertTrue(self.rede.EstaoConectados(self.vertice_um, self.vertice_dois))
    self.assertEquals(0, self.rede.CapacidadeDaConexao(self.vertice_um, self.vertice_dois))
    
  def testConexoesEmDirecoesDiferentesPodemPossuirValoresDiferentes(self):
    self.rede.AdcionaVertice(self.vertice_um)
    self.rede.AdcionaVertice(self.vertice_dois)
    
    self.rede.Conecta(self.vertice_dois, self.vertice_um, 5, 10)
    self.rede.Conecta(self.vertice_um, self.vertice_dois, 3, 10)
    
    self.assertTrue(self.rede.EstaoConectados(self.vertice_um, self.vertice_dois))
    self.assertTrue(self.rede.EstaoConectados(self.vertice_dois, self.vertice_um))
    
    self.assertEquals(5, self.rede.ValorDaConexao(self.vertice_dois, self.vertice_um))
    self.assertEquals(3, self.rede.ValorDaConexao(self.vertice_um, self.vertice_dois))
    
  def testSeDoisVerticesEstaoConectadosPodeInformarOValorDaConexao(self):
    self.rede.AdcionaVertice(self.vertice_um)
    self.rede.AdcionaVertice(self.vertice_dois)
    
    self.rede.Conecta(self.vertice_dois, self.vertice_um, 5, 10)
    
    self.assertEquals(5, self.rede.ValorDaConexao(self.vertice_dois, self.vertice_um))
    
  def testSeDoisVerticesForemConectadosComValorSuperiorACapacidadeOValorSeraACapacidade(self):
    self.rede.AdcionaVertice(self.vertice_um)
    self.rede.AdcionaVertice(self.vertice_dois)
    
    self.rede.Conecta(self.vertice_dois, self.vertice_um, 15, 10)
    
    self.assertEquals(10, self.rede.ValorDaConexao(self.vertice_dois, self.vertice_um))
    
  def testSeAindaNaoFoiDefinidaRaizARaizSeraNone(self):
    self.assertEquals(None, self.rede.ObterRaiz())
    
  def testSeAindaNaoFoiDefinidaAntiRaizAAntiRaizSeraNone(self):
    self.assertEquals(None, self.rede.ObterAntiRaiz())
    
  def testSeFoiDefinidaRaizSabeQualEh(self):
    self.rede.Raiz(self.vertice_um)
    self.assertEquals(self.vertice_um, self.rede.ObterRaiz())
    
  def testSeFoiDefinidaAntiRaizSabeQualEh(self):
    self.rede.AntiRaiz(self.vertice_um)
    self.assertEquals(self.vertice_um, self.rede.ObterAntiRaiz())
    
  def testSeJaFoiDefinidaRaizNaoPodeRedefinila(self):
    self.rede.Raiz(self.vertice_um)
    self.assertEquals(self.vertice_um, self.rede.ObterRaiz())
    self.rede.Raiz(self.vertice_dois)
    self.assertEquals(self.vertice_um, self.rede.ObterRaiz())
    
  def testSeJaFoiDefinidaAntiRaizNaoPodeRedefinila(self):
    self.rede.AntiRaiz(self.vertice_um)
    self.assertEquals(self.vertice_um, self.rede.ObterAntiRaiz())
    self.rede.AntiRaiz(self.vertice_dois)
    self.assertEquals(self.vertice_um, self.rede.ObterAntiRaiz())
    
  def testSeFoiDefinidaRaizARaizEstaNaRede(self):
    self.rede.Raiz(self.vertice_um)
    self.assertTrue(self.rede.PossuiVertice(self.vertice_um))
    
  def testSeFoiDefinidaAntiRaizAAntiRaizEstaNaRede(self):
    self.rede.AntiRaiz(self.vertice_um)
    self.assertTrue(self.rede.PossuiVertice(self.vertice_um))
    
  def testUmVerticeSohPodeSerDefinidoComoRaizSeEleAindaNaoExisteNaRede(self):
    self.rede.AdcionaVertice(self.vertice_um)
    self.rede.Raiz(self.vertice_um)
    self.assertFalse(self.vertice_um == self.rede.ObterRaiz())
    
  def testUmVerticeSohPodeSerDefinidoComoAntiRaizSeEleAindaNaoExisteNaRede(self):
    self.rede.AdcionaVertice(self.vertice_um)
    self.rede.AntiRaiz(self.vertice_um)
    self.assertFalse(self.vertice_um == self.rede.ObterAntiRaiz())
    
  def testRaizNuncaTemAntecessores(self):
    self.rede.Raiz(self.vertice_um)
    self.rede.AdcionaVertice(self.vertice_dois)
    self.rede.AdcionaVertice(self.vertice_tres)
    
    self.rede.Conecta(self.vertice_dois, self.vertice_um, 5, 10)
    self.rede.Conecta(self.vertice_tres, self.vertice_um, 5, 10)
    
    self.assertEquals(0, len(self.rede.Antecessores(self.vertice_um)))
    self.assertFalse(self.rede.EstaoConectados(self.vertice_dois, self.vertice_um))
    self.assertFalse(self.rede.EstaoConectados(self.vertice_tres, self.vertice_um))
    
  def testRaizTemGrauDeRecepcaoZeroSempre(self):
    self.rede.Raiz(self.vertice_um)
    self.rede.AdcionaVertice(self.vertice_dois)
    self.rede.AdcionaVertice(self.vertice_tres)
    
    self.rede.Conecta(self.vertice_dois, self.vertice_um, 5, 10)
    self.rede.Conecta(self.vertice_tres, self.vertice_um, 5, 10)
    
    self.assertEquals(0, self.rede.GrauDeRecepcao(self.vertice_um))
    self.assertFalse(self.rede.EstaoConectados(self.vertice_dois, self.vertice_um))
    self.assertFalse(self.rede.EstaoConectados(self.vertice_tres, self.vertice_um))
    
  def testAntiRaizNuncaTemSuscessores(self):
    self.rede.AntiRaiz(self.vertice_um)
    self.rede.AdcionaVertice(self.vertice_dois)
    self.rede.AdcionaVertice(self.vertice_tres)
    
    self.rede.Conecta(self.vertice_um, self.vertice_dois, 5, 10)
    self.rede.Conecta(self.vertice_um, self.vertice_dois, 5, 10)
    
    self.assertEquals(0, len(self.rede.Suscessores(self.vertice_um)))
    self.assertFalse(self.rede.EstaoConectados(self.vertice_um, self.vertice_dois))
    self.assertFalse(self.rede.EstaoConectados(self.vertice_um, self.vertice_dois))
    
  def testAntiRaizTemGrauDeEmissaoZeroSempre(self):
    self.rede.AntiRaiz(self.vertice_um)
    self.rede.AdcionaVertice(self.vertice_dois)
    self.rede.AdcionaVertice(self.vertice_tres)
    
    self.rede.Conecta(self.vertice_um, self.vertice_dois, 5, 10)
    self.rede.Conecta(self.vertice_um, self.vertice_dois, 5, 10)
    
    self.assertEquals(0, self.rede.GrauDeEmissao(self.vertice_um))
    self.assertFalse(self.rede.EstaoConectados(self.vertice_um, self.vertice_dois))
    self.assertFalse(self.rede.EstaoConectados(self.vertice_um, self.vertice_dois))
    
  def testRaizPodeTerSuscessores(self):
    self.rede.Raiz(self.vertice_um)
    self.rede.AdcionaVertice(self.vertice_dois)
    self.rede.AdcionaVertice(self.vertice_tres)
    
    self.rede.Conecta(self.vertice_um, self.vertice_dois, 5, 10)
    self.rede.Conecta(self.vertice_um, self.vertice_tres, 5, 10)
    
    self.assertEquals(2, len(self.rede.Suscessores(self.vertice_um)))
    self.assertTrue(self.rede.EstaoConectados(self.vertice_um, self.vertice_dois))
    self.assertTrue(self.rede.EstaoConectados(self.vertice_um, self.vertice_tres))
    
  def testRaizPodeTerGrauDeEmissaoMaiorQueZero(self):
    self.rede.Raiz(self.vertice_um)
    self.rede.AdcionaVertice(self.vertice_dois)
    self.rede.AdcionaVertice(self.vertice_tres)
    
    self.rede.Conecta(self.vertice_um, self.vertice_dois, 5, 10)
    self.rede.Conecta(self.vertice_um, self.vertice_tres, 5, 10)
    
    self.assertEquals(2, self.rede.GrauDeEmissao(self.vertice_um))
    self.assertTrue(self.rede.EstaoConectados(self.vertice_um, self.vertice_dois))
    self.assertTrue(self.rede.EstaoConectados(self.vertice_um, self.vertice_dois))
    
  def testAntiRaizPodeTerAntecessores(self):
    self.rede.AntiRaiz(self.vertice_um)
    self.rede.AdcionaVertice(self.vertice_dois)
    self.rede.AdcionaVertice(self.vertice_tres)
    
    self.rede.Conecta(self.vertice_dois, self.vertice_um, 5, 10)
    self.rede.Conecta(self.vertice_tres, self.vertice_um, 5, 10)
    
    self.assertEquals(2, len(self.rede.Antecessores(self.vertice_um)))
    self.assertTrue(self.rede.EstaoConectados(self.vertice_dois, self.vertice_um))
    self.assertTrue(self.rede.EstaoConectados(self.vertice_tres, self.vertice_um))
    
  def testAntiRaizPodeTerGrauDeRecepcaoMaiorQueZero(self):
    self.rede.AntiRaiz(self.vertice_um)
    self.rede.AdcionaVertice(self.vertice_dois)
    self.rede.AdcionaVertice(self.vertice_tres)
    
    self.rede.Conecta(self.vertice_dois, self.vertice_um, 5, 10)
    self.rede.Conecta(self.vertice_tres, self.vertice_um, 5, 10)
    
    self.assertEquals(2, self.rede.GrauDeRecepcao(self.vertice_um))
    self.assertTrue(self.rede.EstaoConectados(self.vertice_dois, self.vertice_um))
    self.assertTrue(self.rede.EstaoConectados(self.vertice_tres, self.vertice_um))
    
  def testSabeACapacidadeMaximaDeUmaConexao(self):
    self.rede.AntiRaiz(self.vertice_um)
    self.rede.AdcionaVertice(self.vertice_dois)
    self.rede.AdcionaVertice(self.vertice_tres)
    
    self.rede.Conecta(self.vertice_dois, self.vertice_um, 5, 8)
    self.rede.Conecta(self.vertice_tres, self.vertice_um, 5, 10)
    
    self.assertEquals(8, self.rede.CapacidadeDaConexao(self.vertice_dois, self.vertice_um))
    self.assertEquals(10, self.rede.CapacidadeDaConexao(self.vertice_tres, self.vertice_um))
    
  def testConexoesEmDirecoesDiferentesPodemPossuirCapacidadesDiferentes(self):
    self.digrafo_valorado.AdcionaVertice(self.vertice_um)
    self.digrafo_valorado.AdcionaVertice(self.vertice_dois)
    
    self.digrafo_valorado.Conecta(self.vertice_dois, self.vertice_um, 2, 5)
    self.digrafo_valorado.Conecta(self.vertice_um, self.vertice_dois, 1, 3)
    
    self.assertEquals(5, self.digrafo_valorado.CapacidadeDaConexao(self.vertice_dois, self.vertice_um))
    self.assertEquals(3, self.digrafo_valorado.CapacidadeDaConexao(self.vertice_um, self.vertice_dois))
    
    
#<<<<<EXECUTANDO TESTES>>>>>#  
suite = unittest.TestSuite()
suite.addTest(unittest.makeSuite(TesteRede))
unittest.TextTestRunner(verbosity=2).run(suite)