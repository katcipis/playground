package mocksDeTransformaveisParaXML;

import infraestruturaDoComponenteGedix.Opcao;
import infraestruturaDoTransformadorParaXML.TransformavelEmXMLComOpcoes;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;

public class MockTransformavelEmXMLComOpcoes extends MockTransformavelEmXML
implements TransformavelEmXMLComOpcoes{

	private Opcao[] opções;
	private int quantidadeDeOpções;
	
	public MockTransformavelEmXMLComOpcoes(){
		quantidadeDeOpções = 3;
		opções = new Opcao[quantidadeDeOpções];
		opções[0] = Fabrica.obterOpçãoDeNome("opção1");
		opções[1] = Fabrica.obterOpçãoDeNome("opção2");
		opções[2] = Fabrica.obterOpçãoDeNome("opção3");
	}
	
	public Opcao obterOpção(int indiceDaOpção) {
		
		return opções[indiceDaOpção - 1];
	}

	public int obterQuantidadeDeOpções() {
		
		return quantidadeDeOpções;
	}

	public boolean possuiAOpçãoDeÍndice(int indice) {
		
		return indice >= 1 && indice <= quantidadeDeOpções;
	}
	
	public void alterarAtributosComOpções(){
		alterarAtributos();
		opções[0] = Fabrica.obterOpçãoDeNome("Mock1");
		opções[1] = Fabrica.obterOpçãoDeNome("Mock1");
		opções[2] = Fabrica.obterOpçãoDeNome("Mock1");
	}

}
