import unittest
from calculadoresDeMedia.MediaEntidadesNaFila import MediaEntidadesNaFila

class TesteMediaEntidadesNaFila(unittest.TestCase):
  
  def setUp(self):
    self.calculadorDeMedia = MediaEntidadesNaFila()
       
  def testCalculaMediaDireitinho(self):
    self.calculadorDeMedia.adcionarAmostra(9 , 17)
    self.calculadorDeMedia.adcionarAmostra(11 , 15)
    self.calculadorDeMedia.adcionarAmostra(15 , 20)
    
    print 'Media de entidade na fila: ', self.calculadorDeMedia.obterMedia() 
    
  def testMediaEhAcumulativa(self):
    self.calculadorDeMedia.adcionarAmostra(9 , 17)
    self.calculadorDeMedia.adcionarAmostra(11 , 15)
    self.calculadorDeMedia.adcionarAmostra(15 , 20)
    
    primeiroCalculo = self.calculadorDeMedia.obterMedia()
    segundoCalculo = self.calculadorDeMedia.obterMedia()
    
    self.assertEqual(primeiroCalculo, segundoCalculo)    
    self.calculadorDeMedia.adcionarAmostra(15 , 20)
    terceiroCalculo = self.calculadorDeMedia.obterMedia()   
    
    self.assertNotEqual(primeiroCalculo, terceiroCalculo)
    self.assertNotEqual(segundoCalculo, terceiroCalculo)
      
      
      
#<<<<<EXECUTANDO TESTES>>>>>#  
suite = unittest.TestSuite()
suite.addTest(unittest.makeSuite(TesteMediaEntidadesNaFila))
unittest.TextTestRunner(verbosity=2).run(suite)