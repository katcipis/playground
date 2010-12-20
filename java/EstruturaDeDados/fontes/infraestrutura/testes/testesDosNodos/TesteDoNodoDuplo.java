package infraestrutura.testes.testesDosNodos;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNull;
import infraestrutura.nodos.NodoDuplo;

import org.junit.Before;
import org.junit.Test;

public class TesteDoNodoDuplo {

	private NodoDuplo<String> nodoUm, nodoDois;
	private String elementoUm, elementoDois;
	
	@Before
	public void criarNodo(){
		elementoUm = "elementoUm";
		elementoDois = "elementoDois";
		nodoUm = new NodoDuplo<String>(elementoUm);
		nodoDois = new NodoDuplo<String>(elementoDois);
	}
	
	@Test
	public void podeAlterarOElementoQueAponta() {
		assertEquals(nodoUm.retornaElemento(), elementoUm);
		nodoUm.atribuiElemento(elementoDois);
		assertEquals(nodoUm.retornaElemento(), elementoDois);
	}

	@Test
	public void podeEscolherQuemSeraOProximo() {
		nodoUm.atribuiProximo(nodoDois);
		assertEquals(nodoUm.retornaProximo(), nodoDois);
	}
	
	@Test
	public void podeEscolherQuemSeraOAnterior() {
		nodoUm.atribuiAnterior(nodoDois);
		assertEquals(nodoUm.retornaAnterior(), nodoDois);
	}

	@Test
	public void podeObterOElementoQueAponta() {
		assertEquals(nodoUm.retornaElemento(), elementoUm);
		
	}

	@Test
	public void podeObterOProximo() {
		nodoUm.atribuiProximo(nodoDois);
		assertEquals(nodoUm.retornaProximo(), nodoDois);
		
	}
	
	@Test
	public void podeObterOAnterior() {
		nodoUm.atribuiAnterior(nodoDois);
		assertEquals(nodoUm.retornaAnterior(), nodoDois);
		
	}

	@Test
	public void seNãoDefinirUmProximoEPedirOProximoRetornaNull() {
		assertNull(nodoUm.retornaProximo());
		
	}
	
	@Test
	public void seNãoDefinirUmAnteriorEPedirOAnteriorRetornaNull() {
		assertNull(nodoUm.retornaAnterior());
		
	}

}
