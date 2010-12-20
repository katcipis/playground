package fila.filas;

import ine5384.excecoes.ExcecaoEstruturaVazia;

public abstract class FilaAbstrata<T> implements Fila<T> {
	
	protected Integer numeroDeElementos;
	
	public FilaAbstrata(){
		numeroDeElementos = 0;
       
	}
	
	public boolean estaVazia() {

		return numeroDeElementos == 0;
	}
	
	@SuppressWarnings("unchecked")
	@Override
	public boolean equals(Object o) {

		if (o instanceof Fila) {
			Fila outraFila = (Fila) o;
			boolean naoEsvaziouAPilha = true;
			do {
				try {
					if (!this.remove().equals(outraFila.remove()))
						return false;

				} catch (ExcecaoEstruturaVazia e) {
					if (this.estaVazia() && outraFila.estaVazia())
						return true;
					return false;
				}
			} while (naoEsvaziouAPilha);
		}

		return false;
	}
}
