package celular;

import servidor.EstacaoBase;

public class CelularNulo extends Thread implements Celular{

	@Override
	public boolean equals(Object o){
		return (o instanceof CelularNulo);
	}
	
	public void desligar() { }

	public void encerrarLigacao() { }

	public boolean enviarMensagem(Integer numeroDesejado, String msg) {
		return false;
	}

	public boolean estaDesligado() {
		return true;
	}

	public boolean estaOcupado() {
		return true;
	}

	public boolean fazerLigacao(Integer numeroDesejado) {
		return false;
	}

	public void lerMensagens() {

	}

	public void ligar() {
		
	}
	
	public void mover() {
		
	}

	public Integer obterNumero() {
		return 0;
	}

	public Integer obterPosicao() {
		return 0;
	}

	public boolean possuiMensagensNaoLidas() {
		return false;
	}

	public void receberLigacao(Celular cel) {
		
	}

	public void receberMensagem(Celular cel, String msg) {
		
	}

	public EstacaoBase obterEstacao() {
		return null;
	}

}
