from newton import newton_simples
from newton import quasi_newton_um
from newton import newton_secante

import trabalho_funcoes

print 'Funcao 2X * cos(2x) - (x - 2)^2 = 0'; print ''

NUMERO_ITERACOES = 50
ERRO_MIN = 10 ** -10

print 'Usando newton simples'
resultado, erro = newton_simples.obter_alpha(trabalho_funcoes.exec_tres_funcao,
                                             trabalho_funcoes.exec_tres_derivada,
                                             ERRO_MIN, NUMERO_ITERACOES, 2.5)
print 'Alpha = ', resultado
print 'Erro = ', erro
print ''


print 'Usando newton com derivada fixa'
resultado, erro = quasi_newton_um.obter_alpha(trabalho_funcoes.exec_tres_funcao,
                                              trabalho_funcoes.exec_tres_derivada,
                                               ERRO_MIN, NUMERO_ITERACOES, 2.5)
print 'Alpha = ', resultado
print 'Erro = ', erro
print ''


print 'Usando newton secante'
resultado, erro = newton_secante.obter_alpha(trabalho_funcoes.exec_tres_funcao,
                                             ERRO_MIN, NUMERO_ITERACOES, 2.2, 2.5)
print 'Alpha = ', resultado
print 'Erro = ', erro
print ''