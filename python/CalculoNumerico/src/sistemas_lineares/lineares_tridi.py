
def resolve_tridi(t, r, d, g):
  n = len(r)
  x = range(n)
  
  for i in range(1, n):
    r[i] = r[i] - (d[i - 1] * t[i - 1]) / (r[i - 1])
    g[i] = g[i] - (g[i - 1] * t[i - 1]) / (r[i - 1])
    
  x[n - 1] = g[n -1] / r[n - 1]
  
  inverso = range(n - 1)
  inverso.reverse()
  
  for i in inverso:
    x[i] = (g[i] - d[i] * x[i + 1]) / r[i]
    
  return x
      