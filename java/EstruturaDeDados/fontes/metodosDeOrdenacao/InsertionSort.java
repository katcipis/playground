package metodosDeOrdenacao;

public class InsertionSort extends MetodoOrdenacaoAbstrato{

	private static InsertionSort eu;
	
	private InsertionSort(){ }
	
	@SuppressWarnings("unchecked")
	@Override
	public void ordena(Comparable[] array) {
		
		tamanhoDoArray = this.normalizarArray(array);
		
		for(int i = 1; i < tamanhoDoArray; i++){
			
			this.inserirNaParteOrdenada(array, array[i], (i - 1));
			
		}
		
	
	
	}
	
	@SuppressWarnings("unchecked")
	private void inserirNaParteOrdenada(Comparable[] array,
										Comparable dado,
										Integer fim){
		if(fim < (tamanhoDoArray - 1)){
			
			for(int i = 0; i <= fim; i++){
				
				if(dado.compareTo(array[i]) < 0){
					
					for(int k = fim + 1; k > i; k--){
						array[k] = array[k - 1];
					}
					
					array[i] = dado;
					i = tamanhoDoArray;
				}
			}
		}
	}
	
	public static InsertionSort retorneSort(){
		if(eu == null)
			eu = new InsertionSort();
		
		return eu;
	}

}
