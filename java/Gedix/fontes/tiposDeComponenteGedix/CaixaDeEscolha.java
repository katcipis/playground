package tiposDeComponenteGedix;

import static edugraf.jadix.fachada.TiposDeComponentesDix.CAIXA_DE_ESCOLHA;

import componentesGedixAbstratos.ComponenteGedixComOpcoesAbstrato;

import infraestruturaDoPainelDeComponenteGedix.RetanguloPosicionavel;
import edugraf.jadix.fachada.TiposDeComponentesDix;

public class CaixaDeEscolha extends ComponenteGedixComOpcoesAbstrato {

	private static int contador = 1;
	public CaixaDeEscolha(RetanguloPosicionavel r) {
		super(r);
		incrementarContador();
	}
	

	protected TiposDeComponentesDix definirMeuTipo() {
		return CAIXA_DE_ESCOLHA;
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