package infraestruturaDoTransformadorParaXML;

import java.util.HashMap;
import java.util.Map;

import edugraf.jadix.fachada.TiposDeComponentesDix;
import static edugraf.jadix.fachada.TiposDeComponentesDix.*;
import static infraestruturaDoComponenteGedix.StringVazia.*;

public class MapaDeTiposDeComponentesDixParaXML {
	
	private final Map<TiposDeComponentesDix, String> mapa;
	
	public MapaDeTiposDeComponentesDixParaXML(){
		mapa = new HashMap<TiposDeComponentesDix, String>();
		
		construirMapa();
	}

	private void construirMapa() {
		mapa.put(BOTÃO, "botão");
		mapa.put(BOTÕES_DE_RÁDIO, "botõesDeRádio");
		mapa.put(CAIXA_DE_ESCOLHA, "caixaDeEscolha");
		mapa.put(ETIQUETA, "etiqueta");
		mapa.put(GRADE, "grade");
		mapa.put(ÁREA_SENSÍVEL, "áreaSensível");
		mapa.put(CAMPO_DE_TEXTO, "campoDeTexto");
		mapa.put(ÁREA_DE_TEXTO, "áreaDeTexto");
		mapa.put(IMAGEM, "imagem");
		mapa.put(LISTA_DE_ESCOLHA, "listaDeEscolha");
		mapa.put(ENLACE, "etiqueta");
	}
	
	public String obterXML(TiposDeComponentesDix tipoDoComponenteDix){
		if(mapa.containsKey(tipoDoComponenteDix))
			return mapa.get(tipoDoComponenteDix);
		return STRING_VAZIA.nome;
	}
	
	

}
