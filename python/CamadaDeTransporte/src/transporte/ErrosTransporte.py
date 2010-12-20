'''
Created on 17/06/2009
@author: Katcipis

Modulo contendo a enumeracao de possiveis erros na camada de transporte

OK = OK 
TABELA_CHEIA = Ocorreu uma tentativa de realizar uma conexao porem ela falhou pois a tabela de conexoes esta cheia.
CONEXAO_REJEITADA = Ocorreu uma tentativa de realizar uma conexao porem ela foi rejeitada pelo endereco remoto.
CONEXAO_NAO_ESTABELECIDA = Ocorreu uma tentativa de enviar dados por uma conexao nao estabelecida.
CONEXAO_FECHADA = Ocorreu uma tentativa de enviar dados por uma conexao que ja foi fechada pelo parceiro remoto.
'''

OK                =  1
TABELA_CHEIA      = -1
CONEXAO_REJEITADA = -2
CONEXAO_NAO_ESTABELECIDA = -3
CONEXAO_FECHADA = -4
