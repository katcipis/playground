package infraEstrutura.comparadores;

import interfaces.Comparador;
import interfaces.Livro;

public class ComparadorDeAutores implements Comparador {

	private static Comparador eu;

	public int compare(Livro livroUm, Livro livroDois) {
		return livroUm.autor().compareTo(livroDois.autor());
	}

	public static Comparador obter() {
		if(eu == null)
			eu = new ComparadorDeAutores();
		return eu;
	}

}
