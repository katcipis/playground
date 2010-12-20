package pilha;

import ine5384.excecoes.ExcecaoEstruturaCheia;
import ine5384.excecoes.ExcecaoEstruturaVazia;

public interface Pilha<T> {

	public T desempilhe() throws ExcecaoEstruturaVazia;

	public void empilhe(T elemento) throws ExcecaoEstruturaCheia;

	public T retorneTopo() throws ExcecaoEstruturaVazia;
	
	public boolean estaVazia();
	
	public boolean estaCheia();
	
	public Integer tamanho();
}
