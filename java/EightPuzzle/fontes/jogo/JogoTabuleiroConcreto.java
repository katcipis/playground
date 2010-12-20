package jogo;

import ine5384.excecoes.ExcecaoEstruturaCheia;
import ine5384.excecoes.ExcecaoEstruturaVazia;
import ine5384.lineares.Lista;
import jogo.Tabuleiro.Peca;
import lista.listas.simples.ListaEncadeada;
import tabelaHash.TabelaHash;
import tabelaHash.TabelaHashConcreta;

public class JogoTabuleiroConcreto implements JogoTabuleiro{

	public Lista<Tabuleiro> soluciona(Tabuleiro inicial) {
		
		BuscadorDeTabuleiros buscador = new BuscadorDeTabuleiros();
		
		TabuleiroConcreto castTosco = transformarEmTabuleiroConcreto(inicial);
		
		Lista<Tabuleiro> lista = new ListaEncadeada<Tabuleiro>();
		
		TabuleiroConcreto resposta = null;
		
		try {
			resposta = buscador.encontrarCaminhoEntre(castTosco);
		} catch (ExcecaoEstruturaVazia e) {
			e.printStackTrace();
		} catch (ExcecaoEstruturaCheia e) {
			e.printStackTrace();
		}
		
		try {
			lista.insiraNoInicio(resposta);
		} catch (ExcecaoEstruturaCheia e) {
			e.printStackTrace();
		}
		
		while(resposta.pai != null){
			try {
				lista.insiraNoInicio(resposta.pai);
			} catch (ExcecaoEstruturaCheia e) {
				e.printStackTrace();
			}
		    resposta = resposta.pai;
			
		}
		
		return lista;
	}

	private TabuleiroConcreto transformarEmTabuleiroConcreto(Tabuleiro inicial) {
		TabelaHash<Posicao, Peca> tabelaDePos = new TabelaHashConcreta<Posicao, Peca>();
		
		tabelaDePos.insere(new Posicao(1,1), inicial.peca(1,1));
		tabelaDePos.insere(new Posicao(1,2), inicial.peca(1,2));
		tabelaDePos.insere(new Posicao(1,3), inicial.peca(1,3));
		
		tabelaDePos.insere(new Posicao(2,1), inicial.peca(2,1));
		tabelaDePos.insere(new Posicao(2,2), inicial.peca(2,2));
		tabelaDePos.insere(new Posicao(2,3), inicial.peca(2,3));
		
		tabelaDePos.insere(new Posicao(3,1), inicial.peca(3,1));
		tabelaDePos.insere(new Posicao(3,2), inicial.peca(3,2));
		tabelaDePos.insere(new Posicao(3,3), inicial.peca(3,3));
		
		return new TabuleiroConcreto(tabelaDePos);
	}



	
	

}
