'''
Created on 30/10/2009
@author: katcipis
'''
import unittest

class TesteAbstratoGramatica(unittest.TestCase):
  
  def obterGramaticas(self):
    '''
    Metodo virtual que DEVE ser implementado pela classe que sera testada.
    deve retornar duas instancias validas da gramatica, que DEVEM ser diferentes em todos os aspectos.
    '''
    
  def testSabeQuaisAsSuasProducoes(self):
    gramatica = self.obterGramaticas()[0]
    prod = gramatica.obterProducoes()
    self.assertEqual(prod, gramatica.obterProducoes())  
  
  def testSabeQuaisNaoSaoAsSuasProducoes(self):
    gramatica = self.obterGramaticas()[0]
    gramatica2 = self.obterGramaticas()[1]
    self.assertNotEqual(gramatica2.obterProducoes(), gramatica.obterProducoes()) 
  
  def testSabeQualSeuConjuntoDeNaoTerminais(self):
    gramatica = self.obterGramaticas()[0]
    vn = gramatica.obterNaoTerminais()
    self.assertEqual(vn, gramatica.obterNaoTerminais())  
  
  def testSabeQualNaoEhSeuConjuntoDeNaoTerminais(self):
    gramatica = self.obterGramaticas()[0]
    gramatica2 = self.obterGramaticas()[1]
    self.assertNotEqual(gramatica2.obterNaoTerminais(), gramatica.obterNaoTerminais())
 
  def testSabeQualSeuConjuntoDeTerminais(self):
    gramatica = self.obterGramaticas()[0]
    vt = gramatica.obterTerminais()
    self.assertEqual(vt, gramatica.obterTerminais())
  
  def testSabeQualNaoEhSeuConjuntoDeTerminais(self):
    gramatica = self.obterGramaticas()[0]
    gramatica2 = self.obterGramaticas()[1]
    self.assertNotEqual(gramatica2.obterTerminais(), gramatica.obterTerminais())
  
  def testSabeQualSeuSimboloInicial(self):
    gramatica = self.obterGramaticas()[0]
    s = gramatica.obterSimboloInicial()
    self.assertEqual(s, gramatica.obterSimboloInicial())  
    
  def testSabeQualNaoEhSeuSimboloInicial(self):
    gramatica = self.obterGramaticas()[0]
    gramatica2 = self.obterGramaticas()[1]
    self.assertNotEqual(gramatica2.obterSimboloInicial(), gramatica.obterSimboloInicial())
  
  def testRetornaUmaCopiaDoConjuntoDeNaoTerminaisInformados(self):
    gramatica = self.obterGramaticas()[0]
    vn = gramatica.obterNaoTerminais()
    self.assertEqual(vn, gramatica.obterNaoTerminais())
    vn.pop()  
    self.assertNotEqual(vn, gramatica.obterNaoTerminais())
    
  def testRetornaUmaCopiaDoConjuntoDeTerminaisInformados(self):
    gramatica = self.obterGramaticas()[0]
    vt = gramatica.obterTerminais()
    self.assertEqual(vt, gramatica.obterTerminais())
    vt.pop()
    self.assertNotEqual(vt, gramatica.obterTerminais())
    
  def testRetornaUmaCopiaDoConjuntoDeProducoesInformados(self):
    gramatica = self.obterGramaticas()[0]
    prod = gramatica.obterProducoes()
    self.assertEqual(prod, gramatica.obterProducoes())
    prod.pop()
    self.assertNotEqual(prod, gramatica.obterProducoes())
    
  
