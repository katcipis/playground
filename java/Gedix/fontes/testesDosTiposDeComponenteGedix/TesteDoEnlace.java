package testesDosTiposDeComponenteGedix;

import static edugraf.jadix.fachada.TiposDeComponentesDix.ENLACE;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;
import infraestruturaDoComponenteGedix.ComponenteGedixComURI;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import infraestruturaDoTransformadorParaXML.TransformavelEmXMLComURI;
import listasDeTestesDoComponenteGedix.ListaDeTestesDoComponenteGedixComURI;

import org.junit.Before;
import org.junit.Test;

import testesAbstratosDoComponenteGedix.TesteAbstratoDoComponenteGedixRotulavel;
import tiposDeComponenteGedix.Enlace;

public class TesteDoEnlace extends TesteAbstratoDoComponenteGedixRotulavel
                            implements ListaDeTestesDoComponenteGedixComURI{
	
	private ComponenteGedixComURI enlaceComURI;
	private String novaURI, vazio;
	
	
	@Override
	public  void informarTipoDoComponenteGedix(){
		tipoDoComponenteGedix = ENLACE;
	}
	
	@Override
	public void criarComponenteGedix(){
		componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial =
		
		Fabrica
		 .obterComponenteGedixDoTipo(ENLACE, Fabrica
				 .obterRetanguloPosicionavel(Fabrica
						 .obterRetangulo(Fabrica
								 .obterDimensão(10, 20))));
		
		novaURI = "novaURI";
		vazio = "";
	}
	
	@Override
	public void criarComponenteGedixRotulável() {
		componenteGedixRotulável = Fabrica
		    .obterComponenteGedixRotulavelDoTipo(ENLACE,
		    		 componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial);
	}
	
	@Before
	public void criarEnlace(){
		enlaceComURI = Fabrica.obterComponenteGedixComURIDoTipo(ENLACE, 
				Fabrica.obterRetanguloPosicionavel(Fabrica
						.obterRetangulo(Fabrica.obterDimensão(10, 10))));
	}
	
	@Test
	public void aURIInicialÉVazia(){
		assertEquals(vazio, enlaceComURI.obterURI());
	}
	
	
	@Test
	public void aURIPodeSerAlterada(){
		enlaceComURI.alterarURI(novaURI);
		assertEquals(novaURI, enlaceComURI.obterURI());
	}

	
	@Test
	public void sabeDizerQualASuaURI(){
		assertEquals(vazio, enlaceComURI.obterURI());
	}
	
	@Test
	public void éTransformávelEmXMLComURI(){
		assertTrue(enlaceComURI instanceof TransformavelEmXMLComURI);
	}

	@Override
	protected void reiniciarContadorDeRetângulosDixCriados() {
		Enlace.reiniciarContador();
	}

	@Override
	protected void criarRetânguloPosicionável() {
		retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial = Fabrica
		 .obterComponenteGedixDoTipo(ENLACE, Fabrica
				 .obterRetanguloPosicionavel(Fabrica
						 .obterRetangulo(Fabrica
								 .obterDimensão(10, 20))));
		
	}
	
	


}
