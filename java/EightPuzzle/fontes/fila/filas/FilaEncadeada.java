package fila.filas;

import ine5384.excecoes.ExcecaoEstruturaCheia;
import ine5384.excecoes.ExcecaoEstruturaVazia;
import infraestrutura.nodos.NodoSimples;

public class FilaEncadeada<T> extends FilaAbstrata<T> {

	private NodoSimples<T> inicio, fim;

	public FilaEncadeada() {
		inicio = null;
		fim = null;
	}

	public boolean estaCheia() {
		return false;
	}

	public void insere(T elemento) throws ExcecaoEstruturaCheia {

		NodoSimples<T> novoNodo = new NodoSimples<T>(elemento);

		if (estaVazia()) {
			inicio = novoNodo;
			fim = novoNodo;
		} else {
			fim.atribuiProximo(novoNodo);
			fim = novoNodo;
		}

		numeroDeElementos++;

	}

	public T remove() throws ExcecaoEstruturaVazia {

		if (estaVazia())
			throw new ExcecaoEstruturaVazia();

		T elementoRemovido = inicio.retornaElemento();

		if (numeroDeElementos == 1) {
			inicio = null;
			fim = null;
		} else {
			inicio = inicio.retornaProximo();
		}

		numeroDeElementos--;

		return elementoRemovido;
	}

	public T retorneInicio() throws ExcecaoEstruturaVazia {

		if (estaVazia())
			throw new ExcecaoEstruturaVazia();

		return inicio.retornaElemento();
	}

	

}
