# -*- coding: utf-8 -*-
'''
Created on 10/04/2009
@author: katcipis
'''
from abstrato.Endereco import Endereco

class EnderecoVO(Endereco):
 
  def __eq__(self, outro):
    if(not isinstance(outro, EnderecoVO)):
      return False
    
    caseUm = self.obterComplemento() == outro.obterComplemento()
    caseDois = self.obterNumero() == outro.obterNumero()
    caseTres = self.obterRua() == outro.obterRua()
    
    return caseUm and caseDois and caseTres
  
  def __neq__(self, outro):
    return not self.__eq__(outro)
  
