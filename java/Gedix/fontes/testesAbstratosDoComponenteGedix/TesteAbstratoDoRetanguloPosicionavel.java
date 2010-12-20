package testesAbstratosDoComponenteGedix;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertNotSame;
import static org.junit.Assert.assertSame;
import static org.junit.Assert.assertTrue;
import infraestruturaDoPainelDeComponenteGedix.Dimensao;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import infraestruturaDoPainelDeComponenteGedix.Posicao;
import infraestruturaDoPainelDeComponenteGedix.RetanguloPosicionavel;
import listasDeTestesDaInfraestruturaDoPainel.ListaDeTestesDoRetanguloPosicionavel;

import org.junit.Before;
import org.junit.Test;

public abstract class TesteAbstratoDoRetanguloPosicionavel 
           implements ListaDeTestesDoRetanguloPosicionavel{

	
	
	protected RetanguloPosicionavel retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial;

	private Posicao esquerda0Topo0, esquerda10Topo10, esquerda20Topo10,
	esquerda5Topo5, esquerda0Topo10, esquerda20Topo0,
	esquerda21Topo4, esquerda20Topo11, esquerda30Topo20,
	esquerda0Topo20, esquerda30Topo0, esquerda31Topo20,
	esquerda30Topo21,esquerda31Topo0,esquerda23Topo4, esquerda3Topo14,
	esquerda3Topo4,esquerda23Topo14,esquerda23Topo15, esquerda24Topo14;
	
	private Dimensao alturaDezLarguraVinte, alturaDezLarguraVinteEUm;
	
	
	
	
	@Before
	public void antesDosTestesDeRetanguloPosicionavel() {
		
		criarPosições();
		criarDimensões();
		criarRetânguloPosicionável();
		
	}
	

	protected abstract void criarRetânguloPosicionável();


	public void criarPosições() {
		esquerda0Topo0 = Fabrica.obterPosição(0, 0);
		esquerda10Topo10 = Fabrica.obterPosição(10, 10);
		esquerda20Topo10 = Fabrica.obterPosição(20, 10);
		esquerda5Topo5 = Fabrica.obterPosição(5, 5);
		esquerda0Topo10 = Fabrica.obterPosição(0, 10);
		esquerda20Topo0 = Fabrica.obterPosição(20, 0);
		esquerda21Topo4 = Fabrica.obterPosição(21, 4);
		esquerda23Topo4 = Fabrica.obterPosição(23, 4);
		esquerda20Topo11 = Fabrica.obterPosição(20, 11);
		esquerda30Topo20 = Fabrica.obterPosição(30, 20);
		esquerda0Topo20 = Fabrica.obterPosição(0, 20);
		esquerda30Topo0 = Fabrica.obterPosição(30, 0);
		esquerda31Topo20 = Fabrica.obterPosição(31, 20);
		esquerda30Topo21 = Fabrica.obterPosição(30, 21);
		esquerda31Topo0 = Fabrica.obterPosição(31, 0);
		esquerda3Topo14 = Fabrica.obterPosição(3, 14);
		esquerda3Topo4 = Fabrica.obterPosição(3, 4);
		esquerda23Topo14 = Fabrica.obterPosição(23, 14);
		esquerda23Topo15 = Fabrica.obterPosição(23, 15);
		esquerda24Topo14 = Fabrica.obterPosição(24, 14);
	}
	
	

	public void criarDimensões() {
		alturaDezLarguraVinte = Fabrica.obterDimensão(10, 20);
		alturaDezLarguraVinteEUm = Fabrica.obterDimensão(10, 21);
	}
	
	@Test
	public void inicialmenteAPosiçãoDeOrigemÉZeroEZero() {
		assertEquals(esquerda0Topo0,
				retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial
						.obterPosiçãoDeOrigem());
	}

	@Test
	public void dadaUmaPosiçãoElaSeTornaANovaPosiçãoDeOrigem() {
		retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial
				.definirPosiçãoDeOrigem(esquerda10Topo10);
		
		assertEquals(esquerda10Topo10,
				retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial
						.obterPosiçãoDeOrigem());
	}


	@Test
	public void sabeAsPosiçõesQueOcupa() {
	
		
		assertTrue(retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda10Topo10));
		
		assertTrue(retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda20Topo10));
		
		assertTrue(retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda5Topo5));
		
		assertTrue(retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda0Topo10));
		
		assertTrue(retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda20Topo0));
		
		
	}

	@Test
	public void sabeAsPosiçõesQueNãoOcupa() {
		
		assertFalse(retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda21Topo4));
		
		assertFalse(retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda20Topo11));
		
	}
	
	@Test
	public void sabeAsPosiçõesQueOcupaQuandoMudaAPosiçãoDeOrigem() {
		
		retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial
		.definirPosiçãoDeOrigem(esquerda3Topo4);
		
		assertTrue(retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda23Topo4));
		
		assertTrue(retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda3Topo14));
		
		assertTrue(retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda3Topo4));
		
		assertTrue(retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda23Topo14));
	}
	
	@Test
	public void sabeAsPosiçõesQueNãoOcupaQuandoMudaAPosiçãoDeOrigem(){
		retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial
		.definirPosiçãoDeOrigem(esquerda3Topo4);
		
		assertFalse(retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda0Topo10));
		
		assertFalse(retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda20Topo0));
		
		assertFalse(retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda23Topo15));
		
		assertFalse(retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda24Topo14));
		
	}
	
	@Test
    public void sabeASuaAltura(){
    	assertSame(10, retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial.obterAltura());
    }
	
	@Test
    public void sabeQualNãoÉSuaAltura(){
    	assertNotSame(11 ,retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial.obterAltura());
    	assertNotSame(9, retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial.obterAltura());
    }
	
	@Test
	public void sabeASuaLargura(){
		assertSame(20, retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial.obterLargura());
	}
	
	@Test
	public void sabeQualNãoÉSuaLargura(){
		assertNotSame(21 , retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial.obterLargura());
		assertNotSame(19 ,retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial.obterLargura());
	}
	
	@Test 
	public void podeMudarSuaAltura(){
		 retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial.definirAltura(15);
		 assertSame(15, retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial.obterAltura());
	 }
		
    @Test 
	public void podeMudarSuaLargura(){
    	 retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial.definirLargura(40);
		 assertSame(40, retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial.obterLargura());
     }
    
    @Test
    public void seForDefinidaUmaAlturaMenorQueZeroAAlturaSeráZero(){
    	 retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial.definirAltura(-1);
		 assertSame(0, retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial.obterAltura());
    }
	
	@Test
    public void seForDefinidaUmaLarguraMenorQueZeroALarguraSeráZero(){
		retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial.definirLargura(-10);
    	assertSame(0, retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial.obterLargura());
	}
	
	
	@Test
	public void sabeAsPosiçõesQueOcupaQuandoMudaADimensão(){
		retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial.definirAltura(20);
		retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial.definirLargura(30);
		
		assertTrue(retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda0Topo0));
		
		assertTrue(retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda30Topo20));
		
		assertTrue(retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda0Topo20));
		
		assertTrue(retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda30Topo0));
		
		
	}
	
	@Test
	public void sabeAsPosiçõesQueNãoOcupaQuandoMudaADimensão(){
		assertFalse(retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda31Topo20));
		
		assertFalse(retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda30Topo21));
		
		assertFalse(retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda31Topo0));
	}
	
    @Test
	public void podeMudarSuaDimensão(){
    	retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial
    	.definirDimensão(alturaDezLarguraVinteEUm);
    	
    	assertEquals(alturaDezLarguraVinteEUm,
    			retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial.obterDimensão());
    }
	
	@Test
    public void sabeQualASuaDimensão(){
		assertEquals(alturaDezLarguraVinte,
			retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial.obterDimensão());
	}
	
	@Test
	public void sabeQualNãoÉASuaDimensão(){
		assertFalse(alturaDezLarguraVinteEUm
				.equals(retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial.obterDimensão()));
	}
	

	
}
