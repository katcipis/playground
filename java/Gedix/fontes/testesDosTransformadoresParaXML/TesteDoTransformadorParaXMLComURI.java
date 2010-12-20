package testesDosTransformadoresParaXML;

import org.junit.Before;
import org.junit.Test;

import listasDeTestesDosTransformadoresParaXML.ListaDeTestesDoTransformadorParaXMLComURI;
import mocksDeTransformaveisParaXML.MockTransformavelEmXMLComURI;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import infraestruturaDoTransformadorParaXML.TransformadorParaXML;
import infraestruturaDoTransformadorParaXML.TransformadorParaXMLComURI;
import static infraestruturaDoTransformadorParaXML.InicioDosAtributosEmXML.URI;
import static org.junit.Assert.*;

public class TesteDoTransformadorParaXMLComURI extends 
                    TesteAbstratoDoTransformadorParaXML
                    implements ListaDeTestesDoTransformadorParaXMLComURI{

	private TransformadorParaXMLComURI transformadorComURI;
	private MockTransformavelEmXMLComURI transformávelComURIDeTextoMock;
	private String atributoURIComTextoMock,
	xmlComTodosOsAtributosDoTransformávelComURIDeTextoMock;
	
	@Before
	public void criarComponentesNecessários(){
		atributoURIComTextoMock = URI.inícioDoAtributo + aspa + "Mock" + aspa;
		transformadorComURI = Fabrica.obterTransformadorParaXMLComURI();
		transformávelComURIDeTextoMock = Fabrica
		     .obterMockTransformavelEmXMLComURI();
		
		xmlComTodosOsAtributosDoTransformávelComURIDeTextoMock =
		 gerarXML() 
		 + espaçoVazio + atributoURIComTextoMock
		 + fimDoMarcador + fechaMarcador + atributoTipoComValorBotão
	     + fimDoMarcador;
	}
	
	@Override
	protected TransformadorParaXML criarTransformadorParaXMLQueSeráTestado() {
		
		return Fabrica.obterTransformadorParaXMLComURI();
	}

	@Test
	public void dadoUmTransformavelEmXMLComURIPodeGerarOAtributoURI() {
		assertEquals(atributoURIComTextoMock,transformadorComURI
				.obterOAtributoURI(transformávelComURIDeTextoMock));
		
		transformávelComURIDeTextoMock.alterarAtributosComURI();
		
		assertFalse(atributoURIComTextoMock.equals(transformadorComURI
				.obterOAtributoURI(transformávelComURIDeTextoMock)));
		
	}

	@Test
	public void dadoUmTransformavelEmXMLComURIPodeGerarOXMLCompletoComOAtributoURI() {
		
		assertEquals(xmlComTodosOsAtributosDoTransformávelComURIDeTextoMock,
				transformadorComURI.obterXMLComURI(transformávelComURIDeTextoMock));
		
		transformávelComURIDeTextoMock.alterarAtributosComURI();
		
		assertFalse(xmlComTodosOsAtributosDoTransformávelComURIDeTextoMock
				.equals(transformadorComURI.obterXMLComURI(transformávelComURIDeTextoMock)));
			
		
	}

}
