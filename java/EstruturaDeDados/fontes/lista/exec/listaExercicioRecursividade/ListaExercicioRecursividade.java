package lista.exec.listaExercicioRecursividade;

public interface ListaExercicioRecursividade <E>{
	
	/**
	 * Insere o elemento no final da lista.
	 */  
	public void insere (E elemento);

	
	/**
	 * Insere o elemento na posicao indicada pelo parametro, considerando que a lista
	 * comeca na posicao 0.
	 * Caso a posicao seja menor do que zero ou maior do que o numero de elementos, 
	 * e' gerada uma EXCECAO.
	 */
	public void insere (E elemento, int posicao);
 
 
	/** 
	 * Retorna TRUE se o elemento esta' contido na lista.
	 */
	public boolean contem (E elemento);

	
	/**
	 * Remove a primeira ocorrencia do elemento, retornando true.
	 * Caso nao encontre o elemento, retorna false. 
	 */
	public boolean exclui (E elemento);
  
  
	/**
	 * Remove o elemento que se encontra na posicao indicada pelo argumento e 
	 * retorna o elemento. Considera que a lista comeca na posicao 0.
	 * Caso a posicao seja menor do que zero, ou menor ou maior do que o numero de 
	 * elementos, e' gerada uma EXCECAO.
	 */
	public E exclui (int posicao);
  

	/**
	 * Retorna o elemento que se encontra na posicao indicada pelo parametro, 
	 * considerando que a lista comeca na posicao 0.
	 * Caso a posicao seja menor do que zero, ou igual ou maior do que o numero de 
	 * elementos, e' gerada uma EXCECAO.
	 */
    public E retorna (int posicao);
  

	/**
 	* Retorna a primeira posicao do elemento, considerando que a lista comeca na posicao 0. 
	* Caso o elemento nao exista na lista, retorna -1.
	*/
	public int retornaPosicao (E elemento);
  
  
	/** 
	 * Retorna TRUE se a lista nao possui nenhum elemento.
	 */
	public boolean estaVazia();


	/** 
	 * Retorna o numero de elementos da lista.
	 */	
	public int numeroElementos();

}
