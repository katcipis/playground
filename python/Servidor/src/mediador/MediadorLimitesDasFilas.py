from gui.PainelLimiteDasFilas import PainelLimiteDasFilas

class MediadorLimitesDasFilas():
  
  def __init__(self, painelLimiteDasFilas):
    self.__painelLimiteDasFilas = painelLimiteDasFilas
    
  def obterLimitesDasFilas(self):
    return self.__painelLimiteDasFilas.obterLimitesDasFilas()
    
  