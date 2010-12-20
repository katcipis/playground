package celular.testes;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

import celular.Mensagem;

public class TesteMensagem {
	
	private Mensagem msg;
	
	private Integer numeroRemetente;
	private Integer remetenteErrado;
	
	private String msgCorreta;
	private String msgErrada;
	
	@Before
	public void iniciar(){
		numeroRemetente = 91495364;
		remetenteErrado = 97854567;
		msgCorreta = "Olá";
		msgErrada = "Olazinho";
		
		msg = new Mensagem(numeroRemetente, msgCorreta);
	}
	
	@Test
	public void sabeQualONumeroDoCelularQueEnviouAMensagem(){
		assertEquals(numeroRemetente, msg.obterRemetente());
	}
	
	@Test
	public void sabeQualONumeroDoCelularQueNaoEnviouAMensagem(){
		assertFalse(remetenteErrado.equals(msg.obterRemetente()));
	}
	
	@Test
	public void sabeSeAindaNaoFoiLida(){
		assertFalse(msg.foiLida());
	}
	
	@Test
	public void sabeSeJaFoiLida(){
		msg.obterTexto();
		assertTrue(msg.foiLida());
	}
	
	@Test
	public void podeSerLida(){
		assertEquals(msgCorreta, msg.obterTexto());
	}
	
	@Test
	public void sabeQualNaoEhSuaMensagem(){
		assertFalse(msgErrada.equals(msg.obterTexto()));
	}

}
