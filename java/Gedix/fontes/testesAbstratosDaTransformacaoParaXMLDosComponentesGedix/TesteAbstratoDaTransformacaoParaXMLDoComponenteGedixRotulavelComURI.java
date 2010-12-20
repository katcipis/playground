package testesAbstratosDaTransformacaoParaXMLDosComponentesGedix;

import static infraestruturaDoTransformadorParaXML.InicioDosAtributosEmXML.URI;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import infraestruturaDoComponenteGedix.ComponenteGedixRotulavelComURI;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import infraestruturaDoTransformadorParaXML.TransformadorParaXMLRotulavelComURI;
import listasDeTestesDaTransformacaoParaXMLDosComponentesGedix.ListaDeTestesDaTransformacaoParaXMLDoComponenteGedixRotulavelComURI;

import org.junit.Before;
import org.junit.Test;

public abstract class TesteAbstratoDaTransformacaoParaXMLDoComponenteGedixRotulavelComURI 
extends TesteAbstratoDaTransformacaoParaXMLDoComponenteGedix
implements ListaDeTestesDaTransformacaoParaXMLDoComponenteGedixRotulavelComURI{

	private TransformadorParaXMLRotulavelComURI transformadorRotulávelComURI;
	private ComponenteGedixRotulavelComURI componenteGedixRotulávelComURIGedix;
	private String atributoURIGedix,atributoTextoGedix,
			xmlComTodosOsAtributosDoComponenteComURIETextoGedix,
	novaURI, novoTexto;

	@Before
	public void criarComponentesNecessários() {
		atributoURIGedix = URI.inícioDoAtributo + aspa + gedix + aspa;
		atributoTextoGedix = gedix;
		transformadorRotulávelComURI = Fabrica.obterTransformadorParaXMLRotulavelComURI();

		novaURI = "novaUri";
		novoTexto = "novoTexto";

		criarComponenteGedixRotulávelComURI();

		xmlComTodosOsAtributosDoComponenteComURIETextoGedix = gerarXML()
				+ espaçoVazio + atributoURIGedix + fimDoMarcador + atributoTextoGedix
				+ fechaMarcador + atributoTipoDoComponenteQueSeráTestado
				+ fimDoMarcador;
	}

	private void criarComponenteGedixRotulávelComURI() {
		
		componenteGedixRotulávelComURIGedix = Fabrica
		.obterComponenteGedixRotulávelComURI(
				tipoDoComponenteQueSeráTestado, Fabrica
						.obterRetanguloPosicionavel(Fabrica
								.obterRetangulo(Fabrica.obterDimensão(
										0, 0))));
		
		componenteGedixRotulávelComURIGedix.alterarNome(gedix);
		componenteGedixRotulávelComURIGedix.alterarLegenda(gedix);
		componenteGedixRotulávelComURIGedix.desabilitar();
		componenteGedixRotulávelComURIGedix.tornarInvisível();
		componenteGedixRotulávelComURIGedix.alterarURI(gedix);
		componenteGedixRotulávelComURIGedix.alterarTexto(gedix);

	}
	

	@Test
	public void dadoUmComponenteGedixRotulavelComURIPodeGerarOAtributoTexto() {
		
		assertEquals(atributoTextoGedix, transformadorRotulávelComURI
				.obterOAtributoTexto(componenteGedixRotulávelComURIGedix));
		
		componenteGedixRotulávelComURIGedix.alterarTexto(novoTexto);

		assertFalse(atributoTextoGedix.equals(transformadorRotulávelComURI
				.obterOAtributoTexto(componenteGedixRotulávelComURIGedix)));
		
	}

	@Test
	public void dadoUmComponenteGedixRotulávelComURIPodeGerarOAtributoURI() {
		
		assertEquals(atributoURIGedix, transformadorRotulávelComURI
				.obterOAtributoURI(componenteGedixRotulávelComURIGedix));

		componenteGedixRotulávelComURIGedix.alterarURI(novaURI);

		assertFalse(atributoURIGedix.equals(transformadorRotulávelComURI
				.obterOAtributoURI(componenteGedixRotulávelComURIGedix)));
		
	}

	@Test
	public void dadoUmComponenteGedixRotulávelComURIPodeGerarOXMLCompletoComTextoEURI() {
		
		assertEquals(xmlComTodosOsAtributosDoComponenteComURIETextoGedix,
				transformadorRotulávelComURI
						.obterXMLComTextoEURI(componenteGedixRotulávelComURIGedix));
		
		componenteGedixRotulávelComURIGedix.alterarURI(novaURI);

		assertFalse(xmlComTodosOsAtributosDoComponenteComURIETextoGedix
				.equals(transformadorRotulávelComURI
						.obterXMLComTextoEURI(componenteGedixRotulávelComURIGedix)));
		
	}

	

}
