from threading import Thread
import time
import random

#Existem duas maneiras de utilizar threads em python,
#uma eh utilizando classes e heranca, a outra eh
#definindo uma funcao e executando ele como uma thread separada.
#Esta segunda maneira eh mais similar ao pascalfc, onde voce
#define um processo e o executa como uma thread separada.

class ExemploThread(Thread):

  def __init__(self, id):
    Thread.__init__(self) #chamando o construtor da classe pai
    self.id = id
    self.rodar = True

  def run(self):
    #Este eh o metodo que sera executado quando for executado o start da thread
    #a thread soh para a execucao quando o metodo run retorna
    while(self.rodar):
      print("Thread id: " + self.id + " esta indo dormir")
      time.sleep(random.random())
      print("Thread id: " + self.id + " acabou de acordar")

  def parar(self):
    #Metodo criado para fazer a thread parar
    self.rodar = False

#instanciando as threads
thread_um   = ExemploThread("1")
thread_dois = ExemploThread("2")
thread_tres = ExemploThread("3")

#agora iniciando as threads
thread_um.start()
thread_dois.start()
thread_tres.start()

#agora bloqueamos a aplicacao principal por 10 segundos enquanto as threads rodam
time.sleep(10)

#agora paramos as threads
thread_um.parar()
thread_dois.parar()
thread_tres.parar()

