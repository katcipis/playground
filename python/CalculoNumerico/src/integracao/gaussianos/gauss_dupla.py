from integracao.gaussianos import parametros_gaussianos

def obter_integral(a, b, c, d, funcao, m = 3):
  aux1 = (b-a) / 2.0;  aux2 = (b+a) / 2.0
  auy1 = (d-c) / 2.0;  auy2 = (d+c) / 2.0
  ap, tp = parametros_gaussianos.obter_parametros(m)
  s = 0.0
  
  for i in range(m):
    ss = 0
    xx = aux1 * tp[i] + aux2
    for j in range(m):
      yy = auy1 * tp[j] + auy2
      ss = ss + ap[j] * funcao(xx, yy)
      
    s = s + ap[i] * ss
    
  return aux1 * auy1 * s
  