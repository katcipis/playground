'''
Created on 04/12/2009
@author: katcipis
'''

from PyQt4 import QtCore, QtGui
from gramatica.Producao import Producao
from gramatica.GramaticaLivreContexto import GramaticaLivreContexto
from util import util

class ErroGramaticaLivreContextoGUIParseGLC(Exception):
  def __init__(self, msg_erro):
    self.__erro = msg_erro

  def __str__(self):
    return str('Ocorreu um erro realizando o parse da gramatica: \n' + self.__erro)

class GramaticaLivreContextoGUI(object):
  '''
  Defina classe que controla a GUI da expressao regular.
  '''

  def __init__(self, ui, janela_principal):
    '''
    Construtor
    @param ui: a gui carregada na memoria.
    @param janela_principal: janela principal que criou a GLC.
    '''
    self.__ui = ui
    self.__janela_principal = janela_principal
    
    self.__janela_principal.connect(self.__ui.remover_ciclos_glc, QtCore.SIGNAL("clicked()"), self.clicouRemoverCiclos)
    self.__janela_principal.connect(self.__ui.remover_inuteis_glc, QtCore.SIGNAL("clicked()"), self.clicouRemoverInuteis)
    
    self.__janela_principal.connect(self.__ui.epsilon_livre_glc, QtCore.SIGNAL("clicked()"), self.clicouEpsilonLivre)
    self.__janela_principal.connect(self.__ui.obter_info_glc, QtCore.SIGNAL("clicked()"), self.clicouObterInfo)
    self.__janela_principal.connect(self.__ui.remover_rec_esq_glc, QtCore.SIGNAL("clicked()"), self.clicouRemoverRecEsquerda)
    self.__janela_principal.connect(self.__ui.fatorar_glc, QtCore.SIGNAL("clicked()"), self.clicouFatorar)
    
    self._error = QtGui.QErrorMessage(janela_principal)
    self._error.setWindowTitle('Erro')
    self.__separadores_alpha_beta = ['::=', '->']
    self.__separador_beta = '|'
    
  
  def __obterGLC(self):
    producoes = set()
    simbolo_inicial = False
    alfabeto = set()
    
    for linha in str(self.__ui.campo_glc.toPlainText()).split('\n'):
      producao = ''
      for separador in self.__separadores_alpha_beta:
        producao = linha.split(separador)
        if(len(producao) == 2):
          break
        
      if(len(producao) != 2):
        continue
      
      alpha = producao[0]
      if(not simbolo_inicial):
        simbolo_inicial = alpha.replace(' ', '')

      betas = producao[1].split(self.__separador_beta)
      for beta in betas:
        producoes.add(Producao(alpha, beta))
        for simbolo in beta:
          if(not (simbolo.isalpha() and simbolo.isupper())):
            alfabeto.add(simbolo)
      
    if(not simbolo_inicial):
      raise ErroGramaticaLivreContextoGUIParseGLC(str(self.__ui.campo_glc.toPlainText()))
     
    nts = set([prod.obterAlpha() for prod in producoes])
    return GramaticaLivreContexto(producoes, nts, alfabeto, simbolo_inicial)
  
  
  def __obterFollowOuFirst(self, glc, func):
    repr_str = ''
    for nt in glc.obterNaoTerminais():
      conjunto_nt = func(nt)
      if(conjunto_nt != set()):
        repr_str += nt + '{ ' + conjunto_nt.pop()
        for terminal in conjunto_nt:
          repr_str += ' , ' + terminal
        repr_str += '}\n'
      else:
        repr_str += nt + '{ }\n'
    return repr_str
  
  
  def __obter_str_producoes_nt(self, glc, nt):
    producoes = [prod for prod in glc.obterProducoesDoAlpha(nt)]
    prod_str = nt + ' ' + self.__separadores_alpha_beta[0] + ' ' + producoes[0].obterBeta()
    for i in range(1, len(producoes)):
      prod_str += ' ' + self.__separador_beta + ' ' + producoes[i].obterBeta()
    return prod_str + '\n'
    
    
  def __setarGLC(self, glc):
    glc_str = self.__obter_str_producoes_nt(glc, glc.obterSimboloInicial())
    
    for nt in (glc.obterNaoTerminais() - set([glc.obterSimboloInicial()])):
      glc_str += self.__obter_str_producoes_nt(glc, nt)
     
    self.__ui.campo_glc.setPlainText(glc_str)
    
    
  def clicouRemoverCiclos(self):
    try:
      glc = self.__obterGLC()
      glc = util.remover_ciclos_glc(glc)
      self.__setarGLC(glc)
      
    except Exception as excecao:
      self._error.showMessage(str(excecao))
  
  
  def clicouRemoverInuteis(self):
    try:
      glc = self.__obterGLC()
      glc = util.remover_simbolos_inuteis_glc(glc)
      self.__setarGLC(glc)
      
    except Exception as excecao:
      self._error.showMessage(str(excecao))
  
  
  def clicouEpsilonLivre(self):
    try:
      glc = self.__obterGLC()
      glc = util.transformar_em_epsilon_livre_glc(glc)
      self.__setarGLC(glc)
      
    except Exception as excecao:
      self._error.showMessage(str(excecao))
    
    
  def clicouObterInfo(self):
    try:
      glc = self.__obterGLC()
      self.__ui.campo_follow_glc.setPlainText(self.__obterFollowOuFirst(glc, glc.obterFollow))
      self.__ui.campo_first_glc.setPlainText(self.__obterFollowOuFirst(glc, glc.obterFirst))
      
      if(glc.estaFatorada()):
        self.__ui.rotulo_fatorada.setText('Fatorada: SIM')
      else:
        self.__ui.rotulo_fatorada.setText('Fatorada: NAO')
        
      if(glc.possuiRecursaoAEsquerda()):
        self.__ui.rotulo_rec_esquerda.setText('Rec a esquerda: SIM')
      else:
        self.__ui.rotulo_rec_esquerda.setText('Rec a esquerda: NAO')
        
    except Exception as excecao:
      self._error.showMessage(str(excecao))
   
   
  def clicouRemoverRecEsquerda(self):
    try:
      glc = self.__obterGLC()
      glc = util.remover_recursao_esquerda_glc(glc)
      self.__setarGLC(glc)
      
    except Exception as excecao:
      self._error.showMessage(str(excecao))
           
           
  def clicouFatorar(self):
    try:
      passos = int(str(self.__ui.campo_passos_glc.text()))
      glc = self.__obterGLC()
      glc = util.fatorar_glc(glc, passos)
      self.__setarGLC(glc)
      
    except Exception as excecao:
      self._error.showMessage(str(excecao))
    
