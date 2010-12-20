import lagrange
import newton

x = [1.0, 3.0, 4.0, 7.0]
y = [2.0, 0.0, 1.0, 3.0]

print 'Testando interpolador de lagrange com Alpha = 5'  
print lagrange.aproximar_funcao(x, y, 5.0, 3); print ''

print 'Testando interpolador de lagrange com Alpha = 8'  
print lagrange.aproximar_funcao(x, y, 8.0, 3); print ''

print 'Testando interpolador de newton com Alpha = 5'    
print newton.aproximar_funcao(x, y, 5.0, 3); print ''

print 'Testando interpolador de newton com Alpha = 8'    
print newton.aproximar_funcao(x, y, 8.0, 3); print ''