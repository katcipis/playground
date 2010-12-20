# -*- coding: latin-1 -*-

from grafo.DigrafoValorado import DigrafoValorado
import copy

class Rede(DigrafoValorado):
  """Digrafo sem laços que possui exatamente uma raiz e uma anti-raiz"""
  
  def __init__(self):
    DigrafoValorado.__init__(self)
    self._raiz = None
    self._anti_raiz = None
  
  def Conecta(self, antecessor, suscessor, valor = 0, capacidade = 0):
    """Conecta os vértices v1 e v2 em G com valor associado"""
    if( (self.PossuiVertices([antecessor, suscessor])) and
        (antecessor != suscessor) and (suscessor != self._raiz) and 
        (antecessor != self._anti_raiz) ):
      
      arco = ArcoComCapacidadeMaxima(antecessor, suscessor, valor, capacidade);
      self._arestas.add(arco)
      
  def Desconecta(self, antecessor, suscessor):
    """Desconecta os vértices v1 e v2 em G"""
    removido = ArcoComCapacidadeMaxima(antecessor, suscessor)
    self._arestas.discard(removido)
    
  def Raiz(self, raiz):
    """Define qual será a raiz da rede"""
    if((self._raiz is None) and (not self.PossuiVertice(raiz))):
      self.AdcionaVertice(raiz)
      self._raiz = raiz
    
  def AntiRaiz(self, anti_raiz):
    """Define qual será a anti-raiz da rede"""
    if((self._anti_raiz is None) and (not self.PossuiVertice(anti_raiz))):
      self.AdcionaVertice(anti_raiz)
      self._anti_raiz = anti_raiz
      
  def ObterRaiz(self):
    return copy.copy(self._raiz)
  
  def ObterAntiRaiz(self):
    return copy.copy(self._anti_raiz)
  
  def CapacidadeDaConexao(self, antecessor, suscessor):
    """Retorna o valor da capacidade entre v1 e v2 se ela existir"""
    for arco in self._arestas:
      mesmo_antecessor = arco.ObterAntecessor() == antecessor
      mesmo_suscessor = arco.ObterSuscessor() == suscessor
      
      if(mesmo_antecessor and mesmo_suscessor):
        return arco.ObterCapacidade()
    
    return None;
    
  
  
class ArcoComCapacidadeMaxima:
  """Arco que possui fluxo máximo"""
  
  def __init__(self, antecessor, suscessor, valor = 0, capacidade = 0):
    self.__vertices = [antecessor, suscessor]
    self.__capacidade = 0
    self.__valor = 0
    
    if(capacidade > 0):
      self.__capacidade = capacidade
      
    if(valor >= 0):
      if(valor > self.__capacidade):
        self.__valor = self.__capacidade
      else:
        self.__valor = valor
    
  def ObterCapacidade(self):
    return copy.copy(self.__capacidade)
  
  def ObterVertices(self):
    return copy.copy(self.__vertices)

  def ObterValor(self):
    return copy.copy(self.__valor)
  
  def ObterSuscessor(self):
    return self.ObterVertices()[1]
    
  def ObterAntecessor(self):
    return self.ObterVertices()[0]

  def __eq__(self, outro):
    if isinstance(outro, ArcoComCapacidadeMaxima):
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
    return  hash(self.ObterVertices()[1]) - hash(self.ObterVertices()[0]) 
   