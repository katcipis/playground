'''
Created on 18/06/2009
@author: Katcipis

Modulo responsavel por toda a parte de baixo nivel de rede e de clock do sistema
Simula um clock de sistema e cria servidores para sempre que um dado chegar ele ser 
repassado para a camada de rede.
'''
from util.ServidorUDP import ServidorUDP
from util.ServidorUDP import adciona_funcao_callback_server
from util.ClockSistema import adciona_funcao_callback_clock
from util.ServidorUDP import separa_endereco
from threading import BoundedSemaphore
import socket

# ================= #
# VARIAVEIS GLOBAIS #
# ================= #
_servidores = {}
_mutex_servidores = BoundedSemaphore()

def _criar_servidor(endereco_local):
  ip, porta = separa_endereco(endereco_local)
  server = ServidorUDP(ip, porta)
  _servidores[endereco_local] = server
  server.start()

def _obter_servidor(endereco_local):
  _mutex_servidores.acquire()
  
  if(not endereco_local in _servidores):
    _criar_servidor(endereco_local)
  
  _mutex_servidores.release()
  
  return _servidores[endereco_local]
    
  
def registra_callback_server(funcao):
  '''
  Adciona uma funcao para ser invocada sempre que algum dado chegar.
  A funcao deve receber como parametros o endereco local, endereco remoto e os 
  dados que chegaram. Os enderecos sao passados no formato IP:PORTA.
  Ex assinatura funcao: funcao_callback(end_local, end_remoto, dados)
  '''
  adciona_funcao_callback_server(funcao)


def registra_callback_clock(funcao):
  '''
  Registra a funcao passada como uma funcao de callback sempre que o clock pulsar
  '''
  adciona_funcao_callback_clock(funcao)
  
  
def enviar_dados(endereco_local, endereco_remoto, dados):
  '''
  Envia dados usando socket UDP, chegada dos dados nao eh garantida.
  '''
  server = _obter_servidor(endereco_local)
  server.enviarDados(dados, separa_endereco(endereco_remoto))
  
def criar_servidor(endereco_local):
  '''
  Cria um servidor para ficar recebendo dados no endereco_local fornecido.
  Se ja existe um servidor escutando nesse endereco nada sera feito. 
  '''
  _mutex_servidores.acquire()
  
  if(not endereco_local in _servidores):
    _criar_servidor(endereco_local)
  else:
    if(_servidores[endereco_local].estaParado()):
      del _servidores[endereco_local]
      _criar_servidor(endereco_local)
       
  _mutex_servidores.release()
    