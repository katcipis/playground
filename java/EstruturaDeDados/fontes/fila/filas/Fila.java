package fila.filas;

import ine5384.excecoes.ExcecaoEstruturaCheia;
import ine5384.excecoes.ExcecaoEstruturaVazia;

public interface Fila<T> {
	
	public T remove() throws ExcecaoEstruturaVazia;

	public void insere(T elemento) throws ExcecaoEstruturaCheia;

	public T retorneInicio() throws ExcecaoEstruturaVazia;
	
	public boolean estaVazia();
	
	public boolean estaCheia();

}
