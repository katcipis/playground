package infraestruturaDoComponenteGedix;

import infraestruturaDoTransformadorParaXML.TransformavelEmXMLRotulavel;


public interface ComponenteGedixRotulavel extends ComponenteGedix, TransformavelEmXMLRotulavel{
	
	public String obterTexto();
	
	public void alterarTexto(String novoTexto);

}
