package arvores.arvoreBinariaDeBusca.testes;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

import arvores.arvoreBinariaDeBusca.ArvoreBuscaBinaria;
import arvores.iteradores.infraestrutura.IteradorInOrdem;
import arvores.iteradores.infraestrutura.IteradorPosOrdem;
import arvores.iteradores.infraestrutura.IteradorPreOrdem;
import ine5384.arvores.ArvoreBinaria;
import ine5384.excecoes.ExcecaoArvore;

public class TesteDaArvoreDeBuscaBinaria {

	private String letraA, letraB, letraC, letraD, letraE, letraF;
	private ArvoreBinaria<String> arvoreBinariaVazia;

	@Before
	public void criarComponentes() {
		letraA = "a";
		letraB = "b";
		letraC = "c";
		letraD = "d";
		letraE = "e";
		letraF = "f";

		arvoreBinariaVazia = criarArvore();
	}

	public ArvoreBinaria<String> criarArvore() {
		return new ArvoreBuscaBinaria<String>();
	}

	@Test
	public void podeRetornarARaizDeUmaArvore() {
		arvoreBinariaVazia.insere(letraA);
		assertEquals(letraA, arvoreBinariaVazia.retornaRaiz());
	}

	@Test
	public void retornaNuloSePedirARaizDeUmaArvoreQueEstaVazia() {

		assertNull(arvoreBinariaVazia.retornaRaiz());
	}

	@Test
	public void inserindoUmElementoNaArvoreVaziaEleFicaNaRaiz() {
		arvoreBinariaVazia.insere(letraA);
		assertTrue(arvoreBinariaVazia.contem(letraA));
		assertEquals(letraA, arvoreBinariaVazia.retornaRaiz());
	}

	@Test
	public void seInserirUmElementoMaiorQueARaizDaArvoreOElementoFicaraNaSubArvoreDireita() {
		arvoreBinariaVazia.insere(letraA);
		arvoreBinariaVazia.insere(letraB);

		assertTrue(arvoreBinariaVazia.contem(letraB));

		assertEquals(letraB, arvoreBinariaVazia.retornaArvoreDireita(letraA)
				.retornaRaiz());
		assertNull(arvoreBinariaVazia.retornaArvoreEsquerda(letraA)
				.retornaRaiz());

	}

	@Test
	public void seInserirUmElementoMenorQueARaizDaArvoreOElementoFicaraNaSubArvoreEsquerda() {

		arvoreBinariaVazia.insere(letraB);
		arvoreBinariaVazia.insere(letraA);

		assertTrue(arvoreBinariaVazia.contem(letraA));

		assertEquals(letraA, arvoreBinariaVazia.retornaArvoreEsquerda(letraB)
				.retornaRaiz());
		assertNull(arvoreBinariaVazia.retornaArvoreDireita(letraB)
				.retornaRaiz());

	}

	@Test
	public void seInserirUmElementoMenorQueARaizDaArvoreEJaExisteUmaSubArvoreNaEsquerdaDaRaizOElementoFicaraNaSubArvoreAhEsquerdaDaRaiz() {

		arvoreBinariaVazia.insere(letraD);
		arvoreBinariaVazia.insere(letraB);
		arvoreBinariaVazia.insere(letraA);

		assertNull(arvoreBinariaVazia.retornaArvoreDireita(letraD)
				.retornaRaiz());

		assertEquals(letraA, arvoreBinariaVazia.retornaArvoreEsquerda(letraB)
				.retornaRaiz());

		arvoreBinariaVazia.insere(letraC);

		assertEquals(letraC, arvoreBinariaVazia.retornaArvoreDireita(letraB)
				.retornaRaiz());

	}

	@Test
	public void seInserirUmElementoMaiorQueARaizDaArvoreEJaExisteUmaSubArvoreNaDireitaDaRaizOElementoFicaraNaSubArvoreAhDireitaDaRaiz() {

		arvoreBinariaVazia.insere(letraA);
		arvoreBinariaVazia.insere(letraC);
		arvoreBinariaVazia.insere(letraB);

		assertTrue(arvoreBinariaVazia.contem(letraA));
		assertTrue(arvoreBinariaVazia.contem(letraB));
		assertTrue(arvoreBinariaVazia.contem(letraC));

		assertNull(arvoreBinariaVazia.retornaArvoreEsquerda(letraA)
				.retornaRaiz());

		assertEquals(letraB, arvoreBinariaVazia.retornaArvoreEsquerda(letraC)
				.retornaRaiz());

		arvoreBinariaVazia.insere(letraD);

		assertEquals(letraD, arvoreBinariaVazia.retornaArvoreDireita(letraC)
				.retornaRaiz());

	}

	@Test
	public void seInserirUmElementoIgualAoQueSeEncontraNaRaizDaArvoreEleFicarahNaSubArvoreDireita() {

		arvoreBinariaVazia.insere(letraA);
		arvoreBinariaVazia.insere(letraA);

		assertEquals(letraA, arvoreBinariaVazia.retornaArvoreDireita(letraA)
				.retornaRaiz());

		assertNull(arvoreBinariaVazia.retornaArvoreEsquerda(letraA)
				.retornaRaiz());

	}

	@Test
	public void podeRetornarARaizDaArvore() {
		arvoreBinariaVazia.insere(letraB);
		assertEquals(letraB, arvoreBinariaVazia.retornaRaiz());
	}

	@Test
	public void aRaizDaArvoreEhOPrimeiroElementoInseridoNaArvore() {
		arvoreBinariaVazia.insere(letraB);
		arvoreBinariaVazia.insere(letraA);
		assertEquals(letraB, arvoreBinariaVazia.retornaRaiz());
	}

	@Test
	public void seInserirUmElementoMaiorQueOdaRaizEUmMenorQueODaRaizOMaiorFicaraADireitaEOMenorAEsquerda() {

		arvoreBinariaVazia.insere(letraB);
		arvoreBinariaVazia.insere(letraA);
		arvoreBinariaVazia.insere(letraC);

		assertEquals(letraA, arvoreBinariaVazia.retornaArvoreEsquerda(letraB)
				.retornaRaiz());
		assertEquals(letraC, arvoreBinariaVazia.retornaArvoreDireita(letraB)
				.retornaRaiz());

	}

	@Test
	public void removendoUmElementoEmUmaArvoreComApenasUmElemento() {
		arvoreBinariaVazia.insere(letraB);
		assertEquals(letraB, arvoreBinariaVazia.retornaRaiz());
		arvoreBinariaVazia.remove(letraB);
		assertNull(arvoreBinariaVazia.retornaRaiz());
	}

	@Test
	public void removendoOPrimeiroElementoEmUmaArvoreComDoisElementosUmNaEsquerda() {
		arvoreBinariaVazia.insere(letraB);
		arvoreBinariaVazia.insere(letraA);

		assertEquals(letraB, arvoreBinariaVazia.retornaRaiz());
		
		arvoreBinariaVazia.remove(letraB);
		
		assertEquals(letraA, arvoreBinariaVazia.retornaRaiz());
		assertNull(arvoreBinariaVazia.retornaArvoreEsquerda(letraA)
				.retornaRaiz());
		assertNull(arvoreBinariaVazia.retornaArvoreDireita(letraA)
				.retornaRaiz());
	}

	@Test
	public void removendoOSegundoElementoEmUmaArvoreComDoisElementosUmNaEsquerda() {
		arvoreBinariaVazia.insere(letraB);
		arvoreBinariaVazia.insere(letraA);

		assertEquals(letraA, arvoreBinariaVazia.retornaArvoreEsquerda(letraB)
				.retornaRaiz());
		
		arvoreBinariaVazia.remove(letraA);
		
		assertNull(arvoreBinariaVazia.retornaArvoreEsquerda(letraB)
				.retornaRaiz());

	}

	@Test
	public void naoPodeRemoverUmElementoSeOElementoNaoExisteNaArvore() {
		arvoreBinariaVazia.insere(letraB);
		assertEquals(letraB, arvoreBinariaVazia.retornaRaiz());
		arvoreBinariaVazia.remove(letraA);
		assertEquals(letraB, arvoreBinariaVazia.retornaRaiz());
	}

	@Test
	public void aoRemoverUmElementoQuePossuiSubArvoresPercorreraASubArvoreEsquerdaProcurandoPeloMaiorElementoParaColocarNoLugarDoElementoRemovido() {

		arvoreBinariaVazia.insere(letraF);
		arvoreBinariaVazia.insere(letraD);
		arvoreBinariaVazia.insere(letraB);
		arvoreBinariaVazia.insere(letraC);
		arvoreBinariaVazia.insere(letraA);

		assertEquals(letraB, arvoreBinariaVazia.retornaArvoreEsquerda(letraD)
				.retornaRaiz());
		arvoreBinariaVazia.remove(letraB);
		assertEquals(letraA, arvoreBinariaVazia.retornaArvoreEsquerda(letraD)
				.retornaRaiz());
		assertEquals(letraC, arvoreBinariaVazia.retornaArvoreDireita(letraA)
				.retornaRaiz());

	}

	@Test
	public void aoRemoverARaizDaArvoreQuePossuiSubArvoresPercorreraASubArvoreEsquerdaProcurandoPeloMaiorElementoParaColocarNoLugarDaRaizRecursivamente() {

		arvoreBinariaVazia.insere(letraE);
		arvoreBinariaVazia.insere(letraF);
		arvoreBinariaVazia.insere(letraD);
		arvoreBinariaVazia.insere(letraB);
		arvoreBinariaVazia.insere(letraC);
		arvoreBinariaVazia.insere(letraA);

		assertEquals(letraE, arvoreBinariaVazia.retornaRaiz());
		assertEquals(letraD, arvoreBinariaVazia.retornaArvoreEsquerda(letraE)
				.retornaRaiz());
		assertEquals(letraF, arvoreBinariaVazia.retornaArvoreDireita(letraE)
				.retornaRaiz());

		arvoreBinariaVazia.remove(letraE);

		assertEquals(letraD, arvoreBinariaVazia.retornaRaiz());
		assertEquals(letraF, arvoreBinariaVazia.retornaArvoreDireita(letraD)
				.retornaRaiz());
		assertEquals(letraC, arvoreBinariaVazia.retornaArvoreEsquerda(letraD)
				.retornaRaiz());

		assertEquals(letraB, arvoreBinariaVazia.retornaArvoreEsquerda(letraC)
				.retornaRaiz());
		assertEquals(letraA, arvoreBinariaVazia.retornaArvoreEsquerda(letraB)
				.retornaRaiz());
	}

	@Test
	public void removendoOPrimeiroElementoEmUmaArvoreComDoisElementosUmNaDireita() {
		arvoreBinariaVazia.insere(letraA);
		arvoreBinariaVazia.insere(letraB);

		assertEquals(letraA, arvoreBinariaVazia.retornaRaiz());
		arvoreBinariaVazia.remove(letraA);
		assertEquals(letraB, arvoreBinariaVazia.retornaRaiz());
		assertNull(arvoreBinariaVazia.retornaArvoreEsquerda(letraB)
				.retornaRaiz());
		assertNull(arvoreBinariaVazia.retornaArvoreDireita(letraB)
				.retornaRaiz());
	}

	@Test
	public void removendoOSegundoElementoEmUmaArvoreComDoisElementosUmNaDireita() {
		arvoreBinariaVazia.insere(letraA);
		arvoreBinariaVazia.insere(letraB);

		assertEquals(letraB, arvoreBinariaVazia.retornaArvoreDireita(letraA)
				.retornaRaiz());
		arvoreBinariaVazia.remove(letraB);
		assertNull(arvoreBinariaVazia.retornaArvoreDireita(letraA)
				.retornaRaiz());

	}

	@Test
	public void aoRemoverUmElementoQueNaoPossuiSubArvoreAEsquerdaPercorreraASubArvoreDireitaProcurandoPeloMenorElementoParaColocarNoLugarDoElementoRemovido() {

		arvoreBinariaVazia.insere(letraA);
		arvoreBinariaVazia.insere(letraB);
		arvoreBinariaVazia.insere(letraE);
		arvoreBinariaVazia.insere(letraF);
		arvoreBinariaVazia.insere(letraC);

		assertEquals(letraB, arvoreBinariaVazia.retornaArvoreDireita(letraA)
				.retornaRaiz());
		assertNull(arvoreBinariaVazia.retornaArvoreEsquerda(letraA)
				.retornaRaiz());

		arvoreBinariaVazia.remove(letraB);

		assertEquals(letraC, arvoreBinariaVazia.retornaArvoreDireita(letraA)
				.retornaRaiz());
		assertEquals(letraE, arvoreBinariaVazia.retornaArvoreDireita(letraC)
				.retornaRaiz());
		assertEquals(letraF, arvoreBinariaVazia.retornaArvoreDireita(letraE)
				.retornaRaiz());

	}

	@Test
	public void aoRemoverARaizDaArvoreQueNaoPossuiSubArvoreAhEsquerdaPercorreraASubArvoreDireitaProcurandoPeloMenorElementoParaColocarNoLugarDaRaizRecursivamente() {

		arvoreBinariaVazia.insere(letraA);
		arvoreBinariaVazia.insere(letraB);
		arvoreBinariaVazia.insere(letraE);
		arvoreBinariaVazia.insere(letraF);
		arvoreBinariaVazia.insere(letraC);

		assertNull(arvoreBinariaVazia.retornaArvoreEsquerda(letraA)
				.retornaRaiz());

		arvoreBinariaVazia.remove(letraA);

		assertEquals(letraB, arvoreBinariaVazia.retornaRaiz());

		assertEquals(letraC, arvoreBinariaVazia.retornaArvoreDireita(letraB)
				.retornaRaiz());
		assertEquals(letraE, arvoreBinariaVazia.retornaArvoreDireita(letraC)
				.retornaRaiz());
		assertEquals(letraF, arvoreBinariaVazia.retornaArvoreDireita(letraE)
				.retornaRaiz());

	}

	@Test
	public void sabeSeContemVariosElementos() {

		arvoreBinariaVazia.insere(letraA);
		arvoreBinariaVazia.insere(letraB);
		arvoreBinariaVazia.insere(letraE);
		arvoreBinariaVazia.insere(letraF);

		assertTrue(arvoreBinariaVazia.contem(letraA));
		assertTrue(arvoreBinariaVazia.contem(letraB));
		assertTrue(arvoreBinariaVazia.contem(letraE));
		assertTrue(arvoreBinariaVazia.contem(letraF));
	}

	@Test
	public void sabeSeContemUmElemento() {

		arvoreBinariaVazia.insere(letraA);

		assertTrue(arvoreBinariaVazia.contem(letraA));
	}

	@Test
	public void sabeSeNaoContemUmElemento() {

		arvoreBinariaVazia.insere(letraA);

		assertFalse(arvoreBinariaVazia.contem(letraB));
	}

	@Test
	public void sabeSeNaoContemVariosElementos() {

		arvoreBinariaVazia.insere(letraA);
		arvoreBinariaVazia.insere(letraB);

		assertFalse(arvoreBinariaVazia.contem(letraC));
		assertFalse(arvoreBinariaVazia.contem(letraE));
		assertFalse(arvoreBinariaVazia.contem(letraF));
	}

	@Test
	public void umElementoDaArvoreSempreEhAncestralDeleMesmo() {

		arvoreBinariaVazia.insere(letraA);

		assertTrue(arvoreBinariaVazia.ehAncestral(letraA, letraA));
	}

	@Test
	public void umElementoQueNaoEstaNaArvoreNaoEhAncestralDeleMesmoNemDeNinguem() {

		arvoreBinariaVazia.insere(letraA);

		assertFalse(arvoreBinariaVazia.ehAncestral(letraB, letraB));
		assertFalse(arvoreBinariaVazia.ehAncestral(letraB, letraA));
		assertFalse(arvoreBinariaVazia.ehAncestral(letraA, letraB));
	}

	@Test
	public void aRaizDaArvoreEhAncestralDeTodos() {
		arvoreBinariaVazia.insere(letraC);

		arvoreBinariaVazia.insere(letraA);
		arvoreBinariaVazia.insere(letraB);

		arvoreBinariaVazia.insere(letraE);
		arvoreBinariaVazia.insere(letraD);

		assertTrue(arvoreBinariaVazia.ehAncestral(letraC, letraA));
		assertTrue(arvoreBinariaVazia.ehAncestral(letraC, letraB));
		assertTrue(arvoreBinariaVazia.ehAncestral(letraC, letraE));
		assertTrue(arvoreBinariaVazia.ehAncestral(letraC, letraD));

	}

	@Test
	public void oAncestralDeUmElementoEhQuemFoiColocadoPrimeiroNaArvoreEEstaAcimaDele() {
		arvoreBinariaVazia.insere(letraC);

		arvoreBinariaVazia.insere(letraA);
		arvoreBinariaVazia.insere(letraB);

		arvoreBinariaVazia.insere(letraE);
		arvoreBinariaVazia.insere(letraD);

		assertTrue(arvoreBinariaVazia.ehAncestral(letraC, letraA));
		assertTrue(arvoreBinariaVazia.ehAncestral(letraA, letraB));

		assertTrue(arvoreBinariaVazia.ehAncestral(letraC, letraE));
		assertTrue(arvoreBinariaVazia.ehAncestral(letraE, letraD));

	}

	@Test
	public void naoEhOAncestralDeUmElementoSeFoiColocadoPrimeiroNaArvoreEEstaAcimaDeleMasNaoEstaNaMesmaSubArvore() {
		arvoreBinariaVazia.insere(letraC);

		arvoreBinariaVazia.insere(letraA);
		arvoreBinariaVazia.insere(letraB);

		arvoreBinariaVazia.insere(letraE);
		arvoreBinariaVazia.insere(letraD);

		assertFalse(arvoreBinariaVazia.ehAncestral(letraA, letraE));
		assertFalse(arvoreBinariaVazia.ehAncestral(letraA, letraD));

		assertFalse(arvoreBinariaVazia.ehAncestral(letraB, letraE));
		assertFalse(arvoreBinariaVazia.ehAncestral(letraB, letraD));

	}

	@Test
	public void oComprimentoEntreUmElementoEEleMesmoEhZero() {
		arvoreBinariaVazia.insere(letraC);

		assertEquals(0, arvoreBinariaVazia.retornaComprimento(letraC, letraC));
	}

	@Test
	public void oComprimentoEntreARaizEOSegundoElementoInseridoEhUm() {
		arvoreBinariaVazia.insere(letraC);
		arvoreBinariaVazia.insere(letraA);

		assertEquals(1, arvoreBinariaVazia.retornaComprimento(letraC, letraA));
	}

	@Test
	public void oComprimentoEntreARaizEUmElementoDeProfundidadeTresEhTres() {
		arvoreBinariaVazia.insere(letraD);
		arvoreBinariaVazia.insere(letraA);
		arvoreBinariaVazia.insere(letraB);
		arvoreBinariaVazia.insere(letraC);

		assertEquals(3, arvoreBinariaVazia.retornaComprimento(letraD, letraC));
	}

	@Test
	public void seOsElementosFazemParteDaMesmaSubArvoreElesTemComprimentoEntreSi() {
		arvoreBinariaVazia.insere(letraD);
		arvoreBinariaVazia.insere(letraA);
		arvoreBinariaVazia.insere(letraB);
		arvoreBinariaVazia.insere(letraC);

		assertEquals(2, arvoreBinariaVazia.retornaComprimento(letraA, letraC));
		assertEquals(1, arvoreBinariaVazia.retornaComprimento(letraA, letraB));
		assertEquals(1, arvoreBinariaVazia.retornaComprimento(letraB, letraC));
	}

	@Test(expected = ExcecaoArvore.class)
	public void oComprimentoEntreUmDescendenteEUmAncestralNaoExisteEEhLancadaUmaExcecao() {
		arvoreBinariaVazia.insere(letraC);
		arvoreBinariaVazia.insere(letraA);
		arvoreBinariaVazia.insere(letraB);

		arvoreBinariaVazia.retornaComprimento(letraA, letraC);

	}

	@Test(expected = ExcecaoArvore.class)
	public void oComprimentoEntreUmElementoQueNaoEstaraArvoreEQualquerOutroNaoExisteEEhLancadaUmaExcecao() {
		arvoreBinariaVazia.insere(letraC);

		arvoreBinariaVazia.insere(letraA);
		arvoreBinariaVazia.insere(letraB);

		arvoreBinariaVazia.retornaComprimento(letraE, letraC);
	}

	@Test(expected = ExcecaoArvore.class)
	public void oComprimentoEntreUmElementoQueEstaNaArvoreEQualquerOutroQueNaoExisteNaArvoreNaoExisteEEhLancadaUmaExcecao() {
		arvoreBinariaVazia.insere(letraC);

		arvoreBinariaVazia.insere(letraA);
		arvoreBinariaVazia.insere(letraB);

		arvoreBinariaVazia.retornaComprimento(letraC, letraF);
	}

	@Test(expected = ExcecaoArvore.class)
	public void oComprimentoEntreElementosDeSubArvoresDiferentesNaoExisteEEhLancadaUmaExcecao() {
		arvoreBinariaVazia.insere(letraB);
		arvoreBinariaVazia.insere(letraA);
		arvoreBinariaVazia.insere(letraC);

		arvoreBinariaVazia.retornaComprimento(letraA, letraC);

	}

	@Test
	public void oGrauDeUmElementoQueEhRaizDeUmaArvoreComApenasUmElementoEhZero() {
		arvoreBinariaVazia.insere(letraB);
		assertEquals(0, arvoreBinariaVazia.retornaGrau(letraB));
	}

	@Test
	public void oGrauDeUmElementoQueEhRaizDeUmaArvoreComUmaSubArvoreEhUm() {
		arvoreBinariaVazia.insere(letraB);
		arvoreBinariaVazia.insere(letraA);
		assertEquals(1, arvoreBinariaVazia.retornaGrau(letraB));
	}

	@Test
	public void oGrauDeUmElementoQueEhRaizDeUmaArvoreComDuasSubArvoresEhDois() {
		arvoreBinariaVazia.insere(letraB);
		arvoreBinariaVazia.insere(letraA);
		arvoreBinariaVazia.insere(letraC);
		assertEquals(2, arvoreBinariaVazia.retornaGrau(letraB));
	}

	@Test
	public void oGrauDeUmElementoQueEhRaizDeUmaSubArvoreComApenasUmElementoEhZero() {
		arvoreBinariaVazia.insere(letraB);
		arvoreBinariaVazia.insere(letraC);
		arvoreBinariaVazia.insere(letraA);
		assertEquals(0, arvoreBinariaVazia.retornaGrau(letraA));
		assertEquals(0, arvoreBinariaVazia.retornaGrau(letraC));
	}

	@Test
	public void oGrauDeUmElementoQueEhRaizDeUmaSubArvoreComUmaSubArvoreEhUm() {
		arvoreBinariaVazia.insere(letraB);
		arvoreBinariaVazia.insere(letraC);
		arvoreBinariaVazia.insere(letraE);
		assertEquals(1, arvoreBinariaVazia.retornaGrau(letraC));
	}

	@Test
	public void oGrauDeUmElementoQueEhRaizDeUmaSubArvoreComDuasSubArvoresEhDois() {
		arvoreBinariaVazia.insere(letraD);
		arvoreBinariaVazia.insere(letraB);
		arvoreBinariaVazia.insere(letraA);
		arvoreBinariaVazia.insere(letraC);
		assertEquals(2, arvoreBinariaVazia.retornaGrau(letraB));
	}

	@Test(expected = ExcecaoArvore.class)
	public void oGrauDeUmElementoQueNaoEstaNaArvoreNaoExisteEUmaExcecaoEhLancada() {
		arvoreBinariaVazia.insere(letraB);
		arvoreBinariaVazia.insere(letraC);
		arvoreBinariaVazia.insere(letraE);
		assertEquals(1, arvoreBinariaVazia.retornaGrau(letraD));
	}

	@Test
	public void arvoreComZeroElementosTemAlturaMenosUm() {
		assertEquals(-1, arvoreBinariaVazia.retornaAltura());
	}

	@Test
	public void arvoreComUmElementoTemAlturaZero() {
		arvoreBinariaVazia.insere(letraB);
		assertEquals(0, arvoreBinariaVazia.retornaAltura());
	}

	@Test
	public void arvoreComDoisElementosTemAlturaUm() {
		arvoreBinariaVazia.insere(letraB);
		arvoreBinariaVazia.insere(letraC);
		assertEquals(1, arvoreBinariaVazia.retornaAltura());
	}

	@Test
	public void arvoreComTresElementosOndeARaizTemDuasSubarvoresTemAlturaUm() {
		arvoreBinariaVazia.insere(letraB);
		arvoreBinariaVazia.insere(letraC);
		arvoreBinariaVazia.insere(letraA);
		assertEquals(1, arvoreBinariaVazia.retornaAltura());
	}

	@Test
	public void arvoreComTresElementosOndeARaizTemUmaSubArvoreQuePossuiOutraSubarvoreTemAlturaDois() {
		arvoreBinariaVazia.insere(letraC);
		arvoreBinariaVazia.insere(letraB);
		arvoreBinariaVazia.insere(letraA);
		assertEquals(2, arvoreBinariaVazia.retornaAltura());
	}

	@Test
	public void umaArvoreComVariosElementosOndeARaizTemDuasSubArvoreQuePossuemOutrasSubarvoresTeraAlturaDoMaiorRamo() {
		arvoreBinariaVazia.insere(letraE);
		arvoreBinariaVazia.insere(letraF);
		arvoreBinariaVazia.insere(letraC);
		arvoreBinariaVazia.insere(letraB);
		arvoreBinariaVazia.insere(letraD);
		arvoreBinariaVazia.insere(letraA);

		assertEquals(3, arvoreBinariaVazia.retornaAltura());

		arvoreBinariaVazia.esvazie();

		arvoreBinariaVazia.insere(letraB);
		arvoreBinariaVazia.insere(letraA);
		arvoreBinariaVazia.insere(letraD);
		arvoreBinariaVazia.insere(letraC);
		arvoreBinariaVazia.insere(letraE);
		arvoreBinariaVazia.insere(letraF);

		assertEquals(3, arvoreBinariaVazia.retornaAltura());
	}

	@Test
	public void aposSerEsvaziadaUmaArvoreNaoContemMaisNenhumElemento() {
		arvoreBinariaVazia.insere(letraE);
		arvoreBinariaVazia.insere(letraF);
		arvoreBinariaVazia.insere(letraC);

		arvoreBinariaVazia.esvazie();

		assertFalse(arvoreBinariaVazia.contem(letraE));
		assertFalse(arvoreBinariaVazia.contem(letraF));
		assertFalse(arvoreBinariaVazia.contem(letraC));
		assertEquals(-1, arvoreBinariaVazia.retornaAltura());
	}

	@Test
	public void dadoUmDeterminadoElementoPodeDizerQualOSeuPai() {
		arvoreBinariaVazia.insere(letraE);
		arvoreBinariaVazia.insere(letraF);
		arvoreBinariaVazia.insere(letraC);

		assertEquals(letraE, arvoreBinariaVazia.retornaPai(letraC));
		assertEquals(letraE, arvoreBinariaVazia.retornaPai(letraF));
	}

	@Test
	public void aRaizDaArvoreNaoPossuiPaiERetornaNull() {
		arvoreBinariaVazia.insere(letraE);
		arvoreBinariaVazia.insere(letraF);
		arvoreBinariaVazia.insere(letraC);

		assertNull(arvoreBinariaVazia.retornaPai(letraE));
	}

	@Test(expected = ExcecaoArvore.class)
	public void seOElementoNaoEstaNaArvoreNaoPossuiPaiELancaUmaExcecao() {
		arvoreBinariaVazia.insere(letraE);
		arvoreBinariaVazia.insere(letraF);
		arvoreBinariaVazia.insere(letraC);

		arvoreBinariaVazia.retornaPai(letraB);
	}

	@Test
	public void arvoreVaziaPossuiTamanhoZero() {

		assertEquals(0, arvoreBinariaVazia.retorneTamanho());
	}
	
	@Test
	public void oTamanhoDaArvoreEhAQuantidadeDeElementosQueElaPossui() {

		arvoreBinariaVazia.insere(letraE);
		arvoreBinariaVazia.insere(letraF);
		arvoreBinariaVazia.insere(letraC);
		
		assertEquals(3, arvoreBinariaVazia.retorneTamanho());
		
		arvoreBinariaVazia.insere(letraE);
		arvoreBinariaVazia.insere(letraF);
		arvoreBinariaVazia.insere(letraC);
	
		assertEquals(6, arvoreBinariaVazia.retorneTamanho());
	}
	
	@Test
	public void podeFornecerUmIteradorPreOrdemDaSuaArvore(){
		assertTrue(arvoreBinariaVazia.retornaIteratorPreOrdem()instanceof IteradorPreOrdem );
	}
	
	@Test
	public void podeFornecerUmIteradorPosOrdemDaSuaArvore(){
		assertTrue(arvoreBinariaVazia.retornaIteratorPosOrdem()instanceof IteradorPosOrdem );
	}
	
	@Test
	public void podeFornecerUmIteradorInOrdemDaSuaArvore(){
		assertTrue(arvoreBinariaVazia.retornaIteratorInOrdem()instanceof IteradorInOrdem );
	}

}
