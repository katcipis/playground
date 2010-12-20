package interfaces;

import infraEstrutura.excecoes.ExcecaoNaoEncontrado;

public interface Catalogo {

	void inserirNovoTitulo(String titulo, long localizacao);

	long pesquisarPorTitulo(String titulo) throws ExcecaoNaoEncontrado;

	void inserirNovoCodigo(int codigo, long localizacao);

	long pesquisarPorCodigo(int codigo) throws ExcecaoNaoEncontrado;
}
