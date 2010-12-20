package listasDeTestesDaInfraestruturaDoComponenteGedix;

public interface ListaDeTestesDoConjuntoDeOpcoes {
	
	public void podeRemoverUmaOpçãoAPartirDoSeuIndice();
	
	public void podeRemoverUmaOpçãoSeElaEstáNoConjunto();

	public void podeObterUmaOpçãoAPartirDoSeuIndice();
	
	public void quandoAdcionadaUmaOpçãoElaFicaráNoFinalDaLista();

	public void sóRemoveUmaOpçãoSeElaExisteNaLista();

	public void seTentarObterUmaOpçãoQueNãoExisteRetornaUmaOpçãoNula();

	public void podeRemoverTodasAsOpçõesDoConjunto();

	public void oIndiceDaPrimeiraOpçãoÉUm();
	
	public void nãoAdcionaUmaOpçãoSeJáExisteUmaOpçãoIgualNoConjunto();
	
	public void podeInformarSePossuiUmaOpção();
	
	public void podeInformarSeExisteUmaOpçãoComUmDeterminadoIndice();
	
	public void sabeQuantasOpçõesPossui();

}
