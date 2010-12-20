import os
import sqlite3
from banco_dados.enum_bd import PATH_BD
from banco_dados.TabelaPacienteSQLite import TabelaPacienteSQLite

def _criar_bd():
  """ Nao deve ser usado """
  conexao = sqlite3.connect(PATH_BD)
  cursor = conexao.cursor()
  TabelaPacienteSQLite().criarTabelaNoBancoDeDados(cursor)
  conexao.commit()
  return True

def iniciar_bd():
  """ Deve ser invocado uma vez antes de inicializar o programa """
  if(not os.path.isfile(PATH_BD)):
    return _criar_bd()
  
  return True