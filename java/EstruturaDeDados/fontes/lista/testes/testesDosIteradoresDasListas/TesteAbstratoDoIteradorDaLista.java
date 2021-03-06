package lista.testes.testesDosIteradoresDasListas;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;
import ine5384.excecoes.ExcecaoEstruturaCheia;
import ine5384.excecoes.ExcecaoEstruturaVazia;
import ine5384.excecoes.ExcecaoOperacaoIlegal;
import ine5384.excecoes.ExcecaoPosicaoIlegal;
import ine5384.lineares.Lista;
import ine5384.pp.Iterador;

import org.junit.Before;
import org.junit.Test;

public abstract class TesteAbstratoDoIteradorDaLista implements ListaDeTestesDoIterador {
	
	private Iterador<String> iteradorDaListaComCincoElementos;
	private Lista<String> listaComCincoElementos;
	private String primeiroElemento, segundoElemento,
	terceiroElemento, quartoElemento, quintoElemento;
	
	
	@Before
	public void criarComponentesNecessarios() throws ExcecaoEstruturaCheia, ExcecaoPosicaoIlegal{
		listaComCincoElementos = criarLista();
		
		primeiroElemento = "primeiro";
	    segundoElemento = "segundo";
	    terceiroElemento = "terceiro";
	    quartoElemento = "quarto";
	    quintoElemento = "quinto";
	    
	    listaComCincoElementos.insiraNaPosicao(primeiroElemento, 1);
	    listaComCincoElementos.insiraNaPosicao(segundoElemento, 1);
	    listaComCincoElementos.insiraNaPosicao(terceiroElemento, 1);
	    listaComCincoElementos.insiraNaPosicao(quartoElemento, 1);
	    listaComCincoElementos.insiraNaPosicao(quintoElemento, 1);
	    
	    iteradorDaListaComCincoElementos = listaComCincoElementos.retorneIterador();
	}

	protected abstract Lista<String> criarLista();
	
	@Test
	public void primeiroElementoDoIteradorEquivaleAoPrimeiroDaLista() throws ExcecaoEstruturaVazia, ExcecaoPosicaoIlegal, ExcecaoOperacaoIlegal{
		assertEquals(listaComCincoElementos.retorneDaPosicao(1),
				iteradorDaListaComCincoElementos.retorneProximo());
	}
	
	@Test
	public void segundoElementoDoIteradorEquivaleAoSegundoDaLista() throws ExcecaoEstruturaVazia, ExcecaoPosicaoIlegal, ExcecaoOperacaoIlegal{
		iteradorDaListaComCincoElementos.retorneProximo();
		
		assertEquals(listaComCincoElementos.retorneDaPosicao(2),
				iteradorDaListaComCincoElementos.retorneProximo());
	}
	
	@Test
	public void terceiroElementoDoIteradorEquivaleAoTerceiroDaLista() throws ExcecaoEstruturaVazia, ExcecaoPosicaoIlegal, ExcecaoOperacaoIlegal{
		iteradorDaListaComCincoElementos.retorneProximo();
		iteradorDaListaComCincoElementos.retorneProximo();
		
		assertEquals(listaComCincoElementos.retorneDaPosicao(3),
				iteradorDaListaComCincoElementos.retorneProximo());
	}
	
	@Test
	public void quartoElementoDoIteradorEquivaleAoQuartoDaLista() throws ExcecaoEstruturaVazia, ExcecaoPosicaoIlegal, ExcecaoOperacaoIlegal{
		iteradorDaListaComCincoElementos.retorneProximo();
		iteradorDaListaComCincoElementos.retorneProximo();
		iteradorDaListaComCincoElementos.retorneProximo();
		
		assertEquals(listaComCincoElementos.retorneDaPosicao(4),
				iteradorDaListaComCincoElementos.retorneProximo());
	}
	
	@Test
	public void quintoElementoDoIteradorEquivaleAoQuintoDaLista() throws ExcecaoEstruturaVazia, ExcecaoPosicaoIlegal, ExcecaoOperacaoIlegal{
		iteradorDaListaComCincoElementos.retorneProximo();
		iteradorDaListaComCincoElementos.retorneProximo();
		iteradorDaListaComCincoElementos.retorneProximo();
		iteradorDaListaComCincoElementos.retorneProximo();
		
		assertEquals(listaComCincoElementos.retorneDaPosicao(5),
				iteradorDaListaComCincoElementos.retorneProximo());
	}
	
	@Test(expected = ExcecaoOperacaoIlegal.class)
	public void seTentarRetornarUmProximoQueNaoExisteLancaUmaExcecaoOperacaoIlegal() throws ExcecaoOperacaoIlegal{
		for(int i = 1; i <=6; i++){
			iteradorDaListaComCincoElementos.retorneProximo();
		}
		
	}
	
	@Test
	public void sabeDizerSePossuiUmProximo() throws ExcecaoOperacaoIlegal{
		
		assertTrue(iteradorDaListaComCincoElementos.temMais());
		
		for(int i = 1; i <=4; i++){
			iteradorDaListaComCincoElementos.retorneProximo();
			
		}
		assertTrue(iteradorDaListaComCincoElementos.temMais());
		iteradorDaListaComCincoElementos.retorneProximo();
		assertFalse(iteradorDaListaComCincoElementos.temMais());
	}

}
