import unittest
from calculadoresDeMedia.TempoMedioDeEntidadesEmAlgo import TempoMedioDeEntidadesEmAlgo

class TesteTempoMedioDeEntidadesEmAlgo(unittest.TestCase):
  
  def setUp(self):
    self.calculadorDeMedia = TempoMedioDeEntidadesEmAlgo()
       
  def testCalculaMediaDireitinho(self):
    self.calculadorDeMedia.adcionarAmostra(30)
    self.calculadorDeMedia.adcionarAmostra(40)
    self.calculadorDeMedia.adcionarAmostra(60)
    
    print 'Tempo medio das entidades em algo: ', self.calculadorDeMedia.obterMedia() 
    
  def testMediaEhAcumulativa(self):
    self.calculadorDeMedia.adcionarAmostra(17)
    self.calculadorDeMedia.adcionarAmostra(15)
    self.calculadorDeMedia.adcionarAmostra(20)
    
    primeiroCalculo = self.calculadorDeMedia.obterMedia()
    segundoCalculo = self.calculadorDeMedia.obterMedia()
    
    self.assertEqual(primeiroCalculo, segundoCalculo)    
    self.calculadorDeMedia.adcionarAmostra(20)
    terceiroCalculo = self.calculadorDeMedia.obterMedia()   
    
    self.assertNotEqual(primeiroCalculo, terceiroCalculo)
    self.assertNotEqual(segundoCalculo, terceiroCalculo)
      
      
      
#<<<<<EXECUTANDO TESTES>>>>>#  
suite = unittest.TestSuite()
suite.addTest(unittest.makeSuite(TesteTempoMedioDeEntidadesEmAlgo))
unittest.TextTestRunner(verbosity=2).run(suite)