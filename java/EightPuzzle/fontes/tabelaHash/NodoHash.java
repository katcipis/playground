package tabelaHash;

public class NodoHash<C, V> {

	private V elemento ;
	private C chave ;
	private NodoHash<C,V> proximo;

    public NodoHash (C chave, V elemento){
    	this.elemento = elemento;
    	this.chave = chave;
    	proximo = null;
    }

    public void atribuiElemento (C chave, V elemento){
    	this.elemento = elemento;
    	this.chave = chave;
    }
    public void atribuiProximo (NodoHash<C, V> nodo) {
    	proximo = nodo;
    }
    public V retornaElemento () {
    	return elemento;
    }
    
    public C retornaChave () {
    	return chave;
    }
    
    public NodoHash<C, V> retornaProximo ( ){
    	return proximo;
    }
    
    public boolean possuiProximo(){
    	
    	return proximo != null;
    }
    
    public NodoHash<C, V> removeProximo(){
    	if(possuiProximo()){
    		NodoHash<C, V> retorna = proximo;
    		proximo = null;
    		return retorna;
    	}
    	return null;
    }
}
