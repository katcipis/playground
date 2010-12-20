package jogo;

import ine5384.lineares.*;

/**
 * Interface que representa um solucionador para o jogo do tabuleiro.
 * @author Patricia
 */
public interface JogoTabuleiro {
	
	/**
	 * Retorna a solucao para o jogo do tabuleiro a partir de um dado tabuleiro
	 * inicial. A solucao consiste na lista de tabuleiros que representam os 
	 * estados que levam a solucao a partir do tabuleiro inicial, sendo que
	 * o primeiro elemento da lista retornada eh o estado inicial e o ultimo 
	 * elemento eh a solucao. A solucao deverá ser sempre um tabuleiro "t" com a 
	 * seguinte disposicao:
	 * <code><pre>
	 * 
	 * t.peca(1,1) == Peca.UM
	 * t.peca(1,2) == Peca.DOIS
	 * t.peca(1,3) == Peca.TRES
	 * t.peca(2,1) == Peca.QUATRO
	 * t.peca(2,2) == Peca.CINCO
	 * t.peca(2,3) == Peca.SEIS
	 * t.peca(3,1) == Peca.SETE
	 * t.peca(3,2) == Peca.OITO
	 * t.peca(3,3) == Peca.NULA
	 * 
	 * </pre></code>
	 * @param inicial o objeto que representa o estado inicial do tabuleiro
	 * @return uma lista de tabuleiros que representam os estados que levam a solucao
	 */
	public Lista<Tabuleiro> soluciona(Tabuleiro inicial);

}