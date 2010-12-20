from integracao.newtonianos import simpson
from integracao import composicao_generica

def obter_integral(a, b, funcao, nit = 10, n = 4, erro = 10 ** -16):
  integrais = simpson.obter_integral(a, b, funcao, nit, n)
  n = len(integrais) - 1
  for i in range(n):
    erro_int = composicao_generica.calcular_erro(integrais[i], integrais[i + 1])
    if erro_int < erro:
      return integrais[i]
    
  return integrais[n/2]