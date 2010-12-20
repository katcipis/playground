package metodosDeOrdenacao.testes;

import metodosDeOrdenacao.MetodoOrdenacao;
import metodosDeOrdenacao.HeapSort;

import org.junit.Test;

public class TesteDoHeapSort extends TesteDosMetodosDeOrdenacaoDeDados{
	@Override
	protected MetodoOrdenacao definirMetodoDeOrdenacao() {
		
		return HeapSort.retorneSort();
	}

	@Test
	public void rodarTestes(){ }
}
