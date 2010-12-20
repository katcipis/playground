'''
Created on 25/07/2009
@author: katcipis <tiagokatcipis@gmail.com>
Modulo que define a classe Evento
'''

class Evento():
  ''' Guarda informacoes a respeito de um evento que pode 
      ser disparado e tratado no sistema.
      Este objeto eh imutavel, possuindo seu proprio hash.
      Pode ser usado como chave de dicionarios e como Enumeracao.'''

  def __init__(self, nomeEvento, nomesParametros = ()):
    ''' Construtor do evento
        Atributos
        -- nomeEvento      - Nome do evento
        -- nomesParametros - Tupla contendo o nome dos parametros que devem ser passados quando esse evento 
                             for disparado e que deverao ser recebidos pelas funcoes que tratarem o evento.
                             Se nenhuma for passada sera assumido que a funcao n recebe parametros.
    '''
    self.__nomeEvento = nomeEvento
    self.__nomesParametros = nomesParametros
    self.__repr_string = str(nomeEvento) + str(nomesParametros)

  def obterNomeEvento(self):
    return self.__nomeEvento

  def obterNomesDosParametros(self):
    return self.__nomesParametros

  def __eq__(self, outro):
    if isinstance(outro, Evento):
      return str(self) == str(outro)

    return False
    
  def __ne__(self, other):
    return not self == other

  def __hash__(self):
    return hash(str(self))

  def __str__(self):
    return self.__repr_string
