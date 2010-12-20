from newton import newton_simples
from newton import quasi_newton_um
from newton import newton_secante
from newton import newton_steffensen

import trabalho_funcoes
import math

print 'Funcao x^2 -4xsenx -2cos2x + 2 = 0'; print ''

NUMERO_ITERACOES = 50
ERRO_MIN = 10 ** -10
x_um = math.pi / 2.0
x_dois = math.pi * 5.0
x_tres = math.pi * 10.0

print 'Usando newton simples, com x0 = pi/2'
resultado, erro = newton_simples.obter_alpha(trabalho_funcoes.exec_quatro_funcao,
                                             trabalho_funcoes.exec_quatro_derivada,
                                             ERRO_MIN, NUMERO_ITERACOES, x_um)
print 'Alpha = ', resultado
print 'Erro = ', erro
print ''


print 'Usando newton com derivada fixa, com x0 = pi/2'
resultado, erro = quasi_newton_um.obter_alpha(trabalho_funcoes.exec_quatro_funcao,
                                              trabalho_funcoes.exec_quatro_derivada,
                                               ERRO_MIN, NUMERO_ITERACOES, x_um)
print 'Alpha = ', resultado
print 'Erro = ', erro
print ''


print 'Usando newton secante, com x0 = pi/2 '
resultado, erro = newton_secante.obter_alpha(trabalho_funcoes.exec_quatro_funcao,
                                             ERRO_MIN, NUMERO_ITERACOES, x_um, (x_um + 0.1))
print 'Alpha = ', resultado
print 'Erro = ', erro
print ''


#<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>#


print 'Usando newton simples, com x0 = 5 * pi'
resultado, erro = newton_simples.obter_alpha(trabalho_funcoes.exec_quatro_funcao,
                                             trabalho_funcoes.exec_quatro_derivada,
                                             ERRO_MIN, NUMERO_ITERACOES, x_dois)
print 'Alpha = ', resultado
print 'Erro = ', erro
print ''


print 'Usando newton steffensen, com x0 = 5 * pi'
resultado, erro = newton_steffensen.obter_alpha(trabalho_funcoes.exec_quatro_funcao,
                                             ERRO_MIN, NUMERO_ITERACOES, x_dois)
print 'Alpha = ', resultado
print 'Erro = ', erro
print ''


print 'Usando newton secante, com x0 = 5 * pi'
resultado, erro = newton_secante.obter_alpha(trabalho_funcoes.exec_quatro_funcao,
                                             ERRO_MIN, NUMERO_ITERACOES, x_dois, (x_dois + 0.1))
print 'Alpha = ', resultado
print 'Erro = ', erro
print ''

#<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>#


print 'Usando newton simples, com x0 = 10 * pi'
resultado, erro = newton_simples.obter_alpha(trabalho_funcoes.exec_quatro_funcao,
                                             trabalho_funcoes.exec_quatro_derivada,
                                             ERRO_MIN, NUMERO_ITERACOES, x_tres)
print 'Alpha = ', resultado
print 'Erro = ', erro
print ''


print 'Usando newton steffensen, com x0 = 10 * pi'
resultado, erro = newton_steffensen.obter_alpha(trabalho_funcoes.exec_quatro_funcao,
                                             ERRO_MIN, NUMERO_ITERACOES, x_tres)
print 'Alpha = ', resultado
print 'Erro = ', erro
print ''


print 'Usando newton secante, com x0 = 10 * pi'
resultado, erro = newton_secante.obter_alpha(trabalho_funcoes.exec_quatro_funcao,
                                             ERRO_MIN, NUMERO_ITERACOES, x_tres, (x_tres + 0.1))
print 'Alpha = ', resultado
print 'Erro = ', erro
print ''