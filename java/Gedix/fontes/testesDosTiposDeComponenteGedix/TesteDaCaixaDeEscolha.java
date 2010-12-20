package testesDosTiposDeComponenteGedix;

import static edugraf.jadix.fachada.TiposDeComponentesDix.CAIXA_DE_ESCOLHA;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import testesAbstratosDoComponenteGedix.TesteAbstratoDoComponenteGedixComOpcoes;
import tiposDeComponenteGedix.CaixaDeEscolha;

public class TesteDaCaixaDeEscolha extends
		TesteAbstratoDoComponenteGedixComOpcoes {

	@Override
	public void informarTipoDoComponenteGedix() {
		tipoDoComponenteGedix = CAIXA_DE_ESCOLHA;
	}

	@Override
	public void criarComponenteGedix() {
		componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial =

		Fabrica.obterComponenteGedixDoTipo(CAIXA_DE_ESCOLHA, Fabrica
				.obterRetanguloPosicionavel(Fabrica.obterRetangulo(Fabrica
						.obterDimensão(10, 20))));
	}

	@Override
	public void criarComponenteGedixComListaDeOpçõesVazia() {
		componenteGedixComNenhumaOpção = Fabrica
				.obterComponenteGedixComOpçõesDoTipo(CAIXA_DE_ESCOLHA,
						Fabrica.obterRetanguloPosicionavel(Fabrica
								.obterRetangulo(Fabrica.obterDimensão(10, 10))));

	}

	@Override
	public void criarComponenteGedixComQuatroOpções() {
		componenteGedixComQuatroOpções = Fabrica
				.obterComponenteGedixComOpçõesDoTipo(CAIXA_DE_ESCOLHA,
						Fabrica.obterRetanguloPosicionavel(Fabrica
								.obterRetangulo(Fabrica.obterDimensão(10, 10))));

	}

	@Override
	protected void reiniciarContadorDeRetângulosDixCriados() {
		CaixaDeEscolha.reiniciarContador();
	}
	
	@Override
	protected void criarRetânguloPosicionável() {
		retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial = Fabrica
		 .obterComponenteGedixDoTipo(CAIXA_DE_ESCOLHA, Fabrica
				 .obterRetanguloPosicionavel(Fabrica
						 .obterRetangulo(Fabrica
								 .obterDimensão(10, 20))));
		
	}

}