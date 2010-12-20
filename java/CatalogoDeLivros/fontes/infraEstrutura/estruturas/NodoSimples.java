package infraEstrutura.estruturas;

public class NodoSimples<T> {
	
	private T elemento ;
	private NodoSimples<T> proximo;

    public NodoSimples (T elemento){
    	this.elemento = elemento;
    	proximo = null;
    }

    public void atribuiElemento (T elemento){
    	this.elemento = elemento;
    }
    public void atribuiProximo (NodoSimples<T> nodo) {
    	proximo = nodo;
    }
    public T retornaElemento ( ) {
    	return elemento;
    }
    public NodoSimples<T> retornaProximo ( ){
    	return proximo;
    }
    


}
