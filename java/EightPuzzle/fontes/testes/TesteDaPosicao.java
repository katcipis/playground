package testes;

import static org.junit.Assert.*;
import jogo.Posicao;

import org.junit.Before;
import org.junit.Test;




public class TesteDaPosicao {

	
	private Posicao linhaUmColunaUm, linhaUmColunaDois, outraLinhaUmColunaUm;
	

	@Before
	public void criarPosições() {
        
         linhaUmColunaUm = new Posicao(1, 1);
         outraLinhaUmColunaUm = new Posicao(1, 1);
         linhaUmColunaDois	 =  new Posicao(1, 2);
	}

	@Test
	public void sabeSeCompararComOutraPosiçãoESaberSeÉIgual() {
		assertEquals(outraLinhaUmColunaUm,  linhaUmColunaUm);
	}

	@Test
	public void sabeSeCompararComOutraPosiçãoESaberSeÉDiferente() {
		assertFalse(linhaUmColunaUm.equals(linhaUmColunaDois));
	}

	@Test
	public void sabeQualSuaLinha() {
		assertSame(1 , linhaUmColunaDois.obterLinha());
	}

	@Test
	public void sabeQualSuaColuna() {
		assertSame(2 , linhaUmColunaDois.obterColuna());
	}

	

}