package lista.testes.testesDaLista;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertNotSame;
import static org.junit.Assert.assertNull;
import static org.junit.Assert.assertTrue;
import lista.listasDeTestes.listasDeTestesDasListas.ListaDeTestesDaLista;
import ine5384.excecoes.ExcecaoEstruturaCheia;
import ine5384.excecoes.ExcecaoEstruturaVazia;
import ine5384.excecoes.ExcecaoPosicaoIlegal;
import ine5384.lineares.Lista;

import org.junit.Before;
import org.junit.Test;

public abstract class TesteAbstratoDaLista implements ListaDeTestesDaLista {

	protected Lista<String> listaVazia, outraListaVazia;
	protected String elementoUm, elementoDois,elementoTrês, 
	elementoQuatro, elementoCinco;

	public TesteAbstratoDaLista() {
		super();
	}

	@Before
	public void criarComponentes() {
		listaVazia = criarListaDeStrings();
		outraListaVazia = criarListaDeStrings();
		elementoUm = "elementoUm";
		elementoDois = "elementoDois";
		elementoTrês = "elementoTrês";
		elementoQuatro = "elementoQuatro";
		elementoCinco = "elementoCinco";
	}

	protected abstract Lista<String> criarListaDeStrings();

	@Test
	public void inserirUmPrimeiroElementoNaPosicaoUm()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaVazia.insiraNaPosicao(elementoUm, 1);

		assertEquals(elementoUm, listaVazia.retorneDaPosicao(1));

	}

	@Test
	public void inserirSegundoElementoNaPosicaoUm()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 1);

		assertEquals(elementoDois, listaVazia.retorneDaPosicao(1));
		assertEquals(elementoUm, listaVazia.retorneDaPosicao(2));
	}

	@Test
	public void inserirSegundoElementoNoFim() throws ExcecaoEstruturaCheia,
			ExcecaoPosicaoIlegal, ExcecaoEstruturaVazia {
		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);

		assertEquals(elementoDois, listaVazia.retorneDaPosicao(2));
		assertEquals(elementoUm, listaVazia.retorneDaPosicao(1));
	}

	@Test
	public void inserirUmElementoNoMeioDaLista() throws ExcecaoEstruturaCheia,
			ExcecaoPosicaoIlegal, ExcecaoEstruturaVazia {

		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);
		listaVazia.insiraNaPosicao(elementoTrês, 3);
		listaVazia.insiraNaPosicao(elementoQuatro, 4);

		listaVazia.insiraNaPosicao(elementoCinco, 4);

		assertEquals(elementoUm, listaVazia.retorneDaPosicao(1));
		assertEquals(elementoCinco, listaVazia.retorneDaPosicao(4));
		assertEquals(elementoDois, listaVazia.retorneDaPosicao(2));
		assertEquals(elementoTrês, listaVazia.retorneDaPosicao(3));
		assertEquals(elementoQuatro, listaVazia.retorneDaPosicao(5));
	}

	@Test
	public void seInserirUmElementoEmUmaDeterminadaPosicaoEleFicaraLa()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);
		listaVazia.insiraNaPosicao(elementoTrês, 3);
		listaVazia.insiraNaPosicao(elementoQuatro, 4);

		assertEquals(elementoUm, listaVazia.retorneDaPosicao(1));
		assertEquals(elementoDois, listaVazia.retorneDaPosicao(2));
		assertEquals(elementoTrês, listaVazia.retorneDaPosicao(3));
		assertEquals(elementoQuatro, listaVazia.retorneDaPosicao(4));

	}

	@Test
	public void seInserirUmElementoEmUmaDeterminadaPosicaoEJaExisteAlguemNelaOsElementosPosterioresSaoMovidosParaCima()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);
		listaVazia.insiraNaPosicao(elementoTrês, 3);
		listaVazia.insiraNaPosicao(elementoQuatro, 4);

		listaVazia.insiraNaPosicao(elementoCinco, 1);

		assertEquals(elementoCinco, listaVazia.retorneDaPosicao(1));
		assertEquals(elementoUm, listaVazia.retorneDaPosicao(2));
		assertEquals(elementoDois, listaVazia.retorneDaPosicao(3));
		assertEquals(elementoTrês, listaVazia.retorneDaPosicao(4));
		assertEquals(elementoQuatro, listaVazia.retorneDaPosicao(5));
	}

	@Test(expected = ExcecaoPosicaoIlegal.class)
	public void seInserirUmElementoNaPosicaoZeroElaEUmaPosicaoInvalida()
			throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia,
			ExcecaoPosicaoIlegal {

		listaVazia.insiraNaPosicao(elementoUm, 0);

	}

	@Test
	public void sabeQuandoEstaVazia() {
		assertTrue(listaVazia.estaVazia());
	}

	@Test
	public void sabeQuandoNaoEstaVazia() throws ExcecaoEstruturaCheia,
			ExcecaoPosicaoIlegal {
		listaVazia.insiraNaPosicao(elementoUm, 1);
		assertFalse(listaVazia.estaVazia());
	}

	@Test
	public void podeRetornarOPrimeiroElementoDaLista()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaVazia.insiraNaPosicao(elementoTrês, 1);
		listaVazia.insiraNaPosicao(elementoQuatro, 2);

		assertEquals(elementoTrês, listaVazia.retorneDoInicio());

	}

	@Test(expected = ExcecaoEstruturaVazia.class)
	public void sePedirParaRetornarOPrimeiroElementoDeUmaListaVaziaLancaUmaExcecaoEstruturaVazia()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaVazia.retorneDoInicio();

	}

	@Test
	public void podeRetornarOUltimoElementoDaLista()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaVazia.insiraNaPosicao(elementoTrês, 1);
		listaVazia.insiraNaPosicao(elementoQuatro, 2);
		listaVazia.insiraNaPosicao(elementoCinco, 3);

		assertEquals(elementoCinco, listaVazia.retorneDoFim());

	}

	@Test(expected = ExcecaoEstruturaVazia.class)
	public void sePedirParaRetornarOUltimoElementoDeUmaListaVaziaLancaUmaExcecaoEstruturaVazia()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaVazia.retorneDoFim();

	}

	@Test
	public void podeSubstituirUmElementoDaListaPorUmOutroENaoAlteraAQuantidadeDeElementos()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaVazia.insiraNaPosicao(elementoTrês, 1);
		listaVazia.insiraNaPosicao(elementoQuatro, 2);
		listaVazia.insiraNaPosicao(elementoCinco, 3);

		assertEquals(elementoCinco, listaVazia.retorneDaPosicao(3));
		listaVazia.substituaDaPosicao(elementoUm, 3);
		assertEquals(elementoUm, listaVazia.retorneDaPosicao(3));

		assertEquals(elementoQuatro, listaVazia.retorneDaPosicao(2));
		listaVazia.substituaDaPosicao(elementoUm, 2);
		assertEquals(elementoUm, listaVazia.retorneDaPosicao(2));

		assertEquals(elementoTrês, listaVazia.retorneDaPosicao(1));
		listaVazia.substituaDaPosicao(elementoUm, 1);
		assertEquals(elementoUm, listaVazia.retorneDaPosicao(1));

		assertEquals(3, listaVazia.retorneTamanho());
	}

	@Test(expected = ExcecaoEstruturaVazia.class)
	public void seSubstituirUmElementoDaListaPorUmOutroEmUmaListaVaziaLancaUmaExcecaoEstruturaVazia()
			throws ExcecaoPosicaoIlegal, ExcecaoEstruturaVazia {

		listaVazia.substituaDaPosicao(elementoUm, 1);

	}

	@Test(expected = ExcecaoPosicaoIlegal.class)
	public void seTentarSubstituirUmElementoDaListaEmUmaPosicaoQueNaoExisteLancaUmaExcecaoPosicaoIlegal()
			throws ExcecaoEstruturaVazia, ExcecaoEstruturaCheia,
			ExcecaoPosicaoIlegal {

		listaVazia.insiraNaPosicao(elementoTrês, 1);
		listaVazia.insiraNaPosicao(elementoQuatro, 2);
		listaVazia.insiraNaPosicao(elementoCinco, 3);

		listaVazia.substituaDaPosicao(elementoCinco, 4);

	}

	@Test
	public void sabeOSeuTamanho() throws ExcecaoEstruturaCheia,
			ExcecaoPosicaoIlegal {
		assertEquals(0, listaVazia.retorneTamanho());

		listaVazia.insiraNaPosicao(elementoTrês, 1);
		listaVazia.insiraNaPosicao(elementoQuatro, 2);
		listaVazia.insiraNaPosicao(elementoUm, 3);

		assertEquals(3, listaVazia.retorneTamanho());

		listaVazia.insiraNaPosicao(elementoUm, 4);
		listaVazia.insiraNaPosicao(elementoDois, 5);
		listaVazia.insiraNaPosicao(elementoTrês, 6);

		assertEquals(6, listaVazia.retorneTamanho());

	}

	@Test
	public void sabeQualNaoEOSeuTamanho() throws ExcecaoEstruturaCheia,
			ExcecaoPosicaoIlegal {
		assertFalse(1 == listaVazia.retorneTamanho());

		listaVazia.insiraNaPosicao(elementoTrês, 1);
		listaVazia.insiraNaPosicao(elementoQuatro, 2);
		listaVazia.insiraNaPosicao(elementoUm, 3);

		assertFalse(2 == listaVazia.retorneTamanho());
		assertFalse(4 == listaVazia.retorneTamanho());

	}

	@Test
	public void podeObterUmElementoAPartirDaSuaPosicao()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaVazia.insiraNaPosicao(elementoTrês, 1);
		listaVazia.insiraNaPosicao(elementoQuatro, 2);
		listaVazia.insiraNaPosicao(elementoUm, 3);

		assertEquals(elementoTrês, listaVazia.retorneDaPosicao(1));
		assertEquals(elementoQuatro, listaVazia.retorneDaPosicao(2));
		assertEquals(elementoUm, listaVazia.retorneDaPosicao(3));
	}

	@Test(expected = ExcecaoEstruturaVazia.class)
	public void seTentarObterUmElementoAPartirDaSuaPosicaoDeUmaListaVaziaLancaUmaExcecaoEstruturaVazia()
			throws ExcecaoPosicaoIlegal, ExcecaoEstruturaVazia {

		listaVazia.retorneDaPosicao(1);

	}

	@Test(expected = ExcecaoPosicaoIlegal.class)
	public void seTentarObterUmElementoAPartirDeUmaPosicaoMaiorQueDoUltimoElementoLancaUmaExcecaoPosicaoIlegal()
			throws ExcecaoEstruturaVazia, ExcecaoEstruturaCheia,
			ExcecaoPosicaoIlegal {

		listaVazia.insiraNaPosicao(elementoTrês, 1);
		listaVazia.insiraNaPosicao(elementoQuatro, 2);
		listaVazia.insiraNaPosicao(elementoUm, 3);

		listaVazia.retorneDaPosicao(4);

	}

	@Test
	public void podeAdcionarUmElementoNoFinalDaListaEEleFicaNoFinalDaLista()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaVazia.insiraNoFim(elementoUm);

		assertEquals(elementoUm, listaVazia.retorneDaPosicao(1));
		assertEquals(elementoUm, listaVazia.retorneDoFim());

		listaVazia.insiraNaPosicao(elementoUm, 2);
		listaVazia.insiraNaPosicao(elementoDois, 3);
		listaVazia.insiraNaPosicao(elementoTrês, 4);
		listaVazia.insiraNaPosicao(elementoQuatro, 5);

		listaVazia.insiraNoFim(elementoCinco);

		assertEquals(elementoCinco, listaVazia.retorneDaPosicao(6));
		assertEquals(elementoCinco, listaVazia.retorneDoFim());

	}

	@Test
	public void podeAdcionarUmElementoNoInicioDaListaEEleFicaNoInicioDaLista()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaVazia.insiraNoInicio(elementoUm);

		assertEquals(elementoUm, listaVazia.retorneDaPosicao(1));
		assertEquals(elementoUm, listaVazia.retorneDoInicio());

		listaVazia.insiraNaPosicao(elementoUm, 2);
		listaVazia.insiraNaPosicao(elementoDois, 3);
		listaVazia.insiraNaPosicao(elementoTrês, 4);
		listaVazia.insiraNaPosicao(elementoQuatro, 5);

		listaVazia.insiraNoInicio(elementoCinco);

		assertEquals(elementoCinco, listaVazia.retorneDaPosicao(1));
		assertEquals(elementoCinco, listaVazia.retorneDoInicio());

	}

	@Test
	public void seAdcionarUmElementoNoInicioDaListaAPosicaoDosOutrosElementosAumenta()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);
		listaVazia.insiraNaPosicao(elementoTrês, 3);
		listaVazia.insiraNaPosicao(elementoQuatro, 4);

		listaVazia.insiraNoInicio(elementoCinco);

		assertEquals(elementoCinco, listaVazia.retorneDaPosicao(1));
		assertEquals(elementoUm, listaVazia.retorneDaPosicao(2));
		assertEquals(elementoDois, listaVazia.retorneDaPosicao(3));
		assertEquals(elementoTrês, listaVazia.retorneDaPosicao(4));
		assertEquals(elementoQuatro, listaVazia.retorneDaPosicao(5));

	}

	@Test
	public void podeVerificarSeUmElementoPertenceOuNaoALista()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal {

		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);
		listaVazia.insiraNaPosicao(elementoTrês, 3);
		listaVazia.insiraNaPosicao(elementoQuatro, 4);

		assertTrue(listaVazia.pertence(elementoUm));
		assertTrue(listaVazia.pertence(elementoDois));
		assertTrue(listaVazia.pertence(elementoTrês));
		assertTrue(listaVazia.pertence(elementoQuatro));

		assertFalse(listaVazia.pertence(elementoCinco));

	}

	protected void colocarDezElementosNaLista() throws ExcecaoEstruturaCheia,
			ExcecaoPosicaoIlegal {
		for (int i = 1; i <= 10; i++) {
			listaVazia.insiraNaPosicao(elementoUm, i);
		}
	}

	@Test(expected = ExcecaoEstruturaVazia.class)
	public void dadoUmaPosicaoNaoRemoveOElementoQueSeEncontraLaSeAListaEstaVazia()
			throws ExcecaoPosicaoIlegal, ExcecaoEstruturaVazia {

		listaVazia.removaDaPosicao(1);

	}

	@Test(expected = ExcecaoPosicaoIlegal.class)
	public void dadoUmaPosicaoNaoRemoveOElementoQueSeEncontraLaSeAPosicaoEMaiorQueADoUltimoElemento()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);

		listaVazia.removaDaPosicao(3);

	}

	@Test
	public void dadoUmaPosicaoPodeRemoverOElementoDaListaQueSeEncontraNessaPosicao()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {
		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);
		listaVazia.insiraNaPosicao(elementoTrês, 3);
		listaVazia.insiraNaPosicao(elementoQuatro, 4);

		assertEquals(elementoTrês, listaVazia.retorneDaPosicao(3));
		listaVazia.removaDaPosicao(3);
		assertNotSame(elementoTrês, listaVazia.retorneDaPosicao(3));
	}

	@Test
	public void dadoUmaPosicaoSeRemoverOElementoDaListaQueSeEncontraNessaPosicaoAPosicaoDosOutrosElementosDiminui()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);
		listaVazia.insiraNaPosicao(elementoTrês, 3);
		listaVazia.insiraNaPosicao(elementoQuatro, 4);

		listaVazia.removaDaPosicao(1);

		assertEquals(elementoDois, listaVazia.retorneDaPosicao(1));
		assertEquals(elementoTrês, listaVazia.retorneDaPosicao(2));
		assertEquals(elementoQuatro, listaVazia.retorneDaPosicao(3));

	}

	@Test
	public void dadoUmaPosicaoSeRemoverOElementoDaListaQueSeEncontraNessaPosicaoAQuantidadeDeElementosDiminui()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);
		listaVazia.insiraNaPosicao(elementoTrês, 3);
		listaVazia.insiraNaPosicao(elementoQuatro, 4);

		assertEquals(4, listaVazia.retorneTamanho());

		listaVazia.removaDaPosicao(1);

		assertEquals(3, listaVazia.retorneTamanho());

		listaVazia.removaDaPosicao(1);

		assertEquals(2, listaVazia.retorneTamanho());

	}

	@Test
	public void aposAdcionarUmElementoNoFinalDaListaAQuantidadeDeElementosAumenta()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		assertEquals(0, listaVazia.retorneTamanho());

		listaVazia.insiraNoFim(elementoUm);
		listaVazia.insiraNoFim(elementoDois);

		assertEquals(2, listaVazia.retorneTamanho());

		listaVazia.insiraNoFim(elementoTrês);
		listaVazia.insiraNoFim(elementoQuatro);

		assertEquals(4, listaVazia.retorneTamanho());

	}

	@Test
	public void aposAdcionarUmElementoNoInicioDaListaAQuantidadeDeElementosAumenta()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		assertEquals(0, listaVazia.retorneTamanho());

		listaVazia.insiraNoInicio(elementoUm);
		listaVazia.insiraNoInicio(elementoDois);

		assertEquals(2, listaVazia.retorneTamanho());

		listaVazia.insiraNoInicio(elementoTrês);
		listaVazia.insiraNoInicio(elementoQuatro);

		assertEquals(4, listaVazia.retorneTamanho());

	}

	@Test
	public void seInserirUmElementoEmUmaDeterminadaPosicaoAQuantidadeDeElementosAumenta()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		assertEquals(0, listaVazia.retorneTamanho());

		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);

		assertEquals(2, listaVazia.retorneTamanho());

		listaVazia.insiraNaPosicao(elementoTrês, 3);
		listaVazia.insiraNaPosicao(elementoQuatro, 4);

		assertEquals(4, listaVazia.retorneTamanho());

		listaVazia.insiraNaPosicao(elementoCinco, 1);

		assertEquals(5, listaVazia.retorneTamanho());

	}

	@Test
	public void depoisQueRemoverOElementoQueSeEncontraNoFimDaListaAListaDiminuiDeTamanho()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);
		listaVazia.insiraNaPosicao(elementoTrês, 3);
		listaVazia.insiraNaPosicao(elementoQuatro, 4);

		listaVazia.removaDoFim();

		assertEquals(3, listaVazia.retorneTamanho());

		listaVazia.removaDoFim();

		assertEquals(2, listaVazia.retorneTamanho());

	}

	@Test(expected = ExcecaoEstruturaVazia.class)
	public void naoPodeRemoverOElementoQueSeEncontraNoFimDaListaSeElaEstaVazia()
			throws ExcecaoEstruturaVazia {

		listaVazia.removaDoFim();

	}

	@Test
	public void podeRemoverOElementoQueSeEncontraNoFimDaLista()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {
		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);

		listaVazia.removaDoFim();

		assertFalse(listaVazia.pertence(elementoDois));
		assertTrue(listaVazia.pertence(elementoUm));

	}

	@Test
	public void quandoRemoverOElementoQueSeEncontraNoFimDaListaRetornaOElementoQueFoiRemovido()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {
		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);

		assertEquals(elementoDois, listaVazia.removaDoFim());

	}

	@Test
	public void depoisQueRemoverOElementoQueSeEncontraNoInicioDaListaAListaDiminuiDeTamanho()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);
		listaVazia.insiraNaPosicao(elementoTrês, 3);
		listaVazia.insiraNaPosicao(elementoQuatro, 4);

		listaVazia.removaDoInicio();

		assertEquals(3, listaVazia.retorneTamanho());

		listaVazia.removaDoInicio();

		assertEquals(2, listaVazia.retorneTamanho());

	}

	@Test
	public void depoisQueRemoverOElementoQueSeEncontraNoInicioDaListaAPosicaoDosOutrosElementosDiminui()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);
		listaVazia.insiraNaPosicao(elementoTrês, 3);
		listaVazia.insiraNaPosicao(elementoQuatro, 4);

		listaVazia.removaDoInicio();

		assertEquals(elementoDois, listaVazia.retorneDaPosicao(1));
		assertEquals(elementoTrês, listaVazia.retorneDaPosicao(2));
		assertEquals(elementoQuatro, listaVazia.retorneDaPosicao(3));

	}

	@Test(expected = ExcecaoEstruturaVazia.class)
	public void naoPodeRemoverOElementoQueSeEncontraNoInicioDaListaSeElaEstaVazia()
			throws ExcecaoEstruturaVazia {

		listaVazia.removaDoInicio();
	}

	@Test
	public void podeRemoverOElementoQueSeEncontraNoInicioDaLista()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);

		assertEquals(elementoUm, listaVazia.retorneDaPosicao(1));

		listaVazia.removaDoInicio();

		assertEquals(elementoDois, listaVazia.retorneDaPosicao(1));

	}

	@Test
	public void quandoRemoverOElementoQueSeEncontraNoInicioDaListaRetornaOElementoQueFoiRemovido()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);

		assertEquals(elementoUm, listaVazia.removaDoInicio());

	}

	@Test(expected = ExcecaoEstruturaVazia.class)
	public void dadoUmElementoNaoPodeRemoverTodasAsOcorrenciasDeleNaListaSeElaEstaVazia()
			throws ExcecaoEstruturaVazia {

		listaVazia.removaIguais(elementoUm);

	}

	@Test
	public void dadoUmElementoPodeRemoverTodasAsOcorrenciasDeleNaListaEAQuantidadeDeElementosDiminuiDeAcordoComONumeroDeOcorrenciasDoElementoNaLista()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);
		listaVazia.insiraNaPosicao(elementoTrês, 3);
		listaVazia.insiraNaPosicao(elementoUm, 4);

		assertEquals(4, listaVazia.retorneTamanho());

		listaVazia.removaIguais(elementoUm);

		assertEquals(2, listaVazia.retorneTamanho());

	}

	@Test
	public void dadoUmElementoPodeRemoverTodasAsOcorrenciasDeleNaListaEEleNaoPertenceraMaisALista()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);
		listaVazia.insiraNaPosicao(elementoTrês, 3);
		listaVazia.insiraNaPosicao(elementoUm, 4);

		assertTrue(listaVazia.pertence(elementoUm));

		listaVazia.removaIguais(elementoUm).retorneTamanho();

		assertFalse(listaVazia.pertence(elementoUm));

	}

	@Test
	public void dadoUmElementoPodeRemoverTodasAsOcorrenciasDeleNaListaERetornaUmaListaComOsElementosQueForamRemovidos()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		Lista<String> listaRetornada;

		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);
		listaVazia.insiraNaPosicao(elementoTrês, 3);
		listaVazia.insiraNaPosicao(elementoUm, 4);

		listaRetornada = listaVazia.removaIguais(elementoUm);

		assertEquals(2, listaRetornada.retorneTamanho());
		assertEquals(elementoUm, listaRetornada.retorneDaPosicao(1));
		assertEquals(elementoUm, listaRetornada.retorneDaPosicao(2));

	}

	@Test
	public void dadoUmElementoPodeRemoverTodasAsOcorrenciasDeleNaListaSeEleNãoEstaNaListaRetornaUmaListaVazia()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {
		Lista<String> listaRetornada;

		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);
		listaVazia.insiraNaPosicao(elementoTrês, 3);
		listaVazia.insiraNaPosicao(elementoUm, 4);

		listaRetornada = listaVazia.removaIguais(elementoCinco);

		assertTrue(listaRetornada.estaVazia());
	}

	@Test
	public void dadoUmElementoAposRemoverAPrimeiraOcorrenciaDeleNaListaAPosicaoDosOutrosElementosDiminui()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);
		listaVazia.insiraNaPosicao(elementoTrês, 3);
		listaVazia.insiraNaPosicao(elementoUm, 4);

		assertEquals(elementoUm, listaVazia.retorneDaPosicao(1));

		listaVazia.removaIgual(elementoUm);

		assertEquals(elementoDois, listaVazia.retorneDaPosicao(1));
		assertEquals(elementoTrês, listaVazia.retorneDaPosicao(2));
		assertEquals(elementoUm, listaVazia.retorneDaPosicao(3));

	}

	@Test
	public void dadoUmElementoAposRemoverAPrimeiraOcorrenciaDeleNaListaAsOutrasOcorrenciasPermanecem()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);
		listaVazia.insiraNaPosicao(elementoTrês, 3);
		listaVazia.insiraNaPosicao(elementoUm, 4);

		assertEquals(elementoUm, listaVazia.retorneDaPosicao(1));

		listaVazia.removaIgual(elementoUm);

		assertEquals(elementoDois, listaVazia.retorneDaPosicao(1));
		assertTrue(listaVazia.pertence(elementoUm));

	}

	@Test(expected = ExcecaoEstruturaVazia.class)
	public void dadoUmElementoNaoPodeRemoverAPrimeiraOcorrenciaDeleNaListaSeElaEstaVazia()
			throws ExcecaoEstruturaVazia {

		listaVazia.removaIgual(elementoUm);
	}

	@Test
	public void dadoUmElementoPodeRemoverAPrimeiraOcorrenciaDeleNaLista()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);
		listaVazia.insiraNaPosicao(elementoTrês, 3);
		listaVazia.insiraNaPosicao(elementoUm, 4);

		assertEquals(elementoTrês, listaVazia.retorneDaPosicao(3));

		listaVazia.removaIgual(elementoTrês);

		assertEquals(elementoUm, listaVazia.retorneDaPosicao(3));

	}

	@Test
	public void dadoUmElementoPodeRemoverAPrimeiraOcorrenciaDeleNaListaERetornaOProprioElementoRemovido()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);

		assertEquals(elementoDois, listaVazia.removaIgual(elementoDois));

	}

	@Test
	public void dadoUmElementoPodeRemoverAPrimeiraOcorrenciaDeleNaListaSeEleNaoEstaNaListaRetornaNull()
			throws ExcecaoEstruturaVazia, ExcecaoEstruturaCheia,
			ExcecaoPosicaoIlegal {

		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);

		assertNull(listaVazia.removaIgual(elementoTrês));
	}

	@Test
	public void dadoUmElementoSeRemoverAPrimeiraOcorrenciaDeleNaListaAQuantidadeDeElementosNaListaDiminui()
			throws ExcecaoEstruturaVazia, ExcecaoEstruturaCheia,
			ExcecaoPosicaoIlegal {

		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);
		listaVazia.insiraNaPosicao(elementoTrês, 3);
		listaVazia.insiraNaPosicao(elementoUm, 4);

		assertEquals(4, listaVazia.retorneTamanho());

		listaVazia.removaIgual(elementoUm);

		assertEquals(3, listaVazia.retorneTamanho());

		listaVazia.removaIgual(elementoUm);

		assertEquals(2, listaVazia.retorneTamanho());

		listaVazia.removaIgual(elementoDois);

		assertEquals(1, listaVazia.retorneTamanho());

	}

	@Test(expected = ExcecaoEstruturaVazia.class)
	public void dadoUmElementoNaoPodeSubstituirOUltimoElementoDaListaPorEsteSeAListaEstaVazia()
			throws ExcecaoEstruturaVazia {

		listaVazia.substituaDoFim(elementoUm);
	}

	@Test
	public void dadoUmElementoPodeSubstituirOUltimoElementoDaListaPorEste()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);
		listaVazia.insiraNaPosicao(elementoTrês, 3);

		assertEquals(elementoTrês, listaVazia.retorneDoFim());
		listaVazia.substituaDoFim(elementoUm);
		assertEquals(elementoUm, listaVazia.retorneDoFim());
		listaVazia.substituaDoFim(elementoDois);
		assertEquals(elementoDois, listaVazia.retorneDoFim());

	}

	@Test
	public void dadoUmElementoSeSubstituirOUltimoElementoDaListaPorEsteAQuantidadeDeElementosNaoEAlterada()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {
		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);
		listaVazia.insiraNaPosicao(elementoTrês, 3);

		assertEquals(3, listaVazia.retorneTamanho());
		listaVazia.substituaDoFim(elementoUm);
		assertEquals(3, listaVazia.retorneTamanho());

	}

	@Test(expected = ExcecaoEstruturaVazia.class)
	public void dadoUmElementoNaoPodeSubstituirOPrimeiroElementoDaListaPorEsteSeAListaEstaVazia()
			throws ExcecaoEstruturaVazia {

		listaVazia.substituaDoInicio(elementoUm);

	}

	@Test
	public void dadoUmElementoPodeSubstituirOPrimeiroElementoDaListaPorEste()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);
		listaVazia.insiraNaPosicao(elementoTrês, 3);

		assertEquals(elementoUm, listaVazia.retorneDoInicio());
		listaVazia.substituaDoInicio(elementoTrês);
		assertEquals(elementoTrês, listaVazia.retorneDoInicio());
		listaVazia.substituaDoInicio(elementoDois);
		assertEquals(elementoDois, listaVazia.retorneDoInicio());

	}

	@Test
	public void dadoUmElementoSeSubstituirOPrimeiroElementoDaListaPorEsteAQuantidadeDeElementosNaoEAlterada()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);
		listaVazia.insiraNaPosicao(elementoTrês, 3);

		assertEquals(3, listaVazia.retorneTamanho());
		listaVazia.substituaDoInicio(elementoCinco);
		assertEquals(3, listaVazia.retorneTamanho());

	}

	@Test
	public void dadoUmElementoPodeRemoverTodasAsOcorrenciasDeleNaListaERetornaUmaListaComOsElementosQueForamRemovidosComOTamanhoMaximoIgualAoDaListaQueARetornou()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		colocarDezElementosNaLista();
		Lista<String> listaDeElementosRemovidos;

		assertEquals(10, listaVazia.retorneTamanho());

		listaDeElementosRemovidos = listaVazia.removaIguais(elementoUm);

		assertEquals(10, listaDeElementosRemovidos.retorneTamanho());
		assertEquals(0, listaVazia.retorneTamanho());

		assertTrue(listaVazia.estaVazia());

	}

	@Test
	public void dadoUmElementoPodeRetornarUmaListaComTodosOsDadosQueSaoIguaisAEsseElemento()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal {
		Lista<String> listaDeElementosIguaisEncontrados;

		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);
		listaVazia.insiraNaPosicao(elementoTrês, 3);
		listaVazia.insiraNaPosicao(elementoUm, 4);
		listaVazia.insiraNaPosicao(elementoCinco, 5);
		listaVazia.insiraNaPosicao(elementoUm, 6);

		listaDeElementosIguaisEncontrados = listaVazia.temIguais(elementoUm);

		assertTrue(listaDeElementosIguaisEncontrados.pertence(elementoUm));
		assertEquals(3, listaDeElementosIguaisEncontrados.retorneTamanho());

	}

	@Test
	public void dadoUmElementoRetornaUmaListaVaziaSeNaoExisteOcorrenciaDesseElementoNaLista()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal {
		Lista<String> listaDeElementosIguaisEncontrados;

		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);
		listaVazia.insiraNaPosicao(elementoTrês, 3);
		listaVazia.insiraNaPosicao(elementoUm, 4);
		listaVazia.insiraNaPosicao(elementoCinco, 5);
		listaVazia.insiraNaPosicao(elementoUm, 6);

		listaDeElementosIguaisEncontrados = listaVazia
				.temIguais(elementoQuatro);

		assertFalse(listaDeElementosIguaisEncontrados.pertence(elementoQuatro));
		assertTrue(listaDeElementosIguaisEncontrados.estaVazia());

	}

	@Test
	public void dadoUmElementoPodeRetornarAPrimeiraOcorrenciaDesseDadoNaLista()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal {

		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);
		listaVazia.insiraNaPosicao(elementoTrês, 3);
		listaVazia.insiraNaPosicao(elementoUm, 4);
		listaVazia.insiraNaPosicao(elementoCinco, 5);
		listaVazia.insiraNaPosicao(elementoUm, 6);

		assertEquals(elementoUm, listaVazia.temIgual(elementoUm));
		assertEquals(elementoDois, listaVazia.temIgual(elementoDois));
		assertEquals(elementoTrês, listaVazia.temIgual(elementoTrês));
		assertEquals(elementoCinco, listaVazia.temIgual(elementoCinco));

	}

	@Test
	public void dadoUmElementoPodeRetornarAPrimeiraOcorrenciaDesseDadoNaListaSeNaoHouverOcorrenciaDeleRetornaNull()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal {

		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);
		listaVazia.insiraNaPosicao(elementoTrês, 3);
		listaVazia.insiraNaPosicao(elementoUm, 4);
		listaVazia.insiraNaPosicao(elementoCinco, 5);
		listaVazia.insiraNaPosicao(elementoUm, 6);

		assertNull(listaVazia.temIgual(elementoQuatro));
		assertNotNull(listaVazia.temIgual(elementoUm));
	}

	@Test
	public void podeEsvaziarAListaEElaNaoConteraMaisNenhumElementoESeuTamanhoSeraZero()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);
		listaVazia.insiraNaPosicao(elementoTrês, 3);
		listaVazia.insiraNaPosicao(elementoQuatro, 4);
		listaVazia.insiraNaPosicao(elementoCinco, 5);

		assertEquals(5, listaVazia.retorneTamanho());

		listaVazia.esvazie();

		assertEquals(0, listaVazia.retorneTamanho());

		assertFalse(listaVazia.pertence(elementoUm));
		assertFalse(listaVazia.pertence(elementoDois));
		assertFalse(listaVazia.pertence(elementoTrês));
		assertFalse(listaVazia.pertence(elementoQuatro));
		assertFalse(listaVazia.pertence(elementoCinco));

	}

	@Test(expected = ExcecaoPosicaoIlegal.class)
	public void seInserirUmElementEmUmaPosicaoMaiorQueAUltimaPosicaoLivreElaEUmaPosicaooInvalida()
			throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia,
			ExcecaoPosicaoIlegal {

		listaVazia.insiraNaPosicao(elementoTrês, 1);
		listaVazia.insiraNaPosicao(elementoQuatro, 2);
		listaVazia.insiraNaPosicao(elementoQuatro, 4);

	}

	@Test(expected = ExcecaoPosicaoIlegal.class)
	public void seInserirUmElementEmUmaPosicaoMenorZeroElaEUmaPosicaoInvalida()
			throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia,
			ExcecaoPosicaoIlegal {

		listaVazia.insiraNaPosicao(elementoUm, -1);

	}

	@Test(expected = ExcecaoPosicaoIlegal.class)
	public void seTentarObterUmElementoAPartirDaPosicaoZeroLancaUmaExcecaoPosicaoIlegal()
			throws ExcecaoEstruturaVazia, ExcecaoEstruturaCheia,
			ExcecaoPosicaoIlegal {

		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.retorneDaPosicao(0);

	}

	@Test(expected = ExcecaoPosicaoIlegal.class)
	public void seTentarObterUmElementoAPartirDeUmaPosicaoMenorQueZeroLancaUmaExcecaoPosicaoIlegal()
			throws ExcecaoEstruturaVazia, ExcecaoEstruturaCheia,
			ExcecaoPosicaoIlegal {

		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.retorneDaPosicao(-1);

	}

	@Test(expected = ExcecaoPosicaoIlegal.class)
	public void dadoAPosicaoZeroNaoRemoveOElementoQueSeEncontraLaSeAPosicaoEMenorQueZero()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);

		listaVazia.removaDaPosicao(-1);

	}

	@Test(expected = ExcecaoPosicaoIlegal.class)
	public void dadoAPosicaoZeroNaoRemoveOElementoQueSeEncontraLaSeAPosicaoEZero()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);

		listaVazia.removaDaPosicao(0);

	}
	
	@Test
	public void duasListasSaoIguaisSeTodosSeusElementosSaoIguaisEEstaoNaMesmaOrdem() throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal{
		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoDois, 2);
		listaVazia.insiraNaPosicao(elementoTrês, 3);
		listaVazia.insiraNaPosicao(elementoQuatro, 4);
		
		outraListaVazia.insiraNaPosicao(elementoUm, 1);
		outraListaVazia.insiraNaPosicao(elementoDois, 2);
		outraListaVazia.insiraNaPosicao(elementoTrês, 3);
		outraListaVazia.insiraNaPosicao(elementoQuatro, 4);
		
		assertEquals(listaVazia, outraListaVazia);
	}
	
	@Test
	public void duasListasNaoSaoIguaisSeTodosSeusElementosSaoIguaisMasNaoEstaoNaMesmaOrdem() throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal{
		
		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoQuatro, 2);
		listaVazia.insiraNaPosicao(elementoTrês, 3);
		listaVazia.insiraNaPosicao(elementoDois, 4);
		
		outraListaVazia.insiraNaPosicao(elementoUm, 1);
		outraListaVazia.insiraNaPosicao(elementoDois, 2);
		outraListaVazia.insiraNaPosicao(elementoTrês, 3);
		outraListaVazia.insiraNaPosicao(elementoQuatro, 4);
		
		assertFalse(listaVazia.equals(outraListaVazia));
	}
	
	@Test
	public void duasListasNaoSaoIguaisSeNaoPossuemAMesmaQuantidadeDeElementos() throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal{
		listaVazia.insiraNaPosicao(elementoUm, 1);
		listaVazia.insiraNaPosicao(elementoQuatro, 2);
		listaVazia.insiraNaPosicao(elementoTrês, 3);
	
		
		outraListaVazia.insiraNaPosicao(elementoUm, 1);
		outraListaVazia.insiraNaPosicao(elementoDois, 2);
		
		assertFalse(listaVazia.equals(outraListaVazia));
	
	}
	
	@Test
	public void duasListasVaziasSaoIguais(){
		assertEquals(listaVazia, outraListaVazia);
	}

}