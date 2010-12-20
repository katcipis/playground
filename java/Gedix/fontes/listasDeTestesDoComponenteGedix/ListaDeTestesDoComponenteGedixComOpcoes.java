package listasDeTestesDoComponenteGedix;


public interface ListaDeTestesDoComponenteGedixComOpcoes { 
	
	public void oConjuntoDeOpcoesInicialÉVazio();
	
	public void podeAdcionarUmaOpção();

	public void podeRemoverUmaOpçãoAPartirDoSeuIndice();
	
	public void podeRemoverUmaOpçãoDesdeQueContenhaEssaOpção();

	public void podeObterUmaOpçãoAPartirDoSeuIndice();
	
	public void sóRemoveUmaOpçãoSePossuiEla();

	public void seTentarObterUmaOpçãoQueNãoExisteRetornaUmaOpçãoNula();

	public void podeRemoverTodasAsOpções();

	public void oIndiceDaPrimeiraOpçãoÉUm();
	
	public void nãoAdcionaUmaOpçãoSeJáExisteUmaOpçãoIgual();
	
	public void sabeQuantasOpçõesPossui();
	
	public void éTransformávelEmXMLComOpções();
	
}