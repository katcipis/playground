# -*- coding: latin-1 -*-
import threading
import random
import rankSort
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

# criar thread ordenadora
class Ordenadora(threading.Thread):

  def run(self):
    while(rankSort.indice < rankSort.indiceMax):
      rankSort.mutexOrdenar.acquire()
      
      if(rankSort.indice < rankSort.indiceMax):
        print 'Thread de numero: ', self.getName(), ' esta obtendo acesso ao indice global'
        contador = 0
        meuIndice = rankSort.indice
        rankSort.indice += 1
        rankSort.mutexOrdenar.release()
        meuNumero = rankSort.ordenar[meuIndice]
        
        for numero in rankSort.ordenar:
          if(numero < meuNumero):
            contador += 1

        while(rankSort.ordenado[contador] == meuNumero):
          contador += 1

        rankSort.ordenado[contador] = meuNumero
         
      else:
        rankSort.mutexOrdenar.release()
        rankSort.mutexImpresso.acquire()

        if(not rankSort.foiImpresso):
          print 'Terminou ordenacao'
          print rankSort.ordenado; print ''
          print "Tempo decorrido para ordenar: " , (time.time() - start)
          rankSort.foiImpresso = True

        rankSort.mutexImpresso.release()


#rodando threads ordenadoras
start = time.time()

for i in range(40):
  thread = Ordenadora()
  thread.start()




