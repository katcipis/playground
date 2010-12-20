package infraestruturaDoTransformadorParaXML;

import static infraestruturaDoComponenteGedix.StringVazia.STRING_VAZIA;
import static infraestruturaDoTransformadorParaXML.InicioDosAtributosEmXML.*;
import infraestruturaDoComponenteGedix.Opcao;

public class TransformadorParaXMLComOpcoesConcreto extends TransformadorParaXMLConcreto implements TransformadorParaXMLComOpcoes{

	private int indiceDaPrimeiraOpção;
	
	public TransformadorParaXMLComOpcoesConcreto(){
		indiceDaPrimeiraOpção = 1;
	}
	
	public String obterAsOpções(TransformavelEmXMLComOpcoes transformável) {
		if(transformável.obterQuantidadeDeOpções() == 0)
			return STRING_VAZIA.nome;
		
		StringBuilder opções = new StringBuilder();
		
		for(int i = indiceDaPrimeiraOpção; 
		    i <= transformável.obterQuantidadeDeOpções(); i++){
			
			Opcao opção = transformável.obterOpção(i);
			String marcaçãoDaOpção = inícioDoMarcador + OPÇÃO.inícioDoAtributo +
			espaçoVazio + NOME.inícioDoAtributo + aspa + opção.obterNome() + aspa +
			fimDoMarcador + opção.obterTexto() + inícioDoMarcadorQueEncerra +
			OPÇÃO.inícioDoAtributo + fimDoMarcador;
			
			opções.append(marcaçãoDaOpção);
		}
		
		return opções.toString();
	
	}
	
	public String obterXMLComOpções(TransformavelEmXMLComOpcoes transformável){
		return 
		gerarXML(transformável)
		+ fimDoMarcador +
		obterAsOpções(transformável)
		+ inícioDoMarcadorQueEncerra + obterOAtributoTipo(transformável) + fimDoMarcador;
	}
}
