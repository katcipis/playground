package lista.testes.testesDosIteradoresDasListas;

import ine5384.excecoes.ExcecaoEstruturaVazia;
import ine5384.excecoes.ExcecaoOperacaoIlegal;
import ine5384.excecoes.ExcecaoPosicaoIlegal;

public interface ListaDeTestesDoIterador {


	
	public void primeiroElementoDoIteradorEquivaleAoPrimeiroDaLista()
			throws ExcecaoEstruturaVazia, ExcecaoPosicaoIlegal,
			ExcecaoOperacaoIlegal;

	
	public void segundoElementoDoIteradorEquivaleAoSegundoDaLista()
			throws ExcecaoEstruturaVazia, ExcecaoPosicaoIlegal,
			ExcecaoOperacaoIlegal;

	
	public void terceiroElementoDoIteradorEquivaleAoTerceiroDaLista()
			throws ExcecaoEstruturaVazia, ExcecaoPosicaoIlegal,
			ExcecaoOperacaoIlegal;

	
	public void quartoElementoDoIteradorEquivaleAoQuartoDaLista()
			throws ExcecaoEstruturaVazia, ExcecaoPosicaoIlegal,
			ExcecaoOperacaoIlegal;

	
	public void quintoElementoDoIteradorEquivaleAoQuintoDaLista()
			throws ExcecaoEstruturaVazia, ExcecaoPosicaoIlegal,
			ExcecaoOperacaoIlegal;


	public void seTentarRetornarUmProximoQueNaoExisteLancaUmaExcecaoOperacaoIlegal()
			throws ExcecaoOperacaoIlegal;

	
	public void sabeDizerSePossuiUmProximo() throws ExcecaoOperacaoIlegal;

}