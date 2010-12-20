from sistema.Sistema import Sistema
from sistema.GeradorDeChegadasDeEntidades import GeradorDeChegadasDeEntidades
from componentes.ListaDeEventosFuturos import ListaDeEventosFuturos
from componentes.Evento import Evento
from componentes.Entidade import Entidade


def imprimirEventosDeChegada(chegadas):
    while (chegadas.possuiEvento()):
        evento = chegadas.obterProximoEvento()
        entidade = evento.obterEntidade()
        print "Tipo: ", evento.obterTipo(), " : ", "Tempo que ocorre: ", evento.obterTempoQueOcorre()
        print "ID Entidade: ", entidade.obterID(), " : ", "Tipo da entidade: ", entidade.obterTipo()
        print " ------------------------------------------------ "

def testeBaseGeradorDeChegadasEntidades(geradorDeChegadas):

  chegadas = geradorDeChegadas.obterListaDeChegadasDasEntidades(100, 0)
  imprimirEventosDeChegada(chegadas)
    
  chegadas = geradorDeChegadas.obterListaDeChegadasDasEntidades(100, 100)
  imprimirEventosDeChegada(chegadas)
    
  chegadas = geradorDeChegadas.obterListaDeChegadasDasEntidades(50, 200)
  imprimirEventosDeChegada(chegadas)
  