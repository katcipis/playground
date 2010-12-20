package testesAbstratosDoComponenteGedix;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;
import infraestruturaDoComponenteGedix.ComponenteGedixComURI;
import infraestruturaDoTransformadorParaXML.TransformavelEmXMLComURI;
import listasDeTestesDoComponenteGedix.ListaDeTestesDoComponenteGedixComURI;

import org.junit.Before;
import org.junit.Test;

public abstract class TesteAbstratoDoComponenteGedixComURI extends TesteAbstratoDoComponenteGedix
												implements ListaDeTestesDoComponenteGedixComURI{

	protected ComponenteGedixComURI componenteGedixComURI;
	private String novaURI;
	
	@Before
	public void antesDosTestesDoComponenteGedixComURI(){
		criarComponenteGedixComURI();
		novaURI = "novaURI";
	}
	
	public abstract void criarComponenteGedixComURI();

	@Test
	public void aURIInicialÉVazia(){
		assertEquals(vazia, componenteGedixComURI.obterURI());
	}
	
	
	@Test
	public void aURIPodeSerAlterada(){
		componenteGedixComURI.alterarURI(novaURI);
		assertEquals(novaURI, componenteGedixComURI.obterURI());
	}

	
	@Test
	public void sabeDizerQualASuaURI(){
		assertEquals(vazia, componenteGedixComURI.obterURI());
	}
	
	@Test
	public void éTransformávelEmXMLComURI(){
		assertTrue(componenteGedixComURI instanceof TransformavelEmXMLComURI);
	}

}
