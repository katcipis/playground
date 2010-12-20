package testesDosTiposDeComponenteGedix;

import static edugraf.jadix.fachada.TiposDeComponentesDix.BOTÃO;
import static infraestruturaDoComponenteGedix.PosicoesDaLegenda.NA_ESQUERDA;
import static infraestruturaDoComponenteGedix.StringVazia.STRING_VAZIA;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertSame;
import static org.junit.Assert.assertTrue;
import infraestruturaDoComponenteGedix.PosicoesDaLegenda;
import infraestruturaDoComponenteGedix.Opcao;
import infraestruturaDoComponenteGedix.ComponenteGedix;
import infraestruturaDoComponenteGedix.ComponenteGedixComGrade;
import infraestruturaDoComponenteGedix.ComponenteGedixComOpcoes;
import infraestruturaDoComponenteGedix.ComponenteGedixComURI;
import infraestruturaDoComponenteGedix.ComponenteGedixRotulavel;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import infraestruturaDoPainelDeComponenteGedix.Posicao;

import java.util.ArrayList;
import java.util.List;

import listasDeTestesDoComponenteGedix.ListaDeTestesDoComponenteGedixNulo;

import org.junit.Before;
import org.junit.Test;

import tiposDeComponenteGedix.ComponenteGedixNulo;

public class TesteDoRetanguloDixNulo implements ListaDeTestesDoComponenteGedixNulo {

	private ComponenteGedixNulo retânguloDixNulo;
	
	private String novoTexto, novoNome, novaURI, vazia;
	private Opcao opçãoNova;
	private List<Opcao> listaComUmaOpção, listaVazia;
	private Posicao esquerdaZeroTopoZero, esquerdaUmTopoUm;
	
	@Before
	public void criarRetânguloDixNulo() {

		retânguloDixNulo = Fabrica.obterComponenteGedixNulo();
		novoTexto = "novoTexto";
		novoNome = "novoNome";
		novaURI = "novaURI";
		vazia = STRING_VAZIA.nome;
		opçãoNova = Fabrica.obterOpçãoDeNome("nova");
		listaComUmaOpção = new ArrayList<Opcao>();
		listaComUmaOpção.add(opçãoNova);
		listaVazia = new ArrayList<Opcao>();
		esquerdaZeroTopoZero = Fabrica.obterPosição(0, 0);
		esquerdaUmTopoUm = Fabrica.obterPosição(1, 1);
	}

	@Test
	public void nuncaEstáHabilitado() {
		assertFalse(retânguloDixNulo.verificarSeEstáHabilitado());
		retânguloDixNulo.habilitar();
		assertFalse(retânguloDixNulo.verificarSeEstáHabilitado());
	}

	@Test
	public void nuncaEstáVisível() {
		assertFalse(retânguloDixNulo.verificarSeEstáVisível());
		retânguloDixNulo.tornarVisível();
		assertFalse(retânguloDixNulo.verificarSeEstáVisível());
	}

	@Test
	public void nãoMudaALegenda() {
		retânguloDixNulo.definirPosiçãoDaLegenda(NA_ESQUERDA);
		assertFalse(retânguloDixNulo.obterPosiçãoDaLegenda().equals(NA_ESQUERDA));
	}

	@Test
	public void nãoMudaAListaDeOpções() {
		
		retânguloDixNulo.substituirListaDeOpções(listaComUmaOpção);
		assertFalse(retânguloDixNulo.obterListaDeOpções().equals(listaComUmaOpção));
		
		retânguloDixNulo.adcionarListaDeOpções(listaComUmaOpção);
		assertFalse(retânguloDixNulo.obterListaDeOpções().equals(listaComUmaOpção));
		
		retânguloDixNulo.adcionarOpção(opçãoNova);
		assertEquals(retânguloDixNulo.obterListaDeOpções(), listaVazia);
	}

	@Test
	public void nãoMudaONome() {
		retânguloDixNulo.alterarNome(novoNome);
		assertFalse(retânguloDixNulo.obterNome().equals(novoNome));
	}

	@Test
	public void nãoMudaOTexto() {
		retânguloDixNulo.alterarTexto(novoTexto);
		assertFalse(retânguloDixNulo.obterTexto().equals(novoTexto));
	}

	@Test
	public void nãoAMudaURI() {
		retânguloDixNulo.alterarURI(novaURI);
		assertFalse(retânguloDixNulo.obterURI().equals(novaURI));
	}

	@Test
	public void podeSerUmComponenteGedix() {
		assertTrue(retânguloDixNulo instanceof ComponenteGedix);

	}

	@Test
	public void podeSerUmComponenteGedixComOpções() {
		assertTrue(retânguloDixNulo instanceof ComponenteGedixComOpcoes);

	}

	@Test
	public void podeSerUmComponenteGedixComURI() {
		assertTrue(retânguloDixNulo instanceof ComponenteGedixComURI);

	}

	@Test
	public void podeSerUmComponenteGedixRotulável() {
		assertTrue(retânguloDixNulo instanceof ComponenteGedixRotulavel);

	}

	@Test
	public void nãoMudaONúmeroDeColunas() {
		retânguloDixNulo.alterarNúmeroDeColunas(3);
		assertSame(0, retânguloDixNulo.obterNúmeroDeColunas());
	}

	@Test
	public void nãoMudaONúmeroDeLinhas() {
		retânguloDixNulo.alterarNúmeroDeLinhas(3);
		assertSame(0, retânguloDixNulo.obterNúmeroDeLinhas());

	}

	@Test
	public void númeroDeLinhasEColunasÉZero() {
		assertSame(retânguloDixNulo.obterNúmeroDeColunas(), 0);
		assertSame(retânguloDixNulo.obterNúmeroDeLinhas(), 0);
	}

	@Test
	public void podeSerUmComponenteGedixComGrade() {
		assertTrue(retânguloDixNulo instanceof ComponenteGedixComGrade);

	}

	@Test
	public void seuTextoÉVazio() {
		assertEquals(retânguloDixNulo.obterTexto(), vazia);

	}

	@Test
	public void seuTipoDeComponenteDixÉBotão() {
		assertEquals(retânguloDixNulo.obterTipo(), BOTÃO);

	}

	@Test
	public void suaListaDeOpçõesÉVazia() {
		assertEquals(retânguloDixNulo.obterListaDeOpções(), listaVazia);

	}

	@Test
	public void suaURIÉVazia() {
		assertEquals(retânguloDixNulo.obterURI(), vazia);

	}

	@Test
	public void nãoOcupaPosiçãoAlguma() {
		assertFalse(retânguloDixNulo
				.verificarSeOcupaAPosição(esquerdaZeroTopoZero));
		
		assertFalse(retânguloDixNulo
				.verificarSeOcupaAPosição(esquerdaUmTopoUm));
		
	}

	@Test
	public void nãoPodeTerSuaPosiçãoDeOrigemRedefinida() {
		retânguloDixNulo.definirPosiçãoDeOrigem(esquerdaZeroTopoZero);
		assertFalse(retânguloDixNulo
				.verificarSeOcupaAPosição(esquerdaZeroTopoZero));
	}

	@Test
	public void suaAlturaÉZero() {
		assertSame(0, retânguloDixNulo.obterAltura());
		
	}

	@Test
	public void suaLarguraÉZero() {
		assertSame(0, retânguloDixNulo.obterLargura());
		
	}

	public void nãoMudaOTextoDaLegenda() {
		retânguloDixNulo.alterarLegenda(novoTexto);
		assertFalse(retânguloDixNulo
				.obterLegenda().equals(novoTexto));
	}

	public void oTextoDaLegendaÉVazio() {
		assertEquals(retânguloDixNulo
				.obterLegenda(), vazia);
		
	}

	public void suaLegendaÉNula() {
		assertEquals(retânguloDixNulo
				.obterPosiçãoDaLegenda(), PosicoesDaLegenda.NULO);
		
	}

}
