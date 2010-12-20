package testesDaTransformacaoParaXMLDosComponentesGedix;

import static edugraf.jadix.fachada.TiposDeComponentesDix.CAIXA_DE_ESCOLHA;
import edugraf.jadix.fachada.TiposDeComponentesDix;
import testesAbstratosDaTransformacaoParaXMLDosComponentesGedix.TesteAbstratoDaTransformacaoParaXMLDoComponenteGedixComOpcoes;

public class TesteDaTransformacaoParaXMLDoCaixaDeEscolha extends TesteAbstratoDaTransformacaoParaXMLDoComponenteGedixComOpcoes{

	@Override
	protected TiposDeComponentesDix retornarTipoDoComponenteDixQueSeráTestado() {
		
		return CAIXA_DE_ESCOLHA;
	}
	
}
