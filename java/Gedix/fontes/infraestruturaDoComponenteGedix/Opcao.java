package infraestruturaDoComponenteGedix;

public class Opcao {
	
	private final String nome;
	private String texto;

	public Opcao(String nome){
		this.nome = nome;
		texto = nome;
	}
	
	public String obterNome(){
		return nome;
	}
	
	public void fixarTexto(String texto){
		this.texto = texto;
	}
	
	public String obterTexto(){
		return texto;
	}
	
	@Override
	public boolean equals(Object o){
		Opcao outraOpção;
		if(o instanceof Opcao){
			outraOpção = (Opcao) o;
			return seOsNomesSãoIguais(outraOpção);
		}
		
		return false;
	}

	private boolean seOsNomesSãoIguais(Opcao outraOpção) {
		return outraOpção.nome.equals(this.nome);
	}
	
}
