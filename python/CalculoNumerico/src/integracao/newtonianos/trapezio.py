from interpolacao import newton

def obter_integral(a, b, funcao, nit = 10, n = 4):
  
  h = (b-a) / n
  ex = funcao(a) + funcao(b)
  c = a; s = 0
  integrais = []
  
  for i in range(n-1):
    c = c+h
    s = s + funcao(c)
    
  integrais.append( (ex + 2.0 * s) * (h/2.0) )
  
  for k in range(1, nit):
    h_novo = h/2.0; c = a + h_novo
    s = s + funcao(c)
    
    for i in range(n-1):
      c = c + h
      s = s + funcao(c)
      
    integrais.append( (ex + 2.0 * s) * (h_novo / 2.0) )
    h = h_novo; n = n + n
    
  return integrais 
  
  
  
  
def obter_integral_aprox(a, b, x, y, grau, nit = 10, n = 4):
  
  h = (b-a) / n
  fa = newton.aproximar_funcao(x, y, a, grau)
  fb = newton.aproximar_funcao(x, y, b, grau)
  ex = fa + fb; c = a; s = 0
  integrais = []
  
  for i in range(n-1):
    c = c+h
    s = s + newton.aproximar_funcao(x, y, c, grau)
    
  integrais.append( (ex + 2.0 * s) * (h/2.0) )
  
  for k in range(1, nit):
    h_novo = h/2.0; c = a + h_novo
    s = s + newton.aproximar_funcao(x, y, c, grau)
    
    for i in range(n-1):
      c = c + h
      s = s + newton.aproximar_funcao(x, y, c, grau)
      
    integrais.append( (ex + 2.0 * s) * (h_novo / 2.0) )
    h = h_novo; n = n + n
    
  return integrais