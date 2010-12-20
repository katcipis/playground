package infraestruturaDoPainelDeComponenteGedix;

public class RetanguloPosicionavelNulo implements RetanguloPosicionavel{
	
	
	public Posicao obterPosiçãoDeOrigem() {
		return Fabrica.obterPosicaoNula();
	}

	public void definirPosiçãoDeOrigem(Posicao p) {
		
	}

	public boolean verificarSeOcupaAPosição(Posicao p) {
	
		return false;
	}

	protected void definirPosiçõesQueOcupa() {

	}

	public int obterAltura() {
		return 0;
	}

	public int obterLargura() {
		return 0;
	}

	public void definirAltura(int altura) {

	}

	public void definirLargura(int largura) {
		
	}

	@Override
	public boolean equals(Object o){
		return o instanceof RetanguloPosicionavelNulo;
	}
	
	public void definirDimensão(Dimensao d){

	}
	
	public Dimensao obterDimensão(){
		return Fabrica.obterDimensão(0, 0);
	}

}
