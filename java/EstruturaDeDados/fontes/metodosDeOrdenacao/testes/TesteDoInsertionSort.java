package metodosDeOrdenacao.testes;

import org.junit.Test;

import metodosDeOrdenacao.InsertionSort;
import metodosDeOrdenacao.MetodoOrdenacao;

public class TesteDoInsertionSort extends TesteDosMetodosDeOrdenacaoDeDados{

	@Override
	protected MetodoOrdenacao definirMetodoDeOrdenacao() {
		
		return InsertionSort.retorneSort();
	}
	
	@Test
	public void rodarTestes(){ }

}
