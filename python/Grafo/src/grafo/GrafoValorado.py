# -*- coding: latin-1 -*-
from Grafo import Grafo
from Grafo import Aresta

class GrafoValorado(Grafo):
    
  def Conecta(self, vertice_um, vertice_dois, valor):
    """Conecta os vértices v1 e v2 em G com valor associado"""
    if((self.PossuiVertices([vertice_um, vertice_dois]))):
       aresta = Aresta(vertice_um, vertice_dois, valor);
       self._arestas.add(aresta)
       
  def ValorDaConexao(self, vertice_um, vertice_dois):
    """Retorna o valor da conexão entre v1 e v2 se ela existir"""
    for aresta in self._arestas:
      tmp = aresta.ObterVertices()
      if((vertice_um in tmp) and (vertice_dois in tmp)):
        if(vertice_um != vertice_dois):
          return aresta.ObterValor();
        else:
          if(tmp[0] == tmp[1]):
            return aresta.ObterValor();
    
    return None;