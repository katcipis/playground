'''
Created on 07/04/2010
@author: katz
'''

class Jogador(object):
    '''
    Classe abstrata que define um jogador.
    '''

    def __init__(self, nome):
        '''
        Construtor
        @param nome: Nome do jogador.
        '''
        self.__nome = nome
        
    def __str__(self):
        return 'Jogador % 25s]' % ('['+self.__nome)
        
    def obterProximaJogada(self, moedasRestantes):
        '''
        Obtem quantas moedas devem ser removidas da pilha de moedas
        @param moedasRestantes: Total de moedas que existem na pilha ainda
        @return: Quantidade de moedas a remover (uma ou duas).
        '''
        pass
        
        