from newton import newton_simples
from newton import quasi_newton_um
from newton import newton_secante

import trabalho_funcoes

print 'Funcao x^2 -2xe^-x + e^-2x = 0'; print ''

NUMERO_ITERACOES = 50
ERRO_MIN = 10 ** -10



print 'Usando newton simples'
resultado, erro = newton_simples.obter_alpha(trabalho_funcoes.exec_um_funcao,
                                             trabalho_funcoes.exec_um_derivada,
                                             ERRO_MIN, NUMERO_ITERACOES, 0.0)
print 'Alpha = ', resultado
print 'Erro = ', erro
print ''

print 'Usando quasi newton derivada fixa'
resultado, erro = quasi_newton_um.obter_alpha(trabalho_funcoes.exec_um_funcao,
                                             trabalho_funcoes.exec_um_derivada,
                                             ERRO_MIN, NUMERO_ITERACOES, 0.6)
print 'Alpha = ', resultado
print 'Erro = ', erro
print ''


print 'Usando newton secante'
resultado, erro = newton_secante.obter_alpha(trabalho_funcoes.exec_um_funcao,
                                             ERRO_MIN, NUMERO_ITERACOES, 1.0, 0.6)
print 'Alpha = ', resultado
print 'Erro = ', erro
print ''