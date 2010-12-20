package infraestruturaDoPainelDeComponenteGedix;

public interface Posicionavel {

	public Posicao obterPosiçãoDeOrigem();
	public void definirPosiçãoDeOrigem(Posicao p);
	public boolean verificarSeOcupaAPosição(Posicao p);

	
}
