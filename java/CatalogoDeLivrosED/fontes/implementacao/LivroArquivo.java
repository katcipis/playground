package implementacao;

import java.io.*;

public class LivroArquivo {
	
	static final int tamanhoString = 20;
	
	private int codigo;
	private String nome;
	private String autor;
	private double preco;
	private int quantidade;
	
	public LivroArquivo (int codigo, String nome, String autor, double preco, int quantidade) {
		this.codigo = codigo;
		this.nome = nome;
		this.autor = autor;
		this.preco = preco; 
		this.quantidade = quantidade; 
	}
	
	public LivroArquivo (){
	}
	
	public boolean equals(Object o){
		if(o instanceof LivroArquivo){
			return codigo == ((LivroArquivo) o).codigo;
		}
		return false;
	}
	
	public int getCodigo (){
		return this.codigo;
	}
	
	public String getNome (){
		return this.nome;
	}
	
	public String getAutor (){
		return this.autor;
	}
	
	public double getPreco (){
		return this.preco;
	}
	
	public int getQuantidade (){
		return this.quantidade;
	}
	
	public void escrevaNoArquivo (RandomAccessFile arquivo) throws IOException{
		arquivo.writeInt(this.codigo);
		int i = 0;	
		
		for (int j=0; j<tamanhoString - this.nome.length(); j++) {
			arquivo.writeChar(' ');
		}
		for (i=0; i<this.nome.length(); i++){
			arquivo.writeChar(this.nome.charAt(i));	
		}
			
		for (int j=0; j<tamanhoString - this.autor.length(); j++) {
			arquivo.writeChar(' ');
		}
		for (i=0; i<this.autor.length(); i++){
			arquivo.writeChar(this.autor.charAt(i));	
		}
		
		arquivo.writeDouble(this.preco);
		arquivo.writeInt(this.quantidade);
	}
	
	public void leiaDoArquivo (RandomAccessFile arquivo) throws IOException{
		this.codigo = arquivo.readInt();
		
		this.nome = "";
		
		for (int i=0; i<tamanhoString; i++){
			nome = nome + arquivo.readChar();
		}
		
		nome = nome.trim();
		
		this.autor = "";
		
		for (int i=0; i<tamanhoString; i++){
			autor = autor + arquivo.readChar();
		}
		
		autor = autor.trim();

		this.preco = arquivo.readDouble();
		this.quantidade = arquivo.readInt();
	}
	
	public static int tamanhoLivro (){
		return 4 + tamanhoString*2 + tamanhoString*2 + 8 + 4;
	}
	
}
