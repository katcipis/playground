from sistemas_lineares import lineares_gauss

def aproximar_ln_raizquinta_pade(x):
  c = [0.0, 1.0/5.0, -1.0/10.0, 1.0/15.0, -1.0/20.0, 1.0/25.0]
  matriz = [ [c[2], c[3], -c[4]], [c[3], c[4], -c[5]] ]
  
  lineares_gauss.EscalonarMatriz(matriz)
  b = lineares_gauss.ObterMatrizResposta(matriz)
  a = [0.0, c[1] + b[0]*c[0], c[2]+b[0]*c[1], c[3]+b[0]*c[2]+b[1]*c[1] ]
  
  x_qad = x*x
  num = a[0] + (a[1]*x) + (a[2] * x_qad) + (a[3] * x_qad *x)
  den = 1.0 + (b[0]*x) + (b[1] * x_qad)
  
  return num / den

def aproximar_ln_raizquinta_taylor(x, n = 500):
  num = x
  den = 5.0
  s = 0.0
  sinal = 1.0
  for i in range(n):
    s = s + (sinal * (num / den) )
    sinal = -sinal
    den = den + 5.0
    num = num * num
    
  return s