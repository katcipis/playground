import copy

def obter_resto(grau, coef, x):
  coeficientes = copy.copy(coef)
  resultado = coeficientes[0]
  
  for i in range(grau):
    resultado = resultado * x + coeficientes[i + 1]
    
  return resultado