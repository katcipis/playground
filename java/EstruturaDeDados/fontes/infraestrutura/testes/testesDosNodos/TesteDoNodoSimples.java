package infraestrutura.testes.testesDosNodos;

import static org.junit.Assert.*;
import infraestrutura.nodos.NodoSimples;


import org.junit.Before;
import org.junit.Test;




public class TesteDoNodoSimples {

	private NodoSimples<String> nodoUm, nodoDois;
	private String elementoUm, elementoDois;
	
	@Before
	public void criarNodo(){
		elementoUm = "elementoUm";
		elementoDois = "elementoDois";
		nodoUm = new NodoSimples<String>(elementoUm);
		nodoDois = new NodoSimples<String>(elementoDois);
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
