package infraestruturaDoPainelDeComponenteGedix;

import infraestruturaDoComponenteGedix.ComponenteGedix;
import infraestruturaDoComponenteGedix.ComponenteGedixComGrade;
import infraestruturaDoComponenteGedix.ComponenteGedixComOpcoes;
import infraestruturaDoComponenteGedix.ComponenteGedixComURI;
import infraestruturaDoComponenteGedix.ComponenteGedixRotulavel;
import infraestruturaDoComponenteGedix.ComponenteGedixRotulavelComURI;
import infraestruturaDoComponenteGedix.ConjuntoDeOpcoes;
import infraestruturaDoComponenteGedix.Opcao;
import infraestruturaDoComponenteGedix.OpcaoNula;
import infraestruturaDoTransformadorParaXML.TransformadorParaXML;
import infraestruturaDoTransformadorParaXML.TransformadorParaXMLComGrade;
import infraestruturaDoTransformadorParaXML.TransformadorParaXMLComOpcoes;
import infraestruturaDoTransformadorParaXML.TransformadorParaXMLComURI;
import infraestruturaDoTransformadorParaXML.TransformadorParaXMLConcreto;
import infraestruturaDoTransformadorParaXML.TransformadorParaXMLComGradeConcreto;
import infraestruturaDoTransformadorParaXML.TransformadorParaXMLComOpcoesConcreto;
import infraestruturaDoTransformadorParaXML.TransformadorParaXMLComURIConcreto;
import infraestruturaDoTransformadorParaXML.TransformadorParaXMLRotulavel;
import infraestruturaDoTransformadorParaXML.TransformadorParaXMLRotulavelComURI;
import infraestruturaDoTransformadorParaXML.TransformadorParaXMLRotulavelComURIConcreto;
import infraestruturaDoTransformadorParaXML.TransformadorParaXMLRotulavelConcreto;
import mocksDeTransformaveisParaXML.MockTransformavelEmXML;
import mocksDeTransformaveisParaXML.MockTransformavelEmXMLComGrade;
import mocksDeTransformaveisParaXML.MockTransformavelEmXMLComOpcoes;
import mocksDeTransformaveisParaXML.MockTransformavelEmXMLComURI;
import mocksDeTransformaveisParaXML.MockTransformavelEmXMLRotulavel;
import mocksDeTransformaveisParaXML.MockTransformavelEmXMLRotulavelComURI;
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
import edugraf.jadix.fachada.TiposDeComponentesDix;

public class Fabrica {

	public static Posicao obterPosição(int esquerda, int topo) {
		return new Posicao(esquerda, topo);
	}

	public static Dimensao obterDimensão(int altura, int largura) {
		return new Dimensao(altura, largura);
	}

	public static Retangulo obterRetangulo(Dimensao d) {
		return new RetanguloConcreto(d);
	}

	public static RetanguloPosicionavel obterRetanguloPosicionavel(Retangulo r) {
		return new RetanguloPosicionavelConcreto(r);
	}

	public static RetanguloPosicionavel obterRetanguloPosicionavelNulo() {
		return new RetanguloPosicionavelNulo();
	}

	public static Posicao obterPosicaoNula() {
		return new PosicaoNula();
	}

	public static ComponenteGedixNulo obterComponenteGedixNulo() {
		return new ComponenteGedixNulo();
	}

	public static ComponenteGedix obterComponenteGedixDoTipo(TiposDeComponentesDix tipo,
			RetanguloPosicionavel rp) {
	
		switch (tipo) {

		case BOTÃO:
			return new Botao(rp);
		case ENLACE:
			return new Enlace(rp);
		case ETIQUETA:
			return new Etiqueta(rp);
		case CAMPO_DE_TEXTO:
			return new CampoDeTexto(rp);
		case CAIXA_DE_ESCOLHA:
			return new CaixaDeEscolha(rp);
		case BOTÕES_DE_RÁDIO:
			return new BotoesDeRadio(rp);
		case GRADE:
			return new Grade(rp);
		case IMAGEM:
			return new Imagem(rp);
		case LISTA_DE_ESCOLHA:
			return new ListaDeEscolha(rp);
		case ÁREA_DE_TEXTO:
			return new AreaDeTexto(rp);
		case ÁREA_SENSÍVEL:
			return new AreaSensivel(rp);

		default:
			return obterComponenteGedixNulo();
		}
	}

	public static ComponenteGedixRotulavel obterComponenteGedixRotulavelDoTipo(
			TiposDeComponentesDix tipo, RetanguloPosicionavel rp) {

		switch (tipo) {

		case BOTÃO:
			return new Botao(rp);
		case ENLACE:
			return new Enlace(rp);
		case ETIQUETA:
			return new Etiqueta(rp);
		case CAMPO_DE_TEXTO:
			return new CampoDeTexto(rp);
		case ÁREA_DE_TEXTO:
			return new AreaDeTexto(rp);

		default:
			return obterComponenteGedixNulo();
		}
	}

	public static ComponenteGedixComURI obterComponenteGedixComURIDoTipo(
			TiposDeComponentesDix tipo, RetanguloPosicionavel rp) {
	
		switch (tipo) {

		case ENLACE:
			return new Enlace(rp);

		case IMAGEM:
			return new Imagem(rp);

		default:
			return obterComponenteGedixNulo();
		}
	}
	
	public static ComponenteGedixComOpcoes obterComponenteGedixComOpçõesDoTipo(
			TiposDeComponentesDix tipo, RetanguloPosicionavel rp) {
		
		switch (tipo) {

		case LISTA_DE_ESCOLHA:
			return new ListaDeEscolha(rp);
		case CAIXA_DE_ESCOLHA:
			return new CaixaDeEscolha(rp);
		case BOTÕES_DE_RÁDIO:
			return new BotoesDeRadio(rp);

		default:
			return obterComponenteGedixNulo();
		}
	}
	
	public static ComponenteGedixComGrade obterComponenteGedixComGradeDoTipo(
			TiposDeComponentesDix tipo, RetanguloPosicionavel rp) {
		
		switch (tipo) {

		case GRADE:
			return new Grade(rp);

		default:
			return obterComponenteGedixNulo();
		}
	}

	public static Opcao obterOpçãoDeNome(String nome){
		return new Opcao(nome);
	}
	
	public static Opcao obterOpçãoNula(){
		return new OpcaoNula();
	}
	
	public static ConjuntoDeOpcoes obterConjuntoDeOpções(){
		return new ConjuntoDeOpcoes();
	}
	
	public static MockTransformavelEmXML obterMockTransformavelEmXML(){
		return new MockTransformavelEmXML();
	}
	
	public static TransformadorParaXML obterTransformadorParaXML(){
		return new TransformadorParaXMLConcreto();
	}
	
	public static TransformadorParaXMLComURI obterTransformadorParaXMLComURI(){
		return new TransformadorParaXMLComURIConcreto();
	}
	
	public static MockTransformavelEmXMLComURI obterMockTransformavelEmXMLComURI(){
		return new MockTransformavelEmXMLComURI();
	}
	
	public static MockTransformavelEmXMLComGrade obterMockTransformavelEmXMLComGrade(){
		return new MockTransformavelEmXMLComGrade();
	}
	
	public static TransformadorParaXMLComGrade obterTransformadorParaXMLComGrade(){
		return new TransformadorParaXMLComGradeConcreto();
	}
	
	public static MockTransformavelEmXMLRotulavel obterMockTransformavelEmXMLRotulavel(){
		return new MockTransformavelEmXMLRotulavel();
	}
	
	public static TransformadorParaXMLRotulavel obterTransformadorParaXMLRotulavel(){
		return new TransformadorParaXMLRotulavelConcreto();
	}
	
	public static TransformadorParaXMLComOpcoes obterTransformadorParaXMLComOpções(){
		return new TransformadorParaXMLComOpcoesConcreto();
	}
	
	public static MockTransformavelEmXMLComOpcoes obterMockTransformavelEmXMLComOpções(){
		return new MockTransformavelEmXMLComOpcoes();
	}
	
	public static TransformadorParaXMLRotulavelComURI obterTransformadorParaXMLRotulavelComURI(){
		return new TransformadorParaXMLRotulavelComURIConcreto();
	}
	
	public static MockTransformavelEmXMLRotulavelComURI obterMockTransformavelEmXMLRotulavelComURI(){
		return new MockTransformavelEmXMLRotulavelComURI();
	}
	
	public static ComponenteGedixRotulavelComURI obterComponenteGedixRotulávelComURI(
			TiposDeComponentesDix tipo, RetanguloPosicionavel rp) {
		
		switch (tipo) {

		case ENLACE:
			return new Enlace(rp);

		default:
			return obterComponenteGedixNulo();
		}
	}
	
}
