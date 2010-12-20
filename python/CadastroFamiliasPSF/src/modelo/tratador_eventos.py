# -*- coding: utf-8 -*-
'''
Created on 25/07/2009
@author: katcipis <tiagokatcipis@gmail.com>
Modulo que define as funcoes que tratam eventos no modelo logico
'''
from modelo.PacienteVO import PacienteVO
from modelo.PacienteDAO import PacienteDAO
from eventos.TratadorDeEventos import TratadorDeEventos
from eventos import eventos_sistema

def adciona_paciente(paciente):
  ''' Adciona um paciente no banco de dados '''
  pacienteVo = PacienteVO(nome = paciente.obterNome(), 
                          dataNascimento = paciente.obterDataNascimento(), 
                          numFamilia = paciente.obterNumeroFamilia(), 
                          numArea = paciente.obterNumeroArea(),
                          numMicroArea = paciente.obterNumeroMicroArea(), 
                          endereco = paciente.obterEndereco())
  PacienteDAO().salvar(pacienteVo)
  
def remove_paciente(paciente):
  pacienteVo = PacienteVO(nome = paciente.obterNome(), 
                          dataNascimento = paciente.obterDataNascimento(), 
                          numFamilia = paciente.obterNumeroFamilia(), 
                          numArea = paciente.obterNumeroArea(),
                          numMicroArea = paciente.obterNumeroMicroArea(), 
                          endereco = paciente.obterEndereco())
  PacienteDAO().remover(pacienteVo)
  
def busca_paciente(parametro_pesquisa):
  TratadorDeEventos().dispararEvento(evento = eventos_sistema.RESP_BUSCA_PACIENTE,
                                    pacientes = PacienteDAO().buscar(parametro_pesquisa))

def listar_pacientes():
  TratadorDeEventos().dispararEvento(evento = eventos_sistema.RESP_LISTAR_PACIENTES,
                                     pacientes = PacienteDAO().listar())
  
