package arvores.arvoreB;

import ine5384.arvores.ArvoreB;
import ine5384.excecoes.ExcecaoArvore;
import ine5384.excecoes.ExcecaoEstruturaCheia;
import ine5384.excecoes.ExcecaoEstruturaVazia;
import ine5384.excecoes.ExcecaoPosicaoIlegal;
import ine5384.lineares.ListaClassificada;

import java.util.Iterator;

import lista.listas.ordenadas.ListaOrdenadaArray;

public class ArvoreBConcreta<C extends Comparable<C>> implements ArvoreB<C> {

	private ArvoreBConcreta<C>[] subArvores;
	private C[] chaves;
	private Integer numeroDeElementos, nDaArvore;
	private ArvoreBConcreta<C> pai;
	
	
	@SuppressWarnings("unchecked")
	public ArvoreBConcreta(Integer nDaArvore){
		this.nDaArvore = nDaArvore;
		subArvores =  new ArvoreBConcreta[nDaArvore + 1];
		chaves = (C[]) new Comparable[nDaArvore];
		numeroDeElementos = 0;
		pai = null;
	}
	
	@SuppressWarnings("unchecked")
	private ArvoreBConcreta(Integer nDaArvore, ArvoreBConcreta<C> pai){
		this.pai = pai;
		this.nDaArvore = nDaArvore;
		subArvores =  new ArvoreBConcreta[nDaArvore + 1];
		chaves = (C[]) new Comparable[nDaArvore];
		numeroDeElementos = 0;
		
	}
	

	@SuppressWarnings("unchecked")
	public ArvoreBConcreta(){
		nDaArvore = 3;
		subArvores =  new ArvoreBConcreta[nDaArvore + 1];
		chaves = (C[]) new Comparable[nDaArvore];
		numeroDeElementos = 0;
		pai = null;
	}
	
	
	@SuppressWarnings("unchecked")
	public void insere(C elemento) {
		if(estaVazia()){
			criarSubArvoresVazias();
		}
		
		if(estaCheia()){
			Integer meio = nDaArvore / 2;
			C ficaNaRaiz = chaves[meio];
			
			for(int i = 0; i < meio; i++){
				subArvores[meio - 1].insere(chaves[i]);
			}
			
			for(int i = meio + 1; i < nDaArvore; i++){
				subArvores[meio + 1].insere(chaves[i]);
			}
			
			if(elemento.compareTo(ficaNaRaiz) < 0){
				subArvores[meio - 1].insere(elemento);
			}else{
				subArvores[meio + 1].insere(elemento);
			}
			
			chaves = (C[]) new Comparable[nDaArvore];
			chaves[0] = ficaNaRaiz;
			numeroDeElementos = 1;
			
		}else{
			chaves[numeroDeElementos] = elemento;
			numeroDeElementos++;
			reordenarArvore();
		}
		
		
	}


	private void reordenarArvore() {
		ListaClassificada<C> listaOrdenada = new ListaOrdenadaArray<C>(numeroDeElementos); 
		for(int i = 0; i < numeroDeElementos; i++){
			try {
				listaOrdenada.insira(chaves[i]);
			} catch (ExcecaoEstruturaCheia e) {
				e.printStackTrace();
			}
		}
		
		for(int i = 0; i < numeroDeElementos; i++){
			
				try {
					chaves[i] = listaOrdenada.retorneDaPosicao(i + 1);
				} catch (ExcecaoEstruturaVazia e) {
					e.printStackTrace();
				} catch (ExcecaoPosicaoIlegal e) {
					e.printStackTrace();
				}
			
		}
		
	}

	private void criarSubArvoresVazias() {
		for(int i = 0; i < subArvores.length; i++){
			
			subArvores[i] = new ArvoreBConcreta<C>(nDaArvore, this);
			
		}
	}

	
	public void remove(C elemento) throws ExcecaoArvore {
		// TODO Auto-generated method stub
		
	}

	
	public Iterator<C> retornaIteratorInOrdem() {
		// TODO Auto-generated method stub
		return null;
	}

	
	public boolean contem(C elemento) {
		if(estaVazia())
			return false;
		
		for(int i = 0; i < numeroDeElementos; i++){
			if(chaves[i].compareTo(elemento) == 0)
				return true;
		}
		
		boolean contem = false;
	    Integer i = 0;
		
	    while(!contem && i < nDaArvore){
			
			contem = subArvores[i].contem(elemento);
			i++;
	   }
		
		return contem;
	}

	
	public C retorna(C arg0) {
		// TODO Auto-generated method stub
		return null;
	}

	
	public boolean estaCheia() {
		
		return numeroDeElementos == nDaArvore;
	}

	
	public boolean estaVazia() {
		
		return numeroDeElementos == 0;
	}

	
	public void esvazie() {
		chaves = null;
		subArvores = null;
		numeroDeElementos = 0;
	}

	
	public int retorneTamanho(){
		if(estaVazia())
			return 0;
		Integer tamanhoDasArvores = 0;
		for(int i = 0; i < subArvores.length; i++){
			tamanhoDasArvores = tamanhoDasArvores + subArvores[i].retorneTamanho();
		}
		return numeroDeElementos + tamanhoDasArvores;
	
	}

}
