package arvores.iteradores.testes;

import static org.junit.Assert.*;

import ine5384.arvores.ArvoreBinaria;

import java.util.Iterator;
import java.util.NoSuchElementException;

import org.junit.Before;
import org.junit.Test;

public abstract class TesteDoIterador {

	protected Iterator<String> iteradorDaArvoreComDezElementos;
	protected ArvoreBinaria<String> arvoreQueOIteradorPercorreComDezElementos;
	protected String letraA, letraB, letraC, letraD, letraE, letraF, letraG,
			letraH, letraI, letraJ;

	@Before
	public void criarComponentes() {
		letraA = "a";
		letraB = "b";
		letraC = "c";
		letraD = "d";
		letraE = "e";
		letraF = "f";
		letraG = "g";
		letraH = "h";
		letraI = "i";
		letraJ = "j";

		arvoreQueOIteradorPercorreComDezElementos = retornarArvoreQueOIteradorPercorrera();
		
		arvoreQueOIteradorPercorreComDezElementos.insere(letraE);
		
		arvoreQueOIteradorPercorreComDezElementos.insere(letraC);
		arvoreQueOIteradorPercorreComDezElementos.insere(letraB);
		arvoreQueOIteradorPercorreComDezElementos.insere(letraD);
		arvoreQueOIteradorPercorreComDezElementos.insere(letraA);
		
		arvoreQueOIteradorPercorreComDezElementos.insere(letraH);
		arvoreQueOIteradorPercorreComDezElementos.insere(letraF);
		arvoreQueOIteradorPercorreComDezElementos.insere(letraG);
		arvoreQueOIteradorPercorreComDezElementos.insere(letraJ);
		arvoreQueOIteradorPercorreComDezElementos.insere(letraI);
		
		iteradorDaArvoreComDezElementos = retornarIteradorASerTestado();
	}

	protected abstract ArvoreBinaria<String> retornarArvoreQueOIteradorPercorrera();

	protected abstract Iterator<String> retornarIteradorASerTestado();

	@Test
	public void sabeDizerSeExisteUmProximoElemento() {
		assertTrue(iteradorDaArvoreComDezElementos.hasNext());
	}

	@Test
	public void sabeDizerSeNaoExisteUmProximoElemento() {
		esvaziarIterador();
		assertFalse(iteradorDaArvoreComDezElementos.hasNext());
	}

	@Test(expected = NoSuchElementException.class)
	public void seTentarObterOProximoENaoExisteProximoLancaUmaExcecao() {
		esvaziarIterador();
		iteradorDaArvoreComDezElementos.next();
	}

	@Test(expected = UnsupportedOperationException.class)
	public void seTentarRemoverUmElementoLancaUmaExcecao() {
		iteradorDaArvoreComDezElementos.remove();
	}

	private void esvaziarIterador() {
		for (int i = 1; i <= 10; i++) {
			iteradorDaArvoreComDezElementos.next();
		}
	}
}
