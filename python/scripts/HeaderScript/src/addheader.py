#! /usr/bin/env python

import glob
import os
import sys

# Functions definitions starts here #

def getHeaderTemplate():
  template_file = '.' + backslash + 'template.txt'
  return open(template_file, 'r')

def getProjectLocation():
  args = sys.argv
  
  if(len(args) is 2):
    return args[1];
  
  return None

def getFileNames(file_location, extension):
  file_extension = backslash + '*.' + extension
  complete_file_location = file_location + file_extension
  
  files = glob.glob(complete_file_location)
  directories = os.listdir(file_location)
  
  for directorie in directories:
    path = file_location + backslash + directorie
    if(os.path.isdir(path)):
      aux = getFileNames(path, extension)
      if(aux != []):
       for file_path in aux:
        files.append(file_path)
    
  return files
  
  
def writeTemplateOnFileHeader(file_path, template):
  file_name = os.path.basename(file_path);
  builded_template = buildTemplate(file_name, template)
  temp_file = open(file_path, 'r')
  file_without_header = temp_file.read()
  temp_file.close()
  if(file_without_header.find(builded_template) is -1):
    file_with_header = builded_template + file_without_header
    write_file = open(file_path, 'w')
    write_file.write(file_with_header)
    write_file.close()
  
  
def buildTemplate(file_name, template):
  template_lines = template.readlines()
  template.close()
  template_str = ''
  class_name = file_name[: -4]

  for line in template_lines:
    template_str = template_str + line
    
  template_str = template_str.replace(file_name_str, file_name)
  
  if(file_name.endswith('cpp')):
    template_str = template_str.replace(impl_or_header_str, 'Implementation')
  else:
    template_str = template_str.replace(impl_or_header_str, 'Header')
    
  template_str = template_str.replace(class_name_str, class_name)

  return template_str



#<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>#


enviroment_info = os.uname()
backslash = '/'

# Script starts here #

location = getProjectLocation()

#these strings are defined in the template file, changing 
#them will make the script stop working they are used on the
#buildTemplate function to replace they with the class name and file name

file_name_str = '#FileName#'
impl_or_header_str = '#Implementation or Header#'
class_name_str = '#ClassName#'

if(location is None):
  print 'Path not informed'

else:

  if (os.path.isdir(location)):  
    hpplist = getFileNames(location, 'hpp')
    cpplist = getFileNames(location, 'cpp')
    
    
    print 'The following hpp files will have the header inserted:'
    
    for hpp in hpplist:
      print hpp
      
    print ''
    
    print 'The following cpp files will have the header inserted:'
    
    for cpp in cpplist:
      print cpp
      
    print ''
    
    print 'Are you sure you want to proceed?, after inserting there is no comming back'
    print 'Type y or yes to go insert, or any key to abort'
    
    answer = raw_input()
    RIGHT_ANSWERS = ['y', 'yes', 'Y', 'YES']
    
    if(answer in RIGHT_ANSWERS):
    
      for hpp in hpplist:
        writeTemplateOnFileHeader(hpp, getHeaderTemplate())
        
      for cpp in cpplist:
        writeTemplateOnFileHeader(cpp, getHeaderTemplate())
        
      print 'Headers inserted succesfully'
      
    else:
      
      print 'Process aborted by user'
      
  else:
    
    print 'Path %s not found' %location
  

#<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>#





