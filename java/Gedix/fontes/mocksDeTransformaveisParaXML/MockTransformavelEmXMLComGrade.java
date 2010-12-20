package mocksDeTransformaveisParaXML;

import infraestruturaDoTransformadorParaXML.TransformavelEmXMLComGrade;


public class MockTransformavelEmXMLComGrade extends MockTransformavelEmXML
                                       implements TransformavelEmXMLComGrade{

	private int númeroDeColunas, númeroDeLinhas;
	
	public MockTransformavelEmXMLComGrade(){
		númeroDeColunas = 0;
		númeroDeLinhas = 0;
	}
	
	public int obterNúmeroDeColunas() {
		
		return númeroDeColunas;
	}

	public int obterNúmeroDeLinhas() {
		
		return númeroDeLinhas;
	}
	
	public void alterarAtributosComGrade(){
		alterarAtributos();
		númeroDeColunas = 2;
		númeroDeLinhas = 4;
	}

}
