package lista.iteradoresDaLista;

import ine5384.excecoes.ExcecaoEstruturaVazia;
import ine5384.excecoes.ExcecaoOperacaoIlegal;
import ine5384.excecoes.ExcecaoPosicaoIlegal;
import ine5384.lineares.ListaClassificada;
import ine5384.pp.Iterador;

public class IteradorDaListaOrdenada<C extends Comparable<C>> implements Iterador<C> {
	
	public int pos;
	public ListaClassificada<C> lista;

    public IteradorDaListaOrdenada(ListaClassificada<C> lista){
       pos = 0;
       this.lista = lista;
    }
	
	public C retorneProximo() throws ExcecaoOperacaoIlegal {
		
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
