package componentesGedixAbstratos;

import static infraestruturaDoComponenteGedix.StringVazia.STRING_VAZIA;
import infraestruturaDoComponenteGedix.ComponenteGedix;
import infraestruturaDoComponenteGedix.PosicoesDaLegenda;
import infraestruturaDoPainelDeComponenteGedix.Dimensao;
import infraestruturaDoPainelDeComponenteGedix.Posicao;
import infraestruturaDoPainelDeComponenteGedix.RetanguloPosicionavel;
import edugraf.jadix.fachada.TiposDeComponentesDix;

public abstract class ComponenteGedixAbstrato implements ComponenteGedix  {

	private final RetanguloPosicionavel retânguloPosicionável;
	protected final TiposDeComponentesDix meuTipo;
	private boolean visível, habilitado;
	private String nome, legenda;
	private PosicoesDaLegenda posiçãoDaLegenda;
	private int profundidade;

	public ComponenteGedixAbstrato(RetanguloPosicionavel r) {
		retânguloPosicionável = r;
		visível = true;
		profundidade = 0;
		legenda = STRING_VAZIA.nome;
		habilitado = true;
		posiçãoDaLegenda = PosicoesDaLegenda.EM_CIMA;
		meuTipo = definirMeuTipo();
		nome = definirMeuNome();
	}

	protected abstract String definirMeuNome();

	protected abstract TiposDeComponentesDix definirMeuTipo();

	public Posicao obterPosiçãoDeOrigem() {
		return retânguloPosicionável.obterPosiçãoDeOrigem();
	}

	public void definirPosiçãoDeOrigem(Posicao p) {
		retânguloPosicionável.definirPosiçãoDeOrigem(p);
	}

	public boolean verificarSeOcupaAPosição(Posicao p) {

		return retânguloPosicionável.verificarSeOcupaAPosição(p);
	}

	public int obterAltura() {
		return retânguloPosicionável.obterAltura();
	}

	public int obterLargura() {
		return retânguloPosicionável.obterLargura();
	}

	public void definirAltura(int altura) {
		retânguloPosicionável.definirAltura(altura);
	}

	public void definirLargura(int largura) {
		retânguloPosicionável.definirLargura(largura);
	}

	public void definirDimensão(Dimensao d) {
		retânguloPosicionável.definirDimensão(d);
	}

	public Dimensao obterDimensão() {
		return retânguloPosicionável.obterDimensão();
	}

	public TiposDeComponentesDix obterTipo() {
		return meuTipo;
	}

	public String obterNome() {
		return nome;
	}

	public void alterarNome(String n) {
		nome = n;
	}

	public void tornarVisível() {
		visível = true;
	}

	public void tornarInvisível() {
		visível = false;
	}

	public boolean verificarSeEstáVisível() {
		return visível;
	}

	public void habilitar() {
		habilitado = true;
	}

	public void desabilitar() {
		habilitado = false;
	}

	public boolean verificarSeEstáHabilitado() {
		return habilitado;
	}

	public void alterarLegenda(String s) {
		legenda = s;
	}

	public String obterLegenda() {
		return legenda;
	}

	public void definirPosiçãoDaLegenda(PosicoesDaLegenda novaLegenda) {
		posiçãoDaLegenda = novaLegenda;
	}

	public PosicoesDaLegenda obterPosiçãoDaLegenda() {
		return posiçãoDaLegenda;
	}
	
    public void definirProfundidade(int novaProfundidade){
    	if(novaProfundidade >= 0)
    	     profundidade = novaProfundidade;
    }
	
	public int obterProfundidade(){
		return profundidade;
	}

}
