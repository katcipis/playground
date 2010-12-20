package listasDeTestesDaInfraestruturaDoPainel;

public interface ListaDeTestesDeUmPosicionavel {

	public void inicialmenteAPosiçãoDeOrigemÉZeroEZero();
	
	public void dadaUmaPosiçãoElaSeTornaANovaPosiçãoDeOrigem();
	
	public void sabeAsPosiçõesQueOcupa();
	
	public void sabeAsPosiçõesQueNãoOcupa();
	
	public void sabeAsPosiçõesQueOcupaQuandoMudaAPosiçãoDeOrigem();
	
	public void sabeAsPosiçõesQueNãoOcupaQuandoMudaAPosiçãoDeOrigem();
	
}
