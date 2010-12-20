'''
Created on 23/07/2009
@author: katcipis <tiagokatcipis@gmail.com>
'''
from modelo.testes.TestePacienteDAO import TestePacienteDAO
from modelo.testes.TestePacienteVO import TestePacienteVO
import unittest

#<<<<<EXECUTANDO TESTES>>>>>#  
suite = unittest.TestSuite()
suite.addTest(unittest.makeSuite(TestePacienteDAO))
suite.addTest(unittest.makeSuite(TestePacienteVO))
unittest.TextTestRunner(verbosity=2).run(suite)
