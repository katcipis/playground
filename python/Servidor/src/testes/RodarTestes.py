import unittest
from testes.TesteEntidade import TesteEntidade
from testes.TesteEvento import TesteEvento
from testes.TesteListaDeEventosFuturos import TesteListaDeEventosFuturos
from testes.TesteRelogio import TesteRelogio
from TesteGeradorDeNumerosTriangular import TesteGeradorDeNumerosTriangular
from TesteGeradorDeNumerosNormal import TesteGeradorDeNumerosNormal
from TesteGeradorDeNumerosExponencial import TesteGeradorDeNumerosExponencial
from TesteFilaDoServidor import TesteFilaDoServidor
from TesteTempoEntreEventos import TesteTempoEntreEventos
from TesteServidor import TesteServidor

#<<<<<EXECUTANDO TESTES>>>>>#  
suite = unittest.TestSuite()

suite.addTest(unittest.makeSuite(TesteListaDeEventosFuturos))
suite.addTest(unittest.makeSuite(TesteEntidade))
suite.addTest(unittest.makeSuite(TesteEvento))
suite.addTest(unittest.makeSuite(TesteRelogio))
suite.addTest(unittest.makeSuite(TesteGeradorDeNumerosTriangular))
suite.addTest(unittest.makeSuite(TesteGeradorDeNumerosNormal))
suite.addTest(unittest.makeSuite(TesteGeradorDeNumerosExponencial))
suite.addTest(unittest.makeSuite(TesteFilaDoServidor))
suite.addTest(unittest.makeSuite(TesteTempoEntreEventos))
suite.addTest(unittest.makeSuite(TesteServidor))

unittest.TextTestRunner(verbosity=2).run(suite)