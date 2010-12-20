package celular.testes;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

import celular.Celular;
import celular.CelularNulo;
import celular.CelularPadrao;

public class TesteCelularNulo {

	private Celular celNulo, celZero;
	
	@Before
	public void iniciar(){
		celNulo = new CelularNulo();
		celZero = new CelularPadrao(0);
	}
	
	@Test
	public void seuNumeroEhSempreZero(){
		assertEquals(0, celNulo.obterNumero());
	}
	
	@Test
	public void sempreEstaOcupado(){
		assertTrue(celNulo.estaOcupado());
	}
	
	@Test
	public void sempreEstaDesligado(){
		assertTrue(celNulo.estaDesligado());
		celNulo.ligar();
		assertTrue(celNulo.estaDesligado());
	}
	
	@Test
	public void posicaoSempreEhZero(){
		assertEquals(0, celNulo.obterPosicao());
	}
	
	@Test
	public void todoCelularNuloEhIgual(){
		assertEquals(new CelularNulo(), new CelularNulo());
	}
	
	@Test
	public void nuncaEhIgualAUmCelularQueNaoSejaNulo(){
		assertFalse(celNulo.equals(celZero));
	}
	
	@Test
	public void possuiEstacaoNula(){
		assertNull(celNulo.obterEstacao());
	}
	
}
