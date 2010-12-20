package implementacao;

import java.io.File;
import java.io.IOException;
import java.io.RandomAccessFile;

import infraEstrutura.excecoes.ExcecaoLivroNaoEncontrado;
import interfaces.Catalogo;

public class CatalogoArquivo implements Catalogo{
	
	private RandomAccessFile arquivo;
	private static final String LOCALISACAO = "arquivoTemporario.txt";

	public CatalogoArquivo(){
		
		try {
			File arquivo =  new File(LOCALISACAO);
			arquivo.createNewFile();
			arquivo.deleteOnExit();
			this.arquivo = new RandomAccessFile(arquivo, "rw");
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public boolean contemCodigo(int codigo) {

		try {
			
			long fim = arquivo.length();
			long posicao = 0;
			
			arquivo.seek(posicao);
			
			while(posicao < fim){
				LivroArquivo livro = new LivroArquivo();
				livro.leiaDoArquivo(arquivo);
				
				if(livro.getCodigo() == codigo)
					return true;
				
				posicao = arquivo.getFilePointer();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		return false;
	}

	public void esvaziar() {
		
		try {
			
			File arquivo =  new File(LOCALISACAO);
			arquivo.createNewFile();
			arquivo.deleteOnExit();
			
			this.arquivo = new RandomAccessFile(arquivo, "rw");
			
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public void inserirNovoLivro(LivroArquivo livro, long localizacao) {
	
		try {

			arquivo.seek(localizacao);
			
			livro.escrevaNoArquivo(arquivo);
			
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public long pesquisarPorCodigo(int codigo) throws ExcecaoLivroNaoEncontrado {

		try {
			
			long fim = arquivo.length();
			long posicao = 0;
			
			arquivo.seek(posicao);
			
			while(posicao < fim){
				LivroArquivo livro = new LivroArquivo();
				livro.leiaDoArquivo(arquivo);
				
				if(livro.getCodigo() == codigo){
					return posicao;
				}
				
				posicao = arquivo.getFilePointer();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		throw new ExcecaoLivroNaoEncontrado();
	}

	public long pesquisarPorTitulo(String titulo) throws ExcecaoLivroNaoEncontrado {

		try {
			
			long fim = arquivo.length();
			long posicao = 0;
			
			arquivo.seek(posicao);
			
			while(posicao < fim){
				LivroArquivo livro = new LivroArquivo();
				livro.leiaDoArquivo(arquivo);
				
				if(livro.getNome().equals(titulo))
					return posicao;
				
				posicao = arquivo.getFilePointer();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		throw new ExcecaoLivroNaoEncontrado();
	}

}
