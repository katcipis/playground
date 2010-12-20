package arvores.iteradores.infraestrutura;

import ine5384.arvores.ArvoreBinaria;
import ine5384.excecoes.ExcecaoEstruturaCheia;
import ine5384.excecoes.ExcecaoEstruturaVazia;

import java.util.Iterator;
import java.util.NoSuchElementException;

import pilha.pilhas.PilhaEncadeada;

public class IteradorPreOrdem<T extends Comparable<T>> implements Iterator<T> {

	
	private final PilhaEncadeada<ArvoreBinaria<T>> pilha;

	public IteradorPreOrdem(ArvoreBinaria<T> arvore) {
		
		this.pilha = new PilhaEncadeada<ArvoreBinaria<T>>();
		
		try {
			if(!arvore.estaVazia())
			    pilha.empilhe(arvore);
		} catch (ExcecaoEstruturaCheia e) {
			e.printStackTrace();
		}
	}

	public boolean hasNext() {
		if(pilha.estaVazia())
		         return false;
		return true;
	}

	public T next() {
		if(this.hasNext()){
			ArvoreBinaria<T> arvoreEmpilhada = null;
			try {
				arvoreEmpilhada = pilha.desempilhe();
				
				if(arvoreEmpilhada.retornaArvoreDireita(arvoreEmpilhada.retornaRaiz()).retornaRaiz() != null)
					pilha.empilhe(arvoreEmpilhada.retornaArvoreDireita(arvoreEmpilhada.retornaRaiz()));
				
				if(arvoreEmpilhada.retornaArvoreEsquerda(arvoreEmpilhada.retornaRaiz()).retornaRaiz() != null)
					pilha.empilhe(arvoreEmpilhada.retornaArvoreEsquerda(arvoreEmpilhada.retornaRaiz()));
				
				return arvoreEmpilhada.retornaRaiz();
				
			} catch (ExcecaoEstruturaVazia e) {
				e.printStackTrace();
			}  catch (ExcecaoEstruturaCheia e) {
				e.printStackTrace();
			}
			
			
			
		}
		throw new NoSuchElementException();
	}

	public void remove() {
		throw new UnsupportedOperationException();
	}

}
