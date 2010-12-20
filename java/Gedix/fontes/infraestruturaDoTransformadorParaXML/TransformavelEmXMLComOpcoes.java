package infraestruturaDoTransformadorParaXML;

import infraestruturaDoComponenteGedix.Opcao;

public interface TransformavelEmXMLComOpcoes extends TransformavelEmXML{
	
	public Opcao obterOpção(int indiceDaOpção);
	
	public boolean possuiAOpçãoDeÍndice(int indice);
	
	public int obterQuantidadeDeOpções();

}
