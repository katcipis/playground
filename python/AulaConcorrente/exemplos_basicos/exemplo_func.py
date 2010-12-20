

#definindo funcoes que nao retornam dados
#o escopo eh definido pela identacao e nao por chaves
def funcao_um():
  print("Executando funcao_um")

def funcao_dois():
  print("Executando funcao_dois")


#definindo funcao que retorna um string
#nao eh necessario especificar o tipo de retorno
def retorna_string():
  return "retorna_string()"


#definindo funcao que retorna um inteiro
def retorna_inteiro():
  return 1

#todas as funcoes retornam algo, se nao for definido um return na funcao (void)
#a funcao ira retornar None, que seria o equivalente de null em java.
def funcao_nao_retorna():
  a = "a"

#Funcoes podem ter valores default atribuidos aos argumentos. Como em C++
def funcao_param_default(arg = "Default"):
  print(arg)


#chamando funcoes 
funcao_um()
funcao_dois()

print("Imprimindo o que retorna da funcao: " + retorna_string())
print("Convertendo para string e imprimindo o numero que retorna da funcao: " + str(retorna_inteiro()))
print(funcao_nao_retorna())

funcao_param_default()
funcao_param_default("Nao default")




