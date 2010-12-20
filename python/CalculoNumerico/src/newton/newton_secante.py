import math
import funcoes

def obter_alpha(funcao, erro_fornecido = 0.0, limite = 20, x_um = 0.1, x_dois = 0.0):
  """ Quasi newton utilizando metodo da secante """
  
  x_novo = x_um
  x_antigo = x_dois
  
  for i in range(limite):
    f_novo = funcao(x_novo)
    
    x_tmp = x_novo
    x_novo = x_novo - ( (f_novo * (x_novo - x_antigo)) / (f_novo - funcao(x_antigo)) )
    x_antigo = x_tmp
    
    erro = funcoes.calcular_erro(x_antigo, x_novo)
    
    print 'Iteracao ', (i + 1) , ' = ', x_novo
      
    if(erro < erro_fornecido):
      return x_novo, erro

    
  print 'Precisao nao obtida'
  print ''
  return x_novo, erro
     
def obter_melhor_x_inicial(intervalo, funcao, erro_fornecido = 0.0, limite = 20):
  
  x_temp = float(intervalo[0])
  fim = float(intervalo[1])
  erro_final = 10.0
  melhor_x = x_temp
  
  while(x_temp <= fim):
    resposta, erro = obter_alpha(funcao, erro_fornecido, limite, x_temp, (x_temp + 0.1))
    
    if(erro < erro_final):
      erro_final = erro
      melhor_x = x_temp
      
    x_temp += 0.1
    
  return melhor_x