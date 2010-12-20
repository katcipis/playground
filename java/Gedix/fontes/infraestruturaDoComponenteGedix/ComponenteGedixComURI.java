package infraestruturaDoComponenteGedix;

import infraestruturaDoTransformadorParaXML.TransformavelEmXMLComURI;

public interface ComponenteGedixComURI extends ComponenteGedix, TransformavelEmXMLComURI{
	
	public String obterURI();
	
	public void alterarURI(String novaURI);

}
