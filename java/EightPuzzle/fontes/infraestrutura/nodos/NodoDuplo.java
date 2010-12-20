package infraestrutura.nodos;

public class NodoDuplo<T> {
	
	private T elemento ;
	private NodoDuplo<T> proximo, anterior;

    public NodoDuplo (T elemento){
    	this.elemento = elemento;
    	proximo = null;
    	anterior = null;
    }

    public void atribuiElemento (T elemento){
    	this.elemento = elemento;
    }
    public void atribuiProximo (NodoDuplo<T> nodo) {
    	proximo = nodo;
    }
    
    public void atribuiAnterior (NodoDuplo<T> nodo) {
    	anterior = nodo;
    }
    
    public T retornaElemento ( ) {
    	return elemento;
    }
    
    public NodoDuplo<T> retornaProximo ( ){
    	return proximo;
    }
    
    public NodoDuplo<T> retornaAnterior ( ){
    	return anterior;
    }

}
