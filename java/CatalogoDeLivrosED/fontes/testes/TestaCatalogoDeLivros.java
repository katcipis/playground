package testes;

import static infraEstrutura.Estruturas.ARVORE_AVL;
import static infraEstrutura.Estruturas.TABELA_HASH;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;
import implementacao.CatalogoDeLivros;
import implementacao.LivroArquivo;
import infraEstrutura.excecoes.ExcecaoCodigoRepetido;
import infraEstrutura.excecoes.ExcecaoLivroNaoEncontrado;

import java.io.File;
import java.io.IOException;
import java.io.RandomAccessFile;

import org.junit.Before;
import org.junit.Test;


public class TestaCatalogoDeLivros {
	
	CatalogoDeLivros catalogoAVL, catalogoHash;
	private String localizacaoDoArquivoEmBranco = "fontes/infraEstrutura/arquivo.txt";
	private String localizacaoDoArquivoTeste = "fontes/testes/arquivoTeste.txt";
	private String nomeDoLivro1;
	private int codigoDoLivro1;
	private double precoDoLivro1;
	private String autorDoLivro1;
	LivroArquivo livro1, livro2, livro3;
	private int quantidadeDeLivros1;
	
	@Before
	public void iniciar() throws IOException{
		nomeDoLivro1 = "Livro 1";
		codigoDoLivro1 = 1;
		autorDoLivro1 = "Autor 1";
		precoDoLivro1 = 1.11;
		quantidadeDeLivros1 = 10;
		
		this.criarArquivoTeste();
		
		File arquivo = new File(localizacaoDoArquivoEmBranco);
		arquivo.delete();
		arquivo.createNewFile();
		
		catalogoAVL = new CatalogoDeLivros();
		catalogoAVL.carregar(localizacaoDoArquivoEmBranco, ARVORE_AVL);
		
		catalogoHash = new CatalogoDeLivros();
		catalogoHash.carregar(localizacaoDoArquivoEmBranco, TABELA_HASH);
	}
	
	@Test
	public void inserirUmLivroAoCatalogo() throws Exception{
		catalogoAVL.insira(livro1);
		catalogoHash.insira(livro1);
		
		assertEquals(livro1, catalogoAVL.procurePorCodigo(codigoDoLivro1));
		assertEquals(livro1, catalogoHash.procurePorCodigo(codigoDoLivro1));
	}
	
	@Test(expected = ExcecaoCodigoRepetido.class)
	public void naoPodeInserirLivrosComMesmoCodigo() throws Exception{
		catalogoAVL.carregar(localizacaoDoArquivoTeste, ARVORE_AVL);
		catalogoHash.carregar(localizacaoDoArquivoTeste, TABELA_HASH);
		
		catalogoAVL.insira(livro1);
		catalogoHash.insira(livro1);
	}
	
	@Test
	public void procurarPorCodigoValidoEmCatalogoAVL() throws Exception{
		catalogoAVL.insira(livro1);
		
		LivroArquivo livroObtido = catalogoAVL.procurePorCodigo(codigoDoLivro1);
		
		assertEquals(livro1, livroObtido);
		assertEquals(nomeDoLivro1, livroObtido.getNome());
		assertEquals(autorDoLivro1, livroObtido.getAutor());
		assertEquals(precoDoLivro1, livroObtido.getPreco());
		assertEquals(quantidadeDeLivros1, livroObtido.getQuantidade());
	}
	
	@Test
	public void procurarPorCodigoValidoEmCatalogoHash() throws Exception {
		catalogoHash.insira(livro1);
		
		LivroArquivo livroObtido = catalogoHash.procurePorCodigo(codigoDoLivro1);
		
		assertEquals(livro1, livroObtido);
		assertEquals(nomeDoLivro1, livroObtido.getNome());
		assertEquals(autorDoLivro1, livroObtido.getAutor());
		assertEquals(precoDoLivro1, livroObtido.getPreco());
		assertEquals(quantidadeDeLivros1, livroObtido.getQuantidade());
	}
	
	@Test(expected = ExcecaoLivroNaoEncontrado.class)
	public void procurarPorCodigoInvalidoEmCatalogoAVL() throws Exception {
		catalogoAVL.insira(livro1);
		
		catalogoAVL.procurePorCodigo(codigoDoLivro1 + 1);
	}
	
	@Test(expected = ExcecaoLivroNaoEncontrado.class)
	public void procurarPorCodigoInvalidoEmCatalogoHash() throws Exception{
		catalogoHash.insira(livro1);
		
		catalogoHash.procurePorCodigo(codigoDoLivro1 + 1);
	}
	
	@Test
	public void aoProcurarUmLivroPorCodigoEleFixaOTempoDecorrido() throws Exception {
		catalogoAVL.insira(livro1);
		
		assertEquals(livro1, catalogoAVL.procurePorCodigo(codigoDoLivro1));
		assertTrue(catalogoAVL.obterTempoDeProcessamento() != 100);
	}
	
	@Test
	public void procurarPorTituloEmCatalogoAVL() throws Exception{
		catalogoAVL.insira(livro1);
		
		LivroArquivo livroObtido = catalogoAVL.procurePorTitulo(nomeDoLivro1);
		
		assertEquals(livro1, livroObtido);
		assertEquals(nomeDoLivro1, livroObtido.getNome());
		assertEquals(autorDoLivro1, livroObtido.getAutor());
		assertEquals(precoDoLivro1, livroObtido.getPreco());
		assertEquals(quantidadeDeLivros1, livroObtido.getQuantidade());
	}
	
	@Test
	public void procurarPorTituloEmCatalogoHash() throws Exception{
		catalogoHash.insira(livro1);
		
		LivroArquivo livroObtido = catalogoHash.procurePorTitulo(nomeDoLivro1);
		
		assertEquals(livro1, livroObtido);
		assertEquals(nomeDoLivro1, livroObtido.getNome());
		assertEquals(autorDoLivro1, livroObtido.getAutor());
		assertEquals(precoDoLivro1, livroObtido.getPreco());
		assertEquals(quantidadeDeLivros1, livroObtido.getQuantidade());
	}
	
	@Test(expected = ExcecaoLivroNaoEncontrado.class)
	public void procurarPorTituloInexistenteEmCatalogoAVl() throws Exception{
		catalogoAVL.insira(livro1);
		
		catalogoAVL.procurePorTitulo(nomeDoLivro1 + "In");
	}
	
	@Test(expected = ExcecaoLivroNaoEncontrado.class)
	public void procurarPorTituloInexistenteEmCatalogoHash() throws Exception{
		catalogoHash.insira(livro1);
		
		catalogoHash.procurePorTitulo(nomeDoLivro1 + "In");
	}
	
	@Test
	public void procurarPorTituloExibeOTempoDecorrido() throws Exception{
		catalogoAVL.insira(livro1);
		
		catalogoAVL.procurePorTitulo(nomeDoLivro1);
		
		assertTrue(catalogoAVL.obterTempoDeProcessamento() != 100);
	}

	private void criarArquivoTeste() throws IOException{
		File arquivoTeste = new File(localizacaoDoArquivoTeste);
		arquivoTeste.delete();
		arquivoTeste.createNewFile();
		
		RandomAccessFile arquivoComTresLivros = new RandomAccessFile(arquivoTeste, "rw");
		arquivoComTresLivros.seek(0);
		
		livro1 = new LivroArquivo(1, nomeDoLivro1, autorDoLivro1, precoDoLivro1, quantidadeDeLivros1);
		livro1.escrevaNoArquivo(arquivoComTresLivros);
		
		livro2 = new LivroArquivo(2, "Livro 2", "Autor 2", 2.22, 20);
		livro2.escrevaNoArquivo(arquivoComTresLivros);
		
		livro3 = new LivroArquivo(3, "Livro 3", "Autor 3", 3.33, 30);
		livro3.escrevaNoArquivo(arquivoComTresLivros);
	}
	
	@Test
	public void carregaTodosOsLivrosDeUmArquivo() throws IOException, Exception{
		
		CatalogoDeLivros catalogo = new CatalogoDeLivros();
		
		catalogo.carregar(localizacaoDoArquivoTeste, ARVORE_AVL);
		
		assertEquals(livro1, catalogo.procurePorCodigo(1));
		assertEquals(livro2, catalogo.procurePorCodigo(2));
		assertEquals(livro3, catalogo.procurePorCodigo(3));
		
		catalogo.carregar(localizacaoDoArquivoTeste, TABELA_HASH);
		
		assertEquals(livro1, catalogo.procurePorCodigo(1));
		assertEquals(livro2, catalogo.procurePorCodigo(2));
		assertEquals(livro3, catalogo.procurePorCodigo(3));
	}
	
}
