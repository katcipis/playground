package infraEstrutura;


public class Ponteiro<T extends Comparable<T>> implements Comparable<Ponteiro<T>>{

	private final T elemento;
	private final long localizacao;

	public Ponteiro(T nome, long localizacao){
		this.elemento = nome;
		this.localizacao = localizacao;
	}
	
	public int compareTo(Ponteiro<T> o) {
		return this.elemento.compareTo(o.elemento);
	}
	
	public long localizacao(){
		return localizacao;
	}
	
	public T elemento(){
		return elemento;
	}
	
	@SuppressWarnings("unchecked")
	public boolean equals(Object o){
		if(!(o instanceof Ponteiro))
			return false;
		
		return this.elemento.equals(((Ponteiro<T>) o).elemento());
	}

}
