package arvores.arvoreB.testes;

import static org.junit.Assert.*;
import ine5384.arvores.ArvoreB;

import org.junit.Before;
import org.junit.Test;

import arvores.arvoreB.ArvoreBConcreta;

public class TesteDaArvoreB {
	
	private ArvoreB<String> arvoreBVaziaDeNQuatro;
	private String letraA, letraB, letraC,
	letraD, letraE, letraF, letraG, letraH,
	letraI, letraJ, letraL, letraM;
	
	@Before
	public void criarComponentesNecessarios(){
		
		letraA = "a";
		letraB = "b";
		letraC = "c";
		letraD = "d";
		letraE = "e";
		letraF = "f";
		letraG = "g";
		letraH = "h";
		letraI = "i";
		letraJ = "j";
		letraL = "l";
		letraM = "m";
		
		arvoreBVaziaDeNQuatro = new ArvoreBConcreta<String>(4);
		
	}
	
	@Test
	public void seInserirUmElementoNaArvoreEleFicaNaRaizEElaNaoEstaMaisVazia(){
		arvoreBVaziaDeNQuatro.insere(letraA);
		assertTrue(arvoreBVaziaDeNQuatro.contem(letraA));
		assertFalse(arvoreBVaziaDeNQuatro.estaVazia());
	}
	
	@Test
	public void seNaoInserirUmElementoNaArvoreEleNaoEstarahLah(){
		arvoreBVaziaDeNQuatro.insere(letraB);
		assertFalse(arvoreBVaziaDeNQuatro.contem(letraA));
	}
	
	@Test
	public void seInserirDoisElementoNaArvoreEleFicaNaRaizEElaNaoEstaMaisVazia(){
		arvoreBVaziaDeNQuatro.insere(letraA);
		assertTrue(arvoreBVaziaDeNQuatro.contem(letraA));
		assertFalse(arvoreBVaziaDeNQuatro.estaVazia());
	}
	
	@Test
	public void sabeQuandoEstaVazia(){
		
		assertTrue(arvoreBVaziaDeNQuatro.estaVazia());
	}
	
	@Test
	public void sabeQuantosElementosPossui(){
		assertSame(0, arvoreBVaziaDeNQuatro.retorneTamanho());
		
		arvoreBVaziaDeNQuatro.insere(letraA);
		assertSame(1, arvoreBVaziaDeNQuatro.retorneTamanho());
		
		arvoreBVaziaDeNQuatro.insere(letraB);
		assertSame(2, arvoreBVaziaDeNQuatro.retorneTamanho());
		
		arvoreBVaziaDeNQuatro.insere(letraC);
		assertSame(3, arvoreBVaziaDeNQuatro.retorneTamanho());
	}
	
	@Test
	public void seInserirMaisElementosQueOLimiteSeraoCriadasDuasSubArvores(){
		
		arvoreBVaziaDeNQuatro.insere(letraA);
		arvoreBVaziaDeNQuatro.insere(letraB);
		arvoreBVaziaDeNQuatro.insere(letraC);
		arvoreBVaziaDeNQuatro.insere(letraD);
		arvoreBVaziaDeNQuatro.insere(letraE);
		
		
		assertTrue(arvoreBVaziaDeNQuatro.contem(letraA));
		assertTrue(arvoreBVaziaDeNQuatro.contem(letraB));
		
		assertTrue(arvoreBVaziaDeNQuatro.contem(letraC));
		
		assertTrue(arvoreBVaziaDeNQuatro.contem(letraD));
		assertTrue(arvoreBVaziaDeNQuatro.contem(letraE));
		
		assertSame(5, arvoreBVaziaDeNQuatro.retorneTamanho());
	}
	
	

}
