from threading import Thread
from threading import Semaphore
import time, random, Queue

#Utilizaremos varias threads consumidoras e uma 
#thread provedora para testar o uso de queues
#O acesso a queue dados ja eh sincronizado e thread safe, nao necessita semaforos ou locks

dados = Queue.Queue() # Controi uma FIFO Queue, tambem existem LIFO e Queues de prioridade
mutex_print = Semaphore(1)

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
      try:
        #fica bloqueado esperando por dados por 20 segundos
        #se nao chegar um dado vai lancar uma excecao
        #nao eh necessario passar um timeout, nesse caso vai 
        #ficar bloqueado ate obter um dado, possibilidade de deadlock.
        dado = dados.get(timeout=20) 
        imprimir('Thread ' + self.id + ' obteve o dado ' + dado)
      except:
        imprimir('Thread ' + self.id + ' estourou o timeout esperando por um dado')
        
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
      dados.put(dado)
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

      
  

