package infraEstrutura.estruturas;

import ine5384.arvores.ArvoreBinaria;
import ine5384.excecoes.ExcecaoArvore;
import ine5384.excecoes.ExcecaoEstruturaCheia;
import ine5384.excecoes.ExcecaoEstruturaVazia;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class IteradorInOrdem<T extends Comparable<T>> implements Iterator<T> {

	private final PilhaEncadeada<Object> pilha;

	public IteradorInOrdem(ArvoreBinaria<T> arvore) {

		this.pilha = new PilhaEncadeada<Object>();

		try {
			if (!arvore.estaVazia())
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
	
	public void remove() {
		throw new UnsupportedOperationException();
	}

	@SuppressWarnings("unchecked")
	public T next() {
			
		if(this.hasNext()){
			
			boolean ehUmaArvore = false;
			try {
				ehUmaArvore = pilha.retorneTopo() instanceof ArvoreBinaria;
			} catch (ExcecaoEstruturaVazia e1) {
				e1.printStackTrace();
			}
			
			try {
				if(ehUmaArvore){
					do{
						ArvoreBinaria<T> arvoreDesempilhada = null, arvoreAEsquerdaDaDesempilhada = null, 
						arvoreADireitaDaDesempilhada = null;
							
							arvoreDesempilhada = (ArvoreBinaria<T>) pilha
								.desempilhe();
							
							arvoreAEsquerdaDaDesempilhada = arvoreDesempilhada
							        .retornaArvoreEsquerda(arvoreDesempilhada.retornaRaiz());
							
							arvoreADireitaDaDesempilhada = arvoreDesempilhada
							         .retornaArvoreDireita(arvoreDesempilhada.retornaRaiz());
							
							
							
							if(arvoreADireitaDaDesempilhada.retornaRaiz() != null){
								pilha.empilhe(arvoreADireitaDaDesempilhada);
							}
							
							pilha.empilhe(arvoreDesempilhada.retornaRaiz());
										
							if(arvoreAEsquerdaDaDesempilhada.retornaRaiz() != null){
								pilha.empilhe(arvoreAEsquerdaDaDesempilhada);
							}
											
						
						ehUmaArvore = pilha.retorneTopo() instanceof ArvoreBinaria;
						
					}while(ehUmaArvore);
				}
				
				return (T) pilha.desempilhe();
				
			
			}catch (ExcecaoEstruturaVazia e) {
				e.printStackTrace();
			} catch (ExcecaoArvore e) {
				e.printStackTrace();
			} catch (ExcecaoEstruturaCheia e) {
				e.printStackTrace();
			}
			
				
		}
		throw new NoSuchElementException();
	}
}
