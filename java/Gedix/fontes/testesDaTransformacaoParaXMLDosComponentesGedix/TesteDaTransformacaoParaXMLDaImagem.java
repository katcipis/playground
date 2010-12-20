package testesDaTransformacaoParaXMLDosComponentesGedix;

import testesAbstratosDaTransformacaoParaXMLDosComponentesGedix.TesteAbstratoDaTransformacaoParaXMLDoComponenteGedixComURI;
import edugraf.jadix.fachada.TiposDeComponentesDix;
import static edugraf.jadix.fachada.TiposDeComponentesDix.IMAGEM;


public class TesteDaTransformacaoParaXMLDaImagem extends TesteAbstratoDaTransformacaoParaXMLDoComponenteGedixComURI{

	@Override
	protected TiposDeComponentesDix retornarTipoDoComponenteDixQueSeráTestado() {
	
		return IMAGEM;
	}

}
