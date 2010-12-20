import unittest
from componentes.ListaDeTempoEntreEventos import ListaDeTempoEntreEventos

class TesteTempoEntreEventos(unittest.TestCase):
  
  def setUp(self):
    self.listaVazia = ListaDeTempoEntreEventos()
    self.tempoUm = 10
    self.tempoDois = 17
    self.tempoTres = 28
    self.tempoQuatro = 33
    self.temposEntreEventos = [self.tempoDois - self.tempoUm, 
                               self.tempoTres - self.tempoDois,
                               self.tempoQuatro - self.tempoTres]
    self.temposParciais = [self.tempoDois - self.tempoUm]
    
  def testAposInformadosOsTemposDeOcorrenciaDosEventosPodeRetornarUmaListaComTodosOsTemposEntreEventos(self):
    self.listaVazia.adcionarTempoDeOcorrencia(self.tempoUm)
    self.listaVazia.adcionarTempoDeOcorrencia(self.tempoDois)
    self.listaVazia.adcionarTempoDeOcorrencia(self.tempoTres)
    self.listaVazia.adcionarTempoDeOcorrencia(self.tempoQuatro)
    
    self.assertEqual(self.temposEntreEventos, self.listaVazia.obterTemposEntreEventos())
    
  def testAsOcorrenciasSaoAcumulativasMesmoDepoisDeTerSidoObtidoUmaListaParcial(self):
    self.listaVazia.adcionarTempoDeOcorrencia(self.tempoUm)
    self.listaVazia.adcionarTempoDeOcorrencia(self.tempoDois)
    
    self.assertEqual(self.temposParciais, self.listaVazia.obterTemposEntreEventos())
    
    self.listaVazia.adcionarTempoDeOcorrencia(self.tempoTres)
    self.listaVazia.adcionarTempoDeOcorrencia(self.tempoQuatro)
    
    self.assertEqual(self.temposEntreEventos, self.listaVazia.obterTemposEntreEventos())
    
  def testSeNaoForInformadaOcorrenciaAlgumaRetornaUmaListaVazia(self):
    self.assertEqual([], self.listaVazia.obterTemposEntreEventos())
    
  def testSeFoiInformadoApenasUmaOcorrenciaRetornaUmaListaVazia(self):
    self.listaVazia.adcionarTempoDeOcorrencia(self.tempoTres)
    self.assertEqual([], self.listaVazia.obterTemposEntreEventos())
    
      
      
      
      
#<<<<<EXECUTANDO TESTES>>>>>#  
suite = unittest.TestSuite()
suite.addTest(unittest.makeSuite(TesteTempoEntreEventos))
unittest.TextTestRunner(verbosity=2).run(suite)