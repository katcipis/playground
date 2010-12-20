import unittest
from componentes.Relogio import Relogio

class TesteRelogio(unittest.TestCase):
  
  def setUp(self):
    self.relogioEmZero = Relogio()
    self.umDiaEmMinutos = 1440.0
    self.umDiaEmHoras = 24.0
    self.umDiaEmSegundos = 86400.0
    
  def testSeNaoForPassadoUmTempoInicialIniciaEmZero(self):
    relogioInicial = Relogio()
    self.assertEqual(0.0, relogioInicial.obterEmMinutos())
    self.assertEqual(0.0, relogioInicial.obterEmDias())
    self.assertEqual(0.0, relogioInicial.obterEmHoras())
    self.assertEqual(0.0, relogioInicial.obterEmSegundos())
    
    
  def testAposAdiantadoOTempoAtualSeraOTempoAtualMaisOAdiantamento(self):
    self.relogioEmZero.adiantarMinutos(15.0)
    self.assertEqual(15.0, self.relogioEmZero.obterEmMinutos())
    self.relogioEmZero.adiantarMinutos(15.0)
    self.assertEqual(30.0, self.relogioEmZero.obterEmMinutos())
    self.relogioEmZero.adiantarMinutos(10.0)
    self.assertEqual(40.0, self.relogioEmZero.obterEmMinutos())
    self.relogioEmZero.adiantarMinutos(5.5)
    self.assertEqual(45.5, self.relogioEmZero.obterEmMinutos())
    
  def testPodeAdiantarEmMinutosEObterEmSegundos(self):
    self.relogioEmZero.adiantarMinutos(self.umDiaEmMinutos)
    self.assertEqual(self.umDiaEmSegundos, self.relogioEmZero.obterEmSegundos())
    
  def testPodeAdiantarEmMinutosEObterEmHoras(self):
    self.relogioEmZero.adiantarMinutos(self.umDiaEmMinutos)
    self.assertEqual(self.umDiaEmHoras, self.relogioEmZero.obterEmHoras())
    
  def testPodeAdiantarEmMinutosEObterEmDias(self):
    self.relogioEmZero.adiantarMinutos(self.umDiaEmMinutos)
    self.assertEqual(1.0, self.relogioEmZero.obterEmDias())
    
    
    
  def testPodeAdiantarEmSegundosEObterEmMinutos(self):
    self.relogioEmZero.adiantarSegundos(self.umDiaEmSegundos)
    self.assertEqual(self.umDiaEmMinutos, self.relogioEmZero.obterEmMinutos())
    
  def testPodeAdiantarEmSegundosEObterEmHoras(self):
    self.relogioEmZero.adiantarSegundos(self.umDiaEmSegundos)
    self.assertEqual(self.umDiaEmHoras, self.relogioEmZero.obterEmHoras())
    
  def testPodeAdiantarEmSegundosEObterEmDias(self):
    self.relogioEmZero.adiantarSegundos(self.umDiaEmSegundos)
    self.assertEqual(1.0, self.relogioEmZero.obterEmDias())
    
  
  
  def testPodeAdiantarEmHorasEObterEmMinutos(self):
    self.relogioEmZero.adiantarHoras(self.umDiaEmHoras)
    self.assertEqual(self.umDiaEmMinutos, self.relogioEmZero.obterEmMinutos())
    
  def testPodeAdiantarEmHorasEObterEmSegundos(self):
    self.relogioEmZero.adiantarHoras(self.umDiaEmHoras)
    self.assertEqual(self.umDiaEmSegundos, self.relogioEmZero.obterEmSegundos())
    
  def testPodeAdiantarEmHorasEObterEmDias(self):
    self.relogioEmZero.adiantarHoras(self.umDiaEmHoras)
    self.assertEqual(1.0, self.relogioEmZero.obterEmDias())
    
    
    
  def testPodeAdiantarEmDiasEObterEmMinutos(self):
    self.relogioEmZero.adiantarDias(1.0)
    self.assertEqual(self.umDiaEmMinutos, self.relogioEmZero.obterEmMinutos())
    
  def testPodeAdiantarEmDiasEObterEmSegundos(self):
    self.relogioEmZero.adiantarDias(1.0)
    self.assertEqual(self.umDiaEmSegundos, self.relogioEmZero.obterEmSegundos())
    
  def testPodeAdiantarEmDiasEObterEmHoras(self):
    self.relogioEmZero.adiantarDias(1.0)
    self.assertEqual(self.umDiaEmHoras, self.relogioEmZero.obterEmHoras())
    
 
    
    
#<<<<<EXECUTANDO TESTES>>>>>#  
suite = unittest.TestSuite()
suite.addTest(unittest.makeSuite(TesteRelogio))
unittest.TextTestRunner(verbosity=2).run(suite)