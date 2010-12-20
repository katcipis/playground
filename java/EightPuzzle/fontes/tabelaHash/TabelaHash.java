package tabelaHash;

import ine5384.EstruturaDeDados;

import java.util.Iterator;



/**
 * @author PatriciaVilain
 *
 * @param <C> Tipo das chaves que podem ser incluídas na tabela hash.
 * @param <V> Tipo dos elementos que podem ser incluídos na tabela hash.
 */
public interface TabelaHash<C,V> extends EstruturaDeDados{
	
	/**
	 * Insere a chave e o valor na tabela, de acordo com a aplicacao da 
	 * funcao hash sobre a chave.
	 * Se a chave existir na tabela, substitui o valor antigo pelo novo. 
	 * @param chave Chave do elemento que vai ser inserido na tabela hash.
	 * @param valor Elemento que vai ser inserido na tabela hash.
	 */	
	public void insere (C chave, V valor);
	
	/**
	 * Retorna o valor associado com a chave.
	 * Se a chave nao existir, retorna null.
	 * @param chave Chave do elemento que vai ser retornado da tabela hash.
	 */	
	public V retorna (C chave);
	
	/**
	 * Remove a chave e o seu valor da tabela, retornando o valor.
	 * Se a chave nao existir, retorna null.
	 * @param chave Chave do elemento que vai ser retornado da tabela hash.
	 */	
	public V remove (C chave);
	
	/**
	 * Retorna true se a chave existir na tabela.
	 * @param chave Chave do elemento que está sendo procurado na tabela hash.
	 */	
	boolean existe (C chave);
	
	/**
	 * Retorna um iterator com as chaves da tabela.
	 */	
	public Iterator<C> retornaChaves ();
	
    public	TabelaHash<C,V> retornaCopia();
	


}
