package listasDeTestesDaInfraestruturaDoPainel;

public interface ListaDeTestesDoPainelDeComponenteGedix {
	
    public void seForPassadoOComponenteGedixEAPosiçãoDesejadaEleFicaráNaPosiçãoDesejada();
    
    public void seNãoForPassadaUmaPosiçãoParaOPainelOComponenteGedixFicaráNaPosição0e0IndependenteDaPosiçãoQueElePossua();
    
	public void podeMudarAPosiçãoDeUmComponenteGedix();
	
	public void sóMudaPosiçãoDeComponentesGedixQueEstãoDentroDoPainel();
	
	public void dadoUmaPosiçãoSabeDizerSeExisteAlguemNessaPosição();
	
	public void dadoUmaPosiçãoSabeDizerSeNãoExisteAlguemNessaPosição();
	
	public void dadoUmaPosiçãoSabeDizerQuemSeEncontraNessaPosição();
	
	public void dadoUmaPosiçãoSeNãoTemNinguémLáRetornaUmComponenteGedixNulo();
	
	public void seExisteMaisDeUmComponenteGedixEmUmaPosiçãoRetornaOUltimoQueFoiPosicionadoLá();
	
	public void podeRemoverUmComponenteGedixDoPainelSeEleEstáNoPainel();
	
	public void nãoPodeRemoverUmComponenteGedixDoPainelSeEleNãoEstáNoPainel();
	
	public void apósOComponenteGedixTerSidoRemovidoEleNãoSeEncontraMaisNaquelaPosição();
	
	public void seRemoverOComponenteGedixQueEstáEmUmaPosiçãoPodeObterOOutroQueSeEncontraLá();
	
	public void seMoverOComponenteGedixQueEstáEmUmaPosiçãoPodeObterOOutroQueSeEncontraLá();
	
	public void sabeDizerQuantosComponenteGedixEstãoNoPainel();
	
	public void seRemoveUmComponenteGedixAQuantidadeDeComponentesGedixNoPainelDiminui();
	
	public void podeRemoverTodosOsComponentesGedixDoPainel();
	
	public void podeObterOComponenteGedixAtravesDeQualquerPosiçãoQueEleOcupe();
	
}
