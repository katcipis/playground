package lista.listas.simples;

import ine5384.excecoes.ExcecaoEstruturaCheia;
import ine5384.excecoes.ExcecaoEstruturaVazia;
import ine5384.excecoes.ExcecaoPosicaoIlegal;
import ine5384.lineares.Lista;
import infraestrutura.nodos.NodoSimples;

public class ListaEncadeada<T> extends ListaAbstrata<T> {

	private NodoSimples<T> inicio;
	private NodoSimples<T> fim;

	public ListaEncadeada() {

		inicio = null;
		fim = null;

	}

	public void insiraNaPosicao(T elemento, int posicao)
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal {

		if (posicao > numeroDeElementos + 1 || posicao <= 0)
			throw new ExcecaoPosicaoIlegal(posicao);

		NodoSimples<T> nodoAnteriorAPosicao = null;
		NodoSimples<T> novoNodo = new NodoSimples<T>(elemento);

		if (estaVazia()) {
			this.inicio = novoNodo;
			this.fim = novoNodo;

		} else {
			if (posicao == 1) {
				novoNodo.atribuiProximo(inicio);
				inicio = novoNodo;

			} else {
				if (posicao == numeroDeElementos + 1) {
					fim.atribuiProximo(novoNodo);
					fim = novoNodo;

				} else {
					nodoAnteriorAPosicao = inicio;
					for (int i = 2; i < posicao; i++) {
						nodoAnteriorAPosicao = nodoAnteriorAPosicao
								.retornaProximo();
					}
					novoNodo.atribuiProximo(nodoAnteriorAPosicao
							.retornaProximo());
					nodoAnteriorAPosicao.atribuiProximo(novoNodo);

				}
			}

		}
		numeroDeElementos++;

	}

	public void insiraNoFim(T elemento) throws ExcecaoEstruturaCheia {

		if (estaVazia()) {
			inserirElementoNaListaVazia(elemento);

		} else {
			NodoSimples<T> novoNodo = new NodoSimples<T>(elemento);
			fim.atribuiProximo(novoNodo);
			fim = novoNodo;
			numeroDeElementos++;
		}

	}

	private void inserirElementoNaListaVazia(T elemento) {
		inicio = new NodoSimples<T>(elemento);
		fim = inicio;
		numeroDeElementos++;
	}

	public void insiraNoInicio(T elemento) throws ExcecaoEstruturaCheia {

		if (estaVazia()) {

			inserirElementoNaListaVazia(elemento);

		} else {

			NodoSimples<T> novoNodo = new NodoSimples<T>(elemento);
			novoNodo.atribuiProximo(inicio);
			inicio = novoNodo;
			numeroDeElementos++;

		}
	}

	public boolean pertence(T elemento) {

		for (NodoSimples<T> nodoTemporario = inicio; nodoTemporario != null; nodoTemporario = nodoTemporario
				.retornaProximo()) {

			if (nodoTemporario.retornaElemento() == elemento)
				return true;

		}
		return false;
	}

	public T removaDaPosicao(int posicao) throws ExcecaoEstruturaVazia,
			ExcecaoPosicaoIlegal {

		if (estaVazia())
			throw new ExcecaoEstruturaVazia();

		if (posicaoIlegal(posicao))
			throw new ExcecaoPosicaoIlegal(posicao);

		if (posicao == 1)
			return removaDoInicio();

		if (posicao == numeroDeElementos)
			return removaDoFim();

		NodoSimples<T> nodoAnteriorAoQueSeraRemovido = inicio;
		for (int i = 2; i < posicao; i++) {
			nodoAnteriorAoQueSeraRemovido = nodoAnteriorAoQueSeraRemovido
					.retornaProximo();
		}

		T elementoRemovido = nodoAnteriorAoQueSeraRemovido.retornaProximo()
				.retornaElemento();

		nodoAnteriorAoQueSeraRemovido
				.atribuiProximo(nodoAnteriorAoQueSeraRemovido.retornaProximo()
						.retornaProximo());

		numeroDeElementos--;

		return elementoRemovido;
	}

	public T removaDoFim() throws ExcecaoEstruturaVazia {
		if (estaVazia())
			throw new ExcecaoEstruturaVazia();

		T elementoRemovido;

		if (numeroDeElementos == 1) {
			elementoRemovido = inicio.retornaElemento();
			esvazie();
			return elementoRemovido;
		}

		NodoSimples<T> nodoAnteriorAoFim = inicio;

		for (int i = 2; i < numeroDeElementos; i++) {
			nodoAnteriorAoFim = nodoAnteriorAoFim.retornaProximo();
		}

		elementoRemovido = nodoAnteriorAoFim.retornaProximo().retornaElemento();
		fim = nodoAnteriorAoFim;
		fim.atribuiProximo(null);

		numeroDeElementos--;
		return elementoRemovido;
	}

	public T removaDoInicio() throws ExcecaoEstruturaVazia {

		if (estaVazia())
			throw new ExcecaoEstruturaVazia();

		T elementoRemovido = inicio.retornaElemento();

		if (inicio.retornaProximo() == null) {
			esvazie();
			return elementoRemovido;
		}

		inicio = inicio.retornaProximo();

		numeroDeElementos--;
		return elementoRemovido;
	}

	public Lista<T> removaIguais(T elemento) throws ExcecaoEstruturaVazia {
		if (estaVazia())
			throw new ExcecaoEstruturaVazia();

		NodoSimples<T> nodoAnterior = null;
		Lista<T> listaDeRemovidos = new ListaEncadeada<T>();

		for (NodoSimples<T> nodoAtual = inicio; nodoAtual != null; nodoAtual = nodoAtual
				.retornaProximo()) {

			if (nodoAtual.retornaElemento().equals(elemento)) {
				try {
					listaDeRemovidos.insiraNoFim(nodoAtual.retornaElemento());
				} catch (ExcecaoEstruturaCheia e) {
					e.printStackTrace();
				}

				if (nodoAnterior != null) {

					if (nodoAtual.retornaProximo() != null) {
						nodoAnterior.atribuiProximo(nodoAtual.retornaProximo());

						numeroDeElementos--;
					} else {
						fim = nodoAnterior;
						fim.atribuiProximo(null);
						numeroDeElementos--;
					}

				} else {
					if (nodoAtual.retornaProximo() != null) {
						inicio = nodoAtual.retornaProximo();
						numeroDeElementos--;
					} else {
						esvazie();
					}

				}

			} else {
				nodoAnterior = nodoAtual;
			}
		}

		return listaDeRemovidos;
	}

	public T removaIgual(T elemento) throws ExcecaoEstruturaVazia {

		if (estaVazia())
			throw new ExcecaoEstruturaVazia();

		NodoSimples<T> nodoAnterior = null;
		T elementoRemovido = null;

		for (NodoSimples<T> nodoAtual = inicio; nodoAtual != null; nodoAtual = nodoAtual
				.retornaProximo()) {

			if (nodoAtual.retornaElemento().equals(elemento)) {

				elementoRemovido = nodoAtual.retornaElemento();

				if (nodoAnterior != null) {

					if (nodoAtual.retornaProximo() != null) {
						nodoAnterior.atribuiProximo(nodoAtual.retornaProximo());
						numeroDeElementos--;
						return elementoRemovido;

					} else {
						fim = nodoAnterior;
						fim.atribuiProximo(null);
						numeroDeElementos--;
						return elementoRemovido;
					}

				} else {
					if (nodoAtual.retornaProximo() != null) {
						inicio = nodoAtual.retornaProximo();
						numeroDeElementos--;
						return elementoRemovido;

					} else {
						esvazie();
						return elementoRemovido;
					}

				}

			} else {
				nodoAnterior = nodoAtual;
			}
		}

		return elementoRemovido;
	}

	public T retorneDaPosicao(int posicao) throws ExcecaoEstruturaVazia,
			ExcecaoPosicaoIlegal {

		if (estaVazia())
			throw new ExcecaoEstruturaVazia();

		if (posicaoIlegal(posicao))
			throw new ExcecaoPosicaoIlegal(posicao);

		NodoSimples<T> nodoNaPosicaoDesejada = inicio;

		for (int i = 2; i <= posicao; i++) {
			if (nodoNaPosicaoDesejada.retornaProximo() != null)
				nodoNaPosicaoDesejada = nodoNaPosicaoDesejada.retornaProximo();
		}

		return nodoNaPosicaoDesejada.retornaElemento();
	}

	public void substituaDaPosicao(T elemento, int posicao)
			throws ExcecaoEstruturaVazia, ExcecaoPosicaoIlegal {

		if (estaVazia())
			throw new ExcecaoEstruturaVazia();

		if (posicaoIlegal(posicao))
			throw new ExcecaoPosicaoIlegal(posicao);

		NodoSimples<T> nodoNaPosicaoDesejada = inicio;

		for (int i = 2; i <= posicao; i++) {
			nodoNaPosicaoDesejada = nodoNaPosicaoDesejada.retornaProximo();
		}

		nodoNaPosicaoDesejada.atribuiElemento(elemento);
	}

	public void substituaDoFim(T elemento) throws ExcecaoEstruturaVazia {
		if (estaVazia())
			throw new ExcecaoEstruturaVazia();
		fim.atribuiElemento(elemento);

	}

	public void substituaDoInicio(T elemento) throws ExcecaoEstruturaVazia {
		if (estaVazia())
			throw new ExcecaoEstruturaVazia();
		inicio.atribuiElemento(elemento);

	}

	public Lista<T> temIguais(T elemento) {
		Lista<T> listaDeIguais = new ListaEncadeada<T>();
		for (NodoSimples<T> nodoAtual = inicio; nodoAtual != null; nodoAtual = nodoAtual
				.retornaProximo()) {
			if (nodoAtual.retornaElemento().equals(elemento))
				try {
					listaDeIguais.insiraNoFim(nodoAtual.retornaElemento());
				} catch (ExcecaoEstruturaCheia e) {
					e.printStackTrace();
				}
		}
		return listaDeIguais;
	}

	public T temIgual(T elemento) {

		for (NodoSimples<T> nodoAtual = inicio; nodoAtual != null; nodoAtual = nodoAtual
				.retornaProximo()) {
			if (nodoAtual.retornaElemento().equals(elemento))
				return nodoAtual.retornaElemento();
		}
		return null;
	}

	public T retorneDoFim() throws ExcecaoEstruturaVazia {
		if (estaVazia())
			throw new ExcecaoEstruturaVazia();
		return fim.retornaElemento();
	}

	public T retorneDoInicio() throws ExcecaoEstruturaVazia {
		if (estaVazia())
			throw new ExcecaoEstruturaVazia();
		return inicio.retornaElemento();
	}

	public boolean estaCheia() {

		return false;
	}

	public void esvazie() {
		numeroDeElementos = 0;
		inicio = null;
		fim = null;

	}

}
