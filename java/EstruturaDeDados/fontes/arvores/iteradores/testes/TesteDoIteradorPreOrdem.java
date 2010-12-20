package arvores.iteradores.testes;

import static org.junit.Assert.*;
import ine5384.arvores.ArvoreBinaria;

import java.util.Iterator;

import org.junit.Test;

import arvores.arvoreBinariaDeBusca.ArvoreBuscaBinaria;

public class TesteDoIteradorPreOrdem extends TesteDoIterador{

	@Override
	protected ArvoreBinaria<String> retornarArvoreQueOIteradorPercorrera() {
		
		return new ArvoreBuscaBinaria<String>();
	}

	@Override
	protected Iterator<String> retornarIteradorASerTestado() {
		
		return arvoreQueOIteradorPercorreComDezElementos.retornaIteratorPreOrdem();
	}
	
	@Test
	public void oPrimeiroElementoNoIteradorEhARaizDaArvore(){
		assertEquals(arvoreQueOIteradorPercorreComDezElementos.retornaRaiz(), 
				iteradorDaArvoreComDezElementos.next());
	}
	
	@Test
	public void oIteradorPercorreAArvoreEmProfundidadeDeCimaParaBaixoEDaEsquerdaParaADireitaDaArvore(){
		
		assertEquals(letraE, iteradorDaArvoreComDezElementos.next());
		assertEquals(letraC, iteradorDaArvoreComDezElementos.next());
		assertEquals(letraB, iteradorDaArvoreComDezElementos.next());
		assertEquals(letraA, iteradorDaArvoreComDezElementos.next());
		assertEquals(letraD, iteradorDaArvoreComDezElementos.next());
		assertEquals(letraH, iteradorDaArvoreComDezElementos.next());
		assertEquals(letraF, iteradorDaArvoreComDezElementos.next());
		assertEquals(letraG, iteradorDaArvoreComDezElementos.next());
		assertEquals(letraJ, iteradorDaArvoreComDezElementos.next());
		assertEquals(letraI, iteradorDaArvoreComDezElementos.next());
		
	}

}
