package infraestruturaDoPainelDeComponenteGedix;

public class PosicaoNula extends Posicao{
	
	
	public PosicaoNula(){
		super(0,0);
	}
	
	@Override
	public boolean equals(Object o) {
			return (o instanceof PosicaoNula);
	}
	
	@Override
	public int hashCode() {
		return 0;
	}
}
