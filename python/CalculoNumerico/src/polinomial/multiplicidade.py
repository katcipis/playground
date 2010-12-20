from polinomial import horner

def verifica_multiplicidade(grau, coeficientes, x, erro = (10 ** -16) ):
  novo_grau = grau

  for k in range(grau - 1):
    for i in range(novo_grau):
      coeficientes[i] = coeficientes[i] * (novo_grau - i)
      
    novo_grau -= 1
    vp = horner.obter_resto(novo_grau, coeficientes, x)
    
    if(vp > erro):
      return k + 1
    
    
  return grau
    