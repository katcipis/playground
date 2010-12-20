package infraestruturaDoTransformadorParaXML;

import static infraestruturaDoTransformadorParaXML.InicioDosAtributosEmXML.LINHAS;
import static infraestruturaDoTransformadorParaXML.InicioDosAtributosEmXML.COLUNAS;

public class TransformadorParaXMLComGradeConcreto extends TransformadorParaXMLConcreto implements TransformadorParaXMLComGrade{
	
public String obterOAtributoLinhas(TransformavelEmXMLComGrade transformável) {
		Integer linhas = transformável.obterNúmeroDeLinhas();
		return LINHAS.inícioDoAtributo + aspa + linhas.toString() + aspa;
	}

public String obterOAtributoColunas(TransformavelEmXMLComGrade transformável) {
	Integer colunas = transformável.obterNúmeroDeColunas();
	return COLUNAS.inícioDoAtributo + aspa + colunas.toString() + aspa;
}

public String obterXMLComGrade(TransformavelEmXMLComGrade transformável){
	return 
	gerarXML(transformável)
	+ espaçoVazio + obterOAtributoLinhas(transformável)
	+ espaçoVazio + obterOAtributoColunas(transformável)
	+ fimDoMarcador 
	+ inícioDoMarcadorQueEncerra + obterOAtributoTipo(transformável) + fimDoMarcador;
}

}
