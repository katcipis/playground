'''
Created on 22/06/2009
@author: Katcipis
'''
from threading import Thread
from threading import BoundedSemaphore
import SocketServer


def concatena_endereco(endereco, porta):
  '''
  Concatena um endereco do formato IP e PORTA para "IP:PORTA"
  '''
  return endereco + ':' + str(porta)

def separa_endereco(endereco):
  '''
  Separa um endereco do formato IP:PORTA retornando uma tupla (string IP, int PORTA)
  '''
  lista = endereco.split(':')
  return lista[0], int(lista[1])

def adciona_funcao_callback_server(funcao):
  '''
  Adciona uma funcao para ser invocada sempre que algum dado chegar.
  A funcao deve receber como parametros o endereco local, endereco remoto e os 
  dados que chegaram. Os enderecos sao passados no formato IP:PORTA.
  Ex assinatura funcao: funcao_callback(end_local, end_remoto, dados)
  '''
  _TratadorUDP.funcoes.add(funcao)


class ServidorUDP(Thread):
  '''
  Cria um servidor UDP na porta e no endereco local fornecidos
  no construtor. Sempre que um dado chegar no servidor a classe tratadora
  fornecida sera instanciada e seu metodo handle chamado. 
  Cada instancia desta classe sera uma Thread, a thread soh para quando for
  solicitado que o servidor seja desligado.
  '''

  def __init__(self, endereco_local, porta):
    '''
    Construtor
    endereco_local   deve ser uma string representando um IP. (192.168.170.30)
    porta            deve ser um inteiro representando uma porta. (8000)
    '''
    Thread.__init__(self)
    self.__endereco_local = endereco_local
    self.__porta = porta
    self.__server = None
    self.__estaParado = False
    self.__mutexSocket = BoundedSemaphore()
    self.__server = SocketServer.UDPServer((self.__endereco_local, self.__porta), _TratadorUDP)
    
  def run(self):
    self.__server.serve_forever()
    
  def parar(self):
    '''
    Para o servidor e a thread, apos chamar essa funcao o servidor nao
    escutara mais os dados que estao chegando.
    '''
    self.__server.shutdown()
    self.__estaParado = True
      
  def estaParado(self):
    return self.__estaParado  
  
  def enviarDados(self, dados, tupla_endereco):
    self.__mutexSocket.acquire()
    self.__server.socket.sendto(dados, tupla_endereco)
    self.__mutexSocket.release()
    

class _TratadorUDP(SocketServer.BaseRequestHandler):
    """
    Classe privada do modulo, nao deve ser usada externamente
    self.request[0] sao os dados enviados pela rede
    self.request[1] eh um socket aberto para enviar uma possivel resposta
    """
    funcoes = set()
    
    def handle(self):
      dados = self.request[0]
      endereco_remoto = concatena_endereco(self.client_address[0], self.client_address[1])
      endereco_local = concatena_endereco(self.server.server_address[0] , self.server.server_address[1])
      [funcao(endereco_local, endereco_remoto, dados) for funcao in _TratadorUDP.funcoes]
        
        
  
        