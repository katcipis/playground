'''
Created on 29/03/2009
@author: Tiago Katcipis
'''
import os 

if(os.name == 'nt'):
  COM1, COM2, COM3, COM4 = 'COM1','COM2', 'COM3', 'COM4'
else:
  COM1, COM2, COM3, COM4 = '/dev/ttyS0','/dev/ttyS1', '/dev/ttyS2', '/dev/ttyS3'
  
def obter_portas_disponiveis():
  return (COM1, COM2, COM3, COM4)
