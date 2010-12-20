'''
Created on 23/09/2009
@author: katcipis
'''
import unittest
from automato_finito.Transicao import Transicao

class TesteTransicao(unittest.TestCase):

  def setUp(self):
    self.transicao_a_q1 = Transicao('a', 'q1')

  def testSabeQualOSimbolo(self):
    self.assertEqual(self.transicao_a_q1.obterSimbolo(), 'a')
    
  def testSabeQualNaoEhOSimbolo(self):
    self.assertNotEqual(self.transicao_a_q1.obterSimbolo(), 'b')
    
  def testSabeQualEhONomeDoEstadoDestino(self):
    self.assertEqual(self.transicao_a_q1.obterNomeEstadoDestino(), 'q1')
    
  def testSabeQualNaoEhONomeDoEstadoDestino(self):
    self.assertNotEqual(self.transicao_a_q1.obterNomeEstadoDestino(), 'q2')
    
  def testSeDuasTransicoesPossuemMesmoNomeEEstadoDestinoEntaoSaoIguais(self):
    self.assertEqual(self.transicao_a_q1, Transicao('a','q1'))
    
  def testSeDuasTransicoesNaoPossuemMesmoNomeEEstadoDestinoEntaoNaoSaoIguais(self):
    self.assertNotEqual(self.transicao_a_q1, Transicao('a','q2'))
    self.assertNotEqual(self.transicao_a_q1, Transicao('b','q2'))
    self.assertNotEqual(self.transicao_a_q1, Transicao('b','q1'))
    
  def testUmaTransicaoEhConstanteEPossuiHashProprio(self):
    self.assertNotEqual(hash(Transicao('a', '10')), hash(Transicao('b', '11')))
    self.assertEqual(hash(Transicao('a', '10')), hash(Transicao('a', '10')))
    
  def testSeDuasTransicoesNaoPossuemMesmoHashNaoSaoIguais(self):
    self.assertNotEqual(self.transicao_a_q1, Transicao('a','q2'))
    self.assertNotEqual(hash(self.transicao_a_q1), hash(Transicao('a','q2')))
    
  def testSeDuasTransicoesPossuemMesmoHashSaoIguais(self):
    self.assertEqual(self.transicao_a_q1, Transicao('a','q1'))
    self.assertEqual(hash(self.transicao_a_q1), hash(Transicao('a','q1')))
    
  def testTransicaoPossuiRepresentacaoComoString(self):
    self.assertEqual(str(Transicao('a', '10')), str(Transicao('a', '10')))
    self.assertNotEqual(str(Transicao('a', '10')), str(Transicao('a', '0')))
    
if(__name__ == "__main__"):  
  suite = unittest.TestSuite()
  suite.addTest(unittest.makeSuite(TesteTransicao))
  unittest.TextTestRunner(verbosity=2).run(suite)