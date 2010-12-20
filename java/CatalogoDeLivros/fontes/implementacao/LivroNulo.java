package implementacao;

import interfaces.Comparador;
import interfaces.Livro;

public class LivroNulo implements Livro {

	public String autor() {
		return "Autor Nulo";
	}

	public int codigo() {
		return 0;
	}

	public void fixarComparador(Comparador comparador) {
	}

	public void fixarPreco(double novoPreco) {
	}

	public double preco() {
		return 0;
	}

	public String titulo() {
		return "Titulo Nulo";
	}

	public int compareTo(Livro o) {
		return -1;
	}

}
