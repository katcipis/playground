package infraestruturaDoTransformadorParaXML;

public enum InicioDosAtributosEmXML {
	
	NOME("nome="),
	
	ALTURA("altura="),
	
	LARGURA("largura="),
	
	TOPO("topo="),
	
	ESQUERDA("esquerda="),
	
	LINHAS("linhas="),
	
	COLUNAS("colunas="),
	
	URI("uri="),
	
	LEGENDA("legenda="),
	
	POSIÇÃO_DA_LEGENDA("posiçãoDaLegenda="),
	
	HABILITADO("habilitado="),
	
	VISÍVEL("visível="),
	
	PROFUNDIDADE("profundidade="),
	
	OPÇÃO("opção");
	
	public final String inícioDoAtributo;
	
	private InicioDosAtributosEmXML(String stringDoInícioDoAtributo){
		inícioDoAtributo = stringDoInícioDoAtributo;
	}

}
