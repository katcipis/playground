package lista.listas.simples;

import ine5384.excecoes.ExcecaoEstruturaCheia;
import ine5384.excecoes.ExcecaoEstruturaVazia;
import ine5384.excecoes.ExcecaoPosicaoIlegal;
import ine5384.lineares.Lista;
import infraestrutura.nodos.NodoDuplo;

public class ListaDuplamenteEncadeada<T> extends ListaAbstrata<T> {

	private NodoDuplo<T> inicio;
	private NodoDuplo<T> fim;

	public ListaDuplamenteEncadeada() {

		inicio = null;
		fim = null;

	}

	public void insiraNaPosicao(T elemento, int posicao)
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal {

		if (posicao <= 0 || posicao > numeroDeElementos + 1)
			throw new ExcecaoPosicaoIlegal(posicao);

		NodoDuplo<T> novoNodo = new NodoDuplo<T>(elemento);

		if (estaVazia()) {
			colocarPrimeiroElementoDaLista(novoNodo);

		} else {
			if (posicao == 1) {
				novoNodo.atribuiProximo(inicio);
				inicio.atribuiAnterior(novoNodo);
				inicio = novoNodo;
			} else {
				if (posicao == numeroDeElementos + 1) {
					fim.atribuiProximo(novoNodo);
					novoNodo.atribuiAnterior(fim);
					fim = novoNodo;
				} else {

					NodoDuplo<T> nodoNaPosicao = obterNodoNaPosicaoIndicada(posicao);
					novoNodo.atribuiAnterior(nodoNaPosicao.retornaAnterior());
					nodoNaPosicao.retornaAnterior().atribuiProximo(novoNodo);
					nodoNaPosicao.atribuiAnterior(novoNodo);
					novoNodo.atribuiProximo(nodoNaPosicao);
				}
			}
		}

		numeroDeElementos++;
	}

	private NodoDuplo<T> obterNodoNaPosicaoIndicada(int posicao) {
		NodoDuplo<T> nodoNaPosicao = inicio;
		for (int i = 2; i <= posicao; i++) {
			nodoNaPosicao = nodoNaPosicao.retornaProximo();
		}
		return nodoNaPosicao;
	}

	private void colocarPrimeiroElementoDaLista(NodoDuplo<T> novoNodo) {
		inicio = novoNodo;
		fim = novoNodo;
	}

	public void insiraNoFim(T elemento) throws ExcecaoEstruturaCheia {
		NodoDuplo<T> novoNodo = new NodoDuplo<T>(elemento);

		if (estaVazia()) {
			colocarPrimeiroElementoDaLista(novoNodo);
		} else {
			fim.atribuiProximo(novoNodo);
			novoNodo.atribuiAnterior(fim);
			fim = novoNodo;
		}

		numeroDeElementos++;

	}

	public void insiraNoInicio(T elemento) throws ExcecaoEstruturaCheia {

		NodoDuplo<T> novoNodo = new NodoDuplo<T>(elemento);

		if (estaVazia()) {
			colocarPrimeiroElementoDaLista(novoNodo);
		} else {
			novoNodo.atribuiProximo(inicio);
			inicio.atribuiAnterior(novoNodo);
			inicio = novoNodo;
		}

		numeroDeElementos++;

	}

	public boolean pertence(T elemento) {
		if (estaVazia())
			return false;
		for (NodoDuplo<T> nodoTemp = inicio; nodoTemp != null; nodoTemp = nodoTemp
				.retornaProximo()) {
			if (nodoTemp.retornaElemento() == elemento)
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

		if (numeroDeElementos == 1) {
			T elementoRemovido = inicio.retornaElemento();
			esvazie();
			return elementoRemovido;
		}

		if (posicao == 1) {
			T elementoRemovido = inicio.retornaElemento();
			inicio = inicio.retornaProximo();
			inicio.atribuiAnterior(null);
			numeroDeElementos--;
			return elementoRemovido;
		}

		if (posicao == numeroDeElementos) {
			T elementoRemovido = fim.retornaElemento();
			fim = fim.retornaAnterior();
			fim.atribuiProximo(null);
			numeroDeElementos--;
			return elementoRemovido;
		}

		NodoDuplo<T> nodoNaPosicao = obterNodoNaPosicaoIndicada(posicao);

		NodoDuplo<T> nodoAnteriorAPosicao = nodoNaPosicao.retornaAnterior();
		NodoDuplo<T> nodoPosteriorAPosicao = nodoNaPosicao.retornaProximo();

		nodoAnteriorAPosicao.atribuiProximo(nodoPosteriorAPosicao);
		nodoPosteriorAPosicao.atribuiAnterior(nodoAnteriorAPosicao);

		nodoAnteriorAPosicao = null;
		nodoPosteriorAPosicao = null;

		numeroDeElementos--;

		return nodoNaPosicao.retornaElemento();
	}

	public T removaDoFim() throws ExcecaoEstruturaVazia {

		if (estaVazia())
			throw new ExcecaoEstruturaVazia();

		T elementoRemovido = fim.retornaElemento();

		if (numeroDeElementos == 1) {
			esvazie();
		} else {
			fim = fim.retornaAnterior();
			fim.atribuiProximo(null);
		}

		numeroDeElementos--;
		return elementoRemovido;
	}

	public T removaDoInicio() throws ExcecaoEstruturaVazia {

		if (estaVazia())
			throw new ExcecaoEstruturaVazia();

		T elementoRemovido = inicio.retornaElemento();

		if (numeroDeElementos == 1) {
			esvazie();
		} else {
			inicio = inicio.retornaProximo();
			inicio.atribuiAnterior(null);
		}

		numeroDeElementos--;
		return elementoRemovido;

	}

	public Lista<T> removaIguais(T elemento) throws ExcecaoEstruturaVazia {

		if (estaVazia())
			throw new ExcecaoEstruturaVazia();

		Lista<T> listaDeRemovidos = new ListaDuplamenteEncadeada<T>();

		if (numeroDeElementos == 1) {
			if (inicio.retornaElemento().equals(elemento)) {

				try {
					listaDeRemovidos.insiraNoFim(inicio.retornaElemento());
				} catch (ExcecaoEstruturaCheia e) {
					e.printStackTrace();
				}
				esvazie();

			}
			return listaDeRemovidos;

		}

		for (NodoDuplo<T> nodoAtual = inicio; nodoAtual != null; nodoAtual = nodoAtual
				.retornaProximo()) {

			if (nodoAtual.retornaElemento().equals(elemento)) {

				try {
					listaDeRemovidos.insiraNoFim(nodoAtual.retornaElemento());
				} catch (ExcecaoEstruturaCheia e) {
					e.printStackTrace();
				}

				numeroDeElementos--;

				if (nodoAtual.retornaAnterior() == null) {
					inicio = inicio.retornaProximo();
				} else {
					if (nodoAtual.retornaProximo() == null) {
						fim = fim.retornaAnterior();
					} else {

						NodoDuplo<T> nodoAnteriorAoAtual = nodoAtual
								.retornaAnterior();
						NodoDuplo<T> nodoPosteriorAoAtual = nodoAtual
								.retornaProximo();

						nodoAnteriorAoAtual.atribuiProximo(nodoAtual
								.retornaProximo());
						nodoPosteriorAoAtual.atribuiAnterior(nodoAtual
								.retornaAnterior());

						nodoAnteriorAoAtual = null;
						nodoPosteriorAoAtual = null;
					}
				}
			}
		}

		inicio.atribuiAnterior(null);
		fim.atribuiProximo(null);

		return listaDeRemovidos;
	}

	public T removaIgual(T elemento) throws ExcecaoEstruturaVazia {

		if (estaVazia())
			throw new ExcecaoEstruturaVazia();

		T elementoRemovido = null;

		if (numeroDeElementos == 1) {
			if (inicio.retornaElemento().equals(elemento)) {
				elementoRemovido = inicio.retornaElemento();
				esvazie();
				return elementoRemovido;
			}

		} else {

			for (NodoDuplo<T> nodoAtual = inicio; nodoAtual != null; nodoAtual = nodoAtual
					.retornaProximo()) {

				if (nodoAtual.retornaElemento().equals(elemento)) {

					elementoRemovido = nodoAtual.retornaElemento();
					numeroDeElementos--;

					if (nodoAtual.retornaAnterior() == null) {
						inicio = inicio.retornaProximo();
						inicio.atribuiAnterior(null);
						return elementoRemovido;

					} else {
						if (nodoAtual.retornaProximo() == null) {
							fim = fim.retornaAnterior();
							fim.atribuiProximo(null);
							return elementoRemovido;
						} else {
							NodoDuplo<T> nodoAnteriorAPosicao = nodoAtual
									.retornaAnterior();
							NodoDuplo<T> nodoPosteriorAPosicao = nodoAtual
									.retornaProximo();

							nodoAnteriorAPosicao
									.atribuiProximo(nodoPosteriorAPosicao);
							nodoPosteriorAPosicao
									.atribuiAnterior(nodoAnteriorAPosicao);
							return elementoRemovido;
						}
					}
				}

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

		if (posicao == 1)
			return inicio.retornaElemento();

		if (posicao == numeroDeElementos)
			return fim.retornaElemento();

		NodoDuplo<T> nodoTemporario = inicio;
		for (int i = 2; i <= posicao; i++) {
			nodoTemporario = nodoTemporario.retornaProximo();
		}

		return nodoTemporario.retornaElemento();
	}

	public void substituaDaPosicao(T elemento, int posicao)
			throws ExcecaoEstruturaVazia, ExcecaoPosicaoIlegal {

		if (estaVazia())
			throw new ExcecaoEstruturaVazia();

		if (posicaoIlegal(posicao))
			throw new ExcecaoPosicaoIlegal(posicao);

		obterNodoNaPosicaoIndicada(posicao).atribuiElemento(elemento);

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
		Lista<T> listaDeIguais = new ListaDuplamenteEncadeada<T>();

		if (estaVazia())
			return listaDeIguais;

		for (NodoDuplo<T> nodoAtual = inicio; nodoAtual != null; nodoAtual = nodoAtual
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

		if (estaVazia())
			return null;

		for (NodoDuplo<T> nodoAtual = inicio; nodoAtual != null; nodoAtual = nodoAtual
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
