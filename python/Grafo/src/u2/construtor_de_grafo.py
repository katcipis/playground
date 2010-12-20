# -*- coding: latin-1 -*-
from u2.VerticeU2 import VerticeU2
from u2.IntegranteU2 import IntegranteU2
from sets import Set

U2 = Set()
U2.add(IntegranteU2('Bono', 1))
U2.add(IntegranteU2('Edge', 2))
U2.add(IntegranteU2('Adam', 5))
U2.add(IntegranteU2('Larry', 10))

U2Raiz = VerticeU2(U2, True)

def construir_grafo(grafo, raiz = U2Raiz):
  """ Função responsável pela construção do Grafo """
  
  grafo.AdcionaVertice(raiz)
  
  if(raiz.PossuiLanterna()):
      construir_grafo_com_lanterna(raiz, grafo)
  else:
      construir_grafo_sem_lanterna(raiz, grafo)
    
def ParaLista(set):
  lista = []
  
  for x in set:
    lista.append(x)
    
  return lista    
    
def obter_mais_lento(atravessa_um, atravessa_dois):
  if(atravessa_um.ObterVelocidade() > atravessa_dois.ObterVelocidade()):
    return atravessa_um.ObterVelocidade()

  return atravessa_dois.ObterVelocidade()
    
def gerar_travessia(raiz,grafo, lista, atravessa_um, atravessa_dois):
  gerado = Set()
  for x in lista:
    gerado.add(x)
    
  gerado.discard(atravessa_um)
  gerado.discard(atravessa_dois)
  
  vertice = VerticeU2(gerado)
  grafo.AdcionaVertice(vertice)
  grafo.Conecta(raiz, vertice, obter_mais_lento(atravessa_um, atravessa_dois))
  
  construir_grafo(grafo, vertice)
  
  
def gerar_retorno(raiz,grafo, lista, retorna):
  gerado = Set()
  
  for x in lista:
    gerado.add(x)
    
  gerado.add(retorna)
  
  vertice = VerticeU2(gerado, True)
  grafo.AdcionaVertice(vertice)
  grafo.Conecta(raiz, vertice, retorna.ObterVelocidade())
  
  construir_grafo(grafo, vertice)
    
def construir_grafo_com_lanterna(raiz, grafo):
  lista = ParaLista(raiz.ObterIntegrantes())
  num_integrantes = len(lista)
  
  if(num_integrantes is 4):
    gerar_travessia(raiz,grafo, lista, lista[0], lista[1]);
    gerar_travessia(raiz,grafo, lista, lista[0], lista[2]);
    gerar_travessia(raiz,grafo, lista, lista[0], lista[3]);
    gerar_travessia(raiz,grafo, lista, lista[1], lista[2]);
    gerar_travessia(raiz,grafo, lista, lista[1], lista[3]);
    gerar_travessia(raiz,grafo, lista, lista[2], lista[3]);
    
   
  elif(num_integrantes is 3):
    gerar_travessia(raiz,grafo, lista, lista[0], lista[1]);
    gerar_travessia(raiz,grafo, lista, lista[0], lista[2]);
    gerar_travessia(raiz,grafo, lista, lista[1], lista[2]);

  elif(num_integrantes is 2):
    gerar_travessia(raiz,grafo, lista, lista[0], lista[1]);
       
    
    
def construir_grafo_sem_lanterna(raiz, grafo):
  if(not raiz.EstaVazio()):
      
    lista = ParaLista(raiz.ObterIntegrantes())
    diferenca = U2.difference(raiz.ObterIntegrantes())
  
    for integrante in diferenca:
      gerar_retorno(raiz, grafo, lista, integrante)
  