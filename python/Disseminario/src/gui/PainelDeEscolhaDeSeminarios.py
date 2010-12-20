# -*- coding: latin-1 -*-
import wx
from gui.abstrato.CaixaMultiplaEscolhaRotulada import CaixaMultiplaEscolhaRotulada
from gui.DialogoDeMensagem import DialogoDeMensagem

class PainelDeEscolhaDeSeminarios(CaixaMultiplaEscolhaRotulada):
  
  def __init__(self, pai):
    CaixaMultiplaEscolhaRotulada.__init__(self, pai)
    self._adcionarEspacamento()
    
  def _obterEscolhas(self):
    return ['Seminário 1', 'Seminário 2']
    
  def _obterRotuloInicial(self):
    return 'Seminário: '
    
  def _trataCliqueNaCaixa(self, evento):
    dialogo = DialogoDeMensagem(self, 'Clique ocorrido', 'clicou ' + self.obterOpcaoSelecionada())
    dialogo.ShowModal()
    dialogo.Destroy()
