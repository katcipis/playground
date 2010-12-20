package infraestruturaDoTransformadorParaXML;

import static infraestruturaDoTransformadorParaXML.InicioDosAtributosEmXML.URI;

public class TransformadorParaXMLRotulavelComURIConcreto extends TransformadorParaXMLConcreto 
                                               implements TransformadorParaXMLRotulavelComURI{

	public String obterOAtributoTexto(
			TransformavelEmXMLRotulavelComURI transformável) {
		
		return transformável.obterTexto();
	}

	public String obterOAtributoURI(
			TransformavelEmXMLRotulavelComURI transformável) {
		
		return URI.inícioDoAtributo + aspa + transformável.obterURI() + aspa;
	}

	public String obterXMLComTextoEURI(
			TransformavelEmXMLRotulavelComURI transformável) {
		
		return gerarXML(transformável)
		+ espaçoVazio + obterOAtributoURI(transformável)
		+ fimDoMarcador  + obterOAtributoTexto(transformável) 
		+ inícioDoMarcadorQueEncerra + obterOAtributoTipo(transformável) + fimDoMarcador;
	}

}
