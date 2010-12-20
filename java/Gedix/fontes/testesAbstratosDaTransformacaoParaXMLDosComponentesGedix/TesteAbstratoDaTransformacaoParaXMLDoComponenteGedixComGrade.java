package testesAbstratosDaTransformacaoParaXMLDosComponentesGedix;

import static infraestruturaDoTransformadorParaXML.InicioDosAtributosEmXML.COLUNAS;
import static infraestruturaDoTransformadorParaXML.InicioDosAtributosEmXML.LINHAS;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import infraestruturaDoComponenteGedix.ComponenteGedixComGrade;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import infraestruturaDoTransformadorParaXML.TransformadorParaXMLComGrade;
import listasDeTestesDaTransformacaoParaXMLDosComponentesGedix.ListaDeTestesDaTransformacaoParaXMLDoComponenteGedixComGrade;

import org.junit.Before;
import org.junit.Test;

public abstract class TesteAbstratoDaTransformacaoParaXMLDoComponenteGedixComGrade 
           extends TesteAbstratoDaTransformacaoParaXMLDoComponenteGedix 
           implements ListaDeTestesDaTransformacaoParaXMLDoComponenteGedixComGrade{

	
	private TransformadorParaXMLComGrade transformadorComGrade;
	private ComponenteGedixComGrade componenteGedixComLinhasUmEColunhasUm;
	private String atributoLinhasComValorUm, atributoColunasComValorUm,
	xmlComTodosOsAtributosDoComponenteComLinhasUmEColunhasUm;
	private int numeroDeLinhasNovo, numeroDeColunasNovo;
	
	@Before
	public void criarComponentesNecessários(){

		
		numeroDeLinhasNovo = 10;
		numeroDeColunasNovo = 10;
		
		atributoLinhasComValorUm = LINHAS.inícioDoAtributo + aspa + "1" + aspa;
		atributoColunasComValorUm = COLUNAS.inícioDoAtributo + aspa + "1" + aspa;
		transformadorComGrade = Fabrica.obterTransformadorParaXMLComGrade();
		
		criarComponenteGedixComGrade();
		
		xmlComTodosOsAtributosDoComponenteComLinhasUmEColunhasUm =
		 gerarXML() 
		 + espaçoVazio + atributoLinhasComValorUm
		 + espaçoVazio + atributoColunasComValorUm
		 + fimDoMarcador + fechaMarcador + atributoTipoDoComponenteQueSeráTestado
	     + fimDoMarcador;
	}

	private void criarComponenteGedixComGrade() {
		componenteGedixComLinhasUmEColunhasUm = Fabrica.obterComponenteGedixComGradeDoTipo(tipoDoComponenteQueSeráTestado, 
				Fabrica.obterRetanguloPosicionavel(Fabrica.obterRetangulo(Fabrica.obterDimensão(0, 0))));
		
		componenteGedixComLinhasUmEColunhasUm.alterarNome(gedix);
		componenteGedixComLinhasUmEColunhasUm.alterarLegenda(gedix);
		componenteGedixComLinhasUmEColunhasUm.desabilitar();
		componenteGedixComLinhasUmEColunhasUm.tornarInvisível();
		
	}


	@Test
	public void dadoUmComponenteGedixComGradePodeGerarOAtributoLinhas() {
		assertEquals(atributoLinhasComValorUm, transformadorComGrade
				.obterOAtributoLinhas(componenteGedixComLinhasUmEColunhasUm));
		
		componenteGedixComLinhasUmEColunhasUm.alterarNúmeroDeLinhas(numeroDeLinhasNovo);
		
		assertFalse(atributoLinhasComValorUm.equals(transformadorComGrade
				.obterOAtributoLinhas(componenteGedixComLinhasUmEColunhasUm)));
		
	}

	@Test
	public void dadoUmComponenteGedixComGradePodeGerarOAtributoColunas() {
		assertEquals(atributoColunasComValorUm, transformadorComGrade
				.obterOAtributoColunas(componenteGedixComLinhasUmEColunhasUm));
		
		componenteGedixComLinhasUmEColunhasUm.alterarNúmeroDeColunas(numeroDeColunasNovo);
		
		assertFalse(atributoColunasComValorUm.equals(transformadorComGrade
				.obterOAtributoColunas(componenteGedixComLinhasUmEColunhasUm)));
	}

	@Test
	public void dadoUmComponenteGedixComGradePodeGerarOXMLCompletoComOsAtributosLinhasEColunas() {
		assertEquals(xmlComTodosOsAtributosDoComponenteComLinhasUmEColunhasUm,
				transformadorComGrade.obterXMLComGrade(componenteGedixComLinhasUmEColunhasUm));
		
		componenteGedixComLinhasUmEColunhasUm.alterarNúmeroDeLinhas(numeroDeLinhasNovo);
		componenteGedixComLinhasUmEColunhasUm.alterarNúmeroDeColunas(numeroDeColunasNovo);
		
		assertFalse(xmlComTodosOsAtributosDoComponenteComLinhasUmEColunhasUm
				.equals(transformadorComGrade.obterXMLComGrade(componenteGedixComLinhasUmEColunhasUm)));
		
	}

}
