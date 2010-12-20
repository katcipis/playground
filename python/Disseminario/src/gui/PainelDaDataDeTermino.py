# -*- coding: latin-1 -*-
import wx
from gui.abstrato.CampoDeDataRotulado import CampoDeDataRotulado

class PainelDaDataDeTermino(CampoDeDataRotulado):
  
  def __init__(self, pai):
    CampoDeDataRotulado.__init__(self, pai)
    self._adcionarEspacamento()
    
  def _obterRotuloInicial(self):
    return 'Data de termino: '

