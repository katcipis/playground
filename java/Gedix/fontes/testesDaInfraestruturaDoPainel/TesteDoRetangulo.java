package testesDaInfraestruturaDoPainel;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertNotSame;
import static org.junit.Assert.assertSame;
import infraestruturaDoPainelDeComponenteGedix.Dimensao;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import infraestruturaDoPainelDeComponenteGedix.Retangulo;
import listasDeTestesDaInfraestruturaDoPainel.ListaDeTestesDoRetangulo;

import org.junit.Before;
import org.junit.Test;


public class TesteDoRetangulo implements  ListaDeTestesDoRetangulo{
	
	private Retangulo retânguloDeAlturaDezELarguraVinte,
	outroRetânguloDeAlturaDezELarguraVinte;
	private Dimensao alturaDezLarguraVinte, alturaDezLarguraVinteEUm;
	
	@Before
	public void criarComponentes(){

		
		criarDimensões();
		
		criarRetângulos();
	}

	private void criarRetângulos() {
		retânguloDeAlturaDezELarguraVinte = 
			Fabrica.obterRetangulo(alturaDezLarguraVinte);
		
		outroRetânguloDeAlturaDezELarguraVinte = 
			Fabrica.obterRetangulo(alturaDezLarguraVinte);
	}

	private void criarDimensões() {
		alturaDezLarguraVinte = Fabrica.obterDimensão(10, 20);
		alturaDezLarguraVinteEUm = Fabrica.obterDimensão(10, 21);
	}
	
	@Test
    public void sabeASuaAltura(){
    	assertSame(10, retânguloDeAlturaDezELarguraVinte.obterAltura());
    }
	
	@Test
    public void sabeQualNãoÉSuaAltura(){
    	assertNotSame(11,retânguloDeAlturaDezELarguraVinte.obterAltura());
    	assertNotSame(9,retânguloDeAlturaDezELarguraVinte.obterAltura());
    }
	
	@Test
	public void sabeASuaLargura(){
		assertSame(20, retânguloDeAlturaDezELarguraVinte.obterLargura());
	}
	
	@Test
	public void sabeQualNãoÉSuaLargura(){
		assertNotSame(21, retânguloDeAlturaDezELarguraVinte.obterLargura());
		assertNotSame(19, retânguloDeAlturaDezELarguraVinte.obterLargura());
	}
	
	@Test 
	public void podeMudarSuaAltura(){
		retânguloDeAlturaDezELarguraVinte.definirAltura(40);
		 assertSame(40, retânguloDeAlturaDezELarguraVinte.obterAltura());
	 }
		
    @Test 
	public void podeMudarSuaLargura(){
		 retânguloDeAlturaDezELarguraVinte.definirLargura(15);
		 assertSame(15, retânguloDeAlturaDezELarguraVinte.obterLargura());
     }
    
    @Test
    public void seForDefinidaUmaAlturaMenorQueZeroAAlturaSeráZero(){
    	 retânguloDeAlturaDezELarguraVinte.definirLargura(-1);
		 assertSame(0, retânguloDeAlturaDezELarguraVinte.obterLargura());
    }
	
	@Test
    public void seForDefinidaUmaLarguraMenorQueZeroALarguraSeráZero(){
		retânguloDeAlturaDezELarguraVinte.definirAltura(-10);
    	assertSame(0, retânguloDeAlturaDezELarguraVinte.obterAltura());
	}
	
	@Test
	public void podeMudarSuaDimensão(){
		retânguloDeAlturaDezELarguraVinte
		.definirDimensão(alturaDezLarguraVinteEUm);
		
		assertEquals(alturaDezLarguraVinteEUm,
				retânguloDeAlturaDezELarguraVinte.obterDimensão());
		
	}
	
	@Test
	public void sabeQualASuaDimensão(){
		assertEquals(alturaDezLarguraVinte,
				retânguloDeAlturaDezELarguraVinte.obterDimensão());
	}
	
	@Test
	public void sabeQualNãoÉASuaDimensão(){
		assertFalse(alturaDezLarguraVinteEUm
				.equals(retânguloDeAlturaDezELarguraVinte.obterDimensão()));
	}

	@Test
	public void retângulosDeMesmaDimensãoSãoIguais(){
		assertEquals(retânguloDeAlturaDezELarguraVinte,
				outroRetânguloDeAlturaDezELarguraVinte);
	}

}
