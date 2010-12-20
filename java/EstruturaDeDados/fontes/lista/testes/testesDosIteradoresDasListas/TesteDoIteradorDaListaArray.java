package lista.testes.testesDosIteradoresDasListas;

import lista.listas.simples.ListaArray;
import ine5384.lineares.Lista;

public class TesteDoIteradorDaListaArray extends TesteAbstratoDoIteradorDaLista{

	@Override
	protected Lista<String> criarLista() {
		
		return new ListaArray<String>();
	}

}
