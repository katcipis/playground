# -*- coding: latin-1 -*-
import copy
from sets import Set


class Grafo:
  
  def __init__(self):
    self._vertices = Set()
    self._arestas = Set()
  
  def AdcionaVertice(self, vertice):
    """Adiciona um novo vértice em G"""
    self._vertices.add(vertice)
    
  def AdcionaVertices(self, vertices):
    """Adiciona novos vértices em G"""
    for vertice in vertices:
      self.AdcionaVertice(vertice)
      
  def RemoveVertice(self, vertice):
    """Remove um  vértice de G, juntamente com todas as conexões"""
    if(self.PossuiVertice(vertice)):
      
      for v in self._vertices:
        self.Desconecta(vertice, v)
        
      self._vertices.discard(vertice)
        
        
  def Desconecta(self, vertice_um, vertice_dois):
    """Desconecta os vértices v1 e v2 em G"""
    removido = Aresta(vertice_um, vertice_dois)
    self._arestas.discard(removido)
        
    
  def Conecta(self, vertice_um, vertice_dois):
    """Conecta os vértices v1 e v2 em G"""
    if( (self.PossuiVertices([vertice_um, vertice_dois]))):
        
      aresta = Aresta(vertice_um, vertice_dois);
      self._arestas.add(aresta)
      
      
  def PossuiVertice(self, vertice):
    """Verifica se o vértice existe em G"""
    return vertice in self._vertices

  def PossuiVertices(self, vertices):
    """Verifica se os vértices existem em G"""
    for vertice in vertices:
      if(vertice not in self._vertices):
        return False;
    
    return True;

  def EstaoConectados(self, vertice_um, vertice_dois):
    """Verifica se os vértices estao conectados e estao em G"""
    for aresta in self._arestas:
      tmp = aresta.ObterVertices()
      if((vertice_um in tmp) and (vertice_dois in tmp)):
        if(vertice_um != vertice_dois):
          return True;
        else:
          return tmp[0] == tmp[1]
    
    return False;

  def EstaVazio(self):
    """Verifica se G não possui vértices"""
    return len(self._vertices) is 0

  def Ordem(self):
    """Retorna ordem de G"""
    return len(self._vertices)

  def RetornaVertices(self):
    """Retorna todos os vértices de G"""
    return self._vertices.copy()

  def RetornaVertice(self):
    """Retorna um vértice qualquer de G"""
    if(not self.EstaVazio()):
      tmp = self._vertices.pop()
      self._vertices.add(tmp)
      return tmp
  
    return None

  def Adjacentes(self, vertice):
    """Retorna todos os vértices adjacentes ao vértice dado"""
    adjacentes = set()
    for v in self._vertices:
      if(self.EstaoConectados(vertice, v)):
        adjacentes.add(v)
        
    return adjacentes

  def Grau(self, vertice):
    grau = 0
    for v in self._vertices:
      if(self.EstaoConectados(vertice, v)):
        grau += 1
        
    return grau
  
    
class Aresta:
  """ Aresta para ser utilizada no Grafo """  
    
  def __init__(self, vertice_um, vertice_dois, valor = None):
    self.__vertices = [vertice_um, vertice_dois]
    self.__valor = valor
    
  def ObterVertices(self):
    return copy.copy(self.__vertices)

  def ObterValor(self):
    return copy.copy(self.__valor)

  def __eq__(self, outro):
    if isinstance(outro, Aresta):
      if(self.__vertices[0] == outro.__vertices[0]):
        return self.__vertices[1] == outro.__vertices[1]
      
      if(self.__vertices[0] == outro.__vertices[1]):
        return self.__vertices[1] == outro.__vertices[0]
      
      return False

    return NotImplemented
    
  def __ne__(self, other):
    result = self.__eq__(other)
    if result is NotImplemented:
      return result
    
    return not result

  def __hash__(self):
    return hash(self.__vertices[0]) + hash(self.__vertices[1])

    
  