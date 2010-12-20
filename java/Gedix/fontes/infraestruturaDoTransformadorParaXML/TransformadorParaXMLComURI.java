package infraestruturaDoTransformadorParaXML;

public interface TransformadorParaXMLComURI extends TransformadorParaXML{

	public String obterOAtributoURI(TransformavelEmXMLComURI transformável);

	public String obterXMLComURI(TransformavelEmXMLComURI transformável);

}