package testesDaInfraestruturaDoComponenteGedix;

import static org.junit.Assert.*;
import infraestruturaDoComponenteGedix.Opcao;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;

import org.junit.Before;
import org.junit.Test;

import listasDeTestesDaInfraestruturaDoComponenteGedix.ListaDeTestesDaOpcao;

public class TesteDaOpcao implements ListaDeTestesDaOpcao{

	private Opcao opçãoDeNomeOpção1, opçãoDeNomeOpção2, outraOpçãoDeNomeOpção1;
	private String texto, nomeDaOpção1, nomeDaOpção2;
	
	@Before
	public void criarOpções(){
		
		nomeDaOpção1 = "Opção1";
		nomeDaOpção2 = "Opção2";
		
		opçãoDeNomeOpção1 = Fabrica.obterOpçãoDeNome(nomeDaOpção1);
		opçãoDeNomeOpção2 = Fabrica.obterOpçãoDeNome(nomeDaOpção2);
		outraOpçãoDeNomeOpção1 = Fabrica.obterOpçãoDeNome(nomeDaOpção1);
		texto = "texto";
	}
	
	@Test
	public void inicialmenteSeuTextoÉOMesmoQueSeuNome() {
		assertEquals(opçãoDeNomeOpção1.obterNome(), 
				opçãoDeNomeOpção1.obterTexto());
	}
	
	@Test
	public void nãoPodeMudarOSeuNome() {
	}

	@Test
	public void opçõesDeMesmoNomeSãoIguais() {
		assertEquals(opçãoDeNomeOpção1, 
				      outraOpçãoDeNomeOpção1);

	}

	@Test
	public void podeMudarOSeuTexto() {
		opçãoDeNomeOpção1.fixarTexto(texto);
		assertEquals(opçãoDeNomeOpção1.obterTexto(), texto);
	}

	@Test
	public void sabeQualÉOSeuNome() {
		assertEquals(opçãoDeNomeOpção1.obterNome(), nomeDaOpção1);
		assertEquals(opçãoDeNomeOpção2.obterNome(), nomeDaOpção2);
	}

	@Test
	public void sabeQualÉOSeuTexto() {
		assertEquals(opçãoDeNomeOpção1.obterTexto(), nomeDaOpção1);	
	}

	public void opçõesDeNomesDiferentesSãoDiferentes() {
		assertFalse(opçãoDeNomeOpção1.equals(opçãoDeNomeOpção2));
	}

}
