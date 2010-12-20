import urllib
import os
import glob

"""Module defined to hold all the data needed to make the requests to Dotproject""" 

def GetInstallDir():
    return '/home/mell/workspace/DotProjectManager'


def GetCookiesFilePath():
  install_dir = GetInstallDir()
    
  path = SearchForCookieFile(install_dir)

  return path

def SearchForCookieFile(path):
  """ Search for cookielib cookie file """
  cookie_extension = '*.lwp'
  
  if(os.path.isdir(path)):
    complete_file_location = os.path.join(path, cookie_extension)
    files = glob.glob(complete_file_location)
    
    if(files != []):
      return os.path.join(path, files.pop())
    
    directories = os.listdir(path)
    
    for dir in directories:
      
      return_path = SearchForCookieFile(os.path.join(path, dir))
      if(not return_path is None):
        return return_path
      
        
    return None
  
  else:
    
    return None
    
 
def GetMainUrl():
  return 'http://projetos.telemedicina.ufsc.br/index.php'
 
def GetRequestHeader():
  header = {}
    
  header['User-Agent'] = 'Mozilla/5.0 (Windows; U; Windows NT 5.1; pt-BR; rv:1.8.1.12) Gecko/20080201 Firefox/2.0.0.12'
  header['Host'] = 'projetos.telemedicina.ufsc.br'
  header['Referer'] = 'http://projetos.telemedicina.ufsc.br/index.php'
    
  header['Accept'] = 'text/xml,application/xml,application/xhtml+xml,text/html;q=0.9,text/plain;q=0.8,image/png,*/*;q=0.5'
  header['Accept-Language'] = 'pt-br,pt;q=0.8,en-us;q=0.5,en;q=0.3'
  header['Accept-Encoding'] = 'gzip,deflate'
    
  header['Accept-Charset'] = 'ISO-8859-1,utf-8;q=0.7,*;q=0.7'
  header['Keep-Alive'] = '300'
  header['Connection'] = 'keep-alive'
    
    
  return header
  
  
def GetLoginPostData(username, password):
  value = {}
  value['username'] = username
  value['password'] = password
  value['login'] = 'login'
  return urllib.urlencode(value)