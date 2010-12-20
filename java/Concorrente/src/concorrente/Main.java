//Nome : Luiz Paulo de Farias Jr - 06232801
//		 Tiago Katcipis			 - 06232047
// Bingo Mallucco

package concorrente;

public class Main{
	public static void main (String args[]){
		Jogador jogador[] = new Jogador[50];
		Mesa  mesa = new Mesa( 50 );
		for (int i = 0; i < 50 ; i++ ){
			jogador[i] = new Jogador ( i , mesa );
			jogador[i].start();
		}
	}
}
