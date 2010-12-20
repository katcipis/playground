'''
Created on 30/10/2009
@author: katcipis
'''
from gramatica.Producao import Producao
from gramatica.GramaticaRegular import GramaticaRegular
from gramatica.GramaticaLivreContexto import GramaticaLivreContexto
from enum.epsilon import EPSILON
from enum.marcadores import FIM_DE_SENTENCA


def construirGLCComNaoFatoracaoIndireta():
  vn = set(['S', 'A', 'C', 'B'])
  vt = set(['a', 'd', 'b', 'c'])
  s = 'S'
  
  producoes = set()
  producoes.add(Producao('S', 'A B'))
  producoes.add(Producao('S', 'B C'))
  
  producoes.add(Producao('A', 'a A'))
  producoes.add(Producao('A', EPSILON))
  
  producoes.add(Producao('B', 'b B'))
  producoes.add(Producao('B', 'd'))
  
  
  producoes.add(Producao('C', 'c C'))
  producoes.add(Producao('C', 'c'))
    
  return GramaticaLivreContexto(producoes, vn,vt,s)


def construirGLCComNaoFatoracaoIndiretaFatorada():
  vn = set(['S','S1', 'A', 'C', 'C1', 'B'])
  vt = set(['a', 'd', 'b', 'c'])
  s = 'S'
  
  producoes = set()
  producoes.add(Producao('S', 'a A B'))
  producoes.add(Producao('S', 'b B S1'))
  producoes.add(Producao('S', 'd S1'))
  
  producoes.add(Producao('S1', 'C'))
  producoes.add(Producao('S1', EPSILON))
  
  producoes.add(Producao('A', 'a A'))
  producoes.add(Producao('A', EPSILON))
  
  producoes.add(Producao('B', 'b B'))
  producoes.add(Producao('B', 'd'))
  
  
  producoes.add(Producao('C', 'c C1'))
  producoes.add(Producao('C1', 'C'))
  producoes.add(Producao('C1', EPSILON))
    
  return GramaticaLivreContexto(producoes, vn,vt,s)


def construirGLCComNaoFatoracaoDireta():
  vn = set(['S', 'B'])
  vt = set(['a', 'd', 'b'])
  s = 'S'
  
  producoes = set()
  producoes.add(Producao('S', 'a S'))
  producoes.add(Producao('S', 'a B'))
  producoes.add(Producao('S', 'd S'))
  producoes.add(Producao('B', 'b B'))
  producoes.add(Producao('B', 'b'))
    
  return GramaticaLivreContexto(producoes, vn,vt,s)

def construirGLCComNaoFatoracaoDiretaFatorada():
  vn = set(['S', 'B', 'S1', 'B1'])
  vt = set(['a', 'd', 'b'])
  s = 'S'
  
  producoes = set()
  producoes.add(Producao('S', 'a S1'))
  producoes.add(Producao('S', 'd S'))
  producoes.add(Producao('S1', 'S'))
  producoes.add(Producao('S1', 'B'))
  
  producoes.add(Producao('B', 'b B1'))
  producoes.add(Producao('B1', 'B'))
  producoes.add(Producao('B1', EPSILON))
    
  return GramaticaLivreContexto(producoes, vn,vt,s)

def construirTodosFirstDaGLCDoTesteFirst():
  return { 'P' : set(['t', 'v', 'b', 'c', EPSILON]),
           'D' : set(['t', 'v', EPSILON]),
           'T' : set(['t', EPSILON]),
           'V' : set(['v', EPSILON]),
           'C' : set(['b', 'c', EPSILON])
         }

def construirTodosFollowsDaGLCDoTesteFollow():
  return { 'P' : set([FIM_DE_SENTENCA]),
           'D' : set(['b', 'c', FIM_DE_SENTENCA, 'e']),
           'T' : set(['v', 'b', 'c', FIM_DE_SENTENCA, 'e']),
           'V' : set(['b', 'c', 'e', FIM_DE_SENTENCA]),
           'C' : set(['e', FIM_DE_SENTENCA])
         }

def construirGLCTesteFollow():
  return construirGLCTesteFirst()


def construirGLCTesteFirst():
  vn = set(['P', 'D', 'T', 'V', 'C'])
  vt = set(['t', 'v', 'b', 'e', 'c'])
  s = 'P'
  
  producoes = set()
  producoes.add(Producao('P', 'D C'))
  producoes.add(Producao('D', 'T V'))
  producoes.add(Producao('T', 't T'))
  producoes.add(Producao('T', EPSILON))
  producoes.add(Producao('V', 'v V'))
  producoes.add(Producao('V', EPSILON))
  producoes.add(Producao('C', 'b D C e'))
  producoes.add(Producao('C', 'c C'))
  producoes.add(Producao('C', EPSILON))
    
  return GramaticaLivreContexto(producoes, vn,vt,s)
  

def construirGLCComABOndeNumAsEhIgualNumBsComSimbolosInalcancaveis():
  vn = set(['S2', 'S', 'C'])
  vt = set(['a', 'b'])
  s = 'S2'
  
  producoes = set()
  producoes.add(Producao('S2', 'S'))
  producoes.add(Producao('S2', EPSILON))
  producoes.add(Producao('S', 'a S b'))
  producoes.add(Producao('S', 'a b'))
  producoes.add(Producao('C', 'a b'))
  producoes.add(Producao('C', 'S'))
  
  return GramaticaLivreContexto(producoes, vn,vt,s)

def construirGLCComABOndeNumAsEhIgualNumBsComSimbolosMortos():
  vn = set(['S2', 'S', 'D'])
  vt = set(['a', 'b'])
  s = 'S2'
  
  producoes = set()
  producoes.add(Producao('S2', 'S'))
  producoes.add(Producao('S2', EPSILON))
  producoes.add(Producao('S', 'a S b'))
  producoes.add(Producao('S', 'a b'))
  producoes.add(Producao('S', 'a D b'))
  producoes.add(Producao('D', 'a D'))
    
  return GramaticaLivreContexto(producoes, vn,vt,s)

def construirGLCComABOndeNumAsEhIgualNumBsComSimbolosInuteis():
  vn = set(['S2','S', 'D', 'C'])
  vt = set(['a', 'b'])
  s = 'S2'
  
  producoes = set()
  producoes.add(Producao('S2', 'S'))
  producoes.add(Producao('S2', EPSILON))
  producoes.add(Producao('S', 'a S b'))
  producoes.add(Producao('S', 'a b'))
  producoes.add(Producao('S', 'a D b'))
  producoes.add(Producao('D', 'a D'))
  producoes.add(Producao('C', 'a b'))
  producoes.add(Producao('C', 'S'))
    
  return GramaticaLivreContexto(producoes, vn,vt,s)

def construirGLCComABOndeNumAsEhIgualNumBsSemSimbolosInuteis():
  vn = set(['S2', 'S'])
  vt = set(['a', 'b'])
  s = 'S2'
  
  producoes = set()
  producoes.add(Producao('S2', 'S'))
  producoes.add(Producao('S2', EPSILON))
  producoes.add(Producao('S', 'a S b'))
  producoes.add(Producao('S', 'a b'))
    
  return GramaticaLivreContexto(producoes, vn,vt,s)

def construirGLCComCiclo():
  vn = set(['S2', 'S', 'A', 'B', 'C'])
  vt = set(['a', 'b'])
  s = 'S2'
  
  producoes = set()
  producoes.add(Producao('S2', 'S'))
  producoes.add(Producao('S2', EPSILON))
  
  producoes.add(Producao('S', 'a S b'))
  producoes.add(Producao('S', 'a b'))
  producoes.add(Producao('S', 'A'))
  
  producoes.add(Producao('A', 'B'))
  producoes.add(Producao('A', 'C'))
  producoes.add(Producao('A', 'a A'))
  producoes.add(Producao('A', 'a'))
  
  producoes.add(Producao('B', 'S'))
  producoes.add(Producao('B', 'b B'))
  producoes.add(Producao('B', 'b'))
  
  producoes.add(Producao('C', 'a'))
  
  
  return GramaticaLivreContexto(producoes, vn,vt,s)

def construirGLCSemCiclo():
  vn = set(['S2', 'S', 'A', 'B', 'C'])
  vt = set(['a', 'b'])
  s = 'S2'
  
  producoes = set()
  producoes.add(Producao('S2', 'S'))
  producoes.add(Producao('S2', EPSILON))
  producoes.add(Producao('S', 'a S b'))
  producoes.add(Producao('S', 'a b'))
  
  producoes.add(Producao('S', 'a A'))
  producoes.add(Producao('S', 'a'))
  producoes.add(Producao('S', 'C'))
  producoes.add(Producao('S', 'b B'))
  producoes.add(Producao('S', 'b'))
  
  producoes.add(Producao('A', 'B'))
  producoes.add(Producao('A', 'C'))
  producoes.add(Producao('A', 'a A'))
  producoes.add(Producao('A', 'a'))
  
  producoes.add(Producao('B', 'S'))
  producoes.add(Producao('B', 'b B'))
  producoes.add(Producao('B', 'b'))
  
  producoes.add(Producao('C', 'a'))
  
  return GramaticaLivreContexto(producoes, vn,vt,s)


def construirGLCComABOndeNumAsEhIgualNumBsEpsilonLivre():
  vn = set(['S1', 'S'])
  vt = set(['a', 'b'])
  s = 'S1'
  
  producoes = set()
  producoes.add(Producao('S1', 'S'))
  producoes.add(Producao('S1', EPSILON))
  producoes.add(Producao('S', 'a S b'))
  producoes.add(Producao('S', 'a b'))
    
  return GramaticaLivreContexto(producoes, vn,vt,s)


def construirGLCComABOndeNumAsEhIgualNumBsComEpsilon():
  vn = set(['S'])
  vt = set(['a', 'b'])
  s = 'S'
  
  producoes = set()
  producoes.add(Producao('S', 'a S b'))
  producoes.add(Producao('S', EPSILON))
    
  return GramaticaLivreContexto(producoes, vn,vt,s)

def construirGLCQueNaoProduzEpsilon():
  vn = set(['S'])
  vt = set(['a', 'b'])
  s = 'S'
  
  producoes = set()
  producoes.add(Producao('S', 'a S b'))
  producoes.add(Producao('S', 'a b'))
  
  return GramaticaLivreContexto(producoes, vn,vt,s)

def construirGLCExpAritmeticaComRecEsquerdaDireta():
  vn = set(['E', 'T', 'F'])
  vt = set(['+', '*' , 'i', '(', ')'])
  s = 'E'
  
  producoes = set()
  producoes.add(Producao('E', 'E + T'))
  producoes.add(Producao('E', 'T'))
  producoes.add(Producao('T', 'T * F'))
  producoes.add(Producao('T', 'F'))
  producoes.add(Producao('F', '( E )'))
  producoes.add(Producao('F', 'i'))
  
  return GramaticaLivreContexto(producoes, vn,vt,s)
  
  
def construirGLCComRecEsquerdaIndireta():
  vn = set(['S', 'A'])
  vt = set(['a','c', 'd'])
  s = 'S'
  
  producoes = set()
  producoes.add(Producao('S', 'A a'))
  producoes.add(Producao('A', 'S c'))
  producoes.add(Producao('A', 'd'))
  
  return GramaticaLivreContexto(producoes, vn,vt,s)
  
def construirGLCExpAritmeticaSemRecEsquerda():
  vn = set(['E', 'T', 'F', 'E1', 'T1'])
  vt = set(['+', '*' , 'i', '(', ')'])
  s = 'E'
  
  producoes = set()
  producoes.add(Producao('E', 'T E1'))
  producoes.add(Producao('E1', '+ T E1'))
  producoes.add(Producao('E1', EPSILON))
  producoes.add(Producao('T', 'F T1'))
  producoes.add(Producao('T1', '* F T1'))
  producoes.add(Producao('T1', EPSILON))
  producoes.add(Producao('F', '( E )'))
  producoes.add(Producao('F', 'i'))
  
  return GramaticaLivreContexto(producoes, vn,vt,s)

def construirGRComABOndeAsEhPar():
  vn = set(['S', 'A', 'B'])
  vt = set(['a', 'b'])
  s = 'S'
  
  producoes = set()
  producoes.add(Producao('S', 'bA'))
  producoes.add(Producao('S', 'b'))
  producoes.add(Producao('S', 'aB'))
  producoes.add(Producao('S', EPSILON))
  
  producoes.add(Producao('A', 'bA'))
  producoes.add(Producao('A', 'b'))
  producoes.add(Producao('A', 'aB'))
  
  producoes.add(Producao('B', 'bB'))
  producoes.add(Producao('B', 'a'))
  producoes.add(Producao('B', 'aA'))
    
  return GramaticaRegular(producoes, vn,vt,s)
