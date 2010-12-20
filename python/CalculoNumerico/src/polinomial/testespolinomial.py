import horner
import divisao
import multiplicidade
import localizacao_raizes
import newton_polinomial
import newton_kinkeid_pol

grau = 4
coeficientes = [2.0, 0.0, 0.0, 3.0, -2.0]
coeficientes_multi = [1.0, -1.0, -5.0, 1.0, 8.0, 0.0]
coeficientes_loc = [2.0, 0.0, 0.0, 0.0, -8.0, 3.0]
coeficientes_newton = [2.0, 0.0, 0.0, 3.0, -5.0]
x = 2.0

print 'Testando solver uma polinomial simples usando horner'
print horner.obter_resto(grau, coeficientes, x); print ''

print 'Testando solver uma polinomial simples e obter derivadas usando divisao'
print divisao.obter_resto(grau, coeficientes, x); print ''

print 'Testando obter multiplicidade de uma raiz'
print multiplicidade.verifica_multiplicidade(5, coeficientes_multi, -1.0); print ''

print 'Testando obter localizacao das raizes'
print localizacao_raizes.obter_localizacao_raizes(5, coeficientes_loc); print ''

print 'Testando obter localizacao refinada das raizes bom Beta = 0'
print localizacao_raizes.obter_localizacao_ref_raizes(5, coeficientes_loc); print ''

print 'Testando obter pn(x) = 0 com newton geral polinomial'
print newton_polinomial.obter_alpha(4, coeficientes_newton)

print 'Testando obter pn(x) = 0 com newton kinkeid polinomial'
print newton_kinkeid_pol.obter_alpha(4, coeficientes_newton)
