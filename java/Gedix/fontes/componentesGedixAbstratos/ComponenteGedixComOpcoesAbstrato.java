package componentesGedixAbstratos;

import infraestruturaDoComponenteGedix.ComponenteGedixComOpcoes;
import infraestruturaDoComponenteGedix.ConjuntoDeOpcoes;
import infraestruturaDoComponenteGedix.Opcao;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import infraestruturaDoPainelDeComponenteGedix.RetanguloPosicionavel;

public abstract class ComponenteGedixComOpcoesAbstrato extends
		ComponenteGedixAbstrato implements ComponenteGedixComOpcoes{

	private ConjuntoDeOpcoes opções;

	public ComponenteGedixComOpcoesAbstrato(RetanguloPosicionavel r) {
		super(r);
		opções = Fabrica.obterConjuntoDeOpções();
	}

	public boolean adcionarOpção(Opcao novaOpção) {
		return opções.adcionar(novaOpção);
	}

	public void removerTodasAsOpções() {
		opções.removerTodos();
	}

	public Opcao obterOpção(int indiceDaOpção) {
		return opções.obterOpção(indiceDaOpção);
	}

	public int obterQuantidadeDeOpções() {
		return opções.obterTamanho();
	}
	
	public boolean possuiAOpção(Opcao o){
		return opções.possui(o);
	}

	public boolean removerOpção(int indiceDaOpção) {
		return opções.remover(indiceDaOpção);
	}

	public boolean possuiAOpçãoDeÍndice(int indice) {
		return opções.possui(indice);
	}
	
	public boolean removerOpção(Opcao o){
		return opções.remover(o);
	}

}
