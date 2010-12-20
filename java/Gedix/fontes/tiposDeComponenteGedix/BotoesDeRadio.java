package tiposDeComponenteGedix;

import static edugraf.jadix.fachada.TiposDeComponentesDix.BOTÕES_DE_RÁDIO;

import componentesGedixAbstratos.ComponenteGedixComOpcoesAbstrato;

import infraestruturaDoPainelDeComponenteGedix.RetanguloPosicionavel;
import edugraf.jadix.fachada.TiposDeComponentesDix;

public class BotoesDeRadio extends ComponenteGedixComOpcoesAbstrato {

	private static int contador = 1;

	public BotoesDeRadio(RetanguloPosicionavel r) {
		super(r);
		incrementarContador();
	}
	
	protected TiposDeComponentesDix definirMeuTipo() {
		return BOTÕES_DE_RÁDIO;
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