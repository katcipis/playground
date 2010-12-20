# -*- coding: latin-1 -*-
import threading
import random
import time

# inicializando variáveis
ordenar = []
ordenado = []
indice = 0
indiceMax = 1000
foiImpresso = False
mutexOrdenar = threading.Semaphore(1)
mutexImpresso = threading.Semaphore(1)

for i in range(1000):
  ordenar.append(random.randint(0,1000))
  ordenado.append(-1)

# criar funcao ordenadora

def funcaoOrdenar():
  # declarando variáveis globais
  global ordenar
  global ordenado
  global indice
  global indiceMax
  global foiImpresso
  global mutexOrdenar
  global mutexImpresso
  
  while(indice < indiceMax):
    mutexOrdenar.acquire()
      
    if(indice < indiceMax):
      print 'Thread anonima acessando indice global'
      contador = 0
      meuIndice = indice
      indice += 1
      mutexOrdenar.release()
      meuNumero = ordenar[meuIndice]
        
      for numero in ordenar:
        if(numero < meuNumero):
          contador += 1

      while(ordenado[contador] == meuNumero):
        contador += 1

      ordenado[contador] = meuNumero
         
    else:
      mutexOrdenar.release()
      mutexImpresso.acquire()

      if(not foiImpresso):
        print 'Terminou ordenacao'
        print ordenado; print ''
        print "Tempo decorrido para ordenar: " , (time.time() - start)
        foiImpresso = True

      mutexImpresso.release()


#rodando threads ordenadoras

start = time.time()

for i in range(40):
  thread = threading.Thread(target=funcaoOrdenar)
  thread.start()




