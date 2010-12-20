import calculos_estatisticos

def adcionarDado(titulo, dado, dadosRelatorio):
  dadosRelatorio.append('-----------------------------------------\n')
  dadosRelatorio.append(str(titulo) + ' : ' + str(dado) + '\n')
  dadosRelatorio.append('-----------------------------------------\n')

def obterDados(sistema, dadosRelatorio):
    dadosRelatorio.append('------------- INICIO DO RELATORIO ---------------\n\n')
    dado1, dado2 = calculos_estatisticos.obterNumeroMedioDeEntidadesNasFilasDosServidores(sistema)
    adcionarDado('Numero medio de entidades na fila do Servidor 1', dado1, dadosRelatorio)
    adcionarDado('Numero medio de entidades na fila do Servidor 2', dado2, dadosRelatorio)
    
    dado1, dado2 = calculos_estatisticos.obterTaxaMediaDeOcupacaoDosServidores(sistema)
    dado1, dado2 = str(dado1 * 100) + '%', str(dado2 * 100) + '%'
    adcionarDado('Taxa media de ocupacao do Servidor 1', dado1, dadosRelatorio)
    adcionarDado('Taxa media de ocupacao do Servidor 2', dado2, dadosRelatorio)
    
    dado1, dado2 = calculos_estatisticos.obterTempoMedioDeUmaEntidadeNasFilasDosServidores(sistema)
    adcionarDado('Tempo medio das entidades na fila do Servidor 1', dado1, dadosRelatorio)
    adcionarDado('Tempo medio das entidades na fila do Servidor 2', dado2, dadosRelatorio)
    
    dado1 = calculos_estatisticos.obterTempoMedioNoSistema(sistema)
    adcionarDado('Tempo medio que as entidades ficaram no sistema', dado1, dadosRelatorio)
    
    dado1 = calculos_estatisticos.obterQuantasEntidadesEntraramNoSistema(sistema)
    adcionarDado('Quantidade de entidades que entraram no sistema', dado1, dadosRelatorio)
    
    dado1 = calculos_estatisticos.obterQuantasEntidadesSairamDoSistema(sistema)
    adcionarDado('Quantidade de entidades que sairam do sistema', dado1, dadosRelatorio)
    
    dado1 = calculos_estatisticos.obterQuantasEntidadesSeEncontramNoSistema(sistema)
    adcionarDado('Quantidade de entidades que se encontram no sistema', dado1, dadosRelatorio)
    
    dado1, dado2 = calculos_estatisticos.obterOTempoQueOsServidoresPermaneceramEmFalha(sistema)
    adcionarDado('Tempo que o Servidor 1 permaneceu em falha', dado1, dadosRelatorio)
    adcionarDado('Tempo que o Servidor 2 permaneceu em falha', dado2, dadosRelatorio)
    
    dado1, dado2 = calculos_estatisticos.obterQuantasVezesOsServidoresEntraramEmFalha(sistema)
    adcionarDado('Quantidade de vezes que o Servidor 1 entrou em falha', dado1, dadosRelatorio)
    adcionarDado('Quantidade de vezes que o Servidor 2 entrou em falha', dado2, dadosRelatorio)
    
    dado1, dado2 = calculos_estatisticos.obterPercentualQueOsServidoresFicaramEmFalha(sistema)
    dado1, dado2 = str(dado1 * 100) + '%', str(dado2 * 100) + '%'
    adcionarDado('Percentual de falha do Servidor Um', dado1, dadosRelatorio)
    adcionarDado('Percentual de falha do Servidor Dois', dado2, dadosRelatorio)
    
    dado1 = calculos_estatisticos.obterQuantidadeDeTrocasRealizadasEntreOsServidores(sistema)
    adcionarDado('Quantidade de entidades que trocaram entre servidores', dado1, dadosRelatorio)
    
    dado1 = calculos_estatisticos.obterQuantidadeDeEntidadesDescartadasComFalha(sistema)
    adcionarDado('Quantidade de entidades descartadas com falha', dado1, dadosRelatorio)
    dadosRelatorio.append('\n------------- FIM DO RELATORIO ---------------')


def gerarRelatorio(sistema, filename):
  relatorio = open(filename, 'w')
  dadosRelatorio = []
  
  obterDados(sistema, dadosRelatorio)
  
  for dado in dadosRelatorio:
    relatorio.write(dado)
    
  relatorio.close()
  
def gerarRelatorioParcial(sistema, filename):
  relatorio = open(filename, 'w')
  relatorio.write('!!!----Relatorio Parcial, simulacao foi cancelada durante execucao----!!!\n\n')  
 
  dadosRelatorio = []
  obterDados(sistema, dadosRelatorio)
  
  for dado in dadosRelatorio:
    relatorio.write(dado)
    
  relatorio.close()
  