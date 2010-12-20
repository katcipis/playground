import lineares_gauss
import lineares_jacob
import math

TAMANHO_MATRIZ = 5000
PRECISAO = math.pow(10, -8);
matriz = []
incognitas = []

def criar_matriz_esparsa():
    
  matriz.append([3.0, -1.0, 1.0, 2])
    
  for i in range(1, (TAMANHO_MATRIZ - 1)):
    linha = []
    linha.append(-1.0)
    linha.append(2.0 + i)
    linha.append(-1.0)
    linha.append(2.0 * i)
    matriz.append(linha)
    
  matriz.append([1.0, -1.0, 5002, 10000])
  
  
def criar_matriz_incognitas():
  for i in range(TAMANHO_MATRIZ):
    incognitas.append(0)

criar_matriz_esparsa()

criar_matriz_incognitas()

respostas = lineares_jacob.obter_respostas(matriz, incognitas, PRECISAO)

i = 1
for resposta in respostas:
  x = 'x' + str(i) + ': '
  print x, resposta
  i += 1
  
print ''
print 'Erro: '
print lineares_jacob.ERRO_FINAL
print 'Numero de Iteracoes: '
print lineares_jacob.ITERACOES

