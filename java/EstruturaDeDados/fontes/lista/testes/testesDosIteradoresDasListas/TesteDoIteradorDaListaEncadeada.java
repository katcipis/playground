package lista.testes.testesDosIteradoresDasListas;

import lista.listas.simples.ListaEncadeada;
import ine5384.lineares.Lista;

public class TesteDoIteradorDaListaEncadeada extends TesteAbstratoDoIteradorDaLista{

	@Override
	protected Lista<String> criarLista() {
		return new ListaEncadeada<String>();
	}

}
