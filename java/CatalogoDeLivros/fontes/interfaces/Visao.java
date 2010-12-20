package interfaces;

public interface Visao {

	void mostrarConfirmacaoDeCarregamento(String localizacaoDoArquivo,
			String estrutura);

	void fixarTempoDecorrido(long tempo);

	void livroNaoEncontrado(int codigo);

	void livroNaoEncontrado(String titulo);

}
