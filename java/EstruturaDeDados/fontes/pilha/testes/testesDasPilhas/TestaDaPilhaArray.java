package pilha.testes.testesDasPilhas;

import static org.junit.Assert.*;
import ine5384.excecoes.ExcecaoEstruturaCheia;

import org.junit.Test;

import pilha.pilhas.Pilha;
import pilha.pilhas.PilhaArray;
import pilha.testes.listasDeTestesDasPilhas.ListaDeTestesDaPilhaArray;

public class TestaDaPilhaArray extends TesteAbstratoDaPilha implements ListaDeTestesDaPilhaArray {

	@Override
	protected Pilha<String> criarPilha() {
		return new PilhaArray<String>();
	}
	
	@Test
	public void seNaoForInformadoOTamanhoOTamanhoSeraDez() throws ExcecaoEstruturaCheia{
		PilhaArray<String> pilhaPadrao = new PilhaArray<String>();
		assertFalse(pilhaPadrao.estaCheia());
		for(int i = 1; i <=10; i++){
			pilhaPadrao.empilhe(elementoUm);
		}
		assertTrue(pilhaPadrao.estaCheia());
	}

	@Test
	public void podeTerOTamanhoEspecificado() throws ExcecaoEstruturaCheia{
		PilhaArray<String> pilhaPadrao = new PilhaArray<String>(100);
		assertFalse(pilhaPadrao.estaCheia());
		
		for(int i = 1; i <=100; i++){
			pilhaPadrao.empilhe(elementoUm);
		}
		
		assertTrue(pilhaPadrao.estaCheia());
	}
	
	@Test(expected = ExcecaoEstruturaCheia.class)
	public void seExcederOTamanhoEspecificadoLancaUmaExcecaoDeEstruturaCheia() throws ExcecaoEstruturaCheia{
		PilhaArray<String> pilhaDeTamanhoDez = new PilhaArray<String>();
		assertFalse(pilhaDeTamanhoDez.estaCheia());
		for(int i = 1; i <=11; i++){
			pilhaDeTamanhoDez.empilhe(elementoUm);
		}
	
	}
}
