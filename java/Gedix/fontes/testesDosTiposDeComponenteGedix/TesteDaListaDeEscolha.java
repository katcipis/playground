package testesDosTiposDeComponenteGedix;

import static edugraf.jadix.fachada.TiposDeComponentesDix.LISTA_DE_ESCOLHA;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import testesAbstratosDoComponenteGedix.TesteAbstratoDoComponenteGedixComOpcoes;
import tiposDeComponenteGedix.ListaDeEscolha;

public class TesteDaListaDeEscolha extends TesteAbstratoDoComponenteGedixComOpcoes{
	
	@Override
	public  void informarTipoDoComponenteGedix(){
		tipoDoComponenteGedix = LISTA_DE_ESCOLHA;
	}
	
	@Override
	public void criarComponenteGedix(){
		componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial =
		
		Fabrica
		 .obterComponenteGedixDoTipo(LISTA_DE_ESCOLHA, Fabrica
				 .obterRetanguloPosicionavel(Fabrica
						 .obterRetangulo(Fabrica
								 .obterDimensão(10, 20))));
	}
	
	@Override
	public void criarComponenteGedixComListaDeOpçõesVazia() {
		componenteGedixComNenhumaOpção = Fabrica
		.obterComponenteGedixComOpçõesDoTipo(LISTA_DE_ESCOLHA, Fabrica
				.obterRetanguloPosicionavel(Fabrica
						.obterRetangulo(Fabrica
								.obterDimensão(10, 10))));
		
	}

	@Override
	public void criarComponenteGedixComQuatroOpções() {
		componenteGedixComQuatroOpções = Fabrica
		.obterComponenteGedixComOpçõesDoTipo(LISTA_DE_ESCOLHA, Fabrica
				.obterRetanguloPosicionavel(Fabrica
						.obterRetangulo(Fabrica
								.obterDimensão(10, 10))));
		
	}

	@Override
	protected void reiniciarContadorDeRetângulosDixCriados() {
		ListaDeEscolha.reiniciarContador();
	}
	
	@Override
	protected void criarRetânguloPosicionável() {
		retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial = Fabrica
		 .obterComponenteGedixDoTipo(LISTA_DE_ESCOLHA, Fabrica
				 .obterRetanguloPosicionavel(Fabrica
						 .obterRetangulo(Fabrica
								 .obterDimensão(10, 20))));
		
	}
	
	

}