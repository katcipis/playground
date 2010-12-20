'''
Created on 22/06/2009
@author: Katcipis
'''
from transporte import camada_transporte
import sys


def main():
  if(len(sys.argv) < 2):
    print '\n usage: ' + str(sys.argv[0]) + ' IP:PORTA (ex: 192.168.170.30:8000)\n'
    sys.exit()
    return
    
  endereco = sys.argv[1]
  id_con = camada_transporte.listen(endereco)
  print 'Processo: Obteve conexao de id: ' + str(id_con)
  
  for i in range(10):
    print 'Receive numero: ' + str(i)
    print 'Processo: Recebeu ' + str(camada_transporte.receive(id_con))
  
  print 'Processo: Desconectando'
  camada_transporte.disconnect(id_con)
  sys.exit()

if __name__ == '__main__':
    main()