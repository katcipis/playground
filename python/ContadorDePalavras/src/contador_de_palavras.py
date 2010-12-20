#! /usr/bin/env python
# -*- coding: latin-1 -*-
 
import os
import sys
import string

def string_ok(segmento):
  for letra in segmento:
    if(not(letra in string.lowercase)):
      return False
    
  return True

def contar_com_intervalo(linha, dicionario, tamanho = 1):
  indice = 0
  maximo = len(linha)
  while(indice < maximo):
    tmp = indice + tamanho
    if(tmp < maximo):
      segmento = linha[indice:tmp]
      indice += 1
      segmento = segmento.lower()
      if(string_ok(segmento)):
        if(segmento in dicionario):
          dicionario[segmento] += 1
        else:
          dicionario[segmento] = 1
    else:
      indice = maximo

def gravar_em_arquivo(dicionario_tmp, arquivo):
  str_tmp = ''
  for letra, quantidade in sorted(dicionario_tmp.iteritems()):
      str_tmp = str_tmp + letra + ': ' + str(quantidade) + '\n'
      
  arquivo.write(str_tmp)
  arquivo.close()

#<<<<<<<<<<<<<<<<<<<Execucao do programa>>>>>>>>>>>>>>>>>>>>>#

ARGUMENTOS_PASSADOS = sys.argv
dicionario = dict()
dicionario_par = dict()
dicionario_trio = dict()

letras = open('letras.txt', 'w')
duas_letras = open('duas_letras.txt', 'w')
tres_letras = open('tres_letras.txt', 'w')


if(len(ARGUMENTOS_PASSADOS) > 1):
  CAMINHO_ARQUIVO = ARGUMENTOS_PASSADOS[1]
  if(os.path.isfile(CAMINHO_ARQUIVO)):
    
    arquivo = open(CAMINHO_ARQUIVO, 'r')
    for linha in arquivo:
      contar_com_intervalo(linha, dicionario, 1)
      contar_com_intervalo(linha, dicionario_par, 2)
      contar_com_intervalo(linha, dicionario_trio, 3)
      
    gravar_em_arquivo(dicionario, letras)
    
    gravar_em_arquivo(dicionario_par, duas_letras)
    
    gravar_em_arquivo(dicionario_trio, tres_letras)
      
else:
  print 'Por favor informe o caminho para o arquivo'