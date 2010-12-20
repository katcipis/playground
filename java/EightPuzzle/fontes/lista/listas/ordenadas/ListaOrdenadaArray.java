package lista.listas.ordenadas;

import ine5384.excecoes.ExcecaoEstruturaCheia;
import ine5384.excecoes.ExcecaoEstruturaVazia;
import ine5384.excecoes.ExcecaoPosicaoIlegal;
import ine5384.lineares.ListaClassificada;

public class ListaOrdenadaArray<C extends Comparable<C>> extends ListaOrdenadaAbstrata<C>{
	
     private C[] elementos;
	

	@SuppressWarnings("unchecked")
	public ListaOrdenadaArray(int tamanhoDaLista) {

		elementos = (C[]) new Comparable[tamanhoDaLista];
		
	}

	@SuppressWarnings("unchecked")
	public ListaOrdenadaArray() {

		elementos = (C[]) new Comparable[10];
		
	}

	public void insira(C elemento) throws ExcecaoEstruturaCheia {

		if (estaCheia())
			throw new ExcecaoEstruturaCheia();

		if (estaVazia()) {
			elementos[0] = elemento;

		} else {

			boolean naoInseriu = true;
			for (int i = 0; i <= (numeroDeElementos - 1) && naoInseriu; i++) {
				if (elemento.compareTo(elementos[i]) <= 0) {
					naoInseriu = false;
					Integer posicao = i;
					for (int k = numeroDeElementos - 1; k >= posicao; k--) {
						elementos[k + 1] = elementos[k];
					}
					elementos[posicao] = elemento;
				}
			}

			if (naoInseriu) {
				elementos[numeroDeElementos] = elemento;

			}
		}
		numeroDeElementos++;

	}

	public boolean pertence(C elemento) {
		if (estaVazia())
			return false;

		for (int i = numeroDeElementos - 1; i >= 0; i--) {
			if (elementos[i] == elemento)
				return true;
		}

		return false;
	}

	public C removaDaPosicao(int posicao) throws ExcecaoEstruturaVazia,
			ExcecaoPosicaoIlegal {

		if (estaVazia())
			throw new ExcecaoEstruturaVazia();

		if (posicaoIlegal(posicao))
			throw new ExcecaoPosicaoIlegal(posicao);

		C seraRemovido = elementos[posicao - 1];

		for (int i = posicao - 1; i < numeroDeElementos - 1; i++) {
			elementos[i] = elementos[i + 1];
		}

		elementos[numeroDeElementos - 1] = null;
		numeroDeElementos--;
		return seraRemovido;
	}

	public C removaDoFim() throws ExcecaoEstruturaVazia {
		if (estaVazia())
			throw new ExcecaoEstruturaVazia();

		C elementoRemovido = elementos[numeroDeElementos - 1];
		elementos[numeroDeElementos - 1] = null;
		numeroDeElementos--;
		return elementoRemovido;
	}

	public C removaDoInicio() throws ExcecaoEstruturaVazia {
		if (estaVazia())
			throw new ExcecaoEstruturaVazia();

		C elementoRemovido = elementos[0];

		try {
			removaDaPosicao(1);
		} catch (ExcecaoPosicaoIlegal e) {
			e.printStackTrace();
		}

		return elementoRemovido;
	}

	public C retorneDaPosicao(int posicao) throws ExcecaoEstruturaVazia,
			ExcecaoPosicaoIlegal {

		if (estaVazia())
			throw new ExcecaoEstruturaVazia();
		if (posicaoIlegal(posicao))
			throw new ExcecaoPosicaoIlegal(posicao);

		return elementos[posicao - 1];
	}


	public ListaClassificada<C> temIguais(C elemento) {
		ListaClassificada<C> listaDeIguais = new ListaOrdenadaArray<C>(
				elementos.length);

		for (int i = 0; i < numeroDeElementos; i++) {
			if (elementos[i].equals(elemento)) {
				try {
					listaDeIguais.insira(elementos[i]);
				} catch (ExcecaoEstruturaCheia e) {
					e.printStackTrace();
				}
			}
		}
		return listaDeIguais;
	}

	public C temIgual(C elemento) {
		for (int i = 0; i < numeroDeElementos; i++) {
			if (elementos[i].equals(elemento))
				return elementos[i];
		}
		return null;
	}


	public C retorneDoFim() throws ExcecaoEstruturaVazia {
		if (estaVazia())

			throw new ExcecaoEstruturaVazia();

		return elementos[numeroDeElementos - 1];
	}

	public C retorneDoInicio() throws ExcecaoEstruturaVazia {
		if (estaVazia())
			throw new ExcecaoEstruturaVazia();

		return elementos[0];
	}

	public boolean estaCheia() {
		return numeroDeElementos == elementos.length;
	}


	public void esvazie() {
		int i = 0;
		while ((elementos[i] != null)) {
			elementos[i] = null;
			i++;
		}

		numeroDeElementos = 0;

	}


}
