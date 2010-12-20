package fila.testes.testesDasFilas;

import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import org.junit.Test;

import ine5384.excecoes.ExcecaoEstruturaCheia;
import fila.filas.Fila;
import fila.filas.FilaArray;
import fila.testes.listasDeTestesDasFilas.ListaDeTestesDaFilaArray;

public class TesteDaFilaArray extends TesteAbstratoDaFila implements ListaDeTestesDaFilaArray {

	@Override
	protected Fila<String> criarFilaVazia() {
		
		return new FilaArray<String>();
	}

	@Test
	public void podeTerOTamanhoEspecificado() throws ExcecaoEstruturaCheia {
		FilaArray<String> filaPadrao = new FilaArray<String>(100);
		assertFalse(filaPadrao.estaCheia());
		
		for(int i = 1; i <=100; i++){
			filaPadrao.insere(elementoUm);
		}
		
		assertTrue(filaPadrao.estaCheia());
		
	}

	@Test(expected = ExcecaoEstruturaCheia.class)
	public void seExcederOTamanhoEspecificadoLancaUmaExcecaoDeEstruturaCheia()
			throws ExcecaoEstruturaCheia {
		
		FilaArray<String> filaDeTamanhoDez = new FilaArray<String>();
		assertFalse(filaDeTamanhoDez.estaCheia());
		for(int i = 1; i <=11; i++){
			filaDeTamanhoDez.insere(elementoUm);
		}
	
	}
		
	@Test
	public void seNaoForInformadoOTamanhoOTamanhoSeraDez()
			throws ExcecaoEstruturaCheia {
		FilaArray<String> filaPadrao = new FilaArray<String>();
		assertFalse(filaPadrao.estaCheia());
		for(int i = 1; i <=10; i++){
			filaPadrao.insere(elementoUm);
		}
		assertTrue(filaPadrao.estaCheia());
		
	}

}
