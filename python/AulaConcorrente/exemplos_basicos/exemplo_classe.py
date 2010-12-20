
# Definindo uma classe
# Mais detalhes sobre classes e heranca em python: http://docs.python.org/tutorial/classes.html
class ClasseExemplo():

  #definindo o construtor da classe
  #o primeiro parametro de todo metodo
  #de uma classe eh self, onde self eh
  #a propria instancia (como o this em java e C++)
  def __init__(self):
    #criando variaveis
    self.a = "a"
    self.b = "b"

  #definindo gets
  def getA(self):
    return self.a

  def getB(self):
    return self.b

  #definindo sets
  def setA(self, parametro):
    self.a = parametro

  def setB(self, parametro):
    self.b = parametro


#instanciando a classe
instancia = ClasseExemplo()

#usando os gets
print("Executando instancia.getA(): " + instancia.getA())
print("Executando instancia.getB(): " + instancia.getB())

#usando os sets
instancia.setA("Variavel a redefinida")
instancia.setB("Variavel b redefinida")

print("Executando instancia.getA(): " + instancia.getA())
print("Executando instancia.getB(): " + instancia.getB())

#acessando variaveis diretamente
print("Acessando diretamente instancia.a: " + instancia.a)
print("Acessando diretamente instancia.b: " + instancia.b)

#Agora uma peculiaridade interessante em python que
#nao existe em linguagens de tipagem estatica,
#criacao de variaveis dinamicamente em tempo de execucao
#da mesma maneira que as variaveis sao criadas no construtor
#da classe elas podem ser criadas a qualquer momento e em qualquer lugar.
instancia.novaVariavel = "novaVariavel"
print("Imprimindo variavel criada dinamicamente: " + instancia.novaVariavel)

