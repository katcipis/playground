from series import cosseno
from series import tchebyshev
from series import ln_raizquinta
import math

x = 0.2

print 'Cosseno segundo python: '
print math.cos(x); print ''

print 'Cosseno segundo taylor: '
print cosseno.aproximar_cosseno_taylor(x); print ''

print 'Testando como se obter parametros de tchebyshev'
print tchebyshev.obter_parametro_t(2.0, 5); print ''

print 'Testando cosseno x = 0.2 com pade'
print 'Aproximado: ', cosseno.aproximar_cosseno_pade(x)
print 'Exato: ', math.cos(x); print ''

print 'Testando ln * raiz quinta de 1 + x com pade'
print 'Por Pade: ', ln_raizquinta.aproximar_ln_raizquinta_pade(x)
print 'Por python: ', math.log(math.pow(1.0 + x, 1.0/5.0)); print ''

print 'Testando ln * raiz quinta de 1 + x com taylor'
print 'Por Taylor: ', ln_raizquinta.aproximar_ln_raizquinta_taylor(x)
print 'Por python: ', math.log(math.pow(1.0 + x, 1.0/5.0))