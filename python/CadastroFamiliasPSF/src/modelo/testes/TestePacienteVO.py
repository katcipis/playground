'''
Created on 11/07/2009
@author: Katcipis
'''
import unittest
import datetime
from modelo.EnderecoVO import EnderecoVO
from modelo.PacienteVO import PacienteVO
from abstrato.DataNascimento import DataNascimento

class TestePacienteVO(unittest.TestCase):
  
  def testSabeOSeuNome(self):
    pacienteTiago = PacienteVO('Tiago', DataNascimento(datetime.date(1986, 6, 23)), 3, 5, 7, EnderecoVO('Rua: Antonio Carlos', 200, 'Casa'))
    nome = 'Tiago'
    self.assertEqual(nome, pacienteTiago.obterNome())
    
  def testSabeQualNaoEhOSeuNome(self):
    pacienteTiago = PacienteVO('Tiago', DataNascimento(datetime.date(1986, 6, 23)), 3, 5, 7, EnderecoVO('Rua: Antonio Carlos', 200, 'Casa'))
    nome = 'Tigo'
    self.assertNotEqual(nome, pacienteTiago.obterNome())
    
  def testSabeASuaDataDeNascimento(self):
    nasc = DataNascimento(datetime.date(1986, 6, 23))
    pacienteTiago = PacienteVO('Tiago', nasc, 3, 5, 7, EnderecoVO('Rua: Antonio Carlos', 200, 'Casa'))
    self.assertEqual(nasc, pacienteTiago.obterDataNascimento())
    
  def testSabeQualNaoEhASuaDataDeNascimento(self):
    pacienteTiago = PacienteVO('Tiago', DataNascimento(datetime.date(1986, 6, 23)), 3, 5, 7, EnderecoVO('Rua: Antonio Carlos', 200, 'Casa'))
    nasc = datetime.date(1986, 6, 22)
    self.assertNotEqual(nasc, pacienteTiago.obterDataNascimento())
    
  def testSabeQualSeuNumeroDeFamilia(self):
    familia = 3
    pacienteTiago = PacienteVO('Tiago', DataNascimento(datetime.date(1986, 6, 23)), familia, 5, 7, EnderecoVO('Rua: Antonio Carlos', 200, 'Casa'))
    self.assertEqual(familia, pacienteTiago.obterNumeroFamilia())
    
  def testSabeQualNaoEhSeuNumeroDeFamilia(self):
    pacienteTiago = PacienteVO('Tiago', DataNascimento(datetime.date(1986, 6, 23)), 3, 5, 7, EnderecoVO('Rua: Antonio Carlos', 200, 'Casa'))
    familia = 4
    self.assertNotEqual(familia, pacienteTiago.obterNumeroFamilia())
    
  def testSabeQualSeuNumeroDeArea(self):
    area = 5
    pacienteTiago = PacienteVO('Tiago', DataNascimento(datetime.date(1986, 6, 23)), 3, area, 7, EnderecoVO('Rua: Antonio Carlos', 200, 'Casa'))
    self.assertEqual(area, pacienteTiago.obterNumeroArea())
    
  def testSabeQualNaoEhSeuNumeroDeArea(self):
    pacienteTiago = PacienteVO('Tiago', DataNascimento(datetime.date(1986, 6, 23)), 3, 5, 7, EnderecoVO('Rua: Antonio Carlos', 200, 'Casa'))
    area = 4
    self.assertNotEqual(area, pacienteTiago.obterNumeroArea())
    
  def testSabeQualSeuNumeroDeMicroArea(self):
    microarea = 7
    pacienteTiago = PacienteVO('Tiago', DataNascimento(datetime.date(1986, 6, 23)), 3, 5, microarea, EnderecoVO('Rua: Antonio Carlos', 200, 'Casa'))
    self.assertEqual(microarea, pacienteTiago.obterNumeroMicroArea())
    
  def testSabeQualNaoEhSeuNumeroDeMicroArea(self):
    pacienteTiago = PacienteVO('Tiago', DataNascimento(datetime.date(1986, 6, 23)), 3, 5, 7, EnderecoVO('Rua: Antonio Carlos', 200, 'Casa'))
    microarea = 6
    self.assertNotEqual(microarea, pacienteTiago.obterNumeroMicroArea())
    
  def testSabeQualSeuEndereco(self):
    endereco = EnderecoVO('Rua: Antonio Carlos', 200, 'Casa')
    pacienteTiago = PacienteVO('Tiago', DataNascimento(datetime.date(1986, 6, 23)), 3, 5, 7, endereco)
    self.assertEqual(endereco, pacienteTiago.obterEndereco())
    
  def testSabeQualNaoEhSeuEndereco(self):
    enderecoCerto =  EnderecoVO('Rua: Antonio Carlos', 200, 'Casa')
    pacienteTiago = PacienteVO('Tiago', DataNascimento(datetime.date(1986, 6, 23)), 3, 5, 7, enderecoCerto)
    enderecoErrado = EnderecoVO('Rua: Antonio Carlos Lero', 200, 'Casa')
    self.assertNotEqual(enderecoErrado, pacienteTiago.obterEndereco())
    
  def testSabeDizerSeEhIgualAOutroPaciente(self):
    pacienteTiago = PacienteVO('Tiago', DataNascimento(datetime.date(1986, 6, 23)), 3, 5, 7, EnderecoVO('Rua: Antonio Carlos', 200, 'Casa'))
    outroPacienteTiago = PacienteVO('Tiago', DataNascimento(datetime.date(1986, 6, 23)), 3, 5, 7, EnderecoVO('Rua: Antonio Carlos', 200, 'Casa'))
    
    self.assertEqual(pacienteTiago, outroPacienteTiago)
    
  def testSabeDizerSeNaoEhIgualAOutroPaciente(self):
    pacienteTiago    = PacienteVO('Tiago', DataNascimento(datetime.date(1986, 6, 23)), 3, 5, 7, EnderecoVO('Rua: Antonio Carlos', 200, 'Casa'))
    nascDiferente    = PacienteVO('Tiago', DataNascimento(datetime.date(1987, 6, 23)), 3, 5, 7, EnderecoVO('Rua: Antonio Carlos', 200, 'Casa'))
    familiaDiferente = PacienteVO('Tiago', DataNascimento(datetime.date(1986, 6, 23)), 4, 5, 7, EnderecoVO('Rua: Antonio Carlos', 200, 'Casa'))
    areaDiferente    = PacienteVO('Tiago', DataNascimento(datetime.date(1986, 6, 23)), 3, 9, 7, EnderecoVO('Rua: Antonio Carlos', 200, 'Casa'))
    microAreaDirefente = PacienteVO('Tiago', DataNascimento(datetime.date(1986, 6, 23)), 3, 5, 65, EnderecoVO('Rua: Antonio Carlos', 200, 'Casa'))
    enderecoDiferente  = PacienteVO('Tiago', DataNascimento(datetime.date(1986, 6, 23)), 3, 5, 7, EnderecoVO('Rua: Antonio Carlos Irra', 210, 'Casa'))
    nomeDiferente = PacienteVO('Tiago Pah', DataNascimento(datetime.date(1986, 6, 23)), 3, 5, 7, EnderecoVO('Rua: Antonio Carlos', 200, 'Casa'))
    
    self.assertNotEqual(pacienteTiago, nascDiferente)
    self.assertNotEqual(pacienteTiago, familiaDiferente)
    self.assertNotEqual(pacienteTiago, areaDiferente)
    self.assertNotEqual(pacienteTiago, microAreaDirefente)
    self.assertNotEqual(pacienteTiago, enderecoDiferente)
    self.assertNotEqual(pacienteTiago, nomeDiferente)
    
  def testSabeDizerQualEhASuaIdadeSeJaPassouUmMesDoAniversario(self):
    idade = 23 
    hoje = datetime.date.today()
    dataNascimento = DataNascimento(datetime.date(hoje.year - idade, hoje.month - 1, hoje.day))
    pacienteTiago = PacienteVO('Tiago', dataNascimento, 3, 5, 7, EnderecoVO('Rua: Antonio Carlos', 200, 'Casa'))
    self.assertEqual(idade, pacienteTiago.obterIdade())
  
  def testSabeDizerQualEhASuaIdadeSeJaPassouUmDiaDoAniversario(self):
    idade = 23 
    hoje = datetime.date.today()
    dataNascimento = DataNascimento(datetime.date(hoje.year - idade, hoje.month, hoje.day - 1))
    pacienteTiago = PacienteVO('Tiago', dataNascimento, 3, 5, 7, EnderecoVO('Rua: Antonio Carlos', 200, 'Casa'))
    self.assertEqual(idade, pacienteTiago.obterIdade())
    
  def testSabeDizerQualEhASuaIdadeSeEhOAniversario(self):
    idade = 23 
    hoje = datetime.date.today()
    dataNascimento = DataNascimento(datetime.date(hoje.year - idade, hoje.month, hoje.day))
    pacienteTiago = PacienteVO('Tiago', dataNascimento, 3, 5, 7, EnderecoVO('Rua: Antonio Carlos', 200, 'Casa'))
    self.assertEqual(idade, pacienteTiago.obterIdade())
    
  def testSabeDizerQualEhASuaIdadeSeAindaFaltaUmDiaParaOAniversario(self):
    idade = 23 
    hoje = datetime.date.today()
    dataNascimento = DataNascimento(datetime.date(hoje.year - idade, hoje.month, hoje.day + 1))
    pacienteTiago = PacienteVO('Tiago', dataNascimento, 3, 5, 7, EnderecoVO('Rua: Antonio Carlos', 200, 'Casa'))
    self.assertNotEqual(idade, pacienteTiago.obterIdade())
    self.assertEqual(idade - 1, pacienteTiago.obterIdade())
    
  def testSabeDizerQualEhASuaIdadeSeAindaFaltaUmMesParaOAniversario(self):
    idade = 23 
    hoje = datetime.date.today()
    dataNascimento = DataNascimento(datetime.date(hoje.year - idade, hoje.month + 1, hoje.day))
    pacienteTiago = PacienteVO('Tiago', dataNascimento, 3, 5, 7, EnderecoVO('Rua: Antonio Carlos', 200, 'Casa'))
    self.assertNotEqual(idade, pacienteTiago.obterIdade())
    self.assertEqual(idade - 1, pacienteTiago.obterIdade())
    
  def testSabeDizerQualNaoEhASuaIdade(self):
    idade = 23 
    hoje = datetime.date.today()
    dataNascimento = DataNascimento(datetime.date(hoje.year - idade, hoje.month, hoje.day))
    pacienteTiago = PacienteVO('Tiago', dataNascimento, 3, 5, 7, EnderecoVO('Rua: Antonio Carlos', 200, 'Casa'))
    self.assertNotEqual(idade + 1, pacienteTiago.obterIdade())
    self.assertNotEqual(idade - 1, pacienteTiago.obterIdade())
    
