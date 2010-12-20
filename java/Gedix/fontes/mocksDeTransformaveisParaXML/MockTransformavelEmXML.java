package mocksDeTransformaveisParaXML;

import edugraf.jadix.fachada.TiposDeComponentesDix;
import infraestruturaDoComponenteGedix.PosicoesDaLegenda;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import infraestruturaDoPainelDeComponenteGedix.Posicao;
import infraestruturaDoTransformadorParaXML.TransformavelEmXML;


public class MockTransformavelEmXML implements TransformavelEmXML{

	private int altura, largura, profundidade;
	private String nome, legenda;
	private PosicoesDaLegenda posiçãoDaLegenda;
	private Posicao posição;
	private boolean habilitado, visivel;
	private TiposDeComponentesDix tipo;
	
	public MockTransformavelEmXML(){
		altura = 0;
		largura = 0;
		profundidade = 0;
		nome = "Mock";
		legenda = "Mock";
		posiçãoDaLegenda = PosicoesDaLegenda.EM_CIMA;
		posição = Fabrica.obterPosição(0, 0);
		habilitado = false;
		visivel = false;
		tipo = TiposDeComponentesDix.BOTÃO;
	}
	
	public int obterAltura() {
		
		return altura;
	}

	public int obterLargura() {
	
		return largura;
	}

	public PosicoesDaLegenda obterPosiçãoDaLegenda() {
		
		return posiçãoDaLegenda;
	}

	public String obterNome() {
		
		return nome;
	}

	public Posicao obterPosiçãoDeOrigem() {
		
		return posição;
	}

	public int obterProfundidade() {
	
		return profundidade;
	}

	public String obterLegenda() {
		
		return legenda;
	}

	public boolean verificarSeEstáHabilitado() {
		
		return habilitado;
	}

	public boolean verificarSeEstáVisível() {
		
		return visivel;
	}
	
	public TiposDeComponentesDix obterTipo(){
		return tipo;
	}
	
	public void alterarAtributos(){
		altura = 10;
		largura = 10;
		profundidade = 10;
		nome = "Mock2";
		legenda = "Mock2";
		posiçãoDaLegenda = PosicoesDaLegenda.NA_ESQUERDA;
		posição = Fabrica.obterPosição(2, 3);
		habilitado = true;
		visivel = true;
		tipo = TiposDeComponentesDix.BOTÕES_DE_RÁDIO;
	}

}
