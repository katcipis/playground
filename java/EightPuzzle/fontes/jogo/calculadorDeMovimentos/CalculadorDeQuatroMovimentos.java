package jogo.calculadorDeMovimentos;

import ine5384.excecoes.ExcecaoEstruturaCheia;

import java.util.HashSet;

import java.util.Set;

import jogo.Posicao;
import jogo.Tabuleiro.Peca;
import pilha.Pilha;
import pilha.PilhaEncadeada;
import tabelaHash.TabelaHash;

public class CalculadorDeQuatroMovimentos extends CalculadorDeMovimentos {

	private final Set<Posicao> posicoesValidas;

	public CalculadorDeQuatroMovimentos(Posicao posDaPecaNula,
			TabelaHash<Posicao, Peca> posicoesDasPecas) {

		super(posDaPecaNula, posicoesDasPecas);

		posicoesValidas = new HashSet<Posicao>();
		definirPosicoesValidas();
	}

	private void definirPosicoesValidas() {
		posicoesValidas.add(new Posicao(2, 2));
	}

	@Override
	public Pilha<TabelaHash<Posicao, Peca>> calcularMovimentos() {
		if (posDaPecaNula.equals(new Posicao(2, 2)))
			return this.obterTabuleiros(new Posicao(1,2), new Posicao(2,1), 
					                    new Posicao(2,3), new Posicao(3,2));

		return new PilhaEncadeada<TabelaHash<Posicao, Peca>>();
	}

	private Pilha<TabelaHash<Posicao, Peca>> obterTabuleiros(
			Posicao posPecaMovidaUm, Posicao posPecaMovidaDois,
			Posicao posPecaMovidaTres, Posicao posPecaMovidaQuatro) {

		Pilha<TabelaHash<Posicao, Peca>> tabuleiros = new PilhaEncadeada<TabelaHash<Posicao, Peca>>();

		TabelaHash<Posicao, Peca> primeiroMovimento = pecasNoTab.retornaCopia();
		TabelaHash<Posicao, Peca> segundoMovimento = pecasNoTab.retornaCopia();
		TabelaHash<Posicao, Peca> terceiroMovimento = pecasNoTab.retornaCopia();
		TabelaHash<Posicao, Peca> quartoMovimento = pecasNoTab.retornaCopia();

		Peca pecaMovidaUm = pecasNoTab.retorna(posPecaMovidaUm);
		Peca pecaMovidaDois = pecasNoTab.retorna(posPecaMovidaDois);
		Peca pecaMovidaTres = pecasNoTab.retorna(posPecaMovidaTres);
		Peca pecaMovidaQuatro = pecasNoTab.retorna(posPecaMovidaQuatro);
		
		primeiroMovimento.insere(posDaPecaNula, pecaMovidaUm);
		segundoMovimento.insere(posDaPecaNula, pecaMovidaDois);
		terceiroMovimento.insere(posDaPecaNula, pecaMovidaTres);
		quartoMovimento.insere(posDaPecaNula, pecaMovidaQuatro);

		
		primeiroMovimento.insere(posPecaMovidaUm, Peca.NULA);
		segundoMovimento.insere(posPecaMovidaDois, Peca.NULA);
		terceiroMovimento.insere(posPecaMovidaTres, Peca.NULA);
		quartoMovimento.insere(posPecaMovidaQuatro, Peca.NULA);

		try {
			tabuleiros.empilhe(primeiroMovimento);
			tabuleiros.empilhe(segundoMovimento);
			tabuleiros.empilhe(terceiroMovimento);
			tabuleiros.empilhe(quartoMovimento);
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
