package tiposDeComponenteGedix;

import static edugraf.jadix.fachada.TiposDeComponentesDix.CAMPO_DE_TEXTO;

import componentesGedixAbstratos.ComponenteGedixRotulavelAbstrato;

import infraestruturaDoPainelDeComponenteGedix.RetanguloPosicionavel;
import edugraf.jadix.fachada.TiposDeComponentesDix;

public class CampoDeTexto extends ComponenteGedixRotulavelAbstrato {
	
	private static int contador = 1;

	public CampoDeTexto(RetanguloPosicionavel r) {
		super(r);
		incrementarContador();
	}
	
	private static void incrementarContador(){
		contador++;
	}
	
	public static void reiniciarContador(){
		contador = 1;
	}
	

	protected TiposDeComponentesDix definirMeuTipo() {
		return CAMPO_DE_TEXTO;
	}
	
	@Override
	protected String definirMeuNome() {
		return meuTipo.nome + contador;
	}

	
}