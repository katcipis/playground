package testesAbstratosDoComponenteGedix;

import static org.junit.Assert.*;
import infraestruturaDoComponenteGedix.ComponenteGedixComGrade;
import infraestruturaDoTransformadorParaXML.TransformavelEmXMLComGrade;

import org.junit.Before;
import org.junit.Test;

import listasDeTestesDoComponenteGedix.ListaDeTestesDoComponenteGedixComGrade;

public abstract class TesteAbstratoDoComponenteGedixComGrade extends TesteAbstratoDoComponenteGedix 
												implements ListaDeTestesDoComponenteGedixComGrade{

	protected ComponenteGedixComGrade componenteGedixComGrade;

	public abstract void criarRetânguloDixComGrade();
	
	@Before
	public void antesDosTestesDoComponenteGedixComGrade(){
		criarRetânguloDixComGrade();
	}
	
	@Test
	public void oNúmeroDeColunasInicialÉUm() {
		assertSame(1, componenteGedixComGrade.obterNúmeroDeColunas());
	}

	@Test
	public void oNúmeroDeColunasNãoPodeSerIgualOuMenorQueZero() {
		assertFalse(componenteGedixComGrade.alterarNúmeroDeColunas(0));
		assertFalse(componenteGedixComGrade.alterarNúmeroDeColunas(-1));
		assertSame(1, componenteGedixComGrade.obterNúmeroDeColunas());
	}

	@Test
	public void oNúmeroDeColunasPodeSerAlterado() {
		assertTrue(componenteGedixComGrade.alterarNúmeroDeColunas(3));
		assertSame(3, componenteGedixComGrade.obterNúmeroDeColunas());
	}

	@Test
	public void oNúmeroDeLinhasInicialÉUm() {
		assertSame(1, componenteGedixComGrade.obterNúmeroDeLinhas());
	}

	@Test
	public void oNúmeroDeLinhasNãoPodeSerIgualOuMenorQueZero() {
		assertFalse(componenteGedixComGrade.alterarNúmeroDeLinhas(0));
		assertFalse(componenteGedixComGrade.alterarNúmeroDeLinhas(-1));
		assertSame(1, componenteGedixComGrade.obterNúmeroDeLinhas());
	}

	@Test
	public void oNúmeroDeLinhasPodeSerAlterado() {
		assertTrue(componenteGedixComGrade.alterarNúmeroDeLinhas(3));
		assertSame(3, componenteGedixComGrade.obterNúmeroDeLinhas());
	}

	@Test
	public void sabeQuantasColunasPossui() {
		assertSame(1, componenteGedixComGrade.obterNúmeroDeColunas());
	}

	@Test
	public void sabeQuantasLinhasPossui() {
		assertSame(1, componenteGedixComGrade.obterNúmeroDeLinhas());
	}
	
	@Test
	public void éTransformávelEmXMLComGrade(){
		assertTrue(componenteGedixComGrade instanceof TransformavelEmXMLComGrade);
	}

}
