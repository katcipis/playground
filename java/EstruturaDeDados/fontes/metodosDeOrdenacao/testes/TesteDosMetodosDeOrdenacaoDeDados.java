package metodosDeOrdenacao.testes;

import static org.junit.Assert.*;
import metodosDeOrdenacao.MetodoOrdenacao;

import org.junit.Before;
import org.junit.Test;

public abstract class TesteDosMetodosDeOrdenacaoDeDados {
	
	private String[] umElementoOrdenado, doisElementosDesordenados,
	doisElementosOrdenados, oitoElementosOrdenados, oitoElementosDesordenados,
	arrayDeTamanhoDezComCincoElementos, arrayDeTamanhoDezComCincoElementosDesordenado;
	
	private MetodoOrdenacao ordenador;
	
	@Before
	public void construirComponentes(){
		umElementoOrdenado = new String[1];
		doisElementosDesordenados = new String[2];
		doisElementosOrdenados = new String[2];
		oitoElementosOrdenados = new String[8];
		oitoElementosDesordenados = new String[8];
		arrayDeTamanhoDezComCincoElementos = new String[10];
		arrayDeTamanhoDezComCincoElementosDesordenado = new String[10];
		
		umElementoOrdenado[0] = "A";
		
		doisElementosDesordenados[0] = "B";
		doisElementosDesordenados[1] = "A";
		
		doisElementosOrdenados[0] = "A";
		doisElementosOrdenados[1] = "B";
		
		criarOitoElementosOrdenados();
		
		criarOitoElementosDesordenados();
		
		criarArrayDeTamanhoDez();
		
		ordenador = definirMetodoDeOrdenacao();
	}

	private void criarArrayDeTamanhoDez() {
		arrayDeTamanhoDezComCincoElementosDesordenado[0] = "A";
		arrayDeTamanhoDezComCincoElementosDesordenado[3] = "F";
		arrayDeTamanhoDezComCincoElementosDesordenado[7] = "C";
		arrayDeTamanhoDezComCincoElementosDesordenado[9] = "D";
		arrayDeTamanhoDezComCincoElementosDesordenado[2] = "E";
		
		arrayDeTamanhoDezComCincoElementos[0] = "A";
		arrayDeTamanhoDezComCincoElementos[1] = "C";
		arrayDeTamanhoDezComCincoElementos[2] = "D";
		arrayDeTamanhoDezComCincoElementos[3] = "E";
		arrayDeTamanhoDezComCincoElementos[4] = "F";
	}

	private void criarOitoElementosOrdenados() {
		oitoElementosOrdenados[0] = "A";
		oitoElementosOrdenados[1] = "B";
		oitoElementosOrdenados[2] = "C";
		oitoElementosOrdenados[3] = "D";
		oitoElementosOrdenados[4] = "E";
		oitoElementosOrdenados[5] = "F";
		oitoElementosOrdenados[6] = "G";
		oitoElementosOrdenados[7] = "H";
	}

	private void criarOitoElementosDesordenados() {
		oitoElementosDesordenados[0] = "H";
		oitoElementosDesordenados[1] = "G";
		oitoElementosDesordenados[2] = "F";
		oitoElementosDesordenados[3] = "D";
		oitoElementosDesordenados[4] = "E";
		oitoElementosDesordenados[5] = "C";
		oitoElementosDesordenados[6] = "B";
		oitoElementosDesordenados[7] = "A";
	}
	
	
	
	protected abstract MetodoOrdenacao definirMetodoDeOrdenacao();
	
	
	
	@Test
	public void sabeOrdenarArraysComUmElemento(){
		ordenador.ordena(umElementoOrdenado);
		assertEquals(umElementoOrdenado[0], "A");
	}
	
	@Test
	public void sabeOrdenarArraysComDoisElementos(){
		
		assertFalse(doisElementosOrdenados[0].equals(doisElementosDesordenados[0]));
		assertFalse(doisElementosOrdenados[1].equals(doisElementosDesordenados[1]));
		
		ordenador.ordena(doisElementosDesordenados);
		
		assertEquals(doisElementosOrdenados[0], doisElementosDesordenados[0]);
		assertEquals(doisElementosOrdenados[1], doisElementosDesordenados[1]);
	}
	
	@Test
	public void sabeOrdenarArraysComOitoElementos(){
		
		ordenador.ordena(oitoElementosDesordenados);
		
		assertEquals(oitoElementosOrdenados[0], oitoElementosDesordenados[0]);
		assertEquals(oitoElementosOrdenados[1], oitoElementosDesordenados[1]);
		assertEquals(oitoElementosOrdenados[2], oitoElementosDesordenados[2]);
		assertEquals(oitoElementosOrdenados[3], oitoElementosDesordenados[3]);
		assertEquals(oitoElementosOrdenados[4], oitoElementosDesordenados[4]);
		assertEquals(oitoElementosOrdenados[5], oitoElementosDesordenados[5]);
		assertEquals(oitoElementosOrdenados[6], oitoElementosDesordenados[6]);
		assertEquals(oitoElementosOrdenados[7], oitoElementosDesordenados[7]);
		
	}
	
	@Test
	public void sabeOrdenarArraysQueNaoEstaoCheiosEQuePossuemPosicoesNulas(){
		ordenador.ordena(arrayDeTamanhoDezComCincoElementosDesordenado);
		
		assertEquals(arrayDeTamanhoDezComCincoElementos[0], arrayDeTamanhoDezComCincoElementosDesordenado[0]);
		assertEquals(arrayDeTamanhoDezComCincoElementos[1], arrayDeTamanhoDezComCincoElementosDesordenado[1]);
		assertEquals(arrayDeTamanhoDezComCincoElementos[2], arrayDeTamanhoDezComCincoElementosDesordenado[2]);
		assertEquals(arrayDeTamanhoDezComCincoElementos[3], arrayDeTamanhoDezComCincoElementosDesordenado[3]);
		assertEquals(arrayDeTamanhoDezComCincoElementos[4], arrayDeTamanhoDezComCincoElementosDesordenado[4]);
		
		assertNull(arrayDeTamanhoDezComCincoElementosDesordenado[5]);
		assertNull(arrayDeTamanhoDezComCincoElementosDesordenado[6]);
		assertNull(arrayDeTamanhoDezComCincoElementosDesordenado[7]);
		assertNull(arrayDeTamanhoDezComCincoElementosDesordenado[8]);
		assertNull(arrayDeTamanhoDezComCincoElementosDesordenado[9]);
		
	}
	
	

}
