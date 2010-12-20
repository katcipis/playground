package listasDeTestesDoComponenteGedix;

public interface ListaDeTestesDoComponenteGedixComGrade {
	
	public abstract void oNúmeroDeLinhasInicialÉUm();
	
	public abstract void oNúmeroDeColunasInicialÉUm();
	
	public abstract void oNúmeroDeLinhasPodeSerAlterado();
	
	public abstract void oNúmeroDeLinhasNãoPodeSerIgualOuMenorQueZero();

	public abstract void oNúmeroDeColunasPodeSerAlterado();
	
	public abstract void oNúmeroDeColunasNãoPodeSerIgualOuMenorQueZero();

    public abstract void sabeQuantasLinhasPossui();

    public abstract void sabeQuantasColunasPossui();
    
    public void éTransformávelEmXMLComGrade();

}