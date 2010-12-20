def obter_param_dois():
  a = []; t = []
  a.append(1.0); a.append(1.0)
  t.append(-0.577350269)
  t.append(0.577350269)
  return a, t
  
def obter_param_tres():
  a = []; t = []
  a.append(0.555555555); a.append(0.555555555)
  a.append(0.888888889)
  
  t.append(-0.774596667); t.append(0.774596667)
  t.append(0.0)
  return a, t

def obter_param_quatro():
  a = []; t = []
  a.append(0.34785484); a.append(0.65214516)
  a.append(0.65214516); a.append(0.34785484)
  
  t.append(-0.86113631); t.append(-0.33998104)
  t.append(0.33998104); t.append(0.86113631)
  return a, t

def obter_mapa_parametros():
  parametros = dict()
  parametros[2] = obter_param_dois
  parametros[3] = obter_param_tres
  parametros[4] = obter_param_quatro
  return parametros

def obter_parametros(m = 4):
  parametros = obter_mapa_parametros()
  a, t = parametros[m]()
  return a, t

def obter_m_maximo():
  return len(obter_mapa_parametros()) + 1