package servidor;

import java.util.HashSet;
import java.util.Set;

import celular.Celular;
import celular.CelularNulo;

public class EstacaoBase extends Thread {
	
	private Set<Celular> celulares;
	
	public EstacaoBase(){
		celulares = new HashSet<Celular>();
	}

	public Celular solicitarLigacao(Celular remetente, Integer numeroChamado) {
		return null;
	}
	
	public boolean enviarMensagem(Celular remetente, Integer numeroChamado, String msg) {
		return false;
	}
	
	public void removerCelular(Celular cel){
		celulares.remove(cel);
	}
	
	public void inserirCelular(Celular cel){
		celulares.add(cel);
	}
	
	public boolean possuiCelular(Integer numeroCel){

		for(Celular cel : celulares){
			if(cel.obterNumero().equals(numeroCel))
				return true;
		}
		return false;
	}
	
  public Celular obterCelular(Integer numeroCel){
  	for(Celular cel : celulares){
			if(cel.obterNumero().equals(numeroCel))
				return cel;
		}
		return new CelularNulo();
	}
	
}
