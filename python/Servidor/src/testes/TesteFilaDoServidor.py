import unittest
from componentes.FilaDoServidor import FilaDoServidor
from componentes.Entidade import Entidade
from enum import TipoDaEntidade

class TesteFilaDoServidor(unittest.TestCase):
  
  def setUp(self):
    self.filaVazia = FilaDoServidor()
    self.entidadeUm = Entidade(TipoDaEntidade.TIPO_UM, 'Um')
    self.entidadeDois = Entidade(TipoDaEntidade.TIPO_DOIS, 'Dois')
    self.entidadeTres = Entidade(TipoDaEntidade.TIPO_UM, 'Tres')
    
  def testAsEntidadesSaoObtidasPelaOrdemDeEntrada(self):
    self.filaVazia.adcionarEntidade(self.entidadeUm)
    self.filaVazia.adcionarEntidade(self.entidadeDois)
    self.filaVazia.adcionarEntidade(self.entidadeTres)
    
    self.assertEqual(self.entidadeUm, self.filaVazia.obterEntidade())
    self.assertEqual(self.entidadeDois, self.filaVazia.obterEntidade())
    self.assertEqual(self.entidadeTres, self.filaVazia.obterEntidade())
    
  def testAposObterUmaEntidadeAEntidadeSeraRemovidaDaFila(self):
    self.filaVazia.adcionarEntidade(self.entidadeUm)
    self.filaVazia.adcionarEntidade(self.entidadeDois)
  
    self.assertEqual(2, self.filaVazia.obterQuantasEntidadesPossui())
    self.filaVazia.obterEntidade()
    self.assertEqual(1, self.filaVazia.obterQuantasEntidadesPossui())
    
  def testSabeQuantasEntidadesPossui(self):
    self.filaVazia.adcionarEntidade(self.entidadeUm)
    self.filaVazia.adcionarEntidade(self.entidadeDois)
  
    self.assertEqual(2, self.filaVazia.obterQuantasEntidadesPossui())
    
  def testSabeSeNaoEstaVazia(self):
    self.filaVazia.adcionarEntidade(self.entidadeUm)
    self.assertFalse(self.filaVazia.estaVazia())
    
  def testSabeSeEstaVazia(self):
    self.assertTrue(self.filaVazia.estaVazia())
    
    self.filaVazia.adcionarEntidade(self.entidadeUm)
    self.assertFalse(self.filaVazia.estaVazia())
    
    self.filaVazia.obterEntidade()
    self.assertTrue(self.filaVazia.estaVazia())
    
  def testAMesmaEntidadeNaoPodeSerAdcionadaNaFilaNovamenteEnquantoElaNaoSairDaMesma(self):
    self.filaVazia.adcionarEntidade(self.entidadeUm)
    self.assertEqual(1, self.filaVazia.obterQuantasEntidadesPossui())
    self.filaVazia.adcionarEntidade(self.entidadeUm)
    self.assertEqual(1, self.filaVazia.obterQuantasEntidadesPossui())
    self.filaVazia.obterEntidade()
    self.assertEqual(0, self.filaVazia.obterQuantasEntidadesPossui())
    self.filaVazia.adcionarEntidade(self.entidadeUm)  
    self.assertEqual(1, self.filaVazia.obterQuantasEntidadesPossui())
    
  def testSePossuiUmLimiteSabeQuandoEstaCheia(self):
    filaTamanhoTres = FilaDoServidor(3)
    filaTamanhoTres.adcionarEntidade(self.entidadeUm)
    filaTamanhoTres.adcionarEntidade(self.entidadeDois)
    filaTamanhoTres.adcionarEntidade(self.entidadeTres)
    self.assertTrue(filaTamanhoTres.estaCheia())
    
  def testSePossuiUmLimiteSabeQuandoNaoEstaCheia(self):
    filaTamanhoQuatro = FilaDoServidor(4)
    filaTamanhoQuatro.adcionarEntidade(self.entidadeUm)
    filaTamanhoQuatro.adcionarEntidade(self.entidadeDois)
    filaTamanhoQuatro.adcionarEntidade(self.entidadeTres)
    self.assertFalse(filaTamanhoQuatro.estaCheia())
    
  def testSePossuiUmLimiteNaoInsereMaisNenhumaEntidadeSeEstaCheia(self):
    filaTamanhoDois = FilaDoServidor(2)
    filaTamanhoDois.adcionarEntidade(self.entidadeUm)
    filaTamanhoDois.adcionarEntidade(self.entidadeDois)
    self.assertEqual(2, filaTamanhoDois.obterQuantasEntidadesPossui())
    filaTamanhoDois.adcionarEntidade(self.entidadeTres)
    self.assertEqual(2, filaTamanhoDois.obterQuantasEntidadesPossui())
    
  def testSePossuiUmLimiteEFicarCheiaAposRemoverUmaEntidadeNaoEstaMaisCheia(self):
    filaTamanhoTres = FilaDoServidor(3)
    filaTamanhoTres.adcionarEntidade(self.entidadeUm)
    filaTamanhoTres.adcionarEntidade(self.entidadeDois)
    filaTamanhoTres.adcionarEntidade(self.entidadeTres)
    self.assertTrue(filaTamanhoTres.estaCheia())
    filaTamanhoTres.obterEntidade()
    self.assertFalse(filaTamanhoTres.estaCheia())
    
  def testSeNaoPossuiLimitesNuncaFicaCheia(self):
    filaSemLimite = FilaDoServidor()
    for i in range(1000):
      filaSemLimite.adcionarEntidade(Entidade('Entidade: ' + str(i)))
      
    self.assertFalse(filaSemLimite.estaCheia())
    self.assertEqual(1000, filaSemLimite.obterQuantasEntidadesPossui())
    
      
#<<<<<EXECUTANDO TESTES>>>>>#  
suite = unittest.TestSuite()
suite.addTest(unittest.makeSuite(TesteFilaDoServidor))
unittest.TextTestRunner(verbosity=2).run(suite)