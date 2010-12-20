package infraestruturaDoComponenteGedix;

public class OpcaoNula extends Opcao{

	public OpcaoNula() {
		super(StringVazia.STRING_VAZIA.nome);
		// TODO Auto-generated constructor stub
	}
	
	@Override
	public void fixarTexto(String texto){ }
	
	@Override
	public boolean equals(Object o){ 
		return (o instanceof OpcaoNula);
	}

}
