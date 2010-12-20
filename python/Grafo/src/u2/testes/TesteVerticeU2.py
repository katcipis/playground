# -*- coding: latin-1 -*-
import unittest
from u2.VerticeU2 import VerticeU2
from u2.IntegranteU2 import IntegranteU2
from sets import Set

class TesteVerticeU2(unittest.TestCase):
  """Teste do Vertice do U2"""
  
  def setUp(self):
    self.integrantes_um = Set()
    self.integrantes_um.add(IntegranteU2('Bono', 2))
    self.integrantes_um.add(IntegranteU2('Larry', 10))
    
    self.integrantes_dois = Set()
    self.integrantes_dois.add(IntegranteU2('Bono', 2))
    self.integrantes_dois.add(IntegranteU2('Larry', 10))
    self.integrantes_dois.add(IntegranteU2('John', 5))
    
    self.vertice_um = VerticeU2(self.integrantes_um)
    self.vertice_dois = VerticeU2(self.integrantes_dois, True)
  
  def testEhIgualAOutroVerticeSeTemOsMesmoIntegrantesEMesmoEstadoDaLanterna(self):
    self.assertEquals(self.vertice_um, VerticeU2(self.integrantes_um))
    self.assertEquals(self.vertice_dois, VerticeU2(self.integrantes_dois, True))
    
  def testNaoEhIgualAOutroVerticeSeNaoTemOsMesmoIntegrantes(self):
    self.assertNotEquals(self.vertice_um, VerticeU2(self.integrantes_dois, True))
    self.assertNotEquals(self.vertice_dois, VerticeU2(self.integrantes_um))
    self.assertNotEquals(self.vertice_dois, self.vertice_um)
    
  def testNaoEhIgualAOutroVerticeSeNaoTemOMesmoEstadoDaLanterna(self):
    self.assertNotEquals(self.vertice_um, VerticeU2(self.integrantes_um, True))
    self.assertNotEquals(self.vertice_dois, VerticeU2(self.integrantes_dois))
    
  def testSabeQuaisSaoSeusIntegrantes(self):
    self.assertEquals(self.vertice_um.ObterIntegrantes(), self.integrantes_um)
    self.assertEquals(self.vertice_dois.ObterIntegrantes(), self.integrantes_dois)
    
  def testSabeQuaisNaoSaoSeusIntegrantes(self):
    self.assertNotEquals(self.vertice_um.ObterIntegrantes(), self.integrantes_dois)
    self.assertNotEquals(self.vertice_dois.ObterIntegrantes(), self.integrantes_um)
      
 
    

#<<<<<EXECUTANDO TESTES>>>>>#  
suite = unittest.TestSuite()
suite.addTest(unittest.makeSuite(TesteVerticeU2))
unittest.TextTestRunner(verbosity=2).run(suite)