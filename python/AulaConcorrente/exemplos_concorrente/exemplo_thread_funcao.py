from threading import Thread
import time
import random

#Existem duas maneiras de utilizar threads em python,
#uma eh utilizando classes, a outra eh definindo uma 
#funcao e executando ele como uma thread separada.
#Esta segunda maneira eh mais similar ao pascalfc, onde voce
#define um processo e o executa como uma thread separada.

rodar = True

#Definindo a funcao que sera executada como thread
def exemplo_thread(id):
  while(rodar):
    print("Thread id: " + id + " esta indo dormir")
    time.sleep(random.random())
    print("Thread id: " + id + " acabou de acordar")

#instanciando as threads
#target eh a funcao que sera executada
#kwargs eh um dicionario que mapeia um parametro da funcao com 
#o seu valor, neste caso temos apenas um parametro.
thread_um   = Thread(target=exemplo_thread, kwargs={"id" : "1"})
thread_dois = Thread(target=exemplo_thread, kwargs={"id" : "2"})
thread_tres = Thread(target=exemplo_thread, kwargs={"id" : "3"})

#agora iniciando as threads
thread_um.start()
thread_dois.start()
thread_tres.start()

#agora bloqueamos a aplicacao principal por 10 segundos enquanto as threads rodam
time.sleep(10)

#agora paramos as threads
rodar = False

