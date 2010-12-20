import math
import copy

def PivotarMatriz(matriz, linha = 0, coluna = 0):
  tamanho = len(matriz)
  inicio = linha + 1
  maior_linha = linha
  
  for i in range(inicio, tamanho):
    if(math.fabs(matriz[maior_linha][coluna]) < math.fabs(matriz[i][coluna])):
      maior_linha = i
      
  if(maior_linha is not linha):
    matriz = TrocaLinha(matriz, linha, maior_linha)
      

def TrocaLinha(matriz, linha_um, linha_dois):
  
  aux = matriz[linha_um]
  matriz[linha_um] = matriz[linha_dois]
  matriz[linha_dois] = aux
  
  return matriz

def ExpandirMatriz(matriz_reduzida, coluna_resposta):  
  [matriz_reduzida[i].append(coluna_resposta[i]) for i in range(len(coluna_resposta))]


def ObterResiduos(matriz_escalonada, respostas):
  n = len(respostas)
  residuos = []
  
  for i in range(n):
    linha = i
    soma = 0
   
    for j in range(i, n):
      soma = soma + (matriz_escalonada[linha][j] * respostas[j])
      
    residuos.append(math.fabs(matriz_escalonada[linha][n] - soma))
    
  return residuos

  
    
def ObterErro(residuos):
  erro = 0
  
  for residuo in residuos:
    erro = erro + residuo
    
  return erro
      
def EscalonarMatriz(matriz_ampliada):
  n = len(matriz_ampliada)
  n_ampliado = n + 1
  n_reduzido = n - 1
  
  for k in range(n_reduzido): 
    PivotarMatriz(matriz_ampliada, k, k) 
    akk = matriz_ampliada[k][k]
    
    if(akk == 0.0):
      break
      
    for i in range(k, n_ampliado):
      matriz_ampliada[k][i] = matriz_ampliada[k][i] / akk
        
    for i in range(k+1, n):
      cond = matriz_ampliada[i][k]
        
      for j in range(k, n_ampliado):
        matriz_ampliada[i][j] = matriz_ampliada[i][j] - cond  * matriz_ampliada[k][j]
          

def TrocarIncognitas(matriz_ampliada, incognitas):
  n = len(matriz_ampliada)
  for i in range(n):
    matriz_ampliada[i][n] = incognitas[i]
     

def ObterMatrizResposta(matriz):
  
  n_reversed = range(len(matriz))
  n_reversed.reverse()
  n_penultimo = len(matriz)
  respostas = []
  
  for i in n_reversed:
    j = 0
    r = len(respostas) - 1
    
    while(matriz[i][j] == 0.0):
      j += 1
    
    soma = 0
    
    for k in range((j+1), n_penultimo):
      soma = soma + (matriz[i][k] * respostas[r])
      r -= 1
       
    tmp = matriz[i][n_penultimo] - soma  
    
    if(matriz[i][j] != 1):
      respostas.append(tmp/matriz[i][j])
    else:
      respostas.append(tmp)
    
  respostas.reverse()
  return respostas
  