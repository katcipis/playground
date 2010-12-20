from interpolacao import newton

def obter_integral(a, b, funcao, nit = 10, n = 4):
  hv = (b - a) / n
  integrais = []
  ex = funcao(a) + funcao(b)
  sp = funcao(a + hv) + funcao(a + 3.0 * hv)
  si = funcao(a + 2.0 * hv)
  integrais.append((ex + 4.0 * sp + 2.0 * si) * (hv/3.0))
  
  for i in range(1, nit):
    si = si + sp; hp = hv/2.0
    c = a + hp; sp = funcao(c)
    
    for k in range(n - 1):
      c = c + hv
      sp = sp + funcao(c)
      
    n = n + n
    hv = hp
    
    integrais.append((ex + 4.0 * sp + 2.0 * si) * (hp/3.0))
    
  return integrais


def obter_integral_aprox(a, b, x, y, grau, nit = 10, n = 4):
  hv = (b - a) / n
  integrais = []
  
  fa = newton.aproximar_funcao(x, y, a, grau)
  fb = newton.aproximar_funcao(x, y, b, grau)
  ex = fa + fb
  
  sp = newton.aproximar_funcao(x, y, (a + hv), grau) + \
  newton.aproximar_funcao(x, y, (a + 3.0 * hv), grau)
  
  si = newton.aproximar_funcao(x, y, (a + 2.0 * hv), grau)
  integrais.append((ex + 4.0 * sp + 2.0 * si) * (hv/3.0))
  
  for i in range(1, nit):
    si = si + sp; hp = hv/2.0
    c = a + hp; sp = newton.aproximar_funcao(x, y, c, grau)
    
    for k in range(n - 1):
      c = c + hv
      sp = sp + newton.aproximar_funcao(x, y, c, grau)
      
    n = n + n
    hv = hp
    
    integrais.append((ex + 4.0 * sp + 2.0 * si) * (hp/3.0))
    
  return integrais