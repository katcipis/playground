package jogo;


/**
 * Interface que representa um estado do tabuleiro no jogo do tabuleiro.
 * @author Patricia
 */
public interface Tabuleiro {

	
	
	public enum Peca {
		UM,
		DOIS,
		TRES,
		QUATRO,
		CINCO,
		SEIS,
		SETE,
		OITO,
		NULA  // peca especial que representa o espaco vazio do tabuleiro
	}
	
	/**
	 * Retorna a peca na posicao (linha,coluna), tal que 1 <= linha <= 3 e 
	 * 1 <= coluna <= 3.
	 * Exemplo: 
	 * <code><pre>
	 * 
	 *   Tabuleiro tab;
	 *   ...
	 *   Peca p12 = tab.peca(1,2); // retorna a peca na linha 1 da coluna 2  
	 *   Peca p32 = tab.peca(3,2); // retorna a peca na linha 3 da coluna 2 
	 *   
	 * </pre></code>
	 * @param linha valor correspondente a linha do tabuleiro, sendo que 1 <= linha <= 3
	 * @param coluna valor correspondente a linha do tabuleiro, sendo que 1 <= coluna <= 3
	 * @return a peca na posicao correspondente a linha e coluna informadas
	 */
	public Peca peca(int linha, int coluna);
	

}