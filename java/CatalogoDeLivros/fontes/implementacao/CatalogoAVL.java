package implementacao;

import ine5384.arvores.ArvoreBinaria;
import infraEstrutura.Ponteiro;
import infraEstrutura.estruturas.ArvoreBuscaBinariaAVL;
import infraEstrutura.excecoes.ExcecaoNaoEncontrado;
import interfaces.Catalogo;

public class CatalogoAVL implements Catalogo {
	
	private ArvoreBinaria<Ponteiro<String>> titulos;
	private ArvoreBinaria<Ponteiro<Integer>> codigos;

	public CatalogoAVL() {
		titulos = new ArvoreBuscaBinariaAVL<Ponteiro<String>>();
		codigos = new ArvoreBuscaBinariaAVL<Ponteiro<Integer>>();
	}

	public long pesquisarPorTitulo(String titulo) throws ExcecaoNaoEncontrado{
		Ponteiro<String> tituloFalso = new Ponteiro<String>(titulo, 0);
		Ponteiro<String> tituloObtido = titulos.retorna(tituloFalso);
		
		if(tituloObtido == null)
			throw new ExcecaoNaoEncontrado();
		
		return tituloObtido.localizacao();
	}

	public void inserirNovoTitulo(String titulo, long localizacao) {
		Ponteiro<String> novoTitulo = new Ponteiro<String>(titulo, localizacao);
		
		titulos.insere(novoTitulo);
	}

	public void inserirNovoCodigo(int codigo, long localizacao) {
		Ponteiro<Integer> novoCodigo = new Ponteiro<Integer>(codigo, localizacao);
		
		codigos.insere(novoCodigo);
	}

	public long pesquisarPorCodigo(int codigo) throws ExcecaoNaoEncontrado{
		Ponteiro<Integer> codigoFalso = new Ponteiro<Integer>(codigo, 0);
		Ponteiro<Integer> codigoObtido = codigos.retorna(codigoFalso);
		
		if(codigoObtido == null)
			throw new ExcecaoNaoEncontrado();
		
		return codigoObtido.localizacao();
	}
}
