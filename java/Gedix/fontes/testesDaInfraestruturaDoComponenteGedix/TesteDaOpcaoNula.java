package testesDaInfraestruturaDoComponenteGedix;

import static org.junit.Assert.*;
import infraestruturaDoComponenteGedix.Opcao;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import static infraestruturaDoComponenteGedix.StringVazia.*;

import org.junit.Before;
import org.junit.Test;

import listasDeTestesDaInfraestruturaDoComponenteGedix.ListaDeTestesDaOpcaoNula;

public class TesteDaOpcaoNula implements ListaDeTestesDaOpcaoNula{

	private Opcao opçãoNula, outraOpçãoNula, opçãoQueNãoÉNula;
	private String texto;
	
	@Before
	public void criarOpçõesNulas(){
		texto = "texto";
		opçãoNula = Fabrica.obterOpçãoNula();
		outraOpçãoNula = Fabrica.obterOpçãoNula();
		opçãoQueNãoÉNula = Fabrica.obterOpçãoDeNome(texto);
	
	}
	
	@Test
	public void inicialmenteSeuTextoÉOMesmoQueSeuNome() {
		assertEquals(opçãoNula.obterNome(), opçãoNula.obterTexto());
		
	}

	@Test
	public void nãoPodeMudarOSeuNome() {
	}

	@Test
	public void nãoPodeMudarOSeuTexto() {
		opçãoNula.fixarTexto(texto);
		assertFalse(opçãoNula.obterTexto().equals(texto));
	}

	@Test
	public void seuNomeÉVazio() {
		assertEquals(STRING_VAZIA.nome, opçãoNula.obterNome());
		
	}

	@Test
	public void todasAsOpçõesNulasSãoIguais() {
		
		assertEquals(opçãoNula, outraOpçãoNula);
		
		assertFalse(opçãoQueNãoÉNula.equals(opçãoNula));
		assertFalse(opçãoQueNãoÉNula.equals(outraOpçãoNula));
	}

}
