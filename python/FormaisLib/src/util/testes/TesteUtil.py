'''
Created on 02/10/2009
@author: katcipis
'''

import unittest
from automato_finito.testes.construtor_automatos import construirAFDSemEstadosMortosOuInalcancaveis
from automato_finito.testes.construtor_automatos import construirAFDComUmEstadoInalcancavel
from automato_finito.testes.construtor_automatos import construirAFDComUmEstadoMorto
from automato_finito.testes.construtor_automatos import construirAFDImcompleto
from automato_finito.testes.construtor_automatos import construirAFND
from automato_finito.testes.construtor_automatos import construirAFDCompleto
from automato_finito.testes.construtor_automatos import construirAFDNaoMinimo
from automato_finito.testes.construtor_automatos import construirAFDMinimo
from automato_finito.testes.construtor_automatos import construirAFDComABOndeAsEhPar
from automato_finito.testes.construtor_automatos import construirAFDComABOndeBsEhImpar
from automato_finito.testes.construtor_automatos import construirComplementoDoAFDComABOndeAsEhPar
from automato_finito.testes.construtor_automatos import construirEquivalenteDoAFDComABOndeAsEhPar
from automato_finito.testes.construtor_automatos import construirAFDQueGeraOSimboloA
from automato_finito.testes.construtor_automatos import construirAFDQueGeraEpsilon
from gramatica.testes.construtor_gramaticas import construirGLCComCiclo
from gramatica.testes.construtor_gramaticas import construirGLCSemCiclo
from gramatica.testes.construtor_gramaticas import construirGLCExpAritmeticaComRecEsquerdaDireta
from gramatica.testes.construtor_gramaticas import construirGLCComRecEsquerdaIndireta
from gramatica.testes.construtor_gramaticas import construirGLCComABOndeNumAsEhIgualNumBsComSimbolosInalcancaveis
from gramatica.testes.construtor_gramaticas import construirGLCComABOndeNumAsEhIgualNumBsSemSimbolosInuteis
from gramatica.testes.construtor_gramaticas import construirGLCComABOndeNumAsEhIgualNumBsComSimbolosMortos
from gramatica.testes.construtor_gramaticas import construirGLCComABOndeNumAsEhIgualNumBsComSimbolosInuteis
from gramatica.testes.construtor_gramaticas import construirGRComABOndeAsEhPar
from gramatica.testes.construtor_gramaticas import construirGLCComABOndeNumAsEhIgualNumBsEpsilonLivre
from gramatica.testes.construtor_gramaticas import construirGLCComABOndeNumAsEhIgualNumBsComEpsilon
from gramatica.testes.construtor_gramaticas import construirGLCComNaoFatoracaoDireta
from gramatica.testes.construtor_gramaticas import construirGLCComNaoFatoracaoDiretaFatorada
from gramatica.testes.construtor_gramaticas import construirGLCComNaoFatoracaoIndireta
from gramatica.testes.construtor_gramaticas import construirGLCComNaoFatoracaoIndiretaFatorada
from gramatica.Gramatica import Gramatica
from gramatica.Producao import Producao
from expressao_regular.ExpressaoRegular import ExpressaoRegular
from util import util
from enum.epsilon import EPSILON 
import os

class TesteUtil(unittest.TestCase):
  
  def setUp(self):
    self.afnd = construirAFND()
    self.afd_um_estado_inalcancavel = construirAFDComUmEstadoInalcancavel()
    self.afd_um_estado_morto = construirAFDComUmEstadoMorto()
  
  
  def testDadoUmAFNDRetornaUmAFDEquivalente(self):
    self.assertFalse(self.afnd.ehDeterministico())
    afd = util.determinizar_af(self.afnd)
    self.assertTrue(afd.ehDeterministico())
    self.assertTrue(util.sao_equivalentes_af(self.afnd, afd))
    
  def testDadoUmAFDPodeRemoveTodosOsEstadosInalcancaveis(self):
    afd_novo = util.remover_estados_inalcancaveis_afd(self.afd_um_estado_inalcancavel)
    self.assertEqual(3, len(self.afd_um_estado_inalcancavel.obterEstados()))
    self.assertEqual(2, len(afd_novo.obterEstados()))
    self.assertTrue(util.sao_equivalentes_af(self.afd_um_estado_inalcancavel, afd_novo))
    
  def testSeTodosOsEstadosSaoAlcancaveisNaoRemoveEstadoAlgum(self):
    afd_novo = util.remover_estados_inalcancaveis_afd(construirAFDSemEstadosMortosOuInalcancaveis())
    self.assertEqual(len(afd_novo.obterEstados()), len(construirAFDSemEstadosMortosOuInalcancaveis().obterEstados()))
    self.assertTrue(util.sao_equivalentes_af(afd_novo, construirAFDSemEstadosMortosOuInalcancaveis()))
    
  def testDadoUmAFDPodeRemoverTodosOsEstadosMortos(self):
    afd_novo = util.remover_estados_mortos_afd(self.afd_um_estado_morto)
    self.assertEqual(3, len(self.afd_um_estado_morto.obterEstados()))
    self.assertEqual(2, len(afd_novo.obterEstados()))
    self.assertTrue(util.sao_equivalentes_af(afd_novo,self.afd_um_estado_morto))
    
  def testSeTodosOsEstadosSaoVivosNaoRemoveEstadoAlgum(self):
    afd_novo = util.remover_estados_mortos_afd(construirAFDSemEstadosMortosOuInalcancaveis())
    self.assertEqual(len(afd_novo.obterEstados()), len(construirAFDSemEstadosMortosOuInalcancaveis().obterEstados()))
    self.assertTrue(util.sao_equivalentes_af(afd_novo,construirAFDSemEstadosMortosOuInalcancaveis()))
    
  def testDadoUmAFDImcompletoPodeGerarUmNovoAFDCompletoEquivalente(self):
    afd_imcompleto = construirAFDImcompleto()
    self.assertFalse(afd_imcompleto.ehCompleto())
    afd_completo = util.completar_af(afd_imcompleto)
    self.assertTrue(afd_completo.ehCompleto())
    self.assertTrue(util.sao_equivalentes_af(afd_imcompleto,afd_completo))
    
  def testSeOAFDJaEhCompletoRetornaOMesmo(self):
    afd_completo = construirAFDCompleto()
    self.assertEqual(afd_completo, util.completar_af(afd_completo))
   
  def testSeOAFDJaEhMinimoRetornaOMesmo(self):
    afd_minimo =  construirAFDMinimo()
    self.assertTrue(afd_minimo.ehMinimo())
    self.assertEqual(afd_minimo, util.minimizar_afd(afd_minimo))
    
  def testDadoUmAFDNaoMinimoGeraUmAFDMinimoEquivalente(self):
    afd_nao_minimo = construirAFDNaoMinimo()
    self.assertFalse(afd_nao_minimo.ehMinimo())
    afd_minimo = util.minimizar_afd(afd_nao_minimo)
    self.assertTrue(afd_minimo.ehMinimo())
    self.assertTrue(util.sao_equivalentes_af(afd_nao_minimo,afd_minimo))
   
  def testDadoDoisAFPodeUnilos(self):
    afd1 = construirAFDComABOndeAsEhPar()
    afd2 = construirAFDComABOndeBsEhImpar()
    afd1Uafd2 = util.unir_af(afd1, afd2)
    estados_antigos = len(afd1.obterEstados()) + len(afd2.obterEstados())
    self.assertEqual(len(afd1Uafd2.obterEstados()) - 1, estados_antigos)
    
  def testNaoUniaoSeUmDosAFTemEstadoInicialFinalOEstadoInicialNovoTbEhFinal(self):
    afd1 = construirAFDComABOndeAsEhPar()
    afd2 = construirAFDComABOndeBsEhImpar()
    self.assertTrue(afd1.obterEstadoInicial().ehFinal())
    self.assertFalse(afd2.obterEstadoInicial().ehFinal())
    afd1Uafd2 = util.unir_af(afd1, afd2)
    self.assertTrue(afd1Uafd2.obterEstadoInicial().ehFinal())
  
  def testNaUniaoSeAmbosAFTemEstadoInicialFinalOEstadoInicialNovoTbEhFinal(self):
    afd1 = construirAFDComABOndeAsEhPar()
    afd2 = construirAFDComABOndeAsEhPar()
    self.assertTrue(afd1.obterEstadoInicial().ehFinal())
    self.assertTrue(afd2.obterEstadoInicial().ehFinal())
    afd1Uafd2 = util.unir_af(afd1, afd2)
    self.assertTrue(afd1Uafd2.obterEstadoInicial().ehFinal())
    
  def testNaUniaoSeNenhumAFTemEstadoInicialFinalOEstadoInicialNovoNaoEhFinal(self):
    afd1 = construirAFDComABOndeBsEhImpar()
    afd2 = construirAFDComABOndeBsEhImpar()
    self.assertFalse(afd1.obterEstadoInicial().ehFinal())
    self.assertFalse(afd2.obterEstadoInicial().ehFinal())
    afd1Uafd2 = util.unir_af(afd1, afd2)
    self.assertFalse(afd1Uafd2.obterEstadoInicial().ehFinal())

  def testDadoDoisAFPodeConcatenalos(self):
    afd1 = construirAFDComABOndeAsEhPar()
    afd2 = construirAFDComABOndeBsEhImpar()
    afd1afd2 = util.concatenar_af(afd1, afd2)
    estados_antigos = len(afd1.obterEstados()) + len(afd2.obterEstados())
    self.assertEqual(len(afd1afd2.obterEstados()), estados_antigos)
  
  def testDadoAConcatenacaoDeDoisAFSeOInicialDoSegundoEhFinalOsFinaisDoPrimeiroContinuamSendoFinais(self):
    afd1 = construirAFDComABOndeBsEhImpar() 
    afd2 = construirAFDComABOndeAsEhPar()
    self.assertTrue(afd2.obterEstadoInicial().ehFinal())
    afd1afd2 = util.concatenar_af(afd1, afd2)
    finais_antigos_len = len(afd1.obterEstadosFinais()) + len(afd2.obterEstadosFinais())
    self.assertEqual(finais_antigos_len, len(afd1afd2.obterEstadosFinais()))
    
  def testDadoAConcatenacaoDeDoisAFSeOInicialDoSegundoNaoEhFinalOsFinaisDoPrimeiroDeixamDeSerFinais(self):
    afd1 = construirAFDComABOndeAsEhPar()
    afd2 = construirAFDComABOndeBsEhImpar()
    self.assertFalse(afd2.obterEstadoInicial().ehFinal())
    afd1afd2 = util.concatenar_af(afd1, afd2)
    finais_antigos_len = len(afd1.obterEstadosFinais()) + len(afd2.obterEstadosFinais())
    self.assertTrue(finais_antigos_len > len(afd1afd2.obterEstadosFinais()))
    
  def testDadoUmAFPodeAplicarFechamentoReflexivoNoMesmo(self):
    afd1 = construirAFDComABOndeAsEhPar()
    afd_reflex = util.obter_fechamento_reflexivo_af(afd1)
    self.assertEqual(len(afd_reflex.obterEstados()), len(afd1.obterEstados()) + 1)
  
  def testDadoUmAFAposAplicarFechamentoReflexivoNoMesmoOEstadoInicialSempreEhFinal(self):
    afd1 = construirAFDComABOndeBsEhImpar()
    self.assertFalse(afd1.obterEstadoInicial().ehFinal())
    afd_reflex = util.obter_fechamento_reflexivo_af(afd1)
    self.assertTrue(afd_reflex.obterEstadoInicial().ehFinal())
    
  def testDadoUmAFPodeAplicarFechamentoPositivoNoMesmo(self):
    afd1 = construirAFDQueGeraOSimboloA()
    afd_pos = util.obter_fechamento_positivo_af(afd1)
    self.assertEqual(len(afd_pos.obterEstados()), len(afd1.obterEstados()))
    self.assertFalse(util.sao_equivalentes_af(afd1, afd_pos))
    
    self.assertTrue(afd1.reconhecePalavra('a'))
    self.assertFalse(afd1.reconhecePalavra('aa'))
    self.assertTrue(afd_pos.reconhecePalavra('aa'))
    self.assertTrue(afd_pos.reconhecePalavra('aaa'))
    self.assertTrue(afd_pos.reconhecePalavra('a'))
    self.assertFalse(afd_pos.reconhecePalavra(EPSILON))
    
  
  def testDadoUmAFAposAplicarFechamentoPositivoNoMesmoOEstadoInicialSohEhFinalSeJaEraFinalAntes(self):
    afd1 = construirAFDComABOndeBsEhImpar()
    afd2 = construirAFDComABOndeAsEhPar()
    self.assertFalse(afd1.obterEstadoInicial().ehFinal())
    self.assertTrue(afd2.obterEstadoInicial().ehFinal())
    
    afd_pos1 = util.obter_fechamento_positivo_af(afd1)
    afd_pos2 = util.obter_fechamento_positivo_af(afd2)
    self.assertFalse(afd_pos1.obterEstadoInicial().ehFinal())
    self.assertTrue(afd_pos2.obterEstadoInicial().ehFinal())
    
  def testDadosDoisAFSabeSeAF1EstaContidoEmAF2(self):
    afd1 = construirAFDComABOndeAsEhPar()
    afd2 = construirEquivalenteDoAFDComABOndeAsEhPar()
    self.assertTrue(util.esta_contido_af(afd1, afd2))
  
  def testDadosDoisAFSabeSeAF1NaoEstaContidoEmAF2(self):
    afd1 = construirAFDComABOndeAsEhPar()
    afd2 = construirAFDComABOndeBsEhImpar()
    self.assertFalse(util.esta_contido_af(afd1, afd2)) 
  
  def testDadosDoisAFSabeSeElesSaoEquivalentes(self):
    afd1 = construirAFDComABOndeAsEhPar()
    afd2 = construirEquivalenteDoAFDComABOndeAsEhPar()
    self.assertTrue(util.sao_equivalentes_af(afd1, afd2))
  
  def testDadosDoisAFSabeSeElesNaoSaoEquivalentes(self):
    afd1 = construirAFDComABOndeAsEhPar()
    afd2 = construirAFDComABOndeBsEhImpar()
    self.assertFalse(util.sao_equivalentes_af(afd1, afd2)) 
  
  def testDadoUmAFDSabeQualSeuComplemento(self):
    afd1 = construirAFDComABOndeAsEhPar()
    afd2 = construirComplementoDoAFDComABOndeAsEhPar()
    complemento = util.obter_complemento_af(afd1)
    self.assertEqual(afd2.obterEstados(), complemento.obterEstados())
    self.assertEqual(afd2.obterEstadosFinais(), complemento.obterEstadosFinais())
    self.assertEqual(afd2.obterEstadoInicial(), complemento.obterEstadoInicial())
    
  def testComplementoSempreEhUmAFD(self):
    afnd1 = construirAFND()
    self.assertFalse(afnd1.ehDeterministico())
    complemento = util.obter_complemento_af(afnd1)
    self.assertTrue(complemento.ehDeterministico())
    
  def testComplementoSempreEhUmAFDCompleto(self):
    afnd1 = construirAFDImcompleto()
    self.assertFalse(afnd1.ehCompleto())
    complemento = util.obter_complemento_af(afnd1)
    self.assertTrue(complemento.ehDeterministico())
    self.assertTrue(complemento.ehCompleto())
    
  def testPodeConstruirOAutomatoQueGeraUmDadoSimbolo(self):
    afd = construirAFDQueGeraOSimboloA()
    afd2 = util.gerar_automato_finito('a')
    afd3 = util.gerar_automato_finito('b')
    self.assertTrue(util.sao_equivalentes_af(afd, afd2))
    self.assertFalse(util.sao_equivalentes_af(afd, afd3)) 
    
  def testPodeConstruirUmAutomatoQueGeraApenasEpsilon(self): 
    afd = construirAFDQueGeraEpsilon()
    afd2 = util.gerar_automato_finito_epsilon()
    afd3 = util.gerar_automato_finito('a')
    
    self.assertTrue(util.sao_equivalentes_af(afd, afd2))
    self.assertFalse(util.sao_equivalentes_af(afd, afd3))
    
  def testConcatenarDoisAutomatosQueGeramEpsilonGeraOMesmoAutomato(self):
    afd = util.gerar_automato_finito_epsilon()
    afd2 = util.concatenar_af(util.gerar_automato_finito_epsilon(), util.gerar_automato_finito_epsilon())
    self.assertTrue(util.sao_equivalentes_af(afd, afd2))
    
  def testUnirDoisAutomatosQueGeramEpsilonGeraOMesmoAutomato(self):
    afd = util.gerar_automato_finito_epsilon()
    afd2 = util.unir_af(util.gerar_automato_finito_epsilon(), util.gerar_automato_finito_epsilon())
    self.assertTrue(util.sao_equivalentes_af(afd, afd2))
    
  def testOAutomatoMinimoDeUmAutomatoQueGeraApenasEpsilonEhEleMesmo(self):
    afd = util.gerar_automato_finito_epsilon()
    afd2 = util.minimizar_afd(afd)
    self.assertEqual(afd, afd2)
    
  def testDadaUmaGramaticaRegularSabeQualEhOSeuAFDMinimoCorrespondente(self):
    afd1 = construirAFDComABOndeAsEhPar()
    afd2 = util.obter_afd(construirGRComABOndeAsEhPar())
    
    self.assertTrue(util.sao_equivalentes_af(afd1, afd2))
    self.assertTrue(afd2.ehDeterministico())
    self.assertTrue(afd2.ehMinimo())
  
   
  def testDadoUmAFDSabeQualEhASuaGramaticaRegularCorrespondente(self):
    gr1 = util.obter_gramatica_regular(construirAFDComABOndeAsEhPar())
    afd1  = util.obter_afd(gr1)
    afd2 = construirAFDComABOndeAsEhPar()
    
    self.assertTrue(util.sao_equivalentes_af(afd1, afd2))
    
  def testDadoUmAFDQueGeraApenasUmSimboloSabeQualEhASuaGramaticaRegularCorrespondente(self):
    gr1 = util.obter_gramatica_regular(construirAFDQueGeraOSimboloA())
    afd1  = util.obter_afd(gr1)
    afd2 = construirAFDQueGeraOSimboloA()
    
    self.assertTrue(util.sao_equivalentes_af(afd1, afd2))
    
  def testDadoUmAFDSabeQualEhASuaGramaticaRegularCorrespondenteQuandoAFDProduzEpsilon(self):
    gr1 = util.obter_gramatica_regular(construirAFDComABOndeAsEhPar())
    afd1  = util.obter_afd(gr1)
    afd2 = construirAFDComABOndeAsEhPar()
    
    self.assertTrue(util.sao_equivalentes_af(afd1, afd2))
  
  def testDadoUmAFDSabeQualEhASuaGramaticaRegularCorrespondenteQuandoAFDNaoProduzEpsilon(self):
    gr1 = util.obter_gramatica_regular(construirAFDComABOndeBsEhImpar())
    afd1  = util.obter_afd(gr1)
    afd2 = construirAFDComABOndeBsEhImpar()
    
    self.assertTrue(util.sao_equivalentes_af(afd1, afd2))
  
  def testSeAGramaticaNaoForRegularRetornaNoneAoTentarObterOAFD(self):
    vn = set(['S', 'V'])
    vt = set(['a', 'b', 'c'])
    s = 'S'
    producoes_s = set([Producao('S', 'a V S'), Producao('S', 'b')])
    producoes_v = set([Producao('V', 'a S V'), Producao('V', 'c')])
    producoes = set()
    producoes.update(producoes_s)
    producoes.update(producoes_v)
    
    g = Gramatica(producoes, vn,vt,s)
    afd2 = util.obter_afd(g)
    self.assertEqual(None, afd2)
    
    
  def testPodeSalvarECarregarUmaExpressaoRegularDoDisco(self):
    exp = ExpressaoRegular('a*b?.(ab)')
    util.salvar(exp, os.path.join(os.getcwd(), 'teste.exp'))
    exp2 = util.carregar(os.path.join(os.getcwd(), 'teste.exp'))
    self.assertTrue(util.sao_equivalentes_af(exp.obterAFD(), exp2.obterAFD()))
  
  def testPodeSalvarECarregarUmaGramaticaRegularDoDisco(self):
    gr1 = util.obter_gramatica_regular(construirAFDComABOndeBsEhImpar())
    util.salvar(gr1, os.path.join(os.getcwd(), 'teste.gr'))
    gr2 = util.carregar(os.path.join(os.getcwd(), 'teste.gr'))
    self.assertTrue(util.sao_equivalentes_af(util.obter_afd(gr1), util.obter_afd(gr2)))
  
  def testPodeSalvarECarregarUmAutomatoFinitoDoDisco(self):
    afd1 = construirAFDComABOndeBsEhImpar()
    util.salvar(afd1, os.path.join(os.getcwd(), 'teste.af'))
    afd2 = util.carregar(os.path.join(os.getcwd(), 'teste.af'))
    self.assertTrue(util.sao_equivalentes_af(afd1, afd2))
  
  def testSeOLocalOndeEstaSalvandoNaoExisteGeraErro(self):
    self.assertRaises(IOError,
                      util.salvar,
                      ExpressaoRegular('a*b?.(ab)'), '/lerolero')

  
  def testSeOLocaoOndeEstaCarregandoNaoExisteGeraErro(self):
    self.assertRaises(IOError,
                      util.carregar,
                      '/lerolero')
    
     
  def testDadaUmaGLCComSimbolosInalcancaveisPodeRemovelosERetornarUmaGLCSemSimbolosInalcancaveis(self):
    glc_ok = construirGLCComABOndeNumAsEhIgualNumBsSemSimbolosInuteis()
    glc_nok = construirGLCComABOndeNumAsEhIgualNumBsComSimbolosInalcancaveis()
    self.assertNotEqual(glc_ok, glc_nok)
    self.assertEqual(glc_ok, util.remover_simbolos_inalcancaveis_glc(glc_nok))
  

  def testDadaUmaGLCComSimbolosMortosPodeRemovelosERetornarUmaGLCSemSimbolosMortos(self):
    glc_ok = construirGLCComABOndeNumAsEhIgualNumBsSemSimbolosInuteis()
    glc_nok = construirGLCComABOndeNumAsEhIgualNumBsComSimbolosMortos()
    self.assertNotEqual(glc_ok, glc_nok)
    self.assertEqual(glc_ok, util.remover_simbolos_mortos_glc(glc_nok))
     
  
  def testDadaUmaGLCComSimbolosInuteisPodeRemovelosERetornarUmaGLCSemSimbolosInuteis(self):
    glc_ok = construirGLCComABOndeNumAsEhIgualNumBsSemSimbolosInuteis()
    glc_nok = construirGLCComABOndeNumAsEhIgualNumBsComSimbolosInuteis()
    self.assertNotEqual(glc_ok, glc_nok)
    self.assertEqual(glc_ok, util.remover_simbolos_inuteis_glc(glc_nok))
  
  
  def testDadaUmaGLCNaoEpsilonLivrePodeRetornarUmaGLCEpsilonLivre(self):
    glc_ok = construirGLCComABOndeNumAsEhIgualNumBsEpsilonLivre()
    glc_nok = construirGLCComABOndeNumAsEhIgualNumBsComEpsilon()
    self.assertNotEqual(glc_ok, glc_nok)
    self.assertEqual(glc_ok, util.transformar_em_epsilon_livre_glc(glc_nok))
  
  
  def testDadaUmaGLCEpsilonLivreSeTransformarEmEpsilonLivreRetornaAMesmaGramatica(self):
    self.assertEqual(construirGLCComABOndeNumAsEhIgualNumBsEpsilonLivre(), util.transformar_em_epsilon_livre_glc(construirGLCComABOndeNumAsEhIgualNumBsEpsilonLivre()))
    self.assertEqual(construirGLCExpAritmeticaComRecEsquerdaDireta(), util.transformar_em_epsilon_livre_glc(construirGLCExpAritmeticaComRecEsquerdaDireta()))
    
    
  def testDadaUmaGLCComCiclosPodeRetornarUmaGLCSemOsCiclos(self):
    glc_nok = construirGLCComCiclo()
    self.assertTrue(glc_nok.possuiCiclo())
    glc_nok = util.remover_ciclos_glc(glc_nok)
    self.assertFalse(glc_nok.possuiCiclo())
  
  def testDadaUmaGLCSemCiclosSeTentarRemoverCiclosNaoAlteraAGramatica(self):
    self.assertEqual(construirGLCSemCiclo(), util.remover_ciclos_glc(construirGLCSemCiclo()))
  
  def testDadaUmaGLCComRecursaoAEsquerdaDiretaPodeRetornarUmaGLCSemRecursaoAEsquerda(self):
    glc_nok = construirGLCExpAritmeticaComRecEsquerdaDireta()
    self.assertTrue(glc_nok.possuiRecursaoAEsquerda())
    glc_nok = util.remover_recursao_esquerda_glc(glc_nok)
    self.assertFalse(glc_nok.possuiRecursaoAEsquerda())
  
  def testDadaUmaGLCComRecursaoAEsquerdaIndiretaPodeRetornarUmaGLCSemRecursaoAEsquerda(self):
    glc_nok = construirGLCComRecEsquerdaIndireta()
    self.assertTrue(glc_nok.possuiRecursaoAEsquerda())
    glc_nok = util.remover_recursao_esquerda_glc(glc_nok)
    self.assertFalse(glc_nok.possuiRecursaoAEsquerda())
    
  def testDadaUmaGLCNaoFatoradaDiretamentePodeRetornarUmaGLCFatorada(self):
    glc_nok = construirGLCComNaoFatoracaoDireta()
    glc_ok  = construirGLCComNaoFatoracaoDiretaFatorada()
    self.assertTrue(glc_ok.estaFatorada())
    self.assertFalse(glc_nok.estaFatorada())
    self.assertTrue(util.fatorar_glc(glc_nok).estaFatorada())
    self.assertEqual(glc_ok, util.fatorar_glc(glc_nok))
    
  def testDadaUmaGLCNaoFatoradaIndiretamentePodeRetornarUmaGLCFatorada(self):
    glc_nok = construirGLCComNaoFatoracaoIndireta()
    glc_ok  = construirGLCComNaoFatoracaoIndiretaFatorada()
    self.assertTrue(glc_ok.estaFatorada())
    self.assertFalse(glc_nok.estaFatorada())
    self.assertTrue(util.fatorar_glc(glc_nok).estaFatorada())
    self.assertEqual(glc_ok, util.fatorar_glc(glc_nok))
    
if(__name__ == "__main__"):  
  suite = unittest.TestSuite()
  suite.addTest(unittest.makeSuite(TesteUtil))
  unittest.TextTestRunner(verbosity=2).run(suite)
  