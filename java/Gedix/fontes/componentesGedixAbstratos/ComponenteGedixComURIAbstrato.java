package componentesGedixAbstratos;

import static infraestruturaDoComponenteGedix.StringVazia.STRING_VAZIA;
import infraestruturaDoComponenteGedix.ComponenteGedixComURI;
import infraestruturaDoPainelDeComponenteGedix.RetanguloPosicionavel;

public abstract class ComponenteGedixComURIAbstrato extends ComponenteGedixAbstrato
		implements ComponenteGedixComURI{

	private String uri;

	public ComponenteGedixComURIAbstrato(RetanguloPosicionavel r) {
		super(r);
		uri = STRING_VAZIA.nome;
	}

	public String obterURI() {
		return uri;
	}

	public void alterarURI(String novaURI) {
		uri = novaURI;
	}

}
