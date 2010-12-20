package testes;

import static infraEstrutura.Estruturas.ARVORE_AVL;
import static infraEstrutura.Estruturas.TABELA_HASH;
import static org.junit.Assert.*;

import java.io.File;
import java.io.IOException;
import java.io.RandomAccessFile;

import implementacao.Arquivador;
import implementacao.CatalogoDeLivros;
import implementacao.LivroConcreto;
import interfaces.Livro;

import org.junit.Before;
import org.junit.Test;


public class TestaCatalogoDeLivros {
	
	CatalogoDeLivros catalogo;
	private VisaoMock visaoMock;
	private String localizacaoDoArquivo = "fontes/infraEstrutura/arquivo.txt";
	private String titulo;
	private int codigo;
	private double preco;
	private String autor;
	Livro livro;
	
	@Before
	public void iniciar(){
		visaoMock = new VisaoMock();
		catalogo = new CatalogoDeLivros(visaoMock);
		codigo = 1;
		preco = 19.90;
		titulo = "Livro dos Codigos, O";
		autor = "Fulano";
		livro = new LivroConcreto(codigo, titulo, autor, preco);
	}
	
	@Test
	public void aoCarregarOArquivoEleMostraAConfirmacaoEmTela(){
		catalogo.carregar(localizacaoDoArquivo , ARVORE_AVL);
		
		assertEquals(localizacaoDoArquivo, visaoMock.obterLocalizacaoDoArquivo());
		assertEquals(ARVORE_AVL.toString(), visaoMock.obterEstrutura());
	}
	
	@Test
	public void aoTrocarAEstruturaEleMostraAConfirmacaoEmTela(){
		catalogo.carregar(localizacaoDoArquivo , ARVORE_AVL);
		catalogo.trocarEstrutura(TABELA_HASH);
		
		assertEquals(localizacaoDoArquivo, visaoMock.obterLocalizacaoDoArquivo());
		assertEquals(TABELA_HASH.toString(), visaoMock.obterEstrutura());
	}
	
	@Test
	public void inserirUmLivroAoCatalogo(){
		catalogo.insira(livro);
		
		assertEquals(livro, catalogo.procurePorCodigo(codigo));
	}
	
	@Test
	public void procurarPorCodigoValido(){
		catalogo.insira(livro);
		
		Livro livroObtido = catalogo.procurePorCodigo(codigo);
		
		assertEquals(livro, livroObtido);
		assertEquals(titulo, livroObtido.titulo());
		assertEquals(autor, livroObtido.autor());
		assertEquals(preco, livroObtido.preco());
	}
	
	@Test
	public void procurarPorCodigoInvalido(){
		catalogo.insira(livro);
		
		catalogo.procurePorCodigo(codigo + 1);
		
		assertEquals(codigo + 1, visaoMock.obterCodigoNaoEncontrado());
	}
	
	@Test
	public void aoProcurarUmLivroPorCodigoEleFixaOTempoDecorrido(){
		catalogo.insira(livro);
		
		assertEquals(livro, catalogo.procurePorCodigo(codigo));
		
		assertTrue(visaoMock.tempoFoiFixado());
	}
	
	@Test
	public void procurarPorTitulo(){
		catalogo.insira(livro);
		
		Livro livroObtido = catalogo.procurePorTitulo(titulo);
		
		assertEquals(livro, livroObtido);
		assertEquals(titulo, livroObtido.titulo());
		assertEquals(autor, livroObtido.autor());
		assertEquals(preco, livroObtido.preco());
	}
	
	@Test
	public void procurarPorTituloInexistente(){
		catalogo.insira(livro);
		
		catalogo.procurePorTitulo(titulo + "In");
		
		assertEquals(titulo + "In", visaoMock.obterTituloNaoEncontrado());
	}
	
	@Test
	public void procurarPorTituloExibeOTempoDecorrido(){
		catalogo.insira(livro);
		
		catalogo.procurePorTitulo(titulo);
		
		assertTrue(visaoMock.tempoFoiFixado());
	}

	@Test
	public void carregaTodosOsLivrosDeUmArquivo() throws IOException{
		String localizacaoDoArquivoTeste = "fontes/testes/arquivoTeste.txt";
		
		File arquivoComTresLivros = new File(localizacaoDoArquivoTeste);
		arquivoComTresLivros.createNewFile();
		
		Arquivador arquivador = new Arquivador(arquivoComTresLivros);
		
		arquivador.escreva(1);
		arquivador.escreva("Narnia");
		arquivador.escreva("Tiago");
		arquivador.escreva(9.9);
		
		arquivador.escreva(2);
		arquivador.escreva("Harry Potter");
		arquivador.escreva("Katcipis");
		arquivador.escreva(2.9);
		
		arquivador.escreva(3);
		arquivador.escreva("Senhor dos Aneis, o");
		arquivador.escreva("Cesar");
		arquivador.escreva(20.9);
		
		catalogo.carregar(localizacaoDoArquivoTeste, ARVORE_AVL);
		
		catalogo.procurePorCodigo(1);
		catalogo.procurePorCodigo(2);
		catalogo.procurePorCodigo(3);
		
		assertEquals("", visaoMock.obterCodigoNaoEncontrado());
	}
	
}
