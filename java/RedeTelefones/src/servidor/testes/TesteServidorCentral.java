package servidor.testes;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

import celular.Celular;
import celular.CelularPadrao;

import servidor.EstacaoBase;
import servidor.ServidorCentral;

public class TesteServidorCentral {

	private ServidorCentral servidor;
	private Integer numeroValido, numeroInvalido;
	private Celular cel;
	
	@Before
	public void iniciar(){
		numeroValido = 91498687;
		numeroInvalido = 74587923;
		cel = new CelularPadrao(numeroValido);
		servidor = ServidorCentral.obterServidor();
	}
	
	@Test
	public void dadoUmNumeroDeCelularSabeSeEsteNumeroExiste(){
		assertTrue(servidor.possuiCelular(numeroValido));
	}
	
	@Test
	public void dadoUmNumeroDeCelularSabeSeEsteNumeroNaoExiste() {
		assertFalse(servidor.possuiCelular(numeroInvalido));
	}
	
	@Test
	public void seUmNumeroDeCelularExisteDentroDoServidorPodeObterSuaEstacaoBase() {
		EstacaoBase estacao = servidor.obterEstacaoDoCelular(numeroValido);
		assertEquals(cel, estacao.obterCelular(numeroValido));
	}
	
	@Test
	public void seUmNumeroDeCelularNaoExisteDentroDoServidorRetornaNulo(){
		assertNull(servidor.obterEstacaoDoCelular(numeroInvalido));
	}
	
}
