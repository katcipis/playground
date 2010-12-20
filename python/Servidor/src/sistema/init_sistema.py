from calculadoresDeMedia.MediaEntidadesNaFila import MediaEntidadesNaFila
from calculadoresDeMedia.MediaOcupacaoServidor import MediaOcupacaoServidor
from calculadoresDeMedia.TempoMedioDeEntidadesEmAlgo import TempoMedioDeEntidadesEmAlgo
from componentes.ListaDeTempoEntreEventos import ListaDeTempoEntreEventos
from componentes.Servidor import Servidor

def iniciarCalculadoresDeMedia(sistema):
  sistema._mediaEntidadesNaFilaUm = MediaEntidadesNaFila()
  sistema._mediaEntidadesNaFilaDois = MediaEntidadesNaFila()
      
  sistema._mediaOcupacaoServidorUm = MediaOcupacaoServidor()
  sistema._mediaOcupacaoServidorDois = MediaOcupacaoServidor()
      
  sistema._tempoMedioNaFilaDoServidorUm = TempoMedioDeEntidadesEmAlgo()
  sistema._tempoMedioNaFilaDoServidorDois = TempoMedioDeEntidadesEmAlgo()

def iniciarSomadoresDeTempoTotal(sistema):
  sistema._tempoTotalDeFalhaDoServidorUm = 0
  sistema._tempoTotalDeFalhaDoServidorDois = 0
    
def iniciarContadores(sistema):
  sistema._contadorDeFalhasNoServidorUm = 0
  sistema._contadorDeFalhasNoServidorDois = 0
  sistema._contadorDeTrocasNosServidores = 0
  
def iniciarComponentesDosServidores(sistema, filaDoServidorUm, filaDoServidorDois):
  sistema._servidorUm = Servidor('Servidor 1')
  sistema._servidorDois = Servidor('Servidor 2')
  sistema._filaDoServidorUm = filaDoServidorUm
  sistema._filaDoServidorDois = filaDoServidorDois
  sistema._tempoRestanteDeFalhaServidorUm   = 0
  sistema._tempoRestanteDeFalhaServidorDois = 0
  sistema._tempoRestanteDeServicoServidorUm   = 0
  sistema._tempoRestanteDeServicoServidorDois = 0
  sistema._tempoQueFaltaParaFalharServidorUm = 0
  sistema._tempoQueFaltaParaFalharServidorDois = 0
  sistema._amostrasEntidadesEsperandoNaFilaUm = []
  sistema._amostrasEntidadesEsperandoNaFilaDois = []