package infraestrutura.pessoa;

public class Pessoa implements Comparable<Pessoa>{

	private final String nome;
	private final Integer idade;
	
	public Pessoa(String nome, Integer idade){
		this.nome = nome;
		this.idade = idade;
	}
	
	public int compareTo(Pessoa pessoa) {
		Integer valorDaComparacao = 0;
		
		if(this.idade > pessoa.obterIdade())
			valorDaComparacao = 1;
		
		if(this.idade < pessoa.obterIdade())
			valorDaComparacao = -1;
		
		if(pessoa.obterIdade() == this.idade){
			String nomeDaPessoa = pessoa.obterNome();
			valorDaComparacao = this.nome.compareTo(nomeDaPessoa);
		}
		
		return valorDaComparacao;
	}

	public Integer obterIdade(){
		return idade;
	}
	
	public String obterNome(){
		return nome;
	}
	
	@Override
	public String toString(){
		return nome + idade;
	}

}
