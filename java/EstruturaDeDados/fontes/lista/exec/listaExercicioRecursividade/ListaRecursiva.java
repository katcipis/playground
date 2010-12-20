package lista.exec.listaExercicioRecursividade;

public class ListaRecursiva<E> implements ListaExercicioRecursividade<E> {

	private Integer numeroDeElementos;
	private E elemento;
	private ListaRecursiva<E> resto;

	public ListaRecursiva() {
		resto = null;
		numeroDeElementos = 0;
		elemento = null;
	}

	public boolean contem(E elemento) {

		if (this.estaVazia())
			return false;

		if (this.elemento.equals(elemento))
			return true;

		return resto.contem(elemento);

	}

	public boolean estaVazia() {
		
		return numeroDeElementos == 0;
	}

	public boolean exclui(E elemento) {
		
		return false;
	}

	public E exclui(int posicao) {
		
		E elementoExcluido = null;
		
		if(estaVazia())
			return null;
		
		if(posicaoLegal(posicao)){
			
			if(posicao == 0){
				elementoExcluido = elemento;
				elemento = resto.elemento;
				this.resto = resto.resto;
				numeroDeElementos--;
			}else{
				numeroDeElementos--;
				return resto.exclui(--posicao);
			}
		}
		
		return elementoExcluido;
	}

	private boolean posicaoLegal(int posicao) {
		
		return posicao >= 0 && posicao < numeroDeElementos;
	}

	public void insere(E elemento) {
		
		if(estaVazia()){
			resto = new ListaRecursiva<E>();
			this.elemento = elemento;
		}else{
			resto.insere(elemento);
		}
		
		numeroDeElementos++;

	}

	public void insere(E elemento, int posicao) {
		
		if(estaVazia() && posicao == 0){
			resto = new ListaRecursiva<E>();
			this.elemento = elemento;
			numeroDeElementos++;
		}else{
			
			if(posicao >= 0 && posicao <= numeroDeElementos){
				if(posicao == 0){
					ListaRecursiva<E> novaLista = new ListaRecursiva<E>();
					
					novaLista.elemento = this.elemento;
					novaLista.resto = this.resto;
					novaLista.numeroDeElementos = this.numeroDeElementos;
					
					this.resto = novaLista;
					this.elemento = elemento;
					numeroDeElementos++;
					
				}else{
					numeroDeElementos++;
					resto.insere(elemento, --posicao);
				}
			}
			
		}
		
		

	}

	public int numeroElementos() {
		
		return numeroDeElementos;
	}

	public E retorna(int posicao) {
		
		if(estaVazia())
			return null;
		
		if(posicaoLegal(posicao)){
			
			if(posicao == 0){
				return this.elemento;
			}else{
				return resto.retorna(--posicao);
			}
		}
		
		return null;
		
	}

	public int retornaPosicao(E elemento) {
		if(estaVazia())
		    return -1;
		
		if(contem(elemento)){
			Integer contador = 0;
			return retornaPosicao(elemento, contador);
		}
		
		return -1;
	}

	private Integer retornaPosicao(E elemento, Integer contador) {
	
		if(this.elemento.equals(elemento))
			return contador;
		
		return resto.retornaPosicao(elemento, ++contador);
	
	}

}
