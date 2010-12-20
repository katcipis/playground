'''
Created on 08/04/2010
@author: guih
'''

from JogoDasMoedas import JogoDasMoedas
from JogadorAlfaBeta import JogadorAlfaBeta
from JogadorCPU import JogadorCPU
from JogadorHumano import JogadorHumano

if __name__ == '__main__':

    jogo = JogoDasMoedas(int(raw_input('Insira a quantidade de moedas: ')))
    
    jogo.adicionarJogador(JogadorHumano(raw_input('Digite seu nome: ')))
    
    print 'Escolha o tipo do jogador oponente'
    print '\t[1] Jogador Humano'
    print '\t[2] Jogador CPU MinMax'
    print '\t[3] Jogador CPU MinMax com poda Alfa-Beta'
    tipoDoJogador = int(raw_input()) - 1
            
    jogador = [JogadorHumano, JogadorCPU, JogadorAlfaBeta][tipoDoJogador](raw_input('Nome do Jogador oponente: '))
    jogo.adicionarJogador(jogador)
    
    jogo.iniciar()
