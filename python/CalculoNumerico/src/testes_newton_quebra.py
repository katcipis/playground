import funcoes

from quebra import bissecao 
from quebra import falsa_posicao
from quebra import falsa_posicaom

from newton import newton_simples
from newton import quasi_newton_um
from newton import newton_secante
from newton import newton_steffensen
from newton import newton_kinkeid

import math

INTERVALO = [0,1]
ERRO_DET = math.pow(10, -10)
ITER = funcoes.calcular_num_iteracoes(INTERVALO[0], INTERVALO[1], ERRO_DET)

print 'Por bissecao: '
print 'Numero de iteracoes necessarios = ', ITER
resultado, erro = bissecao.obter_alpha(INTERVALO, funcoes.convergente_simples, ERRO_DET, ITER)
print 'Alpha = ', resultado
print 'Erro = ', erro
print ''

print 'Por falsa posicao: '
print 'Numero de iteracoes necessarios = ', ITER
resultado, erro = falsa_posicao.obter_alpha(INTERVALO, funcoes.convergente_simples, ERRO_DET, ITER)
print 'Alpha = ', resultado
print 'Erro = ', erro
print ''

print 'Por falsa posicao melhorado: '
print 'Numero de iteracoes necessarios = ', ITER
resultado, erro = falsa_posicaom.obter_alpha(INTERVALO, funcoes.convergente_simples, ERRO_DET, ITER)
print 'Alpha = ', resultado
print 'Erro = ', erro
print ''

print 'Por newton convergindo'
resultado, erro = newton_simples.obter_alpha(funcoes.newton_convergente, funcoes.der_newton_convergente, ERRO_DET, 10, 0)
print 'Alpha = ', resultado
print 'Erro = ', erro
print ''

print 'Por newton divergindo (indo pro inferno :P)'
resultado, erro = newton_simples.obter_alpha(funcoes.newton_divergente, funcoes.der_newton_divergente, ERRO_DET, 10, 10)
print 'Alpha = ', resultado
print 'Erro = ', erro
print ''

print 'Por newton quasi um, convergindo'
resultado, erro = quasi_newton_um.obter_alpha(funcoes.newton_convergente, funcoes.der_newton_convergente, ERRO_DET, 20, 0)
print 'Alpha = ', resultado
print 'Erro = ', erro
print ''

print 'Por newton quasi um, divergindo (indo pro inferno :P)'
resultado, erro = quasi_newton_um.obter_alpha(funcoes.newton_divergente, funcoes.der_newton_divergente, ERRO_DET, 10, 10)
print 'Alpha = ', resultado
print 'Erro = ', erro
print ''

print 'Por newton metodo da secante, convergindo'
resultado, erro = newton_secante.obter_alpha(funcoes.newton_convergente, ERRO_DET, 20, 0, 0.1)
print 'Alpha = ', resultado
print 'Erro = ', erro
print ''

print 'Por newton metodo da secante, divergindo (abraca o diabo :P)'
resultado, erro = newton_secante.obter_alpha(funcoes.newton_divergente, ERRO_DET, 20, 5, 10)
print 'Alpha = ', resultado
print 'Erro = ', erro
print ''

print 'Por newton metodo de steffensen, convergindo'
resultado, erro = newton_steffensen.obter_alpha(funcoes.newton_convergente, ERRO_DET, 20, 0)
print 'Alpha = ', resultado
print 'Erro = ', erro
print ''

print 'Por newton metodo de steffensen, divergindo (indo pra saudade )'
resultado, erro = newton_steffensen.obter_alpha(funcoes.newton_divergente, ERRO_DET, 10, 10)
print 'Alpha = ', resultado
print 'Erro = ', erro
print ''

print 'Por newton kinkeid convergindo'
resultado, erro = newton_kinkeid.obter_alpha(funcoes.newton_convergente, 
                                             funcoes.der_newton_convergente,
                                             funcoes.der_seg_newton_convergente,
                                              ERRO_DET, 10, 0)
print 'Alpha = ', resultado
print 'Erro = ', erro
print ''
