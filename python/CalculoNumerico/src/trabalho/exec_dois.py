from newton import newton_simples
from newton import newton_kinkeid
from newton import newton_steffensen

import trabalho_funcoes

print 'Funcao ln(x-1) + cos(x - 1)'; print ''

NUMERO_ITERACOES = 50
ERRO_MIN = 10 ** -10


print 'Usando newton simples'
resultado, erro = newton_simples.obter_alpha(trabalho_funcoes.exec_dois_funcao,
                                             trabalho_funcoes.exec_dois_derivada,
                                             ERRO_MIN, NUMERO_ITERACOES, 1.5)
print 'Alpha = ', resultado
print 'Erro = ', erro
print ''

print 'Usando newton kinkeid'
resultado, erro = newton_kinkeid.obter_alpha(trabalho_funcoes.exec_dois_funcao,
                                             trabalho_funcoes.exec_dois_derivada,
                                             trabalho_funcoes.exec_dois_derivada_seg,
                                             ERRO_MIN, NUMERO_ITERACOES, 1.5)
print 'Alpha = ', resultado
print 'Erro = ', erro
print ''


print 'Usando steffensen'
resultado, erro = newton_steffensen.obter_alpha(trabalho_funcoes.exec_dois_funcao,
                                             ERRO_MIN, NUMERO_ITERACOES, 1.5)
print 'Alpha = ', resultado
print 'Erro = ', erro
print ''
