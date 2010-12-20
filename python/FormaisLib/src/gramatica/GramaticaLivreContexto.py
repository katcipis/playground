'''
Created on 17/11/2009
@author: katcipis
'''
from gramatica.Gramatica import Gramatica
from enum.epsilon import EPSILON
from enum.separadores import SEPARADOR_SIMBOLO_PRODUCAO
from enum.marcadores import FIM_DE_SENTENCA
from copy import deepcopy

class ErroConstruindoGramaticaLivreContexto(Exception):
  def __init__(self, msg_erro):
    self.__erro = msg_erro

  def __str__(self):
    return 'Erro construindo gramatica livre de contexto: ' + str(self.__erro)

class GramaticaLivreContexto(Gramatica):
  '''
  classe que define uma Gramatica Livre de Contexto.
  '''
  
  def __obter_nao_terminal_no_inicio_beta(self, prod):
    if(prod.obterSimboloBeta(0) in self._nao_terminais):
      return prod.obterSimboloBeta(0)   
    return None

  def __nt_possui_ciclo(self, nt_origem, nt_beta, nt_investigados):
    if(nt_origem == nt_beta):
      return True
  
    nt_investigados.add(nt_beta)
    investigar = set()
  
    for prod in self.obterProducoesDoAlpha(nt_beta):
      if(len(prod.obterBeta()) == 1 and 
         prod.obterBeta() in self._nao_terminais and
         not prod.obterBeta() in nt_investigados):
      
        investigar.add(prod.obterBeta())
        
    for nt in investigar:
      if(self.__nt_possui_ciclo(nt_origem, nt, nt_investigados)):
        return True
  
    return False

  def __verifica_alpha(self):
    for prod in self._producoes:
      alpha = prod.obterAlpha().split(SEPARADOR_SIMBOLO_PRODUCAO)
      if(len(alpha) != 1):
        raise ErroConstruindoGramaticaLivreContexto('Producao invalida [{0}]'.format(str(prod)))
      
  
  def __calculaFollow(self):
    follow = {}
    follow_antigo = {}
    for nao_terminal in self._nao_terminais:
      follow[nao_terminal] = set()
    follow[self._simbolo_inicial].add(FIM_DE_SENTENCA)
    
    while(follow != follow_antigo):
      follow_antigo = deepcopy(follow)
      
      for prod in self._producoes:
        for i in range(prod.obterTamanhoBeta()):
          if(prod.obterSimboloBeta(i) in self._nao_terminais):
            percorre_beta = True; j = i + 1
            while(percorre_beta):
              if(j == prod.obterTamanhoBeta()):
                follow[prod.obterSimboloBeta(i)].update(follow[prod.obterAlpha()])
                percorre_beta = False
              elif(prod.obterSimboloBeta(j) in self._nao_terminais):
                follow[prod.obterSimboloBeta(i)].update(self.obterFirst(prod.obterSimboloBeta(j)) - set([EPSILON]))
                if(not EPSILON in self.obterFirst(prod.obterSimboloBeta(j))):
                  percorre_beta = False
              else:
                follow[prod.obterSimboloBeta(i)].add(prod.obterSimboloBeta(j))
                percorre_beta = False
              j+=1
               
    self.__follow = follow      
  
  
  def __calculaFirst(self):
    first = {}
    first_antigo = {}
    for nao_terminal in self._nao_terminais:
      first[nao_terminal] = set()
    
    while(first != first_antigo):
      first_antigo = deepcopy(first)

      for nao_terminal in self._nao_terminais:
        for prod in self.obterProducoesDoAlpha(nao_terminal):
          percorre_beta = True
          i = 0
          while(percorre_beta):
            if(i == prod.obterTamanhoBeta()):
              first[nao_terminal].add(EPSILON)
              percorre_beta = False
            elif(prod.obterSimboloBeta(i) in self._nao_terminais):
              first[nao_terminal].update(first[prod.obterSimboloBeta(i)] - set([EPSILON]))
              if(not EPSILON in first[prod.obterSimboloBeta(i)]):
                percorre_beta = False
            else:
              first[nao_terminal].add(prod.obterSimboloBeta(i))
              percorre_beta = False
            i+=1
            
    self.__first = first      
      
  
  def __init__(self, producoes, nao_terminais, terminais, simbolo_inicial):
    '''
    Construtor
    @param producoes: conjunto de producoes da gramatica.
    @param nao_terminais: conjunto de nao terminais (Vn).
    @param terminais: conjunto de terminais (Vt).
    @param simbolo_inicial: simbolo inicial da gramatica (S).
    '''
    Gramatica.__init__(self, producoes, nao_terminais, terminais, simbolo_inicial)
    self.__verifica_alpha()
    self.__calculaFirst()
    self.__calculaFollow()
    
  def __possui_recursao_esquerda_indireta(self, nt, nt_alcancado, analisados):
    analisados.add(nt_alcancado)
    
    if(nt == nt_alcancado):
      return True
    
    for prod in self.obterProducoesDoAlpha(nt_alcancado):
      nt_inicio = self.__obter_nao_terminal_no_inicio_beta(prod)
      if(nt_inicio != None):
        if(self.__possui_recursao_esquerda_indireta(nt, nt_inicio, analisados)):
          return True
        
    return False
    
  def possuiRecursaoAEsquerda(self):
    for nt in self._nao_terminais:
      for prod in self.obterProducoesDoAlpha(nt):
        nt_inicio = self.__obter_nao_terminal_no_inicio_beta(prod)
        if(nt_inicio != None):
          if(self.__possui_recursao_esquerda_indireta(nt, nt_inicio, set())):
            return True
          
    return False
      
      
  def estaFatorada(self):
    for nt in self.obterNaoTerminais():
      for prod_i in self.obterProducoesDoAlpha(nt):
        for prod_j in self.obterProducoesDoAlpha(nt):
          if(prod_i != prod_j):
            first_i = self.obterFirst(prod_i.obterSimboloBeta(0))
            first_j = self.obterFirst(prod_j.obterSimboloBeta(0))
            if(first_i.intersection(first_j) != set()):
              return False
            
    return True
  
  def possuiCiclo(self):
    for nt in self._nao_terminais:
      for prod in self.obterProducoesDoAlpha(nt):
        if(len(prod.obterBeta()) == 1 and prod.obterBeta() in self._nao_terminais):
          if(self.__nt_possui_ciclo(nt, prod.obterBeta(), set())):
            return True
          
    return False


  def obterFirst(self, simbolo):
    if(simbolo == EPSILON):
      return set([EPSILON])
    
    if(simbolo in self._nao_terminais):
      return self.__first[simbolo]
    
    if(simbolo in self._terminais):
      return set([simbolo])
    
    
  def obterFollow(self, nao_terminal):
    if(nao_terminal in self._nao_terminais):
      return self.__follow[nao_terminal]
  
  def obterNaoTerminaisQueDerivamEpsilon(self):      
    marcados = set()
    
    for prod in self._producoes:
      if(prod.obterBeta() == EPSILON):
        marcados.add(prod.obterAlpha())
    
    marcou = True
    while(marcou):
      marcou = False
      nao_marcados = self.obterNaoTerminais() - marcados
      for nao_marcado in nao_marcados:
        for prod in self.obterProducoesDoAlpha(nao_marcado):
          nao_terminais = self.obterNaoTerminaisDoBeta(prod)
          if(nao_terminais.issubset(marcados) and
             self.obterTerminaisDoBeta(prod) == set()):
            marcados.add(nao_marcado)
            marcou = True
            break
          
    return marcados
            
          
        