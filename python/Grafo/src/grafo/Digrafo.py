# -*- coding: latin-1 -*-

from Grafo import Grafo
import copy

class Digrafo(Grafo):
    
  def Conecta(self, antecessor, suscessor):
    """Conecta os vértices v1 e v2 em G com valor associado"""
    if( (self.PossuiVertices([antecessor, suscessor]))):
      arco = Arco(antecessor, suscessor);
      self._arestas.add(arco)
    
  def Desconecta(self, antecessor, suscessor):
    """Desconecta os vértices v1 e v2 em G"""
    removido = Arco(antecessor, suscessor)
    self._arestas.discard(removido)
    
  def Antecessores(self, v):
    """Retorna um conjunto contendo os vértices que são antecessores de v em G"""
    antecessores = []
    
    if(self.PossuiVertice(v)):
      for arco in self._arestas:
        if(arco.ObterSuscessor() == v):
          antecessores.append(arco.ObterAntecessor())
          
    return antecessores
      
    
  def Suscessores(self, v):
    """Retorna um conjunto contendo os vértices que são sucessores de v em G"""
    suscessores = []
    
    if(self.PossuiVertice(v)):
      for arco in self._arestas:
        if(arco.ObterAntecessor() == v):
          suscessores.append(arco.ObterSuscessor())
          
    return suscessores
    
  def GrauDeEmissao(self, v):
    """Retorna o número de vértices sucessores de v em G"""
    sum = 0
    
    if(self.PossuiVertice(v)):
      for arco in self._arestas:
        if(arco.ObterAntecessor() == v):
          sum += 1
          
    return sum
    
  def GrauDeRecepcao(self, v):
    """Retorna o número de vértices antecessores de v em G"""
    sum = 0
    
    if(self.PossuiVertice(v)):
      for arco in self._arestas:
        if(arco.ObterSuscessor() == v):
          sum += 1
          
    return sum
  
  def EstaoConectados(self, antecessor, suscessor):
    """Verifica se os vértices estao conectados e estao em G"""
    for arco in self._arestas:
      if(arco.ObterAntecessor() == antecessor and
         arco.ObterSuscessor() == suscessor):
        return True
    
    return False
  
  def Adjacentes(self, vertice):
    """Retorna todos os vértices adjacentes ao vértice dado"""
    adjacentes = set()
    for v in self._vertices:
      if(Grafo.EstaoConectados(self, vertice, v)):
        adjacentes.add(v)
        
    return adjacentes
  
  def Grau(self, vertice):
    grau = 0
    for v in self._vertices:
      if(Grafo.EstaoConectados(self, vertice, v)):
        grau += 1
        
    return grau
    
class Arco:
  """ Arco para ser utilizado no Digrafo """  
    
  def __init__(self, antecessor, suscessor, valor = None):
    self.__vertices = [antecessor, suscessor]
    self.__valor = valor
    
  def ObterVertices(self):
    return copy.copy(self.__vertices)

  def ObterValor(self):
    return copy.copy(self.__valor)
  
  def ObterSuscessor(self):
    return self.ObterVertices()[1]
    
  def ObterAntecessor(self):
    return self.ObterVertices()[0]

  def __eq__(self, outro):
    if isinstance(outro, Arco):
      assertUm = self.ObterSuscessor() == outro.ObterSuscessor()
      assertDois = self.ObterAntecessor() == outro.ObterAntecessor()
      return (assertUm and assertDois)

    return NotImplemented
    
  def __ne__(self, other):
    result = self.__eq__(other)
    if result is NotImplemented:
      return result
    
    return not result

  def __hash__(self):
    return  hash(self.ObterVertices()[0]) - hash(self.ObterVertices()[1]) 
           