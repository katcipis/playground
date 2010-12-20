package testesDosTransformadoresParaXML;

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
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import infraestruturaDoTransformadorParaXML.TransformadorParaXML;
import listasDeTestesDosTransformadoresParaXML.ListaDeTestesDoTransformadorParaXML;
import mocksDeTransformaveisParaXML.MockTransformavelEmXML;

import org.junit.Before;
import org.junit.Test;

public abstract class TesteAbstratoDoTransformadorParaXML implements ListaDeTestesDoTransformadorParaXML{

	private MockTransformavelEmXML transformávelDeNomeMock,
	transformávelDeAlturaZero, transformávelDeLarguraZero,
	transformávelComLegendaEmCima, transformávelDeTopoZero,
	transformávelDeEsquerdaZero, transformávelDeProfundidadeZero,
	transformávelComLegendaDeTextoMock, transformávelDesabilitado,
	transformávelInvisível, transformávelDoTipoBotão;
	
	private TransformadorParaXML transformador;
	
	private Integer valorZero;
	
	protected String atributoAlturaComValorZero, atributoEsquerdaComValorZero, falso,
	atributoHabilitadoComValorFalso,atributoLarguraComValorZero, mock, atributoLegendaComTextoMock,
	atributoNomeComTextoMock, atributoPosiçãoDaLegendaEmCima, atributoProfundidadeComValorZero,
	atributoTopoComValorZero, atributoVisívelComValorFalso, atributoTipoComValorBotão,
	xmlComTodosOsAtributosDoTransformávelDeNomeMock,inícioDoMarcador, fimDoMarcador, 
	fechaMarcador, espaçoVazio, aspa;
	
	@Before
	public void antesDosTestesDoTransformadorParaXML(){
		
		valorZero = 0;
		
		falso = "falso";
		
		mock = "Mock";
		
		inícioDoMarcador = "<";
		espaçoVazio = " ";
		fimDoMarcador = ">";
		fechaMarcador = "</";
		aspa = "\"";
		
		criarTransformáveisEmXML();
		
		criarAtributos();
		
		transformador = criarTransformadorParaXMLQueSeráTestado();
		
		xmlComTodosOsAtributosDoTransformávelDeNomeMock =  gerarXML()
		+ fimDoMarcador + fechaMarcador + atributoTipoComValorBotão
		+ fimDoMarcador;
		
	}
	
	protected String gerarXML(){
		return inícioDoMarcador + atributoTipoComValorBotão + espaçoVazio +
		atributoNomeComTextoMock + espaçoVazio + atributoLarguraComValorZero + espaçoVazio +
		atributoAlturaComValorZero + espaçoVazio + atributoEsquerdaComValorZero + espaçoVazio
		+ atributoTopoComValorZero + espaçoVazio + atributoLegendaComTextoMock + espaçoVazio
		+ atributoPosiçãoDaLegendaEmCima + espaçoVazio + atributoProfundidadeComValorZero +
		espaçoVazio + atributoVisívelComValorFalso + espaçoVazio + atributoHabilitadoComValorFalso;
	}

	protected abstract TransformadorParaXML criarTransformadorParaXMLQueSeráTestado();

	private void criarAtributos() {
		atributoAlturaComValorZero = ALTURA.inícioDoAtributo + aspa + valorZero.toString() + aspa;
		atributoLarguraComValorZero = LARGURA.inícioDoAtributo + aspa + valorZero.toString() + aspa;
		atributoEsquerdaComValorZero = ESQUERDA.inícioDoAtributo + aspa + valorZero.toString() + aspa;
		atributoHabilitadoComValorFalso = HABILITADO.inícioDoAtributo + aspa + falso + aspa;
		atributoLegendaComTextoMock = LEGENDA.inícioDoAtributo + aspa + mock + aspa;
		atributoNomeComTextoMock = NOME.inícioDoAtributo + aspa + mock + aspa;
		atributoPosiçãoDaLegendaEmCima = POSIÇÃO_DA_LEGENDA.inícioDoAtributo + aspa + EM_CIMA.nome + aspa;
		atributoProfundidadeComValorZero = PROFUNDIDADE.inícioDoAtributo + aspa + valorZero.toString() + aspa;
		atributoTopoComValorZero = TOPO.inícioDoAtributo + aspa + valorZero.toString() + aspa;
		atributoVisívelComValorFalso = VISÍVEL.inícioDoAtributo + aspa + falso + aspa;
		atributoTipoComValorBotão = "botão";
	}

	private void criarTransformáveisEmXML() {
		transformávelDeNomeMock = Fabrica.obterMockTransformavelEmXML();
		transformávelDeAlturaZero = Fabrica.obterMockTransformavelEmXML();
		transformávelDeLarguraZero = Fabrica.obterMockTransformavelEmXML();
		transformávelComLegendaEmCima = Fabrica.obterMockTransformavelEmXML();
		transformávelDeTopoZero = Fabrica.obterMockTransformavelEmXML();
		transformávelDeEsquerdaZero = Fabrica.obterMockTransformavelEmXML();
		transformávelDeProfundidadeZero = Fabrica.obterMockTransformavelEmXML();
		transformávelComLegendaDeTextoMock = Fabrica.obterMockTransformavelEmXML();
		transformávelDesabilitado = Fabrica.obterMockTransformavelEmXML();
		transformávelInvisível = Fabrica.obterMockTransformavelEmXML();
		transformávelDoTipoBotão = Fabrica.obterMockTransformavelEmXML();
	}
	
	@Test
	public void dadoUmTransformavelEmXMLPodeGerarOAtributoAltura() {
		assertEquals(atributoAlturaComValorZero, 
				transformador.obterOAtributoAltura(transformávelDeAlturaZero));
		
		transformávelDeAlturaZero.alterarAtributos();
		
		assertFalse(atributoAlturaComValorZero
				.equals(transformador.obterOAtributoAltura(transformávelDeAlturaZero)));
	}

	@Test
	public void dadoUmTransformavelEmXMLPodeGerarOAtributoEsquerda() {
		assertEquals(atributoEsquerdaComValorZero, 
				transformador.obterOAtributoEsquerda(transformávelDeEsquerdaZero));
		
		transformávelDeEsquerdaZero.alterarAtributos();
		
		assertFalse(atributoEsquerdaComValorZero.equals
				(transformador.obterOAtributoEsquerda(transformávelDeEsquerdaZero)));
		
	}

	@Test
	public void dadoUmTransformavelEmXMLPodeGerarOAtributoHabilitado() {
		assertEquals(atributoHabilitadoComValorFalso, 
				transformador.obterOAtributoHabilitado(transformávelDesabilitado));
		
		transformávelDesabilitado.alterarAtributos();
		
		assertFalse(atributoHabilitadoComValorFalso.equals
				(transformador.obterOAtributoHabilitado(transformávelDesabilitado)));
		
	}

	@Test
	public void dadoUmTransformavelEmXMLPodeGerarOAtributoLargura() {
		assertEquals(atributoLarguraComValorZero, 
				transformador.obterOAtributoLargura(transformávelDeLarguraZero));
		
		transformávelDeLarguraZero.alterarAtributos();
		
		assertFalse(atributoLarguraComValorZero.equals 
				(transformador.obterOAtributoLargura(transformávelDeLarguraZero)));
		
	}

	@Test
	public void dadoUmTransformavelEmXMLPodeGerarOAtributoLegenda() {
		assertEquals(atributoLegendaComTextoMock, 
				transformador.obterOAtributoLegenda(transformávelComLegendaDeTextoMock));
		
		transformávelComLegendaDeTextoMock.alterarAtributos();
		
		assertFalse(atributoLegendaComTextoMock.equals 
				(transformador.obterOAtributoLegenda(transformávelComLegendaDeTextoMock)));
		
	}

	@Test
	public void dadoUmTransformavelEmXMLPodeGerarOAtributoNome() {
		assertEquals(atributoNomeComTextoMock, 
				transformador.obterOAtributoNome(transformávelDeNomeMock));
		
		transformávelDeNomeMock.alterarAtributos();
		
		assertFalse(atributoNomeComTextoMock.equals 
				(transformador.obterOAtributoNome(transformávelDeNomeMock)));
		
	}

	@Test
	public void dadoUmTransformavelEmXMLPodeGerarOAtributoPosiçãoDaLegenda() {
		assertEquals(atributoPosiçãoDaLegendaEmCima, 
				transformador.obterOAtributoPosiçãoDaLegenda(transformávelComLegendaEmCima));
		
		transformávelComLegendaEmCima.alterarAtributos();
		
		assertFalse(atributoPosiçãoDaLegendaEmCima.equals 
				(transformador.obterOAtributoPosiçãoDaLegenda(transformávelComLegendaEmCima)));
		
	}

	@Test
	public void dadoUmTransformavelEmXMLPodeGerarOAtributoProfundidade() {
		assertEquals(atributoProfundidadeComValorZero, 
				transformador.obterOAtributoProfundidade(transformávelDeProfundidadeZero));
		
		transformávelDeProfundidadeZero.alterarAtributos();
		
		assertFalse(atributoProfundidadeComValorZero.equals
				(transformador.obterOAtributoProfundidade(transformávelDeProfundidadeZero)));
		
	}

	@Test
	public void dadoUmTransformavelEmXMLPodeGerarOAtributoTopo() {
		assertEquals(atributoTopoComValorZero, 
				transformador.obterOAtributoTopo(transformávelDeTopoZero));
		
		transformávelDeTopoZero.alterarAtributos();
		
		assertFalse(atributoTopoComValorZero.equals 
				(transformador.obterOAtributoTopo(transformávelDeTopoZero)));
		
	}

	@Test
	public void dadoUmTransformavelEmXMLPodeGerarOAtributoVisível() {
		assertEquals(atributoVisívelComValorFalso, 
				transformador.obterOAtributoVisível(transformávelInvisível));
		
		transformávelInvisível.alterarAtributos();
		
		assertFalse(atributoVisívelComValorFalso.equals 
				(transformador.obterOAtributoVisível(transformávelInvisível)));
		
	}

	@Test
	public void dadoUmTransformavelEmXMLPodeGerarOXMLCompleto() {
	  
		assertEquals(xmlComTodosOsAtributosDoTransformávelDeNomeMock ,
			  			transformador.obterXML(transformávelDeNomeMock));
	  
	  transformávelDeNomeMock.alterarAtributos();
	  
	  assertFalse(xmlComTodosOsAtributosDoTransformávelDeNomeMock.equals
			  (transformador.obterXML(transformávelDeNomeMock)));
		
	}

	@Test
	public void dadoUmTransformavelEmXMLPodeGerarOAtributoTipoDoTransformavel() {
		assertEquals(atributoTipoComValorBotão, 
				transformador.obterOAtributoTipo(transformávelDoTipoBotão));
		
		transformávelDoTipoBotão.alterarAtributos();
		
		assertFalse(atributoTipoComValorBotão.equals
				(transformador.obterOAtributoTipo(transformávelDoTipoBotão)));
	
		
	}

	
}
