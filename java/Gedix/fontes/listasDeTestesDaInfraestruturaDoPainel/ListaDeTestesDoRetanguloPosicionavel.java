 package listasDeTestesDaInfraestruturaDoPainel;

public interface ListaDeTestesDoRetanguloPosicionavel extends
				 ListaDeTestesDeUmPosicionavel,
				 ListaDeTestesDoRetangulo{

	public void sabeAsPosiçõesQueOcupaQuandoMudaADimensão();
	
	public void sabeAsPosiçõesQueNãoOcupaQuandoMudaADimensão();
	
}
