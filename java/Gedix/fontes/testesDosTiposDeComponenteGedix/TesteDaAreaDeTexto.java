package testesDosTiposDeComponenteGedix;

import static edugraf.jadix.fachada.TiposDeComponentesDix.ÁREA_DE_TEXTO;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import testesAbstratosDoComponenteGedix.TesteAbstratoDoComponenteGedixRotulavel;
import tiposDeComponenteGedix.AreaDeTexto;

public class TesteDaAreaDeTexto extends TesteAbstratoDoComponenteGedixRotulavel {

	@Override
	public void informarTipoDoComponenteGedix() {
		tipoDoComponenteGedix = ÁREA_DE_TEXTO;
	}

	@Override
	public void criarComponenteGedix() {
		componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial =

		Fabrica.obterComponenteGedixDoTipo(ÁREA_DE_TEXTO, Fabrica
				.obterRetanguloPosicionavel(Fabrica.obterRetangulo(Fabrica
						.obterDimensão(10, 20))));
	}

	@Override
	public void criarComponenteGedixRotulável() {
		componenteGedixRotulável = Fabrica.obterComponenteGedixRotulavelDoTipo(
				ÁREA_DE_TEXTO,
				componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial);
	}

	@Override
	protected void reiniciarContadorDeRetângulosDixCriados() {
		AreaDeTexto.reiniciarContador();
	}
	
	@Override
	protected void criarRetânguloPosicionável() {
		retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial = Fabrica
		 .obterComponenteGedixDoTipo(ÁREA_DE_TEXTO, Fabrica
				 .obterRetanguloPosicionavel(Fabrica
						 .obterRetangulo(Fabrica
								 .obterDimensão(10, 20))));
		
	}

}
