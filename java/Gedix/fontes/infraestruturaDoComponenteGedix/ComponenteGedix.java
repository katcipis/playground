package infraestruturaDoComponenteGedix;


import edugraf.jadix.fachada.TiposDeComponentesDix;
import infraestruturaDoPainelDeComponenteGedix.RetanguloPosicionavel;
import infraestruturaDoTransformadorParaXML.TransformavelEmXML;

public interface ComponenteGedix extends RetanguloPosicionavel, TransformavelEmXML{
	
	public TiposDeComponentesDix obterTipo();
	
	public String obterNome();
	
	public void alterarNome(String novoNome);
	
	public void tornarVisível();
	
	public void tornarInvisível();
	
	public boolean verificarSeEstáVisível();
	
	public void habilitar();
	
	public void desabilitar();
	
	public boolean verificarSeEstáHabilitado();
	
	public void alterarLegenda(String novaLegenda);
	
	public String obterLegenda();
	
	public void definirPosiçãoDaLegenda(PosicoesDaLegenda novaPosiçãoDaLegenda);
	
	public PosicoesDaLegenda obterPosiçãoDaLegenda();
	
	public void definirProfundidade(int novaProfundidade);
	
	public int obterProfundidade();
	
}
