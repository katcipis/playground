from threading import Thread
from threading import Semaphore
import time, random

#Utilizaremos varias threads consumidoras e uma 
#thread provedora para testar o uso de semaforos
#O acesso a lista de dados sera controlado por um semaforo

dados = []
mutex_dados = Semaphore(1) 
mutex_print = Semaphore(1)

# definindo as funcoes que obtem e inserem dados de forma thread-safe usando semaforos
def obter_dado():
  ''' Se nao existirem dados retorna None '''
  retorno = None

  mutex_dados.acquire()
  if(len(dados) > 0):
    retorno = dados.pop(0) # remove do inicio
  mutex_dados.release()

  return retorno

def colocar_dado(dado):
  mutex_dados.acquire()
  dados.append(dado)      # insere no final
  mutex_dados.release()

#definindo a funcao que imprimi na tela thread safe
def imprimir(string):
  mutex_print.acquire()
  print(string)
  mutex_print.release()


# definindo as classes consumidor e a produtor
class Consumidor(Thread):

  def __init__(self, id):
    Thread.__init__(self)
    self.id = id
    self.rodar = True

  def run(self):
    while(self.rodar):
      imprimir('Thread ' + self.id + ' esta esperando para consumir')
      dado = obter_dado()
      if(dado == None):
        imprimir('Thread ' + self.id + ' nao conseguiu obter um dado para consumir')
      else:
        imprimir('Thread ' + self.id + ' obteve o dado ' + dado)
      time.sleep(random.random())

  def parar(self):
    self.rodar = False


class Produtor(Thread):

  def __init__(self):
    Thread.__init__(self)
    self.rodar = True

  def run(self):
    i = 0
    while(self.rodar):
      imprimir('Thread produtora esta esperando para inserir dado')
      dado = 'dado ' + str(i)
      colocar_dado(dado)
      i += 1
      imprimir('Thread produtora inseriu dado: ' + dado)
      time.sleep(random.random())

  def parar(self):
    self.rodar = False

# agora vamos montar o sistema para rodar por 10 segundos e observar a saida

consumidores = [Consumidor(str(i)) for i in range(3)] #criando uma lista com 3 consumidores, usando List comprehension
produtor = Produtor()

produtor.start()
# mais uma vez usando lista comprehension para iniciar todos os consumidores dentro de uma lista
# esta tecnica pode ser usada tanto para iterar por uma lista executando ou calculando algo como para gerar novas listas
[consumidor.start() for consumidor in consumidores] 

time.sleep(10)

# parando as threads
[consumidor.parar() for consumidor in consumidores] 
produtor.parar()      

      
  

