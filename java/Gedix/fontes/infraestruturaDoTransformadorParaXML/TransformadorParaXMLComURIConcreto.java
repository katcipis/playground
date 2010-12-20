package infraestruturaDoTransformadorParaXML;

import static infraestruturaDoTransformadorParaXML.InicioDosAtributosEmXML.URI;

public class TransformadorParaXMLComURIConcreto extends TransformadorParaXMLConcreto implements TransformadorParaXMLComURI{

	public String obterOAtributoURI(TransformavelEmXMLComURI transformável) {
		
		return URI.inícioDoAtributo + aspa + transformável.obterURI() + aspa;
	}
	
	public String obterXMLComURI(TransformavelEmXMLComURI transformável){
		return 
		gerarXML(transformável)
		+ espaçoVazio + obterOAtributoURI(transformável)
		+ fimDoMarcador 
		+ inícioDoMarcadorQueEncerra + obterOAtributoTipo(transformável) + fimDoMarcador;
	}
	
}
