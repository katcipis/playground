package fila.testes.listasDeTestesDasFilas;

import ine5384.excecoes.ExcecaoEstruturaCheia;
import ine5384.excecoes.ExcecaoEstruturaVazia;

public interface ListaDeTestesDaFila {

	
	public void inserindoUmElementoEmUmaFilaVazia()
			throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia;

	
	public void inserindoUmElementoEmUmaFilaComUmElementoOPrimeiroElementoInseridoFicaNoInicio()
			throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia;

	
	public void elementosInseridosSempreFicamNoFim()
			throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia;

	
	public void oPrimeiroASerColocadoNaFilaSeraOPrimeiroASairDaFila()
			throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia;


	public void seRemoverDeUmaFilaVaziaLancaUmaExcecaoEstruturaVazia()
			throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia;


	public void seRetornarDoInicioDeUmaFilaVaziaLancaUmaExcecaoEstruturaVazia()
			throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia;

	
	public void duasFilasComOsMesmosElementosNaMesmaOrdemSaoIguais()
			throws ExcecaoEstruturaCheia;

	
	public void duasFilasVaziasSaoIguais() throws ExcecaoEstruturaCheia;

	
	public void duasFilasComOsMesmosElementosNaMesmaOrdemNaoSaoIguaisSeAOutraPossuiMaisElementos()
			throws ExcecaoEstruturaCheia;
}
