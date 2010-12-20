# -*- coding: utf-8 -*-
'''
Created on 10/04/2009
@author: katcipis
'''
import unittest
import datetime
from modelo.EnderecoVO import EnderecoVO
from modelo.PacienteDAO import PacienteDAO
from modelo.PacienteVO import PacienteVO
from abstrato.ParametroDePesquisa import ParametroDePesquisa
from banco_dados import inicia_bd
from banco_dados.TabelaPacienteSQLite import TabelaPacienteSQLite
from abstrato.DataNascimento import DataNascimento

class TestePacienteDAO(unittest.TestCase):

  def setUp(self):
    inicia_bd.iniciar_bd()
    
    self.pacienteDAO = PacienteDAO()
    self.enderecoPaciente = EnderecoVO('Rua: Antonio Carlos',
                                       200, 'Casa')
    self.parametroNomeTiago = ParametroDePesquisa(TabelaPacienteSQLite().obterCampoNome(), 'Tiago')
    self.parametroNomePacienteInexistente = ParametroDePesquisa(TabelaPacienteSQLite().obterCampoNome(),'FulanoInexistenteBlaBla')
    
    self.pacienteTiago = PacienteVO('Tiago', DataNascimento(datetime.date(1986, 6, 23)),
                               3, 5,7, self.enderecoPaciente)
    self.outroPacienteTiago = PacienteVO('Tiago', DataNascimento(datetime.date(1970, 6, 23)),
                               1, 2,5, self.enderecoPaciente)
    
  def tearDown(self):
    self.pacienteDAO.remover(self.pacienteTiago)
    self.pacienteDAO.remover(self.outroPacienteTiago)
    
  
  def testSeONomeDeUmPacienteNaoForEncontradoRetornaUmaListaVazia(self):
    self.assertEqual([], self.pacienteDAO.buscar(self.parametroNomePacienteInexistente))
    
  def testAposInserirUmPacienteEleFicaSalvo(self):
    self.pacienteDAO.salvar(self.pacienteTiago)
    resultado = self.pacienteDAO.buscar(self.parametroNomeTiago)
    self.assertNotEqual([], resultado)
    self.assertTrue(self.pacienteTiago in resultado)
  
    
  def testPodeListarTodosOsPacientesExistentesNoBancoDeDados(self):
    self.pacienteDAO.salvar(self.pacienteTiago)
    self.pacienteDAO.salvar(self.outroPacienteTiago)
    self.pacienteDAO.salvar(self.outroPacienteTiago)
    resultado = self.pacienteDAO.buscar(self.parametroNomeTiago)
    
    self.assertNotEqual(self.pacienteTiago, self.outroPacienteTiago)
    self.assertEqual(2, len(resultado))
    self.assertTrue(self.pacienteTiago in resultado)
    self.assertTrue(self.outroPacienteTiago in resultado)
    
  def testAposSerRemovidoUmPacienteNaoSeEncontraMaisNoSistema(self):
    self.assertFalse(self.pacienteTiago in self.pacienteDAO.buscar(self.parametroNomeTiago))
    self.pacienteDAO.salvar(self.pacienteTiago)
    self.assertTrue(self.pacienteTiago in self.pacienteDAO.buscar(self.parametroNomeTiago))
    self.pacienteDAO.remover(self.pacienteTiago)
    self.assertFalse(self.pacienteTiago in self.pacienteDAO.buscar(self.parametroNomeTiago))
    
  def testSeExistemDoisPacientesComMesmoNomeSeUmEhRemovidoOOutroPermanece(self):
    self.assertFalse(self.pacienteTiago in self.pacienteDAO.buscar(self.parametroNomeTiago))
    self.assertFalse(self.outroPacienteTiago in self.pacienteDAO.buscar(self.parametroNomeTiago))
    
    self.pacienteDAO.salvar(self.pacienteTiago)
    self.pacienteDAO.salvar(self.outroPacienteTiago)
    
    self.assertTrue(self.pacienteTiago in self.pacienteDAO.buscar(self.parametroNomeTiago))
    self.assertTrue(self.outroPacienteTiago in self.pacienteDAO.buscar(self.parametroNomeTiago))
    
    self.pacienteDAO.remover(self.pacienteTiago)
    self.assertFalse(self.pacienteTiago in self.pacienteDAO.buscar(self.parametroNomeTiago))
    self.assertTrue(self.outroPacienteTiago in self.pacienteDAO.buscar(self.parametroNomeTiago))
    
  def testPodeListarTodosOsPacientesComMesmoNome(self):
    self.pacienteDAO.salvar(self.pacienteTiago)
    self.pacienteDAO.salvar(self.outroPacienteTiago)
    resultado = self.pacienteDAO.buscar(self.parametroNomeTiago)
    
    self.assertNotEqual(self.pacienteTiago, self.outroPacienteTiago)
    self.assertEqual(2, len(resultado))
    self.assertTrue(self.pacienteTiago in resultado)
    self.assertTrue(self.outroPacienteTiago in resultado)
    
    
  def testABuscaPorNomeEhCaseSensitive(self):
    tiago = PacienteVO('Tiago', DataNascimento(datetime.date(1986, 6, 23)),
                                 3, 50,7, EnderecoVO('Rua: Antonio Carlos', 200, 'Casa'))
    outroTiago = PacienteVO('tiago',DataNascimento( datetime.date(1986, 6, 23)),
                                 3, 50,7, EnderecoVO('Rua: Antonio Carlos', 200, 'Casa'))
    
    self.assertNotEqual(tiago, outroTiago)
    
    self.pacienteDAO.salvar(tiago)
    self.pacienteDAO.salvar(outroTiago)
    
    parametro = ParametroDePesquisa(TabelaPacienteSQLite().obterCampoNome(), tiago.obterNome())
    resultado = self.pacienteDAO.buscar(parametro)
    self.assertEqual(1, len(resultado))
    self.assertTrue(tiago in resultado)
    
    parametro = ParametroDePesquisa(TabelaPacienteSQLite().obterCampoNome(), outroTiago.obterNome())
    resultado = self.pacienteDAO.buscar(parametro)
    self.assertEqual(1, len(resultado))
    self.assertTrue(outroTiago in resultado)

    self.pacienteDAO.remover(tiago)
    self.pacienteDAO.remover(outroTiago)
    
  def testABuscaPorNomeRespeitaEspacos(self):
    tiago = PacienteVO('tiago', DataNascimento(datetime.date(1986, 6, 23)),
                                 3, 50,7, EnderecoVO('Rua: Antonio Carlos', 200, 'Casa'))
    outroTiago = PacienteVO('ti ago', DataNascimento(datetime.date(1986, 6, 23)),
                                 3, 50,7, EnderecoVO('Rua: Antonio Carlos', 200, 'Casa'))
    
    self.assertNotEqual(tiago, outroTiago)
    
    self.pacienteDAO.salvar(tiago)
    self.pacienteDAO.salvar(outroTiago)
    
    parametro = ParametroDePesquisa(TabelaPacienteSQLite().obterCampoNome(), tiago.obterNome())
    resultado = self.pacienteDAO.buscar(parametro)
    self.assertEqual(1, len(resultado))
    self.assertTrue(tiago in resultado)
    
    parametro = ParametroDePesquisa(TabelaPacienteSQLite().obterCampoNome(), outroTiago.obterNome())
    resultado = self.pacienteDAO.buscar(parametro)
    self.assertEqual(1, len(resultado))
    self.assertTrue(outroTiago in resultado)

    self.pacienteDAO.remover(tiago)
    self.pacienteDAO.remover(outroTiago)
    
  def testPodeListarTodosOsPacientesComMesmoNumeroDeArea(self):
    tiagoArea50 = PacienteVO('Tiago', DataNascimento(datetime.date(1986, 6, 23)),
                                 2, 50,8, EnderecoVO('Rua: Antonio Carlos', 200, 'Casa'))
    pedroArea50 = PacienteVO('Pedro', DataNascimento(datetime.date(1990, 6, 23)),
                                 3, 50,7, EnderecoVO('Rua: Carlos Prates', 200, 'Casa'))
    
    
    self.pacienteDAO.salvar(tiagoArea50)
    self.pacienteDAO.salvar(pedroArea50)
    
    parametroArea50 = ParametroDePesquisa(TabelaPacienteSQLite().obterCampoNumeroArea(), '50')
    resultado = self.pacienteDAO.buscar(parametroArea50)
    
    self.assertNotEqual(tiagoArea50, pedroArea50)
    self.assertEqual(2, len(resultado))
    self.assertTrue(tiagoArea50 in resultado)
    self.assertTrue(pedroArea50 in resultado)
    
    self.pacienteDAO.remover(tiagoArea50)
    self.pacienteDAO.remover(pedroArea50)
    
  def testPodeListarTodosOsPacientesComMesmoNumeroDeMicroArea(self):
    tiagoMicroArea50 = PacienteVO('Tiago', DataNascimento(datetime.date(1986, 6, 23)),
                                 2, 7,50, EnderecoVO('Rua: Antonio Carlos', 200, 'Casa'))
    pedroMicroArea50 = PacienteVO('Pedro', DataNascimento(datetime.date(1990, 6, 23)),
                                 3, 5,50, EnderecoVO('Rua: Carlos Prates', 200, 'Casa'))
    
    
    self.pacienteDAO.salvar(tiagoMicroArea50)
    self.pacienteDAO.salvar(pedroMicroArea50)
    
    parametroMicroArea50 = ParametroDePesquisa(TabelaPacienteSQLite().obterCampoNumeroMicroArea(), '50')
    resultado = self.pacienteDAO.buscar(parametroMicroArea50)
    
    self.assertNotEqual(tiagoMicroArea50, pedroMicroArea50)
    self.assertEqual(2, len(resultado))
    self.assertTrue(tiagoMicroArea50 in resultado)
    self.assertTrue(pedroMicroArea50 in resultado)
    
    self.pacienteDAO.remover(tiagoMicroArea50)
    self.pacienteDAO.remover(pedroMicroArea50)
    
  def testPodeListarTodosOsPacientesComMesmoNumeroDeFamilia(self):
    tiagoFamilia50 = PacienteVO('Tiago', DataNascimento(datetime.date(1986, 6, 23)),
                                 50, 6,5, EnderecoVO('Rua: Antonio Carlos', 200, 'Casa'))
    pedroFamilia50 = PacienteVO('Pedro', DataNascimento(datetime.date(1990, 6, 23)),
                                 50, 5,7, EnderecoVO('Rua: Carlos Prates', 200, 'Casa'))
    
    
    self.pacienteDAO.salvar(tiagoFamilia50)
    self.pacienteDAO.salvar(pedroFamilia50)
    
    parametroFamilia50 = ParametroDePesquisa(TabelaPacienteSQLite().obterCampoNumeroFamilia(), '50')
    resultado = self.pacienteDAO.buscar(parametroFamilia50)
    
    self.assertNotEqual(tiagoFamilia50, pedroFamilia50)
    self.assertEqual(2, len(resultado))
    self.assertTrue(tiagoFamilia50 in resultado)
    self.assertTrue(pedroFamilia50 in resultado)
    
    self.pacienteDAO.remover(tiagoFamilia50)
    self.pacienteDAO.remover(pedroFamilia50)
  
  
  def testPodeListarTodosOsPacientesComMesmaIdade(self):
    tiago = PacienteVO('Tiago', DataNascimento(datetime.date(1986, 6, 23)),
                                 45, 6,9, EnderecoVO('Rua: Antonio Carlos', 200, 'Casa'))
    pedro = PacienteVO('Pedro', DataNascimento(datetime.date(1986, 6, 23)),
                                 50, 5,7, EnderecoVO('Rua: Carlos Prates', 200, 'Casa'))
    
    idade = tiago.obterIdade()
    self.assertEqual(tiago.obterIdade(), pedro.obterIdade())
     
    parametroIdade = ParametroDePesquisa(TabelaPacienteSQLite().obterCampoIdade(), idade)
    self.pacienteDAO.salvar(tiago)
    self.pacienteDAO.salvar(pedro)
    
    resultado = self.pacienteDAO.buscar(parametroIdade)
    
    self.assertNotEqual(tiago, pedro)
    self.assertEqual(2, len(resultado))
    self.assertTrue(tiago in resultado)
    self.assertTrue(pedro in resultado)
    
    self.pacienteDAO.remover(tiago)
    self.pacienteDAO.remover(pedro)
    
  def testPodeListarTodosOsPacientes(self):
    tiago = PacienteVO('Tiago', DataNascimento(datetime.date(1986, 6, 23)),
                                 45, 6,9, EnderecoVO('Rua: Antonio Carlos', 200, 'Casa'))
    pedro = PacienteVO('Pedro', DataNascimento(datetime.date(1986, 6, 23)),
                                 50, 5,7, EnderecoVO('Rua: Carlos Prates', 200, 'Casa'))
    
    self.pacienteDAO.salvar(tiago)
    self.pacienteDAO.salvar(pedro)
    
    resultado = self.pacienteDAO.listar()
    
    self.assertNotEqual(tiago, pedro)
    self.assertEqual(2, len(resultado))
    self.assertTrue(tiago in resultado)
    self.assertTrue(pedro in resultado)
    
    self.pacienteDAO.remover(tiago)
    self.pacienteDAO.remover(pedro)
  
    

