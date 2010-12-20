package testesDaTransformacaoParaXMLDosComponentesGedix;

import static edugraf.jadix.fachada.TiposDeComponentesDix.CAMPO_DE_TEXTO;
import edugraf.jadix.fachada.TiposDeComponentesDix;
import testesAbstratosDaTransformacaoParaXMLDosComponentesGedix.TesteAbstratoDaTransformacaoParaXMLDoComponenteGedixRotulavel;

public class TesteDaTransformacaoParaXMLDoCampoDeTexto extends TesteAbstratoDaTransformacaoParaXMLDoComponenteGedixRotulavel{

	@Override
	protected TiposDeComponentesDix retornarTipoDoComponenteDixQueSeráTestado() {
		
		return CAMPO_DE_TEXTO;
	}

}
