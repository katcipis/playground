import copy

def obter_resto(grau, coef, x, grau_derivadas = 0):
  novo_grau = grau
  aux = 1.0
  respostas = range(grau)
  coeficientes = copy.copy(coef)
  
  if(grau_derivadas == 0):
    grau_derivadas = grau
  
  for k in range(grau_derivadas):
    for i in range(novo_grau):
      coeficientes[i + 1] = coeficientes[i + 1] + x * coeficientes[i]
      
    respostas[k] = aux * coeficientes[novo_grau]
    novo_grau -= 1
    aux = aux * (k + 1)
    
  return respostas