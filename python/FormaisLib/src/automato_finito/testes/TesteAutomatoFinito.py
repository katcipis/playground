'''
Created on 23/09/2009
@author: katcipis
'''
import unittest
from automato_finito.AutomatoFinito import AutomatoFinito
from automato_finito.AutomatoFinito import ErroConstruindoAF
from automato_finito.AutomatoFinito import AFOperacaoIlegal
from automato_finito.Estado import Estado
from automato_finito.Transicao import Transicao
from enum.epsilon import EPSILON
from automato_finito.testes.construtor_automatos import construirAFDNaoMinimo
from automato_finito.testes.construtor_automatos import construirAFDMinimo
from automato_finito.testes.construtor_automatos import construirAFND
from automato_finito.testes.construtor_automatos import construirAFDCompleto
from automato_finito.testes.construtor_automatos import construirAFDImcompleto
from automato_finito.testes.construtor_automatos import construirAFDSemEstadosMortosOuInalcancaveis
from automato_finito.testes.construtor_automatos import construirAFDComCincoEstadosETresClassesDeEquivalencia
from automato_finito.testes.construtor_automatos import construirAFDQueGeraEpsilon
from automato_finito.testes.construtor_automatos import construirAFDComABOndeAsEhPar
from automato_finito.testes.construtor_automatos import construirAFDComABOndeBsEhImpar

class TesteAutomatoFinito(unittest.TestCase):

  def construirAutomatoA(self):
    self.alfabeto_automato_a = set(['a', 'b', 'c'])    
    self.estado_inicial_a = Estado('q0', 
                                    set([Transicao('a', 'q1'), Transicao('b', 'q0'), Transicao('c', 'q2')]), 
                                    True, False)
        
    self.estados_finais_automato_a = set()
    self.estados_finais_automato_a.add(Estado('q2', set([Transicao('a', 'q2')]), False, True))
    self.estados_finais_automato_a.add(Estado('q3', set([Transicao('b', 'q3')]), False, True))
    
    self.estados_automato_a = set()
    self.estados_automato_a.add(self.estado_inicial_a)
    [self.estados_automato_a.add(estado) for estado in self.estados_finais_automato_a]
    self.estados_automato_a.add(Estado('q1', 
                                       set([Transicao('a', 'q2'), Transicao('b', 'q3')]), 
                                       False, False))
    
    self.automato_det = AutomatoFinito(self.alfabeto_automato_a, self.estados_automato_a)
    
  def construirAutomatoB(self):
    self.alfabeto_automato_b = set(['b', 'c'])
  
    self.estado_inicial_b = Estado('q1', 
                                    set([Transicao('b', 'q0'), Transicao('c', 'q2')]), 
                                    True, False)
    
    self.estados_finais_automato_b = set()
    self.estados_finais_automato_b.add(Estado('q2', set([Transicao('b', 'q2')]), False, True))    
    
    self.estados_automato_b = set()
    self.estados_automato_b.add(Estado('q0', set([Transicao('c', 'q0'), Transicao('c', 'q1'), Transicao('b', 'q2')]), False, False))
    self.estados_automato_b.add(self.estado_inicial_b)
    [self.estados_automato_b.add(estado) for estado in self.estados_finais_automato_b]
    
    self.automato_nao_det = AutomatoFinito(self.alfabeto_automato_b, self.estados_automato_b)
  
  
  def setUp(self):
    self.construirAutomatoA()
    self.construirAutomatoB()
    
  def testSabeQuaisSaoSeusEstados(self):
    estados_a = self.automato_det.obterEstados()
    self.assertEqual(estados_a, self.estados_automato_a) 
    
  def testSabeQuaisNaoSaoSeusEstados(self):
    estados_a = self.automato_det.obterEstados()
    self.assertNotEqual(estados_a, self.estados_automato_b) 
           
  def testSabeQuaisSaoSeusEstadosFinais(self):
    estados_a = self.automato_det.obterEstadosFinais()
    self.assertEqual(estados_a, self.estados_finais_automato_a)
  
  def testSabeQuaisNaoSaoSeusEstadosFinais(self):
    estados_a = self.automato_det.obterEstadosFinais()
    self.assertNotEqual(estados_a, self.estados_finais_automato_b) 
    
  def testSabeQualEhOSeuEstadoInicial(self):
    inicial = self.automato_det.obterEstadoInicial()
    self.assertEqual(inicial, self.estado_inicial_a)
  
  def testSabeQualNaoEhOSeuEstadoInicial(self):
    inicial = self.automato_det.obterEstadoInicial()
    self.assertNotEqual(inicial, self.estado_inicial_b)
    
  def testSabeQualEhOSeuAlfabeto(self):
    alfabeto = self.automato_det.obterAlfabeto()
    self.assertEqual(alfabeto, self.alfabeto_automato_a)
  
  def testSabeQualNaoEhOSeuAlfabeto(self):
    alfabeto = self.automato_det.obterAlfabeto()
    self.assertNotEqual(alfabeto, self.alfabeto_automato_b)
  
  def testSabeSeEhDeterministico(self):
    self.assertTrue(self.automato_det.ehDeterministico())
    
  def testSabeSeNaoEhDeterministico(self):
    self.assertFalse(self.automato_nao_det.ehDeterministico())
    
  def testRetornaUmaCopiaDoSeuConjuntoDeEstados(self):
    estados = self.automato_det.obterEstados()
    self.assertEqual(estados, self.automato_det.obterEstados())
    estados.pop()
    self.assertNotEqual(estados, self.automato_det.obterEstados())
    
  def testRetornaUmaCopiaDoSeuAlfabeto(self):
    alfabeto = self.automato_det.obterAlfabeto()
    self.assertEqual(alfabeto, self.automato_det.obterAlfabeto())
    alfabeto.pop()
    self.assertNotEqual(alfabeto, self.automato_det.obterAlfabeto())
    
  def testSeNaoPossuiEstadoInicialDisparaExcecaoErroConstruindoAF(self):
    self.assertRaises(ErroConstruindoAF,
                      AutomatoFinito,
                      alfabeto = set(['a', 'b']),
                      estados = set([Estado('q0', set([Transicao('a', 'q0')]), False, False)]))
    
  def testSePossuiMaisDeUmEstadoInicialDisparaExcecaoErroConstruindoAF(self):
    self.assertRaises(ErroConstruindoAF,
                      AutomatoFinito,
                      alfabeto = set(['a', 'b']),
                      estados = set([Estado('q0', set([Transicao('a', 'q0')]), True, False),
                                     Estado('q1', set([Transicao('b', 'q0')]), True, False)]))
    
  def testSeAlgumaTransicaoPossuiSimboloQueNaoPertenceAoAlfalbetoDisparaExcecaoErroConstruindoAF(self):
    self.assertRaises(ErroConstruindoAF,
                      AutomatoFinito,
                      alfabeto = set(['a', 'b']),
                      estados = set([Estado('q0', set([Transicao('c', 'q0')]), True, True)]))
    
  def testSeAlgumaTransicaoPossuiEstadoDestinoQueNaoPertenceAoConjuntoDeEstadosDisparaExcecaoErroConstruindoAF(self):
    self.assertRaises(ErroConstruindoAF,
                      AutomatoFinito,
                      alfabeto = set(['a', 'b']),
                      estados = set([Estado('q0', set([Transicao('a', 'q1')]), True, True)]))
    
  def testPodeObterUmEstadoAPartirDoSeuNome(self):
    estado_q0 = Estado('q0', set([Transicao('a', 'q0')]), True, False)
    estado_q1 = Estado('q1', set([Transicao('b', 'q0')]), False, True)
    automato = AutomatoFinito( alfabeto = set(['a', 'b']),
                               estados  = set([estado_q0,estado_q1]))
    self.assertEqual(estado_q0, automato.obterEstado('q0'))
    self.assertEqual(estado_q1, automato.obterEstado('q1'))
    
  def testSeNaoExisteEstadoComNomeInformadoRetornaNone(self):
    estado_q0 = Estado('q0', set([Transicao('a', 'q0')]), True, False)
    automato = AutomatoFinito( alfabeto = set(['a', 'b']),
                               estados  = set([estado_q0]))
    self.assertEqual(None, automato.obterEstado('q1'))
    
  def testTransicaoPossuiRepresentacaoComoString(self):
    estado_q0 = Estado('q0', set([Transicao('a', 'q0')]), True, False)
    self.assertEqual(str(AutomatoFinito( alfabeto = set(['a', 'b']), estados  = set([estado_q0]))), 
                     str(AutomatoFinito( alfabeto = set(['a', 'b']), estados  = set([estado_q0]))))
    
  def testSabeSeEhCompleto(self):
    self.assertTrue(construirAFDCompleto().ehCompleto())
  
  def testSabeSeEhImcompleto(self):
    self.assertFalse(construirAFDImcompleto().ehCompleto())
    
  def testSabeQuaisSaoSeusEstadosInalcancaveis(self):
    alfabeto = set(['a'])
    estados = set()
    estado_inalcancavel = Estado('q2', set([Transicao('a', 'q1')]), False, False) 
    estados.add(Estado('q0', set([Transicao('a', 'q1')]), True, True))
    estados.add(Estado('q1', set([Transicao('a', 'q0')]), False, False))
    estados.add(estado_inalcancavel)
    automato = AutomatoFinito(alfabeto, estados)
    self.assertEqual(1, len(automato.obterEstadosInalcancaveis()))
    self.assertTrue(estado_inalcancavel in automato.obterEstadosInalcancaveis())
  
  
  def testSeNaoPossuiEstadosInalcancaveisRetornaUmConjuntoVazio(self):
    automato = construirAFDSemEstadosMortosOuInalcancaveis()
    self.assertEqual(set(), automato.obterEstadosInalcancaveis())
    
  def testSabeQuaisSaoSeusEstadosMortos(self):
    alfabeto = set(['a', 'b'])
    estados = set()
    estado_morto = Estado('q2', set([Transicao('a', 'q2'), Transicao('b', 'q2')]), False, False) 
    estados.add(Estado('q0', set([Transicao('a', 'q1')]), True, True))
    estados.add(Estado('q1', set([Transicao('a', 'q0'), Transicao('b', 'q2')]), False, False))
    estados.add(estado_morto)
    automato = AutomatoFinito(alfabeto, estados)
    self.assertEqual(1, len(automato.obterEstadosMortos()))
    self.assertTrue(estado_morto in automato.obterEstadosMortos())
  
  def testSeNaoPossuiEstadosMortosRetornaUmConjuntoVazio(self):
    automato = construirAFDSemEstadosMortosOuInalcancaveis()
    self.assertEqual(set(), automato.obterEstadosMortos())
    
  def testSabeQuaisSaoSeusClassesDeEquivalencia(self):
    ce_afd, afd = construirAFDComCincoEstadosETresClassesDeEquivalencia()
    conjuntos_equivalencia = afd.obterClassesDeEquivalencia()
    self.assertEqual(5, len(afd.obterEstados()))
    self.assertEqual(3, len(conjuntos_equivalencia))
    self.assertEqual(ce_afd.sort(), conjuntos_equivalencia.sort())
    
  def testSabeSeNaoEhMinimo(self):
    self.assertFalse(construirAFDNaoMinimo().ehMinimo())
    
  def testSabeSeEhMinimo(self):
    self.assertTrue(construirAFDMinimo().ehMinimo())
    
  def testSeTentarObterClassesDeEquivalenciaDeUmAFNDDisparaUmaExcecaoDeOperacaoIlegal(self):
    afnd = construirAFND()
    self.assertRaises(AFOperacaoIlegal, afnd.obterClassesDeEquivalencia)
  
  def testSeTentarObterClassesDeEquivalenciaDeUmAFDImcompletoDisparaUmaExcecaoDeOperacaoIlegal(self):
    afd_imcompleto = construirAFDImcompleto()
    self.assertRaises(AFOperacaoIlegal, afd_imcompleto.obterClassesDeEquivalencia)
    
  def testSeUmAFDPossuiApenasUmEstadoEleJaEhMinimo(self):
    afd = construirAFDQueGeraEpsilon()
    self.assertTrue(afd.ehMinimo())
    
  def testAFNDNaoReconhecePalavra(self):
    afnd = construirAFND()
    self.assertRaises(AFOperacaoIlegal, afnd.reconhecePalavra, 'qualquer')
    
  def testSabeSeReconheceUmaPalavra(self):
    afd = construirAFDComABOndeAsEhPar()
    self.assertTrue(afd.reconhecePalavra('bbbb'))
    self.assertTrue(afd.reconhecePalavra('abbbba'))
    self.assertTrue(afd.reconhecePalavra('ababb'))
    self.assertTrue(afd.reconhecePalavra('babba'))
    self.assertTrue(afd.reconhecePalavra('babab'))
  
  def testSabeSeNaoReconheceUmaPalavra(self):
    afd = construirAFDComABOndeAsEhPar()
    self.assertFalse(afd.reconhecePalavra('babb'))
    self.assertFalse(afd.reconhecePalavra('abbabba'))
    self.assertFalse(afd.reconhecePalavra('abaaaa'))
    self.assertFalse(afd.reconhecePalavra('bbba'))
    self.assertFalse(afd.reconhecePalavra('abbb'))
  
  def testSabeSeReconheceEpsilon(self):
    afd = construirAFDComABOndeAsEhPar()
    self.assertTrue(afd.reconhecePalavra(EPSILON))
    
  def testSabeSeNaoReconheceEpsilon(self):
    afd = construirAFDComABOndeBsEhImpar()
    self.assertFalse(afd.reconhecePalavra(EPSILON))
    
if(__name__ == "__main__"):  
  suite = unittest.TestSuite()
  suite.addTest(unittest.makeSuite(TesteAutomatoFinito))
  unittest.TextTestRunner(verbosity=2).run(suite)
