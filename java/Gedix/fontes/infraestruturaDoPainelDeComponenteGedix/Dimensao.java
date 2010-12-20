package infraestruturaDoPainelDeComponenteGedix;

public class Dimensao {
	
	private final int ALTURA;

	private final int LARGURA;

	public Dimensao(int altura, int largura) {
		ALTURA = (altura >= 0)?altura:0;
		LARGURA = (largura >= 0)?largura:0;
	}

	@Override
	public boolean equals(Object o) {
		if (o instanceof Dimensao) {
			Dimensao c = (Dimensao) o;
			return ((c.ALTURA == ALTURA) && 
					(c.LARGURA == LARGURA));
		}
		
		return false;

	}
	
	public int hashCode(){
		return Integer.valueOf(ALTURA+""+LARGURA);
	}

	public int obterAltura() {
		return ALTURA;
	}

	public int obterLargura() {
		return LARGURA;
	}
	

}
