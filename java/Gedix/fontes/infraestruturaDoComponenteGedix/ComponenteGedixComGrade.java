package infraestruturaDoComponenteGedix;

import infraestruturaDoTransformadorParaXML.TransformavelEmXMLComGrade;


public interface ComponenteGedixComGrade extends ComponenteGedix, TransformavelEmXMLComGrade{
	
	public int obterNúmeroDeLinhas();
	
	public int obterNúmeroDeColunas();
	
	public boolean alterarNúmeroDeLinhas(int novoNúmeroDeLinhas);
	
	public boolean alterarNúmeroDeColunas(int novoNúmeroDeColunas);

}
