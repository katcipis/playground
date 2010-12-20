package tabelaHash;




import ine5384.excecoes.ExcecaoEstruturaCheia;
import ine5384.excecoes.ExcecaoEstruturaVazia;
import infraestrutura.nodos.NodoHash;


import java.util.Iterator;

import pilha.pilhas.Pilha;
import pilha.pilhas.PilhaEncadeada;




public class TabelaHashConcreta<C, V> implements TabelaHash<C,V>{

	private NodoHash<C, V>[] valores;
	private Integer numeroDeElementos, tamanhoDoArray;

	@SuppressWarnings("unchecked")
	
	private TabelaHashConcreta(TabelaHashConcreta copiar) {
		
		this.tamanhoDoArray = copiar.tamanhoDoArray;
		this.valores = copiar.valores.clone();
		numeroDeElementos = copiar.numeroDeElementos;
	}
	
	@SuppressWarnings("unchecked")
	public TabelaHashConcreta(Integer tamanho) {
		this.tamanhoDoArray = tamanho;
		valores = new NodoHash[tamanhoDoArray];
		numeroDeElementos = 0;
	}
	
	@SuppressWarnings("unchecked")
	public TabelaHashConcreta() {
		this.tamanhoDoArray = 53;
		valores = new NodoHash[tamanhoDoArray];
		numeroDeElementos = 0;
	}

	@SuppressWarnings("unchecked")
	@Override
	public boolean equals(Object o){
		if(!(o instanceof TabelaHash))
			return false;
		TabelaHash tabela = (TabelaHash) o;
		
		for(int i = 0; i < valores.length; i++){
			if(valores[i] != null){
			
				if (!(tabela.existe(valores[i].retornaChave()))) 
					return false;
				
				if(!(tabela.retorna(valores[i].retornaChave())
						.equals(valores[i].retornaElemento())))
					return false;
				
				NodoHash nodoNaPosicao = valores[i];
				
				while (nodoNaPosicao.possuiProximo()) {
					
					if (!(tabela.existe(nodoNaPosicao.retornaChave()))) 
						return false;
					
					if(!(tabela.retorna(nodoNaPosicao.retornaChave())
							.equals(nodoNaPosicao.retornaElemento())))
						return false;
			
					nodoNaPosicao = nodoNaPosicao.retornaProximo();
				}
			}
		}
		
		return true;
	}
	
	public void insere(C chave, V valor) {

		Integer resto = Math.abs(chave.hashCode() % tamanhoDoArray);
		NodoHash<C, V> novoNodo = new NodoHash<C, V>(chave, valor);

		if (valores[resto] == null) {
			valores[resto] = novoNodo;
			numeroDeElementos++;
		} else {

			if (valores[resto].retornaChave().equals(chave)) {

				if(valores[resto].possuiProximo())
					novoNodo.atribuiProximo(valores[resto].retornaProximo());
				
				valores[resto] = novoNodo;
				
			} else {

				if(valores[resto].possuiProximo()){
					
					NodoHash<C, V> nodoNaPosicaoAnterior = valores[resto];
					NodoHash<C, V> nodoNaPosicao = null;
				
					boolean inserido = false;

					for(nodoNaPosicao = valores[resto].retornaProximo(); nodoNaPosicao != null && !inserido; 
					nodoNaPosicao = nodoNaPosicao.retornaProximo()){
						
						if(nodoNaPosicao.retornaChave().equals(novoNodo.retornaChave())){
							nodoNaPosicaoAnterior.atribuiProximo(novoNodo);
							novoNodo.atribuiProximo(nodoNaPosicao.retornaProximo());
							inserido = true;
						}
						
						nodoNaPosicaoAnterior = nodoNaPosicao;
						
					}
					
					if (!inserido) {
						
						nodoNaPosicaoAnterior.atribuiProximo(new NodoHash<C, V>(chave,
								valor));
						numeroDeElementos++;
					}
					
				}else{
					valores[resto].atribuiProximo(novoNodo);
					numeroDeElementos++;
				}
				
				

			}
		}

	}

	public V retorna(C chave) {
		
		Integer resto = Math.abs(chave.hashCode() % tamanhoDoArray);
		NodoHash<C, V> nodoNaPosicao = valores[resto];
		
		if(nodoNaPosicao == null)
			return null;
		
		if (nodoNaPosicao.retornaChave().equals(chave))
			return nodoNaPosicao.retornaElemento();
		;

		while (nodoNaPosicao.possuiProximo()) {

			nodoNaPosicao = nodoNaPosicao.retornaProximo();

			if (nodoNaPosicao.retornaChave().equals(chave))
				return nodoNaPosicao.retornaElemento();

		}

		return null;
	}

	public boolean estaVazia() {
		return numeroDeElementos == 0;
	}

	public V remove(C chave) {
		
		Integer resto = Math.abs(chave.hashCode() % tamanhoDoArray);
		
		if (valores[resto] == null) 
			return null;
		
		NodoHash<C, V> nodoRetornado;
			
			if (valores[resto].retornaChave().equals(chave)) {

				if (valores[resto].retornaProximo() != null) {
					
					nodoRetornado = valores[resto];
					valores[resto] = valores[resto].retornaProximo();
					numeroDeElementos--;
					return nodoRetornado.retornaElemento();
					
				} else {
					
					nodoRetornado = valores[resto];
					valores[resto] = null;
					numeroDeElementos--;
					return nodoRetornado.retornaElemento();
				}

			} else {

                  if(valores[resto].retornaProximo() != null){
					
					NodoHash<C, V> nodoNaPosicao = valores[resto].retornaProximo();
					NodoHash<C, V> nodoAnterior = valores[resto];
					
					do{
						if (nodoNaPosicao.retornaChave().equals(chave)) {

							if (nodoNaPosicao.retornaProximo() != null) {
								nodoAnterior.atribuiProximo(nodoNaPosicao
										.retornaProximo());
								numeroDeElementos--;
								return nodoNaPosicao.retornaElemento();
							}else{
								nodoAnterior.atribuiProximo(null);
								numeroDeElementos--;
								return nodoNaPosicao.retornaElemento();
							}


						}
						nodoAnterior = nodoNaPosicao;
						nodoNaPosicao = nodoNaPosicao.retornaProximo();
					}while (nodoNaPosicao.possuiProximo());
					
				}
			}
			
			return null;
				
		}
	

	public boolean existe(C chave) {
		
		return this.retorna(chave) != null;
				
	}

	public int retorneTamanho() {
		return numeroDeElementos;
	}

	public Iterator<C> retornaChaves() {
		return new Iterador();
	}
	
    public boolean estaCheia() {
		
		return false;
	}

	@SuppressWarnings("unchecked")
	public void esvazie() {
		numeroDeElementos = 0;
		valores = new NodoHash[tamanhoDoArray];
	}
	
	
	private class Iterador implements Iterator<C>{

    Pilha<C> pilha;
		
		public Iterador(){
			pilha = new PilhaEncadeada<C>();
			for(int i = (valores.length - 1); i>=0; i--){
				if(valores[i] != null){
					try {
						pilha.empilhe(valores[i].retornaChave());
					} catch (ExcecaoEstruturaCheia e) {
						e.printStackTrace();
					}
					
					NodoHash<C,V> proximo = valores[i];
					while(proximo.retornaProximo() != null){
						proximo = proximo.retornaProximo();
						try {
							pilha.empilhe(proximo.retornaChave());
						} catch (ExcecaoEstruturaCheia e) {
							e.printStackTrace();
						}
					}
				}
			}
		}
		
		public boolean hasNext() {
			return !pilha.estaVazia();
		}

		public C next() {
			if(this.hasNext()){
				try {
					return pilha.desempilhe();
				} catch (ExcecaoEstruturaVazia e) {
					e.printStackTrace();
				}
			}
			return null;
		}

		public void remove() {
			
			
		}

		
		
	}


	public TabelaHash<C, V> retornaCopia() {
		
		return new TabelaHashConcreta<C,V>(this);
	}

	

}
