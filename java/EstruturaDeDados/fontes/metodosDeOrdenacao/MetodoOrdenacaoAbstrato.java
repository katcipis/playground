package metodosDeOrdenacao;

public abstract class MetodoOrdenacaoAbstrato extends MetodoOrdenacao{

	protected Integer tamanhoDoArray;

	@SuppressWarnings("unchecked")
	protected Integer normalizarArray(Comparable[] array) {

		Integer numeroDeElementos = 0;

		for (int i = 0; i <= (array.length - 1); i++) {

			if (array[i] != null) {

				numeroDeElementos++;

			} else {

				Integer pos = this.encontrarPosDoProxElemValido(array, i);

				if (pos != null) {
					array[i] = array[pos];
					array[pos] = null;
					numeroDeElementos++;
				} else {

					i = array.length;
				}

			}

		}

		return numeroDeElementos;
	}

	@SuppressWarnings("unchecked")
	private Integer encontrarPosDoProxElemValido(Comparable[] array,
			Integer posInic) {
		for (int i = posInic; i <= (array.length - 1); i++) {
			if (array[i] != null)
				return i;
		}
		return null;
	}
	
	@SuppressWarnings("unchecked")
	protected void trocarElementosDePosicao(Comparable[] array, Integer posUm, Integer posDois){
		
		if(array[posUm] != null && array[posDois] != null){
			
			Comparable a = array[posUm];
			array[posUm] = array[posDois];
			array[posDois] = a;
			
		}
	}

}
