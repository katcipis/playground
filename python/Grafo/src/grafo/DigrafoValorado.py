# -*- coding: latin-1 -*-

from grafo.Digrafo import Arco
from grafo.Digrafo import Digrafo
import copy

class DigrafoValorado(Digrafo):
    
  def Conecta(self, antecessor, suscessor, valor = None):
    """Conecta os vértices v1 e v2 em G com valor associado"""
    if( (self.PossuiVertices([antecessor, suscessor]))):
      arco = Arco(antecessor, suscessor, valor);
      self._arestas.add(arco)
    
  def ValorDaConexao(self, antecessor, suscessor):
    """Retorna o valor da conexão entre v1 e v2 se ela existir"""
    for arco in self._arestas:
      mesmo_antecessor = arco.ObterAntecessor() == antecessor
      mesmo_suscessor = arco.ObterSuscessor() == suscessor
      
      if(mesmo_antecessor and mesmo_suscessor):
        return arco.ObterValor()
    
    return None;
    
           