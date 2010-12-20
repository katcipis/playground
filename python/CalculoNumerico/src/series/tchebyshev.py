
def obter_parametro_t(x, n):

  T = [1, x];
  for i in range(2,n+1):
    T.append((2.0*x*T[i-1]) - T[i-2]);
  return T;