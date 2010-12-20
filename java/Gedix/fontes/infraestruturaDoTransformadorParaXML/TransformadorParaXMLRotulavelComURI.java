package infraestruturaDoTransformadorParaXML;

public interface TransformadorParaXMLRotulavelComURI extends TransformadorParaXML{
	
	public String obterOAtributoURI(TransformavelEmXMLRotulavelComURI transformável);
	
	public String obterOAtributoTexto(TransformavelEmXMLRotulavelComURI transformável);
	
	public String obterXMLComTextoEURI(TransformavelEmXMLRotulavelComURI transformável);

}
