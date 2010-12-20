import math

def obter_integral(funcao, m = 2, erro = 10 ** -16):
  ai = math.pi / m
  dois_m = 2.0 * m
  int = 0
  for i in range(1, (m + 1)):
    ti = math.cos( ((2.0 * i - 1.0) * math.pi) / dois_m)
    int = int + ai * funcao(ti)
    
  return int