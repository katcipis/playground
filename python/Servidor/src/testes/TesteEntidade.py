import unittest
from componentes.Entidade import SEM_ID
from componentes.Entidade import Entidade
from enum import TipoDaEntidade
from enum import EstadoDaEntidade

class TesteEntidade(unittest.TestCase):
  
  def setUp(self):
    self.idEntidadeUm = 'Entidade 1'
    
    self.entidadeTipoUm = Entidade(TipoDaEntidade.TIPO_UM, self.idEntidadeUm)
    
    self.entidadeTipoDois = Entidade(TipoDaEntidade.TIPO_DOIS)
    self.entidadeSemId = Entidade(TipoDaEntidade.TIPO_UM)
    
  def testSabeQualSeuTipo(self):
    self.assertEqual(TipoDaEntidade.TIPO_UM, self.entidadeTipoUm.obterTipo())
    self.assertEqual(TipoDaEntidade.TIPO_DOIS, self.entidadeTipoDois.obterTipo())
    
  def testSabeQualNaoEhOSeuTipo(self):
    self.assertNotEqual(TipoDaEntidade.TIPO_DOIS, self.entidadeTipoUm.obterTipo())
    self.assertNotEqual(TipoDaEntidade.TIPO_UM, self.entidadeTipoDois.obterTipo())
    
  def testSabeQualSeuID(self):
    self.assertEqual(self.idEntidadeUm, self.entidadeTipoUm.obterID())
    
  def testSabeQualNaoEhSeuID(self):
    self.assertNotEqual(self.idEntidadeUm, self.entidadeTipoDois.obterID())
    
  def testSeUmIdNaoForInformadoOIdSeraSemId(self):
    self.assertEqual(SEM_ID, self.entidadeSemId.obterID())
    
  def testEstadoInicialDaEntidadeEhNaoServida(self):
    entidadeInicial = Entidade(TipoDaEntidade.TIPO_UM)
    self.assertTrue(entidadeInicial.naoEstaServida())
    
  def testAposSerServidaSeuEstadoSeraServida(self):
    self.entidadeTipoUm.marcarComoServida()
    self.assertTrue(self.entidadeTipoUm.estaServida())
    
  def testAposFalharSeuEstadoSeraFalhou(self):
    self.entidadeTipoUm.marcarComoFalha()
    self.assertTrue(self.entidadeTipoUm.falhou())
    
  def testSaoIguaisSePossuemMesmoIdEMesmoTipo(self):
    self.assertEqual(self.entidadeTipoUm, Entidade(TipoDaEntidade.TIPO_UM, self.idEntidadeUm))
    
  def testSaoDiferentesSePossuemMesmoIdETipoDiferente(self):
    self.assertNotEqual(self.entidadeTipoUm, Entidade(TipoDaEntidade.TIPO_DOIS, self.idEntidadeUm))
    
  def testSaoDiferentesSePossuemMesmoTipoEIdDiferente(self):
    self.assertNotEqual(self.entidadeTipoUm, Entidade(TipoDaEntidade.TIPO_UM, "Id qualquer"))
    
  def testSaoDiferentesSePossuemIdETiposDiferentes(self):
    self.assertNotEqual(self.entidadeTipoUm, Entidade(TipoDaEntidade.TIPO_DOIS, "Id qualquer"))  
    
#<<<<<EXECUTANDO TESTES>>>>>#  
suite = unittest.TestSuite()
suite.addTest(unittest.makeSuite(TesteEntidade))
unittest.TextTestRunner(verbosity=2).run(suite)
    