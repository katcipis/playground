#Elementos de uma lista nao precisam ser todos do mesmo tipo
#Mais sobre listas: http://docs.python.org/tutorial/introduction.html#lists

lista = ["a", 2, "c", 5.0]

#indice comeca em 0
print(lista[0])
print(lista[1])
print(lista[2])
print(lista[3])

#iterando pela lista
for elemento in lista:
  print(elemento)

#alterando valor
print(lista)
lista[0] = "d"
print(lista)

#utilizando slices para acessar elementos da lista
print(lista[0:2])
print(lista[2:3])

#utilizando slices para alterar elementos da lista
lista[0:2] = [1,2]
print(lista)

# Agora um exemplo de list comprehensions
# Neste exemplo utilizaremos list comprehensions para filtrar
# uma lista de palavras, deixando apenas as que comecam com "a"
# Mais sobre list comprehensions: http://docs.python.org/tutorial/datastructures.html#list-comprehensions

palavras = ["teste", "concorrencia", "abacate", "abacaxi"]
palavras_com_a = [palavra for palavra in palavras if palavra.startswith("a")]

print(palavras)
print(palavras_com_a)

# O codigo alternativo sem utilizar list comprehensions
palavras_com_a = []
for palavra in palavras:
  if(palavra.startswith("a")):
    palavras_com_a.append(palavra)

print(palavras)
print(palavras_com_a)


