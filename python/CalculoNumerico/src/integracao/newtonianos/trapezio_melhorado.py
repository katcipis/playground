from integracao.newtonianos import trapezio
import math

def obter_integral(a, b, funcao, nit = 4, n = 4, erro = 10**-16):
  integrais = trapezio.obter_integral(a, b, funcao, nit, n)
  rombergs = []  
  rombergs.append(integrais)
  
  for j in range(1, nit):
    rtmp = []
    for k in range(nit - j):
      rkj = (4**j * rombergs[j-1][k+1] - rombergs[j-1][k]) / (4**j - 1.0)
      rtmp.append(rkj)
      
    rombergs.append(rtmp)
    
  for i in range(nit -1):
    errotmp = math.fabs(rombergs[i+1][0] - rombergs[i][0]) 
    if(errotmp < erro):
      return rombergs[i+1][0]
 
  print 'Nao foi encontrado um resultado com a precisao desejada'   
  return integrais[0]
    