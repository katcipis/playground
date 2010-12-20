package tiposDeComponenteGedix;

import static edugraf.jadix.fachada.TiposDeComponentesDix.IMAGEM;

import componentesGedixAbstratos.ComponenteGedixComURIAbstrato;

import infraestruturaDoPainelDeComponenteGedix.RetanguloPosicionavel;
import edugraf.jadix.fachada.TiposDeComponentesDix;

public class Imagem extends ComponenteGedixComURIAbstrato {


	private static int contador = 1;
	public Imagem(RetanguloPosicionavel r) {
		super(r);
		incrementarContador();
	}

	protected TiposDeComponentesDix definirMeuTipo() {
		return IMAGEM;
	}
	
	private static void incrementarContador(){
		contador++;
	}
	
	public static void reiniciarContador(){
		contador = 1;
	}

	@Override
	protected String definirMeuNome() {
		return meuTipo.nome + contador;
	}


}