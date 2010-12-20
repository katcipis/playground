package mocksDeTransformaveisParaXML;

import infraestruturaDoTransformadorParaXML.TransformavelEmXMLRotulavel;

public class MockTransformavelEmXMLRotulavel extends MockTransformavelEmXML
implements TransformavelEmXMLRotulavel{
	
private String texto;
	
	public MockTransformavelEmXMLRotulavel(){
		texto = "Mock";
	}

	public String obterTexto() {
		
		return texto;
	}
	
	public void alterarAtributosRotulavel(){
		alterarAtributos();
		texto = "Mock2";
	}

}
