package lista.listas.ordenadas;

import ine5384.excecoes.ExcecaoEstruturaCheia;
import ine5384.excecoes.ExcecaoEstruturaVazia;
import ine5384.excecoes.ExcecaoPosicaoIlegal;
import ine5384.lineares.ListaClassificada;
import ine5384.pp.Iterador;
import infraestrutura.nodos.NodoComparable;
import lista.iteradoresDaLista.IteradorDaListaOrdenada;

public class ListaOrdenadaEncadeada<C extends Comparable<C>> extends ListaOrdenadaAbstrata<C> {

	private NodoComparable<C> inicio, fim;

	public ListaOrdenadaEncadeada() {
	
		inicio = null;
		fim = null;
	}

	public void insira(C elemento) throws ExcecaoEstruturaCheia {
		if (estaVazia()) {
			inicio = new NodoComparable<C>(elemento);
			fim = inicio;
			numeroDeElementos++;
		} else {

			NodoComparable<C> nodoAtual, nodoAnterior = null;
			NodoComparable<C> novoNodo = new NodoComparable<C>(elemento);
			boolean naoInseriu = true;

			if (numeroDeElementos == 1) {
				if (novoNodo.retornaElemento().compareTo(
						inicio.retornaElemento()) <= 0) {
					novoNodo.atribuiProximo(inicio);
					fim = inicio;
					inicio = novoNodo;

				} else {
					inicio.atribuiProximo(novoNodo);
					fim = novoNodo;

				}
			} else {

				nodoAnterior = inicio;
				for (nodoAtual = inicio.retornaProximo(); naoInseriu
						&& nodoAtual != null; nodoAtual = nodoAtual
						.retornaProximo()) {

					if (novoNodo.retornaElemento().compareTo(
							nodoAtual.retornaElemento()) <= 0) {

						nodoAnterior.atribuiProximo(novoNodo);
						novoNodo.atribuiProximo(nodoAtual);

						naoInseriu = false;
					}

					nodoAnterior = nodoAtual;
				}

				if (naoInseriu) {
					fim.atribuiProximo(novoNodo);
					fim = novoNodo;

				}
			}
			numeroDeElementos++;
		}

	}

	public boolean pertence(C elemento) {
		if (estaVazia())
			return false;

		NodoComparable<C> nodoAtual;
		for (nodoAtual = inicio; nodoAtual != null; nodoAtual = nodoAtual
				.retornaProximo()) {

			if (nodoAtual.retornaElemento() == elemento)
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

		if (ehOPrimeiroElemento(posicao))
			return removaDoInicio();

		if (ehOUltimoElemento(posicao))
			return removaDoFim();

		NodoComparable<C> nodoAnteriorAoQueSeraRemovido = inicio;
		for (int i = 2; i < posicao; i++) {
			nodoAnteriorAoQueSeraRemovido = nodoAnteriorAoQueSeraRemovido
					.retornaProximo();
		}

		C elementoRemovido = nodoAnteriorAoQueSeraRemovido.retornaProximo()
				.retornaElemento();

		nodoAnteriorAoQueSeraRemovido
				.atribuiProximo(nodoAnteriorAoQueSeraRemovido.retornaProximo()
						.retornaProximo());

		numeroDeElementos--;

		return elementoRemovido;
	}

	public C removaDoFim() throws ExcecaoEstruturaVazia {
		if (estaVazia())
			throw new ExcecaoEstruturaVazia();

		C elementoRemovido;

		if (numeroDeElementos == 1) {
			elementoRemovido = inicio.retornaElemento();
			esvazie();
			return elementoRemovido;
		}

		NodoComparable<C> nodoAnteriorAoFim = inicio;

		for (int i = 2; i < numeroDeElementos; i++) {
			nodoAnteriorAoFim = nodoAnteriorAoFim.retornaProximo();
		}

		elementoRemovido = nodoAnteriorAoFim.retornaProximo().retornaElemento();
		fim = nodoAnteriorAoFim;
		fim.atribuiProximo(null);

		numeroDeElementos--;
		return elementoRemovido;
	}

	public C removaDoInicio() throws ExcecaoEstruturaVazia {

		if (estaVazia())
			throw new ExcecaoEstruturaVazia();

		C elementoRemovido = inicio.retornaElemento();

		if (inicio.retornaProximo() == null) {
			esvazie();
			return elementoRemovido;
		}

		inicio = inicio.retornaProximo();

		numeroDeElementos--;
		return elementoRemovido;
	}

	public C retorneDaPosicao(int posicao) throws ExcecaoEstruturaVazia,
			ExcecaoPosicaoIlegal {
		if (estaVazia())
			throw new ExcecaoEstruturaVazia();

		if (posicaoIlegal(posicao))
			throw new ExcecaoPosicaoIlegal(posicao);

		if (ehOPrimeiroElemento(posicao))
			return inicio.retornaElemento();

		if (ehOUltimoElemento(posicao))
			return fim.retornaElemento();

		NodoComparable<C> nodoNaPosicao = inicio;
		for (int i = 2; i <= posicao; i++) {
			nodoNaPosicao = nodoNaPosicao.retornaProximo();
		}

		return nodoNaPosicao.retornaElemento();
	}

	private boolean ehOUltimoElemento(int posicao) {
		return posicao == numeroDeElementos;
	}

	private boolean ehOPrimeiroElemento(int posicao) {
		return posicao == 1;
	}

	public Iterador<C> retorneIterador() {

		return new IteradorDaListaOrdenada<C>(this);
	}

	public ListaClassificada<C> temIguais(C elemento) {
		ListaClassificada<C> listaDeIguais = new ListaOrdenadaEncadeada<C>();
		for (NodoComparable<C> nodoAtual = inicio; nodoAtual != null; nodoAtual = nodoAtual
				.retornaProximo()) {
			if (nodoAtual.retornaElemento().equals(elemento))
				try {
					listaDeIguais.insira(nodoAtual.retornaElemento());
				} catch (ExcecaoEstruturaCheia e) {
					e.printStackTrace();
				}
		}
		return listaDeIguais;
	}

	public C temIgual(C elemento) {
		for (NodoComparable<C> nodoAtual = inicio; nodoAtual != null; nodoAtual = nodoAtual
				.retornaProximo()) {
			if (nodoAtual.retornaElemento().equals(elemento))
				return nodoAtual.retornaElemento();
		}
		return null;
	}

	public C retorneDoFim() throws ExcecaoEstruturaVazia {
		if (estaVazia())
			throw new ExcecaoEstruturaVazia();
		return fim.retornaElemento();
	}

	public C retorneDoInicio() throws ExcecaoEstruturaVazia {
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
