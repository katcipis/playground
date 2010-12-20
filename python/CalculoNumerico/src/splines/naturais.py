from sistemas_lineares import lineares_tridi
import math

def construir_matriz_trid(x, y, h, n):
  m = n - 1
  
  r = []; d=[]; t=[]; g = []
  r.append(2 * (h[0] + h[1]));
  
  aux1 = (y[2] - y[1]) / h[1]
  aux2 = (y[1] - y[0]) / h[0]
  
  g.append(6.0 * (aux1 - aux2))
 
  for i in range(1, m):
    t.append(h[i])
    r.append(2.0 * (h[i] + h[i + 1]))
    d.append(h[i + 1])
    aux2 = aux1
    aux1 = (y[i + 2] - y[i + 1]) / h[i + 1]
    g.append(6.0 * (aux1 - aux2))
  
  return r, d, t, g
    

def obter_aproximacao(x, y, n, alpha):
  h = []
  
  for i in range(n):
    h.append(x[i + 1] - x[i])
    
  r, d, t, g = construir_matriz_trid(x, y, h, n)
  s = range(n + 1)
  res = lineares_tridi.resolve_tridi(t, r, d, g)
  s[0] = 0.0
  s[n] = 0.0
  
  for i in range(1, n):
    s[i] = res[i-1]
  
  inicio = 1; fim = n + 1
  
  while(math.fabs(fim - inicio) != 1.0):
    meio = int( (fim + inicio) / 2 )
    
    if(x[meio] < alpha):
      inicio = meio
    else:
      fim = meio 
      
  j = inicio
  aj = (s[j+1] - s[j]) / 6.0 * h[j] 
  bj = s[j] / 2.0
  cj = ( (y[j+1] - y[j]) / h[j] ) - ( (s[j+1] + 2.0 * s[j] * h[j] ) / 6.0)
  dj = y[j]
  
  aux = alpha - x[j]
  res = dj + aux * (cj + aux * (bj + aux * aj))
  return res