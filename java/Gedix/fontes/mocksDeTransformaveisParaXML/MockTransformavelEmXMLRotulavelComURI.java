package mocksDeTransformaveisParaXML;

import infraestruturaDoTransformadorParaXML.TransformavelEmXMLRotulavelComURI;

public class MockTransformavelEmXMLRotulavelComURI extends MockTransformavelEmXMLRotulavel
implements TransformavelEmXMLRotulavelComURI{
	
	private String uri;

	public MockTransformavelEmXMLRotulavelComURI(){
		uri = "Mock";
	}
	
	public String obterURI() {
		
		return uri;
	}
	
	public void alterarAtributosComURI(){
		alterarAtributos();
		uri = "novaURI";
		
	}

}
