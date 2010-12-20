package lista.listasDeTestes.listasDeTestesDasListas;

import ine5384.excecoes.ExcecaoEstruturaCheia;
import ine5384.excecoes.ExcecaoEstruturaVazia;
import ine5384.excecoes.ExcecaoPosicaoIlegal;

public interface ListaDeTestesDaLista {


	public void inserirUmPrimeiroElementoNaPosicaoUm()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;


	public void inserirSegundoElementoNaPosicaoUm()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;


	public void inserirSegundoElementoNoFim() throws ExcecaoEstruturaCheia,
			ExcecaoPosicaoIlegal, ExcecaoEstruturaVazia;


	public void inserirUmElementoNoMeioDaLista() throws ExcecaoEstruturaCheia,
			ExcecaoPosicaoIlegal, ExcecaoEstruturaVazia;

	
	public void seInserirUmElementoEmUmaDeterminadaPosicaoEleFicaraLa()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void seInserirUmElementoEmUmaDeterminadaPosicaoEJaExisteAlguemNelaOsElementosPosterioresSaoMovidosParaCima()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;


	public void seInserirUmElementoNaPosicaoZeroElaEUmaPosicaoInvalida()
			throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia,
			ExcecaoPosicaoIlegal;


	public void sabeQuandoEstaVazia();


	public void sabeQuandoNaoEstaVazia() throws ExcecaoEstruturaCheia,
			ExcecaoPosicaoIlegal;

	
	public void podeRetornarOPrimeiroElementoDaLista()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void sePedirParaRetornarOPrimeiroElementoDeUmaListaVaziaLancaUmaExcecaoEstruturaVazia()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void podeRetornarOUltimoElementoDaLista()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void sePedirParaRetornarOUltimoElementoDeUmaListaVaziaLancaUmaExcecaoEstruturaVazia()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void podeSubstituirUmElementoDaListaPorUmOutroENaoAlteraAQuantidadeDeElementos()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void seSubstituirUmElementoDaListaPorUmOutroEmUmaListaVaziaLancaUmaExcecaoEstruturaVazia()
			throws ExcecaoPosicaoIlegal, ExcecaoEstruturaVazia;

	
	public void seTentarSubstituirUmElementoDaListaEmUmaPosicaoQueNaoExisteLancaUmaExcecaoPosicaoIlegal()
			throws ExcecaoEstruturaVazia, ExcecaoEstruturaCheia,
			ExcecaoPosicaoIlegal;

	
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

	
	public void podeAdcionarUmElementoNoFinalDaListaEEleFicaNoFinalDaLista()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void podeAdcionarUmElementoNoInicioDaListaEEleFicaNoInicioDaLista()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void seAdcionarUmElementoNoInicioDaListaAPosicaoDosOutrosElementosAumenta()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
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

	
	public void aposAdcionarUmElementoNoFinalDaListaAQuantidadeDeElementosAumenta()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void aposAdcionarUmElementoNoInicioDaListaAQuantidadeDeElementosAumenta()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void seInserirUmElementoEmUmaDeterminadaPosicaoAQuantidadeDeElementosAumenta()
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

	
	public void dadoUmElementoNaoPodeRemoverTodasAsOcorrenciasDeleNaListaSeElaEstaVazia()
			throws ExcecaoEstruturaVazia;

	
	public void dadoUmElementoPodeRemoverTodasAsOcorrenciasDeleNaListaEAQuantidadeDeElementosDiminuiDeAcordoComONumeroDeOcorrenciasDoElementoNaLista()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void dadoUmElementoPodeRemoverTodasAsOcorrenciasDeleNaListaEEleNaoPertenceraMaisALista()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void dadoUmElementoPodeRemoverTodasAsOcorrenciasDeleNaListaERetornaUmaListaComOsElementosQueForamRemovidos()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void dadoUmElementoPodeRemoverTodasAsOcorrenciasDeleNaListaSeEleNãoEstaNaListaRetornaUmaListaVazia()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void dadoUmElementoAposRemoverAPrimeiraOcorrenciaDeleNaListaAPosicaoDosOutrosElementosDiminui()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void dadoUmElementoAposRemoverAPrimeiraOcorrenciaDeleNaListaAsOutrasOcorrenciasPermanecem()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void dadoUmElementoNaoPodeRemoverAPrimeiraOcorrenciaDeleNaListaSeElaEstaVazia()
			throws ExcecaoEstruturaVazia;

	
	public void dadoUmElementoPodeRemoverAPrimeiraOcorrenciaDeleNaLista()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void dadoUmElementoPodeRemoverAPrimeiraOcorrenciaDeleNaListaERetornaOProprioElementoRemovido()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void dadoUmElementoPodeRemoverAPrimeiraOcorrenciaDeleNaListaSeEleNaoEstaNaListaRetornaNull()
			throws ExcecaoEstruturaVazia, ExcecaoEstruturaCheia,
			ExcecaoPosicaoIlegal;

	
	public void dadoUmElementoSeRemoverAPrimeiraOcorrenciaDeleNaListaAQuantidadeDeElementosNaListaDiminui()
			throws ExcecaoEstruturaVazia, ExcecaoEstruturaCheia,
			ExcecaoPosicaoIlegal;

	
	public void dadoUmElementoNaoPodeSubstituirOUltimoElementoDaListaPorEsteSeAListaEstaVazia()
			throws ExcecaoEstruturaVazia;

	
	public void dadoUmElementoPodeSubstituirOUltimoElementoDaListaPorEste()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void dadoUmElementoSeSubstituirOUltimoElementoDaListaPorEsteAQuantidadeDeElementosNaoEAlterada()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void dadoUmElementoNaoPodeSubstituirOPrimeiroElementoDaListaPorEsteSeAListaEstaVazia()
			throws ExcecaoEstruturaVazia;

	
	public void dadoUmElementoPodeSubstituirOPrimeiroElementoDaListaPorEste()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void dadoUmElementoSeSubstituirOPrimeiroElementoDaListaPorEsteAQuantidadeDeElementosNaoEAlterada()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void dadoUmElementoPodeRemoverTodasAsOcorrenciasDeleNaListaERetornaUmaListaComOsElementosQueForamRemovidosComOTamanhoMaximoIgualAoDaListaQueARetornou()
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

	
	public void seInserirUmElementEmUmaPosicaoMaiorQueAUltimaPosicaoLivreElaEUmaPosicaooInvalida()
			throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia,
			ExcecaoPosicaoIlegal;

	
	public void seInserirUmElementEmUmaPosicaoMenorZeroElaEUmaPosicaoInvalida()
			throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia,
			ExcecaoPosicaoIlegal;

	
	public void seTentarObterUmElementoAPartirDaPosicaoZeroLancaUmaExcecaoPosicaoIlegal()
			throws ExcecaoEstruturaVazia, ExcecaoEstruturaCheia,
			ExcecaoPosicaoIlegal;

	
	public void seTentarObterUmElementoAPartirDeUmaPosicaoMenorQueZeroLancaUmaExcecaoPosicaoIlegal()
			throws ExcecaoEstruturaVazia, ExcecaoEstruturaCheia,
			ExcecaoPosicaoIlegal;

	
	public void dadoAPosicaoZeroNaoRemoveOElementoQueSeEncontraLaSeAPosicaoEMenorQueZero()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;

	
	public void dadoAPosicaoZeroNaoRemoveOElementoQueSeEncontraLaSeAPosicaoEZero()
			throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal,
			ExcecaoEstruturaVazia;
	
	
	public void duasListasSaoIguaisSeTodosSeusElementosSaoIguaisEEstaoNaMesmaOrdem() throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal;
	
	
	public void duasListasNaoSaoIguaisSeTodosSeusElementosSaoIguaisMasNaoEstaoNaMesmaOrdem() throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal;
	
	
	public void duasListasNaoSaoIguaisSeNaoPossuemAMesmaQuantidadeDeElementos() throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal;
	
	
	public void duasListasVaziasSaoIguais();

}