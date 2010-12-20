'''
Created on 08/11/2009
@author: katcipis
'''
from distutils.core import setup
import py2exe
setup(windows=[{"script":"main.py"}], options={"py2exe":{"includes":["sip"]}})
