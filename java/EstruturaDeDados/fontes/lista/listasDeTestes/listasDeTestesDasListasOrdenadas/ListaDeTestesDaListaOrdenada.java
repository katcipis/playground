package lista.listasDeTestes.listasDeTestesDasListasOrdenadas;

import ine5384.excecoes.ExcecaoEstruturaCheia;
import ine5384.excecoes.ExcecaoEstruturaVazia;
import ine5384.excecoes.ExcecaoPosicaoIlegal;

public interface ListaDeTestesDaListaOrdenada {

	
	
	public void aposInserirUmElementoSabeQueElePertenceALista()
			throws ExcecaoEstruturaCheia;

	
	public void sabeQuandoEstaVazia();

	
	public void inserirUmElementoNaListaVazia() throws ExcecaoEstruturaCheia,
			ExcecaoEstruturaVazia, ExcecaoPosicaoIlegal;

	
	public void inserirUmElementoNaListaQueJaPossuiUmElemento()
			throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia,
			ExcecaoPosicaoIlegal;

	
	public void naoImportaAOrdemQueSaoInseridosOsElementosFicamEmOrdenadosEmOrdemCrescenteNaListaComUmElemento()
			throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia,
			ExcecaoPosicaoIlegal;

	
	public void naoImportaAOrdemQueSaoInseridosOsElementosFicamEmOrdenadosEmOrdemCrescenteNaListaComMaisDeUmElemento()
			throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia,
			ExcecaoPosicaoIlegal;

	
	public void seOElementoQueEstaSendoInseridoEIgualAUmJaExistenteNaListaEleFicaraAntesDoQueJaEstaNaLista()
			throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia,
			ExcecaoPosicaoIlegal;

	
	public void sabeQuandoNaoEstaVazia() throws ExcecaoEstruturaCheia,
			ExcecaoPosicaoIlegal;

	
	public void podeRetornarOPrimeiroElementoDaLista()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void podeRetornarOUltimoElementoDaLista()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void sePedirParaRetornarOPrimeiroElementoDeUmaListaVaziaLancaUmaExcecaoEstruturaVazia()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void sePedirParaRetornarOUltimoElementoDeUmaListaVaziaLancaUmaExcecaoEstruturaVazia()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void sabeOSeuTamanho() throws ExcecaoEstruturaCheia,
			ExcecaoPosicaoIlegal;

	
	public void sabeQualNaoEOSeuTamanho() throws ExcecaoEstruturaCheia,
			ExcecaoPosicaoIlegal;

	
	public void podeObterUmElementoAPartirDaSuaPosicao()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void seTentarObterUmElementoAPartirDaSuaPosicaoDeUmaListaVaziaLancaUmaExcecaoEstruturaVazia()
			throws ExcecaoPosicaoIlegal, ExcecaoEstruturaVazia;

	
	public void seTentarObterUmElementoAPartirDeUmaPosicaoMaiorQueDoUltimoElementoLancaUmaExcecaoPosicaoIlegal()
			throws ExcecaoEstruturaVazia, ExcecaoEstruturaCheia,
			ExcecaoPosicaoIlegal;

	
	public void podeVerificarSeUmElementoPertenceOuNaoALista()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal;


	public void dadoUmaPosicaoNaoRemoveOElementoQueSeEncontraLaSeAListaEstaVazia()
			throws ExcecaoPosicaoIlegal, ExcecaoEstruturaVazia;

	
	public void dadoUmaPosicaoNaoRemoveOElementoQueSeEncontraLaSeAPosicaoEMaiorQueADoUltimoElemento()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void dadoUmaPosicaoPodeRemoverOElementoDaListaQueSeEncontraNessaPosicao()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void dadoUmaPosicaoSeRemoverOElementoDaListaQueSeEncontraNessaPosicaoAPosicaoDosOutrosElementosDiminui()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void dadoUmaPosicaoSeRemoverOElementoDaListaQueSeEncontraNessaPosicaoAQuantidadeDeElementosDiminui()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void depoisQueRemoverOElementoQueSeEncontraNoFimDaListaAListaDiminuiDeTamanho()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void naoPodeRemoverOElementoQueSeEncontraNoFimDaListaSeElaEstaVazia()
			throws ExcecaoEstruturaVazia;

	
	public void podeRemoverOElementoQueSeEncontraNoFimDaLista()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void quandoRemoverOElementoQueSeEncontraNoFimDaListaRetornaOElementoQueFoiRemovido()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void depoisQueRemoverOElementoQueSeEncontraNoInicioDaListaAListaDiminuiDeTamanho()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void depoisQueRemoverOElementoQueSeEncontraNoInicioDaListaAPosicaoDosOutrosElementosDiminui()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void naoPodeRemoverOElementoQueSeEncontraNoInicioDaListaSeElaEstaVazia()
			throws ExcecaoEstruturaVazia;

	
	public void podeRemoverOElementoQueSeEncontraNoInicioDaLista()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void quandoRemoverOElementoQueSeEncontraNoInicioDaListaRetornaOElementoQueFoiRemovido()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void dadoUmElementoPodeRetornarUmaListaComTodosOsDadosQueSaoIguaisAEsseElemento()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal;

	
	public void dadoUmElementoRetornaUmaListaVaziaSeNaoExisteOcorrenciaDesseElementoNaLista()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal;

	
	public void dadoUmElementoPodeRetornarAPrimeiraOcorrenciaDesseDadoNaLista()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal;

	
	public void dadoUmElementoPodeRetornarAPrimeiraOcorrenciaDesseDadoNaListaSeNaoHouverOcorrenciaDeleRetornaNull()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal;

	
	public void podeEsvaziarAListaEElaNaoConteraMaisNenhumElementoESeuTamanhoSeraZero()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void verificarSeTemIgualEmUmaListaComUmElemento()
			throws ExcecaoEstruturaCheia;

	
	public void verificarSeTemIguaisEmUmaListaComUmElemento()
			throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia;

	
	public void retorneDoFimEmUmaListaComUmElemento()
			throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia;

	
	public void retorneDoInicioEmUmaListaComUmElemento()
			throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia;

	
	public void retorneDaPosicaoEmUmaListaComUmElemento()
			throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia,
			ExcecaoPosicaoIlegal;

	
	public void removaDoFimEmUmaListaComUmElemento()
			throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia,
			ExcecaoPosicaoIlegal;

	
	public void removaDoInicioEmUmaListaComUmElemento()
			throws ExcecaoEstruturaVazia, ExcecaoEstruturaCheia;

	
	public void removaDaPosicaoEmUmaListaComUmElemento()
			throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia,
			ExcecaoPosicaoIlegal;

	
	public void pertenceAListaComUmElemento() throws ExcecaoEstruturaCheia;

	
	public void duasListasSaoIguaisSeTodosSeusElementosSaoIguais() throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal;
	
	
	public void duasListasNaoSaoIguaisSeNaoPossuemAMesmaQuantidadeDeElementos() throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal;
	
	
	public void duasListasVaziasSaoIguais();
}