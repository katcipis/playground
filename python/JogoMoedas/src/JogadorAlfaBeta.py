'''
Created on 08/04/2010

@author: guih
'''

from Jogador import Jogador

class JogadorAlfaBeta(Jogador):
    '''
    Implementa um jogador que utiliza a IA minmax.
    '''

    venceu = 10000000000
    perdeu = -venceu
    
    def __init__(self, name):
        '''
        Construtor
        @param nome: Nome do jogador.
        '''
        name = 'CPU:AlfaBeta: %s' % name
        Jogador.__init__(self, name)
        
    def calculaJogadaMax(self, moedasRestantes, moedasARemover):
        '''
        Obtem o maior score baseado na quantidade de moedas e em quantas deseja remover (perspectiva do jogador).
        @param moedasRestantes: Total de moedas que existem na pilha ainda
        @param moedasARemover: Quantidade de moedas a remover.
        @return: Score dessa jogada.
        '''
        moedasRestantes = moedasRestantes - moedasARemover
        if(moedasRestantes == 0):
            return JogadorAlfaBeta.perdeu
        
        if(moedasRestantes == 1):
            return JogadorAlfaBeta.venceu
        
        min1 = self.calculaJogadaMin(moedasRestantes, 1)
        if min1 > 0:
            return min1

        return self.calculaJogadaMin(moedasRestantes, 2)
        
    def calculaJogadaMin(self, moedasRestantes, moedasARemover):
        '''
        Obtem o maior score baseado na quantidade de moedas e em quantas deseja remover (perspectiva do oponente).
        @param moedasRestantes: Total de moedas que existem na pilha ainda
        @param moedasARemover: Quantidade de moedas a remover.
        @return: Score dessa jogada.
        '''
        moedasRestantes = moedasRestantes - moedasARemover
        if(moedasRestantes == 0):
            return JogadorAlfaBeta.venceu
        
        if(moedasRestantes == 1):
            return JogadorAlfaBeta.perdeu
        
        max1 = self.calculaJogadaMax(moedasRestantes, 1)
        if max1 < 0:
            return max1
        return self.calculaJogadaMax(moedasRestantes, 2)
        
    def obterProximaJogada(self, moedasRestantes):
        '''
        Obtem quantas moedas devem ser removidas da pilha de moedas
        @param moedasRestantes: Total de moedas que existem na pilha ainda
        @return: Quantidade de moedas a remover (uma ou duas).
        '''
     
        if(moedasRestantes == 1):
            return 1
        
        jogada1 = self.calculaJogadaMin(moedasRestantes, 1)
        jogada2 = self.calculaJogadaMin(moedasRestantes, 2)
        
        if(jogada1 > jogada2):
            return 1
        
        return 2
    