package infraestruturaDoTransformadorParaXML;


public class TransformadorParaXMLRotulavelConcreto extends TransformadorParaXMLConcreto implements TransformadorParaXMLRotulavel{
	
public String obterOAtributoTexto(TransformavelEmXMLRotulavel transformável) {
		
		return transformável.obterTexto();
	}
	
	public String obterXMLComTexto(TransformavelEmXMLRotulavel transformável){
		return 
		gerarXML(transformável)
	    + fimDoMarcador + obterOAtributoTexto(transformável)
		+ inícioDoMarcadorQueEncerra + obterOAtributoTipo(transformável) + fimDoMarcador;
	}

}
