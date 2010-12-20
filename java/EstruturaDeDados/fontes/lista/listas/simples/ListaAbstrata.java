package lista.listas.simples;

import lista.iteradoresDaLista.IteradorDaLista;
import ine5384.excecoes.ExcecaoEstruturaVazia;
import ine5384.excecoes.ExcecaoPosicaoIlegal;
import ine5384.lineares.Lista;
import ine5384.pp.Iterador;
import ine5384.pp.Visitante;

public abstract class ListaAbstrata<T> implements Lista<T> {

	protected Integer numeroDeElementos;

	public ListaAbstrata() {
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

	public Iterador<T> retorneIterador() {

		return new IteradorDaLista<T>(this);
	}
	
	public void recebaVisitante(Visitante<T> visitante) {
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
		if(o instanceof Lista){
			Lista outraLista = (Lista) o;
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
