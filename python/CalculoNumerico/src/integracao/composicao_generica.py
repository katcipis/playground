import math

def calcular_erro(int, inta):
  int = math.fabs(int)
  inta = math.fabs(inta)
  
  num = int - inta
  if(int > inta):
    return num / int
  
  return num / inta

def obter_integral(a, b, funcao, metodo_integracao,  nit = 10, erro = 10 ** -16):
  n = 2
  h = (b-a) / n
  inta = metodo_integracao.obter_integral(a, a + h, funcao) + \
         metodo_integracao.obter_integral(a + h, b, funcao)
  n = 4; int = 0
  
  for i in range(nit):
    h = (b-a) / n
    int = 0; inicio = a; fim = inicio + h
    
    for k in range(n):
      int = int + metodo_integracao.obter_integral(inicio, fim, funcao)
      inicio = fim
      fim = fim + h
    
    print 'Iteracao ', i, ' : ', int
      
    erro_tmp = calcular_erro(int, inta)
    if(erro_tmp <= erro):
      return int
    
    inta = int
    n = n + n
    
  return int