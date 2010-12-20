import localizacao_raizes
import divisao
import math

def obter_alpha(grau, coeficientes, erro_min = 10 ** -16 , limite = 20, x = 0.0):

  x_antigo = localizacao_raizes.obter_melhor_alpha(grau, coeficientes)
  
  for i in range(limite):
    fx_derivada = divisao.obter_resto(grau, coeficientes, x_antigo, 3)
    
    fator = fx_derivada[0] / math.sqrt(  (fx_derivada[1] ** 2) - fx_derivada[2] * fx_derivada[0])
    x_novo = x_antigo - fator
    
    erro = grau * math.fabs(fx_derivada[0] / fx_derivada[1])
    
    print 'Iteracao ', (i + 1), ' X = ', x_novo, ', erro = ', erro
    
    if(erro < erro_min):
      return x_novo
    
    x_antigo = x_novo
    
  print 'Resultado com a precisao desejada nao foi encontrado '
  return x_antigo
    
    