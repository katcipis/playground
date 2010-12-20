package lista.testes.testesDaListaOrdenada;

import static org.junit.Assert.assertFalse;

import org.junit.Test;

import lista.listas.ordenadas.ListaOrdenadaEncadeada;
import lista.listasDeTestes.listasDeTestesDasListasOrdenadas.ListaDeTestesDaListaOrdenadaComEncadeamento;
import ine5384.excecoes.ExcecaoEstruturaCheia;
import ine5384.lineares.ListaClassificada;
import infraestrutura.pessoa.Pessoa;

public class TesteDaListaOrdenadaEncadeada extends TesteAbstratoDaListaOrdenada implements ListaDeTestesDaListaOrdenadaComEncadeamento{
	
	@Override
	protected  ListaClassificada<Pessoa> criarListaVazia() {
		return new ListaOrdenadaEncadeada<Pessoa>();
	}
	
	@Test
	public void nuncaFicaCheia() throws ExcecaoEstruturaCheia{
		for(int i = 1; i <= 1000; i++){
			listaOrdenadaVazia.insira(marcioDe20Anos);
			assertFalse(listaOrdenadaVazia.estaCheia());
		}
	}
}
