package testesDaInfraestruturaDoPainel;

import static org.junit.Assert.*;
import infraestruturaDoPainelDeComponenteGedix.Dimensao;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import listasDeTestesDaInfraestruturaDoPainel.ListaDeTestesDaDimensao;

import org.junit.Before;
import org.junit.Test;

public class TesteDaDimensao implements ListaDeTestesDaDimensao {

	private Dimensao alturaDezELarguraVinte, alturaTrintaELarguraCinquenta,
			outraAlturaDezELarguraVinte;

	@Before
	public void construirDimensões() {

		alturaDezELarguraVinte = Fabrica.obterDimensão(10, 20);
		alturaTrintaELarguraCinquenta = Fabrica.obterDimensão(30, 50);
		outraAlturaDezELarguraVinte = Fabrica.obterDimensão(10, 20);
	}

	@Test
	public void sabeSeCompararComOutraDimensãoESaberSeÉIgual() {
		assertEquals(alturaDezELarguraVinte, outraAlturaDezELarguraVinte);
	}

	@Test
	public void sabeSeCompararComOutraDimensãoESaberSeÉDiferente() {
		assertFalse(alturaDezELarguraVinte
				.equals(alturaTrintaELarguraCinquenta));
	}

	@Test
	public void sabeQualSuaAltura() {
		assertSame(10, alturaDezELarguraVinte.obterAltura());
	}

	@Test
	public void sabeQualSuaLargura() {
		assertSame(20, alturaDezELarguraVinte.obterLargura());
	}

	@Test
	public void seCriarUmaDimensãoDeLarguraOuAlturaNegativosOValorDelesSeráZero() {
		assertSame(0, Fabrica.obterDimensão(-10, 10).obterAltura());
		assertSame(0, Fabrica.obterDimensão(10, -10).obterLargura());
	}

}
