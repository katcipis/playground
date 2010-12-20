
import unittest
from http_request.DotProjectLoginHandler import DotProjectLoginHandler 

class DotProjectLoginHandlerTest(unittest.TestCase):
  
  def setUp(self):
    """ Define everything that will be used on the tests """
    self.login_handler = DotProjectLoginHandler()
    
    self.valid_username = 'dgr'
    self.valid_password = 'doom'
    
    self.invalid_username = 'invalid'
    self.invalid_password = 'invalidagain'
    
  def testKnowIfYouAreAlreadyLogged(self):
    """ KnowIfYouAreAlreadyLogged """
    self.login_handler.Login(self.valid_username, self.valid_password)
    self.assertTrue(self.login_handler.IsLogged())
  
  def testKnowIfYouAreNotLogged(self):
    """ KnowIfYouAreNotLogged """
    self.assertFalse(self.login_handler.IsLogged())
    
  def testIfTheRightUsernameAndPasswordIsGivenWillLogin(self):
    """ IfTheRightUsernameAndPasswordIsGivenWillLogin """
    self.login_handler.Login(self.valid_username, self.valid_password)
    self.assertTrue(self.login_handler.IsLogged())
    
  def testIfTheUsernameIsWrongWillNotLogin(self):
    """ IfTheUsernameIsWrongWillNotLogin """
    self.login_handler.Login(self.invalid_username, self.valid_password)
    self.assertFalse(self.login_handler.IsLogged())
    
  def testIfThePasswordIsWrongWillNotLogin(self):
    """ IfThePasswordIsWrongWillNotLogin """
    self.login_handler.Login(self.valid_username, self.invalid_password)
    self.assertFalse(self.login_handler.IsLogged())
    
  def testAfterLogoutItWillNotBeLogged(self):
    """ AfterLogoutItWillNotBeLogged """
    self.login_handler.Login(self.valid_username, self.valid_password)
    self.assertTrue(self.login_handler.IsLogged())
    self.login_handler.Logout()
    self.assertFalse(self.login_handler.IsLogged())