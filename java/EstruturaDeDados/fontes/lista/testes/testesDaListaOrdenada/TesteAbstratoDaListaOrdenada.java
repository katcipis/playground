package lista.testes.testesDaListaOrdenada;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertNull;
import static org.junit.Assert.assertTrue;
import lista.listasDeTestes.listasDeTestesDasListasOrdenadas.ListaDeTestesDaListaOrdenada;
import ine5384.excecoes.ExcecaoEstruturaCheia;
import ine5384.excecoes.ExcecaoEstruturaVazia;
import ine5384.excecoes.ExcecaoPosicaoIlegal;
import ine5384.lineares.ListaClassificada;
import infraestrutura.pessoa.Pessoa;

import org.junit.Before;
import org.junit.Test;

public abstract class TesteAbstratoDaListaOrdenada implements ListaDeTestesDaListaOrdenada {

	protected Pessoa joaoDe17Anos, marcioDe20Anos, melanieDe17Anos,
			outroMarcioDe20Anos, tiagoDe21Anos;

	protected ListaClassificada<Pessoa> listaOrdenadaVazia, outraListaOrdenadaVazia;

	@Before
	public void criarComponentes() {
		joaoDe17Anos = new Pessoa("João", 17);
		marcioDe20Anos = new Pessoa("Márcio", 20);
		outroMarcioDe20Anos = new Pessoa("Márcio", 20);
		melanieDe17Anos = new Pessoa("Melanie", 17);
		tiagoDe21Anos = new Pessoa("Tiago", 21);

		listaOrdenadaVazia = criarListaVazia();
		outraListaOrdenadaVazia = criarListaVazia();
	}

	protected abstract ListaClassificada<Pessoa> criarListaVazia();

	@Test
	public void aposInserirUmElementoSabeQueElePertenceALista()
			throws ExcecaoEstruturaCheia {
		assertFalse(listaOrdenadaVazia.pertence(joaoDe17Anos));
		listaOrdenadaVazia.insira(joaoDe17Anos);
		assertTrue(listaOrdenadaVazia.pertence(joaoDe17Anos));
	}

	@Test
	public void sabeQuandoEstaVazia() {
		assertTrue(listaOrdenadaVazia.estaVazia());
	}

	@Test
	public void inserirUmElementoNaListaVazia() throws ExcecaoEstruturaCheia,
			ExcecaoEstruturaVazia, ExcecaoPosicaoIlegal {
		listaOrdenadaVazia.insira(joaoDe17Anos);
		assertEquals(joaoDe17Anos, listaOrdenadaVazia.retorneDaPosicao(1));
		assertEquals(1, listaOrdenadaVazia.retorneTamanho());
	}

	@Test
	public void inserirUmElementoNaListaQueJaPossuiUmElemento()
			throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia,
			ExcecaoPosicaoIlegal {

		listaOrdenadaVazia.insira(marcioDe20Anos);
		listaOrdenadaVazia.insira(melanieDe17Anos);

		assertEquals(marcioDe20Anos, listaOrdenadaVazia.retorneDaPosicao(2));
		assertEquals(melanieDe17Anos, listaOrdenadaVazia.retorneDaPosicao(1));

		assertEquals(2, listaOrdenadaVazia.retorneTamanho());
	}

	@Test
	public void naoImportaAOrdemQueSaoInseridosOsElementosFicamEmOrdenadosEmOrdemCrescenteNaListaComUmElemento()
			throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia,
			ExcecaoPosicaoIlegal {

		listaOrdenadaVazia.insira(melanieDe17Anos);
		listaOrdenadaVazia.insira(marcioDe20Anos);

		assertEquals(marcioDe20Anos, listaOrdenadaVazia.retorneDaPosicao(2));
		assertEquals(melanieDe17Anos, listaOrdenadaVazia.retorneDaPosicao(1));

		assertEquals(2, listaOrdenadaVazia.retorneTamanho());
	}

	@Test
	public void naoImportaAOrdemQueSaoInseridosOsElementosFicamEmOrdenadosEmOrdemCrescenteNaListaComMaisDeUmElemento()
			throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia,
			ExcecaoPosicaoIlegal {

		listaOrdenadaVazia.insira(joaoDe17Anos);
		listaOrdenadaVazia.insira(tiagoDe21Anos);
		listaOrdenadaVazia.insira(marcioDe20Anos);
		listaOrdenadaVazia.insira(melanieDe17Anos);

		assertEquals(joaoDe17Anos, listaOrdenadaVazia.retorneDaPosicao(1));
		assertEquals(melanieDe17Anos, listaOrdenadaVazia.retorneDaPosicao(2));
		assertEquals(marcioDe20Anos, listaOrdenadaVazia.retorneDaPosicao(3));
		assertEquals(tiagoDe21Anos, listaOrdenadaVazia.retorneDaPosicao(4));

		assertEquals(4, listaOrdenadaVazia.retorneTamanho());
	}

	@Test
	public void seOElementoQueEstaSendoInseridoEIgualAUmJaExistenteNaListaEleFicaraAntesDoQueJaEstaNaLista()
			throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia,
			ExcecaoPosicaoIlegal {

		listaOrdenadaVazia.insira(joaoDe17Anos);
		listaOrdenadaVazia.insira(tiagoDe21Anos);
		listaOrdenadaVazia.insira(marcioDe20Anos);
		listaOrdenadaVazia.insira(melanieDe17Anos);

		listaOrdenadaVazia.insira(outroMarcioDe20Anos);

		assertEquals(joaoDe17Anos, listaOrdenadaVazia.retorneDaPosicao(1));
		assertEquals(melanieDe17Anos, listaOrdenadaVazia.retorneDaPosicao(2));
		assertEquals(outroMarcioDe20Anos, listaOrdenadaVazia.retorneDaPosicao(3));
		assertEquals(marcioDe20Anos, listaOrdenadaVazia.retorneDaPosicao(4));
		assertEquals(tiagoDe21Anos, listaOrdenadaVazia.retorneDaPosicao(5));
	}

	@Test
	public void sabeQuandoNaoEstaVazia() throws ExcecaoEstruturaCheia,
			ExcecaoPosicaoIlegal {
		listaOrdenadaVazia.insira(joaoDe17Anos);
		assertFalse(listaOrdenadaVazia.estaVazia());
	}

	@Test
	public void podeRetornarOPrimeiroElementoDaLista()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaOrdenadaVazia.insira(joaoDe17Anos);
		listaOrdenadaVazia.insira(melanieDe17Anos);

		assertEquals(joaoDe17Anos, listaOrdenadaVazia.retorneDoInicio());

	}

	@Test
	public void podeRetornarOUltimoElementoDaLista()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaOrdenadaVazia.insira(joaoDe17Anos);
		listaOrdenadaVazia.insira(melanieDe17Anos);
		listaOrdenadaVazia.insira(tiagoDe21Anos);

		assertEquals(tiagoDe21Anos, listaOrdenadaVazia.retorneDoFim());

	}

	@Test(expected = ExcecaoEstruturaVazia.class)
	public void sePedirParaRetornarOPrimeiroElementoDeUmaListaVaziaLancaUmaExcecaoEstruturaVazia()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaOrdenadaVazia.retorneDoInicio();

	}

	@Test(expected = ExcecaoEstruturaVazia.class)
	public void sePedirParaRetornarOUltimoElementoDeUmaListaVaziaLancaUmaExcecaoEstruturaVazia()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaOrdenadaVazia.retorneDoFim();

	}

	@Test
	public void sabeOSeuTamanho() throws ExcecaoEstruturaCheia,
			ExcecaoPosicaoIlegal {
		assertEquals(0, listaOrdenadaVazia.retorneTamanho());

		listaOrdenadaVazia.insira(joaoDe17Anos);
		listaOrdenadaVazia.insira(joaoDe17Anos);
		listaOrdenadaVazia.insira(joaoDe17Anos);

		assertEquals(3, listaOrdenadaVazia.retorneTamanho());

		listaOrdenadaVazia.insira(joaoDe17Anos);
		listaOrdenadaVazia.insira(joaoDe17Anos);
		listaOrdenadaVazia.insira(joaoDe17Anos);

		assertEquals(6, listaOrdenadaVazia.retorneTamanho());

	}

	@Test
	public void sabeQualNaoEOSeuTamanho() throws ExcecaoEstruturaCheia,
			ExcecaoPosicaoIlegal {
		assertFalse(1 == listaOrdenadaVazia.retorneTamanho());

		listaOrdenadaVazia.insira(joaoDe17Anos);
		listaOrdenadaVazia.insira(joaoDe17Anos);
		listaOrdenadaVazia.insira(joaoDe17Anos);

		assertFalse(2 == listaOrdenadaVazia.retorneTamanho());
		assertFalse(4 == listaOrdenadaVazia.retorneTamanho());

	}

	@Test
	public void podeObterUmElementoAPartirDaSuaPosicao()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaOrdenadaVazia.insira(joaoDe17Anos);
		listaOrdenadaVazia.insira(melanieDe17Anos);
		listaOrdenadaVazia.insira(tiagoDe21Anos);

		assertEquals(joaoDe17Anos, listaOrdenadaVazia.retorneDaPosicao(1));
		assertEquals(melanieDe17Anos, listaOrdenadaVazia.retorneDaPosicao(2));
		assertEquals(tiagoDe21Anos, listaOrdenadaVazia.retorneDaPosicao(3));
	}

	@Test(expected = ExcecaoEstruturaVazia.class)
	public void seTentarObterUmElementoAPartirDaSuaPosicaoDeUmaListaVaziaLancaUmaExcecaoEstruturaVazia()
			throws ExcecaoPosicaoIlegal, ExcecaoEstruturaVazia {

		listaOrdenadaVazia.retorneDaPosicao(1);

	}

	@Test(expected = ExcecaoPosicaoIlegal.class)
	public void seTentarObterUmElementoAPartirDeUmaPosicaoMaiorQueDoUltimoElementoLancaUmaExcecaoPosicaoIlegal()
			throws ExcecaoEstruturaVazia, ExcecaoEstruturaCheia,
			ExcecaoPosicaoIlegal {

		listaOrdenadaVazia.insira(joaoDe17Anos);
		listaOrdenadaVazia.insira(melanieDe17Anos);
		listaOrdenadaVazia.insira(tiagoDe21Anos);

		listaOrdenadaVazia.retorneDaPosicao(4);

	}

	@Test
	public void podeVerificarSeUmElementoPertenceOuNaoALista()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal {

		listaOrdenadaVazia.insira(joaoDe17Anos);
		listaOrdenadaVazia.insira(melanieDe17Anos);
		listaOrdenadaVazia.insira(tiagoDe21Anos);

		assertTrue(listaOrdenadaVazia.pertence(joaoDe17Anos));
		assertTrue(listaOrdenadaVazia.pertence(melanieDe17Anos));
		assertTrue(listaOrdenadaVazia.pertence(tiagoDe21Anos));

	}
	
	@Test(expected = ExcecaoEstruturaVazia.class)
	public void dadoUmaPosicaoNaoRemoveOElementoQueSeEncontraLaSeAListaEstaVazia()
			throws ExcecaoPosicaoIlegal, ExcecaoEstruturaVazia {

		listaOrdenadaVazia.removaDaPosicao(1);

	}
	
	@Test(expected = ExcecaoPosicaoIlegal.class)
	public void dadoUmaPosicaoNaoRemoveOElementoQueSeEncontraLaSeAPosicaoEMaiorQueADoUltimoElemento()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaOrdenadaVazia.insira(joaoDe17Anos);
		listaOrdenadaVazia.insira(melanieDe17Anos);
		listaOrdenadaVazia.insira(tiagoDe21Anos);

		listaOrdenadaVazia.removaDaPosicao(4);

	}
	
	@Test
	public void dadoUmaPosicaoPodeRemoverOElementoDaListaQueSeEncontraNessaPosicao()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {
		
		listaOrdenadaVazia.insira(joaoDe17Anos);
		listaOrdenadaVazia.insira(melanieDe17Anos);
		listaOrdenadaVazia.insira(tiagoDe21Anos);

		assertEquals(melanieDe17Anos, listaOrdenadaVazia.retorneDaPosicao(2));
		listaOrdenadaVazia.removaDaPosicao(2);
		assertEquals(tiagoDe21Anos, listaOrdenadaVazia.retorneDaPosicao(2));
	}

	@Test
	public void dadoUmaPosicaoSeRemoverOElementoDaListaQueSeEncontraNessaPosicaoAPosicaoDosOutrosElementosDiminui()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaOrdenadaVazia.insira(joaoDe17Anos);
		listaOrdenadaVazia.insira(melanieDe17Anos);
		listaOrdenadaVazia.insira(tiagoDe21Anos);

		assertEquals(joaoDe17Anos, listaOrdenadaVazia.retorneDaPosicao(1));
		assertEquals(melanieDe17Anos, listaOrdenadaVazia.retorneDaPosicao(2));
		assertEquals(tiagoDe21Anos, listaOrdenadaVazia.retorneDaPosicao(3));
		
		listaOrdenadaVazia.removaDaPosicao(1);
		
		assertEquals(melanieDe17Anos, listaOrdenadaVazia.retorneDaPosicao(1));
		assertEquals(tiagoDe21Anos, listaOrdenadaVazia.retorneDaPosicao(2));

	}

	@Test
	public void dadoUmaPosicaoSeRemoverOElementoDaListaQueSeEncontraNessaPosicaoAQuantidadeDeElementosDiminui()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaOrdenadaVazia.insira(joaoDe17Anos);
		listaOrdenadaVazia.insira(melanieDe17Anos);
		listaOrdenadaVazia.insira(tiagoDe21Anos);

		assertEquals(3, listaOrdenadaVazia.retorneTamanho());

		listaOrdenadaVazia.removaDaPosicao(1);

		assertEquals(2, listaOrdenadaVazia.retorneTamanho());

		listaOrdenadaVazia.removaDaPosicao(1);

		assertEquals(1, listaOrdenadaVazia.retorneTamanho());

	}
	
	@Test
	public void depoisQueRemoverOElementoQueSeEncontraNoFimDaListaAListaDiminuiDeTamanho()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaOrdenadaVazia.insira(joaoDe17Anos);
		listaOrdenadaVazia.insira(melanieDe17Anos);
		listaOrdenadaVazia.insira(tiagoDe21Anos);

		listaOrdenadaVazia.removaDoFim();

		assertEquals(2, listaOrdenadaVazia.retorneTamanho());

		listaOrdenadaVazia.removaDoFim();

		assertEquals(1, listaOrdenadaVazia.retorneTamanho());

	}

	@Test(expected = ExcecaoEstruturaVazia.class)
	public void naoPodeRemoverOElementoQueSeEncontraNoFimDaListaSeElaEstaVazia()
			throws ExcecaoEstruturaVazia {

		listaOrdenadaVazia.removaDoFim();

	}

	@Test
	public void podeRemoverOElementoQueSeEncontraNoFimDaLista()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {
		
		listaOrdenadaVazia.insira(joaoDe17Anos);
		listaOrdenadaVazia.insira(melanieDe17Anos);
		listaOrdenadaVazia.insira(tiagoDe21Anos);

		listaOrdenadaVazia.removaDoFim();

		assertFalse(listaOrdenadaVazia.pertence(tiagoDe21Anos));
		assertTrue(listaOrdenadaVazia.pertence(melanieDe17Anos));
		assertTrue(listaOrdenadaVazia.pertence(joaoDe17Anos));

	}
	
	@Test
	public void quandoRemoverOElementoQueSeEncontraNoFimDaListaRetornaOElementoQueFoiRemovido()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {
		
		listaOrdenadaVazia.insira(joaoDe17Anos);
		listaOrdenadaVazia.insira(melanieDe17Anos);
		listaOrdenadaVazia.insira(tiagoDe21Anos);

		assertEquals(tiagoDe21Anos, listaOrdenadaVazia.removaDoFim());

	}

	@Test
	public void depoisQueRemoverOElementoQueSeEncontraNoInicioDaListaAListaDiminuiDeTamanho()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaOrdenadaVazia.insira(joaoDe17Anos);
		listaOrdenadaVazia.insira(melanieDe17Anos);
		listaOrdenadaVazia.insira(tiagoDe21Anos);

		listaOrdenadaVazia.removaDoInicio();

		assertEquals(2, listaOrdenadaVazia.retorneTamanho());

		listaOrdenadaVazia.removaDoInicio();

		assertEquals(1, listaOrdenadaVazia.retorneTamanho());

	}
	
	@Test
	public void depoisQueRemoverOElementoQueSeEncontraNoInicioDaListaAPosicaoDosOutrosElementosDiminui()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaOrdenadaVazia.insira(joaoDe17Anos);
		listaOrdenadaVazia.insira(melanieDe17Anos);
		listaOrdenadaVazia.insira(tiagoDe21Anos);

		listaOrdenadaVazia.removaDoInicio();

		assertEquals(melanieDe17Anos, listaOrdenadaVazia.retorneDaPosicao(1));
		assertEquals(tiagoDe21Anos, listaOrdenadaVazia.retorneDaPosicao(2));
	

	}

	@Test(expected = ExcecaoEstruturaVazia.class)
	public void naoPodeRemoverOElementoQueSeEncontraNoInicioDaListaSeElaEstaVazia()
			throws ExcecaoEstruturaVazia {

		listaOrdenadaVazia.removaDoInicio();
	}

	@Test
	public void podeRemoverOElementoQueSeEncontraNoInicioDaLista()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaOrdenadaVazia.insira(joaoDe17Anos);
		listaOrdenadaVazia.insira(melanieDe17Anos);
		listaOrdenadaVazia.insira(tiagoDe21Anos);

		assertEquals(joaoDe17Anos, listaOrdenadaVazia.retorneDaPosicao(1));

		listaOrdenadaVazia.removaDoInicio();

		assertEquals(melanieDe17Anos, listaOrdenadaVazia.retorneDaPosicao(1));

	}
	
	@Test
	public void quandoRemoverOElementoQueSeEncontraNoInicioDaListaRetornaOElementoQueFoiRemovido()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaOrdenadaVazia.insira(joaoDe17Anos);
		listaOrdenadaVazia.insira(melanieDe17Anos);
		listaOrdenadaVazia.insira(tiagoDe21Anos);

		assertEquals(joaoDe17Anos, listaOrdenadaVazia.removaDoInicio());

	}

	@Test
	public void dadoUmElementoPodeRetornarUmaListaComTodosOsDadosQueSaoIguaisAEsseElemento()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal {
		
		ListaClassificada<Pessoa> listaDeElementosIguaisEncontrados;

		listaOrdenadaVazia.insira(joaoDe17Anos);
		listaOrdenadaVazia.insira(marcioDe20Anos);
		listaOrdenadaVazia.insira(melanieDe17Anos);
		listaOrdenadaVazia.insira(marcioDe20Anos);
		listaOrdenadaVazia.insira(tiagoDe21Anos);
		listaOrdenadaVazia.insira(marcioDe20Anos);
		listaOrdenadaVazia.insira(outroMarcioDe20Anos);

		listaDeElementosIguaisEncontrados = listaOrdenadaVazia.temIguais(marcioDe20Anos);

		assertTrue(listaDeElementosIguaisEncontrados.pertence(marcioDe20Anos));
		assertEquals(3, listaDeElementosIguaisEncontrados.retorneTamanho());

	}
	
	@Test
	public void dadoUmElementoRetornaUmaListaVaziaSeNaoExisteOcorrenciaDesseElementoNaLista()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal {
		ListaClassificada<Pessoa> listaDeElementosIguaisEncontrados;

		listaOrdenadaVazia.insira(marcioDe20Anos);
		listaOrdenadaVazia.insira(melanieDe17Anos);
		listaOrdenadaVazia.insira(marcioDe20Anos);
		listaOrdenadaVazia.insira(tiagoDe21Anos);
		listaOrdenadaVazia.insira(marcioDe20Anos);
		listaOrdenadaVazia.insira(outroMarcioDe20Anos);

		listaDeElementosIguaisEncontrados = listaOrdenadaVazia
				.temIguais(joaoDe17Anos);

		assertTrue(listaDeElementosIguaisEncontrados.estaVazia());

	}
	
	@Test
	public void dadoUmElementoPodeRetornarAPrimeiraOcorrenciaDesseDadoNaLista()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal {

		listaOrdenadaVazia.insira(marcioDe20Anos);
		
		assertEquals(marcioDe20Anos, listaOrdenadaVazia.temIgual(marcioDe20Anos));
		
		listaOrdenadaVazia.insira(melanieDe17Anos);
		listaOrdenadaVazia.insira(marcioDe20Anos);
		listaOrdenadaVazia.insira(tiagoDe21Anos);
		listaOrdenadaVazia.insira(marcioDe20Anos);
		listaOrdenadaVazia.insira(outroMarcioDe20Anos);

		assertEquals(melanieDe17Anos, listaOrdenadaVazia.temIgual(melanieDe17Anos));
		assertEquals(tiagoDe21Anos, listaOrdenadaVazia.temIgual(tiagoDe21Anos));
		assertEquals(outroMarcioDe20Anos, listaOrdenadaVazia.temIgual(outroMarcioDe20Anos));

	}

	@Test
	public void dadoUmElementoPodeRetornarAPrimeiraOcorrenciaDesseDadoNaListaSeNaoHouverOcorrenciaDeleRetornaNull()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal {
		
		assertNull(listaOrdenadaVazia.temIgual(joaoDe17Anos));
		
		listaOrdenadaVazia.insira(marcioDe20Anos);
		listaOrdenadaVazia.insira(melanieDe17Anos);
		listaOrdenadaVazia.insira(marcioDe20Anos);
		listaOrdenadaVazia.insira(tiagoDe21Anos);
		listaOrdenadaVazia.insira(marcioDe20Anos);
		listaOrdenadaVazia.insira(outroMarcioDe20Anos);

		assertNull(listaOrdenadaVazia.temIgual(joaoDe17Anos));
		assertNotNull(listaOrdenadaVazia.temIgual(tiagoDe21Anos));
	}
	
	@Test
	public void podeEsvaziarAListaEElaNaoConteraMaisNenhumElementoESeuTamanhoSeraZero()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia {

		listaOrdenadaVazia.insira(marcioDe20Anos);
		listaOrdenadaVazia.insira(melanieDe17Anos);
		listaOrdenadaVazia.insira(joaoDe17Anos);
		listaOrdenadaVazia.insira(tiagoDe21Anos);
		listaOrdenadaVazia.insira(outroMarcioDe20Anos);

		assertEquals(5, listaOrdenadaVazia.retorneTamanho());

		listaOrdenadaVazia.esvazie();

		assertEquals(0, listaOrdenadaVazia.retorneTamanho());

		assertFalse(listaOrdenadaVazia.pertence(marcioDe20Anos));
		assertFalse(listaOrdenadaVazia.pertence(melanieDe17Anos));
		assertFalse(listaOrdenadaVazia.pertence(joaoDe17Anos));
		assertFalse(listaOrdenadaVazia.pertence(tiagoDe21Anos));
		assertFalse(listaOrdenadaVazia.pertence(outroMarcioDe20Anos));

	}
	
	@Test
	public void verificarSeTemIgualEmUmaListaComUmElemento() throws ExcecaoEstruturaCheia{
		listaOrdenadaVazia.insira(marcioDe20Anos);
		assertEquals(marcioDe20Anos, listaOrdenadaVazia.temIgual(marcioDe20Anos));
	}
	
	@Test
	public void verificarSeTemIguaisEmUmaListaComUmElemento() throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia{
		ListaClassificada<Pessoa> listaRetornada;
		listaOrdenadaVazia.insira(marcioDe20Anos);
		
		listaRetornada = listaOrdenadaVazia.temIguais(marcioDe20Anos);
		assertEquals(1,listaRetornada.retorneTamanho());
		assertEquals(marcioDe20Anos, listaRetornada.retorneDoInicio());
	}
	
	@Test
	public void retorneDoFimEmUmaListaComUmElemento() throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia{
		listaOrdenadaVazia.insira(marcioDe20Anos);
		assertEquals(marcioDe20Anos, listaOrdenadaVazia.retorneDoFim());
	}
	
	@Test
	public void retorneDoInicioEmUmaListaComUmElemento() throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia{
		listaOrdenadaVazia.insira(marcioDe20Anos);
		assertEquals(marcioDe20Anos, listaOrdenadaVazia.retorneDoInicio());
	}
	
	@Test
	public void retorneDaPosicaoEmUmaListaComUmElemento() throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia, ExcecaoPosicaoIlegal{
		listaOrdenadaVazia.insira(marcioDe20Anos);
		assertEquals(marcioDe20Anos, listaOrdenadaVazia.retorneDaPosicao(1));
	}
	
	@Test
	public void removaDoFimEmUmaListaComUmElemento() throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia, ExcecaoPosicaoIlegal{
		listaOrdenadaVazia.insira(marcioDe20Anos);
		assertEquals(marcioDe20Anos, listaOrdenadaVazia.removaDoFim());
		assertTrue(listaOrdenadaVazia.estaVazia());
	}
	
	@Test
	public void removaDoInicioEmUmaListaComUmElemento() throws ExcecaoEstruturaVazia, ExcecaoEstruturaCheia{
		listaOrdenadaVazia.insira(marcioDe20Anos);
		assertEquals(marcioDe20Anos, listaOrdenadaVazia.removaDoInicio());
		assertTrue(listaOrdenadaVazia.estaVazia());
	}
	
	@Test
	public void removaDaPosicaoEmUmaListaComUmElemento() throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia, ExcecaoPosicaoIlegal{
		listaOrdenadaVazia.insira(marcioDe20Anos);
		assertEquals(marcioDe20Anos, listaOrdenadaVazia.removaDaPosicao(1));
		assertTrue(listaOrdenadaVazia.estaVazia());
	}
	
	@Test
	public void pertenceAListaComUmElemento() throws ExcecaoEstruturaCheia{
		listaOrdenadaVazia.insira(marcioDe20Anos);
		assertTrue(listaOrdenadaVazia.pertence(marcioDe20Anos));
	}
	
	@Test
	public void duasListasSaoIguaisSeTodosSeusElementosSaoIguais() throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal{
		listaOrdenadaVazia.insira(marcioDe20Anos);
		listaOrdenadaVazia.insira(melanieDe17Anos);
		listaOrdenadaVazia.insira(joaoDe17Anos);
		listaOrdenadaVazia.insira(tiagoDe21Anos);
		
		outraListaOrdenadaVazia.insira(marcioDe20Anos);
		outraListaOrdenadaVazia.insira(melanieDe17Anos);
		outraListaOrdenadaVazia.insira(joaoDe17Anos);
		outraListaOrdenadaVazia.insira(tiagoDe21Anos);
		
		assertEquals(listaOrdenadaVazia, outraListaOrdenadaVazia);
	}
	
	
	@Test
	public void duasListasNaoSaoIguaisSeNaoPossuemAMesmaQuantidadeDeElementos() throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal{
		listaOrdenadaVazia.insira(marcioDe20Anos);
		listaOrdenadaVazia.insira(melanieDe17Anos);
		
		outraListaOrdenadaVazia.insira(marcioDe20Anos);
		outraListaOrdenadaVazia.insira(melanieDe17Anos);
		outraListaOrdenadaVazia.insira(joaoDe17Anos);
	
		
		assertFalse(listaOrdenadaVazia.equals(outraListaOrdenadaVazia));
	
	}
	
	@Test
	public void duasListasVaziasSaoIguais(){
		assertEquals(listaOrdenadaVazia, outraListaOrdenadaVazia);
	}

}
