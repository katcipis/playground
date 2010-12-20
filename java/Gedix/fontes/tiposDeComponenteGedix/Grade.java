package tiposDeComponenteGedix;

import static edugraf.jadix.fachada.TiposDeComponentesDix.GRADE;

import componentesGedixAbstratos.ComponenteGedixComGradeAbstrato;

import infraestruturaDoPainelDeComponenteGedix.RetanguloPosicionavel;
import edugraf.jadix.fachada.TiposDeComponentesDix;

public class Grade extends ComponenteGedixComGradeAbstrato {
	
	private static int contador = 1;
	public Grade(RetanguloPosicionavel r) {
		super(r);
		incrementarContador();
	}

	protected TiposDeComponentesDix definirMeuTipo() {
		return GRADE;
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