'''
Created on 25/07/2009
@author: katcipis <tiagokatcipis@gmail.com>
Modulo que define a classe DataNascimento e suas Excecoes
'''

class ErroObtendoData(Exception):
  def __init__(self, data):
    self.__rawdata = data

  def __str__(self):
    return 'Erro ao obter fazer parse dos dados[{0}] para obter a data de nascimento '.format(str(self.__rawdata))

class DataNascimento():
  
  def __init__(self, raw_data_nasc):
    ''' Raw data deve ser uma string no formato dd/mm/aaaa ou 
        um objeto com os atributos day, month e year como um datetime.date '''

    obteu_data = False
    self.__divisor_data = '/'

    if(hasattr(raw_data_nasc, 'day') and
       hasattr(raw_data_nasc, 'month') and
       hasattr(raw_data_nasc, 'year')):

      self.__dia = int(raw_data_nasc.day)        
      self.__mes = int(raw_data_nasc.month)
      self.__ano = int(raw_data_nasc.year)
      obteu_data = True

    elif(hasattr(raw_data_nasc, 'split')):
      data = raw_data_nasc.split(self.__divisor_data)
      if(len(data) == 3):
        self.__dia = int(data[0])
        self.__mes = int(data[1])
        self.__ano = int(data[2])
        obteu_data = True 
          
    if(not obteu_data):
      raise ErroObtendoData(raw_data_nasc)
  
 
  def obterDia(self):
    return self.__dia

  def obterMes(self):
    return self.__mes

  def obterAno(self):
    return self.__ano

  def __eq__(self, outraData):
    return str(self) == str(outraData)

  def __neq__(self, outraData):
    return not self == outraData

  def __str__(self):
    str_repr = str(self.obterDia()) + self.__divisor_data
    str_repr += str(self.obterMes()) + self.__divisor_data
    str_repr += str(self.obterAno())
    return str_repr
