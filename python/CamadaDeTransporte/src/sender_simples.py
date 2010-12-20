'''
Created on 22/06/2009
@author: Katcipis
'''
from transporte import camada_transporte
import sys


def main():
  
    if(len(sys.argv) < 3):
      print '\n usage: ' + str(sys.argv[0]) + 'IP_LOCAL:PORTA IP_REMOTO:PORTA (ex: 192.168.170.30:8000) \n'
    
    endereco_local  = sys.argv[1]
    endereco_remoto = sys.argv[2]
    msg = 'TESTANDO ENVIO DE DADOS POR CONEXAO'
  
    id_con = camada_transporte.connect(endereco_local, endereco_remoto)
    print 'Processo: Obteve conexao de id: ' + str(id_con)
    
    for i in range(10):
      print 'Send numero: ' + str(i)
      print 'Processo: Enviou: ' + msg + ' ' + str(i) 
      camada_transporte.send(id_con, msg + ' ' + str(i))
    
    print 'Processo: Desconectando'
    camada_transporte.disconnect(id_con)

    sys.exit()
    
if __name__ == '__main__':
    main()