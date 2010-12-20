package infraestruturaDoTransformadorParaXML;

import static infraestruturaDoTransformadorParaXML.InicioDosAtributosEmXML.*;

public class TransformadorParaXMLConcreto implements TransformadorParaXML {

	protected final String falso, verdadeiro, aspa,
	inícioDoMarcador, fimDoMarcador, inícioDoMarcadorQueEncerra, espaçoVazio;
	private final MapaDeTiposDeComponentesDixParaXML mapaDeTiposDeComponentesDixParaXML;

	public TransformadorParaXMLConcreto() {
		falso = "falso";
		verdadeiro = "verdadeiro";
		aspa = "\"";
		inícioDoMarcador = "<";
		espaçoVazio = " ";
		fimDoMarcador = ">";
		inícioDoMarcadorQueEncerra = "</";
		mapaDeTiposDeComponentesDixParaXML = new MapaDeTiposDeComponentesDixParaXML();
	}

	
	public String obterOAtributoAltura(TransformavelEmXML transformável) {
		Integer altura = transformável.obterAltura();
		return ALTURA.inícioDoAtributo + aspa + altura.toString() + aspa;
	}

	
	public String obterOAtributoLargura(TransformavelEmXML transformável) {
		Integer largura = transformável.obterLargura();
		return LARGURA.inícioDoAtributo + aspa + largura.toString() + aspa;
	}


	public String obterOAtributoEsquerda(TransformavelEmXML transformável) {
		Integer esquerda = transformável.obterPosiçãoDeOrigem()
				.obterDistânciaDaEsquerda();
		
		return ESQUERDA.inícioDoAtributo + aspa + esquerda.toString() + aspa;
	}

	
	public String obterOAtributoHabilitado(TransformavelEmXML transformável) {
		String atributoHabilitado;
		if (transformável.verificarSeEstáHabilitado()) {
			atributoHabilitado = verdadeiro;
		} else {
			atributoHabilitado = falso;
		}
		return HABILITADO.inícioDoAtributo + aspa + atributoHabilitado + aspa;
	}

	
	public String obterOAtributoLegenda(TransformavelEmXML transformável) {
		
		return LEGENDA.inícioDoAtributo + aspa + transformável.obterLegenda() + aspa;
	}

	
	public String obterOAtributoNome(TransformavelEmXML transformável) {
		return NOME.inícioDoAtributo + aspa + transformável.obterNome() + aspa;
	}

	
	public String obterOAtributoPosiçãoDaLegenda(
			TransformavelEmXML transformável) {
		return POSIÇÃO_DA_LEGENDA.inícioDoAtributo + aspa + transformável
				.obterPosiçãoDaLegenda().nome + aspa;
	}


	public String obterOAtributoProfundidade(TransformavelEmXML transformável) {
		Integer profundidade = transformável.obterProfundidade();
		return PROFUNDIDADE.inícioDoAtributo + aspa + profundidade.toString() + aspa;
	}


	public String obterOAtributoTopo(TransformavelEmXML transformável) {
		Integer topo = transformável.obterPosiçãoDeOrigem()
				.obterDistânciaDoTopo();
		return TOPO.inícioDoAtributo + aspa + topo.toString() + aspa;
	}


	public String obterOAtributoVisível(TransformavelEmXML transformável) {

		String visível;
		if (transformável.verificarSeEstáVisível()) {
			visível = verdadeiro;
		} else {
			visível = falso;
		}
		return VISÍVEL.inícioDoAtributo + aspa + visível + aspa;
	}


	public String obterOAtributoTipo(TransformavelEmXML transformável) {

		return mapaDeTiposDeComponentesDixParaXML.obterXML(transformável
				.obterTipo());

	}
	
	
	public String obterXML(TransformavelEmXML transformável){
		return 
		gerarXML(transformável)+ fimDoMarcador 
		+ inícioDoMarcadorQueEncerra + obterOAtributoTipo(transformável)
		+ fimDoMarcador;
	}
	
	protected String gerarXML(TransformavelEmXML transformável){
		return inícioDoMarcador + obterOAtributoTipo(transformável) + espaçoVazio +
		obterOAtributoNome(transformável) 
		+ espaçoVazio + obterOAtributoLargura(transformável) 
		+ espaçoVazio + obterOAtributoAltura(transformável)
		+ espaçoVazio + obterOAtributoEsquerda(transformável)
		+ espaçoVazio + obterOAtributoTopo(transformável) 
		+ espaçoVazio + obterOAtributoLegenda(transformável)
		+ espaçoVazio + obterOAtributoPosiçãoDaLegenda(transformável) 
		+ espaçoVazio + obterOAtributoProfundidade(transformável)
		+ espaçoVazio + obterOAtributoVisível(transformável)
		+ espaçoVazio + obterOAtributoHabilitado(transformável);
	}
}
