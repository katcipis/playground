package implementacao;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;

public class Arquivador {
	
	private static final String COMPLEMENTADOR = " ";
	private static final int CASAS_DECIMAIS = 100;
	private RandomAccessFile r;

	public Arquivador(File arquivo) {
		try {
			this.r = new RandomAccessFile(arquivo, "rwd");
		} catch (FileNotFoundException e) {
			System.out.println("Arquivo nao encontrado em :" + arquivo.getAbsolutePath());
		}
	}

	public long escreva(int i) {
		long posicao = 0;
		try {
			posicao = r.getFilePointer();
			r.writeInt(i);
		} catch (IOException e) {
			e.printStackTrace();
		}
		return posicao;
	}

	public long escreva(double d) {
		int valor = (int) (d * CASAS_DECIMAIS);
		long posicao = 0;
		try {
			posicao = r.getFilePointer();
			r.writeInt(valor);
		} catch (IOException e) {
			e.printStackTrace();
		}
		return posicao;
	}

	public long escreva(String texto) {
		int numDeCaracteres = texto.length();
		
		while (numDeCaracteres++ < 20) {
			texto = COMPLEMENTADOR + texto;
		}
		
		long posicao = 0;
		try {
			posicao = r.getFilePointer();
			r.writeUTF(texto);
		} catch (IOException e) {
			e.printStackTrace();
		}
		return posicao;
	}

	public int leiaInteiro(long posicao) {
		try {
			r.seek(posicao);
			return r.readInt();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return 0;
	}

	public double leiaDouble(long posicao) {
		double valor = leiaInteiro(posicao);
		return valor / CASAS_DECIMAIS;
	}

	public String leiaTexto(long posicao) {
		String texto = "";
		
		try {
			r.seek(posicao);
			texto = r.readUTF();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		int pos = obterPosicaoDoPrimeiroCaracterValido(texto);
		
		return texto.substring(pos);
	}

	private int obterPosicaoDoPrimeiroCaracterValido(String texto) {
		boolean achou = false;
		int pos = 0;
		
		while(pos < 20 && !achou){
			if(!texto.substring(pos, pos + 1).equals(COMPLEMENTADOR))
				achou = true;
			else
				pos++;
		}
		
		return pos;
	}

	public long obterPonteiro() {
		try {
			return r.getFilePointer();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		return 0;
	}
	
	public void puleBytes(int quantidade){
		try {
			r.skipBytes(quantidade);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public String leiaTexto() {
		String texto = "";
		
		try {
			texto = r.readUTF();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		int pos = obterPosicaoDoPrimeiroCaracterValido(texto);
		
		return texto.substring(pos);
	}

	public double leiaDouble() {
		double valor = leiaInteiro();
		
		return valor / CASAS_DECIMAIS;
	}

	public double leiaInteiro() {
		try {
			return r.readInt();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return 0;
	}
	
	public long fim(){
		try {
			return r.length();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return 0;
	}

	public void vaPara(long posicao) {
		try {
			r.seek(posicao);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
