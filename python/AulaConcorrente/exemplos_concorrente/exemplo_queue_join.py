from threading import Thread
from threading import Semaphore
import time, random, Queue

#Agora vamos trabalhar com queues para gerenciar a execucao
#de uma determinada quantidade de tarefas, vamos ter uma
#FIFO com varias tarefas que serao executadas por varias thread simultaneamente

mutex_print = Semaphore(1)
#definindo a funcao que imprimi na tela thread safe
def imprimir(string):
  mutex_print.acquire()
  print(string)
  mutex_print.release()

#definimos o nosso processo que sera enfileirado
def processo(msg_thread):
  imprimir(msg_thread)
  
fila_processos = Queue.Queue()
#adcionamos 30 processos para serem executados na fila
for i in range(30):
  fila_processos.put(processo)


#definimos a classe que vai executar os processos
# definindo as classes consumidor e a produtor
class Executor(Thread):

  def __init__(self, id):
    Thread.__init__(self)
    self.id = id
    self.rodar = True

  def run(self):
    while(self.rodar):
      imprimir('Thread ' + self.id + ' esta esperando para executar')
      try:
        #fica bloqueado esperando por dados por 20 segundos
        #se nao chegar um dado vai lancar uma excecao
        #nao eh necessario passar um timeout, mas nesse caso vai 
        #ficar bloqueado ate obter um dado, possibilidade de deadlock.
        processo = fila_processos.get(timeout=20) 
        processo('Thread ' + self.id + ' executou uma tarefa com sucesso')#Executando o processo
        #Agora sinalizamos que uma task foi executada com sucesso, para cada get com sucesso deve ser executado apenas um task_done
        fila_processos.task_done()
      except:
        imprimir('Thread ' + self.id + ' estourou o timeout esperando por uma tarefa')
        
      time.sleep(random.random())

  def parar(self):
    self.rodar = False


executores = [Executor(str(i)) for i in range(3)]
[executor.start() for executor in executores]

#Join que bloqueia ate a quantidade de task_dones ser igual a de tarefas 
#adcionadas na fila ou seja todas as tarefas serem executadas com sucesso
fila_processos.join()
[executor.parar() for executor in executores]

