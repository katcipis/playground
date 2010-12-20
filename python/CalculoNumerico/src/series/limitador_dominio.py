def obter_x_novo(x, a, b):
  
  if(a == None) or (b == None):
    return x
  
  t = ((2.0 * x) / (b - a)) + ((b + a) / (b - a))
  x_lim = ((b - a) / 2.0) * t +  ((b + a) / 2.0)
  return x_lim