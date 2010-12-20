//Nome : Luiz Paulo de Farias Jr - 06232801
//		 Tiago Katcipis			 - 06232047
// Bingo Mallucco

package concorrente;

import java.util.List;

public class Mesa {
	private final int numeroDeJogadores;
	private boolean semVencedor;
	private int conferidos;
	
	public Mesa(int numero){
		this.numeroDeJogadores = numero;
		this.semVencedor = true;
		this.conferidos = 0;
	}
	
	public boolean semVencedor(){
		return semVencedor;
	}
	
	public synchronized void imprimeTabela(int id,List<Integer> lista){
		System.out.print("Jogador "+id+" : [ ");
		for(int i : lista){
			System.out.print(i+" ");
		}
		System.out.println("]");
	}
	
	public synchronized int requer() throws InterruptedException{
		int numeroSorteado = 0;
		Double tmp;
		
		if(conferidos < numeroDeJogadores - 1 ){
			this.conferidos++;
			if(!semVencedor)
				this.liberaTodos();
			else
				wait();
		}
		else {
			tmp = (Math.random()*99) + 1;
			numeroSorteado = tmp.intValue();
			this.conferidos = 0;
			this.liberaTodos();
		}
		return numeroSorteado;
	}

	public synchronized void liberaTodos() {
		for(int i = 1;i<this.numeroDeJogadores;i++)
			notify();
	}

	public synchronized void verificaSeGanhou(int id,List<Integer> lista){
		boolean ganhou = false;
		for(Integer i : lista){
			if(i > 0)
				ganhou = true;
		}
		this.semVencedor = ganhou;
		if(semVencedor == false){
			System.out.println("O jogador "+id+" grita BINGOOOO!!!");
			this.liberaTodos();
		}
	}
}
