package lista.exec.listaExercicioRecursividade;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

public class TesteExercicioDaListaRecursiva {

	private ListaRecursiva<String> listaRecursiva;
	private String elementoUm, elementoDois, elementoTres, elementoQuatro,
			elementoCinco;

	@Before
	public void criarComponentes(){
		listaRecursiva = new ListaRecursiva<String>();
		
		elementoUm = "elementoUm";
		elementoDois = "elementoDois";
		elementoTres = "elementoTres";
		elementoQuatro = "elementoQuatro";
		elementoCinco = "elementoCinco";
	}
	
	@Test
	public void inserindoUmElementoNaLista(){
		listaRecursiva.insere(elementoUm);
		assertEquals(elementoUm, listaRecursiva.retorna(0));
		assertTrue(listaRecursiva.contem(elementoUm));
		assertFalse(listaRecursiva.estaVazia());
	}
	
	@Test
	public void inserindoDoisElementosNaLista(){
		listaRecursiva.insere(elementoUm);
		listaRecursiva.insere(elementoDois);
		
		assertEquals(elementoUm, listaRecursiva.retorna(0));
		assertEquals(elementoDois, listaRecursiva.retorna(1));
		
		assertTrue(listaRecursiva.contem(elementoUm));
		assertTrue(listaRecursiva.contem(elementoDois));
		
	}
	
	@Test
	public void inserindoTresElementosNaLista(){
		
		listaRecursiva.insere(elementoUm);
		listaRecursiva.insere(elementoDois);
		listaRecursiva.insere(elementoTres);
		
		assertEquals(elementoUm, listaRecursiva.retorna(0));
		assertEquals(elementoDois, listaRecursiva.retorna(1));
		assertEquals(elementoTres, listaRecursiva.retorna(2));
		
		assertTrue(listaRecursiva.contem(elementoUm));
		assertTrue(listaRecursiva.contem(elementoDois));
		assertTrue(listaRecursiva.contem(elementoTres));
		
	}
	
	@Test
	public void excluindoUmElementoEmUmaPosicaoDaListaVazia(){
		assertNull(listaRecursiva.exclui(0));
	}
	
	@Test
	public void excluindoUmElementoEmUmaPosicaoIlegalDaListaVazia(){
		assertNull(listaRecursiva.exclui(2));
		assertNull(listaRecursiva.exclui(-1));
	}
	
	@Test
	public void excluindoUmElementoEmUmaPosicaoIlegalDaListaComElementos(){
		
		listaRecursiva.insere(elementoUm);
		listaRecursiva.insere(elementoDois);
		listaRecursiva.insere(elementoTres);
		
		assertNull(listaRecursiva.exclui(4));
		assertNull(listaRecursiva.exclui(-1));
		assertNull(listaRecursiva.exclui(3));
	}
	
	@Test
	public void excluindoUmElementoEmUmaPosicaoDaListaComUmElemento(){
		listaRecursiva.insere(elementoUm);
		
		assertEquals(elementoUm, listaRecursiva.exclui(0));
		assertTrue(listaRecursiva.estaVazia());
		assertFalse(listaRecursiva.contem(elementoUm));
	}
	
	@Test
	public void excluindoUmElementoNaPrimeiraPosicaoDaListaComDoisElementos(){
		listaRecursiva.insere(elementoUm);
		listaRecursiva.insere(elementoDois);
		
		assertEquals(elementoUm, listaRecursiva.exclui(0));
		
		assertFalse(listaRecursiva.estaVazia());
		assertFalse(listaRecursiva.contem(elementoUm));
		
		assertTrue(listaRecursiva.contem(elementoDois));
		assertEquals(elementoDois, listaRecursiva.retorna(0));
		assertEquals(1, listaRecursiva.numeroElementos());
		assertNull(listaRecursiva.retorna(1));
	}
	
	@Test
	public void excluindoUmElementoNaSegundaPosicaoDaListaComDoisElementos(){
		listaRecursiva.insere(elementoUm);
		listaRecursiva.insere(elementoDois);
		
		assertEquals(elementoDois, listaRecursiva.exclui(1));
		
		assertFalse(listaRecursiva.estaVazia());
		assertFalse(listaRecursiva.contem(elementoDois));
		
		assertTrue(listaRecursiva.contem(elementoUm));
		assertEquals(elementoUm, listaRecursiva.retorna(0));
		assertEquals(1, listaRecursiva.numeroElementos());
		assertNull(listaRecursiva.retorna(1));
	}
	
	@Test
	public void excluindoElementosDaListaComCincoElementos(){
		
		listaRecursiva.insere(elementoUm);
		listaRecursiva.insere(elementoDois);
		listaRecursiva.insere(elementoTres);
		listaRecursiva.insere(elementoQuatro);
		listaRecursiva.insere(elementoCinco);
		
		
		assertEquals(elementoQuatro, listaRecursiva.exclui(3));
		
		assertFalse(listaRecursiva.contem(elementoQuatro));
		
		assertEquals(elementoCinco, listaRecursiva.retorna(3));
		assertEquals(4, listaRecursiva.numeroElementos());
		assertNull(listaRecursiva.retorna(4));
		
		
		
		assertEquals(elementoTres, listaRecursiva.exclui(2));
		
        assertFalse(listaRecursiva.contem(elementoTres));
		
		assertEquals(elementoCinco, listaRecursiva.retorna(2));
		assertEquals(3, listaRecursiva.numeroElementos());
		assertNull(listaRecursiva.retorna(3));
	}
	
	@Test
	public void verificandoPosicaoDosElementosNumaListaComCincoElementos(){
		
		listaRecursiva.insere(elementoUm);
		listaRecursiva.insere(elementoDois);
		listaRecursiva.insere(elementoTres);
		listaRecursiva.insere(elementoQuatro);
		listaRecursiva.insere(elementoCinco);
		
		assertEquals(0, listaRecursiva.retornaPosicao(elementoUm));
		assertEquals(1, listaRecursiva.retornaPosicao(elementoDois));
		assertEquals(2, listaRecursiva.retornaPosicao(elementoTres));
		assertEquals(3, listaRecursiva.retornaPosicao(elementoQuatro));
		assertEquals(4, listaRecursiva.retornaPosicao(elementoCinco));
		
	}
	
	@Test
	public void verificandoPosicaoDosElementosNumaListaComCincoElementosAposExcluirAlgunsElementos(){
		
		listaRecursiva.insere(elementoUm);
		listaRecursiva.insere(elementoDois);
		listaRecursiva.insere(elementoTres);
		listaRecursiva.insere(elementoQuatro);
		listaRecursiva.insere(elementoCinco);
		
		listaRecursiva.exclui(2);
		
		assertEquals(0, listaRecursiva.retornaPosicao(elementoUm));
		assertEquals(1, listaRecursiva.retornaPosicao(elementoDois));
		assertEquals(2, listaRecursiva.retornaPosicao(elementoQuatro));
		assertEquals(3, listaRecursiva.retornaPosicao(elementoCinco));
		
		listaRecursiva.exclui(1);
		
		assertEquals(0, listaRecursiva.retornaPosicao(elementoUm));
		assertEquals(1, listaRecursiva.retornaPosicao(elementoQuatro));
		assertEquals(2, listaRecursiva.retornaPosicao(elementoCinco));
		
	}
	
	@Test
	public void inserindoNaPosicaoUmNaListaVazia(){
		listaRecursiva.insere(elementoUm, 0);
		assertEquals(elementoUm, listaRecursiva.retorna(0));
		assertEquals(1, listaRecursiva.numeroElementos());
	}
	
	@Test
	public void inserindoNaPosicaoUmNaListaComUmElemento(){
		
		listaRecursiva.insere(elementoDois);
		
		listaRecursiva.insere(elementoUm, 0);
		
		assertEquals(elementoUm, listaRecursiva.retorna(0));
		assertEquals(elementoDois, listaRecursiva.retorna(1));
		assertEquals(2, listaRecursiva.numeroElementos());
	}
	
	@Test
	public void inserindoNaPosicaoCincoNaListaComQuatroElementos(){
		
		listaRecursiva.insere(elementoUm);
		listaRecursiva.insere(elementoDois);
		listaRecursiva.insere(elementoTres);
		listaRecursiva.insere(elementoQuatro);
		
		listaRecursiva.insere(elementoCinco, 4);
		
		assertEquals(elementoUm, listaRecursiva.retorna(0));
		assertEquals(elementoDois, listaRecursiva.retorna(1));
		assertEquals(elementoTres, listaRecursiva.retorna(2));
		assertEquals(elementoQuatro, listaRecursiva.retorna(3));
		assertEquals(elementoCinco, listaRecursiva.retorna(4));
		
		assertEquals(5, listaRecursiva.numeroElementos());
	}
	
	@Test
	public void naoInseriNaPosicaoCincoNaListaComTresElementos(){
		
		listaRecursiva.insere(elementoUm);
		listaRecursiva.insere(elementoDois);
		listaRecursiva.insere(elementoTres);
		
		listaRecursiva.insere(elementoCinco, 4);
		
		assertFalse(listaRecursiva.contem(elementoCinco));
		assertEquals(3, listaRecursiva.numeroElementos());
	}
}
