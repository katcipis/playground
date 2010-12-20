import unittest
from componentes.Servidor import Servidor
from componentes.Servidor import ID_NULO
from enum import TipoDaEntidade
from enum import EstadoDaEntidade
from componentes.Entidade import Entidade

class TesteServidor(unittest.TestCase):
  
  def setUp(self):
    self.idServidorVazio = 'ID 1'
    self.servidor = Servidor('ID 1')
    self.entidadeUm = Entidade(TipoDaEntidade.TIPO_UM, 'UM')
    self.entidadeDois = Entidade(TipoDaEntidade.TIPO_DOIS, 'DOIS')
    
  def testEstadoInicialDoServidorEhLivre(self):
    self.assertTrue(self.servidor.estaLivre())
    
  def testQuandoEstaLivreNaoEstaOcupadoNemEmFalha(self):
    self.assertTrue(self.servidor.estaLivre())
    self.assertFalse(self.servidor.estaOcupado())
    self.assertFalse(self.servidor.estaEmFalha())
    
  def testQuandoEstaOcupadoNaoEstaEmFalhaNemLivre(self):
    self.servidor.servirEntidade(self.entidadeUm)
    self.assertFalse(self.servidor.estaLivre())
    self.assertTrue(self.servidor.estaOcupado())
    self.assertFalse(self.servidor.estaEmFalha())
    
  def testQuandoEstaEmFalhaNaoEstaOcupadoNemLivre(self):
    self.servidor.falhar()
    self.assertFalse(self.servidor.estaLivre())
    self.assertFalse(self.servidor.estaOcupado())
    self.assertTrue(self.servidor.estaEmFalha())
    
  def testAssimQueRecebeUmaEntidadePassaAAtenderAMesmaESeuEstadoSeraOcupado(self):
    self.servidor.servirEntidade(self.entidadeUm)
    self.assertTrue(self.servidor.estaOcupado())
    
  def testSabeQualOSeuId(self):
    self.assertEqual(self.idServidorVazio, self.servidor.obterId())
    
  def testSeNaoForInformadoUmIdOIdSeraID_NULO(self):
    servidorSemId = Servidor()
    self.assertEqual(ID_NULO, servidorSemId.obterId())
    
  def testSeNaoEstaServindoNinguemAEntidadeSendoServidaEhNone(self):
    self.assertTrue(self.servidor.estaLivre())
    self.assertEqual(None, self.servidor.obterEntidadeSendoServida())
    
  def testSeEstaServindoUmaEntidadeRetornaAMesmaEntidadeMarcadaComoServida(self):
    self.assertTrue(self.entidadeUm.naoEstaServida())
    self.servidor.servirEntidade(self.entidadeUm)
    self.assertEqual(self.entidadeUm, self.servidor.obterEntidadeSendoServida())
    self.assertTrue(self.servidor.obterEntidadeSendoServida().estaServida())
    
  def testSeEstaServindoUmaEntidadeSohPoderaServirOutraEntidadeQuandoTerminarOServico(self):
    self.servidor.servirEntidade(self.entidadeUm)
    self.assertEqual(self.entidadeUm, self.servidor.obterEntidadeSendoServida())
    self.servidor.servirEntidade(self.entidadeDois)
    self.assertEqual(self.entidadeUm, self.servidor.obterEntidadeSendoServida())
    
  def testAposTerminarDeServirUmaEntidadeAEntidadeSendoServidaSeraNone(self):
    self.servidor.servirEntidade(self.entidadeUm)
    self.assertNotEqual(None, self.servidor.obterEntidadeSendoServida())
    self.servidor.terminarServico()
    self.assertEqual(None, self.servidor.obterEntidadeSendoServida())
    
  def testAposTerminarOServicoSeuEstadoVoltaASerLivre(self):
    self.servidor.servirEntidade(self.entidadeUm)
    self.assertTrue(self.servidor.estaOcupado())
    self.servidor.terminarServico()
    self.assertTrue(self.servidor.estaLivre())
    
  def testSeEstaEmFalhaNaoPodeServirUmaEntidade(self):
    self.servidor.falhar()
    self.servidor.servirEntidade(self.entidadeUm)
    self.assertFalse(self.servidor.estaOcupado())
    self.assertEqual(None, self.servidor.obterEntidadeSendoServida())
      
  def testSeEstaEmFalhaAposVoltarAFuncionarPodeVoltarAAtenderEntidades(self):
    self.servidor.falhar()
    self.servidor.funcionar()
    self.servidor.servirEntidade(self.entidadeUm)
    self.assertTrue(self.servidor.estaOcupado())
    self.assertEqual(self.entidadeUm, self.servidor.obterEntidadeSendoServida())
    
  def testSeEstaOcupadoEMandarFuncionarNaoOcorreNada(self):
    self.servidor.servirEntidade(self.entidadeUm)
    self.assertTrue(self.servidor.estaOcupado())
    self.servidor.funcionar()
    self.assertTrue(self.servidor.estaOcupado())
    self.assertEqual(self.entidadeUm, self.servidor.obterEntidadeSendoServida())
    
  def testSeEntrarEmFalhaEnquantoServeUmaEntidadeAEntidadeSeraMarcadaComFalha(self):
    self.servidor.servirEntidade(self.entidadeUm)
    self.assertTrue(self.servidor.estaOcupado())
    self.assertEqual(self.entidadeUm, self.servidor.obterEntidadeSendoServida())
    self.servidor.falhar()
    self.assertEqual(self.entidadeUm, self.servidor.obterEntidadeSendoServida())
    self.assertTrue(self.servidor.obterEntidadeSendoServida().falhou())
    
  
    
    
#<<<<<EXECUTANDO TESTES>>>>>#  
suite = unittest.TestSuite()
suite.addTest(unittest.makeSuite(TesteServidor))
unittest.TextTestRunner(verbosity=2).run(suite)