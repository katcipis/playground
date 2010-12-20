package infraestruturaDoPainelDeComponenteGedix;

import infraestruturaDoComponenteGedix.ComponenteGedix;

import java.util.ArrayList;
import java.util.List;
import java.util.ListIterator;

public class PainelDeComponenteGedix {
	
	private final List<ComponenteGedix> listaDePosicionáveis;

    public PainelDeComponenteGedix() {
		listaDePosicionáveis = new ArrayList<ComponenteGedix>();
		
	}

	public  void adcionar(ComponenteGedix componente) {
		componente.definirPosiçãoDeOrigem(new Posicao(0, 0));
		listaDePosicionáveis.add(componente);
	}

	public  void adcionar(ComponenteGedix componente, Posicao posicao) {
		componente.definirPosiçãoDeOrigem(posicao);
		listaDePosicionáveis.add(componente);
	}

	public  boolean mover(ComponenteGedix componente, Posicao posicao) {
		if (listaDePosicionáveis.contains(componente)) {
			componente.definirPosiçãoDeOrigem(posicao);
			return true;
		}
		return false;

	}

	public boolean verificarSeExisteAlguemNaPosição(Posicao p) {
		ListIterator<ComponenteGedix> iteradorDaLista;
		boolean existeAlguemNaPosição = false;

		for (iteradorDaLista = listaDePosicionáveis.listIterator(); iteradorDaLista
				.hasNext();) {
			if (iteradorDaLista.next().verificarSeOcupaAPosição(p))
				existeAlguemNaPosição = true;
		}

		return existeAlguemNaPosição;

	}

	public  ComponenteGedix obterComponenteQueSeEncontraNaPosição(Posicao p) {
		ListIterator<ComponenteGedix> iteradorDaLista;
	

		if (verificarSeExisteAlguemNaPosição(p)) {

			for (iteradorDaLista = listaDePosicionáveis
					.listIterator(listaDePosicionáveis.size()); iteradorDaLista
					.hasPrevious();) {

				ComponenteGedix proximoDaLista = iteradorDaLista.previous();
				if (proximoDaLista.verificarSeOcupaAPosição(p))
					return proximoDaLista;

			}

		}

		return Fabrica.obterComponenteGedixNulo();
	}

	public boolean remover(ComponenteGedix componente) {

		return listaDePosicionáveis.remove(componente);

	}

	public int obterQuantidadeDeComponentesPosicionados() {
		return listaDePosicionáveis.size();
	}

	public void removerTodos() {
		listaDePosicionáveis.removeAll(listaDePosicionáveis);
	}

}
