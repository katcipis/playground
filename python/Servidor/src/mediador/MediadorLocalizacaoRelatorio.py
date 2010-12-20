from gui.PainelLocalizacaoRelatorio import PainelLocalizacaoRelatorio

class MediadorLocalizacaoRelatorio():
  
  def __init__(self, painelLocalizacaoRelatorio):
    self.__painelLocalizacaoRelatorio = painelLocalizacaoRelatorio
    
  def obterLocalizacaoRelatorio(self):
    return self.__painelLocalizacaoRelatorio.obterEnderecoRelatorio()
    
  