# -*- coding: utf-8 -*-
'''
Created on 25/07/2009
@author: katcipis <tiagokatcipis@gmail.com>
Modulo que define os Eventos ja existentes no sistema para serem tratados.
Mais eventos customizados podem ser criados e tratados em tempo de execucao.
'''
from eventos.Evento import Evento

ADCIONAR_PACIENTE      = Evento('adcionar_paciente', ('paciente',))
RESP_ADCIONAR_PACIENTE = Evento('resp_adcionar_paciente', ('msg',))

BUSCA_PACIENTE        = Evento('busca_paciente', ('parametro_pesquisa',))
RESP_BUSCA_PACIENTE   = Evento('resp_busca_paciente', ('pacientes',))

LISTAR_PACIENTES      = Evento('listar_pacientes')
RESP_LISTAR_PACIENTES = Evento('resp_listar_pacientes', ('pacientes',))

REMOVER_PACIENTE      = Evento('remover_paciente', ('paciente',))
RESP_REMOVER_PACIENTE = Evento('resp_remover_paciente', ('msg',))

