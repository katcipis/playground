package jogo.calculadorDeMovimentos;

import jogo.Posicao;
import jogo.Tabuleiro.Peca;
import pilha.Pilha;
import tabelaHash.TabelaHash;

public abstract class CalculadorDeMovimentos {
	
	protected final Posicao posDaPecaNula;
	protected final TabelaHash<Posicao, Peca> pecasNoTab;
	
	public CalculadorDeMovimentos(Posicao posDaPecaNula,
			                       TabelaHash<Posicao, Peca> posicoesDasPecas){
		this.posDaPecaNula = posDaPecaNula;
		
		this.pecasNoTab = posicoesDasPecas;

	}

	public abstract boolean verificarSePossoCalcular();
	
	public abstract Pilha<TabelaHash<Posicao, Peca>> calcularMovimentos();
	
	
}
