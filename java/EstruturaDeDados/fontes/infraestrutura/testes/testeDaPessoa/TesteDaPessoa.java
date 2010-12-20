package infraestrutura.testes.testeDaPessoa;

import static org.junit.Assert.*;
import infraestrutura.pessoa.Pessoa;

import org.junit.Before;
import org.junit.Test;


public class TesteDaPessoa {
	
	private Pessoa joaoDe17Anos, marcioDe20Anos, melanieDe17Anos,
	outroMarcioDe20Anos;
	
	@Before
	public void criarPessoas(){
		joaoDe17Anos = new Pessoa("João", 17);
		marcioDe20Anos = new Pessoa("Márcio", 20);
		outroMarcioDe20Anos = new Pessoa("Márcio", 20);
		melanieDe17Anos = new Pessoa("Melanie", 17);
	}
	
	@Test
	public void aPessoaDeMaiorIdadeSeraConsideradaMaior(){
		assertTrue(marcioDe20Anos.compareTo(joaoDe17Anos) > 0);
	}
	
	@Test
	public void aPessoaDeMenorIdadeSeraConsideradaMenor(){
		assertTrue(joaoDe17Anos.compareTo(marcioDe20Anos) < 0);
		assertTrue(melanieDe17Anos.compareTo(marcioDe20Anos) < 0);
	}
	
	@Test
	public void seAsPessoasComparadasTemMesmaIdadeONomePorOrdemAlfabeticaSeraUsadoNaComparacao(){
		assertTrue(joaoDe17Anos.compareTo(melanieDe17Anos) < 0);
		assertTrue(melanieDe17Anos.compareTo(joaoDe17Anos) > 0);
	}
	
	@Test
	public void retornaPositivoQuandoMaiorNegativoQuandoMenorEZeroQuandoIgual(){
		assertTrue(marcioDe20Anos.compareTo(joaoDe17Anos) > 0);
		assertTrue(joaoDe17Anos.compareTo(marcioDe20Anos) < 0);
		assertTrue(marcioDe20Anos.compareTo(outroMarcioDe20Anos) == 0);
	}

}
