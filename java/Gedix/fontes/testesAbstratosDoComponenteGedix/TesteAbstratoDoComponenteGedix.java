package testesAbstratosDoComponenteGedix;

import static infraestruturaDoComponenteGedix.PosicoesDaLegenda.EM_CIMA;
import static infraestruturaDoComponenteGedix.PosicoesDaLegenda.NA_ESQUERDA;
import static infraestruturaDoComponenteGedix.StringVazia.STRING_VAZIA;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertSame;
import static org.junit.Assert.assertTrue;
import infraestruturaDoComponenteGedix.ComponenteGedix;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import infraestruturaDoTransformadorParaXML.TransformavelEmXML;
import listasDeTestesDoComponenteGedix.ListaDeTestesDoComponenteGedix;

import org.junit.Before;
import org.junit.Test;

import edugraf.jadix.fachada.TiposDeComponentesDix;

public abstract class TesteAbstratoDoComponenteGedix 
				extends TesteAbstratoDoRetanguloPosicionavel
				implements ListaDeTestesDoComponenteGedix{
    
	
	protected TiposDeComponentesDix tipoDoComponenteGedix;
	private String novoNome,  novoConteúdoDaLegenda;
	protected String vazia;
	protected ComponenteGedix
	componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial;
	
	
	@Before
	public void antesDosTestesDeRetanguloDix(){
		
		novoNome = "novoNome";
		vazia = STRING_VAZIA.nome;
		novoConteúdoDaLegenda = "novoConteúdo";
		informarTipoDoComponenteGedix();
		criarComponenteGedix();
		
	}
	
	public abstract void criarComponenteGedix();
	
	public abstract void informarTipoDoComponenteGedix();
	
	@Test
	public void sabeOseuTipo(){
		assertEquals(tipoDoComponenteGedix, componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial.obterTipo());
	}
	
	@Test
	public void seuNomeInicialÉONomeDoSeuTipoJuntoComAOrdemQueEleFoiCriado() {
		
		reiniciarContadorDeRetângulosDixCriados();
		
		ComponenteGedix retânguloDix1 = Fabrica.obterComponenteGedixDoTipo(tipoDoComponenteGedix, Fabrica.obterRetanguloPosicionavelNulo());
		ComponenteGedix retânguloDix2 = Fabrica.obterComponenteGedixDoTipo(tipoDoComponenteGedix, Fabrica.obterRetanguloPosicionavelNulo());
		ComponenteGedix retânguloDix3 = Fabrica.obterComponenteGedixDoTipo(tipoDoComponenteGedix, Fabrica.obterRetanguloPosicionavelNulo());
		
		assertEquals(tipoDoComponenteGedix.nome + 1, retânguloDix1.obterNome());
		assertEquals(tipoDoComponenteGedix.nome + 2, retânguloDix2.obterNome());
		assertEquals(tipoDoComponenteGedix.nome + 3, retânguloDix3.obterNome());
		
	}
	
	
	protected abstract void reiniciarContadorDeRetângulosDixCriados();

	@Test
	public void oSeuNomePodeSerAlterado(){
		componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial.alterarNome(novoNome);
		assertEquals(novoNome, componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial.obterNome());
	}
	
	@Test
	public void aSuaVisibilidadeInicialÉVerdadeiro(){
		assertTrue(componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial.verificarSeEstáVisível());
	}
	
	@Test
	public void aSuaVisibilidadePodeSerAlterada(){
		componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial.tornarInvisível();
		assertFalse(componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial.verificarSeEstáVisível());
		componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial.tornarVisível();
		assertTrue(componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial.verificarSeEstáVisível());
	}
	
	@Test
	public void inicialmenteEstáHabilitado(){
		assertTrue(componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial.verificarSeEstáHabilitado());
	}
	
	@Test
	public void podeSerDesabilitado(){
		componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial.desabilitar();
		assertFalse(componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial.verificarSeEstáHabilitado());
	}
	
	@Test
	public void podeSerReabilitado(){
		componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial.desabilitar();
		assertFalse(componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial.verificarSeEstáHabilitado());
		componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial.habilitar();
		assertTrue(componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial.verificarSeEstáHabilitado());
	}
	
	@Test
	public void aSuaLegendaInicialÉVazia(){
		assertEquals(vazia, componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial.obterLegenda());
	}
	
	@Test
	public void oConteúdoDaSuaLegendaPodeSerAlterada(){
		componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial.alterarLegenda(novoConteúdoDaLegenda);
		assertEquals(novoConteúdoDaLegenda, componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial.obterLegenda());
	}
	
	@Test
	public void podeInformarOConteúdoDaSuaLegenda(){
		assertEquals(vazia, componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial.obterLegenda());
	}
	
	@Test
	public void aPosiçãoInicialDaLegendaÉEmCima(){
		assertEquals(EM_CIMA, componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial.obterPosiçãoDaLegenda());	
	}

	@Test
	public void aPosiçãoDaLegendaPodeSerAlterada(){
		componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial.definirPosiçãoDaLegenda(NA_ESQUERDA);
		assertEquals(NA_ESQUERDA, componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial.obterPosiçãoDaLegenda());	
	}
	
	@Test
	public void podeInformarAPosiçãoDaLegenda(){
		assertEquals(EM_CIMA, componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial.obterPosiçãoDaLegenda());	
	}
	
	@Test
	public void suaProfundidadeInicialÉZero(){
		assertSame(0, componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial.obterProfundidade());
	}
	
	@Test
	public void podeMudarSuaProfundidade(){
		componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial.definirProfundidade(2);
		assertSame(2, componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial.obterProfundidade());
	}
	
	@Test
	public void podeInformarSuaProfundidade(){
		assertSame(0, componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial.obterProfundidade());
	}
	
	@Test
	public void nãoFixaProfundidadeDeValorNegativo(){
		componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial.definirProfundidade(-1);
		assertSame(0, componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial.obterProfundidade());
		
		componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial.definirProfundidade(-2);
		assertSame(0, componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial.obterProfundidade());
		
	}
	
	@Test
	public void éTransformávelEmXML(){
		assertTrue(componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial instanceof TransformavelEmXML);
	}
}
