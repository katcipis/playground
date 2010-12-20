package servidor.testes;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

import servidor.EstacaoBase;

import celular.Celular;
import celular.CelularNulo;
import celular.CelularPadrao;

public class TesteEstacaoBase {

	private EstacaoBase estacao;
	private Celular celUm, celDois;
	
	@Before
	public void iniciar(){
		estacao = new EstacaoBase();
		celUm = new CelularPadrao(1);
		celDois = new CelularPadrao(2);
		estacao.inserirCelular(celUm);
	}
	
	@Test
	public void sabeSePossuiUmCelular(){
		assertTrue(estacao.possuiCelular(1));
	}
	
	@Test
	public void sabeSeNaoPossuiUmCelular(){
		assertFalse(estacao.possuiCelular(2));
	}
	
	@Test
	public void umCelularPodeSerInseridoNaEstacao(){
		assertFalse(estacao.possuiCelular(2));
		estacao.inserirCelular(celDois);
		assertTrue(estacao.possuiCelular(2));
	}
	
	@Test
	public void umCelularPodeSerRemovidoDaEstacao(){
		assertTrue(estacao.possuiCelular(1));
		estacao.removerCelular(celUm);
		assertFalse(estacao.possuiCelular(1));
	}
	
	@Test
	public void dadoUmNumeroDeCelularSePossuiUmCelularComEsteNumeroRetornaEle(){
		assertTrue(estacao.possuiCelular(1));
		assertEquals(celUm, estacao.obterCelular(1));
	}
	
	@Test
	public void dadoUmNumeroDeCelularSeNaoPossuiUmCelularComEsteNumeroRetornaUmCelularNulo(){
		assertFalse(estacao.possuiCelular(2));
		assertEquals(new CelularNulo() , estacao.obterCelular(2));
	}
	
}
