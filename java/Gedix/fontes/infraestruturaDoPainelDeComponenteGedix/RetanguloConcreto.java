package infraestruturaDoPainelDeComponenteGedix;

public class RetanguloConcreto implements Retangulo{

	private Dimensao dimensão;


	public RetanguloConcreto(Dimensao d) {
		dimensão = d;
		
	}

	@Override
	public boolean equals(Object o) {
		if (o instanceof Retangulo) {
			Retangulo r = (Retangulo) o;
			return (r.obterDimensão().equals(dimensão));
		}
		return false;
	}

	public int obterAltura() {
		return dimensão.obterAltura();
	}

	public int obterLargura() {
		return dimensão.obterLargura();
	}

	public void definirLargura(int largura) {
		dimensão = 
			Fabrica.obterDimensão(dimensão.obterAltura(), largura);
	}

	public void definirAltura(int altura) {
		dimensão =
			Fabrica.obterDimensão(altura, dimensão.obterLargura());
	}
	
	public void definirDimensão(Dimensao d){
		dimensão = d;
	}
	
	public Dimensao obterDimensão(){
		return dimensão;
	}

}
