package implementacao;

import infraEstrutura.Estruturas;
import infraEstrutura.estruturas.TabelaHash;
import infraEstrutura.estruturas.TabelaHashConcreta;
import infraEstrutura.excecoes.ExcecaoNaoEncontrado;
import interfaces.Catalogo;
import interfaces.Livro;
import interfaces.Visao;

import java.io.File;
import java.io.IOException;

public class CatalogoDeLivros {
	private final Visao visao;
	private String localizacaoDoArquivo = "fontes/infraEstrutura/arquivo.txt";
	private Catalogo catalogo = new CatalogoAVL();
	private Arquivador arquivador;
	private TabelaHash<Estruturas, Catalogo> tabela;

	public CatalogoDeLivros(Visao visao) {
		this.visao = visao;
		this.arquivador = new Arquivador(obterArquivo(localizacaoDoArquivo));
		tabela = new TabelaHashConcreta<Estruturas, Catalogo>();
		tabela.insere(Estruturas.TABELA_HASH, new CatalogoHash());
		tabela.insere(Estruturas.ARVORE_AVL, new CatalogoAVL());
	}

	public void carregar(String localizacaoDoArquivo, Estruturas estrutura) {
		catalogo = tabela.retorna(estrutura);
		this.localizacaoDoArquivo = localizacaoDoArquivo;
		arquivador = new Arquivador(obterArquivo(localizacaoDoArquivo));
		visao.mostrarConfirmacaoDeCarregamento(localizacaoDoArquivo, estrutura.toString());
	}

	private File obterArquivo(String localizacaoDoArquivo) {
		File arquivo = new File(localizacaoDoArquivo);
		try {
			arquivo.createNewFile();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return arquivo;
	}

	public void trocarEstrutura(Estruturas estrutura) {
		visao.mostrarConfirmacaoDeCarregamento(localizacaoDoArquivo, estrutura.toString());
	}

	public Livro procurePorCodigo(int codigo) {
		Livro livro = new LivroNulo();
		
		long inicio = System.currentTimeMillis();
		
		try {
			
			long posicao = catalogo.pesquisarPorCodigo(codigo);
			String titulo = arquivador.leiaTexto(posicao + 4);
			String autor = arquivador.leiaTexto();
			double valor = arquivador.leiaDouble();
			
			livro =  new LivroConcreto(codigo, titulo, autor, valor);
			
		} catch (ExcecaoNaoEncontrado e) {
			visao.livroNaoEncontrado(codigo);
		}
		
		long tempo = inicio - System.currentTimeMillis();
		
		visao.fixarTempoDecorrido(tempo);
		
		return livro;
	}

	public void insira(Livro livro) {
		arquivador.vaPara(arquivador.fim());
		
		catalogo.inserirNovoCodigo(livro.codigo(), arquivador.escreva(livro.codigo()));
		catalogo.inserirNovoTitulo(livro.titulo(), arquivador.escreva(livro.titulo()));
		arquivador.escreva(livro.autor());
		arquivador.escreva(livro.preco());
	}

	public Livro procurePorTitulo(String titulo) {
		Livro livro = new LivroNulo();
		
		long inicio = System.currentTimeMillis();
		
		try {
			long posicao = catalogo.pesquisarPorTitulo(titulo);
			
			long tempo = inicio - System.currentTimeMillis();
			
			visao.fixarTempoDecorrido(tempo);
			
			int codigo = arquivador.leiaInteiro(posicao - 4);
			arquivador.puleBytes(22);
			String autor = arquivador.leiaTexto();
			double valor = arquivador.leiaDouble();
			
			livro = new LivroConcreto(codigo, titulo, autor, valor);
			
		} catch (ExcecaoNaoEncontrado e) {
			visao.livroNaoEncontrado(titulo);
		}
		
		return livro;
	}

}
