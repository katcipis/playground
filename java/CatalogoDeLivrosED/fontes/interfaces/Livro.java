package interfaces;


public interface Livro extends Comparable<Livro>{

	String titulo();

	int codigo();

	String autor();

	double preco();

	void fixarPreco(double novoPreco);

	void fixarComparador(Comparador comparador);

}
