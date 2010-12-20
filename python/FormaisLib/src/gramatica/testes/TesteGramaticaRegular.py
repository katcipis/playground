'''
Created on 30/10/2009
@author: katcipis
'''
import unittest
from gramatica.testes.TesteAbstratoGramatica import TesteAbstratoGramatica
from gramatica.GramaticaRegular import GramaticaRegular
from gramatica.GramaticaRegular import ErroConstruindoGramaticaRegular
from gramatica.GramaticaLivreContexto import ErroConstruindoGramaticaLivreContexto
from gramatica.Gramatica import ErroConstruindoGramatica
from gramatica.Producao import Producao
from enum.epsilon import EPSILON

class TesteGramaticaRegular(TesteAbstratoGramatica):

  
  def obterGramaticas(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes = set()
    producoes.add(Producao('S', 'aV'))
    producoes.add(Producao('V', 'b'))
    g1 = GramaticaRegular(producoes, vn,vt,s)
    
    vn = set(['T', 'A'])
    vt = set(['d', 'e', 'f'])
    s = 'T'
    producoes = set()
    producoes.add(Producao('T', 'dA'))
    producoes.add(Producao('A', 'e'))
    g2 = GramaticaRegular(producoes, vn,vt,s)
    
    return g1, g2
  

  def testSimboloInicialTemDeEstarNaGramatica(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'T'
    producoes = set()
    producoes.add(Producao('S', 'b'))
    producoes.add(Producao('V', 'a'))
    self.assertRaises(ErroConstruindoGramatica,
                      GramaticaRegular,
                      producoes, vn,vt,s)
    
  def testCriaUmaCopiaDoConjuntoDeNaoTerminaisInformados(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes = set()
    producoes.add(Producao('S', 'aV'))
    producoes.add(Producao('V', 'b'))
    g1 = GramaticaRegular(producoes, vn,vt,s)
    self.assertEqual(vn, g1.obterNaoTerminais())
    vn.pop()
    self.assertNotEqual(vn, g1.obterNaoTerminais())
    
  def testCriaUmaCopiaDoConjuntoDeTerminaisInformados(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes = set()
    producoes.add(Producao('S', 'cV'))
    producoes.add(Producao('V', 'a'))
    g1 = GramaticaRegular(producoes, vn,vt,s)
    self.assertEqual(vt, g1.obterTerminais())
    vt.pop()
    self.assertNotEqual(vt, g1.obterTerminais())
    
  
  def testCriaUmaCopiaDoConjuntoDeProducoesInformados(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes = set()
    producoes.add(Producao('S', 'aV'))
    producoes.add(Producao('V', 'b'))
    g1 = GramaticaRegular(producoes, vn,vt,s)
    self.assertEqual(producoes, g1.obterProducoes())
    producoes.pop()
    self.assertNotEqual(producoes, g1.obterProducoes())
    
  def testAlphaDasProducaosDeveTerTamanhoUm(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes = set()
    producoes.add(Producao('S', 'aV'))
    producoes.add(Producao('V b', 'b'))
    self.assertRaises(ErroConstruindoGramaticaLivreContexto,
                      GramaticaRegular,
                      producoes, vn,vt,s)


  def testOTamanhoDosNaoTerminaisPodeSerMaiorQueUm(self):
    vn = set(['S3', '<NT>'])
    vt = set(['a', 'b', 'c'])
    s = 'S3'
    producoes = set()
    producoes.add(Producao('S3', 'a<NT>'))
    producoes.add(Producao('<NT>', 'b'))
    GramaticaRegular(producoes, vn,vt,s)
  

  def testBetaDasProducaosDeveSerUmTerminalOuUmTerminalSeguidoDeUmNaoTerminal(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes = set()
    producoes.add(Producao('S', 'V'))
    producoes.add(Producao('V', 'b'))
    self.assertRaises(ErroConstruindoGramaticaRegular,
                      GramaticaRegular,
                      producoes, vn,vt,s)
    
    producoes = set()
    producoes.add(Producao('S', 'aV'))
    producoes.add(Producao('V', 'ab'))
    self.assertRaises(ErroConstruindoGramaticaRegular,
                      GramaticaRegular,
                      producoes, vn,vt,s)
    
    producoes = set()
    producoes.add(Producao('S', 'a V b'))
    producoes.add(Producao('V', 'a'))
    self.assertRaises(ErroConstruindoGramaticaRegular,
                      GramaticaRegular,
                      producoes, vn,vt,s)
    
    producoes = set()
    producoes.add(Producao('S', 'S a'))
    producoes.add(Producao('V', 'b'))
    self.assertRaises(ErroConstruindoGramaticaRegular,
                      GramaticaRegular,
                      producoes, vn,vt,s)
    
    producoes = set()
    producoes.add(Producao('S', 'a V S'))
    producoes.add(Producao('V', 'a'))
    self.assertRaises(ErroConstruindoGramaticaRegular,
                      GramaticaRegular,
                      producoes, vn,vt,s)
    
  def testDadoUmNaoTerminalSabeQuaisSaoAsProducoesDesseNaoTerminal(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes_s = set([Producao('S', 'aV'), Producao('S', 'b')])
    producoes_v = set([Producao('V', 'aS'), Producao('V', 'c')])
    producoes = set()
    producoes.update(producoes_s)
    producoes.update(producoes_v)
    
    gramatica = GramaticaRegular(producoes, vn,vt,s)
    self.assertEqual(producoes_s, gramatica.obterProducoesDoAlpha('S'))
    self.assertEqual(producoes_v, gramatica.obterProducoesDoAlpha('V'))
    
  def testDadoUmNaoTerminalQueNaoExisteNaGramaticaSeTentarObterProducoesRetornaConjuntoVazio(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes_s = set([Producao('S', 'aV'), Producao('S', 'b')])
    producoes_v = set([Producao('V', 'aS'), Producao('V', 'c')])
    producoes = set()
    producoes.update(producoes_s)
    producoes.update(producoes_v)
    
    gramatica = GramaticaRegular(producoes, vn,vt,s)
    self.assertEqual(set(), gramatica.obterProducoesDoAlpha('T'))
   
  def testSohPodeTerTransicoesParaEpsilonSeForNoSimboloInicialENaoHouverTransicoesIndoParaOSimboloInicial(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes = set()
    producoes.add(Producao('S', EPSILON))
    producoes.add(Producao('S', 'cV'))
    producoes.add(Producao('V', 'b'))
    producoes.add(Producao('V', 'aS'))
    self.assertRaises(ErroConstruindoGramaticaRegular,
                      GramaticaRegular,
                      producoes, vn,vt,s)
    
    producoes = set()
    producoes.add(Producao('S', EPSILON))
    producoes.add(Producao('S', 'aS'))
    producoes.add(Producao('S', 'bV'))
    producoes.add(Producao('V', 'b'))
    self.assertRaises(ErroConstruindoGramaticaRegular,
                      GramaticaRegular,
                      producoes, vn,vt,s)
    
    producoes = set()
    producoes.add(Producao('S', EPSILON))
    producoes.add(Producao('S', 'aV'))
    producoes.add(Producao('V', 'b'))
    GramaticaRegular(producoes, vn,vt,s)
    
  def testTodosOsNTDasProducoesDevemEstarEmVN(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'T'
    producoes = set()
    producoes.add(Producao('S', 'bV'))
    producoes.add(Producao('V', 'aC'))
    self.assertRaises(ErroConstruindoGramatica,
                      GramaticaRegular,
                      producoes, vn,vt,s)
  
  def testTodosOsTerminaisDasProducoesDevemEstarEmVT(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b'])
    s = 'T'
    producoes = set()
    producoes.add(Producao('S', 'bV'))
    producoes.add(Producao('V', 'd'))
    self.assertRaises(ErroConstruindoGramatica,
                      GramaticaRegular,
                      producoes, vn,vt,s) 
    
  def testNaoEhNecessarioUtilizarEspacoParaSepararOTerminalDoNaoTerminalNoBeta(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes_s = set([Producao('S', 'aV'), Producao('S', 'b')])
    producoes_v = set([Producao('V', 'aS'), Producao('V', 'c')])
    producoes = set()
    producoes.update(producoes_s)
    producoes.update(producoes_v)
    
    GramaticaRegular(producoes, vn,vt,s)
    
  def testSeUtilizarEspacoParaSepararOTerminalDoNaoTerminalNoBetaNaoFazDiferenca(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes_s = set([Producao('S', 'a V'), Producao('S', 'b')])
    producoes_v = set([Producao('V', 'a S'), Producao('V', 'c')])
    producoes = set()
    producoes.update(producoes_s)
    producoes.update(producoes_v)
    
    GramaticaRegular(producoes, vn,vt,s)
    
  def testDuasGramaticasSaoIguaisSePossuemAsMesmasProducoesEMesmoVNEMesmoVTEMesmoSimboloInicial(self):
    vn = set(['S'])
    vt = set(['a', 'b'])
    s = 'S'
  
    producoes = set()
    producoes.add(Producao('S', 'a S'))
    producoes.add(Producao('S', 'b'))
    
    glc1 = GramaticaRegular(producoes, vn,vt,s)
    vn = set(['S'])
    vt = set(['a', 'b'])
    s = 'S'
  
    producoes = set()
    producoes.add(Producao('S', 'a S'))
    producoes.add(Producao('S', 'b'))
    
    glc2 = GramaticaRegular(producoes, vn,vt,s)
    self.assertEqual(glc1, glc2)
    
  
    
if(__name__ == "__main__"):  
  suite = unittest.TestSuite()
  suite.addTest(unittest.makeSuite(TesteGramaticaRegular))
  unittest.TextTestRunner(verbosity=2).run(suite)