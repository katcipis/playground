package pilha.testes.testesDasPilhas;

import ine5384.excecoes.ExcecaoEstruturaCheia;

import org.junit.Test;

import pilha.pilhas.Pilha;
import pilha.pilhas.PilhaEncadeada;

public class TestaDaPilhaEncadeada extends TesteAbstratoDaPilha{

	@Override
	protected Pilha<String> criarPilha() {
		
		return new PilhaEncadeada<String>();
	}
	
	@Test
	public void pilhaEncadeadaNuncaFicaCheia() throws ExcecaoEstruturaCheia{
		for(int i = 1; i <= 1000; i++){
			pilhaVazia.empilhe(elementoUm);
		}
	}

}
