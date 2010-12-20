package jogo;

import ine5384.excecoes.ExcecaoEstruturaCheia;
import ine5384.excecoes.ExcecaoEstruturaVazia;

import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

import jogo.calculadorDeMovimentos.CalculadorDeDoisMovimentos;
import jogo.calculadorDeMovimentos.CalculadorDeMovimentos;
import jogo.calculadorDeMovimentos.CalculadorDeQuatroMovimentos;
import jogo.calculadorDeMovimentos.CalculadorDeTresMovimentos;
import pilha.Pilha;
import tabelaHash.TabelaHash;
import fila.filas.Fila;
import fila.filas.FilaEncadeada;

public class TabuleiroConcreto implements Tabuleiro {

	private final TabelaHash<Posicao, Peca> posicoesDasPecas;

	private Set<Posicao> posicoes;

	public final TabuleiroConcreto pai;

	public TabuleiroConcreto(TabelaHash<Posicao, Peca> posicoesDasPecas) {
		pai = null;
		
		this.posicoesDasPecas = posicoesDasPecas;
		this.posicoes = new HashSet<Posicao>();

		this.criarPosicoes();

	}

	private void criarPosicoes() {
		Iterator<Posicao> iter = posicoesDasPecas.retornaChaves();
		while (iter.hasNext()) {
			posicoes.add(iter.next());
		}
		
		

	}

	private TabuleiroConcreto(TabelaHash<Posicao, Peca> posicoesDasPecas,
			TabuleiroConcreto pai) {
		this.pai = pai;
		this.posicoesDasPecas = posicoesDasPecas;
		this.posicoes = new HashSet<Posicao>();

		this.criarPosicoes();

	}

	@Override
	public boolean equals(Object o) {

		if (!(o instanceof TabuleiroConcreto))
			return false;

		return o.toString().equals(this.toString());
	}

	public Peca peca(int linha, int coluna) {
		Posicao pos = new Posicao(linha, coluna);
		return posicoesDasPecas.retorna(pos);
	}

	public TabelaHash<Posicao, Peca> ObterPosicoesDasPecas() {
		return posicoesDasPecas;
	}

	public Integer Tamanho() {
		return posicoes.size();
	}

	public Fila<TabuleiroConcreto> retornaMovimentos() {

		Posicao posicaoDaPecaNula = this.verificarPosicaoDaPecaNula();

		if (new CalculadorDeQuatroMovimentos(posicaoDaPecaNula,
				posicoesDasPecas).verificarSePossoCalcular())
			return calcularMovimentos(new CalculadorDeQuatroMovimentos(
					posicaoDaPecaNula, posicoesDasPecas));

		if (new CalculadorDeTresMovimentos(posicaoDaPecaNula, posicoesDasPecas)
				.verificarSePossoCalcular())
			return calcularMovimentos(new CalculadorDeTresMovimentos(
					posicaoDaPecaNula, posicoesDasPecas));

		if (new CalculadorDeDoisMovimentos(posicaoDaPecaNula, posicoesDasPecas)
				.verificarSePossoCalcular())
			return calcularMovimentos(new CalculadorDeDoisMovimentos(
					posicaoDaPecaNula, posicoesDasPecas));

		return new FilaEncadeada<TabuleiroConcreto>();
	}

	private Fila<TabuleiroConcreto> calcularMovimentos(
			CalculadorDeMovimentos calc) {

		Fila<TabuleiroConcreto> tabuleiros = new FilaEncadeada<TabuleiroConcreto>();
		Pilha<TabelaHash<Posicao, Peca>> movimentos = calc.calcularMovimentos();

		while (!movimentos.estaVazia()) {
			try {
				tabuleiros.insere(new TabuleiroConcreto(
						movimentos.desempilhe(), this));
			} catch (ExcecaoEstruturaCheia e) {
				e.printStackTrace();
			} catch (ExcecaoEstruturaVazia e) {
				e.printStackTrace();
			}
		}

		return tabuleiros;
	}

	private Posicao verificarPosicaoDaPecaNula() {
		Iterator<Posicao> iter = this.posicoes.iterator();
		Posicao posDoNulo = null;

		while (iter.hasNext()) {
			posDoNulo = iter.next();
			if (posicoesDasPecas.retorna(posDoNulo).equals(Peca.NULA))
				return posDoNulo;
		}

		return null;
	}

	@Override
	public String toString() {

		return

		(posicoesDasPecas.retorna(new Posicao(1, 1)).toString()) + " "
				+ (posicoesDasPecas.retorna(new Posicao(1, 2)).toString())
				+ " "
				+ (posicoesDasPecas.retorna(new Posicao(1, 3)).toString())
				+ " " + "\n"

				+ (posicoesDasPecas.retorna(new Posicao(2, 1)).toString())
				+ " "
				+ (posicoesDasPecas.retorna(new Posicao(2, 2)).toString())
				+ " "
				+ (posicoesDasPecas.retorna(new Posicao(2, 3)).toString())
				+ " "

				+ "\n"

				+ (posicoesDasPecas.retorna(new Posicao(3, 1)).toString())
				+ " "
				+ (posicoesDasPecas.retorna(new Posicao(3, 2)).toString())
				+ " "
				+ (posicoesDasPecas.retorna(new Posicao(3, 3)).toString());

	}

	@Override
	public int hashCode() {
		return this.toString().hashCode();
	}

}
