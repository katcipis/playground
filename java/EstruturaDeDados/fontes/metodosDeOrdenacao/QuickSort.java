package metodosDeOrdenacao;

public class QuickSort extends MetodoOrdenacaoAbstrato{

	private static QuickSort eu;
	
	private QuickSort(){ }
	
	 @SuppressWarnings("unchecked")
	public void ordena(Comparable[] array) {
	       this.tamanhoDoArray = this.normalizarArray(array);

	       this.sort(array, 0, tamanhoDoArray-1);

	   }

	   @SuppressWarnings("unchecked")
	   private void sort(Comparable[] array, Integer inicio, Integer fim) {

	       Integer tamanho = (fim - inicio);

	       if(tamanho > 1){

	           Integer indiceEsq = inicio;
	           Integer indiceDir = fim - 1;
	           Comparable elemEscolhido = array[fim];

	           while(indiceEsq <= indiceDir){

	               if(array[indiceEsq].compareTo(elemEscolhido) > 0){

	                   boolean naoAchou = true;

	                   while((indiceEsq <= indiceDir) && naoAchou){

	                       if(array[indiceDir].compareTo(elemEscolhido) < 0){
	                           this.trocarElementosDePosicao(array,
	indiceEsq, indiceDir);
	                           naoAchou = false;
	                           indiceEsq++;
	                           indiceDir--;
	                       }else{
	                           indiceDir--;
	                       }

	                   }


	               }else{
	                   indiceEsq++;
	               }

	           }


	           this.trocarElementosDePosicao(array,indiceEsq,fim);

	           this.sort(array, inicio, (indiceEsq - 1));
	           this.sort(array, (indiceEsq + 1), fim);



	       }else{

	           if(tamanho.equals(1)){

	               if(array[(inicio -1)].compareTo(array[(fim - 1)]) > 0)
	                   this.trocarElementosDePosicao(array, (inicio - 1),(fim - 1));
	           
	}
  }	     
}
	public static QuickSort retorneSort(){
		if(eu == null)
			eu = new QuickSort();
		
		return eu;
	}
	
}
