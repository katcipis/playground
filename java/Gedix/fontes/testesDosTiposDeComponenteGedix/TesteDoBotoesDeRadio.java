package testesDosTiposDeComponenteGedix;

import static edugraf.jadix.fachada.TiposDeComponentesDix.BOTÕES_DE_RÁDIO;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import testesAbstratosDoComponenteGedix.TesteAbstratoDoComponenteGedixComOpcoes;
import tiposDeComponenteGedix.BotoesDeRadio;

public class TesteDoBotoesDeRadio extends
		TesteAbstratoDoComponenteGedixComOpcoes {

	@Override
	public void informarTipoDoComponenteGedix() {
		tipoDoComponenteGedix = BOTÕES_DE_RÁDIO;
	}

	@Override
	public void criarComponenteGedix() {
		componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial =

		Fabrica.obterComponenteGedixDoTipo(BOTÕES_DE_RÁDIO, Fabrica
				.obterRetanguloPosicionavel(Fabrica.obterRetangulo(Fabrica
						.obterDimensão(10, 20))));
	}

	@Override
	public void criarComponenteGedixComListaDeOpçõesVazia() {
		componenteGedixComNenhumaOpção = Fabrica
				.obterComponenteGedixComOpçõesDoTipo(BOTÕES_DE_RÁDIO,
						Fabrica.obterRetanguloPosicionavel(Fabrica
								.obterRetangulo(Fabrica.obterDimensão(10, 10))));

	}

	@Override
	public void criarComponenteGedixComQuatroOpções() {
		componenteGedixComQuatroOpções = Fabrica
				.obterComponenteGedixComOpçõesDoTipo(BOTÕES_DE_RÁDIO,
						Fabrica.obterRetanguloPosicionavel(Fabrica
								.obterRetangulo(Fabrica.obterDimensão(10, 10))));

	}

	protected void reiniciarContadorDeRetângulosDixCriados() {
		BotoesDeRadio.reiniciarContador();
	}

	@Override
	protected void criarRetânguloPosicionável() {
		retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial = Fabrica
		 .obterComponenteGedixDoTipo(BOTÕES_DE_RÁDIO, Fabrica
				 .obterRetanguloPosicionavel(Fabrica
						 .obterRetangulo(Fabrica
								 .obterDimensão(10, 20))));
		
	}

}
