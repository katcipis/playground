package implementacao;

import infraEstrutura.estruturas.TabelaHash;
import infraEstrutura.estruturas.TabelaHashConcreta;
import infraEstrutura.excecoes.ExcecaoNaoEncontrado;
import interfaces.Catalogo;

public class CatalogoHash implements Catalogo {
	
	private TabelaHash<String, Long> titulos;
	private TabelaHash<Integer, Long> codigos;
	
	public CatalogoHash(){
		codigos = new TabelaHashConcreta<Integer, Long>();
		titulos = new TabelaHashConcreta<String, Long>();
	}

	public void inserirNovoCodigo(int codigo, long localizacao) {
		codigos.insere(codigo, localizacao);
	}

	public void inserirNovoTitulo(String titulo, long localizacao) {
		titulos.insere(titulo, localizacao);
	}

	public long pesquisarPorCodigo(int codigo) throws ExcecaoNaoEncontrado {
		long posicao;
		
		try {
			posicao = codigos.retorna(codigo);
			posicao = posicao + 0;
		} catch (NullPointerException e) {
			throw new ExcecaoNaoEncontrado();
		}
		return posicao;
	}

	public long pesquisarPorTitulo(String titulo) throws ExcecaoNaoEncontrado {
long posicao;
		
		try {
			posicao = titulos.retorna(titulo);
			posicao = posicao + 0;
		} catch (NullPointerException e) {
			throw new ExcecaoNaoEncontrado();
		}
		return posicao;
	}

}
