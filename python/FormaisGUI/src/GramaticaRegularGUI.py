'''
Created on 04/11/2009
@author: katcipis
'''
from PyQt4 import QtCore, QtGui
from gramatica.GramaticaRegular import GramaticaRegular
from gramatica.Producao import Producao
from TabelaAbstrataGUI import TabelaAbstrataGUI
from util import util

class GramaticaRegularGUI(TabelaAbstrataGUI):
  '''
  Defina classe que controla a GUI da gramatica regular.
  '''

  def __init__(self, ui, janela_principal):
    '''
    Construtor
    @param ui: a gui carregada na memoria.
    '''
    TabelaAbstrataGUI.__init__(self, janela_principal)
    self.__ui = ui
    
    self._janela_principal.connect(self.__ui.salvar_gramatica, QtCore.SIGNAL("clicked()"), self.clicouSalvar)
    self._janela_principal.connect(self.__ui.carregar_gramatica, QtCore.SIGNAL("clicked()"), self.clicouCarregar)
    self._janela_principal.connect(self.__ui.gramatica_em_automato, QtCore.SIGNAL("clicked()"), self.clicouTransformarEmAFD)
    self._janela_principal.connect(self.__ui.adcionar_producao, QtCore.SIGNAL("clicked()"), self.clicouAdcionarProducao)
    self._janela_principal.connect(self.__ui.adcionar_nt, QtCore.SIGNAL("clicked()"), self.clicouAdcionarNT)
    self._janela_principal.connect(self.__ui.remover_nt, QtCore.SIGNAL("clicked()"), self.clicouRemoverNT)
    self._janela_principal.connect(self.__ui.limpar_gramatica, QtCore.SIGNAL("clicked()"), self._limparTabela)
    self._janela_principal.connect(self._obterTabela(), QtCore.SIGNAL("cellChanged(int,int)"), self.modificouTransicao)
    
    self.__separadores = ['::=', '->']
    
    
  def obterGR(self):
    tabela = self._obterTabela()
    vn = set()
    vt = set()
    producoes = set()
    simbolo_inicial = None
    
    for i in range(tabela.rowCount()):
      nt, prod, eh_inicial = self.__obterNT(i)
      vn.add(nt)
      producoes.update(prod)
      if(eh_inicial):
        simbolo_inicial = nt
    
    for prod in producoes:
      vt.add(prod.obterBeta()[0])
          
    return GramaticaRegular(producoes, vn, vt, simbolo_inicial)
  
  
  def setarGR(self, gr):
    self._limparTabela()
    
    for nt in gr.obterNaoTerminais():
      nt_inserido = nt      
      if(nt_inserido == gr.obterSimboloInicial()):
        nt_inserido = self._inicial + nt_inserido
        
      linha = self.__adcionarNtTabela(nt_inserido, False)
      for prod in gr.obterProducoesDoAlpha(nt):
        self.__inserirProducao(linha, prod.obterBeta())
        
    self.alinharTabela()
    
    
  def __inserirProducao(self, linha, beta):
    tabela = self._obterTabela()
    if(tabela.columnCount() == 0):
      coluna = 0
      tabela.insertColumn(0)
    else:
      coluna = 0
      criar_coluna = True
      for i in range(tabela.columnCount()):
        if(tabela.item(linha, i) == None):
          coluna = i
          criar_coluna = False
          break
      if(criar_coluna):
        coluna = tabela.columnCount()
        tabela.insertColumn(tabela.columnCount())
        
    if(len(beta) > 1):
      beta = beta[0] + beta[1:].upper()
      
    tabela.setItem(linha, coluna, QtGui.QTableWidgetItem(beta))
        
        
  def __removerMarcadoresDoNT(self, nt):
    if(nt.startswith(self._inicial)):
      nt = nt[len(self._inicial):]
    
    return nt
  
  
  def __removerEstadoTabela(self, nt):
    tabela = self._obterTabela()
    nt = self.__removerMarcadoresDoNT(str(nt))
    
    for i in range(tabela.rowCount()):
      outro_nt = self.__removerMarcadoresDoNT(str(tabela.verticalHeaderItem(i).text()))
        
      if(outro_nt == nt):
        tabela.removeRow(i)
        return
      
      
  def __obterNT(self, linha):
    tabela = self._obterTabela()
    nt = str(tabela.verticalHeaderItem(linha).text())
    
    if(nt.startswith(self._inicial)): 
      eh_inicial = True
    else: 
      eh_inicial = False
      
    nt = self.__removerMarcadoresDoNT(nt)
    producoes = set()
    
    for i in range(tabela.columnCount()):
      if(tabela.item(linha, i) != None):
        beta = str(tabela.item(linha, i).text())
        producoes.add(Producao(nt,beta))
        
    return nt, producoes, eh_inicial
  
  def __possuiNt(self, nt):
    tabela = self._obterTabela()
    linha = tabela.rowCount()
    
    for i in range(linha):
      outro_nt = tabela.verticalHeaderItem(i).text()
      outro_nt2 = self.__removerMarcadoresDoNT(str(outro_nt))
      if((outro_nt == nt) or (outro_nt2 == nt)):
        return True
      
    return False
  
  def __obterLinhaNt(self, nt):
    tabela = self._obterTabela()
    linha = tabela.rowCount()
    
    for i in range(linha):
      outro_nt = tabela.verticalHeaderItem(i).text()
      outro_nt2 = self.__removerMarcadoresDoNT(str(outro_nt))
      if((outro_nt == nt) or (outro_nt2 == nt)):
        return i
      
    return -1
  
  def __adcionarNtTabela(self, nt, verifica_caixa = True):
    tabela = self._obterTabela()
    linha = tabela.rowCount()
    nt = str(nt).upper()

    if(self.__possuiNt(nt)):
      return
      
    if(verifica_caixa):
      if(self.__ui.nt_eh_inicial.isChecked()):
        nt = self._inicial + nt
      
    tabela.insertRow(linha)
    tabela.setVerticalHeaderItem(linha, QtGui.QTableWidgetItem(nt))
    self.alinharTabela()
    
    return linha
  
  
  def _obterTabela(self):
    return self.__ui.tabela_gramatica
      
      
  def clicouTransformarEmAFD(self):
    try:
      self._janela_principal.obterAFGUI().setarAF(util.remover_estados_mortos_afd(util.obter_afd(self.obterGR())))
    
    except Exception as excecao:
      self.mostrarErro(str(excecao))
      
    
  def clicouAdcionarNT(self):
    try:
      nt = self.__ui.nao_terminal.text().toUpper().remove(' ')
      if(nt != ''):
        self.__adcionarNtTabela(nt, True)
         
    except Exception as excecao:
      self.mostrarErro(str(excecao))
      
      
  def clicouAdcionarProducao(self):
    try:
      prod = str(self.__ui.producao.text().remove(' '))
      if(prod == ''):
        return
    
      for separador in self.__separadores:
        prod_aux = prod.split(separador) 
        if(len(prod_aux) == 2):
          alpha = prod_aux[0].upper()
          beta = prod_aux[1]
          if(self.__possuiNt(alpha)):
            self.__inserirProducao(self.__obterLinhaNt(alpha), beta)
          
      self.alinharTabela()
      
    except Exception as excecao:
      self.mostrarErro(str(excecao))
    
        
  def clicouRemoverNT(self):
    try:
      nt = self.__ui.nao_terminal.text().toUpper().remove(' ')
      if(nt != ''):
        self.__removerEstadoTabela(nt)
        
    except Exception as excecao:
      self.mostrarErro(str(excecao))
    
    
  def modificouTransicao(self, linha, coluna):
    trans = self._obterTabela().item(linha, coluna).text()

    trans_ok = self._obterTabela().item(linha, coluna).text().remove(' ')
    trans_ok = trans_ok[0] + trans_ok[1:].toUpper()
    if(trans != trans_ok):
      self._obterTabela().setItem(linha, coluna, QtGui.QTableWidgetItem(trans_ok))
  
  
  def _obterSufixo(self):
    return QtCore.QString('*gr')
  
  
  def _trataSalvar(self, lista):
    try:
      if(lista.isEmpty()):
        return
    
      nome_arquivo = lista.takeLast() + '.' + self._obterSufixo()
      gr = self.obterGR()
      util.salvar(gr, nome_arquivo)
      
    except Exception as excecao:
      self.mostrarErro(str(excecao))
  
  def _trataCarregar(self, lista):
    try:
      if(lista.isEmpty()):
        return
    
      gr = util.carregar(lista.takeLast())
      self.setarGR(gr) 
      
    except Exception as excecao:
      self.mostrarErro(str(excecao))
    
      