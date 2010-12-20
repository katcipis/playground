import math
import funcoes

def obter_alpha(intervalo, funcao, erro_passado = 0.0, limite = 20):

  a = intervalo[0]
  b = intervalo[1]
  fa = funcao(a)
  fb = funcao(b)
  erro = erro_passado * 10.0
  contador = 0
  xm = 0.0
  
  if( (fa * fb) < 0 ):
    
    while(contador < limite):
      contador += 1
      xm = (a + b) / 2.0 
      fm = funcao(xm)
      
      if(fm == 0):
        return xm, 0.0
      
      if( (fm * fa) < 0.0):
        b = xm
      else:
        a = xm
        
      erro = funcoes.calcular_erro(a, b)
 
      if(erro < erro_passado):
        return xm, erro
      
      print 'Iteracao ', contador, ' alpha = ', xm
      
    return xm, erro
      
  else:
    print 'Funcao nao eh continua' 
      
      