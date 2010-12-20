package testesDosTiposDeComponenteGedix;

import static edugraf.jadix.fachada.TiposDeComponentesDix.CAMPO_DE_TEXTO;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import testesAbstratosDoComponenteGedix.TesteAbstratoDoComponenteGedixRotulavel;
import tiposDeComponenteGedix.CampoDeTexto;

public class TesteDoCampoDeTexto extends TesteAbstratoDoComponenteGedixRotulavel{
	
	@Override
	public  void informarTipoDoComponenteGedix(){
		tipoDoComponenteGedix = CAMPO_DE_TEXTO;
	}
	
	@Override
	public void criarComponenteGedix(){
		componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial =
		
		Fabrica
		 .obterComponenteGedixDoTipo(CAMPO_DE_TEXTO, Fabrica
				 .obterRetanguloPosicionavel(Fabrica
						 .obterRetangulo(Fabrica
								 .obterDimensão(10, 20))));
	}
	
	@Override
	public void criarComponenteGedixRotulável() {
		componenteGedixRotulável = Fabrica
		    .obterComponenteGedixRotulavelDoTipo(CAMPO_DE_TEXTO,
		    		 componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial);
	}

	@Override
	protected void reiniciarContadorDeRetângulosDixCriados() {
		CampoDeTexto.reiniciarContador();
	}
	
	@Override
	protected void criarRetânguloPosicionável() {
		retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial = Fabrica
		 .obterComponenteGedixDoTipo(CAMPO_DE_TEXTO, Fabrica
				 .obterRetanguloPosicionavel(Fabrica
						 .obterRetangulo(Fabrica
								 .obterDimensão(10, 20))));
		
	}
	
	
	
	
	

}