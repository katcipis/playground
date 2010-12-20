package infraEstrutura.comparadores;

import interfaces.Comparador;
import interfaces.Livro;

public class ComparadorDeCodigo implements Comparador {
	
	private static Comparador eu = null;

	private ComparadorDeCodigo(){
	}

	public static Comparador obter() {
		if(eu == null)
			eu = new ComparadorDeCodigo();
		return eu;
	}

	public int compare(Livro livroUm, Livro livroDois) {
		return livroUm.codigo() - livroDois.codigo();
	}

}
