package infraestruturaDoTransformadorParaXML;

import edugraf.jadix.fachada.TiposDeComponentesDix;
import infraestruturaDoComponenteGedix.PosicoesDaLegenda;
import infraestruturaDoPainelDeComponenteGedix.Posicao;

public interface TransformavelEmXML {
	
	public String obterNome();
	
	public TiposDeComponentesDix obterTipo();
	
	public boolean verificarSeEstáVisível();
	
	public boolean verificarSeEstáHabilitado();
	
	public String obterLegenda();
	
	public PosicoesDaLegenda obterPosiçãoDaLegenda();
	
	public int obterProfundidade();
	
	public int obterAltura();
		
    public int obterLargura();
    
    public Posicao obterPosiçãoDeOrigem();

}
