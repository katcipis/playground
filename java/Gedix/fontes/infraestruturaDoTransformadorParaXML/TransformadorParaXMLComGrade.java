package infraestruturaDoTransformadorParaXML;

public interface TransformadorParaXMLComGrade extends TransformadorParaXML{

	public String obterOAtributoLinhas(TransformavelEmXMLComGrade transformável);

	public String obterOAtributoColunas(TransformavelEmXMLComGrade transformável);

	public String obterXMLComGrade(TransformavelEmXMLComGrade transformável);

}