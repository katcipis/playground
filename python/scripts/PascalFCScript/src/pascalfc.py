#! /usr/bin/env python

import os
import stat
import subprocess
import sys

# Functions definition starts here

def ExecuteBinary(interpret_path):
 
  try:
    execution = subprocess.Popen(interpret_path, shell=True)
    execution.wait()

  except OSError, CalledProcessError:
    print '<<<<<<<<< Something whent wrong while executing >>>>>>>>>'
    
def EraseFiles(files):
  for file in files:
    if(os.path.isfile(file)):
      os.remove(file)  

def MakeExecutable(executables):
  for executable in executables:
    if(os.path.isfile(executable)):
      os.chmod(executable, stat.S_IEXEC)
      
def CompileFile(compile_path):

  try:
    compile = subprocess.Popen(compile_path, shell=True)
    compile.wait()

  except OSError, CalledProcessError:
    print '<<<<<<<<< Something whent wrong while compiling >>>>>>>>>'
    

# Functions definition ends here

# Script starts here


PASCALFC_COMPILER_NAME = 'pfccomp'
PASCALFC_INTERPRETER_NAME = 'pint'
ARGUMENTS_PASSED = sys.argv

blank = ' '

if(len(ARGUMENTS_PASSED) is 2):
  
  file_location = ARGUMENTS_PASSED[1]
  output_extension = '.o'
  debug_extension = '.debug'
  
  if(os.path.isfile(file_location)):
    
    compiler_path = os.path.join('.', PASCALFC_COMPILER_NAME)
    interpreter_path = os.path.join('.', PASCALFC_INTERPRETER_NAME)
    
    MakeExecutable([compiler_path, interpreter_path])
    
    output_bin = file_location + output_extension
    output_debug = output_bin + debug_extension
    
    compile_path = compiler_path + blank + file_location + blank + output_debug + blank + output_bin
    interpret_path = interpreter_path + blank + output_bin
    
    CompileFile(compile_path)
    
    ExecuteBinary(interpret_path)
    
    EraseFiles([output_bin])
    
    print ''; print ''
    print '<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>'
    print 'A debug file has been created'
    print 'If any error has ocurred while compiling'
    print 'See the debug file for further information'
    print '<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>'
    print ''; print ''; print ''
                              
  else:
    print '<<<<<<<<< File not found >>>>>>>>>'
    
else:
  print 'Argument missing'
  print 'Please insert the path to the pfc file after the call to the script'
  print 'Like "command path_to_file" and hit enter'
  


