'''
Created on 10/04/2009
Implementacao da tabela paciente especifica para SQLLite
@author: katcipis
'''
from abstrato.TabelaPaciente import TabelaPaciente

class TabelaPacienteSQLite(TabelaPaciente):
  
  def criarTabelaNoBancoDeDados(self, cursor):
    tab = ( self.obterCampoNome(), self.obterCampoDataNascimento(),
           self.obterCampoNumeroFamilia(), self.obterCampoNumeroArea(),
           self.obterCampoNumeroMicroArea(), self.obterCampoRua(),
           self.obterCampoNumeroCasa(), self.obterCampoComplemento(),
           self.obterCampoIdade() )
    
    cursor.execute('''create table Paciente
                    ({tabela[0]} text, {tabela[1]} text, 
                    {tabela[2]} integer, {tabela[3]} integer,
                    {tabela[4]} integer, {tabela[5]} text, 
                    {tabela[6]} integer, {tabela[7]} text, 
                    {tabela[8]} integer)'''.format(tabela = tab))
    
  
  