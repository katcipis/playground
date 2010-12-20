package testesDaInfraestruturaDoPainel;

import static org.junit.Assert.*;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import infraestruturaDoPainelDeComponenteGedix.ListaDePosicoes;
import listasDeTestesDaInfraestruturaDoPainel.ListaDeTestesDaListaDePosicoes;


import org.junit.Before;
import org.junit.Test;


public class TesteDaListaDePosicoes implements ListaDeTestesDaListaDePosicoes{

	private ListaDePosicoes listaDeposiçõesComPosição3e3;

	
	@Before
	public void criarComponentesNecessários(){
		listaDeposiçõesComPosição3e3 = new ListaDePosicoes();
	
		listaDeposiçõesComPosição3e3.adcionar(Fabrica.obterPosição(3, 3));
	}
	
	@Test
	public void nãoPodeTerDuasPosiçõesIguais(){
		assertFalse(listaDeposiçõesComPosição3e3.adcionar(Fabrica.obterPosição(3,3)));
	}
	
	@Test
	public void sabeQuantasPosiçõesPossui(){
		assertTrue(listaDeposiçõesComPosição3e3.adcionar(Fabrica.obterPosição(3,4)));
		assertEquals(2, listaDeposiçõesComPosição3e3.obterQuantidadeDePosições());
	}
	
	@Test
	public void verificaSeUmaPosiçãoFazParteDaLista(){
		assertTrue(listaDeposiçõesComPosição3e3.verificarSeContêmEssaPosição(Fabrica.obterPosição(3,3)));
	}
	
	@Test
	public void podeSerLimpaESeTornarVazia(){
		listaDeposiçõesComPosição3e3.esvaziar();
		assertTrue(listaDeposiçõesComPosição3e3.verificarSeEstáVazia());
	}
	
	
}
