from grafo.testes.TesteDigrafo import TesteDigrafo
from grafo.testes.TesteDigrafoValorado import TesteDigrafoValorado
from grafo.testes.TesteGrafo import TesteGrafo
from grafo.testes.TesteGrafoValorado import TesteGrafoValorado
from grafo.testes.TesteArco import TesteArco
from grafo.testes.TesteArcoComCapacidadeMaxima import TesteArcoComCapacidadeMaxima
from grafo.testes.TesteAresta import TesteAresta
from grafo.testes.TesteRede import TesteRede
import unittest

suite = unittest.TestSuite()

suite.addTest(unittest.makeSuite(TesteDigrafo))
suite.addTest(unittest.makeSuite(TesteDigrafoValorado))
suite.addTest(unittest.makeSuite(TesteGrafo))
suite.addTest(unittest.makeSuite(TesteGrafoValorado))
suite.addTest(unittest.makeSuite(TesteArco))
suite.addTest(unittest.makeSuite(TesteAresta))
suite.addTest(unittest.makeSuite(TesteArcoComCapacidadeMaxima))
suite.addTest(unittest.makeSuite(TesteRede))

unittest.TextTestRunner(verbosity=2).run(suite)