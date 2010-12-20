package tabelaHash.testes;

import static org.junit.Assert.*;


import org.junit.Before;
import org.junit.Test;

import tabelaHash.TabelaHashConcreta;

public class TesteDaTabelaHash {

	private Integer chaveUm, chaveDois,
	chaveTres, chaveQuatro, chaveCinco,
	chaveSeis, chaveDez, chaveQueGeraMesmoRestoQueChaveDez;
	
	private String letraA, letraB, letraC,
	letraD, letraE, letraF;
	
	private TabelaHashConcreta<Integer,String> tabelaHashTamanhoDez, outraTabelaHashDeTamanhoDez;
	
	@Before
	public void criarComponentesNecessarios(){
		chaveUm = 1;
		chaveDois = 2;
		chaveTres = 3;
		chaveQuatro = 4;
		chaveCinco = 5;
		chaveSeis = 6;
		chaveDez = 10;
		chaveQueGeraMesmoRestoQueChaveDez = 20;
		
		letraA = "a";
		letraB = "b";
		letraC = "c";
		letraD = "d";
		letraE = "e";
		letraF = "f";
		
		tabelaHashTamanhoDez = new TabelaHashConcreta<Integer,String>(10);
		outraTabelaHashDeTamanhoDez = new TabelaHashConcreta<Integer,String>(10);
	}
	
	@Test
	public void inicialmenteATabelaEstaVazia(){
		assertSame(0, tabelaHashTamanhoDez.retorneTamanho());
	}
	
	@Test
	public void seColocarUmaChaveElaFicaraNaTabela(){
		tabelaHashTamanhoDez.insere(chaveUm, letraA);
		assertTrue(tabelaHashTamanhoDez.existe(chaveUm));
	}
	
	@Test
	public void seNaoColocarUmaChaveElaNaoFicaraNaTabela(){
		tabelaHashTamanhoDez.insere(chaveUm, letraA);
		assertFalse(tabelaHashTamanhoDez.existe(chaveDois));
	}
	
	@Test
	public void sabeSeExisteUmaChaveNaTabela(){
		tabelaHashTamanhoDez.insere(chaveUm, letraA);
		assertTrue(tabelaHashTamanhoDez.existe(chaveUm));
	}
	
	@Test
	public void sabeSeNaoExisteUmaChaveNaTabela(){
		assertFalse(tabelaHashTamanhoDez.existe(chaveDois));
		assertFalse(tabelaHashTamanhoDez.existe(chaveUm));
	}
	
	@Test
	public void sabeQuantosElementosPossui(){
		assertSame(0, tabelaHashTamanhoDez.retorneTamanho());
		
		tabelaHashTamanhoDez.insere(chaveUm, letraA);
		assertSame(1, tabelaHashTamanhoDez.retorneTamanho());
		
		tabelaHashTamanhoDez.insere(chaveDois, letraA);
		assertSame(2, tabelaHashTamanhoDez.retorneTamanho());
		
		tabelaHashTamanhoDez.insere(chaveTres, letraA);
		assertSame(3, tabelaHashTamanhoDez.retorneTamanho());
		
		tabelaHashTamanhoDez.insere(chaveQuatro, letraA);
		assertSame(4, tabelaHashTamanhoDez.retorneTamanho());
	}
	
	@Test
	public void seInserirDuasVezesAMesmaChaveAChaveAntigaESeuValorAssociadoSeraoSobreescritos(){
		tabelaHashTamanhoDez.insere(chaveUm, letraA);
		tabelaHashTamanhoDez.insere(chaveUm, letraB);
		
		assertSame(1, tabelaHashTamanhoDez.retorneTamanho());
		assertEquals(letraB, tabelaHashTamanhoDez.retorna(chaveUm));
	}
	
	@Test
	public void aposInserirVariosValoresMapeadosPorChavesPodeRetornarTodosElesPelaChaveDada(){
		
		tabelaHashTamanhoDez.insere(chaveUm, letraA);
		tabelaHashTamanhoDez.insere(chaveDois, letraB);
		tabelaHashTamanhoDez.insere(chaveTres, letraC);
		tabelaHashTamanhoDez.insere(chaveQuatro, letraD);
		tabelaHashTamanhoDez.insere(chaveCinco, letraE);
		tabelaHashTamanhoDez.insere(chaveSeis, letraF);
		
		assertSame(6, tabelaHashTamanhoDez.retorneTamanho());
		
		assertEquals(letraA, tabelaHashTamanhoDez.retorna(chaveUm));
		assertEquals(letraB, tabelaHashTamanhoDez.retorna(chaveDois));
		assertEquals(letraC, tabelaHashTamanhoDez.retorna(chaveTres));
		assertEquals(letraD, tabelaHashTamanhoDez.retorna(chaveQuatro));
		assertEquals(letraE, tabelaHashTamanhoDez.retorna(chaveCinco));
		assertEquals(letraF, tabelaHashTamanhoDez.retorna(chaveSeis));
	}
	
	@Test
	public void seInserirDuasVezesChavesQueGeramOMesmoRestoAsDuasFicamArmazenadas(){
		tabelaHashTamanhoDez.insere(chaveDez, letraA);
		tabelaHashTamanhoDez.insere(chaveQueGeraMesmoRestoQueChaveDez, letraB);
		
		assertSame(2, tabelaHashTamanhoDez.retorneTamanho());
		
		assertEquals(letraA, tabelaHashTamanhoDez.retorna(chaveDez));
		assertEquals(letraB, tabelaHashTamanhoDez.retorna(chaveQueGeraMesmoRestoQueChaveDez));
	}
	
	@Test
	public void dadoUmaChavePodeRetornarOValorMapeadoPorEla(){
		tabelaHashTamanhoDez.insere(chaveDez, letraA);
		assertEquals(letraA, tabelaHashTamanhoDez.retorna(chaveDez));
	}
	
	@Test
	public void dadoUmaChaveNaoPodeRetornarOValorMapeadoPorElaSeNaoFoiInseridoRetornaNull(){
		
		assertNull(tabelaHashTamanhoDez.retorna(chaveDez));
	}
	
	@Test
	public void sabeSeEstaVazia(){
		assertTrue(tabelaHashTamanhoDez.estaVazia());
	}
	
	@Test
	public void sabeQuandoNaoEstaVazia(){
		tabelaHashTamanhoDez.insere(chaveDez, letraA);
		assertFalse(tabelaHashTamanhoDez.estaVazia());
	}
	
	@Test
	public void SeExisteUmaChaveQUeGeraMesmoRestoSabeQueEstaChaveNaoExistenaTabela(){
		
		tabelaHashTamanhoDez.insere(chaveDez, letraA);
		
		assertFalse(tabelaHashTamanhoDez.existe(chaveQueGeraMesmoRestoQueChaveDez));
		assertTrue(tabelaHashTamanhoDez.existe(chaveDez));
	}
	
	@Test
	public void sabeQuandoNaoExisteUmaChaveNaTabela(){
		
		tabelaHashTamanhoDez.insere(chaveDez, letraA);
		
		assertTrue(tabelaHashTamanhoDez.existe(chaveDez));
		assertFalse(tabelaHashTamanhoDez.existe(chaveUm));
		assertFalse(tabelaHashTamanhoDez.existe(chaveDois));
	}
	
	@Test
	public void seExisteUmaChaveQueGeraMesmoRestoSabeQueEstaChaveNaoExisteNaTabelaERetornaNull(){
		
		tabelaHashTamanhoDez.insere(chaveDez, letraA);
		
		assertNotNull(tabelaHashTamanhoDez.retorna(chaveDez));
		assertNull(tabelaHashTamanhoDez.retorna(chaveQueGeraMesmoRestoQueChaveDez));
	}
	
	@Test
	public void seRemoverUmaChaveElaESeuValorAssociadoNaoSeEncontraraoMaisNaTabela(){
		
		tabelaHashTamanhoDez.insere(chaveDez, letraA);
		tabelaHashTamanhoDez.remove(chaveDez);
		assertFalse(tabelaHashTamanhoDez.existe(chaveDez));
		
	}
	
	@Test
	public void seRemoverUmaChaveRetornaOObjetoQueAquelaChaveApontava(){
		
		tabelaHashTamanhoDez.insere(chaveDez, letraA);
		assertEquals(letraA, tabelaHashTamanhoDez.remove(chaveDez));
		
		
	}
	
	@Test
	public void seRemoverUmaChaveONumeroDeElementosDiminui(){
		
		tabelaHashTamanhoDez.insere(chaveDez, letraA);
		assertEquals(1, tabelaHashTamanhoDez.retorneTamanho());
		tabelaHashTamanhoDez.remove(chaveDez);
		assertEquals(0, tabelaHashTamanhoDez.retorneTamanho());
	
	}
	
	@Test
	public void seRemoverUmaChaveEExistirOutraQueGeraOMesmoRestoAQueGeraOMesmoRestoFicaNaTabela(){
		
		tabelaHashTamanhoDez.insere(chaveDez, letraA);
		tabelaHashTamanhoDez.insere(chaveQueGeraMesmoRestoQueChaveDez, letraB);
		assertEquals(letraA, tabelaHashTamanhoDez.remove(chaveDez));
		assertTrue(tabelaHashTamanhoDez.existe(chaveQueGeraMesmoRestoQueChaveDez));
		assertFalse(tabelaHashTamanhoDez.existe(chaveDez));
		assertEquals(1, tabelaHashTamanhoDez.retorneTamanho());
		
	}
	
	@Test
	public void testeAvancadoDaRemocao(){
		
		tabelaHashTamanhoDez.insere(chaveUm, letraA);
		tabelaHashTamanhoDez.insere(chaveDois, letraB);
		tabelaHashTamanhoDez.insere(chaveTres, letraC);
		tabelaHashTamanhoDez.insere(chaveQuatro, letraD);
		tabelaHashTamanhoDez.insere(chaveCinco, letraE);
		
		assertEquals(5, tabelaHashTamanhoDez.retorneTamanho());
		
		assertEquals(letraA, tabelaHashTamanhoDez.remove(chaveUm));
		assertEquals(4, tabelaHashTamanhoDez.retorneTamanho());
		
		assertEquals(letraB, tabelaHashTamanhoDez.remove(chaveDois));
		assertEquals(3, tabelaHashTamanhoDez.retorneTamanho());
		
		assertEquals(letraC, tabelaHashTamanhoDez.remove(chaveTres));
		assertEquals(2, tabelaHashTamanhoDez.retorneTamanho());
		
		assertEquals(letraD, tabelaHashTamanhoDez.remove(chaveQuatro));
		assertEquals(1, tabelaHashTamanhoDez.retorneTamanho());
		
		assertEquals(letraE, tabelaHashTamanhoDez.remove(chaveCinco));
		assertEquals(0, tabelaHashTamanhoDez.retorneTamanho());
		
		
	}
	
	@Test
	public void sabeOSeuTamanho(){
		assertEquals(0, tabelaHashTamanhoDez.retorneTamanho());
		tabelaHashTamanhoDez.insere(chaveUm, letraA);
		assertEquals(1, tabelaHashTamanhoDez.retorneTamanho());
		tabelaHashTamanhoDez.insere(chaveDois, letraB);
		assertEquals(2, tabelaHashTamanhoDez.retorneTamanho());
		tabelaHashTamanhoDez.insere(chaveTres, letraC);
		assertEquals(3, tabelaHashTamanhoDez.retorneTamanho());
		tabelaHashTamanhoDez.insere(chaveQuatro, letraD);
		assertEquals(4, tabelaHashTamanhoDez.retorneTamanho());
		tabelaHashTamanhoDez.insere(chaveCinco, letraE);
		assertEquals(5, tabelaHashTamanhoDez.retorneTamanho());
	}
	
	@Test
	public void aposSerEsvaziadaATabelaNaoContemMaisNenhumaChave(){
		tabelaHashTamanhoDez.insere(chaveUm, letraA);
		tabelaHashTamanhoDez.insere(chaveDois, letraB);
		tabelaHashTamanhoDez.insere(chaveTres, letraC);
		tabelaHashTamanhoDez.insere(chaveQuatro, letraD);
		tabelaHashTamanhoDez.insere(chaveCinco, letraE);
		
		assertEquals(5, tabelaHashTamanhoDez.retorneTamanho());
		tabelaHashTamanhoDez.esvazie();
		assertEquals(0, tabelaHashTamanhoDez.retorneTamanho());
		assertFalse(tabelaHashTamanhoDez.existe(chaveUm));
		assertFalse(tabelaHashTamanhoDez.existe(chaveDois));
		assertFalse(tabelaHashTamanhoDez.existe(chaveTres));
		assertFalse(tabelaHashTamanhoDez.existe(chaveQuatro));
		assertFalse(tabelaHashTamanhoDez.existe(chaveCinco));
	}
	
	@Test
	public void seTentarRemoverUmaChaveQueNaoExisteNaTabelaRetornaNull(){
		tabelaHashTamanhoDez.insere(chaveUm, letraA);
		assertNull(tabelaHashTamanhoDez.remove(chaveQuatro));
	}
	
	@Test
	public void nuncaFicaCheia(){
		for(int i = 0; i <= 10000; i++){
			tabelaHashTamanhoDez.insere(i, letraA);
		}
		assertFalse(tabelaHashTamanhoDez.estaCheia());
	}
	
	@Test
	public void sabeDizerSeUmaTabelaEhIgualAOutra(){
		tabelaHashTamanhoDez.insere(chaveUm, letraA);
		tabelaHashTamanhoDez.insere(chaveDois, letraB);
		tabelaHashTamanhoDez.insere(chaveTres, letraC);
		tabelaHashTamanhoDez.insere(chaveQuatro, letraD);
		tabelaHashTamanhoDez.insere(chaveCinco, letraE);
		
		outraTabelaHashDeTamanhoDez.insere(chaveUm, letraA);
		outraTabelaHashDeTamanhoDez.insere(chaveDois, letraB);
		outraTabelaHashDeTamanhoDez.insere(chaveTres, letraC);
		outraTabelaHashDeTamanhoDez.insere(chaveQuatro, letraD);
		outraTabelaHashDeTamanhoDez.insere(chaveCinco, letraE);
		
		assertEquals(tabelaHashTamanhoDez, outraTabelaHashDeTamanhoDez);
		
	}
	
	@Test
	public void sabeDizerSeUmaTabelaNaoEhIgualAOutra(){
		
		tabelaHashTamanhoDez.insere(chaveUm, letraA);
		tabelaHashTamanhoDez.insere(chaveDois, letraB);
		tabelaHashTamanhoDez.insere(chaveTres, letraC);
		tabelaHashTamanhoDez.insere(chaveQuatro, letraD);
		tabelaHashTamanhoDez.insere(chaveCinco, letraE);
		
		outraTabelaHashDeTamanhoDez.insere(chaveUm, letraB);
		outraTabelaHashDeTamanhoDez.insere(chaveDois, letraC);
		outraTabelaHashDeTamanhoDez.insere(chaveTres, letraA);
		outraTabelaHashDeTamanhoDez.insere(chaveQuatro, letraD);
		outraTabelaHashDeTamanhoDez.insere(chaveCinco, letraE);
		
		assertFalse(tabelaHashTamanhoDez.equals(outraTabelaHashDeTamanhoDez));
	}
	

}
