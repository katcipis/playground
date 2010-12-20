#Neste exemplo vamos criar um arquivo, escrever nele e depois le-lo
#Documentacao da funcao open: http://docs.python.org/library/functions.html#open

nome_arquivo = 'arquivo_teste.txt'
arquivo = open(nome_arquivo, 'w') #w significa que estamos abrindo para gravacao

#agora gravamos 10 linhas no arquivo
for i in range(1, 11):
  arquivo.write('Linha ' + str(i))
  arquivo.write('\n')

arquivo.close()

arquivo = open(nome_arquivo, 'r') #r significa que estamos abrindo para leitura

for linha in arquivo:
  print(linha)

arquivo.close()


