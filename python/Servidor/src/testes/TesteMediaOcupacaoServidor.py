import unittest
from calculadoresDeMedia.MediaOcupacaoServidor import MediaOcupacaoServidor

class TesteMediaOcupacaoServidor(unittest.TestCase):
  
  def setUp(self):
    self.calculadorDeMedia = MediaOcupacaoServidor()
       
  def testCalculaMediaDireitinho(self):
    self.calculadorDeMedia.adcionarAmostra(30)
    self.calculadorDeMedia.adcionarAmostra(40)
    self.calculadorDeMedia.adcionarAmostra(50)
    
    print 'Taxa media de ocupacao: ', self.calculadorDeMedia.obterMedia(150) 
    
  def testMediaEhAcumulativa(self):
    self.calculadorDeMedia.adcionarAmostra(17)
    self.calculadorDeMedia.adcionarAmostra(15)
    self.calculadorDeMedia.adcionarAmostra(20)
    
    primeiroCalculo = self.calculadorDeMedia.obterMedia(100)
    segundoCalculo = self.calculadorDeMedia.obterMedia(100)
    
    self.assertEqual(primeiroCalculo, segundoCalculo)    
    self.calculadorDeMedia.adcionarAmostra(20)
    terceiroCalculo = self.calculadorDeMedia.obterMedia(130)   
    
    self.assertNotEqual(primeiroCalculo, terceiroCalculo)
    self.assertNotEqual(segundoCalculo, terceiroCalculo)
      
      
      
#<<<<<EXECUTANDO TESTES>>>>>#  
suite = unittest.TestSuite()
suite.addTest(unittest.makeSuite(TesteMediaOcupacaoServidor))
unittest.TextTestRunner(verbosity=2).run(suite)