package componentesGedixAbstratos;

import infraestruturaDoComponenteGedix.ComponenteGedixComGrade;
import infraestruturaDoPainelDeComponenteGedix.RetanguloPosicionavel;

public abstract class ComponenteGedixComGradeAbstrato extends ComponenteGedixAbstrato
													implements ComponenteGedixComGrade{

	private int númeroDeLinhas, númeroDeColunas;
	
	public ComponenteGedixComGradeAbstrato(RetanguloPosicionavel r) {
		super(r);
		númeroDeLinhas = 1;
		númeroDeColunas = 1;
	}
	
    public int obterNúmeroDeLinhas(){
    	return númeroDeLinhas;
    }
	
	public int obterNúmeroDeColunas(){
		return númeroDeColunas;
	}
	
	public boolean alterarNúmeroDeLinhas(int novoNúmeroDeLinhas){
		if(novoNúmeroDeLinhas > 0){
			númeroDeLinhas = novoNúmeroDeLinhas;
			return true;
		}
		return false;
	}
	
	public boolean alterarNúmeroDeColunas(int novoNúmeroDeColunas){
		if(novoNúmeroDeColunas > 0){
			númeroDeColunas = novoNúmeroDeColunas;
			return true;
		}
		return false;
	}

}
