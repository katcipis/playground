package lista.testes.testesDaListaOrdenada;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

import ine5384.excecoes.ExcecaoEstruturaCheia;
import ine5384.lineares.ListaClassificada;
import infraestrutura.pessoa.Pessoa;
import lista.listas.ordenadas.ListaOrdenadaArray;
import lista.listasDeTestes.listasDeTestesDasListasOrdenadas.ListaDeTestesDaListaOrdenadaArray;

public class TesteDaListaOrdenadaArray extends TesteAbstratoDaListaOrdenada implements ListaDeTestesDaListaOrdenadaArray{

	private ListaClassificada<Pessoa> listaDeTamanhoCem;
	
	@Before
	public void criarListaDeTamanhoCem(){
		listaDeTamanhoCem = new ListaOrdenadaArray<Pessoa>(100);
	}
	
	@Override
	protected ListaClassificada<Pessoa> criarListaVazia() {
		
		return new ListaOrdenadaArray<Pessoa>();
	}

	@Test
	public void podeTerOTamanhoQueForPedido() throws ExcecaoEstruturaCheia {
		
		for(int i = 1; i <= 99; i++){
			listaDeTamanhoCem.insira(marcioDe20Anos);
		}
		assertFalse(listaDeTamanhoCem.estaCheia());
		listaDeTamanhoCem.insira(marcioDe20Anos);
		assertTrue(listaDeTamanhoCem.estaCheia());
	}

	@Test
	public void sabeQuandoEstaCheia() throws ExcecaoEstruturaCheia {
		
		
		for(int i = 1; i <= 100; i++){
			listaDeTamanhoCem.insira(marcioDe20Anos);
		}
		assertTrue(listaDeTamanhoCem.estaCheia());
		
	}

	@Test
	public void sabeQuandoNaoEstaCheia() throws ExcecaoEstruturaCheia {
		
		for(int i = 1; i <= 99; i++){
			listaDeTamanhoCem.insira(marcioDe20Anos);
		}
		assertFalse(listaDeTamanhoCem.estaCheia());
		
	}

	@Test
	public void seNaoForInformadoUmTamanhoSeuTamanhoSeraDez() throws ExcecaoEstruturaCheia {
		ListaClassificada<Pessoa> listaPadrao = new ListaOrdenadaArray<Pessoa>();
		
		for(int i = 1; i <= 10; i++){
			listaPadrao.insira(marcioDe20Anos);
		}
		assertTrue(listaPadrao.estaCheia());
		
	}

	@Test(expected = ExcecaoEstruturaCheia.class)
	public void seTentarExcederOTamanhoMaximoGeraUmaExcecao() throws ExcecaoEstruturaCheia {
		
		for(int i = 1; i <= 101; i++){
			listaDeTamanhoCem.insira(marcioDe20Anos);
		}
		
	}

}
