# -*- coding: latin-1 -*-
from u2 import construtor_de_grafo
from u2.VerticeU2 import VerticeU2
from grafo.GrafoValorado import GrafoValorado
from sets import Set
import copy

CUSTO_MAXIMO = 17

def imprime_grafo():
    for vertice in grafo.RetornaVertices():
        print 'Adjacentes do vertice ', vertice
        adjacentes = grafo.Adjacentes(vertice)
        for adjacente in adjacentes:
            print adjacente
        
        print 'Termina os adjacentes deste vertice'
        print ''
        
def busca_resposta(grafo, vertice, final, percorridos, custo_total):
  perc = copy.copy(percorridos)
  perc.append(vertice)

  if(custo_total > CUSTO_MAXIMO):
    return ()

  if(vertice == final):
    return perc, custo_total


  adjacentes = grafo.Adjacentes(vertice)
  
  for adjacente in adjacentes:
    if(not (adjacente in percorridos)):
      custo = custo_total + grafo.ValorDaConexao(vertice, adjacente)  
      caminho = busca_resposta(grafo, adjacente, final, perc, custo)
      if( not(len(caminho) is 0)):
        return caminho

 
  return ()
  