package tiposDeComponenteGedix;

import static edugraf.jadix.fachada.TiposDeComponentesDix.ÁREA_DE_TEXTO;

import componentesGedixAbstratos.ComponenteGedixRotulavelAbstrato;

import infraestruturaDoPainelDeComponenteGedix.RetanguloPosicionavel;
import edugraf.jadix.fachada.TiposDeComponentesDix;

public class AreaDeTexto extends ComponenteGedixRotulavelAbstrato {

	private static int contador = 1;
	
	public AreaDeTexto(RetanguloPosicionavel r) {
		super(r);
		incrementarContador();
	}
	
	private static void incrementarContador(){
		contador++;
	}
	
	public static void reiniciarContador(){
		contador = 1;
	}
	
	@Override
	protected TiposDeComponentesDix definirMeuTipo() {
		return ÁREA_DE_TEXTO;
	}

	@Override
	protected String definirMeuNome() {
		return meuTipo.nome + contador;
	}

	

}
