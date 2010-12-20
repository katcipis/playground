package metodosDeOrdenacao;

public class MergeSort extends MetodoOrdenacaoAbstrato{

	private static MergeSort eu;
	
	private MergeSort(){ }
	
	@SuppressWarnings("unchecked")
	@Override
	public void ordena(Comparable[] array) {
		
		this.tamanhoDoArray = this.normalizarArray(array);
		
		this.dividirArray(array, 1, tamanhoDoArray);
		
	}

	@SuppressWarnings("unchecked")
	private void dividirArray(Comparable[] array, Integer inicio, Integer fim) {
		
		Integer meio = (fim - inicio);
	
		if(meio > 1){
			meio = meio / 2;
			meio = meio + inicio;
			
			this.dividirArray(array, inicio, meio);
			this.dividirArray(array, (meio + 1), fim);
			
			this.juntar(array, inicio, meio, (meio + 1), fim);
			
		}else{
			
			if(meio.equals(1)){
			
				if(array[inicio -1].compareTo(array[fim - 1]) > 0){
					this.trocarElementosDePosicao(array, (inicio - 1), (fim - 1));
				}
			}
		}
			
	}

	@SuppressWarnings("unchecked")
	private void juntar(Comparable[] array, Integer inicioEsq, Integer fimEsq, 
			            Integer inicioDir, Integer fimDir) {
		 
		Integer indiceEsq = inicioEsq; 
		Integer indiceDir = inicioDir;
		
		Integer tamanhoEsq = (fimEsq - inicioEsq) + 1;
		Integer tamanhoDir = (fimDir - inicioDir) + 1;
		
		Comparable[] arrayTemp = new Comparable[tamanhoEsq + tamanhoDir];
		Integer indiceArrayTemp = 0;
		
		
		while(indiceEsq <= fimEsq && 
			  indiceDir <= fimDir){
			
			if(array[(indiceEsq - 1)].compareTo(array[(indiceDir - 1)]) <= 0){
				arrayTemp[indiceArrayTemp] = array[(indiceEsq - 1)];
				indiceEsq++;
				indiceArrayTemp++;
			}else{
				arrayTemp[indiceArrayTemp] = array[(indiceDir - 1)];
				indiceDir++;
				indiceArrayTemp++;
			}
		}
		
		
		if(indiceEsq <= fimEsq){
			while(indiceEsq <= fimEsq){
				arrayTemp[indiceArrayTemp] = array[(indiceEsq - 1)];
				indiceEsq++;
				indiceArrayTemp++;
			}
		}else{
			while(indiceDir <= fimDir){
				arrayTemp[indiceArrayTemp] = array[(indiceDir - 1)];
				indiceDir++;
				indiceArrayTemp++;
			}
		}
		
		Integer posArray = inicioEsq;
		
		for(int i = 0; i < indiceArrayTemp; i++){
			
			array[(posArray - 1)] = arrayTemp[i];
			posArray++;
		}
	}

	public static MergeSort retorneSort(){
		if(eu == null)
			eu = new MergeSort();
		
		return eu;
	}
	
}
