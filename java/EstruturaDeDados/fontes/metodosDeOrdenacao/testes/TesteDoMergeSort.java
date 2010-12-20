package metodosDeOrdenacao.testes;

import metodosDeOrdenacao.MergeSort;
import metodosDeOrdenacao.MetodoOrdenacao;

import org.junit.Test;

public class TesteDoMergeSort extends TesteDosMetodosDeOrdenacaoDeDados{
	
	@Override
	protected MetodoOrdenacao definirMetodoDeOrdenacao() {
		
		return MergeSort.retorneSort();
	}

	@Test
	public void rodarTestes(){ }
}
