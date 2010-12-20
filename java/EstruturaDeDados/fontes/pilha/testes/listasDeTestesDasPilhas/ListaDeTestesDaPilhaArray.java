package pilha.testes.listasDeTestesDasPilhas;

import ine5384.excecoes.ExcecaoEstruturaCheia;

public interface ListaDeTestesDaPilhaArray {


	public void seNaoForInformadoOTamanhoOTamanhoSeraDez()
			throws ExcecaoEstruturaCheia;


	public void podeTerOTamanhoEspecificado() throws ExcecaoEstruturaCheia;

	
	public void seExcederOTamanhoEspecificadoLancaUmaExcecaoDeEstruturaCheia()
			throws ExcecaoEstruturaCheia;

}