package testesDaTransformacaoParaXMLDosComponentesGedix;

import static edugraf.jadix.fachada.TiposDeComponentesDix.LISTA_DE_ESCOLHA;
import edugraf.jadix.fachada.TiposDeComponentesDix;
import testesAbstratosDaTransformacaoParaXMLDosComponentesGedix.TesteAbstratoDaTransformacaoParaXMLDoComponenteGedixComOpcoes;

public class TesteDaTransformacaoParaXMLDaListaDeEscolha extends TesteAbstratoDaTransformacaoParaXMLDoComponenteGedixComOpcoes{

	@Override
	protected TiposDeComponentesDix retornarTipoDoComponenteDixQueSeráTestado() {
		
		return LISTA_DE_ESCOLHA;
	}
	
}
