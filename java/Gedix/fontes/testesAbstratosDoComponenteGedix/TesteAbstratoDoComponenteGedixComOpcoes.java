package testesAbstratosDoComponenteGedix;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertSame;
import static org.junit.Assert.assertTrue;
import infraestruturaDoComponenteGedix.Opcao;
import infraestruturaDoComponenteGedix.ComponenteGedixComOpcoes;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import infraestruturaDoTransformadorParaXML.TransformavelEmXMLComOpcoes;
import listasDeTestesDoComponenteGedix.ListaDeTestesDoComponenteGedixComOpcoes;

import org.junit.Before;
import org.junit.Test;

public abstract class TesteAbstratoDoComponenteGedixComOpcoes extends
		TesteAbstratoDoComponenteGedix implements
		ListaDeTestesDoComponenteGedixComOpcoes {

	protected ComponenteGedixComOpcoes componenteGedixComNenhumaOpção,
			componenteGedixComQuatroOpções;

	private Opcao opção1, opção2, opção3, opção4, opção5, opçãoNula;

	public abstract void criarComponenteGedixComQuatroOpções();

	public abstract void criarComponenteGedixComListaDeOpçõesVazia();

	@Before
	public void antesDosTestesDoRetânguloDixComListaDeOpções() {

		criarComponenteGedixComQuatroOpções();

		criarComponenteGedixComListaDeOpçõesVazia();

		criarOpções();

		componenteGedixComQuatroOpções.adcionarOpção(opção1);
		componenteGedixComQuatroOpções.adcionarOpção(opção2);
		componenteGedixComQuatroOpções.adcionarOpção(opção3);
		componenteGedixComQuatroOpções.adcionarOpção(opção4);
	}

	@Test
	public void oConjuntoDeOpcoesInicialÉVazio() {
		assertSame(0, componenteGedixComNenhumaOpção.obterQuantidadeDeOpções());
	}

	@Test
	public void podeRemoverTodasAsOpções() {
		componenteGedixComQuatroOpções.removerTodasAsOpções();
		assertSame(0, componenteGedixComNenhumaOpção.obterQuantidadeDeOpções());
	}

	@Test
	public void oIndiceDaPrimeiraOpçãoÉUm() {
		assertEquals(opção1, componenteGedixComQuatroOpções.obterOpção(1));

	}

	@Test
	public void podeAdcionarUmaOpção() {
		componenteGedixComQuatroOpções.adcionarOpção(opção5);
		
		assertEquals(opção5, componenteGedixComQuatroOpções.obterOpção(5));
	}

	

	@Test
	public void podeObterUmaOpçãoAPartirDoSeuIndice() {
		assertEquals(opção1, componenteGedixComQuatroOpções.obterOpção(1));
		assertEquals(opção2, componenteGedixComQuatroOpções.obterOpção(2));
		assertEquals(opção3, componenteGedixComQuatroOpções.obterOpção(3));
		assertEquals(opção4, componenteGedixComQuatroOpções.obterOpção(4));
	}

	@Test
	public void podeRemoverUmaOpçãoAPartirDoSeuIndice() {
		assertTrue(componenteGedixComQuatroOpções.removerOpção(1));
		assertFalse(componenteGedixComQuatroOpções.possuiAOpção(opção1));
	}


	@Test
	public void quandoAdcionadaUmaOpçãoElaFicaráNoFimDoConjunto() {
		componenteGedixComQuatroOpções.adcionarOpção(opção5);
		assertEquals(opção5, componenteGedixComQuatroOpções.obterOpção(5));
	}

	@Test
	public void seTentarObterUmaOpçãoQueNãoExisteRetornaUmaOpçãoNula() {
		assertEquals(opçãoNula, componenteGedixComQuatroOpções
				.obterOpção(0));
		assertEquals(opçãoNula, componenteGedixComQuatroOpções
				.obterOpção(5));
	}

	@Test
	public void sóRemoveUmaOpçãoSePossuiEla() {
		assertFalse(componenteGedixComQuatroOpções.removerOpção(0));
		assertFalse(componenteGedixComQuatroOpções.removerOpção(5));
	}

	@Test
	public void obtemApenasUmaOpçãoDeUmIndice() {
		assertEquals(opção1, componenteGedixComQuatroOpções.obterOpção(1));
		
		assertFalse(opção2.equals(componenteGedixComQuatroOpções
				.obterOpção(1)));
		
		assertFalse(opção3.equals(componenteGedixComQuatroOpções
				.obterOpção(1)));
		
		assertFalse(opção4.equals(componenteGedixComQuatroOpções
				.obterOpção(1)));
	}

	
	@Test
	public void nãoAdcionaUmaOpçãoSeJáExisteUmaOpçãoIgual(){
		assertTrue(componenteGedixComNenhumaOpção.adcionarOpção(opção1));
		assertFalse(componenteGedixComNenhumaOpção.adcionarOpção(opção1));
	}
	
	@Test
	public void podeRemoverUmaOpçãoDesdeQueContenhaEssaOpção(){
		assertTrue(componenteGedixComQuatroOpções
				.possuiAOpção(opção1));
		assertTrue(componenteGedixComQuatroOpções
				.removerOpção(opção1));
		
		assertFalse(componenteGedixComQuatroOpções
				.removerOpção(opção1));
		assertFalse(componenteGedixComNenhumaOpção
				.removerOpção(opção1));
	}
	
	@Test
    public void sabeQuantasOpçõesPossui(){
		assertSame(4, componenteGedixComQuatroOpções
				.obterQuantidadeDeOpções());
	}
	
	@Test
	public void éTransformávelEmXMLComOpções(){
		assertTrue(componenteGedixComQuatroOpções instanceof TransformavelEmXMLComOpcoes);
	}

	private void criarOpções() {
		opção1 = Fabrica.obterOpçãoDeNome("opção1");
		opção2 = Fabrica.obterOpçãoDeNome("opção2");
		opção3 = Fabrica.obterOpçãoDeNome("opção3");
		opção4 = Fabrica.obterOpçãoDeNome("opção4");
		opção5 = Fabrica.obterOpçãoDeNome("opção5");;
		opçãoNula = Fabrica.obterOpçãoNula();
	}

	

}
