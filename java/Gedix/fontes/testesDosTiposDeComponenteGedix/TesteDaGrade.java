package testesDosTiposDeComponenteGedix;

import static edugraf.jadix.fachada.TiposDeComponentesDix.GRADE;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import testesAbstratosDoComponenteGedix.TesteAbstratoDoComponenteGedixComGrade;
import tiposDeComponenteGedix.Grade;

public class TesteDaGrade extends TesteAbstratoDoComponenteGedixComGrade {

	@Override
	public void informarTipoDoComponenteGedix() {
		tipoDoComponenteGedix = GRADE;
	}

	@Override
	public void criarComponenteGedix() {
		componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial =

		Fabrica.obterComponenteGedixDoTipo(GRADE, Fabrica
				.obterRetanguloPosicionavel(Fabrica.obterRetangulo(Fabrica
						.obterDimensão(10, 20))));
	}

	@Override
	public void criarRetânguloDixComGrade() {
		componenteGedixComGrade =

		Fabrica.obterComponenteGedixComGradeDoTipo(GRADE, Fabrica
				.obterRetanguloPosicionavel(Fabrica.obterRetangulo(Fabrica
						.obterDimensão(10, 20))));

	}

	@Override
	protected void reiniciarContadorDeRetângulosDixCriados() {
		Grade.reiniciarContador();
	}
	
	@Override
	protected void criarRetânguloPosicionável() {
		retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial = Fabrica
		 .obterComponenteGedixDoTipo(GRADE, Fabrica
				 .obterRetanguloPosicionavel(Fabrica
						 .obterRetangulo(Fabrica
								 .obterDimensão(10, 20))));
		
	}

}