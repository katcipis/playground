package tiposDeComponenteGedix;

import componentesGedixAbstratos.ComponenteGedixAbstrato;

import edugraf.jadix.fachada.TiposDeComponentesDix;
import infraestruturaDoPainelDeComponenteGedix.RetanguloPosicionavel;
import static edugraf.jadix.fachada.TiposDeComponentesDix.*;

public class AreaSensivel extends ComponenteGedixAbstrato {
	private static int contador = 1;

	public AreaSensivel(RetanguloPosicionavel r) {
		super(r);
		incrementarContador();
	}


	protected TiposDeComponentesDix definirMeuTipo() {
		return ÁREA_SENSÍVEL;
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