package infraEstrutura.estruturas;

import ine5384.arvores.ArvoreB;
import ine5384.excecoes.ExcecaoArvore;

import java.util.Iterator;

public class ArvoreBConcreta<T extends Comparable<T>> implements ArvoreB<T> {

	private int tamanho = 0;
	private T[] elementos;
	private ArvoreBConcreta<T>[] subArvores;
	private int n;

	public String toString(){
		String texto = elementos[0].toString();
		
		for(int i = 1; i < n - 1; i++){
			if(elementos[i] != null)
				texto = texto + ", " + elementos[i].toString();
		}
		
		texto = texto + "\n";
		
		for(int i = 0; i < n; i++){
			if(subArvores[i] != null)
				texto = texto + "SubArvore " + elementos[i].toString() + ": " + subArvores[i].toString();
		}
		
		return texto;
	}
	
	@SuppressWarnings("unchecked")
	public ArvoreBConcreta(int n) {
		this.n = n;
		elementos = (T[]) new Comparable[this.n];
		subArvores = new ArvoreBConcreta[this.n + 1];
	}

	public void insere(T elemento) {
		
		this.insiraNosElementos(elemento);
		
		if(this.arrayCheio())
			this.split();
		
		tamanho++;
	}

	private void split() {
		int meio = n / 2;
		
		for(int i = 0; i < meio; i ++){
			
		}
	}

	private boolean arrayCheio() {
		return elementos[n - 1] != null;
	}

	private void insiraNosElementos(T elemento) {
		
		if(elementos[0] == null){
			elementos[0] = elemento;
			return;
		}
		
		int posicao = n - 1;
		
		while(elementos[posicao] == null)
			posicao--;
		
		
		while(posicao >= 0 && elemento.compareTo(elementos[posicao]) < 0){
				elementos[posicao + 1] = elementos[posicao];
				posicao--;
		}
		
		elementos[posicao + 1] = elemento;
	}

	public void remove(T arg0) throws ExcecaoArvore {
		
		if(this.estaVazia())
			throw new ExcecaoArvore();
		
		tamanho--;
	}

	public Iterator<T> retornaIteratorInOrdem() {
		// TODO Auto-generated method stub
		return null;
	}

	public boolean contem(T outroElemento) {
		
		for(int i = 0; i < tamanho; i++){
			
			Integer comparacao = outroElemento.compareTo(elementos[i]);
			
			if(comparacao == 0)
				return true;
			
		}
		
		return false;
	}

	public T retorna(T arg0) {
		// TODO Auto-generated method stub
		return null;
	}

	public boolean estaCheia() {
		return false;
	}

	public boolean estaVazia() {
		return tamanho == 0;
	}

	public void esvazie() {
		// TODO Auto-generated method stub

	}

	public int retorneTamanho() {
		return tamanho;
	}

}
