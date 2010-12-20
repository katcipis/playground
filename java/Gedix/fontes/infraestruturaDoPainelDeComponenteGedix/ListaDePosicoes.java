package infraestruturaDoPainelDeComponenteGedix;

import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

public class ListaDePosicoes {
	
	private final Set<Posicao> posiçõesQueContenho;
	
	public ListaDePosicoes(){
		posiçõesQueContenho = new HashSet<Posicao>();
	}
	
	public boolean adcionar(Posicao c){
		return posiçõesQueContenho.add(c);
	}
	
	public int obterQuantidadeDePosições(){
		return posiçõesQueContenho.size();
	}
	
	public boolean verificarSeContêmEssaPosição(Posicao c){
		return posiçõesQueContenho.contains(c);
	}
	
	public Iterator<Posicao> obterIteradorDaLista(){
	     return posiçõesQueContenho.iterator();
	}
	
	public void esvaziar(){
		posiçõesQueContenho.clear();
	}
	
	public boolean verificarSeEstáVazia(){
		return posiçõesQueContenho.isEmpty();
	}

}
