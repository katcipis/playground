package testesDaInfraestruturaDoPainel;

import static edugraf.jadix.fachada.TiposDeComponentesDix.BOTÃO;
import static edugraf.jadix.fachada.TiposDeComponentesDix.BOTÕES_DE_RÁDIO;
import static edugraf.jadix.fachada.TiposDeComponentesDix.CAIXA_DE_ESCOLHA;
import static edugraf.jadix.fachada.TiposDeComponentesDix.CAMPO_DE_TEXTO;
import static edugraf.jadix.fachada.TiposDeComponentesDix.ENLACE;
import static edugraf.jadix.fachada.TiposDeComponentesDix.ETIQUETA;
import static edugraf.jadix.fachada.TiposDeComponentesDix.GRADE;
import static edugraf.jadix.fachada.TiposDeComponentesDix.IMAGEM;
import static edugraf.jadix.fachada.TiposDeComponentesDix.LISTA_DE_ESCOLHA;
import static edugraf.jadix.fachada.TiposDeComponentesDix.ÁREA_DE_TEXTO;
import static edugraf.jadix.fachada.TiposDeComponentesDix.ÁREA_SENSÍVEL;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;
import infraestruturaDoComponenteGedix.ComponenteGedixRotulavelComURI;
import infraestruturaDoComponenteGedix.ConjuntoDeOpcoes;
import infraestruturaDoComponenteGedix.Opcao;
import infraestruturaDoComponenteGedix.OpcaoNula;
import infraestruturaDoPainelDeComponenteGedix.Dimensao;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import infraestruturaDoPainelDeComponenteGedix.Posicao;
import infraestruturaDoPainelDeComponenteGedix.Retangulo;
import infraestruturaDoPainelDeComponenteGedix.RetanguloConcreto;
import infraestruturaDoPainelDeComponenteGedix.RetanguloPosicionavel;
import infraestruturaDoPainelDeComponenteGedix.RetanguloPosicionavelNulo;
import infraestruturaDoTransformadorParaXML.TransformadorParaXML;
import infraestruturaDoTransformadorParaXML.TransformadorParaXMLComGrade;
import infraestruturaDoTransformadorParaXML.TransformadorParaXMLComOpcoes;
import infraestruturaDoTransformadorParaXML.TransformadorParaXMLComURI;
import infraestruturaDoTransformadorParaXML.TransformadorParaXMLRotulavel;
import infraestruturaDoTransformadorParaXML.TransformadorParaXMLRotulavelComURI;
import listasDeTestesDaInfraestruturaDoPainel.ListaDeTestesDaFabrica;
import mocksDeTransformaveisParaXML.MockTransformavelEmXML;
import mocksDeTransformaveisParaXML.MockTransformavelEmXMLComGrade;
import mocksDeTransformaveisParaXML.MockTransformavelEmXMLComOpcoes;
import mocksDeTransformaveisParaXML.MockTransformavelEmXMLComURI;
import mocksDeTransformaveisParaXML.MockTransformavelEmXMLRotulavel;
import mocksDeTransformaveisParaXML.MockTransformavelEmXMLRotulavelComURI;

import org.junit.Before;
import org.junit.Test;

import tiposDeComponenteGedix.AreaDeTexto;
import tiposDeComponenteGedix.AreaSensivel;
import tiposDeComponenteGedix.Botao;
import tiposDeComponenteGedix.BotoesDeRadio;
import tiposDeComponenteGedix.CaixaDeEscolha;
import tiposDeComponenteGedix.CampoDeTexto;
import tiposDeComponenteGedix.Enlace;
import tiposDeComponenteGedix.Etiqueta;
import tiposDeComponenteGedix.Grade;
import tiposDeComponenteGedix.Imagem;
import tiposDeComponenteGedix.ListaDeEscolha;
import tiposDeComponenteGedix.ComponenteGedixNulo;


public class TesteDaFabrica implements ListaDeTestesDaFabrica{

	private Retangulo retanguloDeAlturaDezLarguraVinte;
	private String nomeDaOpção;
	
	@Before
	public void criarRetângulo(){
		
		retanguloDeAlturaDezLarguraVinte = Fabrica
		.obterRetangulo(Fabrica.obterDimensão(10, 20));
		nomeDaOpção = "nome";
	}
	
	@Test
	public void dadoADistanciaDaEsquerdaEDoTopoRetornaUmaPosiçãoComAMesmaDistanciaDaEsquerdaEDoTopo(){
		assertEquals(new Posicao(3,3), Fabrica.obterPosição(3, 3));
	}
	
	@Test
	public void dadoADistanciaDaEsquerdaEDoTopoNãoRetornaUmaPosiçãoComOutraDistanciaDaEsquerdaEDoTopo(){
		assertFalse(new Posicao(3,3).equals(Fabrica.obterPosição(3, 4)));
	}
	
	@Test
	public void dadoAAlturaEALarguraRetornaUmaDimensãoComEstaAlturaEEssaLargura(){
		assertEquals(new Dimensao(3,3), Fabrica.obterDimensão(3, 3));
	}

	@Test
	public void dadoAAlturaEALarguraNãoRetornaUmaDimensãoComOutraAlturaEOutraLargura(){
		assertFalse(new Dimensao(3,3).equals(Fabrica.obterDimensão(3, 4)));
	}
	
	@Test
    public void dadoUmaDimensãoRetornaUmRetanguloComAquelaDimensão(){
		assertEquals(new RetanguloConcreto(Fabrica.obterDimensão(3, 3)), 
				Fabrica.obterRetangulo(Fabrica.obterDimensão(3, 3)));
	}
	
	@Test
	public void dadoUmaDimensãoNãoRetornaUmRetanguloComOutraDimensão(){
		assertFalse(new RetanguloConcreto(Fabrica.obterDimensão(3, 4)).
				equals(Fabrica.obterRetangulo(Fabrica.obterDimensão(3, 3))));
	}
	
	@Test
	public void dadoUmRetanguloRetornaUmRetanguloPosicionavelDeMesmaDimensão(){
		RetanguloPosicionavel retânguloPosicionavelDeAlturaDezLarguraVinte = 
			Fabrica.obterRetanguloPosicionavel(retanguloDeAlturaDezLarguraVinte);
		
		assertEquals(retanguloDeAlturaDezLarguraVinte.obterDimensão(),
				retânguloPosicionavelDeAlturaDezLarguraVinte.obterDimensão());
	}
	
	@Test
	public void semFornecerUmRetanguloRetornaUmRetanguloPosicionavelNulo(){
		assertEquals(new RetanguloPosicionavelNulo(), Fabrica.obterRetanguloPosicionavelNulo());
	}
	
	@Test
	public void podeFornecerUmComponenteGedixNulo(){
		assertEquals(new ComponenteGedixNulo(), Fabrica.obterComponenteGedixNulo());
	}
	
	@Test
	public void dadoUmTipoDeComponenteDixEUmRetanguloPosicionavelRetornaUmComponenteGedixDeMesmoTipo(){
		assertTrue(Fabrica.obterComponenteGedixDoTipo(BOTÃO, Fabrica.obterRetanguloPosicionavelNulo())
				instanceof Botao);
		
		assertTrue(Fabrica.obterComponenteGedixDoTipo(BOTÕES_DE_RÁDIO, Fabrica.obterRetanguloPosicionavelNulo())
				instanceof BotoesDeRadio);
		
		assertTrue(Fabrica.obterComponenteGedixDoTipo(CAIXA_DE_ESCOLHA, Fabrica.obterRetanguloPosicionavelNulo())
				instanceof CaixaDeEscolha);
		
		assertTrue(Fabrica.obterComponenteGedixDoTipo(CAMPO_DE_TEXTO, Fabrica.obterRetanguloPosicionavelNulo())
				instanceof CampoDeTexto);
		
		assertTrue(Fabrica.obterComponenteGedixDoTipo(ENLACE, Fabrica.obterRetanguloPosicionavelNulo())
				instanceof Enlace);
		
		assertTrue(Fabrica.obterComponenteGedixDoTipo(ETIQUETA, Fabrica.obterRetanguloPosicionavelNulo())
				instanceof Etiqueta);
		
		assertTrue(Fabrica.obterComponenteGedixDoTipo(GRADE, Fabrica.obterRetanguloPosicionavelNulo())
				instanceof Grade);
		
		assertTrue(Fabrica.obterComponenteGedixDoTipo(IMAGEM, Fabrica.obterRetanguloPosicionavelNulo())
				instanceof Imagem);
		
		assertTrue(Fabrica.obterComponenteGedixDoTipo(LISTA_DE_ESCOLHA, Fabrica.obterRetanguloPosicionavelNulo())
				instanceof ListaDeEscolha);
		
		assertTrue(Fabrica.obterComponenteGedixDoTipo(ÁREA_DE_TEXTO, Fabrica.obterRetanguloPosicionavelNulo())
				instanceof AreaDeTexto);
		
		assertTrue(Fabrica.obterComponenteGedixDoTipo(ÁREA_SENSÍVEL, Fabrica.obterRetanguloPosicionavelNulo())
				instanceof AreaSensivel);
	}

	
	@Test
	public void dadoUmTipoDeComponenteDixRotulavelEUmRetanguloPosicionavelRetornaUmComponenteGedixRotulavelDeMesmoTipo() {
		
		assertTrue(Fabrica.obterComponenteGedixRotulavelDoTipo(BOTÃO, Fabrica.obterRetanguloPosicionavelNulo())
				instanceof Botao);
		
		assertTrue(Fabrica.obterComponenteGedixRotulavelDoTipo(CAMPO_DE_TEXTO, Fabrica.obterRetanguloPosicionavelNulo())
				instanceof CampoDeTexto);
		
		assertTrue(Fabrica.obterComponenteGedixRotulavelDoTipo(ENLACE, Fabrica.obterRetanguloPosicionavelNulo())
				instanceof Enlace);
		
		assertTrue(Fabrica.obterComponenteGedixRotulavelDoTipo(ETIQUETA, Fabrica.obterRetanguloPosicionavelNulo())
				instanceof Etiqueta);
		
		assertTrue(Fabrica.obterComponenteGedixRotulavelDoTipo(ÁREA_DE_TEXTO, Fabrica.obterRetanguloPosicionavelNulo())
				instanceof AreaDeTexto);
		
		
	}

	@Test
	public void seDerUmTipoDeComponenteDixRotulavelInválidoRetornaComponenteGedixNulo() {
		assertTrue(Fabrica.obterComponenteGedixRotulavelDoTipo(ÁREA_SENSÍVEL, Fabrica.obterRetanguloPosicionavelNulo())
				instanceof ComponenteGedixNulo);
		
	}

	@Test
	public void seDerUmTipoDeComponenteDixInválidoRetornaUmComponenteGedixNulo() {	
	}

	@Test
	public void dadoUmTipoDeComponenteDixComGradeEUmRetanguloPosicionavelRetornaUmComponenteGedixComGradeDeMesmoTipo() {
		
		assertTrue(Fabrica.obterComponenteGedixComGradeDoTipo(GRADE, Fabrica.obterRetanguloPosicionavelNulo())
				instanceof Grade);
		
	}

	@Test
	public void dadoUmTipoDeComponenteDixComListaDeOpçõesEUmRetanguloPosicionavelRetornaUmComponenteGedixComListaDeOpçõesDeMesmoTipo() {
		
		assertTrue(Fabrica.obterComponenteGedixComOpçõesDoTipo(LISTA_DE_ESCOLHA, Fabrica.obterRetanguloPosicionavelNulo())
				instanceof ListaDeEscolha);
		
		assertTrue(Fabrica.obterComponenteGedixComOpçõesDoTipo(BOTÕES_DE_RÁDIO, Fabrica.obterRetanguloPosicionavelNulo())
				instanceof BotoesDeRadio);
		
		assertTrue(Fabrica.obterComponenteGedixComOpçõesDoTipo(CAIXA_DE_ESCOLHA, Fabrica.obterRetanguloPosicionavelNulo())
				instanceof CaixaDeEscolha);
		
		
	}

	@Test
	public void dadoUmTipoDeComponenteDixComURIEUmRetanguloPosicionavelRetornaUmComponenteGedixComURIDeMesmoTipo() {
		
		assertTrue(Fabrica.obterComponenteGedixComURIDoTipo(IMAGEM, Fabrica.obterRetanguloPosicionavelNulo())
				instanceof Imagem);
		
		assertTrue(Fabrica.obterComponenteGedixComURIDoTipo(ENLACE, Fabrica.obterRetanguloPosicionavelNulo())
				instanceof Enlace);
		
		
	}

	@Test
	public void seDerUmTipoDeComponenteDixComGradeInválidoRetornaUmComponenteGedixNulo() {
		assertTrue(Fabrica.obterComponenteGedixComGradeDoTipo(ENLACE, Fabrica.obterRetanguloPosicionavelNulo())
				instanceof ComponenteGedixNulo);
		
	}

	@Test
	public void seDerUmTipoDeComponenteDixComListaDeOpçõesInválidoRetornaUmComponenteGedixNulo() {
		assertTrue(Fabrica.obterComponenteGedixComOpçõesDoTipo(IMAGEM, Fabrica.obterRetanguloPosicionavelNulo())
				instanceof ComponenteGedixNulo);
		
	}

	@Test
	public void seDerUmTipoDeComponenteDixComURIInválidoRetornaUmComponenteGedixNulo() {
		assertTrue(Fabrica.obterComponenteGedixComURIDoTipo(ETIQUETA, Fabrica.obterRetanguloPosicionavelNulo())
				instanceof ComponenteGedixNulo);
		
	}

	@Test
	public void podeRetornarUmaOpçãoNula() {
		assertEquals(new OpcaoNula(), 
				Fabrica.obterOpçãoNula());
		
	}

	@Test
	public void seDerUmNomeRetornaUmaOpçãoDaqueleMesmoNome() {
		assertEquals(new Opcao(nomeDaOpção), 
				Fabrica.obterOpçãoDeNome(nomeDaOpção));
	}

	@Test
	public void podeRetornarUmConjuntoDeOpções() {
		
		assertTrue(Fabrica.obterConjuntoDeOpções() 
				instanceof ConjuntoDeOpcoes);
	}

	@Test
	public void podeRetornarUmMockTransformávelEmXML() {
		assertTrue(Fabrica.obterMockTransformavelEmXML() 
				instanceof MockTransformavelEmXML);
		
	}

	@Test
	public void podeRetornarUmTransformadorParaXML() {
		assertTrue(Fabrica.obterTransformadorParaXML() 
				instanceof TransformadorParaXML);
		
	}

	@Test
	public void podeRetornarUmTransformadorParaXMLComURI() {
		assertTrue(Fabrica.obterTransformadorParaXMLComURI() 
				instanceof TransformadorParaXMLComURI);
		
	}

	@Test
	public void podeRetornarUmMockTransformávelEmXMLComURI() {
		assertTrue(Fabrica.obterMockTransformavelEmXMLComURI() 
				instanceof MockTransformavelEmXMLComURI);
		
	}
	
	@Test
	public void podeRetornarUmMockTransformávelEmXMLComGrade() {
		assertTrue(Fabrica.obterMockTransformavelEmXMLComGrade() 
				instanceof MockTransformavelEmXMLComGrade);
		
	}

	@Test
	public void podeRetornarUmTransformadorParaXMLComGrade() {
		assertTrue(Fabrica.obterTransformadorParaXMLComGrade() 
				instanceof TransformadorParaXMLComGrade);
		
	}

	@Test
	public void podeRetornarUmMockTransformávelEmXMLRotulavel() {
		assertTrue(Fabrica.obterMockTransformavelEmXMLRotulavel() 
				instanceof MockTransformavelEmXMLRotulavel);
		
	}

	@Test
	public void podeRetornarUmTransformadorParaXMLRotulavel() {
		assertTrue(Fabrica.obterTransformadorParaXMLRotulavel() 
				instanceof TransformadorParaXMLRotulavel);
		
	}

	@Test
	public void podeRetornarUmMockTransformávelEmXMLComOpções() {
		assertTrue(Fabrica.obterMockTransformavelEmXMLComOpções()
				instanceof MockTransformavelEmXMLComOpcoes);
		
	}

	@Test
	public void podeRetornarUmTransformadorParaXMLComOpções() {
		assertTrue(Fabrica.obterTransformadorParaXMLComOpções() 
				instanceof TransformadorParaXMLComOpcoes);
		
	}

	@Test
	public void podeRetornarUmTransformadorParaXMLRotulávelComURI() {
		assertTrue(Fabrica.obterTransformadorParaXMLRotulavelComURI() 
				instanceof TransformadorParaXMLRotulavelComURI);
		
	}

	@Test
	public void podeRetornarUmMockTransformávelEmXMLRotulávelComURI() {
		assertTrue(Fabrica.obterMockTransformavelEmXMLRotulavelComURI() 
				instanceof MockTransformavelEmXMLRotulavelComURI);
		
	}

	@Test
	public void dadoUmTipoDeComponenteDixRotulávelComURIEUmRetanguloPosicionavelRetornaUmComponenteGedixRotulávelComURIDeMesmoTipo() {
		assertTrue(Fabrica.obterComponenteGedixRotulávelComURI(ENLACE, Fabrica.obterRetanguloPosicionavelNulo()) 
				instanceof ComponenteGedixRotulavelComURI);
		
	}

	@Test
	public void seDerUmTipoDeComponenteDixRotulávelComURIInválidoRetornaUmComponenteGedixNulo() {
		assertTrue(Fabrica.obterComponenteGedixRotulávelComURI(ETIQUETA, Fabrica.obterRetanguloPosicionavelNulo()) 
				instanceof ComponenteGedixNulo);
		
	}
	
	
	
}
