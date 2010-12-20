# -*- coding: latin-1 -*-

import os

class ValidadorDeArquivos:

  def ArquivoEstaOk(self, diretorio, nomeArquivo):
    caminhoCompleto =  os.path.join(diretorio, nomeArquivo)
    existe = os.path.isfile(caminhoCompleto)
    extensaoCorreta = nomeArquivo.endswith(".csv")
    return existe and extensaoCorreta
  
class ConversorDeArquivos:
  
  def ConverterArquivo(self, caminhoArquivo):    
    
    try:
      arquivo = open(caminhoArquivo, 'r')
      arquivoLido = arquivo.read()
      arquivo.close()
    except(IOError):
      return False
   
    convertido = arquivoLido.replace("," , ";")
    nomeArquivoNovo = os.path.basename(caminhoArquivo)
    nomeArquivoNovo = 'Convertido - ' + nomeArquivoNovo
    caminhoArquivoNovo = os.path.join(os.path.split(caminhoArquivo)[0], nomeArquivoNovo)
    
    return self.CriarArquivoConvertido(caminhoArquivoNovo, convertido)
  
  def CriarArquivoConvertido(self, caminhoArquivo, arquivo):
    try:
      arquivoNovo = open(caminhoArquivo, 'w')
      arquivoNovo.write(arquivo)
      arquivoNovo.close()
    except(IOError):
      return False
    
    return True