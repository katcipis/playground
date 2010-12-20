'''
Created on 17/11/2009
@author: katcipis
'''
import unittest
from gramatica.testes.construtor_gramaticas import construirGLCComABOndeNumAsEhIgualNumBsSemSimbolosInuteis
from gramatica.testes.construtor_gramaticas import construirGLCExpAritmeticaComRecEsquerdaDireta
from gramatica.testes.construtor_gramaticas import construirGLCExpAritmeticaSemRecEsquerda
from gramatica.testes.construtor_gramaticas import construirGLCComRecEsquerdaIndireta
from gramatica.testes.construtor_gramaticas import construirGLCQueNaoProduzEpsilon
from gramatica.testes.construtor_gramaticas import construirGLCTesteFirst
from gramatica.testes.construtor_gramaticas import construirTodosFirstDaGLCDoTesteFirst
from gramatica.testes.construtor_gramaticas import construirGLCTesteFollow
from gramatica.testes.construtor_gramaticas import construirTodosFollowsDaGLCDoTesteFollow
from gramatica.testes.construtor_gramaticas import construirGLCComNaoFatoracaoDiretaFatorada
from gramatica.testes.construtor_gramaticas import construirGLCComNaoFatoracaoDireta
from gramatica.testes.construtor_gramaticas import construirGLCComNaoFatoracaoIndireta
from gramatica.testes.TesteAbstratoGramatica import TesteAbstratoGramatica
from gramatica.GramaticaLivreContexto import GramaticaLivreContexto
from gramatica.GramaticaLivreContexto import ErroConstruindoGramaticaLivreContexto
from gramatica.Gramatica import ErroConstruindoGramatica
from gramatica.testes.construtor_gramaticas import construirGLCComCiclo
from gramatica.testes.construtor_gramaticas import construirGLCSemCiclo
from gramatica.Producao import Producao
from enum.epsilon import EPSILON

class TesteGramaticaLivreContexto(TesteAbstratoGramatica):

  def obterGramaticas(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes = set()
    producoes.add(Producao('S', 'a V'))
    producoes.add(Producao('V', 'b'))
    g1 = GramaticaLivreContexto(producoes, vn,vt,s)
    
    vn = set(['T', 'A'])
    vt = set(['d', 'e', 'f'])
    s = 'T'
    producoes = set()
    producoes.add(Producao('T', 'd A'))
    producoes.add(Producao('A', 'e'))
    g2 = GramaticaLivreContexto(producoes, vn,vt,s)
    
    return g1, g2
  
  def testNoBetaDasProducoesDeveExistirEspacoEntreCadaTerminalENaoTerminalSenaoEhConsideradoUmNaoTerminalInteiro(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes_s = set([Producao('S', 'aVbV'), Producao('S', 'b')])
    producoes_v = set([Producao('V', 'aSaS'), Producao('V', 'c')])
    producoes = set()
    producoes.update(producoes_s)
    producoes.update(producoes_v)
    
    self.assertRaises(ErroConstruindoGramatica,
                      GramaticaLivreContexto,
                      producoes, vn,vt,s)
    
    vn = set(['aV', 'aSaS', 'S', 'V'])
    vt = set(['b', 'c'])
    s = 'S'
    producoes_s = set([Producao('S', 'aV'), Producao('S', 'b')])
    producoes_v = set([Producao('V', 'aSaS'), Producao('V', 'c')])
    producoes = set()
    producoes.update(producoes_s)
    producoes.update(producoes_v)
    GramaticaLivreContexto(producoes, vn,vt,s)
    
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes_s = set([Producao('S', 'a V b V'), Producao('S', 'b')])
    producoes_v = set([Producao('V', 'a S a S'), Producao('V', 'c')])
    producoes = set()
    producoes.update(producoes_s)
    producoes.update(producoes_v)
    GramaticaLivreContexto(producoes, vn,vt,s)
    
  
  def testNoBetaDasProducoesDeveExistirEspacoEntreCadaTerminalSenaoEhConsideradoUmNaoTerminalInteiro(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes_s = set([Producao('S', 'aba'), Producao('S', 'b')])
    producoes_v = set([Producao('V', 'ac'), Producao('V', 'c')])
    producoes = set()
    producoes.update(producoes_s)
    producoes.update(producoes_v)
    
    self.assertRaises(ErroConstruindoGramatica,
                      GramaticaLivreContexto,
                      producoes, vn,vt,s)
    
    vn = set(['ac', 'ab', 'S', 'V'])
    vt = set(['b', 'c'])
    s = 'S'
    producoes_s = set([Producao('S', 'ab'), Producao('S', 'b')])
    producoes_v = set([Producao('V', 'ac'), Producao('V', 'c')])
    producoes = set()
    producoes.update(producoes_s)
    producoes.update(producoes_v)
    GramaticaLivreContexto(producoes, vn,vt,s)
    
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes_s = set([Producao('S', 'a b'), Producao('S', 'b')])
    producoes_v = set([Producao('V', 'a c'), Producao('V', 'c')])
    producoes = set()
    producoes.update(producoes_s)
    producoes.update(producoes_v)
    GramaticaLivreContexto(producoes, vn,vt,s)

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
                      GramaticaLivreContexto,
                      producoes, vn,vt,s)
    
    vn = set(['VS', 'SV', 'S', 'V'])
    vt = set(['b', 'c'])
    s = 'S'
    producoes_s = set([Producao('S', 'SV'), Producao('S', 'b')])
    producoes_v = set([Producao('V', 'VS'), Producao('V', 'c')])
    producoes = set()
    producoes.update(producoes_s)
    producoes.update(producoes_v)
    GramaticaLivreContexto(producoes, vn,vt,s)
    
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes_s = set([Producao('S', 'S V'), Producao('S', 'b')])
    producoes_v = set([Producao('V', 'V S'), Producao('V', 'c')])
    producoes = set()
    producoes.update(producoes_s)
    producoes.update(producoes_v)
    GramaticaLivreContexto(producoes, vn,vt,s)

  def testSimboloInicialTemDeEstarNaGramatica(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'T'
    producoes = set()
    producoes.add(Producao('S', 'b'))
    producoes.add(Producao('V', 'a'))
    self.assertRaises(ErroConstruindoGramatica,
                      GramaticaLivreContexto,
                      producoes, vn,vt,s)
    
  def testCriaUmaCopiaDoConjuntoDeNaoTerminaisInformados(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes = set()
    producoes.add(Producao('S', 'a V S V c'))
    producoes.add(Producao('V', 'b'))
    g1 = GramaticaLivreContexto(producoes, vn,vt,s)
    self.assertEqual(vn, g1.obterNaoTerminais())
    vn.pop()
    self.assertNotEqual(vn, g1.obterNaoTerminais())
    
  def testCriaUmaCopiaDoConjuntoDeTerminaisInformados(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes = set()
    producoes.add(Producao('S', 'c V b c'))
    producoes.add(Producao('V', 'a'))
    g1 = GramaticaLivreContexto(producoes, vn,vt,s)
    self.assertEqual(vt, g1.obterTerminais())
    vt.pop()
    self.assertNotEqual(vt, g1.obterTerminais())
    
  
  def testCriaUmaCopiaDoConjuntoDeProducoesInformados(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes = set()
    producoes.add(Producao('S', 'a V c a b V'))
    producoes.add(Producao('V', 'b'))
    g1 = GramaticaLivreContexto(producoes, vn,vt,s)
    self.assertEqual(producoes, g1.obterProducoes())
    producoes.pop()
    self.assertNotEqual(producoes, g1.obterProducoes())
    
    
  def testAlphaDasProducaosDeveTerTamanhoUm(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes = set()
    producoes.add(Producao('S', 'a V'))
    producoes.add(Producao('V b', 'b'))
    self.assertRaises(ErroConstruindoGramaticaLivreContexto,
                      GramaticaLivreContexto,
                      producoes, vn,vt,s)


  def testOTamanhoDosNaoTerminaisPodeSerMaiorQueUm(self):
    vn = set(['S3', '<NT>'])
    vt = set(['a', 'b', 'c'])
    s = 'S3'
    producoes = set()
    producoes.add(Producao('S3', 'a <NT>'))
    producoes.add(Producao('<NT>', 'b'))
    GramaticaLivreContexto(producoes, vn,vt,s)
      
      
  def testDadoUmNaoTerminalSabeQuaisSaoAsProducoesDesseNaoTerminal(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes_s = set([Producao('S', 'a V'), Producao('S', 'b')])
    producoes_v = set([Producao('V', 'a S'), Producao('V', 'c')])
    producoes = set()
    producoes.update(producoes_s)
    producoes.update(producoes_v)
    
    gramatica = GramaticaLivreContexto(producoes, vn,vt,s)
    self.assertEqual(producoes_s, gramatica.obterProducoesDoAlpha('S'))
    self.assertEqual(producoes_v, gramatica.obterProducoesDoAlpha('V'))
    
  def testDadoUmNaoTerminalQueNaoExisteNaGramaticaSeTentarObterProducoesRetornaConjuntoVazio(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes_s = set([Producao('S', 'a V'), Producao('S', 'b')])
    producoes_v = set([Producao('V', 'a S'), Producao('V', 'c')])
    producoes = set()
    producoes.update(producoes_s)
    producoes.update(producoes_v)
    
    gramatica = GramaticaLivreContexto(producoes, vn,vt,s)
    self.assertEqual(set(), gramatica.obterProducoesDoAlpha('T'))
   
    
  def testTodosOsNTDasProducoesDevemEstarEmVN(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'T'
    producoes = set()
    producoes.add(Producao('S', 'b V'))
    producoes.add(Producao('V', 'a C b V'))
    self.assertRaises(ErroConstruindoGramatica,
                      GramaticaLivreContexto,
                      producoes, vn,vt,s)
  
  
  def testTodosOsTerminaisDasProducoesDevemEstarEmVT(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b'])
    s = 'T'
    producoes = set()
    producoes.add(Producao('S', 'b V V a'))
    producoes.add(Producao('V', 'd'))
    self.assertRaises(ErroConstruindoGramatica,
                      GramaticaLivreContexto,
                      producoes, vn,vt,s) 
    
    
  def testBetaPodeSerQualquerCoisaQueEstejaNaUniaoEntreVTeVN(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes_s = set([Producao('S', 'a V c S a'), Producao('S', 'V')])
    producoes_v = set([Producao('V', 'a S b V'), Producao('V', 'a')])
    producoes = set()
    producoes.update(producoes_s)
    producoes.update(producoes_v)
    
    GramaticaLivreContexto(producoes, vn,vt,s)
  
  
  def testBetaPodeSerEpsilon(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes_s = set([Producao('S', 'a V c S a'), Producao('S', EPSILON)])
    producoes_v = set([Producao('V', 'a S b V'), Producao('V', EPSILON)])
    producoes = set()
    producoes.update(producoes_s)
    producoes.update(producoes_v)
    
    GramaticaLivreContexto(producoes, vn,vt,s)
    
    
  def testDuasGramaticasSaoIguaisSePossuemAsMesmasProducoesEMesmoVNEMesmoVTEMesmoSimboloInicial(self):
    self.assertEqual(construirGLCComABOndeNumAsEhIgualNumBsSemSimbolosInuteis(),
                     construirGLCComABOndeNumAsEhIgualNumBsSemSimbolosInuteis())
    
  def testDuasGramaticasNaoSaoIguaisSeNaoPossuemAsMesmasProducoes(self):
    vn = set(['S'])
    vt = set(['a', 'b'])
    s = 'S'
  
    producoes = set()
    producoes.add(Producao('S', 'a S b'))
    producoes.add(Producao('S', EPSILON))
    
    glc1 = GramaticaLivreContexto(producoes, vn,vt,s)
    vn = set(['S'])
    vt = set(['a', 'b'])
    s = 'S'
  
    producoes = set()
    producoes.add(Producao('S', 'a S b S'))
    producoes.add(Producao('S', EPSILON))
    
    glc2 = GramaticaLivreContexto(producoes, vn,vt,s)
    self.assertNotEqual(glc1, glc2)
    
  def testDuasGramaticasNaoSaoIguaisSeNaoPossuemMesmoVN(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b'])
    s = 'S'
  
    producoes = set()
    producoes.add(Producao('S', 'a S b'))
    producoes.add(Producao('S', EPSILON))
    
    glc1 = GramaticaLivreContexto(producoes, vn,vt,s)
    vn = set(['S'])
    vt = set(['a', 'b'])
    s = 'S'
  
    producoes = set()
    producoes.add(Producao('S', 'a S b'))
    producoes.add(Producao('S', EPSILON))
    
    glc2 = GramaticaLivreContexto(producoes, vn,vt,s)
    self.assertNotEqual(glc1, glc2)
    
  def testDuasGramaticasNaoSaoIguaisSeNaoPossuemMesmoVT(self):
    vn = set(['S'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
  
    producoes = set()
    producoes.add(Producao('S', 'a S b'))
    producoes.add(Producao('S', EPSILON))
    
    glc1 = GramaticaLivreContexto(producoes, vn,vt,s)
    vn = set(['S'])
    vt = set(['a', 'b'])
    s = 'S'
  
    producoes = set()
    producoes.add(Producao('S', 'a S b'))
    producoes.add(Producao('S', EPSILON))
    
    glc2 = GramaticaLivreContexto(producoes, vn,vt,s)
    self.assertNotEqual(glc1, glc2)
    
  def testDuasGramaticasNaoSaoIguaisSeNaoPossuemSimboloInicial(self):
    vn = set(['S', 'C'])
    vt = set(['a', 'b'])
    s = 'C'
  
    producoes = set()
    producoes.add(Producao('S', 'a S b'))
    producoes.add(Producao('S', EPSILON))
    
    glc1 = GramaticaLivreContexto(producoes, vn,vt,s)
    vn = set(['S', 'C'])
    vt = set(['a', 'b'])
    s = 'S'
  
    producoes = set()
    producoes.add(Producao('S', 'a S b'))
    producoes.add(Producao('S', EPSILON))
    
    glc2 = GramaticaLivreContexto(producoes, vn,vt,s)
    self.assertNotEqual(glc1, glc2)
    
  def testDadoUmaProducaoDaGramaticaSeNaoPossuiTerminaisNoBetaRetornaVazioAoTentarObtelos(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
  
    producoes = set()
    producoes.add(Producao('S', 'S V'))
    producoes.add(Producao('S', EPSILON))
    
    glc1 = GramaticaLivreContexto(producoes, vn,vt,s)
    self.assertEqual(set(), glc1.obterTerminaisDoBeta(Producao('S', 'S V')))
    
  def testDadoUmaProducaoQueNaoEhDaGramaticaRetornaNoneAoTentarObterTerminaisDoBeta(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
  
    producoes = set()
    producoes.add(Producao('S', 'a S V b'))
    producoes.add(Producao('S', EPSILON))
    
    glc1 = GramaticaLivreContexto(producoes, vn,vt,s)
    self.assertEqual(None, glc1.obterTerminaisDoBeta(Producao('S', 'S V b')))
    
    
  def testDadoUmaProducaoDaGramaticaSabeInformarQuaisSaoOsTerminaisExistentesNoBeta(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
  
    producoes = set()
    producoes.add(Producao('S', 'a S V b'))
    producoes.add(Producao('S', EPSILON))
    
    glc1 = GramaticaLivreContexto(producoes, vn,vt,s)
    self.assertEqual(set(['a','b']), glc1.obterTerminaisDoBeta(Producao('S', 'a S V b')))
    
  def testDadoUmaProducaoDaGramaticaSeNaoPossuiNaoTerminaisNoBetaRetornaVazioAoTentarObtelos(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
  
    producoes = set()
    producoes.add(Producao('S', 'a S V b'))
    producoes.add(Producao('S', EPSILON))
    
    glc1 = GramaticaLivreContexto(producoes, vn,vt,s)
    self.assertEqual(set(), glc1.obterNaoTerminaisDoBeta(Producao('S', EPSILON)))
    
  def testDadoUmaProducaoQueNaoEhDaGramaticaRetornaNoneAoTentarObterNaoTerminaisDoBeta(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
  
    producoes = set()
    producoes.add(Producao('S', 'a S V b'))
    producoes.add(Producao('S', EPSILON))
    
    glc1 = GramaticaLivreContexto(producoes, vn,vt,s)
    self.assertEqual(None, glc1.obterNaoTerminaisDoBeta(Producao('S', 'S V b')))
    
    
  def testDadoUmaProducaoDaGramaticaSabeInformarQuaisSaoOsNaoTerminaisExistentesNoBeta(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
  
    producoes = set()
    producoes.add(Producao('S', 'a S V b'))
    producoes.add(Producao('S', EPSILON))
    
    glc1 = GramaticaLivreContexto(producoes, vn,vt,s)
    self.assertEqual(set(['S','V']), glc1.obterNaoTerminaisDoBeta(Producao('S', 'a S V b')))
    
    
  def testSabeSePossuiCiclos(self):
    self.assertTrue(construirGLCComCiclo().possuiCiclo())
    
    
  def testSabeSeNaoPossuiCiclos(self):
    self.assertFalse(construirGLCSemCiclo().possuiCiclo())
    
    
  def testSabeQuaisNaoTerminaisDerivamEpsilonDiretamente(self):
    vn = set(['S'])
    vt = set(['a', 'b'])
    s = 'S'
  
    producoes = set()
    producoes.add(Producao('S', 'a S b'))
    producoes.add(Producao('S', EPSILON))
    producoes.add(Producao('S', 'b S a'))
    
    glc = GramaticaLivreContexto(producoes, vn,vt,s)
    self.assertEqual(set(['S']), glc.obterNaoTerminaisQueDerivamEpsilon())
    
  
  def testSabeQuaisNaoTerminaisDerivamEpsilonIndiretamente(self):
    vn = set(['S', 'A', 'B'])
    vt = set(['a', 'b'])
    s = 'S'
  
    producoes = set()
    producoes.add(Producao('S', 'a S b'))
    producoes.add(Producao('S', 'A B'))
    producoes.add(Producao('S', 'b S a'))
    
    producoes.add(Producao('A', EPSILON))
    
    producoes.add(Producao('B', EPSILON))
    producoes.add(Producao('B', 'b'))
    
    glc = GramaticaLivreContexto(producoes, vn,vt,s)
    self.assertEqual(set(['S', 'A', 'B']), glc.obterNaoTerminaisQueDerivamEpsilon())
  
  
  def testSabeQuandoNaoDerivaEpsilon(self):
    self.assertEqual(set(), construirGLCExpAritmeticaComRecEsquerdaDireta().obterNaoTerminaisQueDerivamEpsilon())
    self.assertEqual(set(), construirGLCComRecEsquerdaIndireta().obterNaoTerminaisQueDerivamEpsilon())
    self.assertEqual(set(), construirGLCQueNaoProduzEpsilon().obterNaoTerminaisQueDerivamEpsilon())
    
  def testDadoUmNaoTerminalSabeQualOSeuConjuntoFollow(self):
    glc = construirGLCTesteFollow()
    follows = construirTodosFollowsDaGLCDoTesteFollow()
    for nao_terminal in follows:
      self.assertEqual(glc.obterFollow(nao_terminal), follows[nao_terminal])
  
  
  def testDadoUmNaoTerminalSabeQualNaoEhOSeuConjuntoFollow(self):
    glc = construirGLCTesteFirst()
    follows = construirTodosFollowsDaGLCDoTesteFollow()
    for nao_terminal in follows:
      follows[nao_terminal].pop()
      self.assertNotEqual(glc.obterFollow(nao_terminal), follows[nao_terminal])
  
  
  def testDadoUmNaoTerminalQueNaoExisteOSeuConjuntoFollowEhNone(self):
    vn = set(['S'])
    vt = set(['a', 'b'])
    s = 'S'
  
    producoes = set()
    producoes.add(Producao('S', 'a b'))
    self.assertEqual(None, GramaticaLivreContexto(producoes, vn,vt,s).obterFollow('A'))
  
  def testDadoUmNaoTerminalSabeQualOSeuConjuntoFirst(self):
    glc = construirGLCTesteFirst()
    firsts = construirTodosFirstDaGLCDoTesteFirst()
    for nao_terminal in firsts:
      self.assertEqual(glc.obterFirst(nao_terminal), firsts[nao_terminal])
  
  
  def testDadoUmTerminalSeuConjuntoFirstEhSomenteOTerminal(self):
    glc = construirGLCTesteFirst()
    
    for terminal in glc.obterTerminais():
      self.assertEqual(set([terminal]), glc.obterFirst(terminal))
      
      
  def testOConjuntoFirstDoEpsilonEhOProprioEpsilon(self):
    glc = construirGLCTesteFirst()
    self.assertEqual(set([EPSILON]), glc.obterFirst(EPSILON))
      
      
  def testDadoUmTerminalSeEleNaoExisteNaGramaticaOFirstRetornaNone(self):
    vn = set(['S'])
    vt = set(['a', 'b'])
    s = 'S'
  
    producoes = set()
    producoes.add(Producao('S', 'a b'))
    glc = GramaticaLivreContexto(producoes, vn,vt,s)
    self.assertEqual(None, glc.obterFirst('c'))
    self.assertEqual(None, glc.obterFirst('d')) 
  
  
  def testDadoUmNaoTerminalSabeQualNaoEhOSeuConjuntoFirst(self):
    glc = construirGLCTesteFirst()
    firsts = construirTodosFirstDaGLCDoTesteFirst()
    for nao_terminal in firsts:
      firsts[nao_terminal].pop()
      self.assertNotEqual(glc.obterFirst(nao_terminal), firsts[nao_terminal])
  
  
  def testDadoUmNaoTerminalQueNaoExisteOSeuConjuntoFirstEhNone(self):
    vn = set(['S'])
    vt = set(['a', 'b'])
    s = 'S'
  
    producoes = set()
    producoes.add(Producao('S', 'a b'))
    self.assertEqual(None, GramaticaLivreContexto(producoes, vn,vt,s).obterFirst('A'))
    

  def testSabeSePossuiRecursaoAEsquerdaDireta(self):
    self.assertTrue(construirGLCExpAritmeticaComRecEsquerdaDireta().possuiRecursaoAEsquerda())
   
    
  def testSabeSeNaoPossuiRecursaoAEsquerdaDireta(self):
    self.assertFalse(construirGLCExpAritmeticaSemRecEsquerda().possuiRecursaoAEsquerda())
  
    
  def testSabeSePossuiRecursaoAEsquerdaIndireta(self):
    self.assertTrue(construirGLCComRecEsquerdaIndireta().possuiRecursaoAEsquerda())
  
  
  def testSabeSeNaoPossuiRecursaoAEsquerdaIndireta(self):
    self.assertFalse(construirGLCExpAritmeticaSemRecEsquerda().possuiRecursaoAEsquerda())
  
  
  def testSabeSeEstaFatorada(self):
    self.assertTrue(construirGLCComNaoFatoracaoDiretaFatorada().estaFatorada())
  
  
  def testSabeSeNaoEstaFatoradaDiretamente(self):
    self.assertFalse(construirGLCComNaoFatoracaoDireta().estaFatorada())
  
  def testSabeSeNaoEstaFatoradaIndiretamente(self):
    self.assertFalse(construirGLCComNaoFatoracaoIndireta().estaFatorada())
  
if(__name__ == "__main__"):  
  suite = unittest.TestSuite()
  suite.addTest(unittest.makeSuite(TesteGramaticaLivreContexto))
  unittest.TextTestRunner(verbosity=2).run(suite)