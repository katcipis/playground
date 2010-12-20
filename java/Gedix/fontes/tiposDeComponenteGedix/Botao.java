package tiposDeComponenteGedix;

import componentesGedixAbstratos.ComponenteGedixRotulavelAbstrato;

import edugraf.jadix.fachada.TiposDeComponentesDix;
import infraestruturaDoPainelDeComponenteGedix.RetanguloPosicionavel;
import static edugraf.jadix.fachada.TiposDeComponentesDix.*;

public class Botao extends ComponenteGedixRotulavelAbstrato {

	private static int contador = 1;

	public Botao(RetanguloPosicionavel r) {
		super(r);
		incrementarContador();
	}
	
	

	protected TiposDeComponentesDix definirMeuTipo() {
		return BOTÃO;
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
