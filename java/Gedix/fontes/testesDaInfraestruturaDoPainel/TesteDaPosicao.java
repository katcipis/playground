package testesDaInfraestruturaDoPainel;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertSame;

import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import infraestruturaDoPainelDeComponenteGedix.Posicao;
import listasDeTestesDaInfraestruturaDoPainel.ListaDeTestesDaPosicao;

import org.junit.Before;
import org.junit.Test;

public class TesteDaPosicao implements ListaDeTestesDaPosicao {

	private Posicao esquerdaUmTopoUm, esquerdaUmTopoDois,
			outraEsquerdaUmTopoUm;

	@Before
	public void criarPosições() {

		esquerdaUmTopoUm = Fabrica.obterPosição(1, 1);
		outraEsquerdaUmTopoUm = Fabrica.obterPosição(1, 1);
		esquerdaUmTopoDois = Fabrica.obterPosição(1, 2);
	}

	@Test
	public void sabeSeCompararComOutraPosiçãoESaberSeÉIgual() {
		assertEquals(outraEsquerdaUmTopoUm, esquerdaUmTopoUm);
	}

	@Test
	public void sabeSeCompararComOutraPosiçãoESaberSeÉDiferente() {
		assertFalse(esquerdaUmTopoUm.equals(esquerdaUmTopoDois));
	}

	@Test
	public void sabeQualSuaDistânciaDaEsquerda() {
		assertSame(1, esquerdaUmTopoDois.obterDistânciaDaEsquerda());
	}

	@Test
	public void sabeQualSuaDistânciaDoTopo() {
		assertSame(2, esquerdaUmTopoDois.obterDistânciaDoTopo());
	}

}
