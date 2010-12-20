package jogo;
public class Posicao {

	private final int LINHA;

	private final int COLUNA;

	public Posicao(int linha, int coluna) {
		this.LINHA = linha;
		this.COLUNA = coluna;
	}

	@Override
	public boolean equals(Object o) {
		if (o instanceof Posicao) {
			Posicao c = (Posicao) o;
			return ((c.LINHA == 
				LINHA) && 
				(c.COLUNA == COLUNA));
		}

		return false;

	}

	public int hashCode() {
		return Integer.valueOf(LINHA + "" 
				+ COLUNA);
	}

	public int obterLinha() {
		return LINHA;
	}

	public int obterColuna() {
		return COLUNA;
	}
	
}