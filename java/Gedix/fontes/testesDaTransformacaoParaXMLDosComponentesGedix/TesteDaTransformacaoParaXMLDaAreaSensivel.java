package testesDaTransformacaoParaXMLDosComponentesGedix;

import static edugraf.jadix.fachada.TiposDeComponentesDix.ÁREA_SENSÍVEL;
import testesAbstratosDaTransformacaoParaXMLDosComponentesGedix.TesteAbstratoDaTransformacaoParaXMLDoComponenteGedix;
import edugraf.jadix.fachada.TiposDeComponentesDix;

public class TesteDaTransformacaoParaXMLDaAreaSensivel extends TesteAbstratoDaTransformacaoParaXMLDoComponenteGedix{

	@Override
	protected TiposDeComponentesDix retornarTipoDoComponenteDixQueSeráTestado() {
		return ÁREA_SENSÍVEL;
		
	}

}
