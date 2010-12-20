'''
Created on 15/06/2009
@author: Katcipis
Modulo contendo a enumeracao de possiveis estados de uma conexao

PARADO        = A conexao ainda nao foi estabelecida
ESPERANDO     = Foi requisitada uma conexao e um pacote REQ_CHAMADA foi enviado
ENFILEIRADO   = Um pacote REQ_CHAMADA foi recebido mas nao existe ninguem disposto a receber ainda 
ESTABELECIDA  = A conexao foi estabelecida
ENVIANDO      = O usuario esta aguardando permissao para enviar um pacote
RECEBENDO     = O usuario esta aguardando para receber dados
DISCONECTANDO = O usuario requisitou que a conexao seja encerrada

'''
PARADO        = 'PARADO'
ESPERANDO     = 'ESPERANDO'
ENFILEIRADO   = 'ENFILEIRADO'
ESTABELECIDA  = 'ESTABELECIDA'
ENVIANDO      = 'ENVIANDO'
RECEBENDO     = 'RECEBENDO'
DESCONECTANDO = 'DESCONECTANDO'
