package metodosDeOrdenacao.testes;

import metodosDeOrdenacao.QuickSort;
import metodosDeOrdenacao.MetodoOrdenacao;

import org.junit.Test;

public class TesteDoQuickSort extends TesteDosMetodosDeOrdenacaoDeDados{
	@Override
	protected MetodoOrdenacao definirMetodoDeOrdenacao() {
		
		return QuickSort.retorneSort();
	}

	@Test
	public void rodarTestes(){ }
}
