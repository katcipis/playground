package arvores.iteradores.testes;

import static org.junit.Assert.assertEquals;
import ine5384.arvores.ArvoreBinaria;

import java.util.Iterator;

import org.junit.Test;

import arvores.arvoreBinariaDeBusca.ArvoreBuscaBinaria;

public class TesteDoIteradorPosOrdem extends TesteDoIterador{
	@Override
	protected ArvoreBinaria<String> retornarArvoreQueOIteradorPercorrera() {
		
		return new ArvoreBuscaBinaria<String>();
	}

	@Override
	protected Iterator<String> retornarIteradorASerTestado() {
		
		return arvoreQueOIteradorPercorreComDezElementos.retornaIteratorPosOrdem();
	}
	
	@Test
	public void oPrimeiroElementoNoIteradorEhOElementoQuePossuiMaiorProfundidadeNaSubArvoreEsquerdaSeElaExistir(){
		assertEquals(letraA, 
				iteradorDaArvoreComDezElementos.next());
	}
	
	@Test
	public void oUltimoElementoNoIteradorEhARaiz(){
		for(int i = 1; i < 10; i++){
			iteradorDaArvoreComDezElementos.next();
		}
		assertEquals(arvoreQueOIteradorPercorreComDezElementos.retornaRaiz(), 
				iteradorDaArvoreComDezElementos.next());
	}
	
	@Test
	public void oIteradorPercorreAArvoreEmProfundidadeDeBaixoParaCimaEDaEsquerdaParaADireitaDaArvore(){
		assertEquals(letraA, iteradorDaArvoreComDezElementos.next());
		assertEquals(letraB, iteradorDaArvoreComDezElementos.next());
		assertEquals(letraD, iteradorDaArvoreComDezElementos.next());
		assertEquals(letraC, iteradorDaArvoreComDezElementos.next());
		assertEquals(letraG, iteradorDaArvoreComDezElementos.next());
		assertEquals(letraF, iteradorDaArvoreComDezElementos.next());
		assertEquals(letraI, iteradorDaArvoreComDezElementos.next());
		assertEquals(letraJ, iteradorDaArvoreComDezElementos.next());
		assertEquals(letraH, iteradorDaArvoreComDezElementos.next());
		assertEquals(letraE, iteradorDaArvoreComDezElementos.next());
		
	}
	
}
