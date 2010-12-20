from Evento import Evento

def ehMaiorQue(evento1, evento2):
  return  int(evento1.obterTempoQueOcorre() - evento2.obterTempoQueOcorre())
  
class ListaDeEventosFuturos():
  
  def __init__(self):
    self.__listaEventos = []
    
  def adcionarEvento(self, evento):
    if(isinstance(evento, Evento)):
        self.__listaEventos.append(evento)
    
  def obterProximoEvento(self):
    if(not self.possuiEvento()):
        return None
      
    self.__listaEventos.sort(cmp=ehMaiorQue)
    return self.__listaEventos.pop(0)
  
  def possuiEvento(self):
    return len(self.__listaEventos) != 0
  
  def obterQuantosEventosRestam(self):
    return len(self.__listaEventos)