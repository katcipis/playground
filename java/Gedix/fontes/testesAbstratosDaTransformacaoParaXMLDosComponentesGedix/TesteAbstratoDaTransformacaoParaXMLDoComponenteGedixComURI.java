package testesAbstratosDaTransformacaoParaXMLDosComponentesGedix;

import static infraestruturaDoTransformadorParaXML.InicioDosAtributosEmXML.URI;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import infraestruturaDoComponenteGedix.ComponenteGedixComURI;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import infraestruturaDoTransformadorParaXML.TransformadorParaXMLComURI;
import listasDeTestesDaTransformacaoParaXMLDosComponentesGedix.ListaDeTestesDaTransformacaoParaXMLDoComponenteGedixComURI;

import org.junit.Before;
import org.junit.Test;

public abstract class TesteAbstratoDaTransformacaoParaXMLDoComponenteGedixComURI
		extends TesteAbstratoDaTransformacaoParaXMLDoComponenteGedix implements
		ListaDeTestesDaTransformacaoParaXMLDoComponenteGedixComURI {

	private TransformadorParaXMLComURI transformadorComURI;
	private ComponenteGedixComURI componenteGedixComURIDeURIGedix;
	private String atributoURIGedix,
			xmlComTodosOsAtributosDoComponenteComURIGedix;
	private String novaURI;

	@Before
	public void criarComponentesNecessários() {
		atributoURIGedix = URI.inícioDoAtributo + aspa + gedix + aspa;
		transformadorComURI = Fabrica.obterTransformadorParaXMLComURI();

		novaURI = "novaUri";

		criarComponenteGedixComURI();

		xmlComTodosOsAtributosDoComponenteComURIGedix = gerarXML()
				+ espaçoVazio + atributoURIGedix + fimDoMarcador
				+ fechaMarcador + atributoTipoDoComponenteQueSeráTestado
				+ fimDoMarcador;
	}

	private void criarComponenteGedixComURI() {
		componenteGedixComURIDeURIGedix = Fabrica
				.obterComponenteGedixComURIDoTipo(
						tipoDoComponenteQueSeráTestado, Fabrica
								.obterRetanguloPosicionavel(Fabrica
										.obterRetangulo(Fabrica.obterDimensão(
												0, 0))));
		
		componenteGedixComURIDeURIGedix.alterarNome(gedix);
		componenteGedixComURIDeURIGedix.alterarLegenda(gedix);
		componenteGedixComURIDeURIGedix.desabilitar();
		componenteGedixComURIDeURIGedix.tornarInvisível();
		componenteGedixComURIDeURIGedix.alterarURI(gedix);

	}

	@Test
	public void dadoUmComponenteGedixComURIPodeGerarOAtributoURI() {
		assertEquals(atributoURIGedix, transformadorComURI
				.obterOAtributoURI(componenteGedixComURIDeURIGedix));

		componenteGedixComURIDeURIGedix.alterarURI(novaURI);

		assertFalse(atributoURIGedix.equals(transformadorComURI
				.obterOAtributoURI(componenteGedixComURIDeURIGedix)));

	}

	@Test
	public void dadoUmComponenteGedixComURIPodeGerarOXMLCompletoComOAtributoURI() {

		assertEquals(xmlComTodosOsAtributosDoComponenteComURIGedix,
				transformadorComURI
						.obterXMLComURI(componenteGedixComURIDeURIGedix));
		
		

		componenteGedixComURIDeURIGedix.alterarURI(novaURI);

		assertFalse(xmlComTodosOsAtributosDoComponenteComURIGedix
				.equals(transformadorComURI
						.obterXMLComURI(componenteGedixComURIDeURIGedix)));

	}
	
	

}
