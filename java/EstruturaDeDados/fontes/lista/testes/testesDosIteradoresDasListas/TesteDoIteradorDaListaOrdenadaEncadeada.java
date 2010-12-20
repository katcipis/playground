package lista.testes.testesDosIteradoresDasListas;

import lista.listas.ordenadas.ListaOrdenadaEncadeada;
import ine5384.lineares.ListaClassificada;

public class TesteDoIteradorDaListaOrdenadaEncadeada extends TesteAbstratoDoIteradorOrdenado{

	@Override
	protected ListaClassificada<String> criarLista() {
		
		return new ListaOrdenadaEncadeada<String>();
	}

}
