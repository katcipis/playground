package infraestrutura.nodos;

public class NodoB<C extends Comparable, K> implements Comparable<NodoB> {

	private final C chave;

	private K esquerda;

	private K direita;

	public NodoB(C chave) {
		this.chave = chave;
	}

	public void definirEsquerda(K esquerda){
		this.esquerda = esquerda;
	}
	
	public void definirDireita(K direita){
		this.direita = direita;
	}
	
	public boolean possuiEsquerda() {
		return esquerda != null;
	}

	public boolean possuiDireita() {
		return direita != null;
	}

	public K retornaDireita() {
		return direita;
	}

	public K retornaEsquerda() {
		return esquerda;
	}
	
	public C retornaChave(){
		return this.chave;
	}

	@SuppressWarnings("unchecked")
	public int compareTo(NodoB object) {

		return this.chave.compareTo(object.chave);
	}
	
	@SuppressWarnings("unchecked")
	@Override
	public boolean equals(Object o){
		if(o instanceof NodoB){
			NodoB outroNodo = (NodoB) o;
			return (this.chave.compareTo(outroNodo.chave) == 0);
		}
		return false;
	}

}
