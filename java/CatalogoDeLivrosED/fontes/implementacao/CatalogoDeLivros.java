package implementacao;

import infraEstrutura.Estruturas;
import infraEstrutura.excecoes.ExcecaoAutorInvalido;
import infraEstrutura.excecoes.ExcecaoCodigoRepetido;
import infraEstrutura.excecoes.ExcecaoCodigoInvalido;
import infraEstrutura.excecoes.ExcecaoLivroNaoEncontrado;
import infraEstrutura.excecoes.ExcecaoNomeInvalido;
import interfaces.Catalogo;

import java.io.File;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.StringTokenizer;

public class CatalogoDeLivros {
	private static final int TAMANHO_DO_STRING = 20;
	private static final int TAMANHO_MAXIMO_DO_CODIGO = 100000;
	private Catalogo catalogo;
	private RandomAccessFile arquivo;
	private long tempo = 999;

	public CatalogoDeLivros(){
		catalogo = Estruturas.ARVORE_AVL.obterCatalogo();
	}

	public void carregar(String localizacaoDoArquivo, Estruturas estrutura) throws IOException {
		this.catalogo = estrutura.obterCatalogo();
		this.catalogo.esvaziar();
		this.arquivo = new RandomAccessFile(localizacaoDoArquivo, "rw");
		
		long fim = arquivo.length();
		long posicao = 0;
		arquivo.seek(posicao);
		
		long inicio = System.currentTimeMillis();
		
		while(posicao < fim){
			LivroArquivo livro = new LivroArquivo();
			livro.leiaDoArquivo(arquivo);
			
			this.catalogo.inserirNovoLivro(livro, posicao);
			
			posicao = arquivo.getFilePointer();
		}
		
		tempo = System.currentTimeMillis() - inicio;
	}

	public void criarNovoArquivo(String localizacaoDoArquivo) throws IOException {
		StringTokenizer st = new StringTokenizer(localizacaoDoArquivo, "/");
		String nome = "";
		
		while(st.hasMoreTokens()){
			nome = st.nextToken();
		}
		String caminho = localizacaoDoArquivo.substring(0, localizacaoDoArquivo.length() - nome.length());
		
		
		File arquivo = new File(caminho);
		arquivo.mkdirs();
		
		arquivo = new File(localizacaoDoArquivo);
		arquivo.createNewFile();
		
		this.arquivo = new RandomAccessFile(arquivo, "rw");
		
		catalogo.esvaziar();
	}

	public LivroArquivo procurePorCodigo(int codigo) throws ExcecaoLivroNaoEncontrado, IOException, ExcecaoCodigoInvalido {
		if(codigo > TAMANHO_MAXIMO_DO_CODIGO)
			throw new ExcecaoCodigoInvalido();
		
		LivroArquivo livro = new LivroArquivo();

		long inicio = System.currentTimeMillis();
		
		long posicao = catalogo.pesquisarPorCodigo(codigo);
		arquivo.seek(posicao);
		livro.leiaDoArquivo(arquivo);
		
		tempo = System.currentTimeMillis() - inicio;

		return livro;
	}

	public void insira(LivroArquivo livro) throws IOException, ExcecaoCodigoInvalido, ExcecaoNomeInvalido, ExcecaoAutorInvalido, ExcecaoCodigoRepetido {
		if(livro.getCodigo() > TAMANHO_MAXIMO_DO_CODIGO)
			throw new ExcecaoCodigoInvalido();
		if(catalogo.contemCodigo(livro.getCodigo()))
			throw new ExcecaoCodigoRepetido();
		if(livro.getNome().length() > TAMANHO_DO_STRING)
			throw new ExcecaoNomeInvalido();
		if(livro.getAutor().length() > TAMANHO_DO_STRING)
			throw new ExcecaoAutorInvalido();
		
		long posicao = arquivo.getFilePointer();
		
		catalogo.inserirNovoLivro(livro, posicao);
		
		livro.escrevaNoArquivo(arquivo);
	}
	
	public void insiraNoFim(LivroArquivo livro) throws IOException, ExcecaoCodigoInvalido, ExcecaoNomeInvalido, ExcecaoAutorInvalido, ExcecaoCodigoRepetido {
		if(livro.getCodigo() > TAMANHO_MAXIMO_DO_CODIGO)
			throw new ExcecaoCodigoInvalido();
		if(catalogo.contemCodigo(livro.getCodigo()))
			throw new ExcecaoCodigoRepetido();
		if(livro.getNome().length() > TAMANHO_DO_STRING)
			throw new ExcecaoNomeInvalido();
		if(livro.getAutor().length() > TAMANHO_DO_STRING)
			throw new ExcecaoAutorInvalido();
		
		long posicao = arquivo.length();

		arquivo.seek(posicao);

		catalogo.inserirNovoLivro(livro, posicao);
		
		livro.escrevaNoArquivo(arquivo);
	}

	public LivroArquivo procurePorTitulo(String titulo) throws ExcecaoLivroNaoEncontrado, IOException, ExcecaoNomeInvalido {
		if(titulo.length() > TAMANHO_DO_STRING)
			throw new ExcecaoNomeInvalido();
		
		LivroArquivo livro = new LivroArquivo();

		long inicio = System.currentTimeMillis();
		
		long posicao = catalogo.pesquisarPorTitulo(titulo);
		arquivo.seek(posicao);
		livro.leiaDoArquivo(arquivo);
		
		tempo = System.currentTimeMillis() - inicio;

		return livro;
	}
	
	public long obterTempoDeProcessamento(){
		return tempo;
	}

}
