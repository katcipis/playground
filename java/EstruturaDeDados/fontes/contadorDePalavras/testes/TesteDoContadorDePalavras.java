package contadorDePalavras.testes;

import java.util.Iterator;

import org.junit.Before;
import org.junit.Test;

import tabelaHash.TabelaHash;
import contadorDePalavras.ContadorDePalavras;

public class TesteDoContadorDePalavras {
	
	private String frase;
	private ContadorDePalavras contador;

	
	@Before
	public void criarComponentes(){
		frase = "A casa de madeira e de mel e Mel era doce.";
		contador = new ContadorDePalavras(); 
	}
	
	@Test
	public void testeDoContador(){
		TabelaHash<String, Integer> resultado =
		contador.contarOcorrencias(frase);
		
		Iterator<String> iterador = resultado.retornaChaves();
		while(iterador.hasNext()){
			String chave = iterador.next();
			System.out.println(chave.concat(": ").concat(resultado.retorna(chave).toString()));
			
		}
		
		/*
		assertSame(2, resultado.retorna("os"));
		assertSame(2, resultado.retorna("testes"));
		assertSame(3, resultado.retorna("de"));
		assertSame(1, resultado.retorna("unidade"));
		assertSame(1, resultado.retorna("e"));
		assertSame(1, resultado.retorna("módulo"));
		assertSame(1, resultado.retorna("normalmente"));
		assertSame(1, resultado.retorna("responsabilidade"));
		assertSame(1, resultado.retorna("dos"));
		assertSame(1, resultado.retorna("programadores"));
		assertSame(1, resultado.retorna("desenvolveram"));
		assertSame(1, resultado.retorna("o"));
		assertSame(1, resultado.retorna("componente"));
		*/
	}
	
	

}
