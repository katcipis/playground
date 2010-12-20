package fila.testes.testesDasFilas;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

import ine5384.excecoes.ExcecaoEstruturaCheia;
import ine5384.excecoes.ExcecaoEstruturaVazia;
import fila.filas.Fila;
import fila.testes.listasDeTestesDasFilas.ListaDeTestesDaFila;

public abstract class TesteAbstratoDaFila implements ListaDeTestesDaFila {

	protected Fila<String> filaVazia, outraFilaVazia;
	protected String elementoUm, elementoDois, elementoTres, elementoQuatro;

	@Before
	public void criarComponentes() {
		elementoUm = "elementoUm";
		elementoDois = "elementoDois";
		elementoTres = "elementoTres";
		elementoQuatro = "elementoQuatro";

		filaVazia = criarFilaVazia();
		outraFilaVazia = criarFilaVazia();
	}

	protected abstract Fila<String> criarFilaVazia();

	@Test
	public void duasFilasComOsMesmosElementosNaMesmaOrdemNaoSaoIguaisSeAOutraPossuiMaisElementos()
			throws ExcecaoEstruturaCheia {
		for (int i = 1; i <= 5; i++) {
			filaVazia.insere(elementoUm);
			outraFilaVazia.insere(elementoUm);
		}
		outraFilaVazia.insere(elementoUm);

		assertFalse(filaVazia.equals(outraFilaVazia));

	}

	@Test
	public void duasFilasComOsMesmosElementosNaMesmaOrdemSaoIguais()
			throws ExcecaoEstruturaCheia {

		filaVazia.insere(elementoUm);
		outraFilaVazia.insere(elementoUm);

		filaVazia.insere(elementoDois);
		outraFilaVazia.insere(elementoDois);

		filaVazia.insere(elementoTres);
		outraFilaVazia.insere(elementoTres);

		filaVazia.insere(elementoQuatro);
		outraFilaVazia.insere(elementoQuatro);

		assertEquals(filaVazia, outraFilaVazia);

	}

	@Test
	public void duasFilasVaziasSaoIguais() throws ExcecaoEstruturaCheia {
		assertEquals(filaVazia, outraFilaVazia);

	}

	@Test
	public void elementosInseridosSempreFicamNoFim()
			throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia {
		filaVazia.insere(elementoUm);
		filaVazia.insere(elementoDois);
		filaVazia.insere(elementoTres);

		assertEquals(elementoUm, filaVazia.remove());
		assertEquals(elementoDois, filaVazia.remove());
		assertEquals(elementoTres, filaVazia.remove());

	}

	@Test
	public void inserindoUmElementoEmUmaFilaComUmElementoOPrimeiroElementoInseridoFicaNoInicio()
			throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia {
		
		filaVazia.insere(elementoDois);
		filaVazia.insere(elementoUm);

		assertEquals(elementoDois, filaVazia.retorneInicio());

	}

	@Test
	public void inserindoUmElementoEmUmaFilaVazia()
			throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia {
		filaVazia.insere(elementoUm);

		assertEquals(elementoUm, filaVazia.retorneInicio());

	}

	@Test
	public void oPrimeiroASerColocadoNaFilaSeraOPrimeiroASairDaFila()
			throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia {
		
		filaVazia.insere(elementoUm);
		filaVazia.insere(elementoDois);
		filaVazia.insere(elementoTres);

		assertEquals(elementoUm, filaVazia.remove());
		assertEquals(elementoDois, filaVazia.remove());
		assertEquals(elementoTres, filaVazia.remove());

	}

	@Test(expected = ExcecaoEstruturaVazia.class)
	public void seRemoverDeUmaFilaVaziaLancaUmaExcecaoEstruturaVazia()
			throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia {
		filaVazia.remove();

	}

	@Test(expected = ExcecaoEstruturaVazia.class)
	public void seRetornarDoInicioDeUmaFilaVaziaLancaUmaExcecaoEstruturaVazia()
			throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia {
		filaVazia.retorneInicio();

	}

}
