import lineares_gauss_seidel
import math

ERRO_FINAL = 0.0
ITERACOES = 0

def obter_respostas(matriz, incognitas, erro_max):
  erro = erro_max * 10
  n = len(matriz)
  
  while(erro >= erro_max):
    novas_incognitas = []
    y_um = (2.0 + (1.0 * incognitas[1]) - (1.0 * incognitas[4999])) / 3.0
    novas_incognitas.append(y_um)
    
    for i in range(1 , (n - 1)):
      yi = ( (2.0 * i) + novas_incognitas[i - 1] + incognitas[i + 1] ) / (2.0 + i)
      novas_incognitas.append(yi)
      
    y_cinc_mil = (10000.0 - novas_incognitas[0] + novas_incognitas[4998]) / 5002.0
    novas_incognitas.append(y_cinc_mil)
    
    maior = math.fabs(novas_incognitas[0] - incognitas[0])
    
    for i in range(1, 5000):
      dif = math.fabs(novas_incognitas[i] - incognitas[i])
      if(dif > maior):
        maior = dif
        
    erro = maior
    incognitas = novas_incognitas
    lineares_gauss_seidel.ITERACOES += 1
      
  lineares_gauss_seidel.ERRO_FINAL = erro
  return incognitas
    
    
  