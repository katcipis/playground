from integracao import composicao_generica
from integracao.newtonianos import simpson_melhorado

def obter_integral(a, b, funcao, nit = 10, erro = 10 ** -16):
  return composicao_generica.obter_integral(a, b, funcao, simpson_melhorado)