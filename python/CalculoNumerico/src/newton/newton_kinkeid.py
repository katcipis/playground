import math
import funcoes

def obter_alpha(funcao, derivada, derivada_seg, 
                erro_fornecido = 0.0, limite = 20, x_inicial = 0.0):
  """ Quasi newton utilizando Kinkeid"""
  
  xm = x_inicial
  erro = 100.0
  
  for i in range(limite):
    xa = xm
    fxm = funcao(xm)
    
    divisor = math.pow(derivada(xm), 2) - derivada_seg(xm) * fxm 
    
    if(divisor > 0.0):
      xm = xm -  (fxm / math.sqrt(divisor))
      erro = funcoes.calcular_erro(xa, xm)
    
      print 'Iteracao ', (i + 1) , ' = ', xm
        
      if(erro < erro_fornecido):
        return xm, erro
      
    else:
      print 'Ocorreu divisao por zero, ou raiz quadrada', 
      ' de um numero negativo escolha outro Xo'
      return xm, erro
      
  print 'Precisao nao obtida'
  print ''
  return xm, erro

def obter_melhor_x_inicial(intervalo, funcao, derivada, derivada_seg, erro_fornecido = 0.0, limite = 20):
  
  x_temp = float(intervalo[0])
  fim = float(intervalo[1])
  erro_final = 10.0
  melhor_x = x_temp
  
  while(x_temp <= fim):
    resposta, erro = obter_alpha(funcao, derivada, derivada_seg, erro_fornecido, limite, x_temp)
    
    if(erro < erro_final):
      erro_final = erro
      melhor_x = x_temp
      
    x_temp += 0.1
    
  return melhor_x 