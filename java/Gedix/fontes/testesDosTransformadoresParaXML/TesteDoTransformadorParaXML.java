package testesDosTransformadoresParaXML;

import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import infraestruturaDoTransformadorParaXML.TransformadorParaXML;

public class TesteDoTransformadorParaXML extends TesteAbstratoDoTransformadorParaXML{

	@Override
	protected TransformadorParaXML criarTransformadorParaXMLQueSeráTestado() {
		
		return Fabrica.obterTransformadorParaXML();
	}

}
