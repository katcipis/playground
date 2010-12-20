import math
import divisao
import horner
import falsa_posicaom

def obter_localizacao_raizes(grau, coeficientes):
  intervalo = 0.0
  maior = 0.0

  for i in range(grau):
    if(math.fabs(coeficientes[i]) > maior):
      maior = math.fabs(coeficientes[i])
      
  return 1.0 + (maior / math.fabs(coeficientes[0]))
  

def obter_localizacao_ref_raizes(grau, coeficientes, x = 0.0):
  resultados = divisao.obter_resto(grau, coeficientes, x, 2)
  refinado = grau * math.fabs(resultados[0] / resultados[1])
  return refinado  
  
def obter_melhor_alpha(grau, coeficientes):
  intervalo = obter_localizacao_raizes(grau, coeficientes)
  intervalo = [-intervalo, intervalo]
  x, erro = falsa_posicaom.obter_alpha(intervalo, grau, coeficientes, 5)
  
  return x
 
  
  
  
  
  
    