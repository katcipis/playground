package infraestrutura.testes.testesDosNodos;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNull;
import infraestrutura.nodos.NodoComparable;

import org.junit.Before;
import org.junit.Test;

public class TesteDoNodoComparable {

	private NodoComparable<String> nodoUm,
	 nodoDois;
	private String elementoUm, elementoDois;
	
	@Before
	public void criarNodo(){
		elementoUm = "elementoUm";
		elementoDois = "elementoDois";
		nodoUm = new NodoComparable<String>(elementoUm);
		nodoDois = new NodoComparable<String>(elementoDois);
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
	public void podeObterOElementoQueAponta() {
		assertEquals(nodoUm.retornaElemento(), elementoUm);
		
	}

	@Test
	public void podeObterOProximo() {
		nodoUm.atribuiProximo(nodoDois);
		assertEquals(nodoUm.retornaProximo(), nodoDois);
		
	}

	@Test
	public void seNãoDefinirUmProximEPedirOProximoRetornaNull() {
		assertNull(nodoUm.retornaProximo());
		
	}
}
