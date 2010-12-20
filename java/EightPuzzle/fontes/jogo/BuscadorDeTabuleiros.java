package jogo;

import fila.filas.Fila;
import ine5384.excecoes.ExcecaoEstruturaCheia;
import ine5384.excecoes.ExcecaoEstruturaVazia;
import jogo.Tabuleiro.Peca;
import tabelaHash.TabelaHash;
import tabelaHash.TabelaHashConcreta;


public class BuscadorDeTabuleiros {

	private final TabuleiroConcreto tabuleiroResolvido;
	
	public BuscadorDeTabuleiros(){
        
		TabelaHash<Posicao, Peca> tabela = new TabelaHashConcreta<Posicao, Peca>();
		
		tabela.insere(new Posicao(1,1), Peca.UM);
		tabela.insere(new Posicao(1,2), Peca.DOIS);
		tabela.insere(new Posicao(1,3), Peca.TRES);
		
		tabela.insere(new Posicao(2,1), Peca.QUATRO);
		tabela.insere(new Posicao(2,2), Peca.CINCO);
		tabela.insere(new Posicao(2,3), Peca.SEIS);
		
		tabela.insere(new Posicao(3,1), Peca.SETE);
		tabela.insere(new Posicao(3,2), Peca.OITO);
		tabela.insere(new Posicao(3,3), Peca.NULA);
		
		tabuleiroResolvido = new TabuleiroConcreto(tabela);
		
		
	}
	
	public TabuleiroConcreto encontrarCaminhoEntre(TabuleiroConcreto tabuleiroOriginal) throws ExcecaoEstruturaVazia, ExcecaoEstruturaCheia{
	
		Fila<TabuleiroConcreto> filhos = tabuleiroOriginal.retornaMovimentos();
		
		if(!tabuleiroOriginal.equals(this.tabuleiroResolvido)){
			
			while(!filhos.estaVazia()){
				
				TabuleiroConcreto atual = filhos.remove();
			
				if(atual.equals(this.tabuleiroResolvido)){
			
					return atual;
					
				}
				
				Fila<TabuleiroConcreto> filhosDosFilhos = atual.retornaMovimentos();
				
				while(!filhosDosFilhos.estaVazia()){
					
					TabuleiroConcreto aux = filhosDosFilhos.remove();
					
					if(this.naoEhMovimentoRepetido(aux)){
						filhos.insere(aux);
					}
					
				}
				
			}
			
		}
		
		return tabuleiroOriginal;
	}

	private boolean naoEhMovimentoRepetido(TabuleiroConcreto filho) {
	
		TabuleiroConcreto pai = filho.pai;
		
		while(pai.pai != null){
			if(pai.equals(filho))
				return false;
			pai = pai.pai;
		}
		
		return !pai.equals(filho);
	}

}
