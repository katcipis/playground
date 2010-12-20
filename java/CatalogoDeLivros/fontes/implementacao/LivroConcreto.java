package implementacao;

import interfaces.Comparador;
import interfaces.Livro;

public class LivroConcreto implements Livro {

	private static final int CASAS_DECIMAIS = 100;
	private final int codigo;
	private final String nome;
	private final String autor;
	private int preco;
	private Comparador comparador;

	public LivroConcreto(int codigoUm, String nomeUm, String autorUm, double preco) {
		this.codigo = codigoUm;
		this.nome = nomeUm;
		this.autor = autorUm;
		this.preco = (int) (preco * CASAS_DECIMAIS);
	}
	
	public boolean equals(Object o){
		if (!(o instanceof LivroConcreto))
			return false;
		return this.codigo == ((Livro) o).codigo();
	}

	public String titulo() {
		return nome;
	}

	public int codigo() {
		return codigo;
	}

	public String autor() {
		return autor;
	}

	public double preco() {
		return (double) preco / CASAS_DECIMAIS;
	}

	public void fixarPreco(double novoPreco) {
		preco = (int) (novoPreco * CASAS_DECIMAIS);
	}

	public void fixarComparador(Comparador comparador) {
		this.comparador = comparador;
	}

	public int compareTo(Livro outroLivro) {
		return comparador.compare(this, outroLivro);
	}

}
