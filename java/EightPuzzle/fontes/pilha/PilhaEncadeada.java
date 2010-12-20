package pilha;

import ine5384.excecoes.ExcecaoEstruturaCheia;
import ine5384.excecoes.ExcecaoEstruturaVazia;


public class PilhaEncadeada<T> extends PilhaAbstrata<T> {

	private Integer numeroDeElementos;
	private NodoSimples<T> inicio;

	public PilhaEncadeada() {
		numeroDeElementos = 0;
		inicio = null;
	}

	public T desempilhe() throws ExcecaoEstruturaVazia {
		if (estaVazia())
			throw new ExcecaoEstruturaVazia();

		T elementoRemovido;

		elementoRemovido = inicio.retornaElemento();
		inicio = inicio.retornaProximo();

		numeroDeElementos--;
		return elementoRemovido;
	}

	public void empilhe(T elemento) throws ExcecaoEstruturaCheia {

		NodoSimples<T> novoNodo = new NodoSimples<T>(elemento);
		novoNodo.atribuiProximo(inicio);
		inicio = novoNodo;
		numeroDeElementos++;

	}

	public boolean estaVazia() {
		return numeroDeElementos == 0;
	}

	public T retorneTopo() throws ExcecaoEstruturaVazia {

		if (estaVazia())
			throw new ExcecaoEstruturaVazia();

		return inicio.retornaElemento();
	}

	public boolean estaCheia() {
		return false;
	}
	
	public Integer tamanho(){
		return numeroDeElementos;
	}
}
