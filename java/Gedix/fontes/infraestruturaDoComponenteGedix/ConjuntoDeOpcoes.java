package infraestruturaDoComponenteGedix;

import infraestruturaDoPainelDeComponenteGedix.Fabrica;

import java.util.LinkedHashSet;
import java.util.Set;

public class ConjuntoDeOpcoes {

	private final Set<Opcao> opções;
	private int índiceDaPrimeiraOpção;

	public ConjuntoDeOpcoes() {
		opções = new LinkedHashSet<Opcao>();
		índiceDaPrimeiraOpção = 1;
	}

	public void removerTodos() {
		opções.clear();
	}

	public boolean estáVazio() {
		return opções.isEmpty();
	}

	public boolean adcionar(Opcao o) {
		return opções.add(o);
	}

	public Opcao obterOpção(int índiceDaOpção) {
		Opcao[] arrayDeOpções = opções.toArray(new Opcao[opções.size()]);
		
		if(possui(índiceDaOpção))
		    return arrayDeOpções[(índiceDaOpção - 1)];
		
		return Fabrica.obterOpçãoNula();
	}

	public boolean possui(int índice) {
		return  !opções.isEmpty() && índice >= índiceDaPrimeiraOpção &&
				índice <= opções.size();
	}
	
	public boolean possui(Opcao o){
		return opções.contains(o);
	}
	
	public boolean remover(int índice){
		return opções.remove(obterOpção(índice));
	}
	
	public boolean remover(Opcao o){
		return opções.remove(o);
	}
	
	public int obterTamanho(){
		return opções.size();
	}

}
