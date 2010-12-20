package lista.listas.ordenadas;

import ine5384.excecoes.ExcecaoEstruturaVazia;
import ine5384.excecoes.ExcecaoPosicaoIlegal;
import ine5384.lineares.ListaClassificada;
import ine5384.pp.Iterador;
import ine5384.pp.Visitante;
import lista.iteradoresDaLista.IteradorDaListaOrdenada;

public abstract class ListaOrdenadaAbstrata<C extends Comparable<C>> implements
		ListaClassificada<C> {

	protected Integer numeroDeElementos;

	public ListaOrdenadaAbstrata() {
		numeroDeElementos = 0;
	}

	protected boolean posicaoIlegal(int posicao) {
		return (posicao > numeroDeElementos || posicao <= 0);
	}

	public boolean estaVazia() {

		return (numeroDeElementos == 0);
	}

	public int retorneTamanho() {

		return numeroDeElementos;
	}

	public Iterador<C> retorneIterador() {

		return new IteradorDaListaOrdenada<C>(this);
	}

	public void recebaVisitante(Visitante<C> visitante) {
		for (int cont = 1; (cont <= this.numeroDeElementos)
				|| visitante.satisfeito(); cont++)
			try {
				visitante.visite(retorneDaPosicao(cont));
			} catch (ExcecaoPosicaoIlegal e) {
				System.out.println(e.toString());
			} catch (ExcecaoEstruturaVazia e) {
				System.out.println(e.toString());
			}

	}
	
	@SuppressWarnings("unchecked")
	@Override
	public boolean equals(Object o){
		if(o instanceof ListaClassificada){
			ListaClassificada outraLista = (ListaClassificada) o;
			if(this.retorneTamanho() == outraLista.retorneTamanho()){
				Integer numeroDeElementos = this.retorneTamanho();
				for(int i = 1; i <= numeroDeElementos; i++){
					try {
						if(!this.retorneDaPosicao(i).equals(outraLista.retorneDaPosicao(i)))
							return false;
					} catch (ExcecaoEstruturaVazia e) {
						e.printStackTrace();
					} catch (ExcecaoPosicaoIlegal e) {
						e.printStackTrace();
					}
				}
				return true;
			}
			return false;
		}
		return false;
	}


}
