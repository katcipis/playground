package testesAbstratosDaTransformacaoParaXMLDosComponentesGedix;

import static infraestruturaDoComponenteGedix.PosicoesDaLegenda.EM_CIMA;
import static infraestruturaDoTransformadorParaXML.InicioDosAtributosEmXML.ALTURA;
import static infraestruturaDoTransformadorParaXML.InicioDosAtributosEmXML.ESQUERDA;
import static infraestruturaDoTransformadorParaXML.InicioDosAtributosEmXML.HABILITADO;
import static infraestruturaDoTransformadorParaXML.InicioDosAtributosEmXML.LARGURA;
import static infraestruturaDoTransformadorParaXML.InicioDosAtributosEmXML.LEGENDA;
import static infraestruturaDoTransformadorParaXML.InicioDosAtributosEmXML.NOME;
import static infraestruturaDoTransformadorParaXML.InicioDosAtributosEmXML.POSIÇÃO_DA_LEGENDA;
import static infraestruturaDoTransformadorParaXML.InicioDosAtributosEmXML.PROFUNDIDADE;
import static infraestruturaDoTransformadorParaXML.InicioDosAtributosEmXML.TOPO;
import static infraestruturaDoTransformadorParaXML.InicioDosAtributosEmXML.VISÍVEL;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import infraestruturaDoComponenteGedix.ComponenteGedix;
import infraestruturaDoComponenteGedix.PosicoesDaLegenda;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import infraestruturaDoTransformadorParaXML.MapaDeTiposDeComponentesDixParaXML;
import infraestruturaDoTransformadorParaXML.TransformadorParaXML;
import listasDeTestesDaTransformacaoParaXMLDosComponentesGedix.ListaDeTestesDaTransformacaoParaXMLDoComponenteGedix;

import org.junit.Before;
import org.junit.Test;

import edugraf.jadix.fachada.TiposDeComponentesDix;

public abstract class TesteAbstratoDaTransformacaoParaXMLDoComponenteGedix implements ListaDeTestesDaTransformacaoParaXMLDoComponenteGedix{

	
	protected ComponenteGedix componenteGedixDeNomeGedix,
	componenteGedixDeAlturaZero, componenteGedixDeLarguraZero,
	componenteGedixComLegendaEmCima, componenteGedixDeTopoZero,
	componenteGedixDeEsquerdaZero, componenteGedixDeProfundidadeZero,
	componenteGedixComLegendaDeTextoGedix, componenteGedixDesabilitado,
	componenteGedixInvisível, componenteGedixDoTipoInformado;
	
	protected TiposDeComponentesDix tipoDoComponenteQueSeráTestado;
	
	private PosicoesDaLegenda novaPosiçãoDaLegenda;
	
	private TransformadorParaXML transformador;
	
	private Integer valorZero, novaEsquerda, novoTopo, novaAltura, novaLargura, novaProfundidade;
	
	protected String atributoAlturaComValorZero, atributoEsquerdaComValorZero, falso,
	atributoHabilitadoComValorFalso,atributoLarguraComValorZero, gedix, atributoLegendaComTextoGedix,
	atributoNomeComTextoGedix, atributoPosiçãoDaLegendaEmCima, atributoProfundidadeComValorZero,
	atributoTopoComValorZero, atributoVisívelComValorFalso, atributoTipoDoComponenteQueSeráTestado,
	xmlComTodosOsAtributosDoComponenteDeNomeGedix,inícioDoMarcador, fimDoMarcador, 
	fechaMarcador, espaçoVazio, aspa, novaLegenda, novoNome;
	
	@Before
	public void antesDosTestesDaTransformacaoParaXMLDoComponenteGedix(){
		
		tipoDoComponenteQueSeráTestado = retornarTipoDoComponenteDixQueSeráTestado();
		
		valorZero = 0;
		
		novaEsquerda = 10;
		novoTopo = 10;
		novaAltura = 10;
		novaLargura = 10;
		novaProfundidade = 5;
		
		novaPosiçãoDaLegenda = PosicoesDaLegenda.NA_ESQUERDA;
		
		falso = "falso";
		
		gedix = "Gedix";
		
		inícioDoMarcador = "<";
		espaçoVazio = " ";
		fimDoMarcador = ">";
		fechaMarcador = "</";
		aspa = "\"";
		novaLegenda = "novaLegenda";
		novoNome = "novoNome";
		
		criarComponentesDix();
		
		criarAtributos();
		
		transformador = Fabrica.obterTransformadorParaXML();
		
		xmlComTodosOsAtributosDoComponenteDeNomeGedix =  gerarXML()
		+ fimDoMarcador + fechaMarcador + atributoTipoDoComponenteQueSeráTestado
		+ fimDoMarcador;
		
	}
	
	protected String gerarXML(){
		return inícioDoMarcador + atributoTipoDoComponenteQueSeráTestado + espaçoVazio +
		atributoNomeComTextoGedix + espaçoVazio + atributoLarguraComValorZero + espaçoVazio +
		atributoAlturaComValorZero + espaçoVazio + atributoEsquerdaComValorZero + espaçoVazio
		+ atributoTopoComValorZero + espaçoVazio + atributoLegendaComTextoGedix + espaçoVazio
		+ atributoPosiçãoDaLegendaEmCima + espaçoVazio + atributoProfundidadeComValorZero +
		espaçoVazio + atributoVisívelComValorFalso + espaçoVazio + atributoHabilitadoComValorFalso;
	}


	private void criarAtributos() {
		
		MapaDeTiposDeComponentesDixParaXML mapa = new MapaDeTiposDeComponentesDixParaXML();
		
		atributoAlturaComValorZero = ALTURA.inícioDoAtributo + aspa + valorZero.toString() + aspa;
		atributoLarguraComValorZero = LARGURA.inícioDoAtributo + aspa + valorZero.toString() + aspa;
		atributoEsquerdaComValorZero = ESQUERDA.inícioDoAtributo + aspa + valorZero.toString() + aspa;
		atributoHabilitadoComValorFalso = HABILITADO.inícioDoAtributo + aspa + falso + aspa;
		atributoLegendaComTextoGedix = LEGENDA.inícioDoAtributo + aspa + gedix + aspa;
		atributoNomeComTextoGedix = NOME.inícioDoAtributo + aspa + gedix + aspa;
		atributoPosiçãoDaLegendaEmCima = POSIÇÃO_DA_LEGENDA.inícioDoAtributo + aspa + EM_CIMA.nome + aspa;
		atributoProfundidadeComValorZero = PROFUNDIDADE.inícioDoAtributo + aspa + valorZero.toString() + aspa;
		atributoTopoComValorZero = TOPO.inícioDoAtributo + aspa + valorZero.toString() + aspa;
		atributoVisívelComValorFalso = VISÍVEL.inícioDoAtributo + aspa + falso + aspa;
		atributoTipoDoComponenteQueSeráTestado = mapa.obterXML(componenteGedixDeNomeGedix.obterTipo());
	}
	
	protected abstract TiposDeComponentesDix retornarTipoDoComponenteDixQueSeráTestado();

	private void criarComponentesDix(){
		componenteGedixDeNomeGedix = Fabrica.obterComponenteGedixDoTipo(tipoDoComponenteQueSeráTestado, 
				Fabrica.obterRetanguloPosicionavel(Fabrica.obterRetangulo(Fabrica.obterDimensão(0, 0))));
		
		componenteGedixDeNomeGedix.alterarNome(gedix);
		componenteGedixDeNomeGedix.alterarLegenda(gedix);
		componenteGedixDeNomeGedix.desabilitar();
		componenteGedixDeNomeGedix.tornarInvisível();
		
		
		componenteGedixDeAlturaZero =  Fabrica.obterComponenteGedixDoTipo(tipoDoComponenteQueSeráTestado, 
				Fabrica.obterRetanguloPosicionavel(Fabrica.obterRetangulo(Fabrica.obterDimensão(0, 0))));
		
		componenteGedixDeLarguraZero =  Fabrica.obterComponenteGedixDoTipo(tipoDoComponenteQueSeráTestado, 
				Fabrica.obterRetanguloPosicionavel(Fabrica.obterRetangulo(Fabrica.obterDimensão(0, 0))));
		
		componenteGedixComLegendaEmCima =  Fabrica.obterComponenteGedixDoTipo(tipoDoComponenteQueSeráTestado, 
				Fabrica.obterRetanguloPosicionavel(Fabrica.obterRetangulo(Fabrica.obterDimensão(0, 0))));
		
		componenteGedixDeTopoZero = Fabrica.obterComponenteGedixDoTipo(tipoDoComponenteQueSeráTestado, 
				Fabrica.obterRetanguloPosicionavel(Fabrica.obterRetangulo(Fabrica.obterDimensão(0, 0))));
		
		componenteGedixDeEsquerdaZero = Fabrica.obterComponenteGedixDoTipo(tipoDoComponenteQueSeráTestado, 
				Fabrica.obterRetanguloPosicionavel(Fabrica.obterRetangulo(Fabrica.obterDimensão(0, 0))));
		
		componenteGedixDeProfundidadeZero = Fabrica.obterComponenteGedixDoTipo(tipoDoComponenteQueSeráTestado, 
				Fabrica.obterRetanguloPosicionavel(Fabrica.obterRetangulo(Fabrica.obterDimensão(0, 0))));
		
		componenteGedixComLegendaDeTextoGedix =  Fabrica.obterComponenteGedixDoTipo(tipoDoComponenteQueSeráTestado, 
				Fabrica.obterRetanguloPosicionavel(Fabrica.obterRetangulo(Fabrica.obterDimensão(0, 0))));
		
		componenteGedixComLegendaDeTextoGedix.alterarLegenda(gedix);
		
		componenteGedixDesabilitado = Fabrica.obterComponenteGedixDoTipo(tipoDoComponenteQueSeráTestado, 
				Fabrica.obterRetanguloPosicionavel(Fabrica.obterRetangulo(Fabrica.obterDimensão(0, 0))));
		
		componenteGedixDesabilitado.desabilitar();
		
		componenteGedixInvisível = Fabrica.obterComponenteGedixDoTipo(tipoDoComponenteQueSeráTestado, 
				Fabrica.obterRetanguloPosicionavel(Fabrica.obterRetangulo(Fabrica.obterDimensão(0, 0))));
		
		componenteGedixInvisível.tornarInvisível();
		
		componenteGedixDoTipoInformado = Fabrica.obterComponenteGedixDoTipo(tipoDoComponenteQueSeráTestado, 
				Fabrica.obterRetanguloPosicionavel(Fabrica.obterRetangulo(Fabrica.obterDimensão(0, 0))));
	}
	
	@Test
	public void dadoUmComponenteGedixPodeGerarOAtributoAltura() {
		assertEquals(atributoAlturaComValorZero, 
				transformador.obterOAtributoAltura(componenteGedixDeAlturaZero));
		
		componenteGedixDeAlturaZero.definirAltura(novaAltura);
		
		assertFalse(atributoAlturaComValorZero
				.equals(transformador.obterOAtributoAltura(componenteGedixDeAlturaZero)));
	}

	@Test
	public void dadoUmComponenteGedixPodeGerarOAtributoEsquerda() {
		assertEquals(atributoEsquerdaComValorZero, 
				transformador.obterOAtributoEsquerda(componenteGedixDeEsquerdaZero));
		
		componenteGedixDeEsquerdaZero.definirPosiçãoDeOrigem(Fabrica.obterPosição(novaEsquerda, novoTopo));
		
		assertFalse(atributoEsquerdaComValorZero.equals
				(transformador.obterOAtributoEsquerda(componenteGedixDeEsquerdaZero)));
		
	}

	@Test
	public void dadoUmComponenteGedixPodeGerarOAtributoHabilitado() {
		assertEquals(atributoHabilitadoComValorFalso, 
				transformador.obterOAtributoHabilitado(componenteGedixDesabilitado));
		
		componenteGedixDesabilitado.habilitar();
		
		assertFalse(atributoHabilitadoComValorFalso.equals
				(transformador.obterOAtributoHabilitado(componenteGedixDesabilitado)));
		
	}

	@Test
	public void dadoUmComponenteGedixPodeGerarOAtributoLargura() {
		assertEquals(atributoLarguraComValorZero, 
				transformador.obterOAtributoLargura(componenteGedixDeLarguraZero));
		
		componenteGedixDeLarguraZero.definirLargura(novaLargura);
		
		assertFalse(atributoLarguraComValorZero.equals 
				(transformador.obterOAtributoLargura(componenteGedixDeLarguraZero)));
		
	}

	@Test
	public void dadoUmComponenteGedixPodeGerarOAtributoLegenda() {
		assertEquals(atributoLegendaComTextoGedix, 
				transformador.obterOAtributoLegenda(componenteGedixComLegendaDeTextoGedix));
		
		componenteGedixComLegendaDeTextoGedix.alterarLegenda(novaLegenda);
		
		assertFalse(atributoLegendaComTextoGedix.equals 
				(transformador.obterOAtributoLegenda(componenteGedixComLegendaDeTextoGedix)));
		
	}

	@Test
	public void dadoUmComponenteGedixPodeGerarOAtributoNome() {
		assertEquals(atributoNomeComTextoGedix, 
				transformador.obterOAtributoNome(componenteGedixDeNomeGedix));
		
		componenteGedixDeNomeGedix.alterarNome(novoNome);
		
		assertFalse(atributoNomeComTextoGedix.equals 
				(transformador.obterOAtributoNome(componenteGedixDeNomeGedix)));
		
	}

	@Test
	public void dadoUmComponenteGedixPodeGerarOAtributoPosiçãoDaLegenda() {
		assertEquals(atributoPosiçãoDaLegendaEmCima, 
				transformador.obterOAtributoPosiçãoDaLegenda(componenteGedixComLegendaEmCima));
		
		componenteGedixComLegendaEmCima.definirPosiçãoDaLegenda(novaPosiçãoDaLegenda);
		
		assertFalse(atributoPosiçãoDaLegendaEmCima.equals 
				(transformador.obterOAtributoPosiçãoDaLegenda(componenteGedixComLegendaEmCima)));
		
	}

	@Test
	public void dadoUmComponenteGedixPodeGerarOAtributoProfundidade() {
		assertEquals(atributoProfundidadeComValorZero, 
				transformador.obterOAtributoProfundidade(componenteGedixDeProfundidadeZero));
		
		componenteGedixDeProfundidadeZero.definirProfundidade(novaProfundidade);
		
		assertFalse(atributoProfundidadeComValorZero.equals
				(transformador.obterOAtributoProfundidade(componenteGedixDeProfundidadeZero)));
		
	}

	@Test
	public void dadoUmComponenteGedixPodeGerarOAtributoTopo() {
		assertEquals(atributoTopoComValorZero, 
				transformador.obterOAtributoTopo(componenteGedixDeTopoZero));
		
		componenteGedixDeTopoZero.definirPosiçãoDeOrigem(Fabrica.obterPosição(novaEsquerda, novoTopo));
		
		assertFalse(atributoTopoComValorZero.equals 
				(transformador.obterOAtributoTopo(componenteGedixDeTopoZero)));
		
	}

	@Test
	public void dadoUmComponenteGedixPodeGerarOAtributoVisível() {
		assertEquals(atributoVisívelComValorFalso, 
				transformador.obterOAtributoVisível(componenteGedixInvisível));
		
		componenteGedixInvisível.tornarVisível();
		
		assertFalse(atributoVisívelComValorFalso.equals 
				(transformador.obterOAtributoVisível(componenteGedixInvisível)));
		
	}

	@Test
	public void dadoUmComponenteGedixPodeGerarOXMLCompleto() {
	  
		assertEquals(xmlComTodosOsAtributosDoComponenteDeNomeGedix ,
			  			transformador.obterXML(componenteGedixDeNomeGedix));
	  
	  componenteGedixDeNomeGedix.alterarNome(novoNome);
	  
	  assertFalse(xmlComTodosOsAtributosDoComponenteDeNomeGedix.equals
			  (transformador.obterXML(componenteGedixDeNomeGedix)));
		
	}

	@Test
	public void dadoUmComponenteGedixPodeGerarOAtributoTipoDoComponenteGedix() {
		assertEquals(atributoTipoDoComponenteQueSeráTestado, 
				transformador.obterOAtributoTipo(componenteGedixDoTipoInformado));
		
		
	}

	
}


