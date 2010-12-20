# -*- coding: utf-8 -*-
import sqlite3
from banco_dados.enum_bd import PATH_BD
from banco_dados.TabelaPacienteSQLite import TabelaPacienteSQLite
from modelo.EnderecoVO import EnderecoVO
from modelo.PacienteVO import PacienteVO
from abstrato.DataNascimento import DataNascimento
from abstrato.ParametroDePesquisa import ParametroDePesquisa

class PacienteDAO:
  
  def __init__(self):
    self.__connection = sqlite3.connect(PATH_BD)
    self.__tabelaPaciente = TabelaPacienteSQLite()
    
  def buscar(self, parametro):
    ''' Faz uma busca no banco de dados usando o parametro passado o valor do campo
        do parametro deve ser um string ou possuir uma representacao como string '''
    cursor = self.__connection.cursor()
    cursor.execute('select * from ' + self.__tabelaPaciente.obterNomeTabela() + 
                   ' where ' + parametro.obterNomeDoCampo() + '=?', (str(parametro.obterValorDoCampo()),))

    return [self.__converterDeValoresParaPaciente(valores) for valores in cursor.fetchall()]
  
  def listar(self):
    ''' Lista todos os pacientes existentes no banco de dados '''
    cursor = self.__connection.cursor()
    cursor.execute('select * from ' + self.__tabelaPaciente.obterNomeTabela())
    return [self.__converterDeValoresParaPaciente(valores) for valores in cursor.fetchall()]
    
  def remover(self, paciente):
    #Esse codigo eh medonho pq eh altamente dependente da ordem que a tupla
    #de valores eh montada e da ordem que o comando eh montado. Ou seja horrivel.
    #Portanto cuidado com os metodos do DAO..bem feito nas coxas mesmo.'''
    valores = self.__converterDePacienteParaValores(paciente)
    cursor = self.__connection.cursor()
    comando = 'delete from ' + self.__tabelaPaciente.obterNomeTabela() + ' where ' \
               + self.__tabelaPaciente.obterCampoNome() + '=? and ' \
               + self.__tabelaPaciente.obterCampoDataNascimento() + '=? and ' \
               + self.__tabelaPaciente.obterCampoNumeroFamilia() + '=? and ' \
               + self.__tabelaPaciente.obterCampoNumeroArea() + '=? and ' \
               + self.__tabelaPaciente.obterCampoNumeroMicroArea() + '=? and ' \
               + self.__tabelaPaciente.obterCampoRua() + '=? and ' \
               + self.__tabelaPaciente.obterCampoNumeroCasa() + '=? and ' \
               + self.__tabelaPaciente.obterCampoComplemento() + '=? and ' \
               + self.__tabelaPaciente.obterCampoIdade() + '=?' 
    cursor.execute(comando, valores)
    self.__connection.commit()
  
  def salvar(self, paciente):
    #Mesma coisa que o remover, alta dependencia com a ordem dos argumentos.
    if(self.__jaExiste(paciente)):
      return  
    cursor = self.__connection.cursor()
    comandoInserePaciente = 'insert into ' + self.__tabelaPaciente.obterNomeTabela() + ' values '
    comandoInserePaciente += str(self.__converterDePacienteParaValores(paciente))
    cursor.execute(comandoInserePaciente)
    self.__connection.commit()    
    
    
  def __converterDePacienteParaValores(self, paciente):
    valores = (paciente.obterNome(),
               str(paciente.obterDataNascimento()),
               str(paciente.obterNumeroFamilia()),
               str(paciente.obterNumeroArea()),
               str(paciente.obterNumeroMicroArea()),
               paciente.obterEndereco().obterRua(),
               str(paciente.obterEndereco().obterNumero()),
               paciente.obterEndereco().obterComplemento(),
               str(paciente.obterIdade())
               )
      
    return valores
  
  def __jaExiste(self, paciente):
    parametroPaciente = ParametroDePesquisa(TabelaPacienteSQLite().obterCampoNome(), paciente.obterNome())
    resultados = self.buscar(parametroPaciente)
    for resultado in resultados:
      if(resultado == paciente):
        return True
      
    return False
  
  def __converterDeValoresParaPaciente(self, valores):
    data = DataNascimento(valores[1])
    endereco = EnderecoVO(valores[5], valores[6], valores[7])
    return PacienteVO(valores[0], data, valores[2], valores[3], valores[4], endereco)
    