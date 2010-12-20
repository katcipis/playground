import naturais
import quadraticas

x = [0.0, 1.0, 2.0, 3.0, 4.0]
y= [-3.0, -2.0, 5.0, 24.0, 61.0]

print 'Aproximando funcao usando spline natura no ponto 2.5'
print naturais.obter_aproximacao(x, y, 4, 2.5)

print 'Aproximando funcao usando spline quadratica no ponto 2.5'
print quadraticas.obter_aproximacao(x, y, 4, 2.5)