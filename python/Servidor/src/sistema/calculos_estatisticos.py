
def obterNumeroMedioDeEntidadesNasFilasDosServidores(sistema):
  somatorioServidorUm = 0
  somatorioServidorDois = 0
  totalServidorUm   = len(sistema._amostrasEntidadesEsperandoNaFilaUm)
  totalServidorDois = len(sistema._amostrasEntidadesEsperandoNaFilaDois)
  mediaServidorUm = 0
  mediaServidorDois = 0
  
  for amostra in sistema._amostrasEntidadesEsperandoNaFilaUm:
    somatorioServidorUm += amostra
    
  for amostra in sistema._amostrasEntidadesEsperandoNaFilaDois:
    somatorioServidorDois += amostra
  
  if(totalServidorUm != 0):
    mediaServidorUm = float(somatorioServidorUm) / float(totalServidorUm)
    
  if(totalServidorDois != 0):
    mediaServidorDois = float(somatorioServidorDois) / float(totalServidorDois)
    
  return mediaServidorUm, mediaServidorDois
  
def obterTaxaMediaDeOcupacaoDosServidores(sistema):
  media1 = sistema._mediaOcupacaoServidorUm.obterMedia(sistema._tempoTotalDeSimulacao)
  media2 = sistema._mediaOcupacaoServidorDois.obterMedia(sistema._tempoTotalDeSimulacao)
  return media1, media2
         
  
def obterTempoMedioDeUmaEntidadeNasFilasDosServidores(sistema):
  media1 = sistema._tempoMedioNaFilaDoServidorUm.obterMedia()
  media2 = sistema._tempoMedioNaFilaDoServidorDois.obterMedia()
  return media1, media2
  
def obterTempoMedioNoSistema(sistema):
  temposDispendidosNoSistema = []
  
  for chegada in sistema._historicoDeChegadaDeEntidades:
    for saida in sistema._historicoDeSaidaDeEntidades:
      if(chegada.obterEntidade().obterID() == saida.obterEntidade().obterID()):
        temposDispendidosNoSistema.append(saida.obterTempoQueOcorre() - chegada.obterTempoQueOcorre())
        
  totalDeAmostras = len(temposDispendidosNoSistema)
  if(totalDeAmostras == 0):
    return 0
  
  somatorioTempos = 0
  for amostra in temposDispendidosNoSistema:
    somatorioTempos += amostra
    
  return somatorioTempos / totalDeAmostras
  
  
def obterQuantasEntidadesEntraramNoSistema(sistema):
  return len(sistema._historicoDeChegadaDeEntidades)
  
def obterQuantasEntidadesSairamDoSistema(sistema):
  return len(sistema._historicoDeSaidaDeEntidades)

def obterQuantasEntidadesSeEncontramNoSistema(sistema):
  return obterQuantasEntidadesEntraramNoSistema(sistema) - obterQuantasEntidadesSairamDoSistema(sistema)

def obterOTempoQueOsServidoresPermaneceramEmFalha(sistema):
  return sistema._tempoTotalDeFalhaDoServidorUm ,sistema._tempoTotalDeFalhaDoServidorDois

def obterQuantasVezesOsServidoresEntraramEmFalha(sistema):
  return sistema._contadorDeFalhasNoServidorUm , sistema._contadorDeFalhasNoServidorDois
  
def obterPercentualQueOsServidoresFicaramEmFalha(sistema):
  perc_servidorUm   = float(sistema._tempoTotalDeFalhaDoServidorUm) / float(sistema._tempoTotalDeSimulacao)  
  perc_servidorDois = float(sistema._tempoTotalDeFalhaDoServidorDois) / float(sistema._tempoTotalDeSimulacao)
  return perc_servidorUm, perc_servidorDois  
  
def obterQuantidadeDeTrocasRealizadasEntreOsServidores(sistema):
  return sistema._contadorDeTrocasNosServidores
  
def obterQuantidadeDeEntidadesDescartadasComFalha(sistema):
  contador = 0
  for saida in sistema._historicoDeSaidaDeEntidades:
    if(saida.obterEntidade().falhou()):
      contador += 1
      
  return contador