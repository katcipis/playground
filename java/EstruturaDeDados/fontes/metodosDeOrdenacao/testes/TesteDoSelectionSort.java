package metodosDeOrdenacao.testes;

import org.junit.Test;

import metodosDeOrdenacao.MetodoOrdenacao;
import metodosDeOrdenacao.SelectionSort;

public class TesteDoSelectionSort extends TesteDosMetodosDeOrdenacaoDeDados{

	@Override
	protected MetodoOrdenacao definirMetodoDeOrdenacao() {
		
		return SelectionSort.retorneSort();
	}
	
	@Test
	public void rodarTestes(){ }

}
