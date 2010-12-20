package contadorDePalavras;

import java.util.StringTokenizer;

import tabelaHash.TabelaHash;
import tabelaHash.TabelaHashConcreta;

public class ContadorDePalavras {

	
	public TabelaHash<String,Integer> contarOcorrencias(String frase){
		
		TabelaHash<String,Integer> stringsEncontradas = new TabelaHashConcreta<String, Integer>();
		
		if(frase.length() == 0)
			return stringsEncontradas;
		
		StringTokenizer tokenizer = new StringTokenizer(frase);
		
		while(tokenizer.hasMoreTokens()){
			String token = tokenizer.nextToken();
			if(stringsEncontradas.existe(token)){
				
				Integer vezesQueFoiEncontrada = 
					stringsEncontradas.retorna(token);
				
				stringsEncontradas.insere(token, ++vezesQueFoiEncontrada);
			}else{
				stringsEncontradas.insere(token, 1);
			}
		}
		
		return stringsEncontradas;
		
	}
	
}
