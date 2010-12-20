package implementacao;

import ine5384.arvores.ArvoreBinaria;
import infraEstrutura.Ponteiro;
import infraEstrutura.estruturas.ArvoreBuscaBinariaAVL;
import infraEstrutura.excecoes.ExcecaoLivroNaoEncontrado;
import interfaces.Catalogo;

public class CatalogoAVL implements Catalogo {
	
	private ArvoreBinaria<Ponteiro<String>> titulos;
	private ArvoreBinaria<Ponteiro<Integer>> codigos;

	public CatalogoAVL() {
		titulos = new ArvoreBuscaBinariaAVL<Ponteiro<String>>();
		codigos = new ArvoreBuscaBinariaAVL<Ponteiro<Integer>>();
	}

	public long pesquisarPorTitulo(String titulo) throws ExcecaoLivroNaoEncontrado{
		
		Ponteiro<String> tituloNovo = new Ponteiro<String>(titulo, 0);
		
		Ponteiro<String> tituloObtido = titulos.retorna(tituloNovo);
		
		if(tituloObtido == null)
			throw new ExcecaoLivroNaoEncontrado();
		
		return tituloObtido.localizacao();
	}

	public long pesquisarPorCodigo(int codigo) throws ExcecaoLivroNaoEncontrado{
		Ponteiro<Integer> codigoNovo = new Ponteiro<Integer>(codigo, 0);
		Ponteiro<Integer> codigoObtido = codigos.retorna(codigoNovo);
		
		if(codigoObtido == null)
			throw new ExcecaoLivroNaoEncontrado();
		
		return codigoObtido.localizacao();
	}

	public void esvaziar() {
		this.codigos.esvazie();
		this.titulos.esvazie();
	}

	public boolean contemCodigo(int codigo) {
		Ponteiro<Integer> ponteiroNovo = new Ponteiro<Integer>(codigo, 0);
		return codigos.contem(ponteiroNovo);
	}

	public void inserirNovoLivro(LivroArquivo livro, long localizacao) {
			Ponteiro<String> novoTitulo = new Ponteiro<String>(livro.getNome(), localizacao);
			titulos.insere(novoTitulo);
			
			Ponteiro<Integer> novoCodigo = new Ponteiro<Integer>(livro.getCodigo(), localizacao);
			codigos.insere(novoCodigo);
	}
}
