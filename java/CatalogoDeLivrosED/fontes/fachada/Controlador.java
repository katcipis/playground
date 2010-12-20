package fachada;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import implementacao.CatalogoDeLivros;
import implementacao.LivroArquivo;
import infraEstrutura.Estruturas;
import infraEstrutura.estruturas.TabelaHash;
import infraEstrutura.estruturas.TabelaHashConcreta;
import infraEstrutura.excecoes.ExcecaoAutorInvalido;
import infraEstrutura.excecoes.ExcecaoCodigoInvalido;
import infraEstrutura.excecoes.ExcecaoCodigoRepetido;
import infraEstrutura.excecoes.ExcecaoLivroNaoEncontrado;
import infraEstrutura.excecoes.ExcecaoNomeInvalido;
import edugraf.jadix.Aplique;
import edugraf.jadix.eventos.EventoDeSelecao;
import edugraf.jadix.eventos.EventoSimples;
import edugraf.jadix.eventos.nomes.NomeDeEventosSimples;
import edugraf.jadix.fachada.ComponenteDix;
import edugraf.jadix.fachada.PaginaDix;
import edugraf.jadix.fachada.TratadorDixAbstrato;

import static infraEstrutura.Estruturas.*;

public class Controlador extends Aplique {

	private PaginaDix pagina;
	private ComponenteDix campoLocalizacao, campoStatus, listaEstruturas,
			campoTempo;
	private ComponenteDix botaoCarregar, botaoCriar, botaoBuscarPorCodigo,
			botaoBuscarPorNome, botaoInserir;
	private ComponenteDix codigoDoLivro, nomeDoLivro, autorDoLivro,
			precoDoLivro, quantidadeDeLivros;
	private ComponenteDix aguarde, area;
	private CatalogoDeLivros catalogo;
	private Estruturas estrutura;
	private static final String TEXTO_INICIAL_DO_CAMPO_LOCALIZACAO = "Insira o caminho do arquivo de livros";
	private TabelaHash<String, Estruturas> tabela = new TabelaHashConcreta<String, Estruturas>();

	@Override
	public void iniciar() {
		
		List<String> estruturas = new ArrayList<String>();
		
		estruturas.add(ARVORE_AVL.toString());
		estruturas.add(TABELA_HASH.toString());
		estruturas.add(ARQUIVO.toString());
		
		tabela.insere(ARVORE_AVL.toString(), ARVORE_AVL);
		tabela.insere(TABELA_HASH.toString(), TABELA_HASH);
		tabela.insere(ARQUIVO.toString(), ARQUIVO);
		
		pagina = this.obterPaginaDix();
		
		botaoCarregar = pagina.criarProcuradorDeComponente("carregar");
		botaoCriar = pagina.criarProcuradorDeComponente("criar");
		botaoBuscarPorCodigo = pagina.criarProcuradorDeComponente("buscarPorCodigo");
		botaoBuscarPorNome = pagina.criarProcuradorDeComponente("buscarPorNome");
		botaoInserir = pagina.criarProcuradorDeComponente("inserir");
		
		campoStatus = pagina.criarProcuradorDeComponente("status");
		campoLocalizacao = pagina.criarProcuradorDeComponente("localizacao");
		campoTempo = pagina.criarProcuradorDeComponente("tempo");
		
		listaEstruturas = pagina.criarProcuradorDeComponente("estruturas");
		
		codigoDoLivro = pagina.criarProcuradorDeComponente("codigoDoLivro");
		nomeDoLivro = pagina.criarProcuradorDeComponente("nomeDoLivro");
		autorDoLivro = pagina.criarProcuradorDeComponente("autorDoLivro");
		precoDoLivro = pagina.criarProcuradorDeComponente("precoDoLivro");
		quantidadeDeLivros = pagina.criarProcuradorDeComponente("quantidadeDeLivros");
		
		aguarde = pagina.criarProcuradorDeComponente("botaoAguarde");
		area = pagina.criarProcuradorDeComponente("areaAguarde");

		botaoBuscarPorCodigo.desabilitar();
		botaoBuscarPorNome.desabilitar();
		botaoCarregar.desabilitar();
		botaoCriar.desabilitar();
		botaoInserir.desabilitar();
		
		campoStatus.desabilitar();
		campoTempo.desabilitar();
		
		codigoDoLivro.desabilitar();
		nomeDoLivro.desabilitar();
		autorDoLivro.desabilitar();
		precoDoLivro.desabilitar();
		quantidadeDeLivros.desabilitar();

		campoLocalizacao.fixarTexto(TEXTO_INICIAL_DO_CAMPO_LOCALIZACAO);
		listaEstruturas.fixarLista(estruturas);

		botaoBuscarPorCodigo.adicionarTratadorDeEventos(new TratadorDeBuscaPorCodigo());
		botaoBuscarPorNome.adicionarTratadorDeEventos(new TratadorDeBuscaPorNome());
		botaoCarregar.adicionarTratadorDeEventos(new TratadorCarregar());
		botaoCriar.adicionarTratadorDeEventos(new TratadorCriar());
		botaoInserir.adicionarTratadorDeEventos(new TratadorDeInsercao());
		campoLocalizacao.adicionarTratadorDeEventos(new TratadorDoCampoLocalizacao());
		listaEstruturas.adicionarTratadorDeEventos(new TratadorDeLista());

		estrutura = tabela.retorna(listaEstruturas.obterTexto());
		catalogo = new CatalogoDeLivros();
		
		esconderAguarde();
	}
	
	private void esconderAguarde() {
		this.criarPichador().descansar(0.6);
		aguarde.tornarInvisivel();
		area.tornarInvisivel();
	}
	
	private void mostrarAguarde(){
		area.tornarVisivel();
		aguarde.tornarVisivel();
	}

	private void atualizarInformacoes(LivroArquivo livro) {
		
		campoStatus.fixarTexto("\"" + livro.getNome() + "\" encontrado.");
		
		codigoDoLivro.fixarValorInteiro(livro.getCodigo());
		nomeDoLivro.fixarTexto(livro.getNome());
		autorDoLivro.fixarTexto(livro.getAutor());
		precoDoLivro.fixarValorReal(livro.getPreco());
		quantidadeDeLivros.fixarValorInteiro(livro.getQuantidade());
	}
	
	private void habilitarBusca() {
		
		botaoBuscarPorCodigo.habilitar();
		botaoBuscarPorNome.habilitar();
		botaoInserir.habilitar();
		codigoDoLivro.habilitar();
		nomeDoLivro.habilitar();
		autorDoLivro.habilitar();
		precoDoLivro.habilitar();
		quantidadeDeLivros.habilitar();
	}

	private class TratadorCarregar extends TratadorDixAbstrato {

		public void seDito(EventoSimples evento) {
			
			if (evento.obterNomeDoEvento() == NomeDeEventosSimples.CLICADO) {
			
				mostrarAguarde();
				
				try {
					catalogo.carregar(campoLocalizacao.obterTexto(), estrutura);

					campoStatus.fixarTexto("Arquivo carregado Com Sucesso");
					campoTempo.fixarTexto("" + catalogo.obterTempoDeProcessamento());

					habilitarBusca();
					
				} catch (FileNotFoundException e) {
					campoStatus.fixarTexto("Arquivo não encontrado em \"" + campoLocalizacao.obterTexto() + "\"");
				} catch (IOException e) {
					campoStatus.fixarTexto("Erro inesperado");
				}
				esconderAguarde();
			}
		}
	}
	
	private class TratadorCriar extends TratadorDixAbstrato {
		
		public void seDito(EventoSimples evento) {
		
			if (evento.obterNomeDoEvento() == NomeDeEventosSimples.CLICADO) {
				
				mostrarAguarde();
				
				try {
					
					catalogo.criarNovoArquivo(campoLocalizacao.obterTexto());
					
					campoStatus.fixarTexto("Arquivo Criado Com Sucesso");
					campoTempo.fixarTexto("" + catalogo.obterTempoDeProcessamento());

					habilitarBusca();
					
				} catch (IOException e) {
					campoStatus.fixarTexto("Erro: Caminho Invalido");
				}
				esconderAguarde();
			}
		}
	}

	private class TratadorDeBuscaPorCodigo extends TratadorDixAbstrato {

		public void seDito(EventoSimples evento) {
			
			if (evento.obterNomeDoEvento() == NomeDeEventosSimples.CLICADO) {
				
				mostrarAguarde();
				
				LivroArquivo livro;
				
				try {
					
					livro = catalogo.procurePorCodigo(codigoDoLivro.obterValorInteiro());
					
					campoTempo.fixarTexto("" + catalogo.obterTempoDeProcessamento());
					
					atualizarInformacoes(livro);
					
				} catch (ExcecaoLivroNaoEncontrado e) {
					campoStatus.fixarTexto("Livro não encontrado no arquivo");
				} catch (IOException e) {
					campoStatus.fixarTexto("Erro Inesperado");
				} catch (ExcecaoCodigoInvalido e) {
					campoStatus.fixarTexto("Erro: O Codigo do livro deve ser de 1 a 100.000.");
				}
				esconderAguarde();
			}
		}
	}

	private class TratadorDeBuscaPorNome extends TratadorDixAbstrato {
		
		public void seDito(EventoSimples evento) {
			
			if (evento.obterNomeDoEvento() == NomeDeEventosSimples.CLICADO) {
				
				mostrarAguarde();
				LivroArquivo livro;
				
				try {
					
					livro = catalogo.procurePorTitulo(nomeDoLivro.obterTexto());
					
					campoTempo.fixarTexto("" + catalogo.obterTempoDeProcessamento());
					
					atualizarInformacoes(livro);
					
				} catch (ExcecaoLivroNaoEncontrado e) {
					campoStatus.fixarTexto("Livro não encontrado no arquivo");
				} catch (IOException e) {
					campoStatus.fixarTexto("Erro Inesperado");
				} catch (ExcecaoNomeInvalido e) {
					campoStatus.fixarTexto("Erro: O Nome do livro pode ter apenas 20 caracteres.");
				}
				esconderAguarde();
			}
		}
	}

	private class TratadorDoCampoLocalizacao extends TratadorDixAbstrato {

		public void seDito(EventoSimples evento) {
			if (evento.obterNomeDoEvento() == NomeDeEventosSimples.CLICADO) {
				if (campoLocalizacao.obterTexto().equals(TEXTO_INICIAL_DO_CAMPO_LOCALIZACAO))
					campoLocalizacao.fixarTexto("catalogoDeLivros/arquivoTeste.txt");
				
				botaoCarregar.habilitar();
				botaoCriar.habilitar();
			}
		}
	}

	private class TratadorDeLista extends TratadorDixAbstrato {
		
			public void seDito(EventoDeSelecao evento) {
				
				estrutura = tabela.retorna(evento.obterTextoDaOpcao());
		}
	}
	
	private class TratadorDeInsercao extends TratadorDixAbstrato {
		
		public void seDito(EventoSimples evento){
			
			if(evento.obterNomeDoEvento() == NomeDeEventosSimples.CLICADO){
				
				mostrarAguarde();
				LivroArquivo livro;
				
				int codigo = codigoDoLivro.obterValorInteiro();
				String nome = nomeDoLivro.obterTexto();
				String autor = autorDoLivro.obterTexto();
				double preco = precoDoLivro.obterValorReal();
				int quantidade = quantidadeDeLivros.obterValorInteiro();
				
				livro = new LivroArquivo(codigo, nome, autor, preco, quantidade);
				
				try {
					catalogo.insiraNoFim(livro);
					
					campoStatus.fixarTexto("O Livro \"" + nome +"\" inserido com Sucesso.");
					campoTempo.fixarTexto("" + catalogo.obterTempoDeProcessamento());
					
				} catch (IOException e) {
					campoStatus.fixarTexto("Erro Inesperado");
				} catch (ExcecaoAutorInvalido e){
					campoStatus.fixarTexto("Erro: O Autor do livro pode ter apenas 20 caracteres.");
				} catch (ExcecaoCodigoInvalido e) {
					campoStatus.fixarTexto("Erro: O Codigo do livro deve ser de 1 a 100.000.");
				} catch (ExcecaoNomeInvalido e) {
					campoStatus.fixarTexto("Erro: O Nome do livro pode ter apenas 20 caracteres.");
				} catch (ExcecaoCodigoRepetido e) {
					campoStatus.fixarTexto("Erro: Este Codigo já existe, ele deve ser único.");
				}
				esconderAguarde();
			}
		}
	}
	
}