package lista.iteradoresDaLista;

import ine5384.excecoes.ExcecaoEstruturaVazia;
import ine5384.excecoes.ExcecaoOperacaoIlegal;
import ine5384.excecoes.ExcecaoPosicaoIlegal;
import ine5384.lineares.Lista;
import ine5384.pp.Iterador;


public class IteradorDaLista<T> implements Iterador<T>{

	 public int pos;
	 public Lista<T> lista;

     public IteradorDaLista(Lista<T> lista){
        pos = 0;
        this.lista = lista;
     }
	
	public T retorneProximo() throws ExcecaoOperacaoIlegal {
		
		pos++;
		
		try {
			return lista.retorneDaPosicao(pos);
		} catch (ExcecaoEstruturaVazia e) {
			throw new ExcecaoOperacaoIlegal();
		} catch (ExcecaoPosicaoIlegal e) {
			throw new ExcecaoOperacaoIlegal();
		} 
	}

	public boolean temMais() {
		
		return pos < lista.retorneTamanho() ;
	}

	

}
