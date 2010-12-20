package tiposDeComponenteGedix;

import static edugraf.jadix.fachada.TiposDeComponentesDix.ENLACE;
import static infraestruturaDoComponenteGedix.StringVazia.STRING_VAZIA;
import infraestruturaDoComponenteGedix.ComponenteGedixRotulavelComURI;
import infraestruturaDoPainelDeComponenteGedix.RetanguloPosicionavel;

import componentesGedixAbstratos.ComponenteGedixRotulavelAbstrato;

import edugraf.jadix.fachada.TiposDeComponentesDix;

public class Enlace extends ComponenteGedixRotulavelAbstrato implements
                                  ComponenteGedixRotulavelComURI{
	
	private static int contador = 1;
	private String uri;


	public Enlace(RetanguloPosicionavel r) {
		super(r);
		uri = STRING_VAZIA.nome;
		incrementarContador();
	}
	
	private static void incrementarContador(){
		contador++;
	}
	
	public static void reiniciarContador(){
		contador = 1;
	}

	protected TiposDeComponentesDix definirMeuTipo() {
		return ENLACE;
	}

	public String obterURI() {
		return uri;
	}

	public void alterarURI(String novaURI) {
		uri = novaURI;
	}
	@Override
	protected String definirMeuNome() {
		return meuTipo.nome + contador;
	}
	
}