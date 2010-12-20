package infraestruturaDoTransformadorParaXML;

public interface TransformadorParaXMLRotulavel extends TransformadorParaXML{

	public String obterOAtributoTexto(TransformavelEmXMLRotulavel transformável);

	public String obterXMLComTexto(TransformavelEmXMLRotulavel transformável);

}