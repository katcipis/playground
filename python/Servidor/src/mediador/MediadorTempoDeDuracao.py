from gui.PainelTempoDeDuracao import PainelTempoDeDuracao

class MediadorTempoDeDuracao():
  
  def __init__(self, painelTempoDeDuracao):
    self.__painelTempoDeDuracao = painelTempoDeDuracao
    
  def obterTempoDeDuracao(self):
    return self.__painelTempoDeDuracao.obterTempoDeDuracao()
    
  