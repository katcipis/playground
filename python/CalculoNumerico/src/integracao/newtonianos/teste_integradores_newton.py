import funcoes
from integracao.newtonianos import trapezio
from integracao.newtonianos import simpson
from integracao.newtonianos import simpson_composto
from integracao.newtonianos import trapezio_melhorado

print 'Testando integrador usando metodo de newton com a funcao lnx no intervalo 1-2'
res = trapezio.obter_integral(1.0, 2.0, funcoes.lnx)
i = 1
for r in res:
  print 'Integral', i, ': ', r
  i += 1


print 'Testando integrador usando metodo de simpson com a funcao lnx no intervalo 1-2'
res = simpson.obter_integral(1.0, 2.0, funcoes.lnx)
i = 1
for r in res:
  print 'Integral', i, ': ', r
  i += 1



print 'Testando integrador usando metodo de newton com a funcao 1/ xlnx no intervalo 2-4'
res = trapezio.obter_integral(2.0, 4.0, funcoes.inverso_x_lnx)
i = 1
for r in res:
  print 'Integral', i, ': ', r
  i += 1
  
  
print 'Testando integrador usando metodo de simpson com a funcao 1/ xlnx no intervalo 2-4'
res = simpson.obter_integral(2.0, 4.0, funcoes.inverso_x_lnx)
i = 1
for r in res:
  print 'Integral', i, ': ', r
  i += 1
  

x = []
y = []

x.append(1.0); x.append(1.25); x.append(1.50); x.append(1.75)
y.append(funcoes.lnx(1.0)); y.append(funcoes.lnx(1.25))  
y.append(funcoes.lnx(1.50)); y.append(funcoes.lnx(1.75))  
  
  
print 'Testando integrador usando metodo de trapezio aproximado com a funcao lnx no intervalo 1-2'
res = trapezio.obter_integral_aprox(1.0, 2.0, x, y, 3)
i = 1
for r in res:
  print 'Integral', i, ': ', r
  i += 1
  
  
print 'Testando integrador usando metodo de simpson aproximado com a funcao lnx no intervalo 1-2'
res = simpson.obter_integral_aprox(1.0, 2.0, x, y, 3)
i = 1
for r in res:
  print 'Integral', i, ': ', r
  i += 1
  

print 'Testando integrador usando metodo de simpson-composto com a funcao raiz de lnx no intervalo 1-2'
res = simpson_composto.obter_integral(1.0, 2.0, funcoes.raiz_lnx)
print 'Integral: ', res; print ''

print 'Testando integrador usando metodo de simpson-composto com a funcao lnx no intervalo 1-2'
res = simpson_composto.obter_integral(1.0, 2.0, funcoes.lnx)
print 'Integral: ', res; print ''
  
print 'Testando integrador usando metodo de trapezio com extrapolacao de romberg com a funcao 1/ x lnx no intervalo 2-4'
res = trapezio_melhorado.obter_integral(2.0, 4.0, funcoes.inverso_x_lnx, 3, 2, 10**-2)
print 'Integral: ', res; print ''