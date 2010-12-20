package lista.listasDeTestes.listasDeTestesDasListasOrdenadas;

import ine5384.excecoes.ExcecaoEstruturaCheia;

public interface ListaDeTestesDaListaOrdenadaArray {

	public void sabeQuandoEstaCheia() throws ExcecaoEstruturaCheia;
	
	public void seNaoForInformadoUmTamanhoSeuTamanhoSeraDez() throws ExcecaoEstruturaCheia;
	
	public void sabeQuandoNaoEstaCheia() throws ExcecaoEstruturaCheia;
	
	public void podeTerOTamanhoQueForPedido() throws ExcecaoEstruturaCheia;
	
	public void seTentarExcederOTamanhoMaximoGeraUmaExcecao() throws ExcecaoEstruturaCheia;
}
