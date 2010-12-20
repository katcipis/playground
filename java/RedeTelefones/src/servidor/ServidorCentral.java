package servidor;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class ServidorCentral extends Thread {

	private Set<EstacaoBase> estacoes;
	private Map<Integer, EstacaoBase> cobertura;
	private static ServidorCentral eu;
	public static final Integer limite = 3;

	private ServidorCentral() {
		estacoes = new HashSet<EstacaoBase>();
		cobertura = new HashMap<Integer, EstacaoBase>();

		for (int i = 0; i <= limite; i++)
			cobertura.put(i, new EstacaoBase());

		for (int i = 0; i <= limite; i++)
			estacoes.add(cobertura.get(i));

	}

	public static ServidorCentral obterServidor() {
		if (eu == null)
			eu = new ServidorCentral();
		
		return eu;
	}

	public boolean possuiCelular(Integer numeroCel) {
		for (EstacaoBase e : estacoes)
			if (e.possuiCelular(numeroCel))
				return true;

		return false;
	}

	public EstacaoBase obterEstacaoDoCelular(Integer numeroCel) {
		for (EstacaoBase e : estacoes)
			if (e.possuiCelular(numeroCel))
				return e;
		
		return null;
	}

	public EstacaoBase obterEstacao(Integer area) {
		if (cobertura.containsKey(area))
			return cobertura.get(area);

		return null;
	}

}
