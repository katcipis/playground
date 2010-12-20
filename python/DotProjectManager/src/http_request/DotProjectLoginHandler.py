import urllib2
import os
import cookielib
from http_request import request_data
import webbrowser


class DotProjectLoginHandler():
  """ Class defined to build the essential facilities to make http requests """
  
  def __init__(self):
    self.InstallCookieSupport()
    self.main_url = request_data.GetMainUrl()

  def LoadCookiesFile(self):
    """ Load cookies file according to the path defined on request_data module"""
    if os.path.isfile(self.__COOKIEFILE):
      self.__cookie_jar.load(self.__COOKIEFILE)
    else:
      self.__cookie_jar.save(self.__COOKIEFILE)


  def Login(self, username, password):
     """Make the request to login on DotProject"""
    
     __request = urllib2.Request(self.main_url, 
                                  request_data.GetLoginPostData(username, password), 
                                  request_data.GetRequestHeader())
      
     urllib2.urlopen(__request)
     self.__cookie_jar.save(self.__COOKIEFILE)
      

  def InstallCookieSupport(self):
    """ Instal cookie support on the default urllib2 opener """
      
    self.__COOKIEFILE = request_data.GetCookiesFilePath()
    self.__cookie_jar = cookielib.LWPCookieJar()
     
    self.LoadCookiesFile()
      
    __opener = urllib2.build_opener(urllib2.HTTPCookieProcessor(self.__cookie_jar))
    urllib2.install_opener(__opener)
    
    
  def IsLogged(self):
    """Returns true if it is logged on dotproject, false if not"""
    request_page = urllib2.urlopen(self.main_url)
    print request_page.info()
    return True
  
  def Logout(self):
    """ Logout from Dotproject """
    
       
  
    
    