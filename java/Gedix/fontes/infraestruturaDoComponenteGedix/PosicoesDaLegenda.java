package infraestruturaDoComponenteGedix;

public enum PosicoesDaLegenda {
	EM_CIMA("emCima"), NA_ESQUERDA("àEsquerda"),NULO("nulo");
	
	public final String nome;
	
	private PosicoesDaLegenda(String n){
		nome = n;
	}
}
