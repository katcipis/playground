import unittest
from componentes.ListaDeEventosFuturos import ListaDeEventosFuturos
from componentes.Evento import Evento
from enum import TipoDoEvento

class TesteListaDeEventosFuturos(unittest.TestCase):
  
  def setUp(self):
    self.listaVazia = ListaDeEventosFuturos()
    self.eventoNoTempoCinco = Evento(TipoDoEvento.SAIDA, 5)
    self.eventoNoTempoDez = Evento(TipoDoEvento.ENTRADA, 10)
    self.eventoNoTempoQuinze = Evento(TipoDoEvento.SAIDA, 15)
    self.eventoNoTempoVinte = Evento(TipoDoEvento.ENTRADA, 20)
    
  def testSabeQualEventoOcorrePrimeiroIndependenteDaOrdemQueOsEventosSaoInseridos(self):
    self.listaVazia.adcionarEvento(self.eventoNoTempoQuinze)
    self.listaVazia.adcionarEvento(self.eventoNoTempoDez)
    self.listaVazia.adcionarEvento(self.eventoNoTempoCinco)
    self.listaVazia.adcionarEvento(self.eventoNoTempoVinte)
    
    self.assertEqual(self.eventoNoTempoCinco, self.listaVazia.obterProximoEvento())
    self.assertEqual(self.eventoNoTempoDez, self.listaVazia.obterProximoEvento())
    self.assertEqual(self.eventoNoTempoQuinze, self.listaVazia.obterProximoEvento())
    self.assertEqual(self.eventoNoTempoVinte, self.listaVazia.obterProximoEvento())
    
  def testSabeQualEventoOcorrePrimeiroIndependenteDeQuandoOsEventosSaoInseridos(self):
    self.listaVazia.adcionarEvento(self.eventoNoTempoQuinze)
    self.listaVazia.adcionarEvento(self.eventoNoTempoDez)
    
    self.assertEqual(self.eventoNoTempoDez, self.listaVazia.obterProximoEvento())
    
    self.listaVazia.adcionarEvento(self.eventoNoTempoVinte)
    self.listaVazia.adcionarEvento(self.eventoNoTempoCinco)
    
    self.assertEqual(self.eventoNoTempoCinco, self.listaVazia.obterProximoEvento())
    self.assertEqual(self.eventoNoTempoQuinze, self.listaVazia.obterProximoEvento())
    self.assertEqual(self.eventoNoTempoVinte, self.listaVazia.obterProximoEvento())
    
    
  def testSabeSePossuiEventos(self):
    self.listaVazia.adcionarEvento(self.eventoNoTempoQuinze)
    self.assertTrue(self.listaVazia.possuiEvento())
    
  def testSabeSeNaoPossuiEventos(self):
    self.assertFalse(self.listaVazia.possuiEvento())
    
  def testAposPossuirEventosSabeQuandoNaoPossuiMaisEventos(self):
    self.listaVazia.adcionarEvento(self.eventoNoTempoQuinze)
    self.listaVazia.adcionarEvento(self.eventoNoTempoCinco)
    self.assertTrue(self.listaVazia.possuiEvento())
    self.listaVazia.obterProximoEvento()
    self.listaVazia.obterProximoEvento()
    self.assertFalse(self.listaVazia.possuiEvento())
      
  def testSeNaoPossuiEventosRetornaNone(self):
    self.assertEqual(None, self.listaVazia.obterProximoEvento())
    
  def testSabeQuantosEventosAindaIraoOcorrer(self):
    self.listaVazia.adcionarEvento(self.eventoNoTempoQuinze)
    self.listaVazia.adcionarEvento(self.eventoNoTempoCinco)
    
    self.assertEqual(2, self.listaVazia.obterQuantosEventosRestam())
    self.listaVazia.obterProximoEvento()
    self.assertEqual(1, self.listaVazia.obterQuantosEventosRestam())
    self.listaVazia.obterProximoEvento()
    self.assertEqual(0, self.listaVazia.obterQuantosEventosRestam())
    
  def testSomenteEventosPodemSerInseridos(self):
    self.listaVazia.adcionarEvento(777)
    self.listaVazia.adcionarEvento('Nao sou um evento')
    
    self.assertEqual(0, self.listaVazia.obterQuantosEventosRestam())
    self.assertEqual(None, self.listaVazia.obterProximoEvento())
    
#<<<<<EXECUTANDO TESTES>>>>>#  
suite = unittest.TestSuite()
suite.addTest(unittest.makeSuite(TesteListaDeEventosFuturos))
unittest.TextTestRunner(verbosity=2).run(suite)