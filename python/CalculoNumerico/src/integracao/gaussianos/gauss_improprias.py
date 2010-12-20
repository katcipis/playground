from integracao.gaussianos import parametros_gaussianos

def obter_integral(a, funcao, m = 4):
  ap, tp = parametros_gaussianos.obter_parametros(m)
  aux = 1.0/2.0; s = 0
  f1 = funcao(1.0)
  
  for i in range(m):
    yy = aux + aux * tp[i]
    s = s + ap[i] * (f1 / funcao(yy)) / (yy * yy)
    
  return aux * s