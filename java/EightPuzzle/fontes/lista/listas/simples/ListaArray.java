package lista.listas.simples;

import ine5384.excecoes.ExcecaoEstruturaCheia;
import ine5384.excecoes.ExcecaoEstruturaVazia;
import ine5384.excecoes.ExcecaoPosicaoIlegal;
import ine5384.lineares.Lista;

public class ListaArray<T> extends ListaAbstrata<T> {

	private T[] elementos;

	@SuppressWarnings("unchecked")
	public ListaArray(int tamanhoDaLista) {

		elementos = (T[]) new Object[tamanhoDaLista];

	}

	@SuppressWarnings("unchecked")
	public ListaArray() {
		elementos = (T[]) new Object[10];

	}

	public void insiraNaPosicao(T elemento, int posicao)
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal {

		if (posicao > numeroDeElementos + 1 || posicao <= 0)
			throw new ExcecaoPosicaoIlegal(posicao);

		if (estaCheia())
			throw new ExcecaoEstruturaCheia();

		for (int i = numeroDeElementos; i > posicao - 1; i--) {
			elementos[i] = elementos[i - 1];
		}

		elementos[posicao - 1] = elemento;
		numeroDeElementos++;

	}

	public void insiraNoFim(T elemento) throws ExcecaoEstruturaCheia {

		if (estaCheia())
			throw new ExcecaoEstruturaCheia();

		elementos[numeroDeElementos] = elemento;

		numeroDeElementos++;

	}

	public void insiraNoInicio(T elemento) throws ExcecaoEstruturaCheia {
		if (estaCheia())
			throw new ExcecaoEstruturaCheia();

		for (int i = numeroDeElementos; i > 0; i--) {
			elementos[i] = elementos[i - 1];
		}

		elementos[0] = elemento;
		numeroDeElementos++;

	}

	public boolean pertence(T elemento) {

		if (estaVazia())
			return false;

		for (int i = numeroDeElementos - 1; i >= 0; i--) {
			if (elementos[i] == elemento)
				return true;
		}

		return false;
	}

	public T removaDaPosicao(int posicao) throws ExcecaoEstruturaVazia,
			ExcecaoPosicaoIlegal {

		if (estaVazia())
			throw new ExcecaoEstruturaVazia();

		if (posicaoNaoEValida(posicao))
			throw new ExcecaoPosicaoIlegal(posicao);

		T seraRemovido = elementos[posicao - 1];

		for (int i = posicao - 1; i < numeroDeElementos - 1; i++) {
			elementos[i] = elementos[i + 1];
		}

		elementos[numeroDeElementos - 1] = null;
		numeroDeElementos--;
		return seraRemovido;
	}

	public T removaDoFim() throws ExcecaoEstruturaVazia {
		if (estaVazia())
			throw new ExcecaoEstruturaVazia();

		T elementoRemovido = elementos[numeroDeElementos - 1];
		elementos[numeroDeElementos - 1] = null;
		numeroDeElementos--;
		return elementoRemovido;
	}

	public T removaDoInicio() throws ExcecaoEstruturaVazia {
		if (estaVazia())
			throw new ExcecaoEstruturaVazia();

		T elementoRemovido = elementos[0];

		try {
			removaDaPosicao(1);
		} catch (ExcecaoPosicaoIlegal e) {
		}

		return elementoRemovido;
	}

	public Lista<T> removaIguais(T elemento) throws ExcecaoEstruturaVazia {

		if (estaVazia())
			throw new ExcecaoEstruturaVazia();

		Lista<T> listaQueSeraRetornada = temIguais(elemento);

		for (int i = numeroDeElementos - 1; i >= 0; i--) {

			if (elementos[i].equals(elemento)) {

				try {
					removaDaPosicao(i + 1);
				} catch (ExcecaoPosicaoIlegal e) {
					e.printStackTrace();
				}
			}

		}

		return listaQueSeraRetornada;
	}

	public T removaIgual(T elemento) throws ExcecaoEstruturaVazia {

		if (estaVazia())
			throw new ExcecaoEstruturaVazia();

		T elementoQueSeraRetornado;

		for (int i = 0; i < numeroDeElementos; i++) {

			if (elementos[i].equals(elemento)) {

				elementoQueSeraRetornado = elementos[i];
				try {
					removaDaPosicao(i + 1);
				} catch (ExcecaoPosicaoIlegal e) {
					e.printStackTrace();
				}

				return elementoQueSeraRetornado;
			}
		}
		return null;
	}

	public T retorneDaPosicao(int posicao) throws ExcecaoEstruturaVazia,
			ExcecaoPosicaoIlegal {

		if (estaVazia())
			throw new ExcecaoEstruturaVazia();
		if (posicaoNaoEValida(posicao))
			throw new ExcecaoPosicaoIlegal(posicao);

		return elementos[posicao - 1];
	}

	private boolean posicaoNaoEValida(int posicao) {
		return posicao > numeroDeElementos || posicao <= 0;
	}

	public void substituaDaPosicao(T elemento, int posicao)
			throws ExcecaoEstruturaVazia, ExcecaoPosicaoIlegal {

		if (estaVazia())
			throw new ExcecaoEstruturaVazia();

		if (posicaoNaoEValida(posicao))
			throw new ExcecaoPosicaoIlegal(posicao);

		elementos[posicao - 1] = elemento;

	}

	public void substituaDoFim(T elemento) throws ExcecaoEstruturaVazia {
		if (estaVazia())
			throw new ExcecaoEstruturaVazia();
		elementos[numeroDeElementos - 1] = elemento;
	}

	public void substituaDoInicio(T elemento) throws ExcecaoEstruturaVazia {
		if (estaVazia())
			throw new ExcecaoEstruturaVazia();
		elementos[0] = elemento;
	}

	public Lista<T> temIguais(T elemento) {
		Lista<T> listaDeIguais = new ListaArray<T>(elementos.length);

		for (int i = 0; i < numeroDeElementos; i++) {
			if (elementos[i].equals(elemento)) {
				try {
					listaDeIguais.insiraNoFim(elementos[i]);
				} catch (ExcecaoEstruturaCheia e) {
					e.printStackTrace();
				}
			}
		}
		return listaDeIguais;
	}

	public T temIgual(T elemento) {

		for (int i = 0; i < numeroDeElementos; i++) {
			if (elementos[i].equals(elemento))
				return elementos[i];
		}
		return null;
	}

	public T retorneDoFim() throws ExcecaoEstruturaVazia {
		if (estaVazia())

			throw new ExcecaoEstruturaVazia();

		return elementos[numeroDeElementos - 1];

	}

	public T retorneDoInicio() throws ExcecaoEstruturaVazia {
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