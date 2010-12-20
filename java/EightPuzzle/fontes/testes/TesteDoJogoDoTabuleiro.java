package testes;

import ine5384.excecoes.ExcecaoEstruturaCheia;
import ine5384.excecoes.ExcecaoEstruturaVazia;
import ine5384.lineares.Lista;

import java.io.IOException;

import jogo.JogoTabuleiro;
import jogo.JogoTabuleiroConcreto;
import jogo.Posicao;
import jogo.Tabuleiro;
import jogo.TabuleiroConcreto;
import jogo.Tabuleiro.Peca;

import org.junit.Before;
import org.junit.Test;

import tabelaHash.TabelaHash;
import tabelaHash.TabelaHashConcreta;

public class TesteDoJogoDoTabuleiro {
	
	JogoTabuleiro jogo;
	TabuleiroConcreto tabuleiroNaoResolvido;
	
	@Before
	public void criarComponentesDoJogo(){
		
		criarTabuleiroNaoResolvido();
		
		jogo = new JogoTabuleiroConcreto();
	}
	
	private void criarTabuleiroNaoResolvido() {
		
		TabelaHash<Posicao, Peca> tabela = new TabelaHashConcreta<Posicao, Peca>();
		
		tabela.insere(new Posicao(1,1), Peca.UM);
		tabela.insere(new Posicao(1,2), Peca.CINCO);
		tabela.insere(new Posicao(1,3), Peca.DOIS);
		
		tabela.insere(new Posicao(2,1), Peca.NULA);
		tabela.insere(new Posicao(2,2), Peca.OITO);
		tabela.insere(new Posicao(2,3), Peca.TRES);
		
		tabela.insere(new Posicao(3,1), Peca.QUATRO);
		tabela.insere(new Posicao(3,2), Peca.SETE);
		tabela.insere(new Posicao(3,3), Peca.SEIS);
		
		tabuleiroNaoResolvido = new TabuleiroConcreto(tabela);
		
	}

	

	@Test
	public void wurul() throws ExcecaoEstruturaVazia, ExcecaoEstruturaCheia, IOException{
		
		Lista<Tabuleiro> resposta = jogo.soluciona(tabuleiroNaoResolvido);
		
		while(!resposta.estaVazia()){
			
			System.out.println(resposta.removaDoInicio());
			System.out.println("\n");
		}
		
		
		
		
	}

}
