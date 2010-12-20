package interfaces;

import implementacao.LivroArquivo;
import infraEstrutura.excecoes.ExcecaoLivroNaoEncontrado;

public interface Catalogo {

	long pesquisarPorTitulo(String titulo) throws ExcecaoLivroNaoEncontrado;

	void inserirNovoLivro(LivroArquivo livro, long localizacao);

	long pesquisarPorCodigo(int codigo) throws ExcecaoLivroNaoEncontrado;

	void esvaziar();

	boolean contemCodigo(int codigo);
}
