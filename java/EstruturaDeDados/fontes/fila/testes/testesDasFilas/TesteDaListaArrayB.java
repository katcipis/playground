package fila.testes.testesDasFilas;

import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;
import ine5384.excecoes.ExcecaoEstruturaCheia;

import org.junit.Test;

import fila.filas.Fila;
import fila.filas.FilaArrayB;
import fila.testes.listasDeTestesDasFilas.ListaDeTestesDaFilaArray;

public class TesteDaListaArrayB extends TesteAbstratoDaFila implements ListaDeTestesDaFilaArray{

	@Override
	protected Fila<String> criarFilaVazia() {
		
		return new FilaArrayB<String>();
	}

	@Test
	public void podeTerOTamanhoEspecificado() throws ExcecaoEstruturaCheia {
		FilaArrayB<String> filaPadrao = new FilaArrayB<String>(100);
		assertFalse(filaPadrao.estaCheia());
		
		for(int i = 1; i <=100; i++){
			filaPadrao.insere(elementoUm);
		}
		
		assertTrue(filaPadrao.estaCheia());
		
	}

	@Test(expected = ExcecaoEstruturaCheia.class)
	public void seExcederOTamanhoEspecificadoLancaUmaExcecaoDeEstruturaCheia()
			throws ExcecaoEstruturaCheia {
		
		FilaArrayB<String> filaDeTamanhoDez = new FilaArrayB<String>();
		assertFalse(filaDeTamanhoDez.estaCheia());
		for(int i = 1; i <=11; i++){
			filaDeTamanhoDez.insere(elementoUm);
		}
	
	}
		
	@Test
	public void seNaoForInformadoOTamanhoOTamanhoSeraDez()
			throws ExcecaoEstruturaCheia {
		FilaArrayB<String> filaPadrao = new FilaArrayB<String>();
		assertFalse(filaPadrao.estaCheia());
		for(int i = 1; i <=10; i++){
			filaPadrao.insere(elementoUm);
		}
		assertTrue(filaPadrao.estaCheia());
		
	}

	
}
