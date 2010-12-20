package componentesGedixAbstratos;

import static infraestruturaDoComponenteGedix.StringVazia.STRING_VAZIA;
import infraestruturaDoComponenteGedix.ComponenteGedixRotulavel;
import infraestruturaDoPainelDeComponenteGedix.RetanguloPosicionavel;

public abstract class ComponenteGedixRotulavelAbstrato extends
		ComponenteGedixAbstrato implements ComponenteGedixRotulavel{

	private String textoDoComponente;

	public ComponenteGedixRotulavelAbstrato(RetanguloPosicionavel rp) {
		super(rp);
		textoDoComponente = STRING_VAZIA.nome;
	}

	public String obterTexto() {
		return textoDoComponente;
	}

	public void alterarTexto(String novoTexto) {
		textoDoComponente = novoTexto;
	}

}
