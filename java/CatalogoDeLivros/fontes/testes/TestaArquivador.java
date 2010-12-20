package testes;

import static org.junit.Assert.assertEquals;

import java.io.File;

import implementacao.Arquivador;

import org.junit.Before;
import org.junit.Test;


public class TestaArquivador {
	
	private String localizacaoDoArquivo = "fontes/infraEstrutura/arquivo.txt";	
	private Arquivador arquivador;
	private int codigo = 12345;
	private double valor = 19.90;
	private String texto = "qualquerNome";
	
	@Before
	public void iniciar(){
		File arquivo = new File(localizacaoDoArquivo);
		arquivador = new Arquivador(arquivo);
	}
	
	@Test
	public void escreverUmInteiroNoArquivo(){
		long posicao = arquivador.escreva(codigo);
		assertEquals(codigo, arquivador.leiaInteiro(posicao));
	}
	
	@Test
	public void escreverUmDoubleNoArquivo(){
		long posicao = arquivador.escreva(valor);
		assertEquals(valor, arquivador.leiaDouble(posicao));
	}
	
	@Test
	public void escreverUmTextoNoArquivo(){
		long posicao = arquivador.escreva(texto );
		assertEquals(texto, arquivador.leiaTexto(posicao));
	}
	
	@Test
	public void precisamDe52BytesParaSeEscreverUmLivro(){
		assertEquals(0, arquivador.escreva(codigo));
		assertEquals(4, arquivador.escreva("nome"));
		assertEquals(26, arquivador.escreva("autor"));
		assertEquals(48, arquivador.escreva(valor));
		assertEquals(52, arquivador.obterPonteiro());
	}
	
	@Test
	public void oArquivadorPodePularBytes(){
		assertEquals(0, arquivador.obterPonteiro());
		arquivador.puleBytes(10);
		assertEquals(10, arquivador.obterPonteiro());
	}

}
