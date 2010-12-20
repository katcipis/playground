
def aproximar_funcao(x, y, alpha, grau):
  num = 1
  for i in range(grau + 1):
    num = num * (alpha - x[i])
    
  resultado = 0.0
  
  for i in range(grau + 1):
    den = 1
    for j in range(grau + 1):
      if(i != j):
        den = den * (x[i] - x[j])
        
    resultado = resultado + ( (y[i] * num) / (den * (alpha - x[i])) )
    
  return resultado
  
  