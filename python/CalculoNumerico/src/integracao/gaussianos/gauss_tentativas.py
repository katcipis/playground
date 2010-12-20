from integracao.gaussianos import parametros_gaussianos
from integracao.gaussianos import gauss
import math

def calcular_erro(int, inta):
  int = math.fabs(int)
  inta = math.fabs(inta)
  
  num = int - inta
  if(int > inta):
    return num / int
  
  return num / inta

def obter_integral(a, b, funcao, erro = 10 ** -16):
  max = parametros_gaussianos.obter_m_maximo()
  m = 2; int = 0.0
  inta = gauss.obter_integral(a, b, funcao, m)
  
  while(m < max):
    m += 1
    int = gauss.obter_integral(a, b, funcao, m)
    
    erro_tmp = calcular_erro(int, inta)
    if(erro_tmp <= erro):
      return int
    
    inta = int
    
  return int