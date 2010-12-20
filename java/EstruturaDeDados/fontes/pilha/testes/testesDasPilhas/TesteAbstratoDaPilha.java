package pilha.testes.testesDasPilhas;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import ine5384.excecoes.ExcecaoEstruturaCheia;
import ine5384.excecoes.ExcecaoEstruturaVazia;

import org.junit.Before;
import org.junit.Test;

import pilha.pilhas.Pilha;
import pilha.testes.listasDeTestesDasPilhas.ListaDeTestesDaPilha;


public abstract class TesteAbstratoDaPilha implements ListaDeTestesDaPilha {
    
    protected String elementoUm, elementoDois, elementoTres, elementoQuatro;
    
    protected Pilha<String> pilhaVazia, outraPilhaVazia;
    
    @Before
    public void construirComponentes(){
        elementoUm = "elementoUm";
        elementoDois = "elementoDois";
        elementoTres = "elementoTres";
        elementoQuatro = "elementoQuatro";
        pilhaVazia = criarPilha();
        outraPilhaVazia = criarPilha();
    }

    protected abstract Pilha<String> criarPilha();
    
    @Test
    public void inserindoUmElementoEmUmaPilhaVazia() throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia{
        pilhaVazia.empilhe(elementoUm);
        assertEquals(elementoUm, pilhaVazia.retorneTopo());
    }
    
    @Test
    public void inserindoUmElementoEmUmaPilhaComUmElementoOElementoInseridoFicaNoTopo() throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia{
        pilhaVazia.empilhe(elementoUm);
        pilhaVazia.empilhe(elementoDois);
        assertEquals(elementoDois, pilhaVazia.retorneTopo());
    }
    
    @Test
    public void elementosInseridosSempreFicamNoTopo() throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia{
        
        pilhaVazia.empilhe(elementoUm);
        
        pilhaVazia.empilhe(elementoDois);
        assertEquals(elementoDois, pilhaVazia.retorneTopo());
        
        pilhaVazia.empilhe(elementoTres);
        assertEquals(elementoTres, pilhaVazia.retorneTopo());
        
        pilhaVazia.empilhe(elementoQuatro);
        assertEquals(elementoQuatro, pilhaVazia.retorneTopo());
    }
    
    @Test
    public void podeRemoverOElementoQueSeEncontraNoTopoEOTopoSeraOAntecessorDoTopo() throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia{
        
        pilhaVazia.empilhe(elementoUm);
        pilhaVazia.empilhe (elementoDois);
        pilhaVazia.empilhe(elementoTres);
        pilhaVazia.empilhe(elementoQuatro);
        
        assertEquals(elementoQuatro, pilhaVazia.desempilhe());
        assertEquals(elementoTres, pilhaVazia.retorneTopo());
        
        assertEquals(elementoTres, pilhaVazia.desempilhe());
        assertEquals(elementoDois, pilhaVazia.retorneTopo());
        
        assertEquals(elementoDois, pilhaVazia.desempilhe ());
        assertEquals(elementoUm, pilhaVazia.retorneTopo());
    }
    
    @Test(expected = ExcecaoEstruturaVazia.class)
    public void seDesempilharDeUmaPilhaVaziaLancaUmaExcecaoEstruturaVazia() throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia{
            
        pilhaVazia.desempilhe();
    }
    
    @Test(expected = ExcecaoEstruturaVazia.class)
    public void seRetornarDoTopoDeUmaPilhaVaziaLancaUmaExcecaoEstruturaVazia() throws ExcecaoEstruturaCheia, ExcecaoEstruturaVazia{
            
        pilhaVazia.retorneTopo();
    }
    
    @Test
    public void duasPilhasComOsMesmosElementosEmpilhadosNaMesmaOrdemSaoIguais() throws ExcecaoEstruturaCheia{
    	pilhaVazia.empilhe(elementoUm);
    	pilhaVazia.empilhe(elementoDois);
    	pilhaVazia.empilhe(elementoTres);
    	pilhaVazia.empilhe(elementoQuatro);
    	
    	outraPilhaVazia.empilhe(elementoUm);
    	outraPilhaVazia.empilhe(elementoDois);
    	outraPilhaVazia.empilhe(elementoTres);
    	outraPilhaVazia.empilhe(elementoQuatro);
    	
    	assertEquals(pilhaVazia, outraPilhaVazia);
    }
    
    @Test
    public void duasPilhasVaziasSaoIguais() throws ExcecaoEstruturaCheia{
    	
    	assertEquals(pilhaVazia, outraPilhaVazia);
    }
    
    @Test
    public void duasPilhasComOsMesmosElementosEmpilhadosNaMesmaOrdemNaoSaoIguaisSeAOutraPossuiMaisElementos() throws ExcecaoEstruturaCheia{
    	pilhaVazia.empilhe(elementoUm);
    	pilhaVazia.empilhe(elementoDois);
    	pilhaVazia.empilhe(elementoTres);
    	pilhaVazia.empilhe(elementoQuatro);
    	pilhaVazia.empilhe(elementoUm);
    	
    	outraPilhaVazia.empilhe(elementoUm);
    	outraPilhaVazia.empilhe(elementoDois);
    	outraPilhaVazia.empilhe(elementoTres);
    	outraPilhaVazia.empilhe(elementoQuatro);
    	
    	assertFalse(pilhaVazia.equals(outraPilhaVazia));
    }
    
    

}
