package fila.testes.listasDeTestesDasFilas;

import ine5384.excecoes.ExcecaoEstruturaCheia;

public interface ListaDeTestesDaFilaArray {
	

	public void seNaoForInformadoOTamanhoOTamanhoSeraDez()
			throws ExcecaoEstruturaCheia;

	
	public void podeTerOTamanhoEspecificado() throws ExcecaoEstruturaCheia;


	public void seExcederOTamanhoEspecificadoLancaUmaExcecaoDeEstruturaCheia()
			throws ExcecaoEstruturaCheia;

}
