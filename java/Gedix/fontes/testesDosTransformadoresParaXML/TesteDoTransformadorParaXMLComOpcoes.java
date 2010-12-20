package testesDosTransformadoresParaXML;

import static infraestruturaDoTransformadorParaXML.InicioDosAtributosEmXML.OPÇÃO;
import static infraestruturaDoTransformadorParaXML.InicioDosAtributosEmXML.NOME;
import static org.junit.Assert.*;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import infraestruturaDoTransformadorParaXML.TransformadorParaXML;
import infraestruturaDoTransformadorParaXML.TransformadorParaXMLComOpcoes;
import listasDeTestesDosTransformadoresParaXML.ListaDeTestesDoTransformadorParaXMLComOpcoes;
import mocksDeTransformaveisParaXML.MockTransformavelEmXMLComOpcoes;

import org.junit.Before;
import org.junit.Test;

public class TesteDoTransformadorParaXMLComOpcoes extends
		TesteAbstratoDoTransformadorParaXML implements
		ListaDeTestesDoTransformadorParaXMLComOpcoes {
	
	private TransformadorParaXMLComOpcoes transformadorComOpções;
	private MockTransformavelEmXMLComOpcoes transformávelComTrêsOpções;
	private String marcaçãoXMLDaOpção1, marcaçãoXMLDaOpção2, marcaçãoXMLDaOpção3,
	xmlComTodosOsAtributosDoTransformávelComOpções;

	@Override
	protected TransformadorParaXML criarTransformadorParaXMLQueSeráTestado() {

		return Fabrica.obterTransformadorParaXMLComOpções();
	}
	
	@Before
	public void criarComponentesNecessários(){
		
		marcaçãoXMLDaOpção1 = criarMarcaçãoXmlDaOpçãoDeNome("opção1");
		marcaçãoXMLDaOpção2 = criarMarcaçãoXmlDaOpçãoDeNome("opção2");
		marcaçãoXMLDaOpção3 = criarMarcaçãoXmlDaOpçãoDeNome("opção3");
		
		transformadorComOpções = Fabrica.obterTransformadorParaXMLComOpções();
		
		transformávelComTrêsOpções = Fabrica
		     .obterMockTransformavelEmXMLComOpções();
		
		 xmlComTodosOsAtributosDoTransformávelComOpções =
		 gerarXML() 
		 + fimDoMarcador + marcaçãoXMLDaOpção1 + marcaçãoXMLDaOpção2 +
		 marcaçãoXMLDaOpção3 + fechaMarcador + atributoTipoComValorBotão
	     + fimDoMarcador;
	}
	
	private String criarMarcaçãoXmlDaOpçãoDeNome(String nome){
		return inícioDoMarcador + OPÇÃO.inícioDoAtributo + espaçoVazio + 
		NOME.inícioDoAtributo + aspa + nome + aspa + fimDoMarcador + nome +
		fechaMarcador + OPÇÃO.inícioDoAtributo + fimDoMarcador;
	}

	@Test
	public void dadoUmTransformavelEmXMLComOpçõesPodeGerarOsElementosDasOpções() {
		
		assertEquals(transformadorComOpções.obterAsOpções(transformávelComTrêsOpções),
				marcaçãoXMLDaOpção1 + marcaçãoXMLDaOpção2 + marcaçãoXMLDaOpção3); 
		
		transformávelComTrêsOpções.alterarAtributosComOpções();
		
		assertFalse(transformadorComOpções.obterAsOpções(transformávelComTrêsOpções)
				.equals(marcaçãoXMLDaOpção1 + marcaçãoXMLDaOpção2 + marcaçãoXMLDaOpção3)); 
		
	}

	@Test
	public void podeGerarOXMLCompletoComAsOpçõesComoFilhosDAMarcaçãoXMLDoTransformavel() {
		
		assertEquals(xmlComTodosOsAtributosDoTransformávelComOpções, transformadorComOpções
				.obterXMLComOpções(transformávelComTrêsOpções));
		
		transformávelComTrêsOpções.alterarAtributosComOpções();
		
		assertFalse(xmlComTodosOsAtributosDoTransformávelComOpções.equals(transformadorComOpções
				.obterXMLComOpções(transformávelComTrêsOpções)) );
		
		
	}

}
