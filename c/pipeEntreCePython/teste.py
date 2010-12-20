import subprocess

arquivo = open('original', 'rb')

bytes = arquivo.read()
arquivo.close()
tamanho = len(bytes)

process = subprocess.Popen("./main " + str(tamanho), shell = True, stdin = subprocess.PIPE)
retorno = None

while(retorno == None):
  try:
    process.communicate(bytes) 
    retorno = process.poll()
  except:
    pass


