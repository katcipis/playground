package metodosDeOrdenacao;

public class HeapSort extends MetodoOrdenacaoAbstrato{

	private static HeapSort eu;
	private final Integer RAIZ;
	
	private HeapSort(){ 
		RAIZ = 1;
	}
	
	@SuppressWarnings("unchecked")
	@Override
	public void ordena(Comparable[] array) {
		this.tamanhoDoArray = this.normalizarArray(array);
		
		this.fazerHeap(array, tamanhoDoArray);
	}

	@SuppressWarnings("unchecked")
	private void fazerHeap(Comparable[] array, Integer fim) {
		
		Integer tamanho = fim - RAIZ;
		
		if(tamanho > 1){
			
			tamanho++;
			
			Integer nodoASerAnalisado = tamanho / 2;
			
			while(nodoASerAnalisado >= RAIZ){
				this.ordenar(array, nodoASerAnalisado, fim);
				nodoASerAnalisado--;
			}
			
			this.trocarElementosDePosicao(array, (RAIZ - 1), (fim - 1));
		
			this.fazerHeap(array, (fim - 1));
			
		}else{
			if(tamanho.equals(1)){
				if(array[(RAIZ -1)].compareTo(array[(fim - 1)]) > 0)
					this.trocarElementosDePosicao(array, (RAIZ - 1), (fim - 1));
			}
		}
		
	}

	@SuppressWarnings("unchecked")
	private void ordenar(Comparable[] array, Integer nodoASerAnalisado, Integer limite) {
		
		Integer filhoUm = 2 * nodoASerAnalisado;
		Integer filhoDois = filhoUm + 1;
		
		
		if(filhoUm <= limite){
			if(array[filhoUm - 1] != null){
				if(array[nodoASerAnalisado - 1].compareTo(array[filhoUm - 1]) < 0){
					this.trocarElementosDePosicao(array, nodoASerAnalisado - 1, filhoUm - 1);
					this.ordenar(array, filhoUm, limite);
				}
			}
		}
		
		
		if(filhoDois <= limite){
			if(array[filhoDois - 1] != null){
				if(array[nodoASerAnalisado - 1].compareTo(array[filhoDois - 1]) < 0){
					this.trocarElementosDePosicao(array, nodoASerAnalisado - 1, filhoDois - 1);
					this.ordenar(array, filhoDois, limite);
				}
			}
		}
		
		
	}

	public static HeapSort retorneSort(){
		if(eu == null)
			eu = new HeapSort();
		
		return eu;
	}
}
