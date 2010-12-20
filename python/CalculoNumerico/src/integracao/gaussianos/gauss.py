from integracao.gaussianos import parametros_gaussianos

def obter_integral(a, b, funcao, m = 4):
  ap, tp = parametros_gaussianos.obter_parametros(m)
  aux1 = (b + a) / 2.0; aux2 = (b - a) / 2.0; s = 0
  
  for i in range(m):
    xx = aux1 + aux2 * tp[i]
    s = s + ap[i] * funcao(xx)
    
  return aux2 * s