package tiposDeComponenteGedix;

import static edugraf.jadix.fachada.TiposDeComponentesDix.ETIQUETA;

import componentesGedixAbstratos.ComponenteGedixRotulavelAbstrato;

import infraestruturaDoPainelDeComponenteGedix.RetanguloPosicionavel;
import edugraf.jadix.fachada.TiposDeComponentesDix;

public class Etiqueta extends ComponenteGedixRotulavelAbstrato {

	private static int contador = 1;
	public Etiqueta(RetanguloPosicionavel r) {
		super(r);
		incrementarContador();
	}

	protected TiposDeComponentesDix definirMeuTipo() {
		return ETIQUETA;
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