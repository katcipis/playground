package jogo.calculadorDeMovimentos;

import ine5384.excecoes.ExcecaoEstruturaCheia;

import java.util.HashSet;
import java.util.Set;

import jogo.Posicao;
import jogo.Tabuleiro.Peca;
import pilha.Pilha;
import pilha.PilhaEncadeada;
import tabelaHash.TabelaHash;

public class CalculadorDeTresMovimentos extends CalculadorDeMovimentos {

	private final Set<Posicao> posicoesValidas;

	public CalculadorDeTresMovimentos(Posicao posDaPecaNula,
			TabelaHash<Posicao, Peca> posicoesDasPecas) {

		super(posDaPecaNula, posicoesDasPecas);

		posicoesValidas = new HashSet<Posicao>();
		definirPosicoesValidas();
	}

	private void definirPosicoesValidas() {
		posicoesValidas.add(new Posicao(2, 1));
		posicoesValidas.add(new Posicao(1, 2));
		posicoesValidas.add(new Posicao(3, 2));
		posicoesValidas.add(new Posicao(2, 3));
	}

	@Override
	public Pilha<TabelaHash<Posicao, Peca>> calcularMovimentos() {

		if (posDaPecaNula.equals(new Posicao(2, 1)))
			return obterTabuleiros(new Posicao(1, 1),
					       new Posicao(2, 2),new Posicao(3, 1));

		if (posDaPecaNula.equals(new Posicao(1, 2)))
			return obterTabuleiros(new Posicao(1, 1),
				       new Posicao(2, 2),new Posicao(1, 3));

		if (posDaPecaNula.equals(new Posicao(3, 2)))
			return obterTabuleiros(new Posicao(2, 2),
				       new Posicao(3, 1),new Posicao(3, 3));

		if (posDaPecaNula.equals(new Posicao(2, 3)))
			return obterTabuleiros(new Posicao(1,3),
				       new Posicao(2, 2),new Posicao(3, 3));

		return new PilhaEncadeada<TabelaHash<Posicao, Peca>>();
	}

	
	private Pilha<TabelaHash<Posicao, Peca>> obterTabuleiros(Posicao posPecaMovidaUm, Posicao posPecaMovidaDois, Posicao posPecaMovidaTres) {
		
		Pilha<TabelaHash<Posicao, Peca>> tabuleiros = new PilhaEncadeada<TabelaHash<Posicao, Peca>>();
		TabelaHash<Posicao, Peca> primeiroMovimento = pecasNoTab.retornaCopia();
		TabelaHash<Posicao, Peca> segundoMovimento = pecasNoTab.retornaCopia();
		TabelaHash<Posicao, Peca> terceiroMovimento = pecasNoTab.retornaCopia();
		
		Peca pecaMovidaUm = pecasNoTab.retorna(posPecaMovidaUm);
		Peca pecaMovidaDois = pecasNoTab.retorna(posPecaMovidaDois);
		Peca pecaMovidaTres = pecasNoTab.retorna(posPecaMovidaTres);

		primeiroMovimento.insere(posDaPecaNula, pecaMovidaUm);
		segundoMovimento.insere(posDaPecaNula, pecaMovidaDois);
		terceiroMovimento.insere(posDaPecaNula, pecaMovidaTres);

		primeiroMovimento.insere(posPecaMovidaUm, Peca.NULA);
		segundoMovimento.insere(posPecaMovidaDois, Peca.NULA);
		terceiroMovimento.insere(posPecaMovidaTres, Peca.NULA);

		try {
			tabuleiros.empilhe(primeiroMovimento);
			tabuleiros.empilhe(segundoMovimento);
			tabuleiros.empilhe(terceiroMovimento);
		} catch (ExcecaoEstruturaCheia e) {
			e.printStackTrace();
		}
		
		return tabuleiros;
	}

	

	@Override
	public boolean verificarSePossoCalcular() {

		return posicoesValidas.contains(posDaPecaNula);
	}

}
