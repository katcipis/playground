package mocksDeTransformaveisParaXML;

import infraestruturaDoTransformadorParaXML.TransformavelEmXMLComURI;

public class MockTransformavelEmXMLComURI extends MockTransformavelEmXML
										implements TransformavelEmXMLComURI{

	private String uri;
	
	public MockTransformavelEmXMLComURI(){
		uri = "Mock";
	}
	
	public void alterarAtributosComURI(){
		alterarAtributos();
		uri = "Mock2";
	}
	
	public String obterURI() {

		return uri;
	}

}
