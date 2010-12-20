package infraestruturaDoComponenteGedix;

import infraestruturaDoTransformadorParaXML.TransformavelEmXMLComOpcoes;


public interface ComponenteGedixComOpcoes extends ComponenteGedix, TransformavelEmXMLComOpcoes{
	
	public boolean adcionarOpção(Opcao novaOpção);
	
	public boolean removerOpção(int indiceDaOpção);
	
	public boolean removerOpção(Opcao o);
	
	public Opcao obterOpção(int indiceDaOpção);
	
	public void removerTodasAsOpções();
	
	public int obterQuantidadeDeOpções();
	
	public boolean possuiAOpçãoDeÍndice(int indice);
	
	public boolean possuiAOpção(Opcao o);

}
