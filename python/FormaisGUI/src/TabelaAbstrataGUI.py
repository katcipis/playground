'''
Created on 06/11/2009
@author: katcipis
'''
from PyQt4 import QtGui, QtCore

class TabelaAbstrataGUI(object):
  '''
  Abstracao que define algumas operacoes nas tabelas de automato e gramatica.
  '''

  def __init__(self, janela_principal):
    self._inicial = '->'
    self._janela_principal = janela_principal
    self._error = QtGui.QErrorMessage(janela_principal)
    self._error.setWindowTitle('Erro')

  def _obterTabela(self):
    '''
    Metodo puramente virtual, deve retornar uma instancia de tabela.
    Nao eh para uso publico
    '''
    
  def alinharTabela(self):
    tabela = self._obterTabela()
    tabela.resizeRowsToContents()
    tabela.resizeColumnsToContents()
    
  def _limparTabela(self):
    tabela = self._obterTabela()
    colunas = range(tabela.columnCount())
    linhas =  range(tabela.rowCount())
    colunas.reverse()
    linhas.reverse()
    
    for i in linhas:
      tabela.removeRow(i)
      
    for i in colunas:
      tabela.removeColumn(i)
    
    
  def _removerSimboloTabela(self, simbolo):
    tabela = self._obterTabela()
    
    for i in range(tabela.columnCount()):
      outro_simbolo = tabela.horizontalHeaderItem(i).text ()
      if(outro_simbolo == simbolo):
        tabela.removeColumn(i)
        return
      
      
  def clicouCarregar(self):
    dialogo = QtGui.QFileDialog(self._janela_principal)
    dialogo.setNameFilter(self._obterSufixo())
    dialogo.setFileMode(QtGui.QFileDialog.ExistingFile)
    dialogo.show() 
    dialogo.connect(dialogo, QtCore.SIGNAL('filesSelected(const QStringList &)'), self._trataCarregar)
    
    
  def clicouSalvar(self):
    dialogo = QtGui.QFileDialog(self._janela_principal)
    dialogo.setNameFilter(self._obterSufixo())
    dialogo.setFileMode(QtGui.QFileDialog.AnyFile)
    dialogo.setAcceptMode(QtGui.QFileDialog.AcceptSave)
    dialogo.show() 
    dialogo.connect(dialogo, QtCore.SIGNAL('filesSelected(const QStringList &)'), self._trataSalvar)
      
    
  def _adcionarSimboloTabela(self, simbolo):
    tabela = self._obterTabela()
    coluna = tabela.columnCount()
    
    for i in range(coluna):
      outro_simbolo = tabela.horizontalHeaderItem(i).text ()
      if(outro_simbolo == simbolo):
        return
      
    tabela.insertColumn(coluna)
    tabela.setHorizontalHeaderItem(coluna, QtGui.QTableWidgetItem(simbolo))
    tabela.resizeColumnsToContents()
    return coluna
  
  def mostrarErro(self, erro):
    self._error.showMessage(erro)
  
  def _trataSalvar(self, lista):
    '''
    Metodo virtual, deve ser implementado pela subclasse.
    '''
  
  def _trataCarregar(self, lista):
    '''
    Metodo virtual, deve ser implementado pela subclasse.
    '''  
        