'''
Created on 23/09/2009
@author: katcipis
'''
from copy import copy
from enum.epsilon import EPSILON

class AFOperacaoIlegal(Exception):
  def __init__(self, operacao, detalhes):
    self.__operacao = operacao
    self.__detalhes = detalhes

  def __str__(self):
    msg = 'Erro na operacao : ' + str(self.__operacao) + '.\n'
    msg += 'Detalhes: ' + self.__detalhes + '\n'
    return msg

class ErroConstruindoAF(Exception):
  def __init__(self, msg_erro):
    self.__erro = msg_erro

  def __str__(self):
    return 'Erro construindo automato: ' + str(self.__erro)

class AutomatoFinito(object):
  '''
  Define um automato finito
  '''

  def __init__(self, alfabeto, estados):
    '''
    Construtor
    @param alfabeto: alfabeto 
    @param estados: conjunto de estados 
    '''
    self.__estados = estados
    self.__alfabeto = alfabeto
    
    self.__verificarEstadoInicial()
    self.__verificarTransicoes()

  def __verificarTransicoes(self):
    alfabeto_transicoes = set()
    nomes_estados_transicoes = set()
    nomes_estados = set()
    
    for estado in self.__estados:
      nomes_estados.add(estado.obterNome())
      for transicao in estado.obterTransicoes():
        alfabeto_transicoes.add(transicao.obterSimbolo())
        nomes_estados_transicoes.add(transicao.obterNomeEstadoDestino())
        
    diferenca_alfabeto = alfabeto_transicoes - self.__alfabeto 
    if(len(diferenca_alfabeto) != 0):
      texto = 'Os seguintes simbolos nao fazem parte do alfabeto do automato: '
      texto += str(diferenca_alfabeto)
      raise ErroConstruindoAF(texto)
    
    diferenca_nome_estados = nomes_estados_transicoes - nomes_estados  
    if(len(diferenca_nome_estados) != 0):
      texto = 'Os seguintes estados nao fazem parte do conjunto de estados do automato: '
      texto += str(diferenca_nome_estados)
      raise ErroConstruindoAF(texto)
    
  def __verificarEstadoInicial(self):
    qtdade_estados_iniciais = len([estado for estado in self.__estados if estado.ehInicial()])
    if (qtdade_estados_iniciais < 1):
      raise ErroConstruindoAF('Nao possui estado inicial')
      
    if (qtdade_estados_iniciais > 1):
      raise ErroConstruindoAF('Possui mais de um estado inicial')

  def obterEstados(self):
    ''' Retorna o conjunto de estados 
        @return: Conjunto de estados  
    '''
    return copy(self.__estados)
  
  def obterEstado(self, nome):
    ''' Dado o nome de um estado retorna a instancia do mesmo.
        @param nome: Nome do estado
        @return: estado com o nome informado ou None.
    '''
    for estado in self.__estados:
      if(nome == estado.obterNome()):
        return estado
    return None
  
  def obterEstadosFinais(self):
    ''' Retorna o conjunto de estados finais 
        @return: Conjunto de estados finais
    '''
    return set([estado for estado in self.__estados if estado.ehFinal()])
  
  def obterEstadoInicial(self):
    ''' Retorna o estado inicial do automato 
        @return: Estado inicial do automato 
    '''
    return [estado for estado in self.__estados if estado.ehInicial()].pop()
    
  def obterAlfabeto(self):
    return copy(self.__alfabeto)
  
  def ehDeterministico(self):
    for estado in self.__estados:
      transicoes = estado.obterTransicoes()
      simbolo_entrada_trans = set([transicao.obterSimbolo() for transicao in transicoes])
      if(len(transicoes) > len(simbolo_entrada_trans)):
        return False    
      
    return True
  
  def ehCompleto(self):
    for estado in self.__estados:
      simbolos_transicoes = set([transicao.obterSimbolo() for transicao in estado.obterTransicoes()])
      if(simbolos_transicoes != self.__alfabeto):
        return False
    return True
  
  def obterEstadosInalcancaveis(self):
    ''' Retorna o conjunto de estados inalcancaveis  
        @return: Conjunto de estados inalcancaveis
    '''
    alcancaveis = set([self.obterEstadoInicial()])
    marcou = True
  
    while(marcou):
      marcou = False
      for alcancavel in copy(alcancaveis):
        transicoes = alcancavel.obterTransicoes()
        for transicao in transicoes:
          estado_destino = self.obterEstado(transicao.obterNomeEstadoDestino())
          if(not estado_destino in alcancaveis):
            alcancaveis.add(estado_destino)
            marcou = True
            
    return self.obterEstados() - alcancaveis
  
  def obterEstadosMortos(self):
    ''' Retorna o conjunto de estados mortos 
        @return: Conjunto de estados mortos
    '''
    marcados = set(self.obterEstadosFinais())
    marcou = True
  
    while(marcou):
      marcou = False
      estados_nao_marcados = self.obterEstados() - marcados
      for estado in copy(estados_nao_marcados):
        transicoes = estado.obterTransicoes()
        for transicao in transicoes:
          estado_destino = self.obterEstado(transicao.obterNomeEstadoDestino())
          if(estado_destino in marcados):
            marcados.add(estado)
            marcou = True
          
    return set([estado for estado in self.obterEstados() - marcados])
  
  def obterClassesDeEquivalencia(self):
    ''' Retorna todos os conjuntos de equivalencia do automato, somente ira 
        funcionar se o automato for completo e deterministico.
        @return: Lista de todos os conjuntos de equivalencia do automato
    '''
    if(not self.ehDeterministico()):
      raise AFOperacaoIlegal('obterClassesDeEquivalencia', 'Automato nao eh deterministico')
    
    if(not self.ehCompleto()):
      raise AFOperacaoIlegal('obterClassesDeEquivalencia', 'Automato eh imcompleto')
    
    mudou = True
    classes_equivalencia = []
    
    finais = self.obterEstadosFinais()
    nao_finais = self.obterEstados() - self.obterEstadosFinais()
    if(finais != set()):
      classes_equivalencia.append(finais)
    if(nao_finais != set()):
      classes_equivalencia.append(nao_finais)
      
    while(mudou):
      mudou = False
      classes_equivalencia_nova = []
      for classe in classes_equivalencia:
        estado_ref = classe.pop()
        classe1 = set()
        classe2 = set()
        classe1.add(estado_ref)
        classe.add(estado_ref)
        for estado in classe:
          if(self.__estadosSaoEquivalentes(estado_ref, estado, classes_equivalencia)):
            classe1.add(estado)
          else:
            classe2.add(estado)
        
        classes_equivalencia_nova.append(classe1)
        if(classe2 != set()):
          mudou = True
          classes_equivalencia_nova.append(classe2)
      
      classes_equivalencia = classes_equivalencia_nova
      
    return classes_equivalencia  
  
  def ehMinimo(self):
    if(self.ehDeterministico() and self.ehCompleto()):
      return len(self.obterEstados()) == len(self.obterClassesDeEquivalencia())
  
    return False
  
  def reconhecePalavra(self, palavra):
    if(not self.ehDeterministico()):
      raise AFOperacaoIlegal('reconhecePalavra', 'Automato deve ser deterministico para reconhecer uma palavra')
    
    if(palavra == EPSILON):
      return self.obterEstadoInicial().ehFinal()
    
    estado_atual = self.obterEstadoInicial()
    while(palavra != ''):
      simbolo = palavra[0]
      palavra = palavra[1:]
      transicao = estado_atual.obterTransicoesPorSimbolo(simbolo)
      if(transicao == set()):
        return False
      transicao = transicao.pop()
      estado_atual = self.obterEstado(transicao.obterNomeEstadoDestino())
      
    return estado_atual.ehFinal()
  
  def __str__(self):
    if(self.ehDeterministico()):
      str_repr = '<<<< Automato Finito Deterministico >>>> \n'
    else:
      str_repr = '<<<< Automato Finito Nao Deterministico >>>> \n'
      
    str_repr += 'Alfabeto ' + str(self.__alfabeto) + '\n'
    for estado in self.__estados:
      str_repr += str(estado)
      
    return str_repr
    
  def __estadosSaoEquivalentes(self, estado_ref, estado, classes_equivalencia):
    equivalentes = 0
    for simbolo in self.obterAlfabeto():
      trans_ref = estado_ref.obterTransicoesPorSimbolo(simbolo).pop()
      trans = estado.obterTransicoesPorSimbolo(simbolo).pop()
      estado_dest_ref = self.obterEstado(trans_ref.obterNomeEstadoDestino())
      estado_dest = self.obterEstado(trans.obterNomeEstadoDestino())
      
      
      for classe in classes_equivalencia:
        if((estado_dest in classe) and (estado_dest_ref in classe)):
          equivalentes += 1
         
    return equivalentes == len(self.obterAlfabeto())