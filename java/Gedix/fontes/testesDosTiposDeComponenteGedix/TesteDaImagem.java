package testesDosTiposDeComponenteGedix;

import static edugraf.jadix.fachada.TiposDeComponentesDix.IMAGEM;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import testesAbstratosDoComponenteGedix.TesteAbstratoDoComponenteGedixComURI;
import tiposDeComponenteGedix.Imagem;

public class TesteDaImagem extends TesteAbstratoDoComponenteGedixComURI {

	@Override
	public void informarTipoDoComponenteGedix() {
		tipoDoComponenteGedix = IMAGEM;
	}

	@Override
	public void criarComponenteGedix() {
		componenteGedixDeAlturaDezELarguraVinteNaPosiçãoInicial =

		Fabrica.obterComponenteGedixDoTipo(IMAGEM, Fabrica
				.obterRetanguloPosicionavel(Fabrica.obterRetangulo(Fabrica
						.obterDimensão(10, 20))));

	}

	@Override
	public void criarComponenteGedixComURI() {
		componenteGedixComURI = Fabrica.obterComponenteGedixComURIDoTipo(IMAGEM,
				Fabrica.obterRetanguloPosicionavel(Fabrica
						.obterRetangulo(Fabrica.obterDimensão(10, 10))));
	}

	@Override
	protected void reiniciarContadorDeRetângulosDixCriados() {
		Imagem.reiniciarContador();
	}
	
	@Override
	protected void criarRetânguloPosicionável() {
		retânguloPosicionávelDeAlturaDezELarguraVinteNaPosiçãoInicial = Fabrica
		 .obterComponenteGedixDoTipo(IMAGEM, Fabrica
				 .obterRetanguloPosicionavel(Fabrica
						 .obterRetangulo(Fabrica
								 .obterDimensão(10, 20))));
		
	}

}