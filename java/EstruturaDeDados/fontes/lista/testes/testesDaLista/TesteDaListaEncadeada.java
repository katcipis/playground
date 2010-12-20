package lista.testes.testesDaLista;


import static org.junit.Assert.assertFalse;

import org.junit.Test;

import ine5384.excecoes.ExcecaoEstruturaCheia;
import ine5384.lineares.Lista;
import lista.listas.simples.ListaEncadeada;
import lista.listasDeTestes.listasDeTestesDasListas.ListaDeTestesDaListaComEncadeamento;


public class TesteDaListaEncadeada extends TesteAbstratoDaLista implements ListaDeTestesDaListaComEncadeamento{

	
	
	@Override
	protected Lista<String> criarListaDeStrings() {
		return new ListaEncadeada<String>();
		
	}

	@Test
	public void nuncaFicaCheia() throws ExcecaoEstruturaCheia{
		for(int i = 1; i <= 1000; i++){
			listaVazia.insiraNoFim(elementoUm);
			assertFalse(listaVazia.estaCheia());
		}
	}
	
  
}
