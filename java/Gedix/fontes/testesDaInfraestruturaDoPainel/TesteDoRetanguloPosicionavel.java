package testesDaInfraestruturaDoPainel;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertNotSame;
import static org.junit.Assert.assertSame;
import static org.junit.Assert.assertTrue;
import infraestruturaDoPainelDeComponenteGedix.Dimensao;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import infraestruturaDoPainelDeComponenteGedix.Posicao;
import infraestruturaDoPainelDeComponenteGedix.RetanguloPosicionavel;
import listasDeTestesDaInfraestruturaDoPainel.ListaDeTestesDeUmPosicionavel;
import listasDeTestesDaInfraestruturaDoPainel.ListaDeTestesDoRetangulo;
import listasDeTestesDaInfraestruturaDoPainel.ListaDeTestesDoRetanguloPosicionavel;

import org.junit.Before;
import org.junit.Test;



public class TesteDoRetanguloPosicionavel 
                  implements ListaDeTestesDoRetanguloPosicionavel,
      			             ListaDeTestesDoRetangulo,
      			             ListaDeTestesDeUmPosicionavel{
	
	private RetanguloPosicionavel
	retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial;

	private Posicao esquerda0Topo0, esquerda10Topo10, esquerda20Topo10,
	esquerda5Topo5, esquerda0Topo10, esquerda20Topo0,
	esquerda21Topo4, esquerda20Topo11, esquerda30Topo20,
	esquerda0Topo20, esquerda30Topo0, esquerda31Topo20,
	esquerda30Topo21,esquerda31Topo0,esquerda23Topo4, esquerda3Topo14,
	esquerda3Topo4,esquerda23Topo14,esquerda23Topo15, esquerda24Topo14;
	
	private Dimensao alturaDezLarguraVinte, alturaDezLarguraVinteEUm;

	@Before
	public void criarComponentes() {
		
		criarRetângulos();
			
		criarPosições();
		
		criarDimensões();
	}




	

	@Test
	public void inicialmenteAPosiçãoDeOrigemÉZeroEZero() {
		assertEquals(esquerda0Topo0,
				retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial
						.obterPosiçãoDeOrigem());
	}

	@Test
	public void dadaUmaPosiçãoElaSeTornaANovaPosiçãoDeOrigem() {
		retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial
				.definirPosiçãoDeOrigem(esquerda10Topo10);
		
		assertEquals(esquerda10Topo10,
				retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial
						.obterPosiçãoDeOrigem());
	}


	@Test
	public void sabeAsPosiçõesQueOcupa() {
	
		
		assertTrue(retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda10Topo10));
		
		assertTrue(retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda20Topo10));
		
		assertTrue(retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda5Topo5));
		
		assertTrue(retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda0Topo10));
		
		assertTrue(retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda20Topo0));
		
		
	}

	@Test
	public void sabeAsPosiçõesQueNãoOcupa() {
		
		assertFalse(retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda21Topo4));
		
		assertFalse(retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda20Topo11));
		
	}
	
	@Test
	public void sabeAsPosiçõesQueOcupaQuandoMudaAPosiçãoDeOrigem() {
		
		retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial
		.definirPosiçãoDeOrigem(esquerda3Topo4);
		
		assertTrue(retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda23Topo4));
		
		assertTrue(retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda3Topo14));
		
		assertTrue(retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda3Topo4));
		
		assertTrue(retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda23Topo14));
	}
	
	@Test
	public void sabeAsPosiçõesQueNãoOcupaQuandoMudaAPosiçãoDeOrigem(){
		retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial
		.definirPosiçãoDeOrigem(esquerda3Topo4);
		
		assertFalse(retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda0Topo10));
		
		assertFalse(retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda20Topo0));
		
		assertFalse(retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda23Topo15));
		
		assertFalse(retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda24Topo14));
		
	}
	
	@Test
    public void sabeASuaAltura(){
    	assertSame(10, retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial.obterAltura());
    }
	
	@Test
    public void sabeQualNãoÉSuaAltura(){
    	assertNotSame(11 ,retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial.obterAltura());
    	assertNotSame(9, retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial.obterAltura());
    }
	
	@Test
	public void sabeASuaLargura(){
		assertSame(20, retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial.obterLargura());
	}
	
	@Test
	public void sabeQualNãoÉSuaLargura(){
		assertNotSame(21 , retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial.obterLargura());
		assertNotSame(19 ,retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial.obterLargura());
	}
	
	@Test 
	public void podeMudarSuaAltura(){
		 retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial.definirAltura(15);
		 assertSame(15, retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial.obterAltura());
	 }
		
    @Test 
	public void podeMudarSuaLargura(){
    	 retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial.definirLargura(40);
		 assertSame(40, retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial.obterLargura());
     }
    
    @Test
    public void seForDefinidaUmaAlturaMenorQueZeroAAlturaSeráZero(){
    	 retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial.definirAltura(-1);
		 assertSame(0, retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial.obterAltura());
    }
	
	@Test
    public void seForDefinidaUmaLarguraMenorQueZeroALarguraSeráZero(){
		retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial.definirLargura(-10);
    	assertSame(0, retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial.obterLargura());
	}
	
	
	@Test
	public void sabeAsPosiçõesQueOcupaQuandoMudaADimensão(){
		retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial.definirAltura(20);
		retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial.definirLargura(30);
		
		assertTrue(retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda0Topo0));
		
		assertTrue(retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda30Topo20));
		
		assertTrue(retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda0Topo20));
		
		assertTrue(retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda30Topo0));
		
		
	}
	
	@Test
	public void sabeAsPosiçõesQueNãoOcupaQuandoMudaADimensão(){
		assertFalse(retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda31Topo20));
		
		assertFalse(retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda30Topo21));
		
		assertFalse(retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial
				.verificarSeOcupaAPosição(esquerda31Topo0));
	}
	
    @Test
	public void podeMudarSuaDimensão(){
    	retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial
    	.definirDimensão(alturaDezLarguraVinteEUm);
    	
    	assertEquals(alturaDezLarguraVinteEUm,
    			retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial.obterDimensão());
    }
	
	@Test
    public void sabeQualASuaDimensão(){
		assertEquals(alturaDezLarguraVinte,
			retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial.obterDimensão());
	}
	
	@Test
	public void sabeQualNãoÉASuaDimensão(){
		assertFalse(alturaDezLarguraVinteEUm
				.equals(retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial.obterDimensão()));
	}
	
	
	
	
	
	
	

	private void criarDimensões() {
		alturaDezLarguraVinte = Fabrica.obterDimensão(10, 20);
		alturaDezLarguraVinteEUm = Fabrica.obterDimensão(10, 21);
	}



	private void criarRetângulos() {
		retânguloDeAlturaDezELarguraVinteNaPosiçãoInicial = Fabrica
		.obterRetanguloPosicionavel(Fabrica
		.obterRetangulo(Fabrica.obterDimensão(10, 20)));
		
	}
	
	
	
	private void criarPosições() {
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
}
