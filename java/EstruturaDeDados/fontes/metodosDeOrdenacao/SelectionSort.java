package metodosDeOrdenacao;

public class SelectionSort extends MetodoOrdenacaoAbstrato{

	private static SelectionSort eu;
	
	private SelectionSort(){ }
	
	@SuppressWarnings("unchecked")
	@Override
	public void ordena(Comparable[] array) {
		
		tamanhoDoArray = this.normalizarArray(array);
		
		for(int i = 0; i < (tamanhoDoArray - 1); i++){
			Integer posDoMenorElemento = this.buscarPosicaoDoMenorElementoNoIntervalo(array, i, (tamanhoDoArray - 1));
			this.trocarElementosDePosicao(array, i, posDoMenorElemento);
		}
		
	}
	
	public static SelectionSort retorneSort(){
		if(eu == null)
			eu = new SelectionSort();
		
		return eu;
	}

	
	
	@SuppressWarnings("unchecked")
	private Integer buscarPosicaoDoMenorElementoNoIntervalo(Comparable[] array, Integer inicio, Integer fim){
		
		if(array[inicio] != null && array[fim] != null){
			
			Integer menorElemento = inicio;
			
			for(int i = inicio; i <= fim; i++){
				if(array[i].compareTo(array[menorElemento]) < 0)
					menorElemento = i;
			}
			
			return menorElemento;
			
		}
		
		return null;
	}

}
