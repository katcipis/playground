package infraestruturaDoTransformadorParaXML;

public interface TransformadorParaXML {

	public String obterOAtributoAltura(TransformavelEmXML transformável);

	public String obterOAtributoLargura(TransformavelEmXML transformável);

	public String obterOAtributoEsquerda(TransformavelEmXML transformável);

	public String obterOAtributoHabilitado(TransformavelEmXML transformável);

	public String obterOAtributoLegenda(TransformavelEmXML transformável);

	public String obterOAtributoNome(TransformavelEmXML transformável);

	public String obterOAtributoPosiçãoDaLegenda(
			TransformavelEmXML transformável);

	public String obterOAtributoProfundidade(TransformavelEmXML transformável);

	public String obterOAtributoTopo(TransformavelEmXML transformável);

	public String obterOAtributoVisível(TransformavelEmXML transformável);

	public String obterOAtributoTipo(TransformavelEmXML transformável);

	public String obterXML(TransformavelEmXML transformável);

}