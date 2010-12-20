package testesAbstratosDaTransformacaoParaXMLDosComponentesGedix;

import static infraestruturaDoTransformadorParaXML.InicioDosAtributosEmXML.NOME;
import static infraestruturaDoTransformadorParaXML.InicioDosAtributosEmXML.OPÇÃO;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import infraestruturaDoComponenteGedix.ComponenteGedixComOpcoes;
import infraestruturaDoComponenteGedix.Opcao;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import infraestruturaDoTransformadorParaXML.TransformadorParaXMLComOpcoes;
import listasDeTestesDaTransformacaoParaXMLDosComponentesGedix.ListaDeTestesDaTransformacaoParaXMLDoComponenteGedixComOpcoes;

import org.junit.Before;
import org.junit.Test;

public abstract class TesteAbstratoDaTransformacaoParaXMLDoComponenteGedixComOpcoes extends TesteAbstratoDaTransformacaoParaXMLDoComponenteGedix
                                                                                  implements ListaDeTestesDaTransformacaoParaXMLDoComponenteGedixComOpcoes{

	private TransformadorParaXMLComOpcoes transformadorComOpções;
	private ComponenteGedixComOpcoes componenteGedixComTrêsOpções;
	private String marcaçãoXMLDaOpção1, marcaçãoXMLDaOpção2, marcaçãoXMLDaOpção3,
	xmlComTodosOsAtributosDoComponenteComOpções;
	private Opcao opção1, opção2, opção3;

	
	
	@Before
	public void criarComponentesNecessários(){
		
		opção1 = Fabrica.obterOpçãoDeNome("opção1");
		opção2 = Fabrica.obterOpçãoDeNome("opção2");
		opção3 = Fabrica.obterOpçãoDeNome("opção3");
		
		
		marcaçãoXMLDaOpção1 = criarMarcaçãoXmlDaOpçãoDeNome(opção1.obterNome());
		marcaçãoXMLDaOpção2 = criarMarcaçãoXmlDaOpçãoDeNome(opção2.obterNome());
		marcaçãoXMLDaOpção3 = criarMarcaçãoXmlDaOpçãoDeNome(opção3.obterNome());
		
		criarComponenteGedixComOpções();
		
		transformadorComOpções = Fabrica.obterTransformadorParaXMLComOpções();
		
		 xmlComTodosOsAtributosDoComponenteComOpções =
		 gerarXML() 
		 + fimDoMarcador + marcaçãoXMLDaOpção1 + marcaçãoXMLDaOpção2 +
		 marcaçãoXMLDaOpção3 + fechaMarcador + atributoTipoDoComponenteQueSeráTestado
	     + fimDoMarcador;
	}
	
	private  void criarComponenteGedixComOpções(){
		componenteGedixComTrêsOpções = Fabrica.obterComponenteGedixComOpçõesDoTipo(tipoDoComponenteQueSeráTestado, 
				Fabrica.obterRetanguloPosicionavel(Fabrica.obterRetangulo(Fabrica.obterDimensão(0, 0))));
		
		componenteGedixComTrêsOpções.alterarNome(gedix);
		componenteGedixComTrêsOpções.alterarLegenda(gedix);
		componenteGedixComTrêsOpções.desabilitar();
		componenteGedixComTrêsOpções.tornarInvisível();
		componenteGedixComTrêsOpções.adcionarOpção(opção1);
		componenteGedixComTrêsOpções.adcionarOpção(opção2);
		componenteGedixComTrêsOpções.adcionarOpção(opção3);
		
	}
	
	private String criarMarcaçãoXmlDaOpçãoDeNome(String nome){
		return inícioDoMarcador + OPÇÃO.inícioDoAtributo + espaçoVazio + 
		NOME.inícioDoAtributo + aspa + nome + aspa + fimDoMarcador + nome +
		fechaMarcador + OPÇÃO.inícioDoAtributo + fimDoMarcador;
	}

	@Test
	public void dadoUmComponenteGedixComOpçõesPodeGerarOsElementosDasOpções() {
		
		assertEquals(transformadorComOpções.obterAsOpções(componenteGedixComTrêsOpções),
				marcaçãoXMLDaOpção1 + marcaçãoXMLDaOpção2 + marcaçãoXMLDaOpção3); 
		
		componenteGedixComTrêsOpções.removerOpção(1);
		
		assertFalse(transformadorComOpções.obterAsOpções(componenteGedixComTrêsOpções)
				.equals(marcaçãoXMLDaOpção1 + marcaçãoXMLDaOpção2 + marcaçãoXMLDaOpção3)); 
		
	}

	@Test
	public void podeGerarOXMLCompletoComAsOpçõesComoFilhosDAMarcaçãoXMLDoComponenteGedixComOpções() {
		
		assertEquals(xmlComTodosOsAtributosDoComponenteComOpções, transformadorComOpções
				.obterXMLComOpções(componenteGedixComTrêsOpções));
		
		componenteGedixComTrêsOpções.removerOpção(1);
		
		assertFalse(xmlComTodosOsAtributosDoComponenteComOpções.equals(transformadorComOpções
				.obterXMLComOpções(componenteGedixComTrêsOpções)) );
		
		
	}
	
}
