package testesDosTransformadoresParaXML;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import infraestruturaDoTransformadorParaXML.TransformadorParaXML;
import infraestruturaDoTransformadorParaXML.TransformadorParaXMLRotulavel;
import listasDeTestesDosTransformadoresParaXML.ListaDeTestesDoTransformadorParaXMLRotulavel;
import mocksDeTransformaveisParaXML.MockTransformavelEmXMLRotulavel;

import org.junit.Before;
import org.junit.Test;

public class TesteDoTransformadorParaXMLRotulavel extends 
TesteAbstratoDoTransformadorParaXML
implements ListaDeTestesDoTransformadorParaXMLRotulavel{

	private TransformadorParaXMLRotulavel transformadorRotulável;
	private MockTransformavelEmXMLRotulavel transformávelComTextoMock;
	private String atributoTextoMock,
	xmlComTodosOsAtributosDoTransformávelComTextoMock;
	
	@Before
	public void criarComponentesNecessários(){
		atributoTextoMock = "Mock";
		transformadorRotulável = Fabrica.obterTransformadorParaXMLRotulavel();
		transformávelComTextoMock = Fabrica
		     .obterMockTransformavelEmXMLRotulavel();
		
		xmlComTodosOsAtributosDoTransformávelComTextoMock =
		 gerarXML() 
	     + fimDoMarcador +  atributoTextoMock + 
		 fechaMarcador + atributoTipoComValorBotão
	     + fimDoMarcador;
	}
	
	@Override
	protected TransformadorParaXML criarTransformadorParaXMLQueSeráTestado() {

		return Fabrica.obterTransformadorParaXMLRotulavel();
	}

	@Test
	public void dadoUmTransformavelEmXMLRotulávelPodeGerarOXMLCompletoComTexto() {
		assertEquals(xmlComTodosOsAtributosDoTransformávelComTextoMock, transformadorRotulável
				.obterXMLComTexto(transformávelComTextoMock));
		
		transformávelComTextoMock.alterarAtributosRotulavel();
		
		assertFalse(xmlComTodosOsAtributosDoTransformávelComTextoMock.equals(transformadorRotulável
				.obterXMLComTexto(transformávelComTextoMock)) );
		
	}
	
	@Test
	public void dadoUmTransformavelParaXMLRotulavelPodeGerarOAtributoTexto() {
		assertEquals(atributoTextoMock, transformadorRotulável
				.obterOAtributoTexto(transformávelComTextoMock));
		
		transformávelComTextoMock.alterarAtributosRotulavel();
		
		assertFalse(xmlComTodosOsAtributosDoTransformávelComTextoMock.equals(transformadorRotulável
				.obterXMLComTexto(transformávelComTextoMock)) );
	}

}
