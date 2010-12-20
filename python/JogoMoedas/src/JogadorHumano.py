'''
Created on 07/04/2010
@author: katz
'''

from Jogador import Jogador

class JogadorHumano(Jogador):
    '''
    Implementa um jogador humano.
    '''

    def __init__(self, name):
        '''
        Construtor
        @param nome: Nome do jogador.
        '''
        Jogador.__init__(self, name)
        
    def obterProximaJogada(self, moedasRestantes):
        '''
        Obtem quantas moedas devem ser removidas da pilha de moedas
        @param moedasRestantes: Total de moedas que existem na pilha ainda
        @return: Quantidade de moedas a remover (uma ou duas).
        '''
        print('Total de moedas: ' + str(moedasRestantes))
        moedas = 0
        while moedas not in (1, 2):
            moedas = int(raw_input('%s, quantas moedas gostaria de remover? [1/2]: ' % str(self)))
        return moedas