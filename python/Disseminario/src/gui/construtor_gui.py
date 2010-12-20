from gui.PainelDeEscolhaDeSeminarios import PainelDeEscolhaDeSeminarios
from gui.PainelDoCoordenador import PainelDoCoordenador
from gui.PainelDaDataDeInicio import PainelDaDataDeInicio
from gui.PainelDaDataDeTermino import PainelDaDataDeTermino
from gui.PainelDaDescricao import PainelDaDescricao
from gui.PainelDasInstrucoes import PainelDasInstrucoes
from gui.PainelDaDisponibilidade import PainelDaDisponibilidade
from gui.PainelDaAssistencia import PainelDaAssistencia
from gui.PainelDeAdicaoDeMaterial import PainelDeAdicaoDeMaterial
from gui.PainelMaterialDisponivel import PainelMaterialDisponivel
import wx

ESPACAMENTO_ENTRE_PAINEIS = wx.Size(10,10)

def construir_gui(aplicacaoPrincipal):
  if(aplicacaoPrincipal == None):
    return None
  
  painelPrincipal = aplicacaoPrincipal.obterPainelPrincipal()
  sizerPainelPrincipal = painelPrincipal.GetSizer()
  painel_seminarios = PainelDeEscolhaDeSeminarios(painelPrincipal)
  painel_coordernador = PainelDoCoordenador(painelPrincipal)
  painel_data_inicio = PainelDaDataDeInicio(painelPrincipal)
  painel_data_termino = PainelDaDataDeTermino(painelPrincipal)
  painel_da_descricao = PainelDaDescricao(painelPrincipal)
  painel_das_instrucoes = PainelDasInstrucoes(painelPrincipal)
  painel_da_disponibilidade = PainelDaDisponibilidade(painelPrincipal)
  painel_da_assistencia = PainelDaAssistencia(painelPrincipal)
  painel_adicao_material = PainelDeAdicaoDeMaterial(painelPrincipal)
  painel_material_disponivel = PainelMaterialDisponivel(painelPrincipal)
                        
  sizerPainelPrincipal.Add(ESPACAMENTO_ENTRE_PAINEIS)
  sizerPainelPrincipal.Add(painel_seminarios, flag = wx.EXPAND)
    
  sizerPainelPrincipal.Add(ESPACAMENTO_ENTRE_PAINEIS)
  sizerPainelPrincipal.Add(painel_coordernador, flag = wx.EXPAND)
  
  sizerPainelPrincipal.Add(ESPACAMENTO_ENTRE_PAINEIS)
  
  sizerDasDatas = wx.BoxSizer(wx.HORIZONTAL)
  sizerDasDatas.Add(painel_data_inicio, proportion = 1,flag = wx.EXPAND)
  sizerDasDatas.Add(painel_data_termino, proportion = 1, flag = wx.EXPAND)
  sizerPainelPrincipal.Add(sizerDasDatas, flag = wx.EXPAND)
  
  sizerPainelPrincipal.Add(ESPACAMENTO_ENTRE_PAINEIS)
  sizerPainelPrincipal.Add(painel_da_descricao, proportion = 1,flag = wx.EXPAND)
  
  sizerPainelPrincipal.Add(ESPACAMENTO_ENTRE_PAINEIS)
  sizerPainelPrincipal.Add(painel_das_instrucoes, proportion = 1,flag = wx.EXPAND)
  
  sizerPainelPrincipal.Add(ESPACAMENTO_ENTRE_PAINEIS)
  sizerPainelPrincipal.Add(painel_da_disponibilidade, flag = wx.EXPAND)
  
  sizerPainelPrincipal.Add(ESPACAMENTO_ENTRE_PAINEIS)
  sizerPainelPrincipal.Add(painel_da_assistencia, flag = wx.EXPAND)
  
  sizerPainelPrincipal.Add(ESPACAMENTO_ENTRE_PAINEIS)
  sizerPainelPrincipal.Add(painel_adicao_material, flag = wx.EXPAND)
  
  sizerPainelPrincipal.Add(ESPACAMENTO_ENTRE_PAINEIS)
  sizerPainelPrincipal.Add(painel_material_disponivel, flag = wx.EXPAND)
  
  sizerPainelPrincipal.Add(ESPACAMENTO_ENTRE_PAINEIS)
  
  painelPrincipal.FitInside()
  painelPrincipal.Layout()

  
  