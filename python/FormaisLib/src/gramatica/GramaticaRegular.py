'''
Created on 30/10/2009
@author: katcipis
'''
from gramatica.GramaticaLivreContexto import GramaticaLivreContexto
from gramatica.Producao import Producao
from enum.epsilon import EPSILON
from enum.separadores import SEPARADOR_SIMBOLO_PRODUCAO

class ErroConstruindoGramaticaRegular(Exception):
  def __init__(self, msg_erro):
    self.__erro = msg_erro

  def __str__(self):
    return 'Erro construindo gramatica regular: ' + str(self.__erro)
  

class GramaticaRegular(GramaticaLivreContexto):
  '''
  Classe que define uma gramatica regular.
  '''
  
  def __verificar_epsilon_producoes(self):
    produz_epsilon = False
    for prod in self.obterProducoes():
      beta = prod.obterBeta()
      if(beta.find(EPSILON) != -1):
        if((len(beta) == 1) and (prod.obterAlpha() == self._simbolo_inicial)):
          produz_epsilon = True
        else:
          raise ErroConstruindoGramaticaRegular('Producao [{0}] invalida!!'.format(str(prod)))
        
    if(produz_epsilon):
      for prod in self.obterProducoes():
        if(prod.obterBeta().find(self._simbolo_inicial) != -1):
          raise ErroConstruindoGramaticaRegular('Producao [{0}] invalida!!'.format(str(prod)))

  def __obter_producoes_com_separador(self, producoes):
    novas_prod = set()
    
    for prod in producoes:
      if(len(prod.obterBeta()) == 1):
        novas_prod.add(prod)
      else:
        beta = prod.obterBeta()[0] + SEPARADOR_SIMBOLO_PRODUCAO + prod.obterBeta()[1:] 
        nova_prod = Producao(prod.obterAlpha(), beta)
        novas_prod.add(nova_prod)
        
    return novas_prod
    
  def __remover_separador_producoes(self):
    producoes = set()
    for prod in self._producoes:
      prod_n = Producao(prod.obterAlpha(), prod.obterBeta().replace(SEPARADOR_SIMBOLO_PRODUCAO, ''))
      producoes.add(prod_n)
      
    self._producoes = producoes
  
  def __init__(self, producoes, nao_terminais, terminais, simbolo_inicial):
    '''
    Construtor
    @param producoes: conjunto de producoes da gramatica.
    @param nao_terminais: conjunto de nao terminais (Vn).
    @param terminais: conjunto de terminais (Vt).
    @param simbolo_inicial: simbolo inicial da gramatica (S).
    @attention: Sao inseridos espacos nas producoes para manter compatibilidade com as demais gramaticas
                que necessitam de espacos entre os nao-terminais e terminais para resolver ambiguidades e realizar 
                verificacoes. Os espacos depois sao removidos pois nao eh necessario espaco para resolver ambiguidades 
                jah que gramaticas regulares soh podem comecar com UM terminal que pode ser seguido de UM nao-terminal.
    '''
    GramaticaLivreContexto.__init__(self, self.__obter_producoes_com_separador(producoes), nao_terminais, terminais, simbolo_inicial)
    self.__remover_separador_producoes()
    self.__verificar_epsilon_producoes()
    
    for prod in self._producoes:
      beta = prod.obterBeta()
      alpha = prod.obterAlpha()
      
      if(not alpha in nao_terminais):
        raise ErroConstruindoGramaticaRegular('Producao [{0}] invalida!!'.format(str(prod)))
      
      if(not beta[0] in self._terminais):
        if(beta[0] != EPSILON):
          raise ErroConstruindoGramaticaRegular('Producao [{0}] invalida!!'.format(str(prod)))
      
      if(len(beta) >= 2):
        if(not beta[1:] in self._nao_terminais):
          raise ErroConstruindoGramaticaRegular('Producao [{0}] invalida!!'.format(str(prod)))
      