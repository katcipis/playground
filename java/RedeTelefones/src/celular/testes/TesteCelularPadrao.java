package celular.testes;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertNotNull;
import static org.junit.Assert.assertTrue;

import org.junit.Before;
import org.junit.Test;

import servidor.EstacaoBase;

import celular.Celular;
import celular.CelularPadrao;

public class TesteCelularPadrao {

	protected Celular celular;
	protected Celular celularOcupado;
	protected Celular celularDesligado;
	protected Celular celularLivre;
	
	protected Integer numeroCelular;
	protected Integer numeroCelularLivre;
	protected Integer numeroCelularOcupado;
	protected Integer numeroCelularDesligado;
	protected Integer posicaoInicial;
	
	@Before
	public void iniciar(){
		
		celular = new CelularPadrao(91060132);
		numeroCelular = 91060132;
		
		celularOcupado = new CelularPadrao(88253207);
		numeroCelularOcupado = 88253207;
		celularOcupado.receberLigacao(celular);
		
		celularDesligado = new CelularPadrao(91165874);
		numeroCelularDesligado = 91165874;
		celularDesligado.desligar();
		
		celularLivre = new CelularPadrao(77805624);
		numeroCelularLivre = 77805624;
		
		posicaoInicial = 0;
		
	}
	
	@Test
	public void aposSerCriadoEstaLigado(){
		Celular tmp =  new CelularPadrao(91060132);
		assertFalse(tmp.estaDesligado());
	}
	
	@Test
	public void aposSerDesligadoUmCelularFicaDesligado(){
		celular.desligar();
		assertTrue(celular.estaDesligado());
	}
	
	@Test
	public void aposSerLigadoUmCelularNaoEstaDesLigado(){
		celular.desligar();
		assertTrue(celular.estaDesligado());
		celular.ligar();
		assertFalse(celular.estaDesligado());
	}
	
	@Test
	public void sabeQualOSeuNumero(){
		assertEquals(celular.obterNumero(), numeroCelular);
		assertEquals(celularLivre.obterNumero(), numeroCelularLivre);
		assertEquals(celularOcupado.obterNumero(), numeroCelularOcupado);
		assertEquals(celularDesligado.obterNumero(), numeroCelularDesligado);
	}
	
	@Test
	public void sabeQualNaoEhOSeuNumero(){
		assertFalse(celular.obterNumero().equals(numeroCelularLivre));
		assertFalse(celularLivre.obterNumero().equals(numeroCelularOcupado));
		assertFalse(celularOcupado.obterNumero().equals(numeroCelularDesligado));
		assertFalse(celularDesligado.obterNumero().equals(numeroCelular));
	}
	
	@Test
	public void seOCelularNaoEstaFazendoLigacaoEleNaoEstaOcupado(){
		assertFalse(celular.estaOcupado());
	}
	
	@Test
	public void seOCelularEstaFazendoLigacaoEleEstaOcupado(){
		celular.fazerLigacao(numeroCelularLivre);
		assertTrue(celular.estaOcupado());
	}
	
	@Test
	public void aposEncerrarALigacaoNaoEstaOcupado(){
		celular.fazerLigacao(numeroCelularLivre);
		assertTrue(celular.estaOcupado());
		celular.encerrarLigacao();
		assertFalse(celular.estaOcupado());
	}
	
	@Test
	public void seNaoEstaRecebendoLigacaoNaoEstaOcupado(){
		assertFalse(celular.estaOcupado());
	}
	
	@Test
	public void seEstaRecebendoLigacaoEstaOcupado(){
		celular.receberLigacao(celularLivre);
		assertTrue(celular.estaOcupado());
	}
	
	@Test
	public void aposEncerrarALigacaoQueRecebeuNaoEstaOcupado(){
		celular.receberLigacao(celularLivre);
		assertTrue(celular.estaOcupado());
		celular.encerrarLigacao();
		assertFalse(celular.estaOcupado());
	}
	
	@Test
	public void sabeSePossuiMensagensNaoLidas(){
		celular.receberMensagem(celularLivre,  "Teste");
		assertTrue(celular.possuiMensagensNaoLidas());
	}
	
	@Test
	public void sabeSeNaoPossuiMensagensNaoLidas(){
		assertFalse(celular.possuiMensagensNaoLidas());
	}
	
	@Test
	public void aposLerMensagensNaoPossuiMensagensNaoLidas(){
		celular.receberMensagem(celularLivre,  "Teste");
		assertTrue(celular.possuiMensagensNaoLidas());
		celular.lerMensagens();
		assertFalse(celular.possuiMensagensNaoLidas());
	}
	
	@Test
	public void sabeEmQuePosicaoSeEncontra(){
		assertEquals(celular.obterPosicao(), posicaoInicial);
	}
	
	@Test
	public void posicaoInicialEhZero(){
		assertEquals(0, posicaoInicial);
		assertEquals(celular.obterPosicao(), posicaoInicial);
	}
	
	@Test
	public void sabeEmQuePosicaoNaoSeEncontra(){
		assertFalse(celular.obterPosicao().equals(3));
	}
	
	@Test
	public void aposMudarDePosicaoANovaPosicaoSeraAAntigaIncrementada(){
		assertEquals(celular.obterPosicao(), 0);
		celular.mover();
		assertEquals(celular.obterPosicao(), 1);
	}
	
	@Test
	public void aposMudarDePosicaoSeAPosicaoAntigaEraOLimiteMaximoAPosicaoNovaSeraZero(){
		celular.mover();
		celular.mover();
		celular.mover();
		assertEquals(celular.obterPosicao(), 3);
		celular.mover();
		assertEquals(celular.obterPosicao(), 0);
	}
	
	@Test
	public void aposMudarDePosicaoSuaPosicaoNaoSeraAAntiga(){
		assertEquals(celular.obterPosicao(), posicaoInicial);
		celular.mover();
		assertFalse(celular.obterPosicao().equals(posicaoInicial));
	}
	
	@Test
	public void saoIguaisSePossuemMesmoNumero(){
		assertEquals(new CelularPadrao(91795865), new CelularPadrao(91795865));
	}
	
	@Test
	public void possuiUmaEstacaoBaseNaoNula(){
		assertNotNull(celular.obterEstacao());
		assertNotNull(celularOcupado.obterEstacao());
		assertNotNull(celularLivre.obterEstacao());
	}
	
	@Test
	public void aposSeMoverAEstacaoBaseDoCelularMuda(){
		EstacaoBase tmp = celular.obterEstacao();
		assertEquals(tmp, celular.obterEstacao());
		celular.mover();
		assertFalse(tmp.equals(celular.obterEstacao()));
	}
}
