package testesDosTiposDeComponenteGedix;

import static edugraf.jadix.fachada.TiposDeComponentesDix.ETIQUETA;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import testesAbstratosDoComponenteGedix.TesteAbstratoDoComponenteGedixRotulavel;
import tiposDeComponenteGedix.Etiqueta;

public class TesteDaEtiqueta extends TesteAbstratoDoComponenteGedixRotulavel{
	
	@Override
	public  void informarTipoDoComponenteGedix(){
		tipoDoComponenteGedix = ETIQUETA;
	}
	
	@Override
	public void criarComponenteGedix(){
		componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial =
		
		Fabrica
		 .obterComponenteGedixDoTipo(ETIQUETA, Fabrica
				 .obterRetanguloPosicionavel(Fabrica
						 .obterRetangulo(Fabrica
								 .obterDimensão(10, 20))));
	}
	
	@Override
	public void criarComponenteGedixRotulável() {
		componenteGedixRotulável = Fabrica
		    .obterComponenteGedixRotulavelDoTipo(ETIQUETA,
		    		 componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial);
	}

	@Override
	protected void reiniciarContadorDeRetângulosDixCriados() {
		Etiqueta.reiniciarContador();
	}
	
	@Override
	protected void criarRetânguloPosicionável() {
		retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial = Fabrica
		 .obterComponenteGedixDoTipo(ETIQUETA, Fabrica
				 .obterRetanguloPosicionavel(Fabrica
						 .obterRetangulo(Fabrica
								 .obterDimensão(10, 20))));
		
	}
	

}
