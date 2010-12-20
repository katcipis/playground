'''
Created on 30/10/2009
@author: katcipis
'''
from copy import copy
from enum.epsilon import EPSILON
from enum.separadores import SEPARADOR_SIMBOLO_PRODUCAO

class ErroConstruindoGramatica(Exception):
  def __init__(self, msg_erro):
    self.__erro = msg_erro

  def __str__(self):
    return str(self.__erro)

class Gramatica(object):
  '''
  Classe que define uma gramatica recursiva sem restricoes.
  '''
  
  def __eq__(self, outro):
    if(isinstance(outro, Gramatica)):
      cond1 = self._simbolo_inicial == outro._simbolo_inicial
      cond2 = self._terminais == outro._terminais
      cond3 = self._nao_terminais == outro._nao_terminais
      cond4 = self._producoes == outro._producoes
      return cond1 and cond2 and cond3 and cond4
    
    return False
  
  def __str__(self):
    glc_str = '<<<Gramatica>>>\n'
    glc_str += 'Simbolo Inicial = ' + str(self._simbolo_inicial) + '\n'
    glc_str += 'VN = ' + str(self._nao_terminais) + '\n'
    glc_str += 'VT = ' + str(self._terminais) + '\n'
    glc_str += 'Producoes: \n'
    for prod in self._producoes:
      glc_str += str(prod) + '\n'
      
    return glc_str
        
  def _remover_espacos(self, lista):
    return [fn for fn in lista if fn != '']
  
  def __obterNaoTerminais(self, palavra):    
    palavras = palavra.split(SEPARADOR_SIMBOLO_PRODUCAO)
    return set([fs for fs in palavras if fs in self._nao_terminais])
  
  def __verifica_producoes(self, producoes, v_estrela):
    for prod in producoes:
      formas_sentenciais = prod.obterBeta().split(SEPARADOR_SIMBOLO_PRODUCAO) 
      formas_sentenciais.extend(prod.obterAlpha().split(SEPARADOR_SIMBOLO_PRODUCAO))
      
      for fs in formas_sentenciais:
        if(fs != EPSILON):
          if((not fs in v_estrela)):
            raise ErroConstruindoGramatica('Producao [{0}] invalida, possui forma sentencial que nao existe nem em VN nem em VT'.format(str(prod)))
            
    
  def __init__(self, producoes, nao_terminais, terminais, simbolo_inicial):
    '''
    Construtor
    @param producoes: conjunto de producoes da gramatica.
    @param nao_terminais: conjunto de nao terminais (Vn).
    @param terminais: conjunto de terminais (Vt).
    @param simbolo_inicial: simbolo inicial da gramatica (S).
    '''
    if((nao_terminais & terminais) != set()):
      msg = 'Intersecao entre Vn e Vt nao eh vazia!\n Vn={0}\n Vt={1}\n'
      msg = msg.format(nao_terminais, terminais)
      raise ErroConstruindoGramatica(msg)
      
    v_estrela = copy(nao_terminais)
    v_estrela.update(terminais)
    v_estrela.add(EPSILON)
    
    self.__verifica_producoes(producoes, v_estrela)
    
    for terminal in terminais:
      if(len(terminal) > 1):
        raise ErroConstruindoGramatica('Terminal [{0}] invalido'.format(terminal))
      
    if(not simbolo_inicial in nao_terminais):
      raise ErroConstruindoGramatica('Simbolo inicial [{0}] nao pertence a Vn'.format(simbolo_inicial))
    
    self._simbolo_inicial = simbolo_inicial
    self._nao_terminais = copy(nao_terminais)
    self._terminais = copy(terminais)
    self._producoes = copy(producoes)
    
  def obterProducoes(self):
    return copy(self._producoes)
  
  def obterNaoTerminais(self):
    return copy(self._nao_terminais)
  
  def obterTerminais(self):
    return copy(self._terminais)
  
  def obterSimboloInicial(self):
    return self._simbolo_inicial
  
  def obterNaoTerminaisDoBeta(self, prod):
    if(not prod in self._producoes):
      return None
    
    return self.__obterNaoTerminais(prod.obterBeta())
  
  def obterNaoTerminaisDoAlpha(self, prod):
    if(not prod in self._producoes):
      return None
    
    return self.__obterNaoTerminais(prod.obterAlpha())
  
  def obterTerminaisDoBeta(self, prod):
    if(not prod in self._producoes):
      return None
    
    beta = prod.obterBeta().split(SEPARADOR_SIMBOLO_PRODUCAO)
    return set([fs for fs in beta if fs in self._terminais])
  
  def obterProducoesDoAlpha(self, alpha):
    producoes = set()
    alpha = self._remover_espacos(alpha.split(SEPARADOR_SIMBOLO_PRODUCAO))
    
    for prod in self._producoes:
      if(alpha == prod.obterAlpha().split(SEPARADOR_SIMBOLO_PRODUCAO)):
        producoes.add(prod)
        
    return producoes
        