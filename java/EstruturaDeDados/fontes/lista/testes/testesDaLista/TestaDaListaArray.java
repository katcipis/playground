package lista.testes.testesDaLista;

import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;
import ine5384.excecoes.ExcecaoEstruturaCheia;
import ine5384.excecoes.ExcecaoEstruturaVazia;
import ine5384.excecoes.ExcecaoPosicaoIlegal;
import ine5384.lineares.Lista;
import lista.listas.simples.ListaArray;
import lista.listasDeTestes.listasDeTestesDasListas.ListaDeTestesDaListaArray;

import org.junit.Test;

public class TestaDaListaArray extends TesteAbstratoDaLista implements ListaDeTestesDaListaArray {

	private void encherAListaDeTamanhoDez() throws ExcecaoEstruturaCheia,
			ExcecaoPosicaoIlegal {
		for (int i = 1; i <= 10; i++) {
			listaVazia.insiraNaPosicao(elementoUm, i);
		}
	}

	protected Lista<String> criarListaDeStrings() {
		return new ListaArray<String>();
	}

	@Test(expected = ExcecaoEstruturaCheia.class)
	public void seInserirUmElementoEmUmaListaCheiaLancaExcecaoDeEstruturaCheia()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal {

		encherAListaDeTamanhoDez();

		listaVazia.insiraNaPosicao(elementoUm, 1);

	}

	@Test
	public void sabeQuandoEstaCheia() throws ExcecaoEstruturaCheia,
			ExcecaoPosicaoIlegal {

		encherAListaDeTamanhoDez();

		assertTrue(listaVazia.estaCheia());
	}

	@Test
	public void sabeQuandoNaoEstaCheia() throws ExcecaoEstruturaCheia,
			ExcecaoPosicaoIlegal {

		for (int i = 1; i <= 9; i++) {
			listaVazia.insiraNaPosicao(elementoUm, i);
		}

		assertFalse(listaVazia.estaCheia());
	}

	@Test(expected = ExcecaoEstruturaCheia.class)
	public void naoPodeAdcionarUmElementoNoFinalDaListaSeElaEstaCheia()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal {

		encherAListaDeTamanhoDez();

		listaVazia.insiraNoFim(elementoUm);

	}

	@Test(expected = ExcecaoEstruturaCheia.class)
	public void naoPodeAdcionarUmElementoNoInicioDaListaSeAListaEstaCheia()
			throws ExcecaoPosicaoIlegal, ExcecaoEstruturaVazia,
			ExcecaoEstruturaCheia {

		encherAListaDeTamanhoDez();

		listaVazia.insiraNoInicio(elementoUm);

	}

	@Test
	public void seNaoForPassadoUmTamanhoMaximoParaAListaSeuTamanhoMaximoSeraDez()
			throws ExcecaoPosicaoIlegal, ExcecaoEstruturaCheia {
		boolean lancouExcecao = false;
		Lista<String> listaDoTeste = new ListaArray<String>();

		for (int i = 1; i <= 10; i++) {
			listaDoTeste.insiraNoFim(elementoUm);
		}

		try {
			listaDoTeste.insiraNoFim(elementoUm);
		} catch (ExcecaoEstruturaCheia e) {
			lancouExcecao = true;
		}

		assertTrue(lancouExcecao);

	}

	@Test(expected = ExcecaoEstruturaCheia.class)
	public void seForPassadoUmTamanhoMaximoParaAListaSeuTamanhoMaximoSeraOTamanhoPassado()
			throws ExcecaoEstruturaCheia {
		Lista<String> listaDeTamanhoCem = new ListaArray<String>(100);

		for (int i = 1; i <= 101; i++) {
			listaDeTamanhoCem.insiraNoFim(elementoUm);
		}

	}

	@Test(expected = ExcecaoEstruturaCheia.class)
	public void seExcederAoSeuTamanhoMaximoLancaUmaExcecaoDeEstruturaCheia()
			throws ExcecaoPosicaoIlegal, ExcecaoEstruturaCheia {

		encherAListaDeTamanhoDez();

		listaVazia.insiraNoFim(elementoUm);

	}

	

}
