//Nome : Luiz Paulo de Farias Jr - 06232801
//		 Tiago Katcipis			 - 06232047
// Bingo Mallucco

package concorrente;

import java.util.ArrayList;
import java.util.List;

public class Jogador extends Thread { 
	private int id;
	private Mesa mesa;
	private List<Integer> tabela;
	
	public Jogador(int id, Mesa mesa){
		this.id = id;
		this.mesa = mesa;
		tabela = new ArrayList<Integer>(10);
		this.geraTabela();
	}
	
	private void geraTabela(){
		int numeroDeSorteados = 0;
		int nova;
		Double tmp;
		while(numeroDeSorteados <= 10){
			tmp = (Math.random()*99) + 1;
			nova = tmp.intValue();
			if(!tabela.contains(nova)){
				tabela.add(nova);
				numeroDeSorteados++;
			}
		}
	}
	
	public void run(){
		int sorteada;
		while(mesa.semVencedor()){
			try {
				sorteada = mesa.requer();
				if(mesa.semVencedor()){
					this.verificaTabela(sorteada);
					//sleep(10); // sleep aqui...
				}
				else
					this.mesa.liberaTodos();
			}
			catch ( InterruptedException e ){
				  System.err.println( e );
			}
		}
		this.mesa.liberaTodos();
	}
	
	private void verificaTabela(Integer i){
		if(tabela.contains(i)){
			tabela.remove(i);
			tabela.add(i*-1);
			mesa.imprimeTabela(id,tabela);
			mesa.verificaSeGanhou(id,tabela);
		}
	}
}