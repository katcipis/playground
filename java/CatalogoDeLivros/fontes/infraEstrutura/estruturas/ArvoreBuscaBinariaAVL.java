package infraEstrutura.estruturas;

import ine5384.arvores.ArvoreBinaria;
import ine5384.excecoes.ExcecaoArvore;

import java.util.Iterator;



public class ArvoreBuscaBinariaAVL<T extends Comparable<T>> implements
		ArvoreBinaria<T> {

	private ArvoreBuscaBinariaAVL<T> esquerda, direita;
	private T elemento;

	public boolean ehAncestral(T ancestral, T descendente) {

		if (estaVazia())
			return false;

		if (this.elemento.compareTo(ancestral) == 0) {

			if (ancestral.compareTo(descendente) == 0)
				return true;

			if (ancestral.compareTo(descendente) > 0)
				return this.esquerda.contem(descendente);

			return this.direita.contem(descendente);

		}

		if (ancestral.compareTo(this.elemento) < 0)
			return this.esquerda.ehAncestral(ancestral, descendente);

		return this.direita.ehAncestral(ancestral, descendente);

	}

	public void insere(T elemento) {

		if (estaVazia()) {

			this.elemento = elemento;
			this.esquerda = new ArvoreBuscaBinariaAVL<T>();
			this.direita = new ArvoreBuscaBinariaAVL<T>();

		} else {
			if (elemento.compareTo(this.elemento) < 0) {
				this.esquerda.insere(elemento);
			} else {
				this.direita.insere(elemento);
			}
			
			balancearArvoreSeForPreciso();
					
		}

	}

	

	private int obterDiferencaEntreAlturas() {
		return this.esquerda.retornaAltura() - this.direita.retornaAltura();
	}

	private void rotacionarParaEsquerda() {
		
		ArvoreBuscaBinariaAVL<T> novaDireita, 
		novaEsquerda = new ArvoreBuscaBinariaAVL<T>();
		
	    novaDireita = this.direita.direita;
	   
		novaEsquerda.elemento = this.elemento;
		novaEsquerda.esquerda = this.esquerda;
		novaEsquerda.direita = this.direita.esquerda;
		
		this.elemento = this.direita.elemento;
		this.esquerda = novaEsquerda;
		this.direita = novaDireita;
		
	}

	private void rotacionarParaDireita() {
		
		ArvoreBuscaBinariaAVL<T> novaEsquerda, 
		novaDireita = new ArvoreBuscaBinariaAVL<T>();
		
	    novaEsquerda = this.esquerda.esquerda;
	   
		novaDireita.elemento = this.elemento;
		novaDireita.direita = this.direita;
		novaDireita.esquerda = this.esquerda.direita;
		
		this.elemento = this.esquerda.elemento;
		this.esquerda = novaEsquerda;
		this.direita = novaDireita;
	}
    
	public void remove(T elemento) {

		if (!estaVazia()) {

			if (this.elemento.compareTo(elemento) == 0) {
				if (ehNodoFolha()) {
					esvazie();
				} else {
					if (possuiArvoreEsquerda()) {
						this.elemento = this
								.removeOMaiorElementoDaArvore(this.esquerda);
						
						this.balancearArvoreSeForPreciso();
					} else {
						this.elemento = this
								.removeOMenorElementoDaArvore(this.direita);
						
						this.balancearArvoreSeForPreciso();
					}
				}
			} else {
				if (elemento.compareTo(this.elemento) < 0) {
					
					this.esquerda.remove(elemento);
					
					this.balancearArvoreSeForPreciso();
				} else {
					
					this.direita.remove(elemento);
					
					this.balancearArvoreSeForPreciso();
				}
			}
			
		}
		
	}

	private void balancearArvoreSeForPreciso() {
		Integer diferencaDasAlturas = obterDiferencaEntreAlturas();
		
		if(diferencaDasAlturas >= 2){
			if(this.esquerda.obterDiferencaEntreAlturas() < 0){
				this.esquerda.rotacionarParaEsquerda();
			}
		   
		this.rotacionarParaDireita(); 
			
		}	
		if(diferencaDasAlturas <= -2){
			if(this.direita.obterDiferencaEntreAlturas() > 0){
				this.direita.rotacionarParaDireita();
			}
			
			this.rotacionarParaEsquerda();
		}
	}

	private T removeOMenorElementoDaArvore(ArvoreBuscaBinariaAVL<T> arvore) {

		T menorElemento;

		if (arvore.ehNodoFolha()) {
			menorElemento = arvore.elemento;
			arvore.esvazie();
			return menorElemento;
		}

		if (arvore.esquerda.elemento != null)
			return arvore.removeOMenorElementoDaArvore(arvore.esquerda);

		menorElemento = arvore.elemento;
		this.remove(arvore.elemento);

		return menorElemento;
	}

	private T removeOMaiorElementoDaArvore(ArvoreBuscaBinariaAVL<T> arvore) {

		T maiorElemento;

		if (arvore.ehNodoFolha()) {
			maiorElemento = arvore.elemento;
			arvore.esvazie();
			return maiorElemento;
		}

		if (arvore.direita.elemento != null)
			return arvore.removeOMaiorElementoDaArvore(arvore.direita);

		maiorElemento = arvore.elemento;
		this.remove(arvore.elemento);

		return maiorElemento;

	}

	private boolean possuiArvoreEsquerda() {

		return this.esquerda.retornaRaiz() != null;
	}

	private boolean possuiArvoreDireita() {

		return this.direita.retornaRaiz() != null;
	}

	private boolean ehNodoFolha() {

		return (this.esquerda.retornaRaiz() == null)
				&& (this.direita.retornaRaiz() == null);
	}

	public int retornaAltura() {
		if (estaVazia())
			return -1;

		Integer alturaDaDireita, alturaDaEsquerda;

		alturaDaDireita = 1 + direita.retornaAltura();

		alturaDaEsquerda = 1 + esquerda.retornaAltura();

		if (alturaDaDireita >= alturaDaEsquerda)
			return alturaDaDireita;

		return alturaDaEsquerda;
	}

	public ArvoreBinaria<T> retornaArvoreDireita(T elemento) {

		if (estaVazia())
			return null;

		if (this.elemento.compareTo(elemento) == 0)
			return direita;

		if (elemento.compareTo(this.elemento) < 0) {
			return esquerda.retornaArvoreDireita(elemento);
		} else {
			return direita.retornaArvoreDireita(elemento);
		}

	}

	public ArvoreBinaria<T> retornaArvoreEsquerda(T elemento) {

		if (estaVazia())
			return null;

		if (this.elemento.compareTo(elemento) == 0)
			return esquerda;

		if (elemento.compareTo(this.elemento) < 0) {
			return esquerda.retornaArvoreEsquerda(elemento);
		} else {
			return direita.retornaArvoreEsquerda(elemento);
		}
	}

	public int retornaComprimento(T origem, T destino) {

		if (estaVazia())
			throw new ExcecaoArvore();

		if (this.elemento.compareTo(origem) == 0) {

			if (origem.compareTo(destino) == 0)
				return 0;

			if (origem.compareTo(destino) > 0)
				return this.esquerda.retornaDistancia(destino);

			return this.direita.retornaDistancia(destino);
		}

		if (origem.compareTo(this.elemento) < 0)
			return this.esquerda.retornaComprimento(origem, destino);

		return this.direita.retornaComprimento(origem, destino);
	}

	private Integer retornaDistancia(T destino) {

		if (estaVazia())
			throw new ExcecaoArvore();

		if (this.elemento.compareTo(destino) == 0)
			return 1;

		if (this.elemento.compareTo(destino) > 0)
			return this.esquerda.retornaDistancia(destino) + 1;

		return this.direita.retornaDistancia(destino) + 1;
	}

	public int retornaGrau(T elemento) {

		if (estaVazia())
			throw new ExcecaoArvore();

		if (this.elemento.compareTo(elemento) == 0)
			return verificarQuantasSubArvoresPossui();

		if (elemento.compareTo(this.elemento) < 0) {
			return this.esquerda.retornaGrau(elemento);
		} else {
			return this.direita.retornaGrau(elemento);
		}

	}

	private Integer verificarQuantasSubArvoresPossui() {

		Integer quantidadeDeSubarvores = 0;

		if (possuiArvoreEsquerda())
			quantidadeDeSubarvores++;

		if (possuiArvoreDireita())
			quantidadeDeSubarvores++;

		return quantidadeDeSubarvores;
	}

	public Iterator<T> retornaIteratorInOrdem() {

		return new IteradorInOrdem<T>(this);
	}

	public Iterator<T> retornaIteratorPosOrdem() {

		return new IteradorPosOrdem<T>(this);
	}

	public Iterator<T> retornaIteratorPreOrdem() {

		return new IteradorPreOrdem<T>(this);
	}

	public T retornaPai(T elemento) {

		if (estaVazia())
			throw new ExcecaoArvore();

		if (this.elemento.compareTo(elemento) == 0)
			return null;

		return procurarPaiNasSubArvores(elemento);

	}

	private T procurarPai(T elemento) {
		if (estaVazia())
			throw new ExcecaoArvore();

		return procurarPaiNasSubArvores(elemento);
	}

	private T procurarPaiNasSubArvores(T elemento) {
		boolean elementoDadoEhMenorQueOMeuElemento = elemento
				.compareTo(this.elemento) < 0;

		if (elementoDadoEhMenorQueOMeuElemento) {
			if (this.possuiArvoreEsquerda()) {
				if (elemento.compareTo(this.esquerda.elemento) == 0)
					return this.elemento;
			}

		} else {
			if (this.possuiArvoreDireita()) {
				if (elemento.compareTo(this.direita.elemento) == 0)
					return this.elemento;
			}

		}

		if (elementoDadoEhMenorQueOMeuElemento)
			return this.esquerda.procurarPai(elemento);
		return this.direita.procurarPai(elemento);
	}

	public T retornaRaiz() {

		return elemento;
	}

	public boolean contem(T elemento) {

		if (estaVazia())
			return false;

		if (this.elemento.compareTo(elemento) == 0)
			return true;

		if (elemento.compareTo(this.elemento) < 0) {
			return this.esquerda.contem(elemento);
		} else {
			return this.direita.contem(elemento);
		}

	}

	public T retorna(T elemento) {

		if (estaVazia())
			return null;

		if (this.elemento.compareTo(elemento) == 0)
			return this.elemento;

		if (elemento.compareTo(this.elemento) < 0) {
			return this.esquerda.retorna(elemento);
		} else {
			return this.direita.retorna(elemento);
		}

	}

	public boolean estaCheia() {

		return false;
	}

	public boolean estaVazia() {

		return this.elemento == null;
	}

	public void esvazie() {
		this.elemento = null;
		this.esquerda = null;
		this.direita = null;
	}

	public int retorneTamanho() {

		if (estaVazia())
			return 0;

		Integer tamanhoDaArvoreDireita = 0, tamanhoDaArvoreEsquerda = 0;

		if (this.possuiArvoreDireita())
			tamanhoDaArvoreDireita = this.direita.retorneTamanho();

		if (this.possuiArvoreEsquerda())
			tamanhoDaArvoreEsquerda = this.esquerda.retorneTamanho();

		return tamanhoDaArvoreDireita + tamanhoDaArvoreEsquerda + 1;

	}
}
