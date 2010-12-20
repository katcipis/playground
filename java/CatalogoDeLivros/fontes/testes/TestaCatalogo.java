package testes;

import static org.junit.Assert.*;
import implementacao.CatalogoAVL;
import implementacao.CatalogoHash;
import infraEstrutura.excecoes.ExcecaoNaoEncontrado;
import interfaces.Catalogo;

import org.junit.Before;
import org.junit.Test;


public class TestaCatalogo {
	
	private Catalogo catalogoAVL, catalogoHash;
	private long localizacao = 123;
	private String titulo1 = "nomeDoTitulo";
	private int codigo = 12324;
	
	@Before
	public void iniciar(){
		catalogoAVL = new CatalogoAVL();
		catalogoHash = new CatalogoHash();
	}

	@Test
	public void inserirUmTituloNoCatalogoAVL() throws ExcecaoNaoEncontrado {
		catalogoAVL.inserirNovoTitulo(titulo1, localizacao);
		
		assertSame(localizacao, catalogoAVL.pesquisarPorTitulo(titulo1));
	}
	
	@Test (expected = ExcecaoNaoEncontrado.class)
	public void pesquisarPorTituloInexistenteNoCatalogoAVL() throws ExcecaoNaoEncontrado {
		catalogoAVL.inserirNovoTitulo(titulo1 , localizacao);
		
		assertSame(localizacao, catalogoAVL.pesquisarPorTitulo(titulo1 + "Ine"));
	}
	
	@Test
	public void inserirUmcodigoNoCatalogoAVL() throws ExcecaoNaoEncontrado {
		catalogoAVL.inserirNovoCodigo(codigo , localizacao);
		
		assertSame(localizacao, catalogoAVL.pesquisarPorCodigo(codigo));
	}
	
	@Test (expected = ExcecaoNaoEncontrado.class)
	public void pesquisarPorCodigoInexistenteNoCatalogoAVL() throws ExcecaoNaoEncontrado {
		catalogoAVL.inserirNovoCodigo(codigo , localizacao);
		
		assertSame(localizacao, catalogoAVL.pesquisarPorCodigo(codigo + 132));
	}
	
	@Test
	public void inserirUmTituloNoCatalogoHash() throws ExcecaoNaoEncontrado {
		catalogoHash.inserirNovoTitulo(titulo1, localizacao);
		
		assertSame(localizacao, catalogoHash.pesquisarPorTitulo(titulo1));
	}
	
	@Test (expected = ExcecaoNaoEncontrado.class)
	public void pesquisarPorTituloInexistenteNoCatalogoHash() throws ExcecaoNaoEncontrado {
		catalogoHash.inserirNovoTitulo(titulo1 , localizacao);
		
		assertSame(localizacao, catalogoHash.pesquisarPorTitulo(titulo1 + "Ine"));
	}
	
	@Test
	public void inserirUmCodigoNoCatalogoHash() throws ExcecaoNaoEncontrado {
		catalogoHash.inserirNovoCodigo(codigo , localizacao);
		
		assertSame(localizacao, catalogoHash.pesquisarPorCodigo(codigo));
	}
	
	@Test (expected = ExcecaoNaoEncontrado.class)
	public void pesquisarPorCodigoInexistenteNoCatalogoHash() throws ExcecaoNaoEncontrado {
		catalogoHash.inserirNovoCodigo(codigo , localizacao);
		
		assertSame(localizacao, catalogoHash.pesquisarPorCodigo(codigo + 12));
	}

}
