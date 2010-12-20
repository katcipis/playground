package testesDaInfraestruturaDoPainel;

import static org.junit.Assert.*;
import infraestruturaDoPainelDeComponenteGedix.Dimensao;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import infraestruturaDoPainelDeComponenteGedix.Posicao;
import infraestruturaDoPainelDeComponenteGedix.RetanguloPosicionavel;

import org.junit.Before;
import org.junit.Test;

import listasDeTestesDaInfraestruturaDoPainel.ListaDeTestesDoRetanguloPosicionavelNulo;

public class TesteDoRetanguloPosicionavelNulo implements 
               ListaDeTestesDoRetanguloPosicionavelNulo{
	
	private RetanguloPosicionavel retânguloPosicionávelNulo, 
	outroRetânguloPosicionávelNulo;
	
	private Posicao posiçãoNula, esquerdaDezTopoVinte, esquerdaUmTopoUm,
	esquerdaZeroTopoZero;
	
	private Dimensao alturaZeroLarguraZero,alturaUmLarguraUm;
	
	@Before
	public void criarComponentesNecessários(){
	
		
		criarRetângulosPosicionáveisNulos();
		
		criarPosições();
		
		criarDimensões();
	}


	

	
	@Test
	public void suaPosiçãoDeOrigemÉUmaPosiçãoNula(){
    	assertEquals(retânguloPosicionávelNulo.obterPosiçãoDeOrigem(),
    			posiçãoNula);
    }
	
	@Test
	public void nãoOcupaPosiçãoNenhuma(){
		
		assertFalse(retânguloPosicionávelNulo
				.verificarSeOcupaAPosição(posiçãoNula));
		
		assertFalse(retânguloPosicionávelNulo
				.verificarSeOcupaAPosição(esquerdaDezTopoVinte));
		
		assertFalse(retânguloPosicionávelNulo
				.verificarSeOcupaAPosição(esquerdaUmTopoUm));
		
		assertFalse(retânguloPosicionávelNulo
				.verificarSeOcupaAPosição(esquerdaZeroTopoZero));
	}
	
	@Test
	public void nãoPodeTerSuaPosiçãoDeOrigemRedefinida(){
		
		retânguloPosicionávelNulo.definirPosiçãoDeOrigem(esquerdaUmTopoUm);
		
		assertEquals(retânguloPosicionávelNulo.obterPosiçãoDeOrigem(),
    			posiçãoNula);
	}
	
	@Test
	public void suaAlturaÉZero(){
		assertSame(0, retânguloPosicionávelNulo.obterAltura());
	}
	
	@Test
	public void suaLarguraÉZero(){
		assertSame(0, retânguloPosicionávelNulo.obterLargura());
	}
	
	@Test
	public void nãoPodeTerSuaAlturaRedefinida(){
		retânguloPosicionávelNulo.definirAltura(10);
		assertSame(0, retânguloPosicionávelNulo.obterAltura());
	}
	
	@Test
	public void nãoPodeTerSuaLarguraRedefinida(){
		retânguloPosicionávelNulo.definirLargura(10);
		assertSame(0, retânguloPosicionávelNulo.obterLargura());
	}
	
	@Test
	public void todosRetângulosPosicionáveisNulosSãoIguais(){
		assertEquals(outroRetânguloPosicionávelNulo,
				retânguloPosicionávelNulo	);
	}
	
    
	@Test
	public void suaDimensãoÉZeroZero(){
		assertEquals(alturaZeroLarguraZero,
				retânguloPosicionávelNulo.obterDimensão());
	}
	
	
	@Test
	public void nãoPodeTerSuaDimensãoRedefinida(){
		retânguloPosicionávelNulo.definirDimensão(alturaUmLarguraUm);
		
		assertEquals(alturaZeroLarguraZero,
				retânguloPosicionávelNulo.obterDimensão());
		
	}
	
	
	
	
	
	
	
	
	
	private void criarPosições() {
		posiçãoNula = Fabrica.obterPosicaoNula();
		esquerdaDezTopoVinte = Fabrica.obterPosição(10, 20);
		esquerdaUmTopoUm = Fabrica.obterPosição(1, 1);
		esquerdaZeroTopoZero = Fabrica.obterPosição(0, 0);
	}

	private void criarRetângulosPosicionáveisNulos() {
		retânguloPosicionávelNulo = Fabrica
		.obterRetanguloPosicionavelNulo();
		outroRetânguloPosicionávelNulo = Fabrica
		.obterRetanguloPosicionavelNulo();
	}
	
	private void criarDimensões() {
		alturaZeroLarguraZero = Fabrica.obterDimensão(0, 0);
		alturaUmLarguraUm = Fabrica.obterDimensão(1, 1);
	}

}
