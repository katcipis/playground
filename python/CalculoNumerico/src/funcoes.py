import math

def calcular_num_iteracoes(a,b,erro):
  ab = math.fabs(b - a)
  x = ab / erro
  return math.log(x) / math.log(2)

def calcular_erro(x1, x2):
  xktmp = math.fabs(x2 - x1)
  
  if(math.fabs(x2) > math.fabs(x1)):
    return float(xktmp / math.fabs(x2))
  
  return float(xktmp / math.fabs(x1))

def convergente_simples(x):
  ex = math.exp(x)
  sinx = math.sin(x)
  return ( (ex * sinx) - 1.0 )  

def newton_convergente(x):
  return x + math.exp(x) - 2

def der_newton_convergente(x):
  return 1 + math.exp(x)

def der_seg_newton_convergente(x):
  return math.exp(x)

def newton_divergente(x):  
  if(x < 0):
    tmp =  math.fabs(x) ** (1.0/3.0)
    return -tmp
  
  return x ** (1.0/3.0)

def der_newton_divergente(x):
  exp = -2.0/3.0
  
  if(x < 0):
    tmp = math.fabs(x) ** exp
    tmp = -tmp
  else:
    tmp = x ** exp
    
  return (1.0/3.0) * tmp

def lnx(x):
  return math.log(x)

def inverso_x_lnx(x):
  return 1.0 / (x * math.log(x))

def raiz_lnx(x):
  return math.sqrt(math.log(x))

def x_senx(x):
  return x * math.sin(x)
