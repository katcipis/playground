import lineares_gauss
import copy
import random
import math

TAMANHO_DA_MATRIZ = 500
INTERVALO_DE_VALORES = [0, 100000]
ERRO_MAX = math.pow(10, -100)

def TesteComplexo():
  matriz_teste = []
  matriz_resposta_teste = []
  
  for i in range(TAMANHO_DA_MATRIZ):
    linha_temp = []
    
    for j in range(TAMANHO_DA_MATRIZ):
      linha_temp.append(random.uniform(INTERVALO_DE_VALORES[0], INTERVALO_DE_VALORES[1]))
    
    matriz_teste.append(linha_temp)
    
  for i in range(TAMANHO_DA_MATRIZ):
    matriz_resposta_teste.append(random.uniform(INTERVALO_DE_VALORES[0], INTERVALO_DE_VALORES[1])) 
    
  lineares_gauss.ExpandirMatriz(matriz_teste, matriz_resposta_teste)
  
  print 'Teste Complexo:'; print ''
  print 'Matriz Original'
    
  for linha in matriz_teste:
    print linha
      
  print ''
  
  print 'Matriz Escalonada'
  lineares_gauss.EscalonarMatriz(matriz_teste)  
  for linha in matriz_teste:
    print linha
      
  print ''
  
  print ''
  respostas_teste = lineares_gauss.ObterMatrizResposta(matriz_teste)
  
  print 'Respostas'
  i = 1
  for linha in respostas_teste:
    x = "X" + str(i) + ": " 
    print x, linha
    i += 1
    
  print ''
  
  print 'Residuo: '
  residuos = lineares_gauss.ObterResiduos(matriz_teste, respostas_teste)
  erro = lineares_gauss.ObterErro(residuos)
  print erro
  print ''
  
  while(erro > ERRO_MAX):
    lineares_gauss.TrocarIncognitas(matriz_teste, residuos)
    print ''
    respostas_teste = lineares_gauss.ObterMatrizResposta(matriz_teste)
    print 'Respostas'
    i = 1
    
    for linha in respostas_teste:
      x = "X" + str(i) + ": " 
      print x, linha
      i += 1
    
    print ''
    
    print 'Residuo: '
    residuos = lineares_gauss.ObterResiduos(matriz_teste, respostas_teste)
    erro = lineares_gauss.ObterErro(residuos)
    print erro
    
  

def TesteSimples():
  linha_um = [2.0, 1.0, 0.0]
  linha_dois = [1.0, 3.0, 2.0]
  linha_tres = [-2.0, 0.0, 1.0]
  matriz_resposta = [0.0, 1.0, 1.0]
  matriz_ampliada = [linha_um, linha_dois, linha_tres]
  lineares_gauss.ExpandirMatriz(matriz_ampliada, matriz_resposta)
    
  print 'Teste Simples:'; print ''
  print 'Matriz Original'
  for linha in matriz_ampliada:
    print linha
    
  print ''
  lineares_gauss.EscalonarMatriz(matriz_ampliada)
  print 'Matriz escalonada'
  for linha in matriz_ampliada:
    print linha
    
  print ''
  respostas = lineares_gauss.ObterMatrizResposta(matriz_ampliada)
  print 'Respostas'
 
  i = 1
  for linha in respostas:
    x = "X" + str(i) + ": " 
    print x, linha
    i += 1
    
  print ''
  print 'Residuo: '
  residuos = lineares_gauss.ObterResiduos(matriz_ampliada, respostas)
  print lineares_gauss.ObterErro(residuos)
  print ''

TesteSimples()
TesteComplexo()

