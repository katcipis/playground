package testesDosTiposDeComponenteGedix;

import static edugraf.jadix.fachada.TiposDeComponentesDix.BOTÃO;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import testesAbstratosDoComponenteGedix.TesteAbstratoDoComponenteGedixRotulavel;
import tiposDeComponenteGedix.Botao;

public class TesteDoBotao extends TesteAbstratoDoComponenteGedixRotulavel{
	

	@Override
	public  void informarTipoDoComponenteGedix(){
		tipoDoComponenteGedix = BOTÃO;
	}
	
	@Override
	public void criarComponenteGedix(){
		componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial =
		
		Fabrica
		 .obterComponenteGedixDoTipo(BOTÃO, Fabrica
				 .obterRetanguloPosicionavel(Fabrica
						 .obterRetangulo(Fabrica
								 .obterDimensão(10, 20))));
	}

	
	@Override
	public void criarComponenteGedixRotulável() {
		componenteGedixRotulável = Fabrica
		    .obterComponenteGedixRotulavelDoTipo(BOTÃO,
		    		 componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial);
	}

	@Override
	protected void reiniciarContadorDeRetângulosDixCriados() {
		Botao.reiniciarContador();
	}

	@Override
	protected void criarRetânguloPosicionável() {
		retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial = Fabrica
		 .obterComponenteGedixDoTipo(BOTÃO, Fabrica
				 .obterRetanguloPosicionavel(Fabrica
						 .obterRetangulo(Fabrica
								 .obterDimensão(10, 20))));
		
	}
	
}
