package arvores.iteradores.testes;

import static org.junit.Assert.assertEquals;
import ine5384.arvores.ArvoreBinaria;

import java.util.Iterator;

import org.junit.Test;

import arvores.arvoreBinariaDeBusca.ArvoreBuscaBinaria;

public class TesteDoIteradorInOrdem extends TesteDoIterador{
	
	@Override
	protected ArvoreBinaria<String> retornarArvoreQueOIteradorPercorrera() {
		
		return new ArvoreBuscaBinaria<String>();
	}

	@Override
	protected Iterator<String> retornarIteradorASerTestado() {
		
		return arvoreQueOIteradorPercorreComDezElementos.retornaIteratorInOrdem();
	}
	
	@Test
	public void oPrimeiroElementoNoIteradorEhOElementoQuePossuiMaiorProfundidadeNaSubArvoreEsquerdaSeElaExistir(){
		assertEquals(letraA, 
				iteradorDaArvoreComDezElementos.next());
	}
	
	@Test
	public void oIteradorPercorreAArvoreEmProfundidadeDoElementoMaisAEsquerdaRetornandoOElementoAEsquerdaDepoisOMeioEDepoisADireita(){
	
		assertEquals(letraA, iteradorDaArvoreComDezElementos.next());
		assertEquals(letraB, iteradorDaArvoreComDezElementos.next());
		assertEquals(letraC, iteradorDaArvoreComDezElementos.next());
		assertEquals(letraD, iteradorDaArvoreComDezElementos.next());
		
		assertEquals(letraE, iteradorDaArvoreComDezElementos.next());
		
		assertEquals(letraF, iteradorDaArvoreComDezElementos.next());
		assertEquals(letraG, iteradorDaArvoreComDezElementos.next());
		assertEquals(letraH, iteradorDaArvoreComDezElementos.next());
		assertEquals(letraI, iteradorDaArvoreComDezElementos.next());
		assertEquals(letraJ, iteradorDaArvoreComDezElementos.next());
		
		
	}
}
