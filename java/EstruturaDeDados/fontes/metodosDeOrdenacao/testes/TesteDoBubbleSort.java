
package metodosDeOrdenacao.testes;

import org.junit.Test;

import metodosDeOrdenacao.BubbleSort;
import metodosDeOrdenacao.MetodoOrdenacao;

public class TesteDoBubbleSort extends TesteDosMetodosDeOrdenacaoDeDados {

	@Override
	protected MetodoOrdenacao definirMetodoDeOrdenacao() {
		
		return BubbleSort.retorneSort();
	}

	@Test
	public void rodarTestes(){ }
}
