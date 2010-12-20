import math
import funcoes

def obter_alpha(funcao, derivada, erro_fornecido = 0.0, limite = 20, x_inicial = 0.0):
  """ Quasi newton utilizando derivada fixa em x0 """
  
  xm = x_inicial
  der = derivada(xm)
  
  if(der is 0.0):
    print 'Derivada em Xo igual a zero, escolha outro Xo'
    return None, None
  
  for i in range(limite):
    xa = xm

    xm = xm - (funcao(xm) / der)
    erro = funcoes.calcular_erro(xa, xm)
    
    print 'Iteracao ', (i + 1) , ' = ', xm
      
    if(erro < erro_fornecido):
      return xm, erro
      
    
    
  print 'Precisao nao obtida'
  print ''
  return xm, erro
     
def obter_melhor_x_inicial(intervalo, funcao, derivada, erro_fornecido = 0.0, limite = 20):
  
  x_temp = float(intervalo[0])
  fim = float(intervalo[1])
  erro_final = 10.0
  melhor_x = x_temp
  
  while(x_temp <= fim):
    resposta, erro = obter_alpha(funcao, derivada, erro_fornecido, limite, x_temp)
    
    if(erro < erro_final):
      erro_final = erro
      melhor_x = x_temp
      
    x_temp += 0.1
    
  return melhor_x  