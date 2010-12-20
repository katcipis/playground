'''
Created on 30/10/2009
@author: katcipis
'''
import unittest
from gramatica.Gramatica import Gramatica
from gramatica.Producao import Producao
from gramatica.Gramatica import ErroConstruindoGramatica
from gramatica.testes.TesteAbstratoGramatica import TesteAbstratoGramatica
from enum.epsilon import EPSILON

class TesteGramatica(TesteAbstratoGramatica):
  
  def obterGramaticas(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes = set()
    producoes.add(Producao('S', 'V'))
    producoes.add(Producao('V', 'b c S a'))
    g1 = Gramatica(producoes, vn,vt,s)
    
    vn = set(['T', 'A'])
    vt = set(['d', 'e', 'f'])
    s = 'T'
    producoes = set()
    producoes.add(Producao('T', 'd A'))
    producoes.add(Producao('A', 'e'))
    g2 = Gramatica(producoes, vn,vt,s)
    
    return g1, g2
    
  def testInterseccaoDosTerminaisComOsNaoTerminaisDeveSerVazia(self):
    vn = set(['S', 'V', 'c'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes = set()
    producoes.add(Producao('S', 'V'))
    producoes.add(Producao('V', 'V'))
    self.assertRaises(ErroConstruindoGramatica,
                      Gramatica,
                      producoes, vn,vt,s)
    
    
  def testPodeExistirProducaoComAlphaQueExistaNoConjuntoDeNaoTerminaisOuTerminais(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes = set()
    producoes.add(Producao('S', 'V'))
    producoes.add(Producao('V', 'S a'))
    Gramatica(producoes, vn,vt,s)
    
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes = set()
    producoes.add(Producao('S', 'V'))
    producoes.add(Producao('V a', 'V'))
    Gramatica(producoes, vn,vt,s)
    
  def testPodeExistirProducaoComBetaQueExistaNoConjuntoDeNaoTerminaisOuTerminais(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes = set()
    producoes.add(Producao('S', 'V'))
    producoes.add(Producao('V', 'S a V'))
    Gramatica(producoes, vn,vt,s)
    
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes = set()
    producoes.add(Producao('S', 'V'))
    producoes.add(Producao('V a', 'V a c S'))
    Gramatica(producoes, vn,vt,s)
  
  
  def testTerminaisDevemPossuirTamanhoUm(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c d'])
    s = 'S'
    producoes = set()
    producoes.add(Producao('S', 'b'))
    producoes.add(Producao('V a', 'V'))
    self.assertRaises(ErroConstruindoGramatica,
                      Gramatica,
                      producoes, vn,vt,s)

  def testSimboloInicialTemDeEstarNaGramatica(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'T'
    producoes = set()
    producoes.add(Producao('S', 'b'))
    producoes.add(Producao('V a', 'V'))
    self.assertRaises(ErroConstruindoGramatica,
                      Gramatica,
                      producoes, vn,vt,s)
    
  def testCriaUmaCopiaDoConjuntoDeNaoTerminaisInformados(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes = set()
    producoes.add(Producao('S', 'V'))
    producoes.add(Producao('V', 'b c S a'))
    g1 = Gramatica(producoes, vn,vt,s)
    self.assertEqual(vn, g1.obterNaoTerminais())
    vn.pop()
    self.assertNotEqual(vn, g1.obterNaoTerminais())
    
  def testCriaUmaCopiaDoConjuntoDeTerminaisInformados(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes = set()
    producoes.add(Producao('S', 'V'))
    producoes.add(Producao('V', 'b c S a'))
    g1 = Gramatica(producoes, vn,vt,s)
    self.assertEqual(vt, g1.obterTerminais())
    vt.pop()
    self.assertNotEqual(vt, g1.obterTerminais())
    
  
  def testCriaUmaCopiaDoConjuntoDeProducoesInformados(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes = set()
    producoes.add(Producao('S', 'V'))
    producoes.add(Producao('V', 'b c S a'))
    g1 = Gramatica(producoes, vn,vt,s)
    self.assertEqual(producoes, g1.obterProducoes())
    producoes.pop()
    self.assertNotEqual(producoes, g1.obterProducoes())
    
  def testDadoUmAlphaSabeQuaisSaoAsProducoesDesseNaoTerminal(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes_s = set([Producao('S', 'a V'), Producao('S', 'b')])
    producoes_bv = set([Producao('b V', 'a S'), Producao('b V', 'c')])
    producoes = set()
    producoes.update(producoes_s)
    producoes.update(producoes_bv)
    
    gramatica = Gramatica(producoes, vn,vt,s)
    self.assertEqual(producoes_s, gramatica.obterProducoesDoAlpha('S'))
    self.assertEqual(producoes_bv, gramatica.obterProducoesDoAlpha('b V'))
    
  def testDadoUmAlphaSabeQuaisSaoAsProducoesDesseNaoTerminalIndependenteDeQuantosEspacos(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes_s = set([Producao('S', 'a V'), Producao('S', 'b')])
    producoes_bv = set([Producao('b V', 'a S'), Producao('b V', 'c')])
    producoes = set()
    producoes.update(producoes_s)
    producoes.update(producoes_bv)
    
    gramatica = Gramatica(producoes, vn,vt,s)
    self.assertEqual(producoes_s, gramatica.obterProducoesDoAlpha('S'))
    self.assertEqual(producoes_bv, gramatica.obterProducoesDoAlpha('b  V'))
    
  def testDadoUmAlphaQueNaoExisteNaGramaticaSeTentarObterProducoesRetornaConjuntoVazio(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes_s = set([Producao('S', 'a V'), Producao('S', 'b')])
    producoes_v = set([Producao('V', 'a S'), Producao('V', 'c')])
    producoes = set()
    producoes.update(producoes_s)
    producoes.update(producoes_v)
    
    gramatica = Gramatica(producoes, vn,vt,s)
    self.assertEqual(set(), gramatica.obterProducoesDoAlpha('T'))
    
    
  def testNoAlphaDasProducoesDeveExistirEspacoEntreCadaTerminalENaoTerminalSenaoEhConsideradoUmNaoTerminalInteiro(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes_s = set([Producao('S', 'a V'), Producao('S', 'b')])
    producoes_v = set([Producao('aV', 'a'), Producao('V', 'c')])
    producoes = set()
    producoes.update(producoes_s)
    producoes.update(producoes_v)
    
    self.assertRaises(ErroConstruindoGramatica,
                      Gramatica,
                      producoes, vn,vt,s)

    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes_s = set([Producao('S', 'a V'), Producao('S', 'b')])
    producoes_v = set([Producao('a V', 'a'), Producao('V', 'c')])
    producoes = set()
    producoes.update(producoes_s)
    producoes.update(producoes_v)
    Gramatica(producoes, vn,vt,s)
    
    
  def testNoAlphaDasProducoesDeveExistirEspacoEntreCadaNaoTerminalSenaoEhConsideradoUmNaoTerminalInteiro(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes_s = set([Producao('S', 'a V'), Producao('S', 'b')])
    producoes_v = set([Producao('aV', 'S'), Producao('V', 'c')])
    producoes = set()
    producoes.update(producoes_s)
    producoes.update(producoes_v)
    
    self.assertRaises(ErroConstruindoGramatica,
                      Gramatica,
                      producoes, vn,vt,s)
    
    vn = set(['VS', 'SV', 'S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes_s = set([Producao('S', 'a V'), Producao('S', 'b')])
    producoes_v = set([Producao('a V', 'S'), Producao('V', 'c')])
    producoes = set()
    producoes.update(producoes_s)
    producoes.update(producoes_v)
    Gramatica(producoes, vn,vt,s)
    
    
  def testNoBetaDasProducoesDeveExistirEspacoEntreCadaTerminalENaoTerminalSenaoEhConsideradoUmNaoTerminalInteiro(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes_s = set([Producao('S', 'aV'), Producao('S', 'b')])
    producoes_v = set([Producao('V', 'aS'), Producao('V', 'c')])
    producoes = set()
    producoes.update(producoes_s)
    producoes.update(producoes_v)
    
    self.assertRaises(ErroConstruindoGramatica,
                      Gramatica,
                      producoes, vn,vt,s)
    
    vn = set(['aV', 'aS', 'S', 'V'])
    vt = set(['b', 'c'])
    s = 'S'
    producoes_s = set([Producao('S', 'aV'), Producao('S', 'b')])
    producoes_v = set([Producao('V', 'aS'), Producao('V', 'c')])
    producoes = set()
    producoes.update(producoes_s)
    producoes.update(producoes_v)
    Gramatica(producoes, vn,vt,s)
    
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes_s = set([Producao('S', 'a V'), Producao('S', 'b')])
    producoes_v = set([Producao('V', 'a S'), Producao('V', 'c')])
    producoes = set()
    producoes.update(producoes_s)
    producoes.update(producoes_v)
    Gramatica(producoes, vn,vt,s)
    
    
  def testNoBetaDasProducoesDeveExistirEspacoEntreCadaTerminalSenaoEhConsideradoUmNaoTerminalInteiro(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes_s = set([Producao('S', 'ab'), Producao('S', 'b')])
    producoes_v = set([Producao('V', 'ac'), Producao('V', 'c')])
    producoes = set()
    producoes.update(producoes_s)
    producoes.update(producoes_v)
    
    self.assertRaises(ErroConstruindoGramatica,
                      Gramatica,
                      producoes, vn,vt,s)
    
    vn = set(['ac', 'ab', 'S', 'V'])
    vt = set(['b', 'c'])
    s = 'S'
    producoes_s = set([Producao('S', 'ab'), Producao('S', 'b')])
    producoes_v = set([Producao('V', 'ac'), Producao('V', 'c')])
    producoes = set()
    producoes.update(producoes_s)
    producoes.update(producoes_v)
    Gramatica(producoes, vn,vt,s)
    
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes_s = set([Producao('S', 'a b'), Producao('S', 'b')])
    producoes_v = set([Producao('V', 'a c'), Producao('V', 'c')])
    producoes = set()
    producoes.update(producoes_s)
    producoes.update(producoes_v)
    Gramatica(producoes, vn,vt,s)
    
    
  def testNoBetaDasProducoesDeveExistirEspacoEntreCadaNaoTerminalSenaoEhConsideradoUmNaoTerminalInteiro(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes_s = set([Producao('S', 'SV'), Producao('S', 'b')])
    producoes_v = set([Producao('V', 'VS'), Producao('V', 'c')])
    producoes = set()
    producoes.update(producoes_s)
    producoes.update(producoes_v)
    
    self.assertRaises(ErroConstruindoGramatica,
                      Gramatica,
                      producoes, vn,vt,s)
    
    vn = set(['VS', 'SV', 'S', 'V'])
    vt = set(['b', 'c'])
    s = 'S'
    producoes_s = set([Producao('S', 'SV'), Producao('S', 'b')])
    producoes_v = set([Producao('V', 'VS'), Producao('V', 'c')])
    producoes = set()
    producoes.update(producoes_s)
    producoes.update(producoes_v)
    Gramatica(producoes, vn,vt,s)
    
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes_s = set([Producao('S', 'S V'), Producao('S', 'b')])
    producoes_v = set([Producao('V', 'V S'), Producao('V', 'c')])
    producoes = set()
    producoes.update(producoes_s)
    producoes.update(producoes_v)
    Gramatica(producoes, vn,vt,s)
    
    
  def testTodosOsNTDasProducoesDevemEstarEmVN(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'T'
    producoes = set()
    producoes.add(Producao('S', 'b V c'))
    producoes.add(Producao('V', 'a C b'))
    self.assertRaises(ErroConstruindoGramatica,
                      Gramatica,
                      producoes, vn,vt,s)
  
  def testTodosOsTerminaisDasProducoesDevemEstarEmVT(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b'])
    s = 'T'
    producoes = set()
    producoes.add(Producao('S', 'b V a'))
    producoes.add(Producao('V', 'd'))
    self.assertRaises(ErroConstruindoGramatica,
                      Gramatica,
                      producoes, vn,vt,s)
    
  def testDuasGramaticasSaoIguaisSePossuemAsMesmasProducoesEMesmoVNEMesmoVTEMesmoSimboloInicial(self):
    vn = set(['S'])
    vt = set(['a', 'b'])
    s = 'S'
  
    producoes = set()
    producoes.add(Producao('S', 'a S b'))
    producoes.add(Producao('S', EPSILON))
    
    glc1 = Gramatica(producoes, vn,vt,s)
    vn = set(['S'])
    vt = set(['a', 'b'])
    s = 'S'
  
    producoes = set()
    producoes.add(Producao('S', 'a S b'))
    producoes.add(Producao('S', EPSILON))
    
    glc2 = Gramatica(producoes, vn,vt,s)
    self.assertEqual(glc1, glc2)
    
  def testDuasGramaticasNaoSaoIguaisSeNaoPossuemAsMesmasProducoes(self):
    vn = set(['S'])
    vt = set(['a', 'b'])
    s = 'S'
  
    producoes = set()
    producoes.add(Producao('S', 'a S b'))
    producoes.add(Producao('S', EPSILON))
    
    glc1 = Gramatica(producoes, vn,vt,s)
    vn = set(['S'])
    vt = set(['a', 'b'])
    s = 'S'
  
    producoes = set()
    producoes.add(Producao('S', 'a S b S'))
    producoes.add(Producao('S', EPSILON))
    
    glc2 = Gramatica(producoes, vn,vt,s)
    self.assertNotEqual(glc1, glc2)
    
  def testDuasGramaticasNaoSaoIguaisSeNaoPossuemMesmoVN(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b'])
    s = 'S'
  
    producoes = set()
    producoes.add(Producao('S', 'a S b'))
    producoes.add(Producao('S', EPSILON))
    
    glc1 = Gramatica(producoes, vn,vt,s)
    vn = set(['S'])
    vt = set(['a', 'b'])
    s = 'S'
  
    producoes = set()
    producoes.add(Producao('S', 'a S b'))
    producoes.add(Producao('S', EPSILON))
    
    glc2 = Gramatica(producoes, vn,vt,s)
    self.assertNotEqual(glc1, glc2)
    
  def testDuasGramaticasNaoSaoIguaisSeNaoPossuemMesmoVT(self):
    vn = set(['S'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
  
    producoes = set()
    producoes.add(Producao('S', 'a S b'))
    producoes.add(Producao('S', EPSILON))
    
    glc1 = Gramatica(producoes, vn,vt,s)
    vn = set(['S'])
    vt = set(['a', 'b'])
    s = 'S'
  
    producoes = set()
    producoes.add(Producao('S', 'a S b'))
    producoes.add(Producao('S', EPSILON))
    
    glc2 = Gramatica(producoes, vn,vt,s)
    self.assertNotEqual(glc1, glc2)
    
  def testDuasGramaticasNaoSaoIguaisSeNaoPossuemSimboloInicial(self):
    vn = set(['S', 'C'])
    vt = set(['a', 'b'])
    s = 'C'
  
    producoes = set()
    producoes.add(Producao('S', 'a S b'))
    producoes.add(Producao('S', EPSILON))
    
    glc1 = Gramatica(producoes, vn,vt,s)
    vn = set(['S', 'C'])
    vt = set(['a', 'b'])
    s = 'S'
  
    producoes = set()
    producoes.add(Producao('S', 'a S b'))
    producoes.add(Producao('S', EPSILON))
    
    glc2 = Gramatica(producoes, vn,vt,s)
    self.assertNotEqual(glc1, glc2)
    
    
  def testDadoUmaProducaoDaGramaticaSeNaoPossuiNaoTerminaisNoBetaRetornaVazioAoTentarObtelos(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
  
    producoes = set()
    producoes.add(Producao('S', 'a S V b'))
    producoes.add(Producao('S', EPSILON))
    
    glc1 = Gramatica(producoes, vn,vt,s)
    self.assertEqual(set(), glc1.obterNaoTerminaisDoBeta(Producao('S', EPSILON)))
    
  def testDadoUmaProducaoQueNaoEhDaGramaticaRetornaNoneAoTentarObterNaoTerminaisDoBeta(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
  
    producoes = set()
    producoes.add(Producao('S', 'a S V b'))
    producoes.add(Producao('S', EPSILON))
    
    glc1 = Gramatica(producoes, vn,vt,s)
    self.assertEqual(None, glc1.obterNaoTerminaisDoBeta(Producao('S', 'S V b')))
    
    
  def testDadoUmaProducaoDaGramaticaSabeInformarQuaisSaoOsNaoTerminaisExistentesNoBeta(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
  
    producoes = set()
    producoes.add(Producao('S', 'a S V b'))
    producoes.add(Producao('S', EPSILON))
    
    glc1 = Gramatica(producoes, vn,vt,s)
    self.assertEqual(set(['S','V']), glc1.obterNaoTerminaisDoBeta(Producao('S', 'a S V b')))
    
  def testDadoUmaProducaoDaGramaticaSeNaoPossuiTerminaisNoBetaRetornaVazioAoTentarObtelos(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
  
    producoes = set()
    producoes.add(Producao('S', 'S V'))
    producoes.add(Producao('S', EPSILON))
    
    glc1 = Gramatica(producoes, vn,vt,s)
    self.assertEqual(set(), glc1.obterTerminaisDoBeta(Producao('S', 'S V')))
    
  def testDadoUmaProducaoQueNaoEhDaGramaticaRetornaNoneAoTentarObterTerminaisDoBeta(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
  
    producoes = set()
    producoes.add(Producao('S', 'a S V b'))
    producoes.add(Producao('S', EPSILON))
    
    glc1 = Gramatica(producoes, vn,vt,s)
    self.assertEqual(None, glc1.obterTerminaisDoBeta(Producao('S', 'S V b')))
    
    
  def testDadoUmaProducaoDaGramaticaSabeInformarQuaisSaoOsTerminaisExistentesNoBeta(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
  
    producoes = set()
    producoes.add(Producao('S', 'a S V b'))
    producoes.add(Producao('S', EPSILON))
    
    glc1 = Gramatica(producoes, vn,vt,s)
    self.assertEqual(set(['a','b']), glc1.obterTerminaisDoBeta(Producao('S', 'a S V b')))
    
    
if(__name__ == "__main__"):  
  suite = unittest.TestSuite()
  suite.addTest(unittest.makeSuite(TesteGramatica))
  unittest.TextTestRunner(verbosity=2).run(suite)
