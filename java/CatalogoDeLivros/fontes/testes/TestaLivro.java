package testes;

import static org.junit.Assert.*;
import implementacao.LivroConcreto;
import infraEstrutura.comparadores.ComparadorDeAutores;
import infraEstrutura.comparadores.ComparadorDeCodigo;
import infraEstrutura.comparadores.ComparadorDeNomes;
import interfaces.Livro;

import org.junit.Before;
import org.junit.Test;

public class TestaLivro {
	
	private String nomeDoLivro, outroNome;
	private Livro livro, outroLivro;
	private int codigoDoLivro, outroCodigo;
	private String autorDoLivro, outroAutor;
	private double precoDoLivro, outroPreco;

	@Before
	public void iniciar(){
		nomeDoLivro = "Matematica Aplicada";
		
		codigoDoLivro = 5;
		
		autorDoLivro = "Autor F";
		
		precoDoLivro = 26.90;
		
		livro = new LivroConcreto(codigoDoLivro, nomeDoLivro, autorDoLivro, precoDoLivro);
	}
	
	@Test
	public void umLivroSabeOSeuCodigo(){
		assertEquals(codigoDoLivro, livro.codigo());
	}
	
	@Test
	public void umLivroSabeOSeuNome(){
		assertEquals(nomeDoLivro, livro.titulo());
	}
	
	@Test
	public void umLivroSabeOSeuAutor(){
		assertEquals(autorDoLivro, livro.autor());
	}
	
	@Test
	public void umLivroSabeOSeuPreco(){
		assertEquals(precoDoLivro, livro.preco());
	}
	
	@Test
	public void umLivroPodeTerSeuPrecoModificado(){
		outroPreco = 5.00;
		livro.fixarPreco(outroPreco);
		
		assertEquals(outroPreco, livro.preco());
	}
	
	@Test
	public void livrosSaoIguaisSeTiveremCodigosIguais(){
		outroLivro = new LivroConcreto(codigoDoLivro, "nomeQualquer", "autorQualquer", 0.00);
		
		assertEquals(outroLivro, livro);
	}
	
	@Test
	public void livrosSaoDiferentesSeTiveremCodigosDiferentes(){
		outroCodigo = 2;
		outroLivro = new LivroConcreto(outroCodigo, nomeDoLivro, autorDoLivro, precoDoLivro);
		
		assertFalse(outroLivro.equals(livro));
	}
	
	@Test
	public void LivrosComparadosPorCodigoICasoMaior(){
		outroCodigo = 1;
		outroLivro = new LivroConcreto(outroCodigo, nomeDoLivro, autorDoLivro, precoDoLivro);
		
		livro.fixarComparador(ComparadorDeCodigo.obter());
		
		assertTrue(livro.compareTo(outroLivro) > 0);
	}
	
	@Test
	public void LivrosComparadosPorCodigoIICasoMenor(){
		outroCodigo = 10;
		outroLivro = new LivroConcreto(outroCodigo, nomeDoLivro, autorDoLivro, precoDoLivro);
		
		livro.fixarComparador(ComparadorDeCodigo.obter());
		
		assertTrue(livro.compareTo(outroLivro) < 0);
	}
	
	@Test
	public void LivrosComparadosPorNomeICasoMaior(){
		outroNome = "Cortiço, O";
		outroLivro = new LivroConcreto(codigoDoLivro, outroNome, autorDoLivro, precoDoLivro);
		
		livro.fixarComparador(ComparadorDeNomes.obter());
		
		assertTrue(livro.compareTo(outroLivro) > 0);
	}
	
	@Test
	public void LivrosComparadosPorNomeIICasoMenor(){
		outroNome = "Sistemas Operacionais";
		outroLivro = new LivroConcreto(codigoDoLivro, outroNome, autorDoLivro, precoDoLivro);
		
		livro.fixarComparador(ComparadorDeNomes.obter());
		
		assertTrue(livro.compareTo(outroLivro) < 0);
	}
	
	@Test
	public void LivrosComparadosPorAutorICasoMaior(){
		outroAutor = "Autor A";
		outroLivro = new LivroConcreto(codigoDoLivro, nomeDoLivro, outroAutor, precoDoLivro);
		
		livro.fixarComparador(ComparadorDeAutores.obter());
		
		assertTrue(livro.compareTo(outroLivro) > 0);
	}
	
	@Test
	public void LivrosComparadosPorAutorIICasoMenor(){
		outroAutor = "Autor R";
		outroLivro = new LivroConcreto(codigoDoLivro, nomeDoLivro, outroAutor, precoDoLivro);
		
		livro.fixarComparador(ComparadorDeAutores.obter());
		
		assertTrue(livro.compareTo(outroLivro) < 0);
	}

}
