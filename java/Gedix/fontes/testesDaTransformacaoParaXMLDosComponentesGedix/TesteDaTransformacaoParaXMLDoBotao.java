package testesDaTransformacaoParaXMLDosComponentesGedix;

import edugraf.jadix.fachada.TiposDeComponentesDix;
import static edugraf.jadix.fachada.TiposDeComponentesDix.BOTÃO;
import testesAbstratosDaTransformacaoParaXMLDosComponentesGedix.TesteAbstratoDaTransformacaoParaXMLDoComponenteGedixRotulavel;

public class TesteDaTransformacaoParaXMLDoBotao extends TesteAbstratoDaTransformacaoParaXMLDoComponenteGedixRotulavel{

	
	@Override
	protected TiposDeComponentesDix retornarTipoDoComponenteDixQueSeráTestado() {
		
		return BOTÃO;
	}

	

}
