package testes;

import interfaces.Visao;

public class VisaoMock implements Visao {

	private String localizacaoDoArquivo = "nenhum";
	private String estrutura = "nenhum";
	private boolean tempoFixado = false;
	private int codigoNaoEncontrado;
	private String tituloNaoEncontrado;

	public void mostrarConfirmacaoDeCarregamento(String localizacaoDoArquivo,
			String estrutura) {
		this.localizacaoDoArquivo = localizacaoDoArquivo;
		this.estrutura = estrutura;
	}

	public String obterLocalizacaoDoArquivo() {
		return localizacaoDoArquivo;
	}

	public String obterEstrutura() {
		return estrutura;
	}

	public boolean tempoFoiFixado() {
		return tempoFixado ;
	}

	public void fixarTempoDecorrido(long tempo) {
		System.out.println(tempo);
		tempoFixado = true;
	}

	public void livroNaoEncontrado(int codigo) {
		codigoNaoEncontrado = codigo;
	}

	public void livroNaoEncontrado(String titulo) {
		tituloNaoEncontrado = titulo;
	}

	public int obterCodigoNaoEncontrado() {
		return codigoNaoEncontrado;
	}

	public String obterTituloNaoEncontrado() {
		return tituloNaoEncontrado;
	}

}
