package testesDaInfraestruturaDoPainel;

import static org.junit.Assert.assertEquals;
import static edugraf.jadix.fachada.TiposDeComponentesDix.*;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertSame;
import static org.junit.Assert.assertTrue;
import infraestruturaDoComponenteGedix.ComponenteGedix;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import infraestruturaDoPainelDeComponenteGedix.PainelDeComponenteGedix;
import infraestruturaDoPainelDeComponenteGedix.Posicao;
import listasDeTestesDaInfraestruturaDoPainel.ListaDeTestesDoPainelDeComponenteGedix;

import org.junit.Before;
import org.junit.Test;

import tiposDeComponenteGedix.ComponenteGedixNulo;

public class TesteDoPainelDeComponentesGedix implements
		ListaDeTestesDoPainelDeComponenteGedix {

	private PainelDeComponenteGedix painel;


	private ComponenteGedix umComponenteGedix, outroComponenteGedix,
			maisUmComponenteGedix,
			ComponenteGedixNaPosiçãoEsquerda3Topo3,
			ComponenteGedixQueOcupaVáriasPosições;
	
	private ComponenteGedixNulo ComponenteGedixNulo;

	private Posicao esquerda10Topo20, esquerda0eTopo0, esquerda200Topo100,
			esquerda2Topo5, esquerda5Topo10, esquerda7Topo8;

	@Before
	public void criarComponentes() {

		painel = new PainelDeComponenteGedix();


		criarPosições();

		criarComponentesGedix();
	}

	@Test
	public void seForPassadoOComponenteGedixEAPosiçãoDesejadaEleFicaráNaPosiçãoDesejada() {
		painel.adcionar(umComponenteGedix, esquerda10Topo20);
	
		assertEquals(umComponenteGedix, 
				painel.obterComponenteQueSeEncontraNaPosição(esquerda10Topo20));
	}

	@Test
	public void seNãoForPassadaUmaPosiçãoParaOPainelOComponenteGedixFicaráNaPosição0e0IndependenteDaPosiçãoQueElePossua() {
		
		painel.adcionar(ComponenteGedixNaPosiçãoEsquerda3Topo3);

		assertEquals(ComponenteGedixNaPosiçãoEsquerda3Topo3, 
				painel.obterComponenteQueSeEncontraNaPosição(esquerda0eTopo0));
	}

	@Test
	public void podeMudarAPosiçãoDeUmComponenteGedix() {
		painel.adcionar(umComponenteGedix);
		assertTrue(painel.mover(umComponenteGedix, esquerda10Topo20));
		assertEquals(umComponenteGedix, painel
				.obterComponenteQueSeEncontraNaPosição(esquerda10Topo20));
	}

	@Test
	public void sóMudaPosiçãoDeComponentesGedixQueEstãoDentroDoPainel() {
		assertFalse(painel.mover(umComponenteGedix, esquerda10Topo20));
		assertFalse(umComponenteGedix.equals(painel
				.obterComponenteQueSeEncontraNaPosição(esquerda10Topo20)));
	}

	@Test
	public void dadoUmaPosiçãoSabeDizerSeExisteAlguemNessaPosição() {
		painel.adcionar(umComponenteGedix, esquerda10Topo20);

		assertTrue(painel.verificarSeExisteAlguemNaPosição(esquerda10Topo20));
	}

	@Test
	public void dadoUmaPosiçãoSabeDizerSeNãoExisteAlguemNessaPosição() {
		assertFalse(painel.verificarSeExisteAlguemNaPosição(esquerda10Topo20));
	}

	@Test
	public void dadoUmaPosiçãoSabeDizerQuemSeEncontraNessaPosição() {
		painel.adcionar(umComponenteGedix, esquerda10Topo20);

		assertEquals(umComponenteGedix, painel
				.obterComponenteQueSeEncontraNaPosição(esquerda10Topo20));
	}

	@Test
	public void dadoUmaPosiçãoSeNãoTemNinguémLáRetornaUmComponenteGedixNulo() {
		assertEquals(ComponenteGedixNulo, painel
				.obterComponenteQueSeEncontraNaPosição(esquerda10Topo20));
	}

	@Test
	public void seExisteMaisDeUmComponenteGedixEmUmaPosiçãoRetornaOUltimoQueFoiPosicionadoLá() {

		painel.adcionar(umComponenteGedix, esquerda10Topo20);
		painel.adcionar(outroComponenteGedix, esquerda10Topo20);
		painel.adcionar(maisUmComponenteGedix, esquerda10Topo20);

		assertEquals(maisUmComponenteGedix, painel
				.obterComponenteQueSeEncontraNaPosição(esquerda10Topo20));
	}

	@Test
	public void podeRemoverUmComponenteGedixDoPainelSeEleEstáNoPainel() {
		painel.adcionar(umComponenteGedix);
		assertTrue(painel.remover(umComponenteGedix));
	}

	@Test
	public void nãoPodeRemoverUmComponenteGedixDoPainelSeEleNãoEstáNoPainel() {
		assertFalse(painel.remover(umComponenteGedix));
	}

	@Test
	public void apósOComponenteGedixTerSidoRemovidoEleNãoSeEncontraMaisNaquelaPosição() {
		painel.adcionar(umComponenteGedix, esquerda10Topo20);

		assertTrue(painel.remover(umComponenteGedix));
		assertFalse(painel.verificarSeExisteAlguemNaPosição(esquerda10Topo20));
	}

	@Test
	public void seRemoverOComponenteGedixQueEstáEmUmaPosiçãoPodeObterOOutroQueSeEncontraLá() {

		painel.adcionar(umComponenteGedix, esquerda10Topo20);
		painel.adcionar(outroComponenteGedix, esquerda10Topo20);
		painel.adcionar(maisUmComponenteGedix, esquerda10Topo20);

		assertTrue(painel.remover(maisUmComponenteGedix));

		assertEquals(outroComponenteGedix, painel
				.obterComponenteQueSeEncontraNaPosição(esquerda10Topo20));

		assertTrue(painel.remover(outroComponenteGedix));

		assertEquals(umComponenteGedix, painel
				.obterComponenteQueSeEncontraNaPosição(esquerda10Topo20));
	}

	@Test
	public void seMoverOComponenteGedixQueEstáEmUmaPosiçãoPodeObterOOutroQueSeEncontraLá() {
		painel.adcionar(umComponenteGedix, esquerda10Topo20);
		painel.adcionar(outroComponenteGedix, esquerda10Topo20);

		painel.mover(outroComponenteGedix, esquerda200Topo100);

		assertEquals(umComponenteGedix, painel
				.obterComponenteQueSeEncontraNaPosição(esquerda10Topo20));

	}

	@Test
	public void sabeDizerQuantosComponenteGedixEstãoNoPainel() {

		painel.adcionar(umComponenteGedix);
		assertSame(1, painel.obterQuantidadeDeComponentesPosicionados());

		painel.adcionar(outroComponenteGedix);
		assertSame(2, painel.obterQuantidadeDeComponentesPosicionados());

		painel.adcionar(maisUmComponenteGedix);
		assertSame(3, painel.obterQuantidadeDeComponentesPosicionados());

	}

	@Test
	public void seRemoveUmComponenteGedixAQuantidadeDeComponentesGedixNoPainelDiminui() {
		painel.adcionar(umComponenteGedix);
		painel.adcionar(outroComponenteGedix);
		painel.adcionar(maisUmComponenteGedix);

		assertSame(3, painel.obterQuantidadeDeComponentesPosicionados());

		painel.remover(umComponenteGedix);
		assertSame(2, painel.obterQuantidadeDeComponentesPosicionados());
	}

	@Test
	public void podeRemoverTodosOsComponentesGedixDoPainel() {
		painel.adcionar(umComponenteGedix);
		painel.adcionar(outroComponenteGedix);
		painel.adcionar(maisUmComponenteGedix);
		painel.removerTodos();
		assertSame(0, painel.obterQuantidadeDeComponentesPosicionados());
	}

	@Test
	public void podeObterOComponenteGedixAtravesDeQualquerPosiçãoQueEleOcupe() {
		painel.adcionar(ComponenteGedixQueOcupaVáriasPosições);

		assertEquals(ComponenteGedixQueOcupaVáriasPosições, painel
				.obterComponenteQueSeEncontraNaPosição(esquerda2Topo5));
		assertEquals(ComponenteGedixQueOcupaVáriasPosições, painel
				.obterComponenteQueSeEncontraNaPosição(esquerda5Topo10));
		assertEquals(ComponenteGedixQueOcupaVáriasPosições, painel
				.obterComponenteQueSeEncontraNaPosição(esquerda7Topo8));
		assertEquals(ComponenteGedixQueOcupaVáriasPosições, painel
				.obterComponenteQueSeEncontraNaPosição(esquerda0eTopo0));

	}

	private void criarComponentesGedix(){
		
		umComponenteGedix = Fabrica.obterComponenteGedixDoTipo(BOTÃO, 
				Fabrica.obterRetanguloPosicionavel(Fabrica
						.obterRetangulo(Fabrica.obterDimensão(10, 20))));
		
		outroComponenteGedix = Fabrica.obterComponenteGedixDoTipo(BOTÃO, 
				Fabrica.obterRetanguloPosicionavel(Fabrica
						.obterRetangulo(Fabrica.obterDimensão(10, 20))));
		
		maisUmComponenteGedix = Fabrica.obterComponenteGedixDoTipo(BOTÃO, 
				Fabrica.obterRetanguloPosicionavel(Fabrica
						.obterRetangulo(Fabrica.obterDimensão(10, 20))));
		
		ComponenteGedixNaPosiçãoEsquerda3Topo3 = Fabrica.obterComponenteGedixDoTipo(BOTÃO, 
				Fabrica.obterRetanguloPosicionavel(Fabrica
						.obterRetangulo(Fabrica.obterDimensão(10, 20))));
		ComponenteGedixNaPosiçãoEsquerda3Topo3
		       .definirPosiçãoDeOrigem(Fabrica.obterPosição(3, 3));
		
		ComponenteGedixQueOcupaVáriasPosições =  Fabrica.obterComponenteGedixDoTipo(BOTÃO, 
				Fabrica.obterRetanguloPosicionavel(Fabrica
						.obterRetangulo(Fabrica.obterDimensão(100, 200))));
		
		ComponenteGedixNulo = Fabrica.obterComponenteGedixNulo();
		
	}

	private void criarPosições() {
		esquerda10Topo20 = Fabrica.obterPosição(10, 20);

		esquerda0eTopo0 = Fabrica.obterPosição(0, 0);

		esquerda200Topo100 = Fabrica.obterPosição(200, 100);

		esquerda2Topo5 = Fabrica.obterPosição(2, 5);

		esquerda5Topo10 = Fabrica.obterPosição(5, 10);

		esquerda7Topo8 = Fabrica.obterPosição(7, 8);
	}

}