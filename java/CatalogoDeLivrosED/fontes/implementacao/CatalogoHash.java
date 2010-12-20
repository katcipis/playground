package implementacao;

import infraEstrutura.estruturas.TabelaHash;
import infraEstrutura.estruturas.TabelaHashConcreta;
import infraEstrutura.excecoes.ExcecaoLivroNaoEncontrado;
import interfaces.Catalogo;

public class CatalogoHash implements Catalogo {
	
	private TabelaHash<String, Long> titulos;
	private TabelaHash<Integer, Long> codigos;
	
	public CatalogoHash(){
		codigos = new TabelaHashConcreta<Integer, Long>();
		titulos = new TabelaHashConcreta<String, Long>();
	}

	public void inserirNovoLivro(LivroArquivo livro, long localizacao) {
		codigos.insere(livro.getCodigo(), localizacao);
		titulos.insere(livro.getNome(), localizacao);
	}

	public long pesquisarPorCodigo(int codigo) throws ExcecaoLivroNaoEncontrado {
		
		long posicao;
		
		try {
			
			posicao = codigos.retorna(codigo);
			
		} catch (NullPointerException e) {
			throw new ExcecaoLivroNaoEncontrado();
		}
		return posicao;
	}

	public long pesquisarPorTitulo(String titulo) throws ExcecaoLivroNaoEncontrado {
		
		long posicao;
		
		try {
			
			posicao = titulos.retorna(titulo);
			
		} catch (NullPointerException e) {
			throw new ExcecaoLivroNaoEncontrado();
		}
		return posicao;
	}

	public void esvaziar() {
		this.codigos.esvazie();
		this.titulos.esvazie();
	}

	public boolean contemCodigo(int codigo) {
		return codigos.existe(codigo);
	}

}
