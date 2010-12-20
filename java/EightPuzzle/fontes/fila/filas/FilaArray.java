package fila.filas;

import ine5384.excecoes.ExcecaoEstruturaCheia;
import ine5384.excecoes.ExcecaoEstruturaVazia;

public class FilaArray<T> extends FilaAbstrata<T> {

	private T[] elementos;

	@SuppressWarnings("unchecked")
	public FilaArray() {

		elementos = (T[]) new Object[10];
	}

	@SuppressWarnings("unchecked")
	public FilaArray(Integer tamanhoDaLista) {

		elementos = (T[]) new Object[tamanhoDaLista];
	}

	public T remove() throws ExcecaoEstruturaVazia {
		if (estaVazia())
			throw new ExcecaoEstruturaVazia();
		T elementoRemovido = elementos[0];
		for (int i = 0; i < numeroDeElementos - 1; i++) {
			elementos[i] = elementos[i + 1];
		}
		elementos[numeroDeElementos - 1] = null;
		numeroDeElementos--;
		return elementoRemovido;
	}

	public void insere(T elemento) throws ExcecaoEstruturaCheia {
		if (estaCheia())
			throw new ExcecaoEstruturaCheia();

		elementos[numeroDeElementos] = elemento;
		numeroDeElementos++;

	}

	public boolean estaCheia() {

		return numeroDeElementos == elementos.length;
	}

	

	public T retorneInicio() throws ExcecaoEstruturaVazia {
		if (estaVazia())
			throw new ExcecaoEstruturaVazia();

		return elementos[0];
	}

	

}
