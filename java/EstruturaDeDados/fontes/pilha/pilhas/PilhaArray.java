package pilha.pilhas;

import ine5384.excecoes.ExcecaoEstruturaCheia;
import ine5384.excecoes.ExcecaoEstruturaVazia;



public class PilhaArray<T> extends PilhaAbstrata<T> {

    private T elementos[];
    private Integer numeroDeElementos;
    
    @SuppressWarnings("unchecked")
    public PilhaArray(){
        elementos = (T[]) new Object[10];
        numeroDeElementos = 0;
    }
    
    @SuppressWarnings("unchecked")
    public PilhaArray(Integer tamanhoDaPilha){
        elementos = (T[]) new Object[tamanhoDaPilha];
        numeroDeElementos = 0;
    }
    
    public T desempilhe() throws ExcecaoEstruturaVazia {
    	
    	if(estaVazia())
        	throw new ExcecaoEstruturaVazia();
    	
    	T elementoRemovido = elementos[numeroDeElementos - 1];
        elementos[numeroDeElementos - 1] = null;
        numeroDeElementos--;
        return elementoRemovido;
    }

	public boolean estaVazia() {
		return numeroDeElementos == 0;
	}

    public void empilhe(T elemento) throws ExcecaoEstruturaCheia {
        if(estaCheia())
        	throw new ExcecaoEstruturaCheia();
        
        elementos[numeroDeElementos] = elemento;
        numeroDeElementos++;
        
    }

	public boolean estaCheia() {
		return numeroDeElementos == elementos.length;
	}

    public T retorneTopo() throws ExcecaoEstruturaVazia {
    	if(estaVazia())
        	throw new ExcecaoEstruturaVazia();
    	
        return elementos[numeroDeElementos - 1];
    }
    
    

   

}
