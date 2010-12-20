package testesDaTransformacaoParaXMLDosComponentesGedix;

import testesAbstratosDaTransformacaoParaXMLDosComponentesGedix.TesteAbstratoDaTransformacaoParaXMLDoComponenteGedixRotulavelComURI;
import edugraf.jadix.fachada.TiposDeComponentesDix;
import static edugraf.jadix.fachada.TiposDeComponentesDix.ENLACE;

public class TesteDaTransformacaoParaXMLDoEnlace extends TesteAbstratoDaTransformacaoParaXMLDoComponenteGedixRotulavelComURI{

	@Override
	protected TiposDeComponentesDix retornarTipoDoComponenteDixQueSeráTestado() {
		
		return ENLACE;
	}

}
