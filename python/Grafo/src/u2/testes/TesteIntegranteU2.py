# -*- coding: latin-1 -*-
import unittest
from u2.IntegranteU2 import IntegranteU2

class TesteIntegranteU2(unittest.TestCase):
  """Teste do Integrante do U2"""
  
  def setUp(self):
    self.nome_bono = 'Bono'
    self.vel_bono = 2
    self.bono = IntegranteU2('Bono', 2)
    self.larry = IntegranteU2('Larry', 10)
  
  def testSabeQualSeuNome(self):
    self.assertEquals(self.nome_bono, self.bono.ObterNome())
      
  def testSabeQualNaoEhSeuNome(self):
    self.assertNotEquals('Qualquer', self.bono.ObterNome())
      
  def testSabeQualSuaVelocidade(self):
    self.assertEquals(self.vel_bono, self.bono.ObterVelocidade())
      
  def testSabeQualNaoEhSuaVelocidade(self):
    self.assertNotEquals(-20, self.bono.ObterVelocidade())
      
  def testUmIntegranteEhIgualAoOutroSeOSeuNomeEhOMesmo(self):
    self.assertEquals(self.bono, IntegranteU2('Bono', 2))
    self.assertEquals(self.bono, IntegranteU2('Bono', 10))
    self.assertNotEquals(self.bono, self.larry)
    self.assertEquals(self.larry, IntegranteU2('Larry', 10))
    

#<<<<<EXECUTANDO TESTES>>>>>#  
suite = unittest.TestSuite()
suite.addTest(unittest.makeSuite(TesteIntegranteU2))
unittest.TextTestRunner(verbosity=2).run(suite)