package pilha.testes.listasDeTestesDasPilhas;

import ine5384.excecoes.ExcecaoEstruturaCheia;
import ine5384.excecoes.ExcecaoEstruturaVazia;

public interface ListaDeTestesDaPilha {

	
	public void inserindoUmElementoEmUmaPilhaVazia()
			throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia;

	
	public void inserindoUmElementoEmUmaPilhaComUmElementoOElementoInseridoFicaNoTopo()
			throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia;

	
	public void elementosInseridosSempreFicamNoTopo()
			throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia;

	
	public void podeRemoverOElementoQueSeEncontraNoTopoEOTopoSeraOAntecessorDoTopo()
			throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia;

	
	public void seDesempilharDeUmaPilhaVaziaLancaUmaExcecaoEstruturaVazia()
			throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia;

	
	public void seRetornarDoTopoDeUmaPilhaVaziaLancaUmaExcecaoEstruturaVazia()
			throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia;

	
	public void duasPilhasComOsMesmosElementosEmpilhadosNaMesmaOrdemSaoIguais()
			throws ExcecaoEstruturaCheia;

	
	public void duasPilhasVaziasSaoIguais() throws ExcecaoEstruturaCheia;

	
	public void duasPilhasComOsMesmosElementosEmpilhadosNaMesmaOrdemNaoSaoIguaisSeAOutraPossuiMaisElementos()
			throws ExcecaoEstruturaCheia;

}