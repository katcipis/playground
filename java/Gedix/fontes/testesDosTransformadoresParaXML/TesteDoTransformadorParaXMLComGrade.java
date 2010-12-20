package testesDosTransformadoresParaXML;

import static infraestruturaDoTransformadorParaXML.InicioDosAtributosEmXML.LINHAS;
import static infraestruturaDoTransformadorParaXML.InicioDosAtributosEmXML.COLUNAS;
import static org.junit.Assert.*;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import infraestruturaDoTransformadorParaXML.TransformadorParaXML;
import infraestruturaDoTransformadorParaXML.TransformadorParaXMLComGrade;
import listasDeTestesDosTransformadoresParaXML.ListaDeTestesDoTransformadorParaXMLComGrade;
import mocksDeTransformaveisParaXML.MockTransformavelEmXMLComGrade;

import org.junit.Before;
import org.junit.Test;


public class TesteDoTransformadorParaXMLComGrade extends
		TesteAbstratoDoTransformadorParaXML implements
		ListaDeTestesDoTransformadorParaXMLComGrade {
	
	private TransformadorParaXMLComGrade transformadorComGrade;
	private MockTransformavelEmXMLComGrade transformávelComLinhasZeroEColunhasZero;
	private String atributoLinhasComValorZero, atributoColunasComValorZero,
	xmlComTodosOsAtributosDoTransformávelComLinhasZeroEColunhasZero;
	
	@Before
	public void criarComponentesNecessários(){
		atributoLinhasComValorZero = LINHAS.inícioDoAtributo + aspa + "0" + aspa;
		atributoColunasComValorZero = COLUNAS.inícioDoAtributo + aspa + "0" + aspa;
		transformadorComGrade = Fabrica.obterTransformadorParaXMLComGrade();
		transformávelComLinhasZeroEColunhasZero = Fabrica
		     .obterMockTransformavelEmXMLComGrade();
		
		xmlComTodosOsAtributosDoTransformávelComLinhasZeroEColunhasZero =
		 gerarXML() 
		 + espaçoVazio + atributoLinhasComValorZero
		 + espaçoVazio + atributoColunasComValorZero
		 + fimDoMarcador + fechaMarcador + atributoTipoComValorBotão
	     + fimDoMarcador;
	}

	@Override
	protected TransformadorParaXML criarTransformadorParaXMLQueSeráTestado() {

		return Fabrica.obterTransformadorParaXMLComGrade();
	}

	@Test
	public void dadoUmTransformavelEmXMLComGradePodeGerarOAtributoLinhas() {
		assertEquals(atributoLinhasComValorZero, transformadorComGrade
				.obterOAtributoLinhas(transformávelComLinhasZeroEColunhasZero));
		
		transformávelComLinhasZeroEColunhasZero.alterarAtributosComGrade();
		
		assertFalse(atributoLinhasComValorZero.equals(transformadorComGrade
				.obterOAtributoLinhas(transformávelComLinhasZeroEColunhasZero)));
		
	}

	@Test
	public void dadoUmTransformavelEmXMLComGradePodeGerarOAtributoColunas() {
		assertEquals(atributoColunasComValorZero, transformadorComGrade
				.obterOAtributoColunas(transformávelComLinhasZeroEColunhasZero));
		
		transformávelComLinhasZeroEColunhasZero.alterarAtributosComGrade();
		
		assertFalse(atributoColunasComValorZero.equals(transformadorComGrade
				.obterOAtributoColunas(transformávelComLinhasZeroEColunhasZero)));
	}

	@Test
	public void dadoUmTransformavelEmXMLComGradePodeGerarOXMLCompletoComOsAtributosLinhasEColunas() {
		assertEquals(xmlComTodosOsAtributosDoTransformávelComLinhasZeroEColunhasZero,
				transformadorComGrade.obterXMLComGrade(transformávelComLinhasZeroEColunhasZero));
		
		transformávelComLinhasZeroEColunhasZero.alterarAtributosComGrade();
		
		assertFalse(xmlComTodosOsAtributosDoTransformávelComLinhasZeroEColunhasZero
				.equals(transformadorComGrade.obterXMLComGrade(transformávelComLinhasZeroEColunhasZero)));
		
	}

}
