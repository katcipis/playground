'''
Created on 07/10/2009
@author: katcipis

Colecao de construcoes de automatos para ser utilizado em diversos testes do sistema.
'''

from automato_finito.AutomatoFinito import AutomatoFinito
from automato_finito.Estado import Estado
from automato_finito.Transicao import Transicao

def construirAFDQueGeraEpsilon():
  estados = set()
  estados.add(Estado('EPSILON', set(), True, True))
  alfabeto = set()
  return AutomatoFinito(alfabeto, estados)

def construirAFDQueGeraOSimboloA():
  estados = set()
  estados.add(Estado('q0', set([Transicao('a', 'q1')]), True, False))
  estados.add(Estado('q1', set(), False, True))
  alfabeto = set(['a'])
  return AutomatoFinito(alfabeto, estados)
  
def construirEquivalenteDoAFDComABOndeAsEhPar():
  estados = set()
  estados.add(Estado('q0', set([Transicao('b', 'q0'),  Transicao('a', 'q1')]), True, True))
  estados.add(Estado('q1', set([Transicao('a', 'q0'),  Transicao('b', 'q1')]), False, False))
  alfabeto = set(['a', 'b'])
  return AutomatoFinito(alfabeto, estados)

def construirComplementoDoAFDComABOndeAsEhPar():
  estados = set()
  estados.add(Estado('q0', set([Transicao('b', 'q0'),  Transicao('a', 'q1')]), True, False))
  estados.add(Estado('q1', set([Transicao('a', 'q0'),  Transicao('b', 'q1')]), False, True))
  alfabeto = set(['a', 'b'])
  return AutomatoFinito(alfabeto, estados)

def construirAFDComABOndeAsEhPar():
  estados = set()
  estados.add(Estado('q0', set([Transicao('b', 'q0'),  Transicao('a', 'q1')]), True, True))
  estados.add(Estado('q1', set([Transicao('a', 'q0'),  Transicao('b', 'q1')]), False, False))
  alfabeto = set(['a', 'b'])
  return AutomatoFinito(alfabeto, estados)

def construirAFDComABOndeBsEhImpar():
  estados = set()
  estados.add(Estado('q0', set([Transicao('a', 'q0'),  Transicao('b', 'q1')]), True, False))
  estados.add(Estado('q1', set([Transicao('a', 'q1'),  Transicao('b', 'q0')]), False, True))
  alfabeto = set(['a', 'b'])
  return AutomatoFinito(alfabeto, estados)

def construirAFDNaoMinimo():
  estados = set()
  estados.add(Estado('A', set([Transicao('a', 'G'),  Transicao('b', 'B')]), True, True))
  estados.add(Estado('B', set([Transicao('a', 'F'),  Transicao('b', 'E')]), False, False))
  estados.add(Estado('C', set([Transicao('a', 'C'),  Transicao('b', 'G')]), False, False))
  estados.add(Estado('D', set([Transicao('a', 'A'),  Transicao('b', 'H')]), False, True))
  estados.add(Estado('E', set([Transicao('a', 'E'),  Transicao('b', 'A')]), False, False))
  estados.add(Estado('F', set([Transicao('a', 'B'),  Transicao('b', 'C')]), False, False))
  estados.add(Estado('G', set([Transicao('a', 'G'),  Transicao('b', 'F')]), False, True))
  estados.add(Estado('H', set([Transicao('a', 'H'),  Transicao('b', 'D')]), False, False))
  alfabeto = set(['a', 'b'])
  return AutomatoFinito(alfabeto, estados)
  
def construirAFDMinimo():
  estados = set()
  estados.add(Estado('q0', set([Transicao('a', 'q0'),  Transicao('b', 'q1')]), True, True))
  estados.add(Estado('q1', set([Transicao('a', 'q1'),  Transicao('b', 'q2')]), False, False))
  estados.add(Estado('q2', set([Transicao('a', 'q2'),  Transicao('b', 'q0')]), False, False))
  alfabeto = set(['a', 'b'])
  return AutomatoFinito(alfabeto, estados)

def construirAFDComCincoEstadosETresClassesDeEquivalencia():
  estados = set()
  estados.add(Estado('q0', set([Transicao('0', 'q1'), Transicao('1', 'q2')]), True, False))
  estados.add(Estado('q1', set([Transicao('0', 'q3'), Transicao('1', 'q3')]), False, False))
  estados.add(Estado('q2', set([Transicao('0', 'q4'), Transicao('1', 'q4')]), False, False))
  estados.add(Estado('q3', set([Transicao('0', 'q4'), Transicao('1', 'q4')]), False, True))
  estados.add(Estado('q4', set([Transicao('0', 'q3'), Transicao('1', 'q3')]), False, True))
  alfabeto = set(['0', '1'])
  
  conjunto_um = set([Estado('q0', set([Transicao('0', 'q1'), Transicao('1', 'q2')]), True, False)])
                            
  conjunto_dois = set([Estado('q1', set([Transicao('0', 'q3'), Transicao('1', 'q3')]), False, False), 
                      Estado('q2', set([Transicao('0', 'q4'), Transicao('1', 'q4')]), False, False)])
  conjunto_tres = set([Estado('q3', set([Transicao('0', 'q4'), Transicao('1', 'q4')]), False, True),
                       Estado('q4', set([Transicao('0', 'q3'), Transicao('1', 'q3')]), False, True)])
  
  return [conjunto_um, conjunto_dois, conjunto_tres], AutomatoFinito(alfabeto, estados)

def construirAFND():
  estados = set()
  estados.add(Estado('q0', set([Transicao('a', 'q1'), Transicao('a', 'q0'), Transicao('b', 'q0')]), True, False))
  estados.add(Estado('q1', set([Transicao('b', 'q2')]), False, False))
  estados.add(Estado('q2', set([Transicao('b', 'q3')]), False, False))
  estados.add(Estado('q3', set(), False, True))
  alfabeto = set(['a', 'b'])
  return AutomatoFinito(alfabeto, estados)
  
def construirAFDComUmEstadoInalcancavel():
  alfabeto = set(['a'])
  estados = set()
  estados.add(Estado('q0', set([Transicao('a', 'q1')]), True, True))
  estados.add(Estado('q1', set([Transicao('a', 'q0')]), False, False))
  estados.add(Estado('q2', set([Transicao('a', 'q1')]), False, False))
  return AutomatoFinito(alfabeto, estados)
  
def construirAFDCompleto():
  alfabeto = set(['a', 'b'])
  estados = set()
  estados.add(Estado('q0', set([Transicao('a', 'q1'), Transicao('b', 'q0')]), True, True))
  estados.add(Estado('q1', set([Transicao('a', 'q0'), Transicao('b', 'q2')]), False, False))
  estados.add(Estado('q2', set([Transicao('a', 'q1'), Transicao('b', 'q2')]), False, False))
  return AutomatoFinito(alfabeto, estados)
  
def construirAFDComUmEstadoMorto():
  alfabeto = set(['a', 'b'])
  estados = set()
  estados.add(Estado('q0', set([Transicao('a', 'q1')]), True, True))
  estados.add(Estado('q1', set([Transicao('a', 'q0'), Transicao('b', 'q2')]), False, False))
  estados.add(Estado('q2', set([Transicao('a', 'q2'), Transicao('b', 'q2')]), False, False))
  return AutomatoFinito(alfabeto, estados)
  
def construirAFDSemEstadosMortosOuInalcancaveis():
  alfabeto = set(['a', 'b'])
  estados = set()
  estados.add(Estado('q0', set([Transicao('a', 'q1')]), True, True))
  estados.add(Estado('q1', set([Transicao('a', 'q0'), Transicao('b', 'q2')]), False, False))
  estados.add(Estado('q2', set([Transicao('a', 'q2'), Transicao('b', 'q1')]), False, False))
  return AutomatoFinito(alfabeto, estados)
  
def construirAFDImcompleto():
  alfabeto = set(['a', 'b'])
  estados = set()
  estados.add(Estado('q0', set([Transicao('a', 'q1')]), True, True))
  estados.add(Estado('q1', set([Transicao('a', 'q0'), Transicao('b', 'q2')]), False, False))
  estados.add(Estado('q2', set([Transicao('b', 'q1')]), False, False))
  return AutomatoFinito(alfabeto, estados)
