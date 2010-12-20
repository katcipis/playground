package infraestruturaDoPainelDeComponenteGedix;

public class Posicao {

	private final int DISTANCIA_DA_ESQUERDA;

	private final int DISTANCIA_DO_TOPO;

	public Posicao(int esquerda, int topo) {
		DISTANCIA_DA_ESQUERDA = esquerda;
		DISTANCIA_DO_TOPO = topo;
	}

	@Override
	public boolean equals(Object o) {
		if (o instanceof Posicao) {
			Posicao c = (Posicao) o;
			return ((c.DISTANCIA_DA_ESQUERDA == 
				DISTANCIA_DA_ESQUERDA) && 
				(c.DISTANCIA_DO_TOPO == DISTANCIA_DO_TOPO));
		}

		return false;

	}

	public int hashCode() {
		return Integer.valueOf(DISTANCIA_DA_ESQUERDA + "" 
				+ DISTANCIA_DO_TOPO);
	}

	public int obterDistânciaDaEsquerda() {
		return DISTANCIA_DA_ESQUERDA;
	}

	public int obterDistânciaDoTopo() {
		return DISTANCIA_DO_TOPO;
	}

}
