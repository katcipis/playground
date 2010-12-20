'''
Created on 23/10/2009
@author: katcipis
'''
import unittest
from automato_finito.testes.construtor_automatos import construirAFDQueGeraEpsilon
from automato_finito.testes.construtor_automatos import construirAFDComABOndeAsEhPar
from automato_finito.testes.construtor_automatos import construirAFDComABOndeBsEhImpar
from expressao_regular.ExpressaoRegular import ErroConstruindoER
from expressao_regular.ExpressaoRegular import ExpressaoRegular
from automato_finito.AutomatoFinito import AutomatoFinito
from automato_finito.Estado import Estado
from automato_finito.Transicao import Transicao
from util import util
from enum.epsilon import EPSILON


class TesteExpressaoRegular(unittest.TestCase):

  def testUmaExpressaoRegularEhInvalidaSePossuiOperadoresESeguidos(self):
    self.assertRaises(ErroConstruindoER,
                      ExpressaoRegular,
                      'a*b..(ab)')
    
  def testUmaExpressaoRegularEhInvalidaSePossuiOperadoresOuSeguidos(self):
    self.assertRaises(ErroConstruindoER,
                      ExpressaoRegular,
                      'a*b||(ab)*')
  
  def testUmaExpressaoRegularEhInvalidaSePossuiOperadoresEouOuSeguidos(self):
    self.assertRaises(ErroConstruindoER,
                      ExpressaoRegular,
                      'a*b.|(ab)*')
    self.assertRaises(ErroConstruindoER,
                      ExpressaoRegular,
                      'a*b|.(ab)*')
    
  def testUmaExpressaoRegularEhInvalidaSePossuiOperadoresFechamentoReflexivoSeguidos(self):
    self.assertRaises(ErroConstruindoER,
                      ExpressaoRegular,
                      'a*b**(ab)')
    
  def testUmaExpressaoRegularEhInvalidaSePossuiOperadoresFechamentoPositivoSeguidos(self):
    self.assertRaises(ErroConstruindoER,
                      ExpressaoRegular,
                      'a*b++(ab)')
    
  def testUmaExpressaoRegularEhInvalidaSePossuiDoisOperadoresInterrogacaoSeguidos(self):
    self.assertRaises(ErroConstruindoER,
                      ExpressaoRegular,
                      'a*b??(ab)')
    
  def testUmaExpressaoRegularEhValidaSePossuiOperadorOuAposFechamentoReflexivo(self):
    ExpressaoRegular('a*b*|(ab)').obterAFD()
    
  def testUmaExpressaoRegularEhValidaSePossuiOperadorOuAposFechamentoPositivo(self):
    ExpressaoRegular('a*b+|(ab)').obterAFD()
    
  def testUmaExpressaoRegularEhInvalidaSePossuiOperadorInterrogacaoAposFechamentoReflexivo(self):
    self.assertRaises(ErroConstruindoER,
                      ExpressaoRegular,
                      'a*b*?(ab)')
  
  def testUmaExpressaoRegularEhInvalidaSePossuiOperadorInterrogacaoAposFechamentoPositivo(self):
    self.assertRaises(ErroConstruindoER,
                      ExpressaoRegular,
                      'a*b+?(ab)')
  
  def testUmaExpressaoRegularEhValidaSePossuiOperadorEAposFechamentoReflexivo(self):
    ExpressaoRegular('a*b*.(ab)').obterAFD()
    
  def testUmaExpressaoRegularEhValidaSePossuiOperadorEAposFechamentoPositivo(self):
    ExpressaoRegular('a*b+.(ab)').obterAFD()
  
  def testUmaExpressaoRegularEhValidaSePossuiOperadorOuAposInterrogacao(self):
    ExpressaoRegular('a*b?|(ab)').obterAFD()
  
  def testUmaExpressaoRegularEhValidaSePossuiOperadorEAposInterrogacao(self):
    ExpressaoRegular('a*b?.(ab)').obterAFD()
    
  def testUmaExpressaoRegularEhInvalidaSePossuiOperadorFechamentoReflexivoAposInterrogacao(self):
    self.assertRaises(ErroConstruindoER,
                      ExpressaoRegular,
                      'a*b?*(ab)')
  
  def testUmaExpressaoRegularEhInvalidaSePossuiOperadorFechamentoPositivoAposInterrogacao(self):
    self.assertRaises(ErroConstruindoER,
                      ExpressaoRegular,
                      'a*b?+(ab)')
    
  def testUmaExpressaoRegularEhInvalidaSeIniciaComUmOperador(self):
    self.assertRaises(ErroConstruindoER,
                      ExpressaoRegular,
                      '|a*b(ab)')
    self.assertRaises(ErroConstruindoER,
                      ExpressaoRegular,
                      '*a*b(ab)*')
    self.assertRaises(ErroConstruindoER,
                      ExpressaoRegular,
                      '.a*b(ab)')
    self.assertRaises(ErroConstruindoER,
                      ExpressaoRegular,
                      '?a*b(ab)')
    self.assertRaises(ErroConstruindoER,
                      ExpressaoRegular,
                      '+a*b(ab)')
    
  def testUmaExpressaoRegularEhInvalidaSeTerminaComOOperadorOU(self):
    self.assertRaises(ErroConstruindoER,
                      ExpressaoRegular,
                      'a*b(ab)|')

  def testUmaExpressaoRegularEhInvalidaSeTerminaComOOperadorE(self):
    self.assertRaises(ErroConstruindoER,
                      ExpressaoRegular,
                      'a*b(ab).')
  
  def testUmaExpressaoRegularNaoEhInvalidaSeTerminaComOOperadorFechamentoReflexivo(self):
    ExpressaoRegular('a*b(ab)*').obterAFD()
    
  def testUmaExpressaoRegularNaoEhInvalidaSeTerminaComOOperadorFechamentoPositivo(self):
    ExpressaoRegular('a*b(ab)+').obterAFD()
    
  def testUmaExpressaoRegularEhInvalidaSeExistemMaisAberturasDeParentesisQueFechamentos(self):
    self.assertRaises(ErroConstruindoER,
                      ExpressaoRegular,
                      'a*b((ab)')
  
  def testUmaExpressaoRegularEhInvalidaSeExistemMaisFechamentosDeParentesisQueAberturas(self):
    self.assertRaises(ErroConstruindoER,
                      ExpressaoRegular,
                      'a*b(ab))')
    
  def testUmaExpressaoRegularEhInvalidaSeAsAberturasEFechamentosNaoEstaoNaOrdemCorreta(self):
    self.assertRaises(ErroConstruindoER,
                      ExpressaoRegular,
                      'a*b)ab(a)')
  
  def testUmaExpressaoRegularEhInvalidaSeExisteNadaEntreParentesis(self):
    self.assertRaises(ErroConstruindoER,
                      ExpressaoRegular,
                      'a*b()aba')
  
  def testSuaRepresentacaoEmStringNaoPossuiEspacosVazios(self):
    exp = ExpressaoRegular(' a* b(ab)* b ')
    self.assertEqual('a*b(ab)*b', str(exp))
    
  def testExpressaoRegPodeEstarTodaEmglobadaEmParenteses(self):
    exp1 = ExpressaoRegular('( a* b(ab)* b )')
    exp2 = ExpressaoRegular(' a* b(ab)* b ')
    self.assertTrue(util.sao_equivalentes_af(exp1.obterAFD(), exp2.obterAFD()))
    
  def testReconheceOEpsilonComoCaracterEspecialEGeraUmAutomatoMinimoQueGeraEpsilon(self):
    exp = ExpressaoRegular(EPSILON)
    self.assertTrue(util.sao_equivalentes_af(exp.obterAFD(), construirAFDQueGeraEpsilon()))
    
  def testReconheceOOperadorInterrogacao(self):
    exp1 = ExpressaoRegular('a?')
    exp2 = ExpressaoRegular('a|' + EPSILON)
    self.assertTrue(util.sao_equivalentes_af(exp1.obterAFD(), exp2.obterAFD()))
    
  def testReconheceOOperadorFechamentoPosito(self):
    exp1 = ExpressaoRegular('a+')
    exp2 = ExpressaoRegular('aa*')
    self.assertTrue(util.sao_equivalentes_af(exp1.obterAFD(), exp2.obterAFD()))

  def testSabeQualEhOSeuAFDMinimoCorrespondente(self):
    estados = set()
    estados.add(Estado('q0', set([Transicao('a', 'q1')]), True, False))
    estados.add(Estado('q1', set([Transicao('b', 'q1'), Transicao('c', 'q2')]), False, False))
    estados.add(Estado('q2', set(), False, True))
    alfabeto = set(['a','b','c'])
    
    automato_a_bEstrela_c = AutomatoFinito(alfabeto, estados)
    exp_reg = ExpressaoRegular('ab*c')
    afd_exp = exp_reg.obterAFD()
    self.assertTrue(util.sao_equivalentes_af(automato_a_bEstrela_c, afd_exp))
    self.assertTrue(afd_exp.ehDeterministico())
    self.assertTrue(afd_exp.ehMinimo())
    
  def testModificacoesQueNaoAlteramLinguagem(self):
    exp1 = ExpressaoRegular('a*a*a*')
    exp2 = ExpressaoRegular('a*')
    self.assertTrue(util.sao_equivalentes_af(exp1.obterAFD(), exp2.obterAFD()))
    
    exp1 = ExpressaoRegular('a|b')
    exp2 = ExpressaoRegular('b|a')
    self.assertTrue(util.sao_equivalentes_af(exp1.obterAFD(), exp2.obterAFD()))
  
  def testModificacoesQueAlteramLinguagem(self):
    exp1 = ExpressaoRegular('a?a?a?')
    exp2 = ExpressaoRegular('a?')
    self.assertFalse(util.sao_equivalentes_af(exp1.obterAFD(), exp2.obterAFD()))
    
    exp1 = ExpressaoRegular('a.b')
    exp2 = ExpressaoRegular('b.a')
    self.assertFalse(util.sao_equivalentes_af(exp1.obterAFD(), exp2.obterAFD()))
    
  def testRobustezDaTransformacaoDaEREmAFD(self):
    automato = construirAFDComABOndeAsEhPar()
    exp_reg = ExpressaoRegular('(b*ab*a)*b*')
    afd_exp = exp_reg.obterAFD()
    self.assertTrue(util.sao_equivalentes_af(automato, afd_exp))
    
    automato = construirAFDComABOndeBsEhImpar()
    exp_reg = ExpressaoRegular('a*ba* (a*ba*ba*)*')
    afd_exp = exp_reg.obterAFD()
    self.assertTrue(util.sao_equivalentes_af(automato, afd_exp))
    
    
  def testNaoImportaAQuantidadeDeParentesis(self):
    exp1 = ExpressaoRegular('((( a* b((ab))* b )))')
    exp2 = ExpressaoRegular(' a* b(ab)* b ')
    self.assertTrue(util.sao_equivalentes_af(exp1.obterAFD(), exp2.obterAFD()))
    
  def testDefineEscopoDosParentesisCorretamente(self):
    exp1 = ExpressaoRegular('(a) | (b)')
    exp2 = ExpressaoRegular('a|b')
    self.assertTrue(util.sao_equivalentes_af(exp1.obterAFD(), exp2.obterAFD()))
    
  
    
    
    
if(__name__ == "__main__"):  
  suite = unittest.TestSuite()
  suite.addTest(unittest.makeSuite(TesteExpressaoRegular))
  unittest.TextTestRunner(verbosity=2).run(suite)