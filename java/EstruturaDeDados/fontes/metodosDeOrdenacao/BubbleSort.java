package metodosDeOrdenacao;

public class BubbleSort extends MetodoOrdenacaoAbstrato{

	private static BubbleSort eu;
	
	
	private BubbleSort(){ }
	
	@SuppressWarnings("unchecked")
	@Override
	public void ordena(Comparable[] array) {
		
		tamanhoDoArray = this.normalizarArray(array);
		
		for(int i = 0; i < (tamanhoDoArray - 1); i++){
			for(int k = (tamanhoDoArray - 1); k > i; k--){
				if(array[k].compareTo(array[k-1]) < 0)
					this.trocarElementosDePosicao(array, k, (k-1));
			}
		}
		
	}
	

	public static BubbleSort retorneSort(){
		if(eu == null)
			eu = new BubbleSort();
		
		return eu;
	}

}
