import math

def exec_um_funcao(x):
  return ( (math.pow(x, 2.0)) - (2.0 * x * math.exp(-x)) + (math.exp(-2.0 * x)) )

def exec_um_derivada(x):
  t_um = 2.0 * x
  t_dois = 2.0 * math.exp(-x)
  t_tres = 2.0 * x * math.exp(-x)
  t_quatro = 2.0 * math.exp(-2.0 * x) 
  return t_um - t_dois + t_tres - t_quatro

def exec_dois_funcao(x):
  return math.log(x - 1.0)  + math.cos(x - 1.0)

def exec_dois_derivada(x):
  divisor = (x - 1.0)
  if(divisor != 0.0):
    return (1.0/ divisor) - math.sin(x - 1.0)
  else:
    print 'Ocorreu uma divisao por zero, execucao interrompida'
    return None
  
def exec_dois_derivada_seg(x):
  divisor = (x - 1.0)
  if(divisor != 0.0):
    return (1.0/ math.pow(divisor, 2)) - math.cos(x - 1.0)
  else:
    print 'Ocorreu uma divisao por zero, execucao interrompida'
    return None
  
def exec_tres_funcao(x):
  return (2.0 * x * math.cos(2.0 * x)) - (math.pow((x - 2.0), 2.0)) 

def exec_tres_derivada(x):
  t_um = 2.0 * math.cos(2.0 * x)
  t_dois = (2.0 * x) * (-2 * math.sin(2.0 * x))
  t_tres = 2.0 * (x - 2.0)
  return t_um + t_dois - t_tres

def exec_quatro_funcao(x):
  t_um = math.pow(x, 2)
  t_dois = (4.0 * x) * math.sin(x)
  t_tres = 2.0 * math.cos(2.0 * x)
  return t_um - t_dois - t_tres + 2

def exec_quatro_derivada(x):
  t_um = 2.0 * x
  t_dois = 4.0 * math.sin(x)
  t_tres = 4.0 * x * math.cos(x)
  t_quatro = 4.0 * math.sin(2.0 * x)
  return t_um - t_dois - t_tres + t_quatro