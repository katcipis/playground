package testesDaTransformacaoParaXMLDosComponentesGedix;

import testesAbstratosDaTransformacaoParaXMLDosComponentesGedix.TesteAbstratoDaTransformacaoParaXMLDoComponenteGedixComGrade;
import edugraf.jadix.fachada.TiposDeComponentesDix;
import static edugraf.jadix.fachada.TiposDeComponentesDix.GRADE;

public class TesteDaTransformacaoParaXMLDaGrade extends TesteAbstratoDaTransformacaoParaXMLDoComponenteGedixComGrade{

	@Override
	protected TiposDeComponentesDix retornarTipoDoComponenteDixQueSeráTestado() {
		
		return GRADE;
	}

}
