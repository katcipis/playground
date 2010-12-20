package infraestruturaDoPainelDeComponenteGedix;

public interface Retangulo {
	
    public int obterAltura();
	
	public int obterLargura();
	
	public Dimensao obterDimensão();
	
	public void definirLargura(int largura);
	
	public void definirAltura(int altura);	
	
	public void definirDimensão(Dimensao d);

}
