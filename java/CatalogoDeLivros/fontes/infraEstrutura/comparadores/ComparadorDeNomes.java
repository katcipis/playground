package infraEstrutura.comparadores;

import interfaces.Comparador;
import interfaces.Livro;

public class ComparadorDeNomes implements Comparador {

	private static Comparador eu;

	public int compare(Livro livroUm, Livro livroDois) {
		return livroUm.titulo().compareTo(livroDois.titulo());
	}

	public static Comparador obter() {
		if(eu == null)
			eu = new ComparadorDeNomes();
		return eu;
	}

}
