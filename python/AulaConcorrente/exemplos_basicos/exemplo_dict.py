#Neste exemplo vamos utilizar a estrutura de dados dict.
#Dict eh similar ao hashmap do java, ele mapeia uma chave com um valor.
#Mais informacoes: http://docs.python.org/tutorial/datastructures.html#dictionaries

#Inicializando um dicionario
dicionario = {"Chave_um" : "1", "Chave_dois" : "2"}

#obtendo uma lista com todas as chaves
print(dicionario.keys())

#obtendo uma lista com todos os valores
print(dicionario.values())

#acessando um valor a partir da chave
print(dicionario["Chave_um"])

#iterando pelo dicionario
for chave in dicionario:
  print(chave + " mapeia para " + dicionario[chave])

#verificando se uma chave se encontra no dicionario
print("Chave_um" in dicionario)
print("Falso" in dicionario)

#verificando se um valor se encontra no dicionario
print("1" in dicionario.values())

#removendo um elemento do dicionario
print("Dicionario antes de deletar: " + str(dicionario))
del dicionario["Chave_um"]
print("Dicionario depois de deletar: " + str(dicionario))
