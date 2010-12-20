package testes;

import static org.junit.Assert.*;
import ine5384.arvores.ArvoreB;
import ine5384.excecoes.ExcecaoArvore;
import infraEstrutura.estruturas.ArvoreBConcreta;

import java.util.Random;

import org.junit.Before;
import org.junit.Test;


public class TestaArvoreB {
	
	ArvoreB<Integer> arvoreComUmElemento, arvoreVazia, arvoreComDoisElementos;
	private int n = 3;
	private Integer elementoQualquer, elementoUm, elementoDois, elementoTres;
	
	@Before
	public void preparar(){
		
		elementoQualquer = new Random().nextInt();
		elementoUm = 100;
		elementoDois = 200;
		elementoTres = 0;
		
		arvoreVazia = new ArvoreBConcreta<Integer>(n);
		
		arvoreComUmElemento = new ArvoreBConcreta<Integer>(n);
		arvoreComUmElemento.insere(elementoUm);
		
		arvoreComDoisElementos = new ArvoreBConcreta<Integer>(n);
		arvoreComDoisElementos.insere(elementoUm);
		arvoreComDoisElementos.insere(elementoDois);
		
	}
	
	@Test
	public void umaArvoreInicialEhVazia(){
		assertTrue(arvoreVazia.estaVazia());
	}
	
	@Test
	public void umaArvoreComUmElementoNaoEhVazia(){
		assertFalse(arvoreComUmElemento.estaVazia());
	}
	
	@Test
	public void umaArvoreVaziaTemTamanhoZero(){
		assertEquals(0, arvoreVazia.retorneTamanho());
	}
	
	@Test
	public void aArvoreComUmElementoTemTamanhoUm(){
		assertEquals(1, arvoreComUmElemento.retorneTamanho());
	}
	
	@Test
	public void aoRemoverOTamanhoDecresceUm(){
		arvoreComUmElemento.remove(1);
		assertEquals(0, arvoreComUmElemento.retorneTamanho());
	}
	
	@Test(expected = ExcecaoArvore.class)
	public void naoPodeRemoverDeUmaArvoreVazia(){
		arvoreVazia.remove(elementoQualquer);
	}
	
	@Test
	public void aArvoreComUmElementoContemOElementoUm(){
		assertTrue(arvoreComUmElemento.contem(elementoUm));
	}
	
	@Test
	public void aArvoreComUmElementoNaoContemOElementoDois(){
		assertFalse(arvoreComUmElemento.contem(elementoDois));
	}
	
	@Test
	public void aArvoreVaziaNaoContemElementos(){
		assertFalse(arvoreVazia.contem(elementoQualquer));
	}
	
	@Test
	public void aArvoreComDoisElementosContemOElementoUmEDois(){
		assertTrue(arvoreComDoisElementos.contem(elementoUm));
		assertTrue(arvoreComDoisElementos.contem(elementoDois));
	}
	
	@Test
	public void aArvoreComTresElementosContemOElementoUmDoisETres(){
		arvoreComDoisElementos.insere(elementoTres);
		
		assertTrue(arvoreComDoisElementos.contem(elementoUm));
		assertTrue(arvoreComDoisElementos.contem(elementoDois));
		assertTrue(arvoreComDoisElementos.contem(elementoTres));
		
		System.out.println(arvoreComDoisElementos.toString());
	}
	
}
