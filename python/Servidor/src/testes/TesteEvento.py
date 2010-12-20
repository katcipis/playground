import unittest
from componentes.Entidade import Entidade
from componentes.Evento import Evento
from enum import TipoDaEntidade
from enum import TipoDoEvento

class TesteEvento(unittest.TestCase):
  
  def setUp(self):
    self.tempoEventoUm = 15
    self.tipoEventoUm = TipoDoEvento.ENTRADA 
    
    self.outroTipo = TipoDoEvento.SAIDA
    self.outroTempo = 20
    
    self.eventoSemEntidade = Evento(self.tipoEventoUm, self.tempoEventoUm)
    self.eventoUmComEntidade = Evento(self.tipoEventoUm, self.tempoEventoUm)
    self.entidadeEventoUm = Entidade(TipoDaEntidade.TIPO_UM)
    self.eventoUmComEntidade.designarEntidade(self.entidadeEventoUm)
    
    
  def testSabeQualOTempoQueIraOcorrer(self):
    self.assertEqual(self.eventoUmComEntidade.obterTempoQueOcorre(), self.tempoEventoUm)
    
  def testSabeQualOTempoQueNaoIraOcorrer(self):
    self.assertNotEqual(self.eventoUmComEntidade.obterTempoQueOcorre(), self.outroTempo)
    
  def testSabeQualOSeuTipo(self):
    self.assertEqual(self.eventoUmComEntidade.obterTipo(), self.tipoEventoUm)
    
  def testSabeQualNaoEhOSeuTipo(self):
    self.assertNotEqual(self.eventoUmComEntidade.obterTipo(), self.outroTipo)
    
  def testSabeSePossuiUmaEntidadeAssociada(self):
    self.assertTrue(self.eventoUmComEntidade.possuiEntidade())
    
  def testSabeSePossuiUmaEntidadeAssociada(self):
    self.assertFalse(self.eventoSemEntidade.possuiEntidade())
    
  def testSePossuiUmaEntidadeSabeQualEh(self):
    self.assertEqual(self.eventoUmComEntidade.obterEntidade(), self.entidadeEventoUm)
    
  def testSePossuiUmaEntidadeSabeQualNaoEh(self):
    self.assertNotEqual(self.eventoUmComEntidade.obterEntidade(), Entidade(TipoDaEntidade.TIPO_DOIS, 'qualquer'))
      
  def testSeNaoPossuiUmaEntidadeAEntidadeSeraNone(self):
    self.assertEqual(self.eventoSemEntidade.obterEntidade(), None)
    
    
#<<<<<EXECUTANDO TESTES>>>>>#  
suite = unittest.TestSuite()
suite.addTest(unittest.makeSuite(TesteEvento))
unittest.TextTestRunner(verbosity=2).run(suite)