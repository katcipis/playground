package infraestrutura.testes.testesDosNodos;

import static org.junit.Assert.*;
import infraestrutura.nodos.NodoB;

import org.junit.Before;
import org.junit.Test;

public class TesteDoNodoB {
	
	private NodoB<String, Integer> nodoUm;
	private NodoB<String, Integer> nodoMenorQueOUm;
	private NodoB<String, Integer> nodoMaiorQueOUm;
	private NodoB<String, Integer> nodoIgualOUm;
	
	private String chaveDoNodoUm, chaveDoNodoMenorQueOUm,
	chaveDoNodoMaiorQueOUm; 
	
	@Before
	public void criarComponentes(){
		
		chaveDoNodoUm = "C";
		chaveDoNodoMenorQueOUm = "B";
		chaveDoNodoMaiorQueOUm = "D";

		
		nodoUm = new NodoB<String, Integer>(chaveDoNodoUm);
		nodoMenorQueOUm = new NodoB<String, Integer>(chaveDoNodoMenorQueOUm);
		nodoMaiorQueOUm = new NodoB<String, Integer>(chaveDoNodoMaiorQueOUm);
		nodoIgualOUm = new NodoB<String, Integer>(chaveDoNodoUm);
	}
	
	
	
	@Test
	public void sabeSeCompararComOutroNodoOQuePossuiMaiorChaveEhMaior(){
		assertTrue(nodoUm.compareTo(nodoMaiorQueOUm) < 0);
		assertTrue(nodoUm.compareTo(nodoMenorQueOUm) > 0);
		assertTrue(nodoUm.compareTo(nodoIgualOUm) == 0);
		assertEquals(nodoUm, nodoIgualOUm);
		
	}
	
	@Test
	public void podePossuirUmElementoAssociadoASuaEsquerda(){
		nodoUm.definirEsquerda(1);
		assertSame(1, nodoUm.retornaEsquerda());
	}
	
	@Test
	public void podePossuirUmElementoAssociadoASuaDireita(){
		nodoUm.definirDireita(3);
		assertSame(3, nodoUm.retornaDireita());
	}
	
	@Test
	public void sabeSePossuiUmElementoAssociadoASuaDireita(){
		nodoUm.definirDireita(1);
		assertTrue(nodoUm.possuiDireita());
	}
	
	@Test
	public void sabeSeNaoPossuiUmElementoAssociadoASuaDireita(){
		assertFalse(nodoUm.possuiDireita());
	}
	
	@Test
	public void sabeSePossuiUmElementoAssociadoASuaEsquerda(){
		nodoUm.definirEsquerda(1);
		assertTrue(nodoUm.possuiEsquerda());
	}
	
	@Test
	public void sabeSeNaoPossuiUmElementoAssociadoASuaEsquerda(){
		assertFalse(nodoUm.possuiEsquerda());
	}
	
	@Test
	public void podeRetornarSuaChave(){
		assertEquals(chaveDoNodoUm, nodoUm.retornaChave());
		assertEquals(chaveDoNodoUm, this.nodoIgualOUm.retornaChave());
		assertEquals(chaveDoNodoMenorQueOUm, nodoMenorQueOUm.retornaChave());
		assertEquals(chaveDoNodoMaiorQueOUm, nodoMaiorQueOUm.retornaChave());
	}

}
