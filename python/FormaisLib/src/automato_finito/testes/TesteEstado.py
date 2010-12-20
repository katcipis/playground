'''
Created on 23/09/2009
@author: katcipis
'''
import unittest
from automato_finito.Transicao import Transicao
from automato_finito.Estado import Estado

class TesteEstado(unittest.TestCase):

  def setUp(self):
    self.transicoes_a = set()
    self.transicoes_b = set()
    
    self.transicoes_a.add(Transicao('a', 'q0'))
    self.transicoes_a.add(Transicao('b', 'q1'))
    self.transicoes_a.add(Transicao('c', 'q2'))
    
    self.transicoes_b.add(Transicao('c', 'q0'))
    self.transicoes_b.add(Transicao('b', 'q1'))
    self.transicoes_b.add(Transicao('a', 'q2'))
    
  def testSabeSeEhFinal(self):
    estado = Estado('q5', self.transicoes_a, False, True)
    self.assertTrue(estado.ehFinal())
    
  def testSabeSeNaoEhFinal(self):
    estado = Estado('q5', self.transicoes_a, True, False)
    self.assertFalse(estado.ehFinal())
  
  def testSabeSeNaoEhInicial(self):
    estado = Estado('q5', self.transicoes_a, False, True)
    self.assertFalse(estado.ehInicial())
    
  def testSabeSeEhInicial(self):
    estado = Estado('q5', self.transicoes_a, True, False)
    self.assertTrue(estado.ehInicial())
    
  def testSabeQuaisSaoAsSuasTransicoes(self):
    estado = Estado('q5', self.transicoes_a, True, False)
    self.assertEqual(self.transicoes_a, estado.obterTransicoes())
    
  def testSabeQuaisNaoSaoAsSuasTransicoes(self):
    estado = Estado('q5', self.transicoes_a, True, False)
    self.assertNotEqual(self.transicoes_b, estado.obterTransicoes())
    
  def testGuardaUmaCopiaPropriaDoConjuntoDeTransicoes(self):
    estado = Estado('q5', self.transicoes_a, True, False)
    self.assertEqual(self.transicoes_a, estado.obterTransicoes())
    self.transicoes_a.pop()
    self.assertNotEqual(self.transicoes_a, estado.obterTransicoes())
    
  def testRetornaUmaCopiaDoSeuConjuntoDeTransicoes(self):
    estado = Estado('q5', self.transicoes_a, True, False)
    transicoes = estado.obterTransicoes()
    self.assertEqual(transicoes, estado.obterTransicoes())
    transicoes.pop()
    self.assertNotEqual(transicoes, estado.obterTransicoes())
    
  def testSabeQualOSeuNome(self):
    nome_estado = 'q5'
    estado = Estado(nome_estado, self.transicoes_a, True, False)
    self.assertEqual(nome_estado, estado.obterNome())
    
  def testSabeQualNaoEhOSeuNome(self):
    nome_estado = 'q5'
    nome_errado = 'vida_louca'
    estado = Estado(nome_estado, self.transicoes_a, True, False)
    self.assertNotEqual(nome_errado, estado.obterNome())
    
  def testEhConstanteEPossuiHash(self):
    nome_estado = 'q5'
    self.assertEqual(hash(Estado(nome_estado, self.transicoes_a, True, False)), 
                     hash(Estado(nome_estado, self.transicoes_a, True, False)))
    
  def testDoisEstadosSaoIguaisSePossuemMesmoNome(self):
    self.assertEqual(Estado('q2', self.transicoes_a, True, False), 
                     Estado('q2', self.transicoes_a, True, False))
      
  def testDoisEstadosSaoIguaisSePossuemMesmoNomeIndependenteDasTransicoes(self):
    self.assertEqual(Estado('q1', self.transicoes_a, True, False), 
                     Estado('q1', self.transicoes_b, True, True))
  
  def testDoisEstadosSaoIguaisSePossuemMesmoNomeIndependenteSeEhFinalOuInicial(self):
    self.assertEqual(Estado('q1', self.transicoes_a, True, True), 
                     Estado('q1', self.transicoes_a, True, False))
    self.assertEqual(Estado('q1', self.transicoes_a, True, True), 
                     Estado('q1', self.transicoes_a, False, True))
    self.assertEqual(Estado('q1', self.transicoes_a, True, True), 
                     Estado('q1', self.transicoes_a, False, False))
  
  
  def testDoisEstadosNaoSaoIguaisSeNaoPossuemMesmoNome(self):
    self.assertNotEqual(Estado('q1', self.transicoes_a, True, True), 
                        Estado('q2', self.transicoes_a, True, True))
  
  def testSeDoisEstadosNaoPossuemMesmoHashNaoSaoIguais(self):
    self.assertNotEqual(Estado('q1', self.transicoes_a, True, True), 
                        Estado('q2', self.transicoes_a, True, True))
    self.assertNotEqual(hash(Estado('q1', self.transicoes_a, True, True)), 
                        hash(Estado('q2', self.transicoes_a, True, True)))
    
  def testSeDoisEstadosPossuemMesmoHashSaoIguais(self):
    self.assertEqual(Estado('q1', self.transicoes_a, True, True), 
                     Estado('q1', self.transicoes_b, False, False))
    self.assertEqual(hash(Estado('q1', self.transicoes_a, True, True)), 
                     hash(Estado('q1', self.transicoes_b, False, False)))
    
  def testPossueRepresentacaoComoString(self):
    self.assertEqual(str(Estado('q1', self.transicoes_a, False, False)), 
                     str(Estado('q1', self.transicoes_a, False, False)))
    
  def testPodeNaoPossuirTransicoes(self):
    estado = Estado('q1', set(), False, False)
    self.assertEqual(set(), estado.obterTransicoes())
    
    
  def testPodeFornecerAsTransicoesQueExistemParaUmDeterminadoSimbolo(self):
    estado1 = Estado('q1', set([Transicao('a', 'q0'), Transicao('a', 'q1'),Transicao('b', 'q0')]), True, False)
    self.assertEqual(2, len(estado1.obterTransicoesPorSimbolo('a')))
    self.assertTrue(Transicao('a', 'q0') in estado1.obterTransicoesPorSimbolo('a'))
    self.assertTrue(Transicao('a', 'q1') in estado1.obterTransicoesPorSimbolo('a'))
    self.assertEqual(1, len(estado1.obterTransicoesPorSimbolo('b')))
    self.assertTrue(Transicao('b', 'q0') in estado1.obterTransicoesPorSimbolo('b'))
    
  def testSeNaoPossuiUmaTransicaoParaUmDeterminadoSimboloRetornaVazio(self):
    estado1 = Estado('q1', set([Transicao('a', 'q0'), Transicao('a', 'q1'),Transicao('b', 'q0')]), True, False)
    self.assertEqual(set(), estado1.obterTransicoesPorSimbolo('c'))
                     
if(__name__ == "__main__"):  
  suite = unittest.TestSuite()
  suite.addTest(unittest.makeSuite(TesteEstado))
  unittest.TextTestRunner(verbosity=2).run(suite)

  