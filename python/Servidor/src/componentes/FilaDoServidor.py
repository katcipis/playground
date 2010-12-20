
class FilaDoServidor():
  
  def __init__(self, tamanhoMaximo = 0):
    self.__entidades = []
    self.__maximo = tamanhoMaximo
    
  def obterQuantasEntidadesPossui(self):
    return len(self.__entidades)
  
  def estaVazia(self):
    return self.obterQuantasEntidadesPossui() == 0
  
  def estaCheia(self):
    if(self.__maximo == 0):
      return False
    
    return self.obterQuantasEntidadesPossui() >= self.__maximo
    
  def obterEntidade(self):
    if(self.estaVazia()):
      return None
    
    return self.__entidades.pop()
  
  def adcionarEntidade(self, entidade):
    if(not self.estaCheia()):   
      if(entidade not in self.__entidades):
        self.__entidades.insert(0,entidade)
