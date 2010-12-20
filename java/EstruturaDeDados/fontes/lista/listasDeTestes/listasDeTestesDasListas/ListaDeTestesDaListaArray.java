package lista.listasDeTestes.listasDeTestesDasListas;

import ine5384.excecoes.ExcecaoEstruturaCheia;
import ine5384.excecoes.ExcecaoEstruturaVazia;
import ine5384.excecoes.ExcecaoPosicaoIlegal;

public interface ListaDeTestesDaListaArray {

	
	public void seInserirUmElementoEmUmaListaCheiaLancaExcecaoDeEstruturaCheia()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal;

	
	public void sabeQuandoEstaCheia() throws ExcecaoEstruturaCheia,
			ExcecaoPosicaoIlegal;


	public void sabeQuandoNaoEstaCheia() throws ExcecaoEstruturaCheia,
			ExcecaoPosicaoIlegal;


	public void naoPodeAdcionarUmElementoNoFinalDaListaSeElaEstaCheia()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal;


	public void naoPodeAdcionarUmElementoNoInicioDaListaSeAListaEstaCheia()
			throws ExcecaoPosicaoIlegal, ExcecaoEstruturaVazia,
			ExcecaoEstruturaCheia;


	public void seNaoForPassadoUmTamanhoMaximoParaAListaSeuTamanhoMaximoSeraDez()
			throws ExcecaoPosicaoIlegal, ExcecaoEstruturaCheia;


	public void seForPassadoUmTamanhoMaximoParaAListaSeuTamanhoMaximoSeraOTamanhoPassado()
			throws ExcecaoEstruturaCheia;


	public void seExcederAoSeuTamanhoMaximoLancaUmaExcecaoDeEstruturaCheia()
			throws ExcecaoPosicaoIlegal, ExcecaoEstruturaCheia;

}