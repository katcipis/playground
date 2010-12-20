package testesAbstratosDaTransformacaoParaXMLDosComponentesGedix;

import static org.junit.Assert.assertEquals;
import infraestruturaDoComponenteGedix.ComponenteGedixRotulavel;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import infraestruturaDoTransformadorParaXML.TransformadorParaXMLRotulavel;
import listasDeTestesDaTransformacaoParaXMLDosComponentesGedix.ListaDeTestesDaTransformacaoParaXMLDoComponenteGedixRotulavel;

import org.junit.Before;
import org.junit.Test;

public abstract class TesteAbstratoDaTransformacaoParaXMLDoComponenteGedixRotulavel 
              extends TesteAbstratoDaTransformacaoParaXMLDoComponenteGedix
              implements ListaDeTestesDaTransformacaoParaXMLDoComponenteGedixRotulavel{

	private TransformadorParaXMLRotulavel transformadorRotulável;
	private ComponenteGedixRotulavel componenteGedixRotulavelComTextoGedix;
	private String atributoTextoGedix,
	xmlComTodosOsAtributosDoComponenteRotulavelComTextoGedix;
	
	@Before
	public void criarComponentesNecessários(){
		atributoTextoGedix = gedix;
		transformadorRotulável = Fabrica.obterTransformadorParaXMLRotulavel();
		criarComponenteGedixRotulavel();
		
		xmlComTodosOsAtributosDoComponenteRotulavelComTextoGedix =
		 gerarXML() 
	     + fimDoMarcador +  atributoTextoGedix + 
		 fechaMarcador + atributoTipoDoComponenteQueSeráTestado
	     + fimDoMarcador;
	}
	

	private  void criarComponenteGedixRotulavel(){
		componenteGedixRotulavelComTextoGedix = Fabrica.obterComponenteGedixRotulavelDoTipo(tipoDoComponenteQueSeráTestado, 
				Fabrica.obterRetanguloPosicionavel(Fabrica.obterRetangulo(Fabrica.obterDimensão(0, 0))));
		
		componenteGedixRotulavelComTextoGedix.alterarNome(gedix);
		componenteGedixRotulavelComTextoGedix.alterarTexto(gedix);
		componenteGedixRotulavelComTextoGedix.alterarLegenda(gedix);
		componenteGedixRotulavelComTextoGedix.desabilitar();
		componenteGedixRotulavelComTextoGedix.tornarInvisível();
		
	}
	

	@Test
	public void dadoUmComponenteGedixRotulávelPodeGerarOAtributoTexto() {
		assertEquals(xmlComTodosOsAtributosDoComponenteRotulavelComTextoGedix, transformadorRotulável
				.obterXMLComTexto(componenteGedixRotulavelComTextoGedix));
		
		
	}
	
	@Test
	public void dadoUmComponenteGedixRotulávelPodeGerarOXMLCompletoComTexto() {
		assertEquals(atributoTextoGedix, transformadorRotulável
				.obterOAtributoTexto(componenteGedixRotulavelComTextoGedix));
		
	}

}
