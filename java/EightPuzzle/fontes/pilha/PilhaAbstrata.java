package pilha;

import ine5384.excecoes.ExcecaoEstruturaVazia;

public abstract class PilhaAbstrata<T> implements Pilha<T> {
	
	@SuppressWarnings("unchecked")
	@Override
    public boolean equals(Object o){
    	if(o instanceof Pilha){
    		Pilha<T> outraPilha = (Pilha<T>) o;
    		boolean naoEsvaziouAPilha = true;
    		do{
    			try {
					if(!this.desempilhe().equals(outraPilha.desempilhe()))
						
						return false;
					
				} catch (ExcecaoEstruturaVazia e) {
					if(this.estaVazia() && outraPilha.estaVazia())
						return true;
					return false;
				}
    		}while(naoEsvaziouAPilha);	
    		
    	}
    	
    	return false;
    }
	
	

}
