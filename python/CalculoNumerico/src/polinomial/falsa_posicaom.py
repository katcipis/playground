import horner
import math

def obter_alpha(intervalo, grau, coeficientes , limite = 20, erro_passado = 10 ** -16):

  a = intervalo[0]
  b = intervalo[1]
  erro = erro_passado * 10.0
  contador = 0
  xm = 0.0
  
  fa = horner.obter_resto(grau, coeficientes, a)
  fb = horner.obter_resto(grau, coeficientes, b)
  aux = fa  
  
  if((fa * fb) < 0):
    
    while(contador < limite):
      contador += 1
      
      tmp = (fa * (b - a))
      aux = fb -fa
      
      xm = (a) - (tmp / aux) 
      fm = horner.obter_resto(grau, coeficientes, xm)
      
      if(fm == 0):
        return xm, 0.0
      
      if((fm * fa) < 0.0):
        b = xm; fb = fm
        if(fm  * aux > 0):
          fa = fa / 2.0
      else:
        a = xm; fa = fm
        if(fm  * aux > 0):
          fb = fb / 2.0
        
      aux = fm  
      erro = math.fabs(b - a)
      
      if(erro < erro_passado):
        return xm, erro
      
      print 'Iteracao ', contador, ' alpha = ', xm
      
    return xm, erro
      
  else:
      
    if(intervalo[0] > 0):
      intervalo[0] -= 0.5
    else:
      intervalo[0] += 0.5
      
      
    return obter_alpha(intervalo, grau, coeficientes , limite, erro_passado)