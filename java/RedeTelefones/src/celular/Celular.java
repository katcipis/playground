package celular;

import servidor.EstacaoBase;

public interface Celular {
	
	public boolean estaOcupado();
	
	public boolean estaDesligado();

	public void desligar();
	
	public void ligar();
	
	public boolean fazerLigacao(Integer numeroDesejado);
	
	public void encerrarLigacao();
	
	public boolean enviarMensagem(Integer numeroDesejado, String msg);
	
	public void receberLigacao(Celular cel);
	
	public void receberMensagem(Celular cel, String msg);
	
	public Integer obterNumero();
	
	public boolean possuiMensagensNaoLidas();
	
	public void lerMensagens();
	
	public Integer obterPosicao();
	
	public void mover();
	
	public EstacaoBase obterEstacao();
}
