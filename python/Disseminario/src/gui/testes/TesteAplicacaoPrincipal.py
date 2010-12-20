# -*- coding: latin-1 -*-
import unittest
from gui.AplicacaoPrincipal import ConstrutorAplicacaoPrincipal

class TesteAplicacaoPrincipal(unittest.TestCase):
  
  def setUp(self):
    self.aplicacao_um   = ConstrutorAplicacaoPrincipal().obterAplicacaoPrincipal()
    self.aplicacao_dois = ConstrutorAplicacaoPrincipal().obterAplicacaoPrincipal()
    self.aplicacao_tres = ConstrutorAplicacaoPrincipal().obterAplicacaoPrincipal()
  
  def testSohExisteUmaInstanciaDaAplicacaoPrincipal(self):
    self.assertEquals(self.aplicacao_um, self.aplicacao_dois, self.aplicacao_tres)
  
#<<<<<EXECUTANDO TESTES>>>>>#  
suite = unittest.TestSuite()
suite.addTest(unittest.makeSuite(TesteAplicacaoPrincipal))
unittest.TextTestRunner(verbosity=2).run(suite)
