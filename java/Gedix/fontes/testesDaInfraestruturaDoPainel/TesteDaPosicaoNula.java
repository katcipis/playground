package testesDaInfraestruturaDoPainel;

import static org.junit.Assert.*;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import infraestruturaDoPainelDeComponenteGedix.Posicao;
import listasDeTestesDaInfraestruturaDoPainel.ListaDeTestesDaPosicao;

import org.junit.Before;
import org.junit.Test;



public class TesteDaPosicaoNula implements
			       ListaDeTestesDaPosicao{
	
	private Posicao posiçaoZeroEZero,posiçãoNula, outraPosiçãoNula;
	
	
	@Before
	public void criarPosições(){

		posiçãoNula = Fabrica.obterPosicaoNula();
		posiçaoZeroEZero = Fabrica.obterPosição(0, 0);
		outraPosiçãoNula = Fabrica.obterPosicaoNula();
	}
	
	@Test
	public void sabeSeCompararComOutraPosiçãoESaberSeÉIgual(){
		assertEquals(posiçãoNula, outraPosiçãoNula);
	}

	@Test
	public void sabeSeCompararComOutraPosiçãoESaberSeÉDiferente(){
		assertFalse(posiçãoNula.equals(posiçaoZeroEZero));
	}

	@Test
	public void sabeQualSuaDistânciaDaEsquerda(){
		assertSame(0, posiçãoNula.obterDistânciaDaEsquerda());
	}

	@Test
	public void sabeQualSuaDistânciaDoTopo(){
		assertSame(0, posiçãoNula.obterDistânciaDoTopo());
	}

}
