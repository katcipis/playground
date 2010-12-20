import copy

def obter_dif_divididas(x, y, grau):
  difs = []
  dif = []
  
  for i in range(grau):
    dif.append( (y[i + 1] - y[i]) / (x[i + 1] - x[i]) )
    
  difs.append(copy.copy(dif))
  difantigo =  copy.copy(dif)
  difnovo = []
  
  ordem = 2
  
  while(ordem <= grau):
    for i in range(grau):
      if(len(difantigo) > (i+ 1)):
        difnovo.append( (difantigo[i + 1] - difantigo[i]) / (x[i + ordem] - x[i]) )
    
    difs.append(copy.copy(difnovo)) 
    difantigo = copy.copy(difnovo)
    difnovo = []
    ordem += 1
    
  return difs

def aproximar_funcao(x, y, alpha, grau):
  diferencas = obter_dif_divididas(x, y, grau)
  s = y[0]
  p = 1
  
  for i in range(grau):
    p = p * (alpha - x[i])
    s = s + diferencas[i][0] * p
    
  return s
