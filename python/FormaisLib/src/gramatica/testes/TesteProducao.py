'''
Created on 26/10/2009
@author: katcipis
'''
import unittest
from gramatica.Producao import Producao

class TesteProducao(unittest.TestCase):

  def testSabeQualSeuAlpha(self):
    producao = Producao('A', 'abN')
    self.assertEqual('A', producao.obterAlpha())

  def testSabeQualNaoEhSeuAlpha(self):
    producao = Producao('A', 'abN')
    self.assertNotEqual('B', producao.obterAlpha())

  def testSabeQualSeuBeta(self):
    producao = Producao('A', 'abN')
    self.assertEqual('abN', producao.obterBeta())    
  
  def testSabeQualNaoEhSeuBeta(self):
    producao = Producao('A', 'abN')
    self.assertNotEqual('aBN', producao.obterBeta())
  
  def testSaoIguaisSePossuemMesmoAlphaEMesmoBeta(self):
    producao1 = Producao('A', 'abN')
    producao2 = Producao('A', 'abN')
    self.assertEqual(producao1.obterAlpha(), producao2.obterAlpha())
    self.assertEqual(producao1.obterBeta(), producao2.obterBeta())
    self.assertEqual(producao1, producao2)
    
  def testNaoSaoIguaisSeNaoPossuemMesmoAlpha(self):
    producao1 = Producao('A', 'abN')
    producao2 = Producao('B', 'abN')
    self.assertNotEqual(producao1.obterAlpha(), producao2.obterAlpha())
    self.assertEqual(producao1.obterBeta(), producao2.obterBeta())
    self.assertNotEqual(producao1, producao2)
  
  def testNaoSaoIguaisSeNaoPossuemMesmoBeta(self):
    producao1 = Producao('A', 'abN')
    producao2 = Producao('A', 'abn')
    self.assertEqual(producao1.obterAlpha(), producao2.obterAlpha())
    self.assertNotEqual(producao1.obterBeta(), producao2.obterBeta())
    self.assertNotEqual(producao1, producao2)
    
  def testPossueHashProprio(self):
    producao1 = Producao('A', 'abn')
    producao2 = Producao('A', 'abn')
    self.assertEqual(hash(producao1), hash(producao2))
  
  def testSeSaoIguaisPossuemMesmoHash(self):
    producao1 = Producao('A', 'abN')
    producao2 = Producao('A', 'abN')
    self.assertEqual(producao1, producao2)
    self.assertEqual(hash(producao1), hash(producao2))
  
  def testSeSaoDiferentesPossuemHashDiferentes(self):
    producao1 = Producao('A', 'ab')
    producao2 = Producao('A', 'abN')
    self.assertNotEqual(producao1, producao2)
    self.assertNotEqual(hash(producao1), hash(producao2))
    
  def testSePossuemMesmoHashSaoIguais(self):
    producao1 = Producao('B', 'acbN')
    producao2 = Producao('B', 'acbN')
    self.assertEqual(producao1, producao2)
    self.assertEqual(hash(producao1), hash(producao2))
  
  def testSeNaoPossuemMesmoHashNaoSaoIguais(self):
    producao1 = Producao('B', 'acbN')
    producao2 = Producao('B', 'abN')
    self.assertNotEqual(producao1, producao2)
    self.assertNotEqual(hash(producao1), hash(producao2))
    
  def testEspacosNoInicioDoAlphaSaoIgnorados(self):
    self.assertEqual('B', Producao('  B', 'acbN').obterAlpha())
    self.assertEqual('B', Producao(' B', 'acbN').obterAlpha())
    
  def testEspacosNoFimDoAlphaSaoIgnorados(self):
    self.assertEqual('B', Producao('B  ', 'acbN').obterAlpha())
    self.assertEqual('B', Producao('B ', 'acbN').obterAlpha())
    
  def testUmEspacoEntreSimbolosNoAlphaEhConsiderado(self):
    self.assertEqual('B A', Producao('B A', 'a cb N').obterAlpha())
    
  def testMaisDeUmEspacoEntreSimbolosNoAlphaEhConsideradoComoApenasUmEspaco(self):
    self.assertEqual('B A C', Producao('B  A C', 'a cb N').obterAlpha())
    self.assertEqual('B A C', Producao('B  A  C', 'a cb N').obterAlpha())
    self.assertEqual('B A C', Producao('B  A      C', 'a cb N').obterAlpha())
    
  def testEspacosNoInicioDoBetaSaoIgnorados(self):
    self.assertEqual('acbN', Producao('B', ' acbN').obterBeta())
    self.assertEqual('acbN', Producao('B', '  acbN').obterBeta())
    
  def testEspacosNoFinalDoBetaSaoIgnorados(self):
    self.assertEqual('acbN', Producao('B', 'acbN ').obterBeta())
    self.assertEqual('acbN', Producao('B', 'acbN  ').obterBeta())
    
  def testUmEspacoEntreSimbolosNoBetaEhConsiderado(self):
    self.assertEqual('a cb N', Producao('B A', 'a cb N').obterBeta())
    
  def testMaisDeUmEspacoEntreSimbolosNoBetaEhConsideradoComoApenasUmEspaco(self):
    self.assertEqual('a cb N', Producao('B', 'a  cb N').obterBeta())
    self.assertEqual('a cb N', Producao('B', 'a cb  N').obterBeta())
    self.assertEqual('a cb N', Producao('B', 'a  cb     N').obterBeta())
    
  def testDadoUmIndiceSabeDizerQualSimboloSeEncontraNaquelaPosicaoNoBetaDaProducao(self):
    p = Producao('B', 'a <ABACATE> N b')
    self.assertEqual('a', p.obterSimboloBeta(0))
    self.assertEqual('<ABACATE>', p.obterSimboloBeta(1))
    self.assertEqual('N', p.obterSimboloBeta(2))
    self.assertEqual('b', p.obterSimboloBeta(3))
    
  def testSabeDizerQuantosSimbolosExistemNoBetaDaProducao(self):
    p = Producao('B', 'a <ABACATE> N b')
    self.assertEqual(4, p.obterTamanhoBeta())
    
  def testSeNaoExisteSimboloNoIndiceInformadoRetornaNone(self):  
    p = Producao('B', 'a <ABACATE> N b')
    self.assertEqual(None, p.obterSimboloBeta(4))
    
if(__name__ == "__main__"):  
  suite = unittest.TestSuite()
  suite.addTest(unittest.makeSuite(TesteProducao))
  unittest.TextTestRunner(verbosity=2).run(suite)
  