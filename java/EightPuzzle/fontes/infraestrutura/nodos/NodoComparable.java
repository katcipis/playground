package infraestrutura.nodos;

public class NodoComparable<C extends Comparable<C>> {
	
	private C elemento ;
	private NodoComparable<C> proximo;

    public NodoComparable (C elemento){
    	this.elemento = elemento;
    	proximo = null;
    }

    public void atribuiElemento (C elemento){
    	this.elemento = elemento;
    }
    public void atribuiProximo (NodoComparable<C> nodo) {
    	proximo = nodo;
    }
    public C retornaElemento ( ) {
    	return elemento;
    }
    public NodoComparable<C> retornaProximo ( ){
    	return proximo;
    }

}
