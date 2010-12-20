package testes;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertNotSame;
import static org.junit.Assert.assertSame;
import static org.junit.Assert.assertTrue;
import fila.filas.Fila;
import ine5384.excecoes.ExcecaoEstruturaVazia;

import java.util.HashSet;
import java.util.Set;

import jogo.Posicao;
import jogo.TabuleiroConcreto;
import jogo.Tabuleiro.Peca;

import org.junit.Before;
import org.junit.Test;

import tabelaHash.TabelaHash;
import tabelaHash.TabelaHashConcreta;

public class TesteDoTabuleiro {

	protected TabuleiroConcreto tabuleiroUm, outroTabuleiroUm, tabuleiroTres,
			tabuleiroDois;

	protected TabuleiroConcreto primeiroMovimentoDoTabuleiroTres,
			segundoMovimentoDoTabuleiroTres, terceiroMovimentoDoTabuleiroTres,
			quartoMovimentoDoTabuleiroTres;

	protected TabuleiroConcreto movimentoDoTabuleiroUm,
			outroMovimentoDoTabuleiroUm, movimentoDoTabuleiroDois,
			outroMovimentoDoTabuleiroDois, maisUmMovimentoDoTabuleiroDois;

	private TabelaHash<Posicao, Peca> tabelaDePecasDoTabUm, tabelaDePecasDoMovDoTabUm,
			tabelaDePecasDoOutroMovDoTabUm, tabelaDePecasDoMovDoTabDois,
			tabelaDePecasDoOutroMovDoTabDois,
			maisUmaTabelaDePecasDoMovDoTabDois, tabelaDePecasDoTabDois;

	private TabelaHash<Posicao, Peca> tabelaDePecasDoTabTres,
			tabelaDePecasDoPrimMovTabTres, tabelaDePecasDoSegMovTabTres,
			tabelaDePecasDoTercMovTabTres, tabelaDePecasDoQuarMovTabTres;

	@Before
	public void criarComponentes() {

		tabelaDePecasDoTabUm = new TabelaHashConcreta<Posicao, Peca>();
		tabelaDePecasDoTabDois = new TabelaHashConcreta<Posicao, Peca>();

		tabelaDePecasDoMovDoTabUm = new TabelaHashConcreta<Posicao, Peca>();
		tabelaDePecasDoOutroMovDoTabUm = new TabelaHashConcreta<Posicao, Peca>();

		tabelaDePecasDoMovDoTabDois = new TabelaHashConcreta<Posicao, Peca>();
		tabelaDePecasDoOutroMovDoTabDois = new TabelaHashConcreta<Posicao, Peca>();
		maisUmaTabelaDePecasDoMovDoTabDois = new TabelaHashConcreta<Posicao, Peca>();

		tabelaDePecasDoTabTres = new TabelaHashConcreta<Posicao, Peca>();

		tabelaDePecasDoPrimMovTabTres = new TabelaHashConcreta<Posicao, Peca>();
		tabelaDePecasDoSegMovTabTres = new TabelaHashConcreta<Posicao, Peca>();
		tabelaDePecasDoTercMovTabTres = new TabelaHashConcreta<Posicao, Peca>();
		tabelaDePecasDoQuarMovTabTres = new TabelaHashConcreta<Posicao, Peca>();

		criarTabelasDePecas();

		criarTabuleiros();

	}

	@Test
	public void doisTabuleirosSaoIguaisSePossuemAsMesmasPecasNasMesmasPosicoes() {
		assertEquals(tabuleiroUm, outroTabuleiroUm);
		assertEquals(tabuleiroUm, maisUmMovimentoDoTabuleiroDois);
		assertEquals(tabuleiroUm.hashCode(), maisUmMovimentoDoTabuleiroDois
				.hashCode());
		assertEquals(tabuleiroUm.toString(), maisUmMovimentoDoTabuleiroDois
				.toString());

	}

	@Test
	public void doisTabuleirosNaoSaoIguaisSeNaoPossuemAsMesmasPecasNasMesmasPosicoes() {

		assertFalse(tabuleiroUm.equals(tabuleiroDois));
		assertFalse(tabuleiroUm.equals(movimentoDoTabuleiroUm));
		assertFalse(tabuleiroUm.equals(outroMovimentoDoTabuleiroUm));
		assertFalse(tabuleiroUm.equals(movimentoDoTabuleiroDois));
		assertFalse(tabuleiroUm.equals(outroMovimentoDoTabuleiroDois));
		assertFalse(tabuleiroDois.equals(maisUmMovimentoDoTabuleiroDois));
	}

	@Test
	public void tabuleiroDeDoisMovimentosPossiveisSabeQualSaoSeusMovimentos()
			throws ExcecaoEstruturaVazia {
		Fila<TabuleiroConcreto> tabuleiros = tabuleiroUm.retornaMovimentos();

		assertEquals(movimentoDoTabuleiroUm, tabuleiros.remove());
		assertEquals(outroMovimentoDoTabuleiroUm, tabuleiros.remove());

	}

	@Test
	public void tabuleiroDeTresMovimentosPossiveisSabeQualSaoSeusMovimentos()
			throws ExcecaoEstruturaVazia {
		Fila<TabuleiroConcreto> tabuleiros = tabuleiroDois.retornaMovimentos();

		assertEquals(maisUmMovimentoDoTabuleiroDois, tabuleiros.remove());
		assertEquals(outroMovimentoDoTabuleiroDois, tabuleiros.remove());
		assertEquals(movimentoDoTabuleiroDois, tabuleiros.remove());

	}

	@Test
	public void tabuleiroDeQuatroMovimentosPossiveisSabeQualSaoSeusMovimentos()
			throws ExcecaoEstruturaVazia {
		Fila<TabuleiroConcreto> tabuleiros = tabuleiroTres.retornaMovimentos();

		assertEquals(quartoMovimentoDoTabuleiroTres, tabuleiros.remove());
		assertEquals(terceiroMovimentoDoTabuleiroTres, tabuleiros.remove());
		assertEquals(segundoMovimentoDoTabuleiroTres, tabuleiros.remove());
		assertEquals(primeiroMovimentoDoTabuleiroTres, tabuleiros.remove());
	
	}

	@Test
	public void testeComSet() {
		Set<TabuleiroConcreto> set = new HashSet<TabuleiroConcreto>();
		assertNotSame(tabuleiroUm, outroTabuleiroUm);
		assertTrue(set.add(tabuleiroUm));
		assertFalse(set.add(outroTabuleiroUm));
		assertSame(1, set.size());
	}

	private void criarMaisUmaTabelaDePecasDoMovDoTabDois() {
		maisUmaTabelaDePecasDoMovDoTabDois.insere(new Posicao(1, 1), Peca.TRES);
		maisUmaTabelaDePecasDoMovDoTabDois.insere(new Posicao(1, 2), Peca.QUATRO);
		maisUmaTabelaDePecasDoMovDoTabDois.insere(new Posicao(1, 3), Peca.CINCO);

		maisUmaTabelaDePecasDoMovDoTabDois.insere(new Posicao(2, 1), Peca.OITO);
		maisUmaTabelaDePecasDoMovDoTabDois.insere(new Posicao(2, 2), Peca.SETE);
		maisUmaTabelaDePecasDoMovDoTabDois.insere(new Posicao(2, 3), Peca.SEIS);

		maisUmaTabelaDePecasDoMovDoTabDois.insere(new Posicao(3, 1), Peca.UM);
		maisUmaTabelaDePecasDoMovDoTabDois.insere(new Posicao(3, 2), Peca.DOIS);
		maisUmaTabelaDePecasDoMovDoTabDois.insere(new Posicao(3, 3), Peca.NULA);

	}

	private void criarTabelaDePecasDoOutroMovDoTabDois() {
		tabelaDePecasDoOutroMovDoTabDois.insere(new Posicao(1, 1), Peca.TRES);
		tabelaDePecasDoOutroMovDoTabDois.insere(new Posicao(1, 2), Peca.QUATRO);
		tabelaDePecasDoOutroMovDoTabDois.insere(new Posicao(1, 3), Peca.CINCO);

		tabelaDePecasDoOutroMovDoTabDois.insere(new Posicao(2, 1), Peca.OITO);
		tabelaDePecasDoOutroMovDoTabDois.insere(new Posicao(2, 2), Peca.NULA);
		tabelaDePecasDoOutroMovDoTabDois.insere(new Posicao(2, 3), Peca.SETE);

		tabelaDePecasDoOutroMovDoTabDois.insere(new Posicao(3, 1), Peca.UM);
		tabelaDePecasDoOutroMovDoTabDois.insere(new Posicao(3, 2), Peca.DOIS);
		tabelaDePecasDoOutroMovDoTabDois.insere(new Posicao(3, 3), Peca.SEIS);

	}

	private void criarTabelaDePecasDoMovDoTabDois() {
		tabelaDePecasDoMovDoTabDois.insere(new Posicao(1, 1), Peca.TRES);
		tabelaDePecasDoMovDoTabDois.insere(new Posicao(1, 2), Peca.QUATRO);
		tabelaDePecasDoMovDoTabDois.insere(new Posicao(1, 3), Peca.NULA);

		tabelaDePecasDoMovDoTabDois.insere(new Posicao(2, 1), Peca.OITO);
		tabelaDePecasDoMovDoTabDois.insere(new Posicao(2, 2), Peca.SETE);
		tabelaDePecasDoMovDoTabDois.insere(new Posicao(2, 3), Peca.CINCO);

		tabelaDePecasDoMovDoTabDois.insere(new Posicao(3, 1), Peca.UM);
		tabelaDePecasDoMovDoTabDois.insere(new Posicao(3, 2), Peca.DOIS);
		tabelaDePecasDoMovDoTabDois.insere(new Posicao(3, 3), Peca.SEIS);

	}

	private void criarTabelaComTresMovimentos() {
		tabelaDePecasDoTabDois.insere(new Posicao(1, 1), Peca.TRES);
		tabelaDePecasDoTabDois.insere(new Posicao(1, 2), Peca.QUATRO);
		tabelaDePecasDoTabDois.insere(new Posicao(1, 3), Peca.CINCO);

		tabelaDePecasDoTabDois.insere(new Posicao(2, 1), Peca.OITO);
		tabelaDePecasDoTabDois.insere(new Posicao(2, 2), Peca.SETE);
		tabelaDePecasDoTabDois.insere(new Posicao(2, 3), Peca.NULA);

		tabelaDePecasDoTabDois.insere(new Posicao(3, 1), Peca.UM);
		tabelaDePecasDoTabDois.insere(new Posicao(3, 2), Peca.DOIS);
		tabelaDePecasDoTabDois.insere(new Posicao(3, 3), Peca.SEIS);
	}

	private void criarTabelaComDoisMovimentos() {
		tabelaDePecasDoTabUm.insere(new Posicao(1, 1), Peca.TRES);
		tabelaDePecasDoTabUm.insere(new Posicao(1, 2), Peca.QUATRO);
		tabelaDePecasDoTabUm.insere(new Posicao(1, 3), Peca.CINCO);

		tabelaDePecasDoTabUm.insere(new Posicao(2, 1), Peca.OITO);
		tabelaDePecasDoTabUm.insere(new Posicao(2, 2), Peca.SETE);
		tabelaDePecasDoTabUm.insere(new Posicao(2, 3), Peca.SEIS);

		tabelaDePecasDoTabUm.insere(new Posicao(3, 1), Peca.UM);
		tabelaDePecasDoTabUm.insere(new Posicao(3, 2), Peca.DOIS);
		tabelaDePecasDoTabUm.insere(new Posicao(3, 3), Peca.NULA);
	}

	private void criarTabelaDePecasDoMovDoTabUm() {

		tabelaDePecasDoMovDoTabUm.insere(new Posicao(1, 1), Peca.TRES);
		tabelaDePecasDoMovDoTabUm.insere(new Posicao(1, 2), Peca.QUATRO);
		tabelaDePecasDoMovDoTabUm.insere(new Posicao(1, 3), Peca.CINCO);

		tabelaDePecasDoMovDoTabUm.insere(new Posicao(2, 1), Peca.OITO);
		tabelaDePecasDoMovDoTabUm.insere(new Posicao(2, 2), Peca.SETE);
		tabelaDePecasDoMovDoTabUm.insere(new Posicao(2, 3), Peca.NULA);

		tabelaDePecasDoMovDoTabUm.insere(new Posicao(3, 1), Peca.UM);
		tabelaDePecasDoMovDoTabUm.insere(new Posicao(3, 2), Peca.DOIS);
		tabelaDePecasDoMovDoTabUm.insere(new Posicao(3, 3), Peca.SEIS);
	}

	private void criarTabelaDePecasDoOutroMovDoTabUm() {

		tabelaDePecasDoOutroMovDoTabUm.insere(new Posicao(1, 1), Peca.TRES);
		tabelaDePecasDoOutroMovDoTabUm.insere(new Posicao(1, 2), Peca.QUATRO);
		tabelaDePecasDoOutroMovDoTabUm.insere(new Posicao(1, 3), Peca.CINCO);

		tabelaDePecasDoOutroMovDoTabUm.insere(new Posicao(2, 1), Peca.OITO);
		tabelaDePecasDoOutroMovDoTabUm.insere(new Posicao(2, 2), Peca.SETE);
		tabelaDePecasDoOutroMovDoTabUm.insere(new Posicao(2, 3), Peca.SEIS);

		tabelaDePecasDoOutroMovDoTabUm.insere(new Posicao(3, 1), Peca.UM);
		tabelaDePecasDoOutroMovDoTabUm.insere(new Posicao(3, 2), Peca.NULA);
		tabelaDePecasDoOutroMovDoTabUm.insere(new Posicao(3, 3), Peca.DOIS);
	}

	private void criarTabelaDePecasDoQuarMovTabTres() {
		tabelaDePecasDoQuarMovTabTres.insere(new Posicao(1, 1), Peca.QUATRO);
		tabelaDePecasDoQuarMovTabTres.insere(new Posicao(1, 2), Peca.CINCO);
		tabelaDePecasDoQuarMovTabTres.insere(new Posicao(1, 3), Peca.TRES);

		tabelaDePecasDoQuarMovTabTres.insere(new Posicao(2, 1), Peca.UM);
		tabelaDePecasDoQuarMovTabTres.insere(new Posicao(2, 2), Peca.OITO);
		tabelaDePecasDoQuarMovTabTres.insere(new Posicao(2, 3), Peca.DOIS);

		tabelaDePecasDoQuarMovTabTres.insere(new Posicao(3, 1), Peca.SEIS);
		tabelaDePecasDoQuarMovTabTres.insere(new Posicao(3, 2), Peca.NULA);
		tabelaDePecasDoQuarMovTabTres.insere(new Posicao(3, 3), Peca.SETE);

	}

	private void criarTabelaDePecasDoTercMovTabTres() {
		tabelaDePecasDoTercMovTabTres.insere(new Posicao(1, 1), Peca.QUATRO);
		tabelaDePecasDoTercMovTabTres.insere(new Posicao(1, 2), Peca.CINCO);
		tabelaDePecasDoTercMovTabTres.insere(new Posicao(1, 3), Peca.TRES);

		tabelaDePecasDoTercMovTabTres.insere(new Posicao(2, 1), Peca.UM);
		tabelaDePecasDoTercMovTabTres.insere(new Posicao(2, 2), Peca.DOIS);
		tabelaDePecasDoTercMovTabTres.insere(new Posicao(2, 3), Peca.NULA);

		tabelaDePecasDoTercMovTabTres.insere(new Posicao(3, 1), Peca.SEIS);
		tabelaDePecasDoTercMovTabTres.insere(new Posicao(3, 2), Peca.OITO);
		tabelaDePecasDoTercMovTabTres.insere(new Posicao(3, 3), Peca.SETE);

	}

	private void criarTabelaDePecasDoSegMovTabTres() {

		tabelaDePecasDoSegMovTabTres.insere(new Posicao(1, 1), Peca.QUATRO);
		tabelaDePecasDoSegMovTabTres.insere(new Posicao(1, 2), Peca.CINCO);
		tabelaDePecasDoSegMovTabTres.insere(new Posicao(1, 3), Peca.TRES);

		tabelaDePecasDoSegMovTabTres.insere(new Posicao(2, 1), Peca.NULA);
		tabelaDePecasDoSegMovTabTres.insere(new Posicao(2, 2), Peca.UM);
		tabelaDePecasDoSegMovTabTres.insere(new Posicao(2, 3), Peca.DOIS);

		tabelaDePecasDoSegMovTabTres.insere(new Posicao(3, 1), Peca.SEIS);
		tabelaDePecasDoSegMovTabTres.insere(new Posicao(3, 2), Peca.OITO);
		tabelaDePecasDoSegMovTabTres.insere(new Posicao(3, 3), Peca.SETE);

	}

	private void criarTabelaDePecasDoPrimMovTabTres() {

		tabelaDePecasDoPrimMovTabTres.insere(new Posicao(1, 1), Peca.QUATRO);
		tabelaDePecasDoPrimMovTabTres.insere(new Posicao(1, 2), Peca.NULA);
		tabelaDePecasDoPrimMovTabTres.insere(new Posicao(1, 3), Peca.TRES);

		tabelaDePecasDoPrimMovTabTres.insere(new Posicao(2, 1), Peca.UM);
		tabelaDePecasDoPrimMovTabTres.insere(new Posicao(2, 2), Peca.CINCO);
		tabelaDePecasDoPrimMovTabTres.insere(new Posicao(2, 3), Peca.DOIS);

		tabelaDePecasDoPrimMovTabTres.insere(new Posicao(3, 1), Peca.SEIS);
		tabelaDePecasDoPrimMovTabTres.insere(new Posicao(3, 2), Peca.OITO);
		tabelaDePecasDoPrimMovTabTres.insere(new Posicao(3, 3), Peca.SETE);

	}

	private void criarTabelaDePecasDoTabTres() {

		tabelaDePecasDoTabTres.insere(new Posicao(1, 1), Peca.QUATRO);
		tabelaDePecasDoTabTres.insere(new Posicao(1, 2), Peca.CINCO);
		tabelaDePecasDoTabTres.insere(new Posicao(1, 3), Peca.TRES);

		tabelaDePecasDoTabTres.insere(new Posicao(2, 1), Peca.UM);
		tabelaDePecasDoTabTres.insere(new Posicao(2, 2), Peca.NULA);
		tabelaDePecasDoTabTres.insere(new Posicao(2, 3), Peca.DOIS);

		tabelaDePecasDoTabTres.insere(new Posicao(3, 1), Peca.SEIS);
		tabelaDePecasDoTabTres.insere(new Posicao(3, 2), Peca.OITO);
		tabelaDePecasDoTabTres.insere(new Posicao(3, 3), Peca.SETE);

	}

	private void criarTabelasDePecas() {
		criarTabelaComDoisMovimentos();
		criarTabelaComTresMovimentos();

		criarTabelaDePecasDoMovDoTabUm();
		criarTabelaDePecasDoOutroMovDoTabUm();

		criarTabelaDePecasDoMovDoTabDois();
		criarTabelaDePecasDoOutroMovDoTabDois();
		criarMaisUmaTabelaDePecasDoMovDoTabDois();

		criarTabelaDePecasDoTabTres();
		criarTabelaDePecasDoPrimMovTabTres();
		criarTabelaDePecasDoSegMovTabTres();
		criarTabelaDePecasDoTercMovTabTres();
		criarTabelaDePecasDoQuarMovTabTres();
	}

	private void criarTabuleiros() {
		tabuleiroUm = new TabuleiroConcreto(tabelaDePecasDoTabUm);
		outroTabuleiroUm = new TabuleiroConcreto(tabelaDePecasDoTabUm);

		tabuleiroDois = new TabuleiroConcreto(tabelaDePecasDoTabDois);

		movimentoDoTabuleiroUm = new TabuleiroConcreto(
				tabelaDePecasDoMovDoTabUm);
		outroMovimentoDoTabuleiroUm = new TabuleiroConcreto(
				tabelaDePecasDoOutroMovDoTabUm);

		movimentoDoTabuleiroDois = new TabuleiroConcreto(
				tabelaDePecasDoMovDoTabDois);
		outroMovimentoDoTabuleiroDois = new TabuleiroConcreto(
				tabelaDePecasDoOutroMovDoTabDois);
		maisUmMovimentoDoTabuleiroDois = new TabuleiroConcreto(
				maisUmaTabelaDePecasDoMovDoTabDois);

		tabuleiroTres = new TabuleiroConcreto(tabelaDePecasDoTabTres);

		primeiroMovimentoDoTabuleiroTres = new TabuleiroConcreto(
				tabelaDePecasDoPrimMovTabTres);
		segundoMovimentoDoTabuleiroTres = new TabuleiroConcreto(
				tabelaDePecasDoSegMovTabTres);
		terceiroMovimentoDoTabuleiroTres = new TabuleiroConcreto(
				tabelaDePecasDoTercMovTabTres);
		quartoMovimentoDoTabuleiroTres = new TabuleiroConcreto(
				tabelaDePecasDoQuarMovTabTres);
	}

}
