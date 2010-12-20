package testes;

import static org.junit.Assert.*;
import implementacao.CatalogoAVL;
import implementacao.CatalogoHash;
import implementacao.LivroArquivo;
import infraEstrutura.excecoes.ExcecaoLivroNaoEncontrado;
import interfaces.Catalogo;

import org.junit.Before;
import org.junit.Test;


public class TestaCatalogo {
	
	private Catalogo catalogoAVL, catalogoHash;
	private long localizacao = 123;
	private String titulo = "nomeDoTitulo";
	private int codigo = 12324;
	private LivroArquivo livro;
	
	@Before
	public void iniciar(){
		catalogoAVL = new CatalogoAVL();
		catalogoHash = new CatalogoHash();
		livro = new LivroArquivo(codigo, titulo, "",0,0);
	}

	@Test
	public void inserirUmTituloNoCatalogoAVL() throws ExcecaoLivroNaoEncontrado {
		catalogoAVL.inserirNovoLivro(livro, localizacao);
		
		assertSame(localizacao, catalogoAVL.pesquisarPorTitulo(titulo));
	}
	
	@Test (expected = ExcecaoLivroNaoEncontrado.class)
	public void pesquisarPorTituloInexistenteNoCatalogoAVL() throws ExcecaoLivroNaoEncontrado {
		catalogoAVL.inserirNovoLivro(livro, localizacao);
		
		assertSame(localizacao, catalogoAVL.pesquisarPorTitulo(titulo + "Ine"));
	}
	
	@Test
	public void inserirUmcodigoNoCatalogoAVL() throws ExcecaoLivroNaoEncontrado {
		catalogoAVL.inserirNovoLivro(livro, localizacao);
		
		assertSame(localizacao, catalogoAVL.pesquisarPorCodigo(codigo));
	}
	
	@Test (expected = ExcecaoLivroNaoEncontrado.class)
	public void pesquisarPorCodigoInexistenteNoCatalogoAVL() throws ExcecaoLivroNaoEncontrado {
		catalogoAVL.inserirNovoLivro(livro, localizacao);
		
		assertSame(localizacao, catalogoAVL.pesquisarPorCodigo(codigo + 132));
	}
	
	@Test
	public void inserirUmTituloNoCatalogoHash() throws ExcecaoLivroNaoEncontrado {
		catalogoHash.inserirNovoLivro(livro, localizacao);
		
		assertSame(localizacao, catalogoHash.pesquisarPorTitulo(titulo));
	}
	
	@Test (expected = ExcecaoLivroNaoEncontrado.class)
	public void pesquisarPorTituloInexistenteNoCatalogoHash() throws ExcecaoLivroNaoEncontrado {
		catalogoHash.inserirNovoLivro(livro, localizacao);
		
		assertSame(localizacao, catalogoHash.pesquisarPorTitulo(titulo + "Ine"));
	}
	
	@Test
	public void inserirUmCodigoNoCatalogoHash() throws ExcecaoLivroNaoEncontrado {
		catalogoHash.inserirNovoLivro(livro, localizacao);
		
		assertSame(localizacao, catalogoHash.pesquisarPorCodigo(codigo));
	}
	
	@Test (expected = ExcecaoLivroNaoEncontrado.class)
	public void pesquisarPorCodigoInexistenteNoCatalogoHash() throws ExcecaoLivroNaoEncontrado {
		catalogoHash.inserirNovoLivro(livro, localizacao);
		
		assertSame(localizacao, catalogoHash.pesquisarPorCodigo(codigo + 12));
	}

}
