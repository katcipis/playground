'''
Created on 07/04/2010
@author: katz
'''

from Jogador import Jogador

class JogadorCPU(Jogador):
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
        name = 'CPU:MinMax: %s' % name
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
            return JogadorCPU.perdeu
        
        if(moedasRestantes == 1):
            return JogadorCPU.venceu
        
        min1 = self.calculaJogadaMin(moedasRestantes, 1)
        min2 = self.calculaJogadaMin(moedasRestantes, 2)
        
        if(min1 > min2):
            return min1
        
        return min2
          
    
    def calculaJogadaMin(self, moedasRestantes, moedasARemover):
        '''
        Obtem o maior score baseado na quantidade de moedas e em quantas deseja remover (perspectiva do oponente).
        @param moedasRestantes: Total de moedas que existem na pilha ainda
        @param moedasARemover: Quantidade de moedas a remover.
        @return: Score dessa jogada.
        '''
        moedasRestantes = moedasRestantes - moedasARemover
        if(moedasRestantes == 0):
            return JogadorCPU.venceu
        
        if(moedasRestantes == 1):
            return JogadorCPU.perdeu
        
        max1 = self.calculaJogadaMax(moedasRestantes, 1)
        max2 = self.calculaJogadaMax(moedasRestantes, 2)
        
        if(max1 < max2):
            return max1
        
        return max2
        
        
    def obterProximaJogada(self, moedasRestantes):
        '''
        Obtem quantas moedas devem ser removidas da pilha de moedas
        @param moedasRestantes: Total de moedas que existem na pilha ainda
        @return: Quantidade de moedas a remover (uma ou duas).
        '''
     
        if(moedasRestantes == 1):
            return 1
        
        jogada1 = self.calculaJogadaMax(moedasRestantes, 1)
        jogada2 = self.calculaJogadaMax(moedasRestantes, 2)
        
        if(jogada1 > jogada2):
            return 1
        
        return 2
        