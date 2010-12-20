package infraestruturaDoTransformadorParaXML;

public interface TransformadorParaXMLComOpcoes extends TransformadorParaXML{

	public String obterAsOpções(TransformavelEmXMLComOpcoes transformável);

	public String obterXMLComOpções(TransformavelEmXMLComOpcoes transformável);

}