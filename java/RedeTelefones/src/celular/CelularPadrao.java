package celular;

import java.util.LinkedList;
import java.util.List;

import servidor.EstacaoBase;
import servidor.ServidorCentral;


public class CelularPadrao extends Thread implements Celular{

	private Integer numeroCelular;
	private Integer posicao;
	private boolean ligado;
	private boolean ocupado;
	private List<Mensagem> msgs;
	private EstacaoBase estacao;
	private ServidorCentral servidor;
	private Integer posLimite;
	
	public CelularPadrao(Integer numeroCel){
		numeroCelular = numeroCel;
		ligado = true;
		ocupado = false;
		msgs = new LinkedList<Mensagem>();
		posicao = 0;
		posLimite = ServidorCentral.limite;
		servidor = ServidorCentral.obterServidor();
		procurarEstacaoBase();
	}
	
	private void procurarEstacaoBase() {
		estacao = servidor.obterEstacao(posicao);
	  estacao.inserirCelular(this);
	}

	public void desligar() {
		ligado = false;
	}

	public boolean enviarMensagem(Integer numeroDesejado, String msg) {

		return false;
	}

	public boolean estaDesligado() {
		return !ligado;
	}

	public boolean estaOcupado() {
		return ocupado;
	}

	public boolean fazerLigacao(Integer numeroDesejado) {
		ocupado = true;
		
		return false;
	}

	public void ligar() {
		ligado = true;
	}

	public synchronized void receberLigacao(Celular cel) {
		ocupado = true;
	}

	public synchronized void receberMensagem(Celular cel, String msg) {
     msgs.add(new Mensagem(cel.obterNumero(), msg));
	}
	
	public Integer obterNumero(){
		return numeroCelular;
	}

	public void encerrarLigacao() {
		ocupado = false;
	}

	public boolean possuiMensagensNaoLidas() {
		for(Mensagem m : msgs){
			if(!m.foiLida())
				return true;
		}
		return false;
	}

	public void lerMensagens() {
		
		for(Mensagem m : msgs)
			System.out.println( "Celular numero " +
					                m.obterRemetente().toString() +
					                " enviou a mensagem: " +
			   	                m.obterTexto());
		
		
	}

	public void mover() {
		if(posicao < posLimite)
			posicao++;
		else
			posicao = 0;
		
		atualizarEstacaoBase();
	}

	private void atualizarEstacaoBase() {
		estacao.removerCelular(this);
		procurarEstacaoBase();
	}

	public Integer obterPosicao() {
		return posicao;
	}

	public EstacaoBase obterEstacao() {
		return estacao;
	}
	
	@Override
	public boolean equals(Object e){
		if(e instanceof CelularPadrao){
			CelularPadrao c = (CelularPadrao) e;
			return c.obterNumero().equals(this.obterNumero());
		}
		
		return false;
	}
	
	@Override
	public int hashCode(){
		return numeroCelular;
	}

}
