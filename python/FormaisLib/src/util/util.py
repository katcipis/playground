'''
Created on 02/10/2009
@author: katcipis
'''
from automato_finito.AutomatoFinito import AutomatoFinito
from automato_finito.Transicao import Transicao
from automato_finito.Estado import Estado
from gramatica.GramaticaLivreContexto import GramaticaLivreContexto
from gramatica.GramaticaRegular import GramaticaRegular
from gramatica.Producao import Producao
from enum.epsilon import EPSILON
from enum.separadores import SEPARADOR_SIMBOLO_PRODUCAO
import pickle

# INICIO DAS FUNCOES PRIVADAS #

def _obter_novo_simbolo(gramatica, default = 'N'):
  achou = True
  count = 1
  while(achou):
    achou = False
    for simbolo in gramatica.obterNaoTerminais():
      if(simbolo == default):
        default = default + str(count)
        count+=1
        achou = True
        
  return default


def _tornar_producoes_indiretas_em_diretas(ai, aj, producoes):
  producoes_ai = set([prod for prod in producoes if prod.obterAlpha() == ai])
  producoes_aj = set([prod for prod in producoes if prod.obterAlpha() == aj])
  
  for prod_ai in producoes_ai:
    if(prod_ai.obterSimboloBeta(0) == aj):   
      producoes.remove(prod_ai)
      resto_prod = ''
      for i in range(1, prod_ai.obterTamanhoBeta()):
        resto_prod += SEPARADOR_SIMBOLO_PRODUCAO + prod_ai.obterSimboloBeta(i)
        
      for prod_aj in producoes_aj:
        if(prod_aj.obterBeta() != EPSILON):
          producoes.add(Producao(ai, prod_aj.obterBeta() + resto_prod))
        elif(resto_prod != ''):
          producoes.add(Producao(ai, resto_prod))
        else:
          producoes.add(Producao(ai, EPSILON))

def _existe_ambiguidade_direta(prod_ambiguas):
  for prod_i in prod_ambiguas:
    for prod_j in prod_ambiguas:
      if(prod_i != prod_j):
        if(prod_i.obterSimboloBeta(0) != prod_j.obterSimboloBeta(0)):
          return False
    
  return True

def _obter_tamanho_ambiguidade(prod_ambiguas):
  tamanho_ambig = None
  
  for prod_i in prod_ambiguas:
    for prod_j in prod_ambiguas:
      if(prod_i != prod_j):
        i = 0
        while(prod_i.obterSimboloBeta(i) == prod_j.obterSimboloBeta(i)):
          i += 1
        if(tamanho_ambig == None):
          tamanho_ambig = i
        elif(i < tamanho_ambig):
          tamanho_ambig = i
          
  return tamanho_ambig
  
  
def _remover_ambiguidade_direta(producoes, prod_ambiguas, novo_nt):
  tamanho_ambig = _obter_tamanho_ambiguidade(prod_ambiguas)
  producoes -= prod_ambiguas
  
  for prod in prod_ambiguas:
    beta = ''
    for i in range(tamanho_ambig):
      beta += prod.obterSimboloBeta(i) + SEPARADOR_SIMBOLO_PRODUCAO
    beta += novo_nt
    producoes.add(Producao(prod.obterAlpha(), beta))
    
    if(tamanho_ambig == prod.obterTamanhoBeta()):
      beta = EPSILON
    else:
      beta = ''
      for i in range(tamanho_ambig, prod.obterTamanhoBeta()):
        beta += prod.obterSimboloBeta(i) + SEPARADOR_SIMBOLO_PRODUCAO
    
    producoes.add(Producao(novo_nt, beta))
  
  
def _tornar_ambiguidade_direta(glc, producoes, conjunto_ambiguo):
  nts_tratados = set()
  for prod in conjunto_ambiguo:
    if(prod.obterSimboloBeta(0) in glc.obterNaoTerminais()):
      if(not prod.obterSimboloBeta(0) in nts_tratados):
        _tornar_producoes_indiretas_em_diretas(prod.obterAlpha(), prod.obterSimboloBeta(0), producoes)
        nts_tratados.add(prod.obterSimboloBeta(0))

                    
def _remover_recursao_direta(ai, producoes):
  producoes_comecam_ai = set([prod for prod in producoes if prod.obterAlpha() == ai and prod.obterSimboloBeta(0) == ai])
  if(producoes_comecam_ai == set()):
    return
  
  producoes_n_comecam_ai = set([prod for prod in producoes if prod.obterAlpha() == ai and prod.obterSimboloBeta(0) != ai])
  i = 1; ai_novo = ai + str(i)
  
  while(ai_novo in set([prod.obterAlpha() for prod in producoes])):
    i += 1; ai_novo = ai + str(i)

  producoes -= producoes_comecam_ai
  producoes -= producoes_n_comecam_ai
    
  for prod in producoes_n_comecam_ai:
    producoes.add(Producao(ai, prod.obterBeta() + SEPARADOR_SIMBOLO_PRODUCAO + ai_novo))
    
  for prod in producoes_comecam_ai:
    resto_prod = ''
    for i in range(1, prod.obterTamanhoBeta()):
      resto_prod += prod.obterSimboloBeta(i) + SEPARADOR_SIMBOLO_PRODUCAO
      
    producoes.add(Producao(ai_novo, resto_prod + ai_novo))
    
  producoes.add(Producao(ai_novo, EPSILON))


def _fatorar_glc(glc, conjuntos_ambiguos, nt):
  producoes = glc.obterProducoes()
  
  for conjunto_ambiguo in conjuntos_ambiguos:
    if(_existe_ambiguidade_direta(conjunto_ambiguo)):
      _remover_ambiguidade_direta(producoes, conjunto_ambiguo, _obter_novo_simbolo(glc, nt))
    else:
      _tornar_ambiguidade_direta(glc, producoes, conjunto_ambiguo)
  
  return GramaticaLivreContexto(producoes, set([prod.obterAlpha() for prod in producoes]), glc.obterTerminais(), glc.obterSimboloInicial())
      

def _possui_ciclo_glc(glc, nt_origem, nt_beta, nt_investigados):
  if(nt_origem == nt_beta):
    return True
  
  nt_investigados.add(nt_beta)
  investigar = set()
  
  for prod in glc.obterProducoesDoAlpha(nt_beta):
    if(len(prod.obterBeta()) == 1 and 
       prod.obterBeta() in glc.obterNaoTerminais() and
       not prod.obterBeta() in nt_investigados):
      
      investigar.add(prod.obterBeta())
        
  for nt in investigar:
    if(_possui_ciclo_glc(glc, nt_origem, nt, nt_investigados)):
      return True
  
  return False
        

def _obter_nome_classe_destino(nome_estado_destino, classes):
  for classe in classes:
    for estado in classe[2]:
      if(nome_estado_destino == estado.obterNome()):
        return classe[0]


def _alterar_nomes_estados(automato, alterador):
  estados_novos = set()
  for estado in automato.obterEstados():
    transicoes_novas = set()
    for transicao in estado.obterTransicoes():
      trans_nova = Transicao(transicao.obterSimbolo(), transicao.obterNomeEstadoDestino() + alterador)
      transicoes_novas.add(trans_nova)
    estado_novo = Estado(estado.obterNome() + alterador, transicoes_novas, estado.ehInicial(), estado.ehFinal())
    estados_novos.add(estado_novo)
    
  return AutomatoFinito(automato.obterAlfabeto(), estados_novos)
      
      
def _obter_nome_estado_novo(automato, default = 'qErro'):
  ret = default
  i = 0
  while(automato.obterEstado(ret) != None):
    ret = default + str(i)
    i+=1
  return ret


def _unir_estados(estados):
  ''' Dado um conjunto de estados une todos eles transformando em apenas um estado,
      onde o nome dele serah a concatenacao de todos os nomes ordenados 
      e o conjunto de transicoes dele eh a uniao das transicoes de todos os estados.
      Se algum estado for final a uniao tambem o serah. 
      @param estados: Estados que serao unidos '''
      
  nomes = []
  transicoes = set()
  eh_final = False
  
  for estado in estados:
    if(estado.ehFinal()):
      eh_final = True
    nomes.append(estado.obterNome())
    transicoes.update(estado.obterTransicoes())
    
  nomes.sort()
  nome_final = ''
  for nome in nomes:
    nome_final += nome
    
  return Estado(nome_final, transicoes, False, eh_final)

def _construir_estados(automato, estado_atual, estados_marcados):
  ''' Funcao recursiva interna, nao use '''
  if(estado_atual in estados_marcados):
    return
  
  novas_transicoes = set()  
  estados_alc = set()
  
  for simbolo in automato.obterAlfabeto():
    transicoes = estado_atual.obterTransicoesPorSimbolo(simbolo)
    if(len(transicoes) >= 1):
      estados = set()
      for transicao in transicoes:
        estados.add(automato.obterEstado(transicao.obterNomeEstadoDestino()))
       
      estado_novo = _unir_estados(estados)   
      novas_transicoes.add(Transicao(simbolo, estado_novo.obterNome()))
      estados_alc.add(estado_novo)
      
  estados_marcados.add(Estado(estado_atual.obterNome(), novas_transicoes, 
                    estado_atual.ehInicial(), estado_atual.ehFinal()))
  
  for estado_alc in estados_alc:
    _construir_estados(automato, estado_alc, estados_marcados)
  
# INICIO DAS FUNCOES PUBLICAS #

def determinizar_af(automato):
  ''' A partir do automato_finito nao deterministico informado constroi um equivalente deterministico
      @param automato_finito: automato_finito a ser determinizado
      @return: novo automato_finito deterministico equivalente''' 
      
  if(automato.ehDeterministico()):
    return automato

  estados = set()
  alfabeto = automato.obterAlfabeto()
  _construir_estados(automato, automato.obterEstadoInicial(), estados)
  
  return AutomatoFinito(alfabeto, estados)


def remover_estados_inalcancaveis_afd(automato):
  ''' A partir de um automato_finito deterministico cria um novo automato_finito sem os estados que nao sao alcancaveis
      @param automato_finito: automato_finito possivelmente com estados inalcancaveis
      @return: novo automato_finito sem estados inalcancaveis
  '''
  alcancaveis = automato.obterEstados() - automato.obterEstadosInalcancaveis()
  return AutomatoFinito(automato.obterAlfabeto(), alcancaveis)

def remover_estados_mortos_afd(automato):
  ''' A partir de um automato_finito deterministico SEM estados inalcancaveis cria um novo 
      automato_finito deterministico que nao possui estados mortos (inferteis).
      @param automato_finito: automato_finito possivelmente com estados mortos
      @return: novo automato_finito sem estados mortos
  '''
  mortos = automato.obterEstadosMortos()
  vivos  = automato.obterEstados() - mortos
     
  nomes_estados_mortos = [estado.obterNome() for estado in mortos]
  if(nomes_estados_mortos == []):
    return automato
  
  estados_vivos = set()
  for vivo in vivos:
    transicoes = set()
    for transicao in vivo.obterTransicoes():
      if(not transicao.obterNomeEstadoDestino() in nomes_estados_mortos):
        transicoes.add(transicao)
    estados_vivos.add(Estado(vivo.obterNome(), transicoes, vivo.ehInicial(), vivo.ehFinal()))
          
  return AutomatoFinito(automato.obterAlfabeto(), estados_vivos)

def completar_af(automato):
  ''' A partir de um automato_finito finito imcompleto constroi um novo automato_finito finito completo.
      @param automato_finito: automato_finito imcompleto
      @return: novo automato_finito completo
  '''
  if(automato.ehCompleto()):
    return automato
  
  nome_estado_erro = _obter_nome_estado_novo(automato)
  transicoes_erro = set()
  for simbolo in automato.obterAlfabeto():
    transicoes_erro.add(Transicao(simbolo, nome_estado_erro))
      
  estado_erro = Estado(nome_estado_erro, transicoes_erro,False, False)
  estados_novos = set([estado_erro])
  for estado in automato.obterEstados():
    transicoes = set()
    for simbolo in automato.obterAlfabeto():
      if(estado.obterTransicoesPorSimbolo(simbolo) == set()):
        transicoes.add(Transicao(simbolo, nome_estado_erro))
      else:
        transicoes.update(estado.obterTransicoesPorSimbolo(simbolo))
        
    estados_novos.add(Estado(estado.obterNome(), transicoes, estado.ehInicial(), estado.ehFinal()))
    
  return AutomatoFinito(automato.obterAlfabeto(), estados_novos)
      

def minimizar_afd(automato):
  ''' A partir de um automato finito deterministico nao minimo 
      constroi um novo automato_finito finito minimo.
      @param automato_finito: automato_finito finito completo nao minimo
      @return: novo automato_finito completo
  '''
  if(automato.ehMinimo()):
    return automato
  
  contador_ce = 0
  automato = remover_estados_inalcancaveis_afd(automato)
  automato = remover_estados_mortos_afd(automato)
  automato = completar_af(automato)
  classes_eq = automato.obterClassesDeEquivalencia()
  novas_classes = []
  
  for classe in classes_eq:
    classe = ('q' + str(contador_ce), set(), classe)
    contador_ce += 1
    novas_classes.append(classe)
  
  for classe in novas_classes:
    estado_aux = classe[2].pop()
    classe[2].add(estado_aux)
    for simbolo in automato.obterAlfabeto():
      nome_estado_dest = estado_aux.obterTransicoesPorSimbolo(simbolo).pop().obterNomeEstadoDestino()
      nome_classe_dest = _obter_nome_classe_destino(nome_estado_dest, novas_classes)
      classe[1].add(Transicao(simbolo, nome_classe_dest))
      
  estados = set()
  for classe in novas_classes:
    eh_inicial = False
    eh_final   = False
    for estado in classe[2]:
      if(estado.ehInicial()): eh_inicial = True
      if(estado.ehFinal()): eh_final = True 
      
    estados.add(Estado(classe[0], classe[1], eh_inicial, eh_final))
    
  return AutomatoFinito(automato.obterAlfabeto(), estados)

def unir_af(automato1, automato2):
  ''' Une dois automatos finitos gerando um novo automato_finito finito que 
      representa a uniao dos dois automatos (automatu1 U automato2).
      Os estados dos dois automatos serao renomeados para evitar conflitos de nomes.
      @param automato1: Automato a ser unido
      @param automato2: Automato a ser unido
      @return: automato_finito que representa a uniao dos dois automatos informados 
  '''
  nome_novo_inicial = 'q0'
  automato1 = _alterar_nomes_estados(automato1, 'A')
  automato2 = _alterar_nomes_estados(automato2, 'B')
  
  inicial1 = automato1.obterEstadoInicial()
  inicial2 = automato2.obterEstadoInicial()
  
  transicoes_novo_inicial = inicial1.obterTransicoes()
  transicoes_novo_inicial.update(inicial2.obterTransicoes())
  novos_estados = set()
  estados1 = automato1.obterEstados()
  estados2 = automato2.obterEstados()
  estados1.remove(inicial1)
  estados2.remove(inicial2)
  novos_estados.update(estados1)
  novos_estados.update(estados2)
  novos_estados.add(Estado(nome_novo_inicial, transicoes_novo_inicial, True, inicial1.ehFinal() or inicial2.ehFinal()))
  novos_estados.add(Estado(inicial1.obterNome(), inicial1.obterTransicoes(), False, inicial1.ehFinal()))
  novos_estados.add(Estado(inicial2.obterNome(), inicial2.obterTransicoes(), False, inicial2.ehFinal()))
  alfabeto = automato1.obterAlfabeto()
  alfabeto.update(automato2.obterAlfabeto())
                  
  return AutomatoFinito(alfabeto, novos_estados)
  
def concatenar_af(automato1, automato2):
  ''' Concatena dois automatos finitos gerando um novo automato_finito finito que 
      representa a concatenacao dos dois automatos (automatu1 . automato2).
      Os estados dos dois automatos serao renomeados para evitar conflitos de nomes.
      @param automato1: Automato a ser concatenado
      @param automato2: Automato a ser concatenado
      @return: automato_finito que representa a concatenacao dos dois automatos informados 
  '''
  automato1 = _alterar_nomes_estados(automato1, 'A')
  automato2 = _alterar_nomes_estados(automato2, 'B')
  
  novos_estados = automato2.obterEstados()
  inicial2 = automato2.obterEstadoInicial()
  novos_estados.remove(inicial2)
  novos_estados.add(Estado(inicial2.obterNome(), inicial2.obterTransicoes(), False, inicial2.ehFinal()))
  novos_estados.update(automato1.obterEstados() - automato1.obterEstadosFinais())
  
  for estado in automato1.obterEstadosFinais():
    transicoes = estado.obterTransicoes()
    transicoes.update(inicial2.obterTransicoes())
    novos_estados.add(Estado(estado.obterNome(), transicoes, estado.ehInicial(), inicial2.ehFinal()))
    
  alfabeto = automato1.obterAlfabeto()
  alfabeto.update(automato2.obterAlfabeto())
                  
  return AutomatoFinito(alfabeto, novos_estados)

def obter_complemento_af(automato):
  ''' Complementa um automato_finito, se o automato_finito nao eh deterministico ele serah determinizado e
      se ele nao eh completo ele sera completado antes de se aplicar o complemento ao mesmo.
      @param: automato_finito Automato do qual serah obtido o complemento
      @return: complemento do automato_finito
  '''
  automato = determinizar_af(automato)
  automato = completar_af(automato)
  novos_estados = set()
  
  for estado in automato.obterEstados():
    novos_estados.add(Estado(estado.obterNome(), estado.obterTransicoes(), estado.ehInicial(), not estado.ehFinal()))
    
  return AutomatoFinito(automato.obterAlfabeto(), novos_estados)

def esta_contido_af(automato1, automato2):
  ''' Verifica se L(automato1) esta contida em L(automato2).
      @param automato1: Automato a ser analisado.
      @param automato2: Automato a ser analisado.
      @return: True se L(automato1) esta contida em L(automato2), False caso contrario. 
  '''
  complemento_a1 = obter_complemento_af(automato1)
  complementoa1_U_a2 = unir_af(complemento_a1, automato2)
  final = obter_complemento_af(complementoa1_U_a2)
  final = remover_estados_inalcancaveis_afd(final)
  return final.obterEstadosFinais() == set() 

def sao_equivalentes_af(automato1, automato2):
  ''' Verifica se L(automato1) = L(automato2)
      @param automato1: Automato a ser analisado.
      @param automato2: Automato a ser analisado.
      @return: True se L(automato1) = L(automato2), False caso contrario. 
  '''
  return esta_contido_af(automato1, automato2) and esta_contido_af(automato2, automato1)

def obter_fechamento_reflexivo_af(automato):
  ''' Obtem a reflexao do automato, aplicando * na linguagem gerada pelo mesmo.
      @param automato: automato onde sera aplicado *
      @return: novo automato que representa automato*
  '''
  automato = _alterar_nomes_estados(automato, '*')
  
  antigos_estados = automato.obterEstados() 
  antigo_inicial = automato.obterEstadoInicial()
  antigos_estados.remove(antigo_inicial)
  
  transicoes_antigo_inicial = antigo_inicial.obterTransicoes() 
  novos_estados = set()
  novos_estados.add(Estado('q0', transicoes_antigo_inicial.copy(), True, True))
  novos_estados.add(Estado(antigo_inicial.obterNome(), transicoes_antigo_inicial.copy(), False, antigo_inicial.ehFinal()))
  
  for estado in antigos_estados:
    if(estado.ehFinal()):
      novas_transicoes = set()
      novas_transicoes.update(estado.obterTransicoes())
      novas_transicoes.update(transicoes_antigo_inicial)
      novos_estados.add(Estado(estado.obterNome(), novas_transicoes, False, True))
    else:
      novos_estados.add(estado)
      
  return AutomatoFinito(automato.obterAlfabeto(), novos_estados)


def obter_fechamento_positivo_af(automato):
  ''' Obtem a fechamento transitivo positivo do automato, aplicando + na linguagem gerada pelo mesmo.
      @param automato: automato onde sera aplicado +
      @return: novo automato que representa automato+
  '''
  
  antigos_estados = automato.obterEstados() 
  novos_estados = set()
  inicial = automato.obterEstadoInicial()
  
  for estado in antigos_estados:
    if(estado.ehFinal() and (estado != inicial)):
      novas_transicoes = set()
      novas_transicoes.update(estado.obterTransicoes())
      novas_transicoes.update(inicial.obterTransicoes())
      novos_estados.add(Estado(estado.obterNome(), novas_transicoes, False, True))
    else:
      novos_estados.add(estado)
      
  return AutomatoFinito(automato.obterAlfabeto(), novos_estados)


def gerar_automato_finito(simbolo):
  ''' Gera um automato que eh capaz de reconhecer apenas o simbolo dado. 
      @param simbolo: O simbolo, deve ter tamanho 1.
      @return: automato que reconhece apenas o simbolo.
  '''
  if(len(simbolo) != 1):
    return None
  
  alfabeto = set([simbolo])
  estados = set()
  estados.add(Estado('q0', set([Transicao(simbolo, 'q1')]), True, False))
  estados.add(Estado('q1', set(), False, True))
  return AutomatoFinito(alfabeto, estados)
      
      
def gerar_automato_finito_epsilon():
  ''' Gera um automato capaz de reconhecer apenas epsilon (sentenca vazia).
      @return: automato que reconhece epsilon apenas.
  '''
  alfabeto = set()
  estados = set()
  estados.add(Estado('q0', set(), True, True))
  return AutomatoFinito(alfabeto, estados)

def obter_afd(gramatica_regular):
  ''' Dado uma gramatica regular constroi o automato finito deterministico minimo da mesma.
      @param gramatica_regular: Gramatica Regular
      @return: AutomatoFinito
  '''
  if(not isinstance(gramatica_regular, GramaticaRegular)):
    return None
  
  novo_simbolo = _obter_novo_simbolo(gramatica_regular)
  nomes_estados = gramatica_regular.obterNaoTerminais()
  alfabeto = gramatica_regular.obterTerminais()
  nome_inicial = gramatica_regular.obterSimboloInicial()
  estados = set()
  estados.add(Estado(novo_simbolo, set(), False, True))
  eh_final = False
  
  for prod in gramatica_regular.obterProducoesDoAlpha(nome_inicial):
    if(prod.obterBeta() == EPSILON):
      eh_final = True
  
  for nome in nomes_estados:
    transicoes = set()
    for prod in gramatica_regular.obterProducoesDoAlpha(nome):
      if(prod.obterBeta() != EPSILON):
        if(len(prod.obterBeta()) == 1):
          transicoes.add(Transicao(prod.obterBeta(), novo_simbolo))
        else:
          transicoes.add(Transicao(prod.obterBeta()[0], prod.obterBeta()[1:]))
 
    if(nome == nome_inicial):
      estados.add(Estado(nome, transicoes, True, eh_final))
    else:
      estados.add(Estado(nome, transicoes, False, False))
        
  if(EPSILON in alfabeto):
    alfabeto.remove(EPSILON)
    
  automato = AutomatoFinito(alfabeto, estados)
  automato = determinizar_af(automato)
  automato = minimizar_afd(automato)
  return automato

def obter_gramatica_regular(afd):
  ''' Dado um AFD constroi gramatica regular equivalente.
      @param afd: Automato Finito Deterministico.
      @return: Gramatica regular equivalente
  '''
  vn = set([estado.obterNome() for estado in afd.obterEstados()])
  vt = afd.obterAlfabeto()
  producoes = set()
  
  if(afd.obterEstadoInicial().ehFinal()):
    simbolo_inicial = _obter_nome_estado_novo(afd, 'S')
    vn.add(simbolo_inicial)
    for transicao in afd.obterEstadoInicial().obterTransicoes():
      producoes.add(Producao(simbolo_inicial, transicao.obterSimbolo() + transicao.obterNomeEstadoDestino()))
      if(afd.obterEstado(transicao.obterNomeEstadoDestino()).ehFinal()):
        producoes.add(Producao(simbolo_inicial, transicao.obterSimbolo()))
    producoes.add(Producao(simbolo_inicial, EPSILON))
  else:
    simbolo_inicial = afd.obterEstadoInicial().obterNome()
  
  for estado in afd.obterEstados():
    for transicao in estado.obterTransicoes():
      producoes.add(Producao(estado.obterNome(), transicao.obterSimbolo() + transicao.obterNomeEstadoDestino()))
      if(afd.obterEstado(transicao.obterNomeEstadoDestino()).ehFinal()):
        producoes.add(Producao(estado.obterNome(), transicao.obterSimbolo()))
        
  return GramaticaRegular(producoes, vn, vt, simbolo_inicial)


def remover_simbolos_inalcancaveis_glc(glc):
  ''' @param glc: Gramatica Livre de Contexto.
      @return: Gramatica Livre de Contexto equivalente sem simbolos inalcancaveis.
  '''
  nt_alcancaveis = set([glc.obterSimboloInicial()])
  marcou = True
  
  while(marcou):
    marcou = False
    for nt in nt_alcancaveis.copy():
      for prod in glc.obterProducoesDoAlpha(nt):
        nao_terminais_beta = glc.obterNaoTerminaisDoBeta(prod)
        novos_alcancaveis = [nt_beta for nt_beta in nao_terminais_beta if not nt_beta in nt_alcancaveis]
        if(novos_alcancaveis != []):
          marcou = True
          nt_alcancaveis.update(novos_alcancaveis)
          
  producoes_novas = set()
  for nt in nt_alcancaveis:
    for prod in glc.obterProducoesDoAlpha(nt):
      nao_terminais_beta = glc.obterNaoTerminaisDoBeta(prod)
      if(set([nt_beta for nt_beta in nao_terminais_beta if nt_beta in nt_alcancaveis]) == nao_terminais_beta):
        producoes_novas.add(prod)
        
  return GramaticaLivreContexto(producoes_novas, nt_alcancaveis, glc.obterTerminais(), glc.obterSimboloInicial())
    

def remover_simbolos_mortos_glc(glc):
  ''' @param glc: Gramatica Livre de Contexto.
      @return: Gramatica Livre de Contexto equivalente sem simbolos mortos.
  '''
  nt_ferteis = set()
  marcou = True
  
  for nt in glc.obterNaoTerminais():
    for prod in glc.obterProducoesDoAlpha(nt):
      if(glc.obterNaoTerminaisDoBeta(prod) == set()):
        nt_ferteis.add(nt)
        
      
  while(marcou):
    marcou = False
    for infertil in glc.obterNaoTerminais() - nt_ferteis.copy():
      for prod in glc.obterProducoesDoAlpha(infertil):
        nao_terminais_beta = glc.obterNaoTerminaisDoBeta(prod)
        if(set([nt_beta for nt_beta in nao_terminais_beta if nt_beta in nt_ferteis]) == nao_terminais_beta):
          nt_ferteis.add(infertil)
          marcou = True
      
    
  producoes_novas = set()
  for fertil in nt_ferteis:
    for prod in glc.obterProducoesDoAlpha(fertil):
      nao_terminais_beta = glc.obterNaoTerminaisDoBeta(prod)
      if(set([nt_beta for nt_beta in nao_terminais_beta if nt_beta in nt_ferteis]) == nao_terminais_beta):
        producoes_novas.add(prod)
        
  return GramaticaLivreContexto(producoes_novas, nt_ferteis, glc.obterTerminais(), glc.obterSimboloInicial())


def remover_simbolos_inuteis_glc(glc):
  ''' @param glc: Gramatica Livre de Contexto.
      @return: Gramatica Livre de Contexto equivalente sem simbolos inuteis.
  '''
  glc = remover_simbolos_mortos_glc(glc)
  return remover_simbolos_inalcancaveis_glc(glc)
  
  
def remover_ciclos_glc(glc):
  ''' @param glc: Gramatica Livre de Contexto.
      @return: Gramatica Livre de Contexto equivalente sem ciclos.
  '''
  for nt in glc.obterNaoTerminais():
    for prod in glc.obterProducoesDoAlpha(nt):
      if(len(prod.obterBeta()) == 1 and prod.obterBeta() in glc.obterNaoTerminais()):
        if(_possui_ciclo_glc(glc, nt, prod.obterBeta(), set())):
          producoes_novas = glc.obterProducoes()
          producoes_novas.remove(prod)
          if(nt != prod.obterBeta()):
            for prod2 in glc.obterProducoesDoAlpha(prod.obterBeta()):
              producoes_novas.add(Producao(nt, prod2.obterBeta()))
            
          return remover_ciclos_glc(GramaticaLivreContexto(producoes_novas, glc.obterNaoTerminais(), glc.obterTerminais(), glc.obterSimboloInicial()))
        
  return glc
  
  
def transformar_em_epsilon_livre_glc(glc):
  ''' @param glc: Gramatica Livre de Contexto.
      @return: Gramatica Livre de Contexto equivalente epsilon livre.
  '''
  ne = glc.obterNaoTerminaisQueDerivamEpsilon()      
  producoes_novas = set([prod for prod in glc.obterProducoes() if prod.obterBeta() != EPSILON])
  
  for prod in producoes_novas.copy():
    nts_epsilon = set([nt for nt in glc.obterNaoTerminaisDoBeta(prod) if nt in ne])
    for nt in nts_epsilon:
      if(prod.obterBeta() != nt):
        producoes_novas.add(Producao(prod.obterAlpha(), prod.obterBeta().replace(nt, '')))
  
  nt_novos = glc.obterNaoTerminais()
  simbolo_inicial = glc.obterSimboloInicial()
  
  if(glc.obterSimboloInicial() in ne):
    for prod in glc.obterProducoes():
      if(glc.obterSimboloInicial() in glc.obterNaoTerminaisDoBeta(prod)):
        simbolo_inicial = _obter_novo_simbolo(glc, glc.obterSimboloInicial())  
        nt_novos.add(simbolo_inicial)
        producoes_novas.add(Producao(simbolo_inicial, glc.obterSimboloInicial()))
        producoes_novas.add(Producao(simbolo_inicial, EPSILON))
        break
    if(simbolo_inicial == glc.obterSimboloInicial()):
      producoes_novas.add(Producao(simbolo_inicial, EPSILON))
    
  return GramaticaLivreContexto(producoes_novas, nt_novos, glc.obterTerminais(), simbolo_inicial)
 
 
def remover_recursao_esquerda_glc(glc):
  ''' @param glc: Gramatica Livre de Contexto.
      @return: Gramatica Livre de Contexto equivalente sem recursao a esquerda.
  '''
  glc = transformar_em_epsilon_livre_glc(glc)  
  glc = remover_ciclos_glc(glc)
  glc = remover_simbolos_inuteis_glc(glc)

  nt_ordenados = list(glc.obterNaoTerminais())
  alterou = True
  producoes_novas = glc.obterProducoes()
  
  while(alterou):
    alterou = False
    producoes_atuais = producoes_novas.copy()

    for i in range(len(nt_ordenados)):
      for j in range(0, i):
        _tornar_producoes_indiretas_em_diretas(nt_ordenados[i], nt_ordenados[j], producoes_novas)
        
      _remover_recursao_direta(nt_ordenados[i], producoes_novas)
      
    alterou = producoes_atuais != producoes_novas
    
  nts_novos = set([prod.obterAlpha() for prod in producoes_novas])  
  return GramaticaLivreContexto(producoes_novas, nts_novos, glc.obterTerminais(), glc.obterSimboloInicial())
  
def _prod_sao_ambiguas_entre_si(glc, prod_i, prod_j):
  first_i = set()
  first_j = set()
  i = 0; j = 0
  while(i < prod_i.obterTamanhoBeta() and j < prod_j.obterTamanhoBeta()):
    first_i.update(glc.obterFirst(prod_i.obterSimboloBeta(i)))
    first_j.update(glc.obterFirst(prod_j.obterSimboloBeta(j)))
    
    if(not EPSILON in glc.obterFirst(prod_i.obterSimboloBeta(i)) and 
       not EPSILON in glc.obterFirst(prod_j.obterSimboloBeta(j))):
      break
    
    if(EPSILON in glc.obterFirst(prod_i.obterSimboloBeta(i))):
      i+=1
    if(EPSILON in glc.obterFirst(prod_j.obterSimboloBeta(j))):
      j+=1
      
  return first_i.intersection(first_j) != set()
  
            
            
def fatorar_glc(glc, n_passos = 100):
  ''' @param glc: Gramatica Livre de Contexto.
      @param num_passos: Quantidade de passos que o algoritmo deve executar. (default = 100)
      @return: Gramatica Livre de Contexto equivalente nao fatorada se isso for possivem em n_passos.
  '''
  while(n_passos > 0):
    n_passos -=1
    if(glc.estaFatorada()):
      return glc
    
    for nt in glc.obterNaoTerminais():
      prod_ambiguas_nt = set()
      for prod_i in glc.obterProducoesDoAlpha(nt):
        prod_ambiguas_prod_i = set([prod_i])
        for prod_j in glc.obterProducoesDoAlpha(nt):
          if(prod_i != prod_j):
            if(_prod_sao_ambiguas_entre_si(glc, prod_i, prod_j)):
              prod_ambiguas_prod_i.add(prod_j)
              
        if(prod_ambiguas_prod_i != set([prod_i])):
          prod_ambiguas_nt.add(frozenset(prod_ambiguas_prod_i))
          
      if(prod_ambiguas_nt != set()):
        glc = _fatorar_glc(glc, prod_ambiguas_nt, nt)
    
  return glc  
      
  
  
def salvar(obj, path_arquivo):
  ''' Salva um objeto em disco.
      @param obj: objeto que sera salvo.
      @param path_arquivo: Path completo onde sera salvo o arquivo.
  '''
  arquivo = open(path_arquivo, 'wb')
  pickle.dump(obj, arquivo, pickle.HIGHEST_PROTOCOL)
  arquivo.close()
  
  
def carregar(path_arquivo):
  ''' Carrega um objeto em disco.
      @param path_arquivo: Path completo do arquivo que serah carregado.
      @return: Instancia do objeto carregado.
  '''
  arquivo = open(path_arquivo, 'rb')
  obj = pickle.load(arquivo) 
  arquivo.close()
  return obj
  
