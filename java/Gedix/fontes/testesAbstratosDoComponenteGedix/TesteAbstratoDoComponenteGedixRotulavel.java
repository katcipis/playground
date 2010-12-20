package testesAbstratosDoComponenteGedix;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;
import infraestruturaDoComponenteGedix.ComponenteGedixRotulavel;
import infraestruturaDoTransformadorParaXML.TransformavelEmXMLRotulavel;
import listasDeTestesDoComponenteGedix.ListaDeTestesDoComponenteGedixRotulavel;

import org.junit.Before;
import org.junit.Test;

public abstract class TesteAbstratoDoComponenteGedixRotulavel extends TesteAbstratoDoComponenteGedix 
															implements ListaDeTestesDoComponenteGedixRotulavel{
	
	protected ComponenteGedixRotulavel componenteGedixRotulável;
	private String  novoTexto;
	
	@Before
	public void antesDosTestesDoComponenteGedixRotulável(){
		criarComponenteGedixRotulável();
		
		novoTexto = "novoTexto";
	}
	
	public abstract void criarComponenteGedixRotulável();
	
    @Test
	public void oTextoInicialÉVazio(){
    	assertEquals(vazia, componenteGedixRotulável.obterTexto());
    }
	
    @Test
    public void oTextoPodeSerAlterado(){
    	componenteGedixRotulável.alterarTexto(novoTexto);
    	assertEquals(novoTexto, componenteGedixRotulável.obterTexto());
    }
	
    @Test
    public void podeInformarQualOSeuTexto(){
    	assertEquals(vazia, componenteGedixRotulável.obterTexto());
    }
    
    @Test
    public void éTransformávelEmXMLRotulável(){
    	assertTrue(componenteGedixRotulável instanceof TransformavelEmXMLRotulavel);
    }

}
