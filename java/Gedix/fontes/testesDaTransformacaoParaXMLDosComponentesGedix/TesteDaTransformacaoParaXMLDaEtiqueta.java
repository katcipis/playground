package testesDaTransformacaoParaXMLDosComponentesGedix;

import static edugraf.jadix.fachada.TiposDeComponentesDix.ETIQUETA;
import edugraf.jadix.fachada.TiposDeComponentesDix;
import testesAbstratosDaTransformacaoParaXMLDosComponentesGedix.TesteAbstratoDaTransformacaoParaXMLDoComponenteGedixRotulavel;

public class TesteDaTransformacaoParaXMLDaEtiqueta extends TesteAbstratoDaTransformacaoParaXMLDoComponenteGedixRotulavel{

	@Override
	protected TiposDeComponentesDix retornarTipoDoComponenteDixQueSeráTestado() {
		
		return ETIQUETA;
	}
	
}
