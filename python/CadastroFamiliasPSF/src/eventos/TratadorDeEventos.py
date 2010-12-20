'''
Created on 25/07/2009
@author: katcipis <tiagokatcipis@gmail.com>
Modulo que define a classe TratadorDeEventos e suas Excecoes
'''

class ErroDisparandoEvento(Exception):
  def __init__(self, msg_erro):
    self.__erro = msg_erro

  def __str__(self):
    return 'Erro: ' + str(self.__erro)

class TratadorDeEventos():
  ''' Dispara eventos, invocando os tratadores conectados a aquele evento
      para lidar com determinados eventos, fazendo a checagem dos parametros
      passados por quem disparou o evento. Nao eh feita checagem no tipo dos  
      parametros, apenas checasse a existencia e o nome dos parametros '''

  _eventos = {}

  def dispararEvento(self, evento, **parametros):
    ''' Dispara um evento chamando todos os tratadores '''  
    nomesParametrosEvento = evento.obterNomesDosParametros()

    if(len(nomesParametrosEvento) > len(parametros)):
      msg_erro = 'parametros informados[{0}], parametros necessarios[{1}]'.format(len(parametros), len(nomesParametrosEvento)) 
      raise ErroDisparandoEvento(msg_erro)
      return 

    for nomeParametro in nomesParametrosEvento:
      if(not nomeParametro in parametros):
        msg_erro = 'parametro [{0}] nao foi encontrado na lista de parametros passados: {1}'.format(nomeParametro, parametros.keys())
        raise ErroDisparandoEvento(msg_erro)
        return
 
    if(evento in TratadorDeEventos._eventos):
      [funcao(**parametros) for funcao in TratadorDeEventos._eventos[evento]]

      

  def registraTratador(self, evento, funcaoTratadora):
    ''' Registra uma funcao para tratar um determinado evento, a funcao
        tratadora deve receber os mesmos parametros que os definidos no evento'''

    if(not evento in TratadorDeEventos._eventos):
      TratadorDeEventos._eventos[evento] = set()

    TratadorDeEventos._eventos[evento].add(funcaoTratadora)
