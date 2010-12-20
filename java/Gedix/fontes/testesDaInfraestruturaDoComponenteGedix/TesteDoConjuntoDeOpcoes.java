package testesDaInfraestruturaDoComponenteGedix;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.assertSame;
import infraestruturaDoComponenteGedix.ConjuntoDeOpcoes;
import infraestruturaDoComponenteGedix.Opcao;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import listasDeTestesDaInfraestruturaDoComponenteGedix.ListaDeTestesDoConjuntoDeOpcoes;

import org.junit.Before;
import org.junit.Test;

public class TesteDoConjuntoDeOpcoes implements ListaDeTestesDoConjuntoDeOpcoes{

	private ConjuntoDeOpcoes conjuntoDeOpçõesVazio, conjuntoDeOpçõesComQuatroOpções;
	private Opcao primeiraOpção, segundaOpção, terceiraOpção, quartaOpção,quintaOpção, opçãoNula;
	
	@Before
	public void criarConjuntosDeOpções(){
		conjuntoDeOpçõesVazio = Fabrica.obterConjuntoDeOpções();
		conjuntoDeOpçõesComQuatroOpções = Fabrica.obterConjuntoDeOpções();
		primeiraOpção = Fabrica.obterOpçãoDeNome("um");
		segundaOpção = Fabrica.obterOpçãoDeNome("dois");
		terceiraOpção = Fabrica.obterOpçãoDeNome("três");
		quartaOpção =  Fabrica.obterOpçãoDeNome("quatro");
		quintaOpção =  Fabrica.obterOpçãoDeNome("cinco");
		opçãoNula = Fabrica.obterOpçãoNula();
		
		conjuntoDeOpçõesComQuatroOpções.adcionar(primeiraOpção);
		conjuntoDeOpçõesComQuatroOpções.adcionar(segundaOpção);
		conjuntoDeOpçõesComQuatroOpções.adcionar(terceiraOpção);
		conjuntoDeOpçõesComQuatroOpções.adcionar(quartaOpção);
	} 
	
	
	@Test
	public void podeRemoverTodasAsOpçõesDoConjunto() {
		assertFalse(conjuntoDeOpçõesComQuatroOpções.estáVazio());
		conjuntoDeOpçõesComQuatroOpções.removerTodos();
		assertTrue(conjuntoDeOpçõesComQuatroOpções.estáVazio());
	}

	@Test
	public void nãoAdcionaUmaOpçãoSeJáExisteUmaOpçãoIgualNoConjunto() {
		assertTrue(conjuntoDeOpçõesVazio.adcionar(primeiraOpção));
		assertFalse(conjuntoDeOpçõesVazio.adcionar(primeiraOpção));
	}


	@Test
	public void oIndiceDaPrimeiraOpçãoÉUm() {
		assertEquals(primeiraOpção, conjuntoDeOpçõesComQuatroOpções.obterOpção(1));
	}

	@Test
	public void podeObterUmaOpçãoAPartirDoSeuIndice() {
		
		assertEquals(primeiraOpção, conjuntoDeOpçõesComQuatroOpções.obterOpção(1));
		assertEquals(segundaOpção, conjuntoDeOpçõesComQuatroOpções.obterOpção(2));
		assertEquals(terceiraOpção, conjuntoDeOpçõesComQuatroOpções.obterOpção(3));
		
	}

	@Test
	public void podeRemoverUmaOpçãoAPartirDoSeuIndice() {
		assertTrue(conjuntoDeOpçõesComQuatroOpções.possui(primeiraOpção));
		conjuntoDeOpçõesComQuatroOpções.remover(1);
		assertFalse(conjuntoDeOpçõesComQuatroOpções.possui(primeiraOpção));
	}

	
	@Test
	public void quandoAdcionadaUmaOpçãoElaFicaráNoFinalDaLista() {
		assertTrue(conjuntoDeOpçõesComQuatroOpções.adcionar(quintaOpção));
		assertEquals(quintaOpção, conjuntoDeOpçõesComQuatroOpções.obterOpção(5));
	}

	
	@Test
	public void seTentarObterUmaOpçãoQueNãoExisteRetornaUmaOpçãoNula() {
		assertEquals(opçãoNula, conjuntoDeOpçõesComQuatroOpções.obterOpção(0));
		assertEquals(opçãoNula, conjuntoDeOpçõesComQuatroOpções.obterOpção(5));
	}

	@Test
	public void sóRemoveUmaOpçãoSeElaExisteNaLista() {
		assertFalse(conjuntoDeOpçõesVazio.remover(1));
		assertFalse(conjuntoDeOpçõesComQuatroOpções.remover(0));
		assertFalse(conjuntoDeOpçõesComQuatroOpções.remover(5));
	}


	@Test
	public void podeInformarSePossuiUmaOpção() {
		assertTrue(conjuntoDeOpçõesComQuatroOpções.possui(primeiraOpção));
		assertFalse(conjuntoDeOpçõesVazio.possui(primeiraOpção));
	}

	@Test
	public void podeInformarSeExisteUmaOpçãoComUmDeterminadoIndice() {
		assertTrue(conjuntoDeOpçõesComQuatroOpções.possui(1));
		assertTrue(conjuntoDeOpçõesComQuatroOpções.possui(2));
		assertTrue(conjuntoDeOpçõesComQuatroOpções.possui(3));
		assertTrue(conjuntoDeOpçõesComQuatroOpções.possui(4));
		
		assertFalse(conjuntoDeOpçõesComQuatroOpções.possui(5));
		assertFalse(conjuntoDeOpçõesComQuatroOpções.possui(0));
		
		assertFalse(conjuntoDeOpçõesVazio.possui(1));
	}

	@Test
	public void podeRemoverUmaOpçãoSeElaEstáNoConjunto() {
		
		assertTrue(conjuntoDeOpçõesComQuatroOpções.possui(primeiraOpção));
		assertTrue(conjuntoDeOpçõesComQuatroOpções.remover(primeiraOpção));
		assertFalse(conjuntoDeOpçõesVazio.remover(primeiraOpção));
		
		assertFalse(conjuntoDeOpçõesComQuatroOpções.possui(primeiraOpção));
		
	}


	@Test
	public void sabeQuantasOpçõesPossui() {
		assertSame(4, conjuntoDeOpçõesComQuatroOpções.obterTamanho());
	}

}
