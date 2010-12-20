'''
Created on 04/11/2009
@author: katcipis
'''
from PyQt4 import QtCore, QtGui
from automato_finito.AutomatoFinito import AutomatoFinito
from automato_finito.Estado import Estado
from automato_finito.Transicao import Transicao
from TabelaAbstrataGUI import TabelaAbstrataGUI
from util import util

class AutomatoFinitoGUI(TabelaAbstrataGUI):
  '''
  Defina classe que controla a GUI do automato finito.
  '''

  def __init__(self, ui, janela_principal):
    '''
    Construtor
    @param ui: a gui carregada na memoria.
    @param janela_principal: janela principal.
    '''
    TabelaAbstrataGUI.__init__(self, janela_principal)
    self.__ui = ui
    
    self.__final = '*'
    self.__separadores_estados = [',', ';']
    
    self._janela_principal.connect(self.__ui.reconhecer_palavra_automato, QtCore.SIGNAL("clicked()"), self.clicouReconhecerPalavra)
    self._janela_principal.connect(self.__ui.adcionar_simbolo_automato, QtCore.SIGNAL("clicked()"), self.clicouAdcionarSimbolo)
    self._janela_principal.connect(self.__ui.remover_simbolo_automato, QtCore.SIGNAL("clicked()"), self.clicouRemoverSimbolo)
    self._janela_principal.connect(self.__ui.adcionar_estado, QtCore.SIGNAL("clicked()"), self.clicouAdcionarEstado)
    self._janela_principal.connect(self.__ui.remover_estado, QtCore.SIGNAL("clicked()"), self.clicouRemoverEstado)
    self._janela_principal.connect(self.__ui.determinizar, QtCore.SIGNAL("clicked()"), self.clicouDeterminizar)
    self._janela_principal.connect(self.__ui.minimizar, QtCore.SIGNAL("clicked()"), self.clicouMinimizar)
    self._janela_principal.connect(self.__ui.salvar_automato, QtCore.SIGNAL("clicked()"), self.clicouSalvar)
    self._janela_principal.connect(self.__ui.carregar_automato, QtCore.SIGNAL("clicked()"), self.clicouCarregar)
    self._janela_principal.connect(self.__ui.automato_em_gramatica, QtCore.SIGNAL("clicked()"), self.clicouTransformarGR)
    self._janela_principal.connect(self.__ui.remover_inalc_automato, QtCore.SIGNAL("clicked()"), self.clicouRemoverInalc)
    self._janela_principal.connect(self.__ui.remover_mortos_automato, QtCore.SIGNAL("clicked()"), self.clicouRemoverMortos)
    self._janela_principal.connect(self.__ui.limpar_automato, QtCore.SIGNAL("clicked()"), self._limparTabela)
    self._janela_principal.connect(self._obterTabela(), QtCore.SIGNAL("cellChanged(int,int)"), self.modificouTransicao)
    
 
  def _obterTabela(self):
    return self.__ui.tabela_automato
  
  
  def obterAF(self):
    tabela = self.__ui.tabela_automato
    alfabeto = set()
    estados = set()
    for i in range(tabela.columnCount()):
      alfabeto.add(str(tabela.horizontalHeaderItem(i).text()))
      
    for i in range(tabela.rowCount()):
      estados.add(self.__obterEstado(i))
      
    return AutomatoFinito(alfabeto, estados)
    
    
  def setarAF(self, automato):
    self._limparTabela()
    coluna_simbolo = {}
    tabela = self.__ui.tabela_automato
    
    for simbolo in automato.obterAlfabeto():
      coluna = self._adcionarSimboloTabela(simbolo)
      coluna_simbolo[simbolo] = coluna
      
    for estado in automato.obterEstados():
      nome = estado.obterNome().upper()
      
      if(estado.ehInicial()):
        nome = self._inicial + nome
      if(estado.ehFinal()):
        nome = self.__final + nome
        
      linha = self.__adcionarEstadoTabela(nome, False)
      transicoes = estado.obterTransicoes()
      for transicao in transicoes:
        simbolo = transicao.obterSimbolo()
        estado_destino = transicao.obterNomeEstadoDestino().upper()
        
        if(tabela.item(linha, coluna_simbolo[simbolo]) != None):
          estado_na_tabela = tabela.item(linha, coluna_simbolo[simbolo]).text()
          if(estado_na_tabela != ''):
            estado_destino += self.__separadores_estados[0] + estado_na_tabela
          
        tabela.setItem(linha, coluna_simbolo[simbolo], QtGui.QTableWidgetItem(estado_destino))
    
    self.alinharTabela()    
        
        
  def __obterEstado(self, linha):
    tabela = self.__ui.tabela_automato
    eh_final = False
    eh_inicial = False
    nome = str(tabela.verticalHeaderItem(linha).text())
    transicoes = set()
    
    if(nome.startswith(self.__final + self._inicial)):
      eh_final = True
      eh_inicial = True
    elif(nome.startswith(self.__final)):
      eh_final = True
    elif(nome.startswith(self._inicial)):
      eh_inicial = True
    
    nome = self.__removerMarcadoresDoEstado(nome)
    
    for i in range(tabela.columnCount()):
      simbolo = str(tabela.horizontalHeaderItem(i).text())
      estados = []
      if(tabela.item(linha, i) != None):
        trans_str =str(tabela.item(linha, i).text())
      
        for separador in self.__separadores_estados:
          if(trans_str.find(separador) != -1):
            estados.extend(trans_str.split(separador))
          
        if(estados == []):
          estados.append(trans_str)
        
        for estado in estados:
          transicoes.add(Transicao(simbolo, estado))
      
    return Estado(nome, transicoes, eh_inicial, eh_final)  
    
    
  def __adcionarEstadoTabela(self, estado, verifica_caixa = True):
    tabela = self._obterTabela()
    linha = tabela.rowCount()
    
    for i in range(linha):
      outro_estado = tabela.verticalHeaderItem(i).text()
      outro_estado2 = self.__removerMarcadoresDoEstado(str(outro_estado))
      if((outro_estado == estado) or (outro_estado2 == estado)):
        return
    
    if(verifica_caixa):
      if(self.__ui.estado_eh_inicial.isChecked()):
        estado = self._inicial + estado
      
      if(self.__ui.estado_eh_final.isChecked()):
        estado = self.__final + estado
    
    tabela.insertRow(linha)
    tabela.setVerticalHeaderItem(linha, QtGui.QTableWidgetItem(estado))
    self.alinharTabela()
    
    return linha
  
  
  def __removerMarcadoresDoEstado(self, nome_estado):
    if(nome_estado.startswith(self.__final + self._inicial)):
      nome_estado = nome_estado[len(self.__final + self._inicial):]
    elif(nome_estado.startswith(self.__final)):
      nome_estado = nome_estado[len(self.__final):]
    elif(nome_estado.startswith(self._inicial)):
      nome_estado = nome_estado[len(self._inicial):]
    
    return nome_estado
  
  
  def __removerEstadoTabela(self, nome_estado):
    tabela = self.__ui.tabela_automato
    nome_estado = self.__removerMarcadoresDoEstado(str(nome_estado))
    
    for i in range(tabela.rowCount()):
      nome_outro_estado = self.__removerMarcadoresDoEstado(str(tabela.verticalHeaderItem(i).text()))
        
      if(nome_outro_estado == nome_estado):
        tabela.removeRow(i)
        return
    
      
  def clicouAdcionarSimbolo(self):
    try:  
      simbolo = self.__ui.simbolo_automato.text().remove(' ')
      if(simbolo != '' and (len(simbolo) == 1)):
        self._adcionarSimboloTabela(simbolo)
        
    except Exception as excecao:
      self.mostrarErro(str(excecao))
  
  
  def clicouAdcionarEstado(self):
    try:
      estado = self.__ui.estado_automato.text().toUpper().remove(' ')
      if(estado != ''):
        self.__adcionarEstadoTabela(estado)
         
    except Exception as excecao:
      self.mostrarErro(str(excecao))
  
  
  def clicouMinimizar(self):
    try:
      af = self.obterAF()
      afd = util.determinizar_af(af)
      self.setarAF(util.minimizar_afd(afd))
      
    except Exception as excecao:
      self.mostrarErro(str(excecao))
  
  def clicouDeterminizar(self):
    try:
      af = self.obterAF()
      self.setarAF(util.determinizar_af(af))
    except Exception as excecao:
      self.mostrarErro(str(excecao))
      
  
  def clicouRemoverInalc(self):
    try:
      af = self.obterAF()
      self.setarAF(util.remover_estados_inalcancaveis_afd(af))
    except Exception as excecao:
      self.mostrarErro(str(excecao))
  
  
  def clicouRemoverMortos(self):
    try:
      af = self.obterAF()
      self.setarAF(util.remover_estados_mortos_afd(af))
    except Exception as excecao:
      self.mostrarErro(str(excecao))
  
  
  def clicouRemoverEstado(self):
    try:
      estado = self.__ui.estado_automato.text().toUpper().remove(' ')
      if(estado != ''):
        self.__removerEstadoTabela(estado)
    except Exception as excecao:
      self.mostrarErro(str(excecao))
      
      
  def clicouRemoverSimbolo(self):
    try:
      simbolo = self.__ui.simbolo_automato.text().remove(' ')
      if(simbolo != ''):
        self._removerSimboloTabela(simbolo)
    except Exception as excecao:
      self.mostrarErro(str(excecao))
      
      
  def clicouReconhecerPalavra(self):
    try:
      palavra = self.__ui.palavra_automato.text().remove(' ')
      af = self.obterAF()
      if(af.reconhecePalavra(palavra)):
        self.__ui.reconheceu_palavra.setText('OK')
      else:
        self.__ui.reconheceu_palavra.setText('NOK')
        
    except Exception as excecao:
      self.mostrarErro(str(excecao))
      
  
  def clicouTransformarGR(self):
    try:
      af = self.obterAF()
      af = util.determinizar_af(af)
      self._janela_principal.obterGRGUI().setarGR(util.obter_gramatica_regular(af)) 
    except Exception as excecao:
      self.mostrarErro(str(excecao))
  
  
  def modificouTransicao(self, linha, coluna):
    trans = self._obterTabela().item(linha, coluna).text()
    trans_ok = self._obterTabela().item(linha, coluna).text().toUpper().remove(' ')
    if(trans != trans_ok):
      self._obterTabela().setItem(linha, coluna, QtGui.QTableWidgetItem(trans_ok))

      
  def _obterSufixo(self):
    return QtCore.QString('*af')
  
  
  def _trataSalvar(self, lista):
    try:
      if(lista.isEmpty()):
        return
    
      nome_arquivo = lista.takeLast() + '.' + self._obterSufixo()
      af = self.obterAF()
      util.salvar(af, nome_arquivo)
      
    except Exception as excecao:
      self.mostrarErro(str(excecao))
  
  
  def _trataCarregar(self, lista):
    try:
      if(lista.isEmpty()):
        return
    
      af = util.carregar(lista.takeLast())
      self.setarAF(af)
      
    except Exception as excecao:
      self.mostrarErro(str(excecao))     
  
  