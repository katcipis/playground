
for i in range(1,27):
  inverso = 0.0
  aux = 27.0
  tmp = 0.2
  contador = 0
  
  while((tmp != int(tmp)) and (contador < 40) ):
    inverso = (aux / i)
    tmp = inverso % 26
    aux = aux + 26.0
    contador += 1
    
  print 'Inverso Mod26 de ', i, ': ', inverso 
    
  
    