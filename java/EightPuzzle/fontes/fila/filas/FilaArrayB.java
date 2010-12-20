package fila.filas;

import ine5384.excecoes.ExcecaoEstruturaCheia;
import ine5384.excecoes.ExcecaoEstruturaVazia;

public class FilaArrayB<T> extends FilaAbstrata<T> {

	private T[] elementos;
	private Integer inicio, fim;

	@SuppressWarnings("unchecked")
	public FilaArrayB() {
		inicio = 0;
		fim = -1;
		elementos = (T[]) new Object[10];
	}

	@SuppressWarnings("unchecked")
	public FilaArrayB(Integer tamanhoDaLista) {
		inicio = 0;
		fim = -1;
		elementos = (T[]) new Object[tamanhoDaLista];
	}

	public T remove() throws ExcecaoEstruturaVazia {
		if (estaVazia())
			throw new ExcecaoEstruturaVazia();

		T elementoRemovido = elementos[inicio];

		if (numeroDeElementos == 1) {
			elementos[inicio] = null;
		} else {
			if (inicio < elementos.length - 1) {
				elementos[inicio] = null;
				inicio++;
			} else {
					inicio = 0;
			}
		}
		
		numeroDeElementos--;
		return elementoRemovido;
	}

	public void insere(T elemento) throws ExcecaoEstruturaCheia {
		if (estaCheia())
			throw new ExcecaoEstruturaCheia();

	    fim++;
		
		elementos[fim % (elementos.length - 1)] = elemento;
		numeroDeElementos++;

	}

	public boolean estaCheia() {

		return numeroDeElementos == elementos.length;
	}

	public T retorneInicio() throws ExcecaoEstruturaVazia {
		if (estaVazia())
			throw new ExcecaoEstruturaVazia();

		return elementos[inicio];
	}
}
