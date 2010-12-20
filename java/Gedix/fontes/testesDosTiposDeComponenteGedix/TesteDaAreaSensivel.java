package testesDosTiposDeComponenteGedix;

import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import testesAbstratosDoComponenteGedix.TesteAbstratoDoComponenteGedix;
import tiposDeComponenteGedix.AreaSensivel;
import static edugraf.jadix.fachada.TiposDeComponentesDix.*;

public class TesteDaAreaSensivel extends TesteAbstratoDoComponenteGedix {

	@Override
	public void informarTipoDoComponenteGedix() {
		tipoDoComponenteGedix = ÁREA_SENSÍVEL;
	}

	@Override
	public void criarComponenteGedix() {
		componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial =

		Fabrica.obterComponenteGedixDoTipo(ÁREA_SENSÍVEL, Fabrica
				.obterRetanguloPosicionavel(Fabrica.obterRetangulo(Fabrica
						.obterDimensão(10, 20))));
	}

	@Override
	protected void reiniciarContadorDeRetângulosDixCriados() {
		AreaSensivel.reiniciarContador();
	}
	
	@Override
	protected void criarRetânguloPosicionável() {
		retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial = Fabrica
		 .obterComponenteGedixDoTipo(ÁREA_SENSÍVEL, Fabrica
				 .obterRetanguloPosicionavel(Fabrica
						 .obterRetangulo(Fabrica
								 .obterDimensão(10, 20))));
		
	}

}