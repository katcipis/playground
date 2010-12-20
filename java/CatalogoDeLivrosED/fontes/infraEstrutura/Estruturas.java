package infraEstrutura;

import implementacao.CatalogoAVL;
import implementacao.CatalogoArquivo;
import implementacao.CatalogoHash;
import interfaces.Catalogo;

public enum Estruturas {
	
	ARVORE_AVL {
		
		public String toString(){
			return "Arvore AVL";
		}
		
		public Catalogo obterCatalogo(){
			return new CatalogoAVL();
		}
	},
	
	TABELA_HASH {
		
		public String toString(){
			return "Tabela Hash";
		}
		
		public Catalogo obterCatalogo(){
			return new CatalogoHash();
		}
	},
	
	ARQUIVO {
		
		public String toString(){
			return "Arquivo";
		}
		
		public Catalogo obterCatalogo(){
			return new CatalogoArquivo();
		}
	};
	
	public abstract Catalogo obterCatalogo();
}
