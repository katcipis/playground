package listasDeTestesDaInfraestruturaDoPainel;

public interface ListaDeTestesDaFabrica {
	
	public void dadoADistanciaDaEsquerdaEDoTopoRetornaUmaPosiçãoComAMesmaDistanciaDaEsquerdaEDoTopo();

	public void dadoADistanciaDaEsquerdaEDoTopoNãoRetornaUmaPosiçãoComOutraDistanciaDaEsquerdaEDoTopo();
	
	public void dadoAAlturaEALarguraRetornaUmaDimensãoComEstaAlturaEEssaLargura();

	public void dadoAAlturaEALarguraNãoRetornaUmaDimensãoComOutraAlturaEOutraLargura();
	
	public void dadoUmaDimensãoRetornaUmRetanguloComAquelaDimensão();
	
	public void dadoUmaDimensãoNãoRetornaUmRetanguloComOutraDimensão();
	
	public void dadoUmRetanguloRetornaUmRetanguloPosicionavelDeMesmaDimensão();
	
	public void semFornecerUmRetanguloRetornaUmRetanguloPosicionavelNulo();
	
	public void podeFornecerUmComponenteGedixNulo();
	
	public void dadoUmTipoDeComponenteDixEUmRetanguloPosicionavelRetornaUmComponenteGedixDeMesmoTipo();
	
	public void seDerUmTipoDeComponenteDixInválidoRetornaUmComponenteGedixNulo();
	
	public void dadoUmTipoDeComponenteDixRotulavelEUmRetanguloPosicionavelRetornaUmComponenteGedixRotulavelDeMesmoTipo();
	
	public void seDerUmTipoDeComponenteDixRotulavelInválidoRetornaComponenteGedixNulo();
	
    public void dadoUmTipoDeComponenteDixComURIEUmRetanguloPosicionavelRetornaUmComponenteGedixComURIDeMesmoTipo();
	
	public void seDerUmTipoDeComponenteDixComURIInválidoRetornaUmComponenteGedixNulo();
	
    public void dadoUmTipoDeComponenteDixComListaDeOpçõesEUmRetanguloPosicionavelRetornaUmComponenteGedixComListaDeOpçõesDeMesmoTipo();
	
	public void seDerUmTipoDeComponenteDixComListaDeOpçõesInválidoRetornaUmComponenteGedixNulo();
	
	public void dadoUmTipoDeComponenteDixComGradeEUmRetanguloPosicionavelRetornaUmComponenteGedixComGradeDeMesmoTipo();
		
	public void seDerUmTipoDeComponenteDixComGradeInválidoRetornaUmComponenteGedixNulo();
	
	public void seDerUmNomeRetornaUmaOpçãoDaqueleMesmoNome();
	
	public void podeRetornarUmaOpçãoNula();
	
	public void podeRetornarUmConjuntoDeOpções();
	
	public void podeRetornarUmMockTransformávelEmXML();
	
	public void podeRetornarUmTransformadorParaXML();
	
	public void podeRetornarUmTransformadorParaXMLComURI();
	
	public void podeRetornarUmMockTransformávelEmXMLComURI();
	
	public void podeRetornarUmMockTransformávelEmXMLComGrade();
	
	public void podeRetornarUmTransformadorParaXMLComGrade();
	
	public void podeRetornarUmMockTransformávelEmXMLRotulavel();
	
	public void podeRetornarUmTransformadorParaXMLRotulavel();
	
	public void podeRetornarUmTransformadorParaXMLComOpções();
	
	public void podeRetornarUmMockTransformávelEmXMLComOpções();
	
	public void podeRetornarUmTransformadorParaXMLRotulávelComURI();
	
	public void podeRetornarUmMockTransformávelEmXMLRotulávelComURI();
	
	public void dadoUmTipoDeComponenteDixRotulávelComURIEUmRetanguloPosicionavelRetornaUmComponenteGedixRotulávelComURIDeMesmoTipo();
	
	public void seDerUmTipoDeComponenteDixRotulávelComURIInválidoRetornaUmComponenteGedixNulo();
}
