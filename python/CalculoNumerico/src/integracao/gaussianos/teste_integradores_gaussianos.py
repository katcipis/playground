import funcoes
from integracao.gaussianos import gauss
from integracao.gaussianos import gauss_tentativas
from integracao.gaussianos import gauss_composto
from integracao.gaussianos import gauss_tchebyshev
from integracao.gaussianos import gauss_improprias
import math

print 'Testando integrador usando metodo de gauss com a funcao raiz de lnx no intervalo 1-2'
print 'Com m = 2'
res = gauss.obter_integral(1.0, 2.0, funcoes.raiz_lnx, 2)
print 'Integral: ', res; print ''

print 'Com m = 3'
res = gauss.obter_integral(1.0, 2.0, funcoes.raiz_lnx, 3)
print 'Integral: ', res; print ''

print 'Com m = 4'
res = gauss.obter_integral(1.0, 2.0, funcoes.raiz_lnx, 4)
print 'Integral: ', res; print ''



print 'Testando integrador usando metodo de gauss com a funcao lnx no intervalo 0-1'
print 'Com m = 2'
res = gauss.obter_integral(0.0, 1.0, funcoes.lnx, 2)
print 'Integral: ', res; print ''

print 'Com m = 3'
res = gauss.obter_integral(0.0, 1.0, funcoes.lnx, 3)
print 'Integral: ', res; print ''

print 'Com m = 4'
res = gauss.obter_integral(0.0, 1.0, funcoes.lnx, 4)
print 'Integral: ', res; print ''



print 'Testando integrador usando metodo de gauss-tentativas com a funcao lnx no intervalo 0-1'
res = gauss_tentativas.obter_integral(0.0, 1.0, funcoes.lnx)
print 'Integral: ', res; print ''

print 'Testando integrador usando metodo de gauss-tentativas com a funcao raiz de lnx no intervalo 1-2'
res = gauss_tentativas.obter_integral(1.0, 2.0, funcoes.raiz_lnx)
print 'Integral: ', res; print ''



print 'Testando integrador usando metodo de gauss-composto com a funcao lnx no intervalo 0-1'
res = gauss_composto.obter_integral(0.0, 1.0, funcoes.lnx)
print 'Integral: ', res; print ''

print 'Testando integrador usando metodo de gauss-composto com a funcao raiz de lnx no intervalo 1-2'
res = gauss_composto.obter_integral(1.0, 2.0, funcoes.raiz_lnx)
print 'Integral: ', res; print ''

print 'Testando integrador usando metodo de gauss-composto com a funcao lnx no intervalo 1-2'
res = gauss_composto.obter_integral(1.0, 2.0, funcoes.lnx)
print 'Integral: ', res; print ''



print 'Testando integrador usando metodo de gauss-tchebyshev. com a funcao x senx no intervalo -1, 1'
res = gauss_tchebyshev.obter_integral(funcoes.x_senx)
print 'Integral: ', res; print ''

print 'Testando integrador usando metodo de gauss-improprias. com a funcao e^-x no intervalo 1, OO'
res = gauss_improprias.obter_integral(1.0, lambda x: math.exp(-x))
print 'Integral: ', res; print ''
