package fila.testes.testesDasFilas;

import static org.junit.Assert.*;
import ine5384.excecoes.ExcecaoEstruturaCheia;

import org.junit.Test;

import fila.filas.Fila;
import fila.filas.FilaEncadeada;
import fila.testes.listasDeTestesDasFilas.ListaDeTestesDaFilaEncadeada;

public class TesteDaFilaEncadeada extends TesteAbstratoDaFila implements ListaDeTestesDaFilaEncadeada{

	@Override
	protected Fila<String> criarFilaVazia() {

		return new FilaEncadeada<String>();
	}
	
	@Test
	public void nuncaFicaCheia() throws ExcecaoEstruturaCheia{
		for(int i = 1; i <= 1000; i++){
			filaVazia.insere(elementoUm);
		}
		
		assertFalse(filaVazia.estaCheia());
	}

}
