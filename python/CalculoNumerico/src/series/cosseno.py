from series import limitador_dominio

def aproximar_cosseno_taylor(x, a = None, b = None):
  s  = 1.0
  x = limitador_dominio.obter_x_novo(x, a, b)
  sinal = -1.0
  den = 2.0
  x_quadrado = x ** 2.0
  num = x_quadrado
 
  for i in range(13):
    tmp = (num / den)
    s = s + (sinal * tmp)
    sinal = sinal * (-1.0)
    num = num * x_quadrado
    den = den * (den + 1.0)
    den = den * (den + 1.0)
    
  return s

def aproximar_cosseno_tchebyshev(x):

  t = obter_parametro_t(x, 5)
  exp1 = t[0] - (t[0] / 4.0) + ( (3.0 * t[0]) / (24.0 * 8.0) )
  exp2 = (-t[2] / 4.0) + ( (4.0 * t[2]) / 10.0)
  return exp1 + exp2

def aproximar_cosseno_pade(x):
  num = 24.0 - 2.0 * x + x*x + x*x*x
  den = 24.0 - 2.0 * x
  return num / den
    