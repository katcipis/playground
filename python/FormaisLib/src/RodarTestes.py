'''
Created on 02/10/2009
@author: katcipis
'''

import unittest
from automato_finito.testes.TesteEstado import TesteEstado
from automato_finito.testes.TesteAutomatoFinito import TesteAutomatoFinito
from util.testes.TesteUtil import TesteUtil
from automato_finito.testes.TesteTransicao import TesteTransicao
from expressao_regular.testes.TesteExpressaoRegular import TesteExpressaoRegular
from gramatica.testes.TesteProducao import TesteProducao
from gramatica.testes.TesteGramatica import TesteGramatica
from gramatica.testes.TesteGramaticaRegular import TesteGramaticaRegular
from gramatica.testes.TesteGramaticaLivreContexto import TesteGramaticaLivreContexto

if(__name__ == "__main__"):  
  suite = unittest.TestSuite()
  suite.addTest(unittest.makeSuite(TesteEstado))
  suite.addTest(unittest.makeSuite(TesteAutomatoFinito))
  suite.addTest(unittest.makeSuite(TesteTransicao))
  suite.addTest(unittest.makeSuite(TesteExpressaoRegular))
  suite.addTest(unittest.makeSuite(TesteProducao))
  suite.addTest(unittest.makeSuite(TesteGramatica))
  suite.addTest(unittest.makeSuite(TesteGramaticaRegular))
  suite.addTest(unittest.makeSuite(TesteGramaticaLivreContexto))
  suite.addTest(unittest.makeSuite(TesteUtil))
  unittest.TextTestRunner(verbosity=2).run(suite)