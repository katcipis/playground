from integracao.gaussianos import gauss_tentativas
from integracao import composicao_generica

def obter_integral(a, b, funcao, nit = 10, erro = 10 ** -16):
  return composicao_generica.obter_integral(a, b, funcao, gauss_tentativas)