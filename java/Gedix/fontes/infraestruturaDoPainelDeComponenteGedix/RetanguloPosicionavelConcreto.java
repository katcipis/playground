package infraestruturaDoPainelDeComponenteGedix;

public class RetanguloPosicionavelConcreto implements RetanguloPosicionavel {

	private final Retangulo RETANGULO;
	private Posicao posiçãoDeOrigem;
    private final ListaDePosicoes posiçõesQueOcupo;
   
	public RetanguloPosicionavelConcreto(Retangulo d) {
	
		posiçãoDeOrigem = Fabrica.obterPosição(0, 0);
		posiçõesQueOcupo = new ListaDePosicoes();
		RETANGULO = d;
	}

	public Posicao obterPosiçãoDeOrigem() {
		return posiçãoDeOrigem;
	}

	public void definirPosiçãoDeOrigem(Posicao p) {
		posiçãoDeOrigem = p;
	}

	public boolean verificarSeOcupaAPosição(Posicao p) {
		definirPosiçõesQueOcupa();
		return posiçõesQueOcupo.verificarSeContêmEssaPosição(p);
	}

	private void definirPosiçõesQueOcupa() {
		
		posiçõesQueOcupo.esvaziar();
		
		int distanciaDaEsquerda = posiçãoDeOrigem.obterDistânciaDaEsquerda();
		int distanciaDoTopo = posiçãoDeOrigem.obterDistânciaDoTopo();
		int limiteDaEsquerda = obterLargura() + distanciaDaEsquerda;
		int limiteDoTopo = obterAltura() + distanciaDoTopo;

		for (int esquerda = limiteDaEsquerda; 
		 esquerda >= distanciaDaEsquerda; esquerda--) {
			
			for (int topo = limiteDoTopo; topo >= distanciaDoTopo; topo--) {
				posiçõesQueOcupo.adcionar
				(Fabrica.obterPosição(esquerda,topo));
			}
		}

	}

	public int obterAltura() {
		return RETANGULO.obterAltura();
	}

	public int obterLargura() {
		return RETANGULO.obterLargura();
	}

	public void definirAltura(int altura) {
		RETANGULO.definirAltura(altura);
	}

	public void definirLargura(int largura) {
		RETANGULO.definirLargura(largura);
	}

	public void definirDimensão(Dimensao d){
		RETANGULO.definirDimensão(d);
	}
	
	public Dimensao obterDimensão(){
		return RETANGULO.obterDimensão();
	}
	

}
