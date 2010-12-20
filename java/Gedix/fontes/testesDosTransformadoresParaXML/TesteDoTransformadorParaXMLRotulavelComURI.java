package testesDosTransformadoresParaXML;

import static infraestruturaDoTransformadorParaXML.InicioDosAtributosEmXML.URI;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import infraestruturaDoTransformadorParaXML.TransformadorParaXML;
import infraestruturaDoTransformadorParaXML.TransformadorParaXMLRotulavelComURI;
import listasDeTestesDosTransformadoresParaXML.ListaDeTestesDoTransformadorParaXMLRotulavelComURI;
import mocksDeTransformaveisParaXML.MockTransformavelEmXMLRotulavelComURI;

import org.junit.Before;
import org.junit.Test;

public class TesteDoTransformadorParaXMLRotulavelComURI extends 
TesteAbstratoDoTransformadorParaXML
implements ListaDeTestesDoTransformadorParaXMLRotulavelComURI{

	private TransformadorParaXMLRotulavelComURI transformadorRotulávelComURI;
	private MockTransformavelEmXMLRotulavelComURI transformávelComTextoEURIMock;
	private String atributoTextoMock, atributoURIMock,
	xmlComTodosOsAtributosDoTransformávelComTextoEURIMock;
	
	@Before
	public void criarComponentesNecessários(){
		atributoTextoMock = "Mock";
		atributoURIMock = URI.inícioDoAtributo + aspa + "Mock" + aspa;
		transformadorRotulávelComURI = Fabrica.obterTransformadorParaXMLRotulavelComURI();
		transformávelComTextoEURIMock = Fabrica.obterMockTransformavelEmXMLRotulavelComURI();
		
		xmlComTodosOsAtributosDoTransformávelComTextoEURIMock =
		 gerarXML() + espaçoVazio + atributoURIMock
	     + fimDoMarcador +  atributoTextoMock + 
		 fechaMarcador + atributoTipoComValorBotão
	     + fimDoMarcador;
	}
	
	
	
	@Override
	protected TransformadorParaXML criarTransformadorParaXMLQueSeráTestado() {
		
		return Fabrica.obterTransformadorParaXMLRotulavelComURI();
	}

	@Test
	public void dadoUmTransformavelEmXMLRotulávelComURIPodeGerarOAtributoURI() {
		
		assertEquals(atributoURIMock,transformadorRotulávelComURI
				.obterOAtributoURI(transformávelComTextoEURIMock));
		
		transformávelComTextoEURIMock.alterarAtributosComURI();
		
		assertFalse(atributoURIMock.equals(transformadorRotulávelComURI
				.obterOAtributoURI(transformávelComTextoEURIMock)));
		
	}

	@Test
	public void dadoUmTransformavelEmXMLRotulávelComURIPodeGerarOXMLCompletoComTextoEURI() {
		
		assertEquals(xmlComTodosOsAtributosDoTransformávelComTextoEURIMock,
				transformadorRotulávelComURI.obterXMLComTextoEURI(transformávelComTextoEURIMock));
			
		transformávelComTextoEURIMock.alterarAtributosComURI();
		
		assertFalse(xmlComTodosOsAtributosDoTransformávelComTextoEURIMock
				.equals(transformadorRotulávelComURI.obterXMLComTextoEURI(transformávelComTextoEURIMock)));
		
	}


	@Test
	public void dadoUmTransformavelParaXMLRotulavelComURIPodeGerarOAtributoTexto() {
		
		assertEquals(xmlComTodosOsAtributosDoTransformávelComTextoEURIMock, transformadorRotulávelComURI
				.obterXMLComTextoEURI(transformávelComTextoEURIMock));
		
		transformávelComTextoEURIMock.alterarAtributosRotulavel();
		
		assertFalse(xmlComTodosOsAtributosDoTransformávelComTextoEURIMock.equals(transformadorRotulávelComURI
				.obterXMLComTextoEURI(transformávelComTextoEURIMock)) );
		
	}

}
