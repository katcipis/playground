'''
Created on 08/04/2010
@author: guih
'''
import random, time

class JogoDasMoedas(object):
    '''
    classdocs
    '''
    def __init__(self, totalDeMoedasNaPilha):
        self.totalDeMoedas = totalDeMoedasNaPilha
        self.jogadores = []
        
    def adicionarJogador(self, jogador):
        if jogador not in self.jogadores:
            self.jogadores.append(jogador)
            
    def iniciar(self):
        totalDeMoedas = self.totalDeMoedas
        print 'Total de moedas na pilha: %d' % totalDeMoedas
        random.shuffle(self.jogadores)
        nomes = ''
        for jogador in self.jogadores:
            nomes += str(jogador) + ', '
        print 'Ordem dos jogadores: %s' % nomes[:len(nomes)-2]
        jogadorAtual = -1
        
        print "**Iniciando a partida**"
        while totalDeMoedas > 0:
            jogadorAtual += 1
            jogadorAtual %= len(self.jogadores)
            jogador = self.jogadores[jogadorAtual]
            t = time.time()
            numeroDeMoedas = jogador.obterProximaJogada(totalDeMoedas)
            t = time.time() - t
            if numeroDeMoedas > totalDeMoedas:
                numeroDeMoedas = totalDeMoedas
            totalDeMoedas -= numeroDeMoedas
            print "\t%s removeu %d moeda(s) em %f segundos, moedas restantes = %d" % (str(jogador), numeroDeMoedas,t, totalDeMoedas)
        
        self.__terminar(self.jogadores[jogadorAtual])
        
    def __terminar(self, perdedor):
        print "**Fim de jogo**\n\tO(A) %s perdeu" % str(perdedor)