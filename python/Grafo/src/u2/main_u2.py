# -*- coding: latin-1 -*-
from u2 import construtor_de_grafo
from u2.VerticeU2 import VerticeU2
from grafo.GrafoValorado import GrafoValorado
from sets import Set
import copy
from u2 import buscador_resposta

VERTICE_FINAL = VerticeU2(Set(), False)

grafo =  GrafoValorado()
construtor_de_grafo.construir_grafo(grafo)

caminho, custo = buscador_resposta \
  .busca_resposta(grafo, construtor_de_grafo.U2Raiz, VERTICE_FINAL, [], 0)
  
print 'Segue os vertices do caminho que resolve o problema'
print ''  

i = 1
for vertice in caminho:
  print 'Vertice ', i, ': ', vertice
  i += 1
  
print ''; print 'O custo total eh ', custo; print ''

print 'Segue agora as travessias e custos mais explicitamente: '

print ' Bono e Edge atravessam a ponte a um custo de ', \
       grafo.ValorDaConexao(caminho[0], caminho[1]), ' Minutos'

print ' Edge retorna com a lanterna a um custo de ', \
       grafo.ValorDaConexao(caminho[1], caminho[2]), ' Minutos'
       
print ' Larry e Adam atravessam a ponte a um custo de ', \
       grafo.ValorDaConexao(caminho[2], caminho[3]), ' Minutos'
       
print ' Bono retorna com a lanterna a um custo de ', \
       grafo.ValorDaConexao(caminho[3], caminho[4]), ' Minuto'
       
print ' Bono e Edge atravessam a ponte a um custo de ', \
       grafo.ValorDaConexao(caminho[4], caminho[5]), ' Minutos'
  
