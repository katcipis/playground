'''
Created on 23/10/2009
@author: katcipis
'''
from util import util
from enum.epsilon import EPSILON

class ErroConstruindoER(Exception):
  def __init__(self, msg_erro):
    self.__erro = msg_erro

  def __str__(self):
    return 'Erro construindo expressao regular: ' + str(self.__erro)
 
class ErroConstruindoAFD(Exception):
  def __init__(self, msg_erro):
    self.__erro = msg_erro

  def __str__(self):
    return 'Erro construindo afd a partir da expressao regular: ' + str(self.__erro)
  
class ExpressaoRegular():
  '''
  Classe que define uma expressao regular.
  '''
  operadorOU = '|'
  operadorE  = '.'
  operadorFechamentoReflexivo = '*'
  operadorFechamentoPositivo  = '+'
  operadorInterrogacao = '?'
  operadores = set([operadorOU, operadorE, operadorFechamentoReflexivo, operadorFechamentoPositivo, operadorInterrogacao])
  operadores_unarios = set([operadorFechamentoReflexivo, operadorInterrogacao, operadorFechamentoPositivo])
  
  def __init__(self, exp_reg):
    '''
    Construtor
    @param exp_reg: Expressao regular (string)
    '''
    if(self.__ehOperador(exp_reg[0])):
      raise ErroConstruindoER('Inicia com o operador [{0}]'.format(exp_reg[0]))
    
    self.__verificaSeTerminaComOperadorInvalido(exp_reg)
    self.__verificaOperadoresRepetidos(exp_reg)
    self.__verificaParentesis(exp_reg)
    
    self.__exp_reg = exp_reg.replace(' ', '')#Removendo espacos vazios
    
  def __str__(self):
    return self.__exp_reg
  
  def __ehOperador(self, simbolo):
    return simbolo in ExpressaoRegular.operadores
  
  def __ehOperadorUnario(self, simbolo):
    return simbolo in ExpressaoRegular.operadores_unarios
  
  def __verificaParentesis(self, exp_reg):
    if(exp_reg == ''):
      return True
    
    if(exp_reg[0] == ')'):
      raise ErroConstruindoER('Expressao mal formada!')
    
    if(exp_reg[0] == '('):
      if(exp_reg[1] == ')'):
        raise ErroConstruindoER('Expressao mal formada, possui () !')
      
      i = self.__obterIndiceDoEncerramentoDoPrimeiroParentesis(exp_reg)
      if(i == None):
        raise ErroConstruindoER('Expressao mal formada!')
      
      sub = exp_reg[1:i]      #De depois do ( ateh antes do )
      exp_reg = exp_reg[i+1:] #De depois do ) ate o final da string.
      return self.__verificaParentesis(sub) and self.__verificaParentesis(exp_reg)
    
    return self.__verificaParentesis(exp_reg[1:])
    
    
  def __verificaSeTerminaComOperadorInvalido(self, exp_reg):
    if(self.__ehOperador(exp_reg[-1])):
      if(exp_reg[-1] == ExpressaoRegular.operadorOU or
         exp_reg[-1] == ExpressaoRegular.operadorE):
        raise ErroConstruindoER('Termina com o operador [{0}]'.format(exp_reg[-1]))
    
    
  def __verificaOperadoresRepetidos(self, exp_reg):
    for i in range(len(exp_reg)-1):
      if(self.__ehOperador(exp_reg[i]) and self.__ehOperador(exp_reg[i + 1])):
        if(not self.__ehOperadorUnario(exp_reg[i])):
          msg = 'Possui dois operadores consecutivos, operador[{0}] e operador[{1}]'
          msg = msg.format(exp_reg[i], exp_reg[i+1])
          raise ErroConstruindoER(msg)
        elif(self.__ehOperadorUnario(exp_reg[i+1])):  
          msg = 'Possui dois operadores consecutivos, operador[{0}] e operador[{1}]'
          msg = msg.format(exp_reg[i], exp_reg[i+1])
          raise ErroConstruindoER(msg)
         
          
  def __obterIndiceDoEncerramentoDoPrimeiroParentesis(self, exp_reg):
    contador = 0

    for i in range(len(exp_reg)):
      if(exp_reg[i] == '('):
        contador += 1
      if(exp_reg[i] == ')'):
        contador -= 1
        if(contador == 0):
          return i
        
    return None
  
  def __constroi_automato(self, exp_reg):
    if(self.__ehOperador(exp_reg[0])):
      msg = 'Expressao mal formada, esperando um simbolo mas encontrou um operador[{0}]'
      msg = msg.format(exp_reg[0])
      raise ErroConstruindoAFD(msg)
    
    if(exp_reg[0] == ')'):
      msg = 'Expressao mal formada, esperando um simbolo mas encontrou )'
      raise ErroConstruindoAFD(msg)
          
    if(exp_reg[0] == '('):
      i = self.__obterIndiceDoEncerramentoDoPrimeiroParentesis(exp_reg)
      sub = exp_reg[1:i]      #De depois do ( ateh antes do )
      exp_reg = exp_reg[i+1:] #De depois do ) ate o final da string.
      automato = self.__constroi_automato(sub)
      if(exp_reg == ''):
        return automato
    else:
      if(exp_reg[0] == EPSILON):
        automato = util.gerar_automato_finito_epsilon()
      else:
        automato = util.gerar_automato_finito(exp_reg[0])
      exp_reg = exp_reg[1:]
      if(exp_reg == ''):
        return automato
    
    if(exp_reg[0] == ExpressaoRegular.operadorFechamentoReflexivo):
      automato = util.obter_fechamento_reflexivo_af(automato)
      exp_reg = exp_reg[1:]
      if(exp_reg == ''):
        return automato
      
    if(exp_reg[0] == ExpressaoRegular.operadorFechamentoPositivo):
      automato = util.obter_fechamento_positivo_af(automato)
      exp_reg = exp_reg[1:]
      if(exp_reg == ''):
        return automato
      
    if(exp_reg[0] == ExpressaoRegular.operadorInterrogacao):
      epsilon = util.gerar_automato_finito_epsilon()
      automato = util.unir_af(automato, epsilon)
      exp_reg = exp_reg[1:]
      if(exp_reg == ''):
        return automato
      
    if(exp_reg[0] == ExpressaoRegular.operadorOU):
      return util.unir_af(automato, self.__constroi_automato(exp_reg[1:]))
    
    if(exp_reg[0] == ExpressaoRegular.operadorE):
      return util.concatenar_af(automato, self.__constroi_automato(exp_reg[1:]))

    return util.concatenar_af(automato, self.__constroi_automato(exp_reg))
   
        
  def obterAFD(self):
    automato = self.__constroi_automato(self.__exp_reg)
    automato = util.determinizar_af(automato)
    automato = util.minimizar_afd(automato)
    return automato    