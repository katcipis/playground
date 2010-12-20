package celular;

public class Mensagem {
	
	private final Integer numeroRemetente;
	private final String msg;
	private boolean lida;
	
	public Mensagem(Integer numeroRemetente , String msg){
		this.numeroRemetente = numeroRemetente;
		this.msg = msg;
		lida = false;
	}
	
	public Integer obterRemetente(){
		return numeroRemetente;
	}
	
	public String obterTexto(){
		lida = true;
		return msg;
	}
	
	public boolean foiLida(){
		return lida;
	}

}
