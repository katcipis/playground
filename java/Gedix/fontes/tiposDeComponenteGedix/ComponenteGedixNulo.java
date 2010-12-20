package tiposDeComponenteGedix;

import java.util.ArrayList;
import java.util.List;

import infraestruturaDoComponenteGedix.ComponenteGedixRotulavelComURI;
import infraestruturaDoComponenteGedix.PosicoesDaLegenda;
import infraestruturaDoComponenteGedix.Opcao;
import infraestruturaDoComponenteGedix.ComponenteGedixComGrade;
import infraestruturaDoComponenteGedix.ComponenteGedixComOpcoes;
import infraestruturaDoComponenteGedix.ComponenteGedixComURI;
import infraestruturaDoComponenteGedix.ComponenteGedixRotulavel;
import infraestruturaDoPainelDeComponenteGedix.Dimensao;
import infraestruturaDoPainelDeComponenteGedix.Fabrica;
import infraestruturaDoPainelDeComponenteGedix.Posicao;
import edugraf.jadix.fachada.TiposDeComponentesDix;
import static edugraf.jadix.fachada.TiposDeComponentesDix.*;

import static infraestruturaDoComponenteGedix.StringVazia.*;

public class ComponenteGedixNulo implements ComponenteGedixRotulavel,
		ComponenteGedixComURI, ComponenteGedixComOpcoes, ComponenteGedixComGrade, ComponenteGedixRotulavelComURI {


	private final Dimensao dimensão;
	private final String vazio;
	private final Opcao opçãoVazia;
	private final int númeroDeLinhas, númeroDeColunas, profundidade;

	public ComponenteGedixNulo() {
	
		dimensão = Fabrica.obterDimensão(0, 0);
		vazio = STRING_VAZIA.nome;
		númeroDeLinhas = 0;
		númeroDeColunas = 0;
		opçãoVazia = Fabrica.obterOpçãoDeNome(vazio);
		profundidade = 0;
	}

	public Posicao obterPosiçãoDeOrigem() {
		return Fabrica.obterPosicaoNula();
	}

	public void definirPosiçãoDeOrigem(Posicao p) {

	}

	public boolean verificarSeOcupaAPosição(Posicao p) {
		return false;
	}

	protected void definirPosiçõesQueOcupa() {

	}

	public int obterAltura() {
		return dimensão.obterAltura();
	}

	public int obterLargura() {
		return dimensão.obterLargura();
	}

	public void definirAltura(int altura) {

	}

	public void definirLargura(int largura) {

	}

	public void definirDimensão(Dimensao d) {

	}

	public Dimensao obterDimensão() {
		return dimensão;
	}

	@Override
	public boolean equals(Object o) {
		return (o instanceof ComponenteGedixNulo);
	}

	public TiposDeComponentesDix obterTipo() {
		return BOTÃO;
	}

	public String obterNome() {
		return vazio;
	}

	public void alterarNome(String s) {

	}

	public void tornarVisível() {

	}

	public void tornarInvisível() {

	}

	public boolean verificarSeEstáVisível() {
		return false;
	}

	public void habilitar() {

	}

	public void desabilitar() {

	}

	public boolean verificarSeEstáHabilitado() {
		return false;
	}

	public void alterarLegenda(String s) {

	}

	public String obterLegenda() {
		return vazio;
	}

	public void definirPosiçãoDaLegenda(PosicoesDaLegenda l) {

	}

	public PosicoesDaLegenda obterPosiçãoDaLegenda() {
		return PosicoesDaLegenda.NULO;
	}

	public void alterarTexto(String novoTexto) {

	}

	public String obterTexto() {

		return vazio;
	}

	public void alterarURI(String novaURI) {

	}

	public String obterURI() {

		return vazio;
	}

	public void adcionarListaDeOpções(List<Opcao> novaLista) {

	}

	public boolean adcionarOpção(Opcao novaOpção) {
		return false;
	}

	public void removerTodasAsOpções() {

	}

	public List<Opcao> obterListaDeOpções() {
		return new ArrayList<Opcao>();
	}

	public Opcao obterOpção(int indiceDaOpção) {

		return opçãoVazia;
	}

	public int obterQuantidadeDeOpções() {

		return 0;
	}

	public boolean removerOpção(int indiceDaOpção) {

		return false;
	}

	public void substituirListaDeOpções(List<Opcao> novaLista) {

	}

	public boolean verificarSeExisteUmaOpçãoComEsseTextoNaLista(String opção) {

		return false;
	}

	public boolean possuiAOpçãoDeÍndice(int indice) {

		return false;
	}

	public boolean alterarNúmeroDeColunas(int novoNúmeroDeColunas) {

		return false;
	}

	public boolean alterarNúmeroDeLinhas(int novoNúmeroDeLinhas) {

		return false;
	}

	public int obterNúmeroDeColunas() {

		return númeroDeColunas;
	}

	public int obterNúmeroDeLinhas() {

		return númeroDeLinhas;
	}

	public boolean removerOpção(Opcao o) {
	
		return false;
	}

	public boolean possuiAOpção(Opcao o) {
		
		return false;
	}

	public void definirProfundidade(int novaProfundidade) {	
	}

	public int obterProfundidade() {
		return profundidade;
	}

}
